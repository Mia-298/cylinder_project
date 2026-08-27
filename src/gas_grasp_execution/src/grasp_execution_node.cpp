#include "gas_grasp_execution/grasp_execution_node.hpp"

#include <algorithm>
#include <functional>
#include <cmath>
#include <filesystem>
#include <future>
#include <iomanip>
#include <limits>
#include <sstream>
#include <thread>

namespace gas
{
namespace fs = std::filesystem;
using namespace std::chrono_literals;

namespace
{
constexpr int kSuccess = 0;
constexpr int kNoDetection = -2003;
constexpr int kNoHandeye = -2004;
constexpr int kNoRobotPose = -2005;
constexpr int kDepthInvalid = -2006;
constexpr int kMoveFailed = -2007;
constexpr int kException = -2999;

template<typename ServiceT>
std::shared_ptr<typename ServiceT::Response> callServiceSync(
  const typename rclcpp::Client<ServiceT>::SharedPtr & client,
  const typename ServiceT::Request::SharedPtr & request,
  const std::chrono::milliseconds timeout,
  std::string & error_message)
{
  if (!client) {
    error_message = "service client not initialized";
    return nullptr;
  }
  if (!client->wait_for_service(timeout)) {
    error_message = std::string("service unavailable: ") + client->get_service_name();
    return nullptr;
  }

  auto future = client->async_send_request(request);
  const auto deadline = std::chrono::steady_clock::now() + timeout;
  while (rclcpp::ok() && std::chrono::steady_clock::now() < deadline) {
    if (future.wait_for(0ms) == std::future_status::ready) {
      return future.get();
    }
    std::this_thread::sleep_for(10ms);
  }

  error_message = std::string("service call timed out: ") + client->get_service_name();
  return nullptr;
}

std::string formatFloat3(const std::array<double, 3> & value)
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(4)
      << "[" << value[0] << ", " << value[1] << ", " << value[2] << "]";
  return oss.str();
}

}  // namespace

GraspExecutionNode::GraspExecutionNode()
: Node("gas_grasp_execution_node")
{
  yolo_service_name_ = declare_parameter<std::string>("yolo_service_name", "/yolo/detect_once");
  robot_pose_service_ = declare_parameter<std::string>("robot_pose_service", "/robot/get_pose");
  robot_move_l_service_ = declare_parameter<std::string>("robot_move_l_service", "/robot/move_l");
  handeye_status_service_ =
    declare_parameter<std::string>("handeye_status_service", "/handeye/status");
  handeye_result_file_ = declare_parameter<std::string>("handeye_result_file", "");
  execute_service_name_ =
    declare_parameter<std::string>("execute_service_name", "/grasp/execute_once");
  default_approach_offset_m_ = declare_parameter<double>("default_approach_offset_m", 0.10);
  min_valid_depth_m_ = declare_parameter<double>("min_valid_depth_m", 0.05);
  max_valid_depth_m_ = declare_parameter<double>("max_valid_depth_m", 5.0);
  service_timeout_ms_ = declare_parameter<int>("service_timeout_ms", 3000);
  move_timeout_ms_ = declare_parameter<int>("move_timeout_ms", 30000);

  if (default_approach_offset_m_ <= 0.0) {
    default_approach_offset_m_ = 0.10;
  }
  if (min_valid_depth_m_ <= 0.0) {
    min_valid_depth_m_ = 0.05;
  }
  if (max_valid_depth_m_ <= min_valid_depth_m_) {
    max_valid_depth_m_ = std::max(1.0, min_valid_depth_m_ * 10.0);
  }
  if (service_timeout_ms_ <= 0) {
    service_timeout_ms_ = 3000;
  }
  if (move_timeout_ms_ <= 0) {
    move_timeout_ms_ = 30000;
  }

  service_group_ = create_callback_group(rclcpp::CallbackGroupType::Reentrant);
  client_group_ = create_callback_group(rclcpp::CallbackGroupType::Reentrant);

  yolo_client_ = create_client<gas_interfaces::srv::DetectObjects>(
    yolo_service_name_,
    rmw_qos_profile_services_default,
    client_group_);
  robot_pose_client_ = create_client<gas_interfaces::srv::RobotGetPose>(
    robot_pose_service_,
    rmw_qos_profile_services_default,
    client_group_);
  robot_move_l_client_ = create_client<gas_interfaces::srv::RobotMoveL>(
    robot_move_l_service_,
    rmw_qos_profile_services_default,
    client_group_);
  handeye_status_client_ = create_client<gas_interfaces::srv::HandEyeGetStatus>(
    handeye_status_service_,
    rmw_qos_profile_services_default,
    client_group_);

  execute_srv_ = create_service<gas_interfaces::srv::GraspExecute>(
    execute_service_name_,
    std::bind(&GraspExecutionNode::executeCallback, this, std::placeholders::_1, std::placeholders::_2),
    rmw_qos_profile_services_default,
    service_group_);

  RCLCPP_INFO(get_logger(), "grasp service: %s", execute_service_name_.c_str());
  RCLCPP_INFO(get_logger(), "yolo service: %s", yolo_service_name_.c_str());
  RCLCPP_INFO(get_logger(), "robot pose service: %s", robot_pose_service_.c_str());
  RCLCPP_INFO(get_logger(), "robot move_l service: %s", robot_move_l_service_.c_str());
  RCLCPP_INFO(get_logger(), "handeye status service: %s", handeye_status_service_.c_str());
}

void GraspExecutionNode::executeCallback(
  const std::shared_ptr<gas_interfaces::srv::GraspExecute::Request> request,
  std::shared_ptr<gas_interfaces::srv::GraspExecute::Response> response)
{
  try {
    response->success = false;
    response->error_code = kException;
    response->message.clear();
    response->target_tcp_xyz_m_rpy_rad.fill(0.0);
    response->object_point_camera_m.fill(0.0);
    response->object_point_base_m.fill(0.0);
    response->depth_m = -1.0;
    response->debug_summary.clear();

    std::string result_file;
    cv::Mat T_tool_camera;
    std::string handeye_error;
    if (!resolveHandeyeResultFile(result_file, handeye_error)) {
      response->error_code = kNoHandeye;
      response->message = handeye_error;
      return;
    }
    if (!loadToolCameraMatrix(result_file, T_tool_camera, handeye_error)) {
      response->error_code = kNoHandeye;
      response->message = handeye_error;
      return;
    }

    bool has_sphere_center = false;
    std::array<double, 3> sphere_center_m{};
    double sphere_radius_m = std::numeric_limits<double>::quiet_NaN();
    std::string sphere_frame_id;
    std::string sphere_class_id;
    double sphere_confidence = std::numeric_limits<double>::quiet_NaN();
    std::string yolo_error;
    if (!requestYoloDetection(
          request->publish_debug_image, has_sphere_center,
          sphere_center_m, sphere_radius_m, sphere_frame_id,
          sphere_class_id, sphere_confidence, yolo_error)) {
      response->error_code = kNoDetection;
      response->message = yolo_error;
      return;
    }

    double depth_m = -1.0;
    const double approach_offset_m = request->approach_offset_m > 0.0
      ? request->approach_offset_m
      : default_approach_offset_m_;
    std::array<double, 3> object_camera_m{0.0, 0.0, 0.0};
    std::array<double, 3> target_camera_m{0.0, 0.0, 0.0};
    std::string target_source;

    const bool sphere_center_valid =
      has_sphere_center &&
      std::isfinite(sphere_center_m[0]) &&
      std::isfinite(sphere_center_m[1]) &&
      std::isfinite(sphere_center_m[2]) &&
      sphere_center_m[2] >= min_valid_depth_m_ &&
      sphere_center_m[2] <= max_valid_depth_m_;

    if (!has_sphere_center) {
      response->error_code = kNoDetection;
      response->message = "YOLO did not return a fitted 3D sphere center";
      return;
    }

    if (!sphere_center_valid) {
      response->error_code = kDepthInvalid;
      response->message = "YOLO returned an invalid fitted 3D sphere center";
      return;
    }

    depth_m = sphere_center_m[2];
    const double pregrasp_depth_m = depth_m - approach_offset_m;
    if (pregrasp_depth_m <= min_valid_depth_m_) {
      response->error_code = kDepthInvalid;
      response->message = "approach offset is too large for the fitted sphere depth";
      return;
    }

    const double ray_scale = pregrasp_depth_m / depth_m;
    object_camera_m = sphere_center_m;
    target_camera_m = std::array<double, 3>{
      sphere_center_m[0] * ray_scale,
      sphere_center_m[1] * ray_scale,
      pregrasp_depth_m,
    };
    target_source = "sphere_fit";

    std::array<double, 6> current_tcp_pose{};
    cv::Mat T_base_tool;
    std::string robot_error;
    if (!requestRobotPose(current_tcp_pose, T_base_tool, robot_error)) {
      response->error_code = kNoRobotPose;
      response->message = robot_error;
      return;
    }

    const cv::Mat T_base_camera = T_base_tool * T_tool_camera;
    const cv::Mat target_camera_point = (cv::Mat_<double>(4, 1) <<
      target_camera_m[0], target_camera_m[1], target_camera_m[2], 1.0);
    const cv::Mat object_camera_point = (cv::Mat_<double>(4, 1) <<
      object_camera_m[0], object_camera_m[1], object_camera_m[2], 1.0);

    const cv::Mat target_base_point = T_base_camera * target_camera_point;
    const cv::Mat object_base_point = T_base_camera * object_camera_point;

    std::array<double, 6> target_tcp_pose = current_tcp_pose;
    target_tcp_pose[0] = target_base_point.at<double>(0, 0);
    target_tcp_pose[1] = target_base_point.at<double>(1, 0);
    target_tcp_pose[2] = target_base_point.at<double>(2, 0);

    std::ostringstream summary;
    summary << std::fixed << std::setprecision(4)
            << "source=" << target_source
            << " sphere_class=" << sphere_class_id
            << " sphere_confidence=" << sphere_confidence
            << " depth_m=" << depth_m
            << " object_camera=" << formatFloat3(object_camera_m)
            << " sphere_radius_m=" << sphere_radius_m
            << " sphere_frame=" << sphere_frame_id
            << " object_base=[" << object_base_point.at<double>(0, 0) << ", "
            << object_base_point.at<double>(1, 0) << ", "
            << object_base_point.at<double>(2, 0) << "]"
            << " target_base=[" << target_base_point.at<double>(0, 0) << ", "
            << target_base_point.at<double>(1, 0) << ", "
            << target_base_point.at<double>(2, 0) << "]"
            << " handeye_result_file=" << result_file;

    std::string move_error;
    if (!requestMoveL(target_tcp_pose, request->wait, move_error)) {
      response->error_code = kMoveFailed;
      response->message = move_error;
      response->target_tcp_xyz_m_rpy_rad = target_tcp_pose;
      response->object_point_camera_m = object_camera_m;
      response->object_point_base_m = std::array<double, 3>{
        object_base_point.at<double>(0, 0),
        object_base_point.at<double>(1, 0),
        object_base_point.at<double>(2, 0),
      };
      response->depth_m = depth_m;
      response->debug_summary = summary.str();
      return;
    }

    response->success = true;
    response->error_code = kSuccess;
    response->message = request->wait
      ? "grasp target reached"
      : "move command sent";
    response->target_tcp_xyz_m_rpy_rad = target_tcp_pose;
    response->object_point_camera_m = object_camera_m;
    response->object_point_base_m = std::array<double, 3>{
      object_base_point.at<double>(0, 0),
      object_base_point.at<double>(1, 0),
      object_base_point.at<double>(2, 0),
    };
    response->depth_m = depth_m;
    response->debug_summary = summary.str();

    RCLCPP_INFO(get_logger(), "%s", response->debug_summary.c_str());
  } catch (const std::exception & e) {
    response->success = false;
    response->error_code = kException;
    response->message = e.what();
    response->debug_summary = e.what();
  }
}

bool GraspExecutionNode::requestYoloDetection(
  bool publish_debug_image,
  bool & has_sphere_center,
  std::array<double, 3> & sphere_center_m,
  double & sphere_radius_m,
  std::string & sphere_frame_id,
  std::string & sphere_class_id,
  double & sphere_confidence,
  std::string & error_message)
{
  has_sphere_center = false;
  sphere_center_m.fill(std::numeric_limits<double>::quiet_NaN());
  sphere_radius_m = std::numeric_limits<double>::quiet_NaN();
  sphere_frame_id.clear();
  sphere_class_id.clear();
  sphere_confidence = std::numeric_limits<double>::quiet_NaN();

  auto request = std::make_shared<gas_interfaces::srv::DetectObjects::Request>();
  request->publish_debug_image = publish_debug_image;
  auto response = callServiceSync<gas_interfaces::srv::DetectObjects>(
    yolo_client_, request, std::chrono::milliseconds(service_timeout_ms_), error_message);
  if (!response) {
    return false;
  }
  if (!response->success) {
    error_message = response->message;
    return false;
  }
  has_sphere_center = response->has_sphere_center;
  sphere_center_m = response->sphere_center_m;
  sphere_radius_m = response->sphere_radius_m;
  sphere_frame_id = response->sphere_frame_id;
  sphere_class_id = response->sphere_class_id;
  sphere_confidence = response->sphere_confidence;
  return true;
}

bool GraspExecutionNode::requestRobotPose(
  std::array<double, 6> & tcp_pose,
  cv::Mat & T_base_tool,
  std::string & error_message)
{
  auto request = std::make_shared<gas_interfaces::srv::RobotGetPose::Request>();
  auto response = callServiceSync<gas_interfaces::srv::RobotGetPose>(
    robot_pose_client_, request, std::chrono::milliseconds(service_timeout_ms_), error_message);
  if (!response) {
    return false;
  }
  if (!response->success) {
    error_message = response->message;
    return false;
  }
  if (response->tcp_xyz_m_rpy_rad.size() != 6) {
    error_message = "robot pose response does not contain 6 values";
    return false;
  }

  for (size_t i = 0; i < 6; ++i) {
    tcp_pose[i] = response->tcp_xyz_m_rpy_rad[i];
  }
  const cv::Mat R = rpyToRotationMatrix(tcp_pose[3], tcp_pose[4], tcp_pose[5]);
  const cv::Mat t = (cv::Mat_<double>(3, 1) << tcp_pose[0], tcp_pose[1], tcp_pose[2]);
  T_base_tool = makeHomogeneousMatrix(R, t);
  return true;
}

bool GraspExecutionNode::requestMoveL(
  const std::array<double, 6> & target_tcp_pose,
  bool wait,
  std::string & error_message)
{
  auto request = std::make_shared<gas_interfaces::srv::RobotMoveL::Request>();
  for (size_t i = 0; i < 6; ++i) {
    request->tcp_xyz_m_rpy_rad[i] = target_tcp_pose[i];
  }
  request->wait = wait;
  auto response = callServiceSync<gas_interfaces::srv::RobotMoveL>(
    robot_move_l_client_, request, std::chrono::milliseconds(move_timeout_ms_), error_message);
  if (!response) {
    return false;
  }
  if (!response->success) {
    error_message = response->message;
    return false;
  }
  return true;
}

bool GraspExecutionNode::resolveHandeyeResultFile(
  std::string & result_file,
  std::string & error_message)
{
  if (!handeye_result_file_.empty() && fs::exists(handeye_result_file_)) {
    result_file = handeye_result_file_;
    return true;
  }

  auto request = std::make_shared<gas_interfaces::srv::HandEyeGetStatus::Request>();
  auto response = callServiceSync<gas_interfaces::srv::HandEyeGetStatus>(
    handeye_status_client_, request, std::chrono::milliseconds(service_timeout_ms_), error_message);
  if (!response) {
    if (!handeye_result_file_.empty()) {
      error_message = "hand-eye result file not found: " + handeye_result_file_ +
        "; status query also failed: " + error_message;
    }
    return false;
  }
  if (!response->success) {
    error_message = response->last_error.empty() ? "hand-eye status query failed" : response->last_error;
    return false;
  }
  if (response->result_file.empty()) {
    error_message = "hand-eye result file is empty";
    return false;
  }
  result_file = response->result_file;
  if (!fs::exists(result_file)) {
    error_message = "hand-eye result file does not exist: " + result_file;
    return false;
  }
  return true;
}

bool GraspExecutionNode::loadToolCameraMatrix(
  const std::string & result_file,
  cv::Mat & T_tool_camera,
  std::string & error_message) const
{
  cv::FileStorage fs(result_file, cv::FileStorage::READ);
  if (!fs.isOpened()) {
    error_message = "failed to open hand-eye result file: " + result_file;
    return false;
  }

  cv::Mat T_read;
  fs["tool_camera_matrix"] >> T_read;
  if (T_read.empty()) {
    cv::Mat T_camera_tool;
    fs["camera_tool_matrix"] >> T_camera_tool;
    if (T_camera_tool.empty()) {
      error_message = "hand-eye result file does not contain tool_camera_matrix";
      return false;
    }
    if (T_camera_tool.type() != CV_64F) {
      T_camera_tool.convertTo(T_camera_tool, CV_64F);
    }
    if (!matrixIsValidHomogeneous(T_camera_tool)) {
      error_message = "camera_tool_matrix is not a valid 4x4 matrix";
      return false;
    }
    T_tool_camera = invertHomogeneousMatrix(T_camera_tool);
    return true;
  }

  if (T_read.type() != CV_64F) {
    T_read.convertTo(T_read, CV_64F);
  }
  if (!matrixIsValidHomogeneous(T_read)) {
    error_message = "tool_camera_matrix is not a valid 4x4 matrix";
    return false;
  }
  T_tool_camera = T_read;
  return true;
}

cv::Mat GraspExecutionNode::rpyToRotationMatrix(double rx, double ry, double rz)
{
  const double cx = std::cos(rx);
  const double sx = std::sin(rx);
  const double cy = std::cos(ry);
  const double sy = std::sin(ry);
  const double cz = std::cos(rz);
  const double sz = std::sin(rz);

  const cv::Matx33d Rx(
    1.0, 0.0, 0.0,
    0.0, cx, -sx,
    0.0, sx, cx);
  const cv::Matx33d Ry(
    cy, 0.0, sy,
    0.0, 1.0, 0.0,
    -sy, 0.0, cy);
  const cv::Matx33d Rz(
    cz, -sz, 0.0,
    sz, cz, 0.0,
    0.0, 0.0, 1.0);
  return cv::Mat(Rz * Ry * Rx);
}

cv::Mat GraspExecutionNode::makeHomogeneousMatrix(const cv::Mat & R, const cv::Mat & t)
{
  cv::Mat T = cv::Mat::eye(4, 4, CV_64F);
  CV_Assert(R.rows == 3 && R.cols == 3);
  CV_Assert(t.rows == 3 && t.cols == 1);
  R.copyTo(T(cv::Range(0, 3), cv::Range(0, 3)));
  t.copyTo(T(cv::Range(0, 3), cv::Range(3, 4)));
  return T;
}

cv::Mat GraspExecutionNode::invertHomogeneousMatrix(const cv::Mat & T)
{
  CV_Assert(matrixIsValidHomogeneous(T));
  const cv::Mat R = T(cv::Range(0, 3), cv::Range(0, 3));
  const cv::Mat t = T(cv::Range(0, 3), cv::Range(3, 4));
  const cv::Mat R_inv = R.t();
  const cv::Mat t_inv = -R_inv * t;
  return makeHomogeneousMatrix(R_inv, t_inv);
}

bool GraspExecutionNode::matrixIsValidHomogeneous(const cv::Mat & T)
{
  return T.rows == 4 && T.cols == 4 && (T.type() == CV_64F || T.type() == CV_32F);
}

std::array<double, 16> GraspExecutionNode::matrixToArray16(const cv::Mat & T)
{
  std::array<double, 16> out{};
  if (T.rows != 4 || T.cols != 4) {
    return out;
  }
  cv::Mat T64;
  if (T.type() == CV_64F) {
    T64 = T;
  } else {
    T.convertTo(T64, CV_64F);
  }
  for (int r = 0; r < 4; ++r) {
    for (int c = 0; c < 4; ++c) {
      out[static_cast<size_t>(r * 4 + c)] = T64.at<double>(r, c);
    }
  }
  return out;
}

std::string GraspExecutionNode::serviceName(
  const std::string & service_namespace,
  const std::string & name)
{
  if (service_namespace.empty() || service_namespace == "/") {
    return "/" + name;
  }
  if (service_namespace.back() == '/') {
    return service_namespace + name;
  }
  return service_namespace + "/" + name;
}

}  // namespace gas
