#include "gas_grasp_execution/grasp_execution_node.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <future>
#include <iomanip>
#include <limits>
#include <sstream>
#include <thread>

namespace gas
{
using namespace std::chrono_literals;

namespace
{
constexpr int kSuccess = 0;
constexpr int kNoDetection = -2003;
constexpr int kNoToolTransform = -2004;
constexpr int kNoRobotPose = -2005;
constexpr int kDepthInvalid = -2006;
constexpr int kMoveFailed = -2007;
constexpr int kGeometryInvalid = -2008;
constexpr int kGripperFailed = -2009;
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

bool finitePoint3(const std::array<double, 3> & point)
{
  return std::isfinite(point[0]) && std::isfinite(point[1]) && std::isfinite(point[2]);
}

}  // namespace

GraspExecutionNode::GraspExecutionNode()
: Node("gas_grasp_execution_node")
{
  yolo_service_name_ = declare_parameter<std::string>("yolo_service_name", "/yolo/detect_once");
  robot_pose_service_ = declare_parameter<std::string>("robot_pose_service", "/robot/get_pose");
  robot_move_l_service_ = declare_parameter<std::string>("robot_move_l_service", "/robot/move_l");
  gripper_activate_service_ =
    declare_parameter<std::string>("gripper_activate_service", "/gripper/activate");
  gripper_move_service_ =
    declare_parameter<std::string>("gripper_move_service", "/gripper/move");
  execute_service_name_ =
    declare_parameter<std::string>("execute_service_name", "/grasp/execute_once");

  // 为兼容现有 GraspExecute.srv，仍使用 approach_offset_m 这个名字；
  // 当前语义为 TCP 到物体中心在 base XY 平面内的水平安全距离。
  default_approach_offset_m_ = declare_parameter<double>("default_approach_offset_m", 0.20);
  min_valid_depth_m_ = declare_parameter<double>("min_valid_depth_m", 0.05);
  max_valid_depth_m_ = declare_parameter<double>("max_valid_depth_m", 5.0);
  min_horizontal_direction_m_ =
    declare_parameter<double>("min_horizontal_direction_m", 1e-4);
  service_timeout_ms_ = declare_parameter<int>("service_timeout_ms", 3000);
  move_timeout_ms_ = declare_parameter<int>("move_timeout_ms", 30000);
  gripper_service_timeout_ms_ = declare_parameter<int>("gripper_service_timeout_ms", 10000);

  if (default_approach_offset_m_ <= 0.0) {
    default_approach_offset_m_ = 0.20;
  }
  if (min_valid_depth_m_ <= 0.0) {
    min_valid_depth_m_ = 0.05;
  }
  if (max_valid_depth_m_ <= min_valid_depth_m_) {
    max_valid_depth_m_ = std::max(1.0, min_valid_depth_m_ * 10.0);
  }
  if (min_horizontal_direction_m_ <= 0.0) {
    min_horizontal_direction_m_ = 1e-4;
  }
  if (service_timeout_ms_ <= 0) {
    service_timeout_ms_ = 3000;
  }
  if (move_timeout_ms_ <= 0) {
    move_timeout_ms_ = 30000;
  }
  if (gripper_service_timeout_ms_ <= 0) {
    gripper_service_timeout_ms_ = 10000;
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
  gripper_activate_client_ = create_client<gas_interfaces::srv::GripperActivate>(
    gripper_activate_service_,
    rmw_qos_profile_services_default,
    client_group_);
  gripper_move_client_ = create_client<gas_interfaces::srv::GripperMove>(
    gripper_move_service_,
    rmw_qos_profile_services_default,
    client_group_);

  execute_srv_ = create_service<gas_interfaces::srv::GraspExecute>(
    execute_service_name_,
    std::bind(
      &GraspExecutionNode::executeCallback, this,
      std::placeholders::_1, std::placeholders::_2),
    rmw_qos_profile_services_default,
    service_group_);

  RCLCPP_INFO(get_logger(), "grasp service: %s", execute_service_name_.c_str());
  RCLCPP_INFO(get_logger(), "yolo service: %s", yolo_service_name_.c_str());
  RCLCPP_INFO(get_logger(), "robot pose service: %s", robot_pose_service_.c_str());
  RCLCPP_INFO(get_logger(), "robot move_l service: %s", robot_move_l_service_.c_str());
  RCLCPP_INFO(get_logger(), "gripper activate service: %s", gripper_activate_service_.c_str());
  RCLCPP_INFO(get_logger(), "gripper move service: %s", gripper_move_service_.c_str());
  RCLCPP_INFO(
    get_logger(),
    "default horizontal standoff: %.3f m",
    default_approach_offset_m_);
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

    if (request->close_gripper) {
      if (!request->wait) {
        response->error_code = kGripperFailed;
        response->message = "close_gripper requires wait=true so the robot reaches pre-grasp first";
        return;
      }
      if (request->gripper_index < 0 || request->gripper_position < 0 ||
        request->gripper_position > 100 || request->gripper_velocity < 0 ||
        request->gripper_velocity > 100 || request->gripper_force < 0 ||
        request->gripper_force > 100 || request->gripper_max_time_ms < 0 ||
        request->gripper_max_time_ms > 30000)
      {
        response->error_code = kGripperFailed;
        response->message =
          "invalid gripper parameters: index >= 0, position/velocity/force in [0,100], "
          "max_time_ms in [0,30000]";
        return;
      }
    }

    bool has_sphere_center = false;
    std::array<double, 3> sphere_center_m{};
    double sphere_radius_m = std::numeric_limits<double>::quiet_NaN();
    std::string sphere_frame_id;
    std::string sphere_class_id;
    double sphere_confidence = std::numeric_limits<double>::quiet_NaN();

    bool has_sphere_center_tool = false;
    std::array<double, 3> sphere_center_tool_m{};
    std::string sphere_tool_frame_id;

    std::string yolo_error;
    if (!requestYoloDetection(
          request->publish_debug_image,
          has_sphere_center,
          sphere_center_m,
          sphere_radius_m,
          sphere_frame_id,
          sphere_class_id,
          sphere_confidence,
          has_sphere_center_tool,
          sphere_center_tool_m,
          sphere_tool_frame_id,
          yolo_error))
    {
      response->error_code = kNoDetection;
      response->message = yolo_error;
      return;
    }

    if (!has_sphere_center || !finitePoint3(sphere_center_m)) {
      response->error_code = kNoDetection;
      response->message = "YOLO did not return a valid fitted 3D sphere center in camera frame";
      return;
    }

    const double depth_m = sphere_center_m[2];
    if (depth_m < min_valid_depth_m_ || depth_m > max_valid_depth_m_) {
      response->error_code = kDepthInvalid;
      response->message = "YOLO returned a sphere center outside the valid camera depth range";
      return;
    }

    if (!has_sphere_center_tool || !finitePoint3(sphere_center_tool_m)) {
      response->error_code = kNoToolTransform;
      response->message =
        "YOLO did not return a valid sphere center in tool frame; check hand-eye transform in yolo_cpp";
      return;
    }

    std::array<double, 6> current_tcp_pose{};
    cv::Mat T_base_tool;
    std::string robot_error;
    if (!requestRobotPose(current_tcp_pose, T_base_tool, robot_error)) {
      response->error_code = kNoRobotPose;
      response->message = robot_error;
      return;
    }

    // 视觉服务已经完成 camera -> tool：
    //   p_tool = T_tool_camera * p_camera
    // 执行层只负责 tool -> base：
    //   p_base = T_base_tool * p_tool
    const cv::Mat object_tool_point = (cv::Mat_<double>(4, 1) <<
      sphere_center_tool_m[0], sphere_center_tool_m[1], sphere_center_tool_m[2], 1.0);
    const cv::Mat object_base_point = T_base_tool * object_tool_point;

    const std::array<double, 3> object_base_m{
      object_base_point.at<double>(0, 0),
      object_base_point.at<double>(1, 0),
      object_base_point.at<double>(2, 0),
    };

    if (!finitePoint3(object_base_m)) {
      response->error_code = kGeometryInvalid;
      response->message = "tool-to-base transform produced an invalid object point";
      return;
    }

    const double horizontal_standoff_m = request->approach_offset_m > 0.0
      ? request->approach_offset_m
      : default_approach_offset_m_;

    // 在 base XY 平面上，以“物体中心 -> 当前 TCP”的方向作为接近方向。
    // 预抓取点位于物体中心外侧 horizontal_standoff_m 处，同时令 TCP z = object z。
    // 因此 TCP 与物体中心处于同一水平面，水平距离固定为 0.20 m（默认）。
    const double dx = current_tcp_pose[0] - object_base_m[0];
    const double dy = current_tcp_pose[1] - object_base_m[1];
    const double current_horizontal_distance_m = std::hypot(dx, dy);

    if (!std::isfinite(current_horizontal_distance_m) ||
      current_horizontal_distance_m < min_horizontal_direction_m_)
    {
      response->error_code = kGeometryInvalid;
      response->message =
        "cannot determine horizontal approach direction because current TCP is vertically aligned with object";
      return;
    }

    const double ux = dx / current_horizontal_distance_m;
    const double uy = dy / current_horizontal_distance_m;

    std::array<double, 6> target_tcp_pose = current_tcp_pose;
    target_tcp_pose[0] = object_base_m[0] + horizontal_standoff_m * ux;
    target_tcp_pose[1] = object_base_m[1] + horizontal_standoff_m * uy;
    target_tcp_pose[2] = object_base_m[2];
    // rx/ry/rz 保持当前 TCP 姿态不变。

    const double target_horizontal_distance_m = std::hypot(
      target_tcp_pose[0] - object_base_m[0],
      target_tcp_pose[1] - object_base_m[1]);

    std::ostringstream summary;
    summary << std::fixed << std::setprecision(4)
            << "source=sphere_center_tool"
            << " sphere_class=" << sphere_class_id
            << " sphere_confidence=" << sphere_confidence
            << " sphere_radius_m=" << sphere_radius_m
            << " camera_depth_m=" << depth_m
            << " object_camera=" << formatFloat3(sphere_center_m)
            << " camera_frame=" << sphere_frame_id
            << " object_tool=" << formatFloat3(sphere_center_tool_m)
            << " tool_frame=" << sphere_tool_frame_id
            << " object_base=" << formatFloat3(object_base_m)
            << " current_tcp_base=[" << current_tcp_pose[0] << ", "
            << current_tcp_pose[1] << ", " << current_tcp_pose[2] << "]"
            << " target_tcp_base=[" << target_tcp_pose[0] << ", "
            << target_tcp_pose[1] << ", " << target_tcp_pose[2] << "]"
            << " requested_horizontal_standoff_m=" << horizontal_standoff_m
            << " actual_horizontal_standoff_m=" << target_horizontal_distance_m;

    std::string move_error;
    if (!requestMoveL(target_tcp_pose, request->wait, move_error)) {
      response->error_code = kMoveFailed;
      response->message = move_error;
      response->target_tcp_xyz_m_rpy_rad = target_tcp_pose;
      response->object_point_camera_m = sphere_center_m;
      response->object_point_base_m = object_base_m;
      response->depth_m = depth_m;
      response->debug_summary = summary.str();
      return;
    }

    response->success = true;
    response->error_code = kSuccess;
    response->message = request->wait
      ? "horizontal pre-grasp target reached"
      : "horizontal pre-grasp move command sent";
    response->target_tcp_xyz_m_rpy_rad = target_tcp_pose;
    response->object_point_camera_m = sphere_center_m;
    response->object_point_base_m = object_base_m;
    response->depth_m = depth_m;
    response->debug_summary = summary.str();

    if (request->close_gripper) {
      std::string gripper_error;
      if (request->activate_gripper &&
        !requestGripperActivation(request->gripper_index, true, gripper_error))
      {
        response->success = false;
        response->error_code = kGripperFailed;
        response->message = gripper_error;
        response->debug_summary += " gripper_activation=failed";
        return;
      }
      if (!requestGripperMove(
          request->gripper_index,
          request->gripper_position,
          request->gripper_velocity,
          request->gripper_force,
          request->gripper_max_time_ms,
          request->gripper_wait,
          gripper_error))
      {
        response->success = false;
        response->error_code = kGripperFailed;
        response->message = gripper_error;
        response->debug_summary += " gripper_move=failed";
        return;
      }
      response->message = request->gripper_wait
        ? "horizontal pre-grasp target reached and gripper motion completed"
        : "horizontal pre-grasp target reached and gripper motion command sent";
      response->debug_summary += " gripper_close_requested=true";
    }

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
  bool & has_sphere_center_tool,
  std::array<double, 3> & sphere_center_tool_m,
  std::string & sphere_tool_frame_id,
  std::string & error_message)
{
  has_sphere_center = false;
  sphere_center_m.fill(std::numeric_limits<double>::quiet_NaN());
  sphere_radius_m = std::numeric_limits<double>::quiet_NaN();
  sphere_frame_id.clear();
  sphere_class_id.clear();
  sphere_confidence = std::numeric_limits<double>::quiet_NaN();

  has_sphere_center_tool = false;
  sphere_center_tool_m.fill(std::numeric_limits<double>::quiet_NaN());
  sphere_tool_frame_id.clear();

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

  has_sphere_center_tool = response->has_sphere_center_tool;
  sphere_center_tool_m = response->sphere_center_tool_m;
  sphere_tool_frame_id = response->sphere_tool_frame_id;
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

bool GraspExecutionNode::requestGripperActivation(
  int gripper_index, bool activate, std::string & error_message)
{
  auto request = std::make_shared<gas_interfaces::srv::GripperActivate::Request>();
  request->gripper_index = gripper_index;
  request->activate = activate;
  auto response = callServiceSync<gas_interfaces::srv::GripperActivate>(
    gripper_activate_client_, request,
    std::chrono::milliseconds(gripper_service_timeout_ms_), error_message);
  if (!response) {
    return false;
  }
  if (!response->success) {
    error_message = response->message;
    return false;
  }
  return true;
}

bool GraspExecutionNode::requestGripperMove(
  int gripper_index,
  int position,
  int velocity,
  int force,
  int max_time_ms,
  bool wait,
  std::string & error_message)
{
  auto request = std::make_shared<gas_interfaces::srv::GripperMove::Request>();
  request->gripper_index = gripper_index;
  request->position = position;
  request->velocity = velocity;
  request->force = force;
  request->max_time_ms = max_time_ms;
  request->wait = wait;
  auto response = callServiceSync<gas_interfaces::srv::GripperMove>(
    gripper_move_client_, request,
    std::chrono::milliseconds(gripper_service_timeout_ms_), error_message);
  if (!response) {
    return false;
  }
  if (!response->success) {
    error_message = response->message;
    return false;
  }
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

}  // namespace gas
