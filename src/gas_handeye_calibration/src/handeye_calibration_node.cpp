#include "handeye_calibration_node.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <system_error>

#include <sensor_msgs/image_encodings.hpp>
#include <std_msgs/msg/header.hpp>

namespace gas
{
namespace fs = std::filesystem;

namespace
{
constexpr int kSuccess = 0;
constexpr int kNoImage = -1002;
constexpr int kRobotUnavailable = -1004;
constexpr int kDetectionFailed = -1006;
constexpr int kNotEnoughSamples = -1008;
constexpr int kSaveFailed = -1009;
constexpr int kException = -1999;

template<typename ResponseT>
void setResponse(ResponseT & response, int error_code, const std::string & message)
{
  response.success = (error_code == kSuccess);
  response.error_code = error_code;
  response.message = message;
}

double clampDouble(double value, double low, double high)
{
  return std::max(low, std::min(value, high));
}

std::string toUpper(std::string value)
{
  std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
    return static_cast<char>(std::toupper(c));
  });
  return value;
}

std::string recordPath(const std::string & path_string)
{
  if (path_string.empty()) {
    return "";
  }

  const fs::path path(path_string);
  if (!path.is_absolute()) {
    return path.generic_string();
  }

  std::error_code ec;
  const fs::path cwd = fs::current_path(ec);
  if (ec) {
    return path.generic_string();
  }
  const fs::path relative_path = fs::relative(path, cwd, ec);
  if (!ec && !relative_path.empty()) {
    const std::string value = relative_path.generic_string();
    if (value == "." || (value != ".." && value.rfind("../", 0) != 0)) {
      return value;
    }
  }
  return path.generic_string();
}
}  // namespace

HandEyeCalibrationNode::HandEyeCalibrationNode()
: Node("handeye_calibration_node")
{
  service_namespace_ = declare_parameter<std::string>("service_namespace", "/handeye");
  image_topic_ = declare_parameter<std::string>("image_topic", "/camera/color/image_raw");
  camera_info_topic_ =
    declare_parameter<std::string>("camera_info_topic", "/camera/color/camera_info");
  robot_pose_service_ = declare_parameter<std::string>("robot_pose_service", "/robot/get_pose");
  save_root_dir_ = declare_parameter<std::string>("save_root_dir", "calibration_data/handeye");
  session_name_ = declare_parameter<std::string>("session_name", "");
  publish_debug_image_ = declare_parameter<bool>("publish_debug_image", true);
  robot_pose_timeout_ms_ = declare_parameter<int>("robot_pose_timeout_ms", 2000);
  board_dictionary_id_ = declare_parameter<int>("board_dictionary_id", cv::aruco::DICT_5X5_1000);
  board_squares_x_ = declare_parameter<int>("board_squares_x", 10);
  board_squares_y_ = declare_parameter<int>("board_squares_y", 7);
  board_square_length_m_ = declare_parameter<double>("board_square_length_m", 0.025);
  board_marker_length_m_ = declare_parameter<double>("board_marker_length_m", 0.018);
  handeye_method_ = declare_parameter<std::string>("handeye_method", "TSAI");
  min_samples_ = declare_parameter<int>("min_samples", 5);

  if (board_squares_x_ < 2 || board_squares_y_ < 2) {
    throw std::runtime_error("board_squares_x and board_squares_y must be >= 2");
  }
  if (board_square_length_m_ <= 0.0 || board_marker_length_m_ <= 0.0) {
    throw std::runtime_error("board square and marker length must be positive");
  }
  if (board_marker_length_m_ >= board_square_length_m_) {
    throw std::runtime_error("board_marker_length_m must be smaller than board_square_length_m");
  }
  if (min_samples_ < 1) {
    throw std::runtime_error("min_samples must be >= 1");
  }
  if (robot_pose_timeout_ms_ <= 0) {
    throw std::runtime_error("robot_pose_timeout_ms must be positive");
  }

  if (session_name_.empty()) {
    session_name_ = nowString();
  }
  session_dir_ = (fs::path(save_root_dir_) / session_name_).string();
  samples_dir_ = (fs::path(session_dir_) / "samples").string();
  debug_dir_ = (fs::path(session_dir_) / "debug").string();
  results_dir_ = (fs::path(session_dir_) / "results").string();
  session_metadata_file_ = makeSessionMetadataFile();

  fs::create_directories(samples_dir_);
  fs::create_directories(debug_dir_);
  fs::create_directories(results_dir_);

  dictionary_ = cv::aruco::getPredefinedDictionary(board_dictionary_id_);
  board_ = cv::aruco::CharucoBoard::create(
    board_squares_x_,
    board_squares_y_,
    static_cast<float>(board_square_length_m_),
    static_cast<float>(board_marker_length_m_),
    dictionary_);
  detector_params_ = cv::aruco::DetectorParameters::create();

  service_group_ = create_callback_group(rclcpp::CallbackGroupType::Reentrant);
  client_group_ = create_callback_group(rclcpp::CallbackGroupType::Reentrant);

  rclcpp::SubscriptionOptions sub_options;
  sub_options.callback_group = service_group_;

  image_sub_ = create_subscription<sensor_msgs::msg::Image>(
    image_topic_,
    rclcpp::SensorDataQoS(),
    std::bind(&HandEyeCalibrationNode::imageCallback, this, std::placeholders::_1),
    sub_options);
  camera_info_sub_ = create_subscription<sensor_msgs::msg::CameraInfo>(
    camera_info_topic_,
    rclcpp::SensorDataQoS(),
    std::bind(&HandEyeCalibrationNode::cameraInfoCallback, this, std::placeholders::_1),
    sub_options);

  debug_image_pub_ = create_publisher<sensor_msgs::msg::Image>(
    serviceName(service_namespace_, "debug_image"),
    rclcpp::SensorDataQoS());

  robot_pose_client_ = create_client<gas_interfaces::srv::RobotGetPose>(
    robot_pose_service_,
    rmw_qos_profile_services_default,
    client_group_);

  add_sample_srv_ = create_service<gas_interfaces::srv::HandEyeAddSample>(
    serviceName(service_namespace_, "add_sample"),
    std::bind(&HandEyeCalibrationNode::addSampleCallback, this, std::placeholders::_1, std::placeholders::_2),
    rmw_qos_profile_services_default,
    service_group_);

  clear_samples_srv_ = create_service<gas_interfaces::srv::HandEyeClearSamples>(
    serviceName(service_namespace_, "clear_samples"),
    std::bind(
      &HandEyeCalibrationNode::clearSamplesCallback, this, std::placeholders::_1,
      std::placeholders::_2),
    rmw_qos_profile_services_default,
    service_group_);

  compute_srv_ = create_service<gas_interfaces::srv::HandEyeCompute>(
    serviceName(service_namespace_, "compute"),
    std::bind(&HandEyeCalibrationNode::computeCallback, this, std::placeholders::_1, std::placeholders::_2),
    rmw_qos_profile_services_default,
    service_group_);

  status_srv_ = create_service<gas_interfaces::srv::HandEyeGetStatus>(
    serviceName(service_namespace_, "status"),
    std::bind(&HandEyeCalibrationNode::statusCallback, this, std::placeholders::_1, std::placeholders::_2),
    rmw_qos_profile_services_default,
    service_group_);

  saveSessionMetadata();

  RCLCPP_INFO(this->get_logger(), "hand-eye session dir: %s", session_dir_.c_str());
  RCLCPP_INFO(this->get_logger(), "image topic: %s", image_topic_.c_str());
  RCLCPP_INFO(this->get_logger(), "camera info topic: %s", camera_info_topic_.c_str());
  RCLCPP_INFO(this->get_logger(), "robot pose service: %s", robot_pose_service_.c_str());
  RCLCPP_INFO(this->get_logger(), "hand-eye services under: %s", service_namespace_.c_str());
}

void HandEyeCalibrationNode::imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr msg)
{
  try {
    cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    std::lock_guard<std::mutex> lock(data_mutex_);
    latest_image_bgr_ = cv_ptr->image.clone();
    latest_image_header_ = msg->header;
    has_image_ = true;
  } catch (const std::exception & e) {
    RCLCPP_WARN(this->get_logger(), "failed to convert image: %s", e.what());
  }
}

void HandEyeCalibrationNode::cameraInfoCallback(
  const sensor_msgs::msg::CameraInfo::ConstSharedPtr msg)
{
  std::lock_guard<std::mutex> lock(data_mutex_);
  latest_camera_info_ = *msg;
  latest_camera_matrix_ = buildCameraMatrixFromInfo(*msg);
  latest_dist_coeffs_ = buildDistCoeffsFromInfo(*msg);
  has_camera_info_ = !latest_camera_matrix_.empty();
}

void HandEyeCalibrationNode::addSampleCallback(
  const std::shared_ptr<gas_interfaces::srv::HandEyeAddSample::Request> /*request*/,
  std::shared_ptr<gas_interfaces::srv::HandEyeAddSample::Response> response)
{
  try {
    cv::Mat image_bgr;
    std_msgs::msg::Header header;
    cv::Mat camera_matrix;
    cv::Mat dist_coeffs;
    std::string snapshot_error;
    if (!getLatestSnapshot(image_bgr, header, camera_matrix, dist_coeffs, snapshot_error)) {
      {
        std::lock_guard<std::mutex> lock(data_mutex_);
        last_error_ = snapshot_error;
      }
      setResponse(*response, kNoImage, snapshot_error.empty() ? "no image or camera info" : snapshot_error);
      response->sample_id = -1;
      response->sample_count = sampleCount();
      response->reprojection_error_px = -1.0;
      response->image_path.clear();
      response->debug_image_path.clear();
      response->sample_file.clear();
      return;
    }

    const int sample_id = next_sample_id_++;
    const std::string raw_image_file = makeSampleImageFile(sample_id);
    const std::string debug_image_file = makeSampleDebugFile(sample_id);
    const std::string sample_file = makeSampleYamlFile(sample_id);

    if (!cv::imwrite(raw_image_file, image_bgr)) {
      {
        std::lock_guard<std::mutex> lock(data_mutex_);
        last_error_ = "failed to save captured image";
      }
      setResponse(*response, kSaveFailed, "failed to save captured image");
      response->sample_id = sample_id;
      response->sample_count = sampleCount();
      response->image_path = recordPath(raw_image_file);
      return;
    }

    cv::Mat T_base_tool;
    std::string robot_error;
    if (!requestRobotPose(T_base_tool, robot_error)) {
      {
        std::lock_guard<std::mutex> lock(data_mutex_);
        last_error_ = robot_error;
      }
      setResponse(*response, kRobotUnavailable, robot_error);
      response->sample_id = sample_id;
      response->sample_count = sampleCount();
      response->image_path = recordPath(raw_image_file);
      return;
    }

    std::vector<cv::Point2f> charuco_corners;
    std::vector<int> charuco_ids;
    cv::Vec3d rvec;
    cv::Vec3d tvec;
    double reprojection_error_px = 0.0;
    cv::Mat annotated_image;
    std::string detection_error;
    if (!estimateBoardPose(
          image_bgr, camera_matrix, dist_coeffs, charuco_corners, charuco_ids, rvec, tvec,
          reprojection_error_px, annotated_image, detection_error)) {
      {
        std::lock_guard<std::mutex> lock(data_mutex_);
        last_error_ = detection_error;
      }
      setResponse(*response, kDetectionFailed, detection_error);
      response->sample_id = sample_id;
      response->sample_count = sampleCount();
      response->image_path = recordPath(raw_image_file);
      response->debug_image_path = recordPath(debug_image_file);
      return;
    }

    cv::Mat R_camera_board;
    const cv::Mat rvec_mat = (cv::Mat_<double>(3, 1) << rvec[0], rvec[1], rvec[2]);
    cv::Rodrigues(rvec_mat, R_camera_board);
    cv::Mat t_camera_board = (cv::Mat_<double>(3, 1) << tvec[0], tvec[1], tvec[2]);
    cv::Mat T_camera_board = makeHomogeneousMatrix(R_camera_board, t_camera_board);

    Sample sample;
    sample.sample_id = sample_id;
    sample.stamp = rclcpp::Time(header.stamp);
    sample.frame_id = header.frame_id;
    sample.image_file = raw_image_file;
    sample.debug_image_file = debug_image_file;
    sample.sample_file = sample_file;
    sample.image_bgr = image_bgr.clone();
    sample.camera_matrix = camera_matrix.clone();
    sample.dist_coeffs = dist_coeffs.clone();
    sample.charuco_corners = charuco_corners;
    sample.charuco_ids = charuco_ids;
    sample.board_rvec = rvec;
    sample.board_tvec = tvec;
    sample.T_base_tool = T_base_tool.clone();
    sample.T_camera_board = T_camera_board.clone();
    sample.reprojection_error_px = reprojection_error_px;

    std::string save_error;
    if (!saveSampleFiles(sample, save_error)) {
      {
        std::lock_guard<std::mutex> lock(data_mutex_);
        last_error_ = save_error;
      }
      setResponse(*response, kSaveFailed, save_error);
      response->sample_id = sample_id;
      response->sample_count = sampleCount();
      response->image_path = recordPath(raw_image_file);
      response->debug_image_path = recordPath(debug_image_file);
      response->sample_file = recordPath(sample_file);
      return;
    }

    if (!cv::imwrite(debug_image_file, annotated_image)) {
      {
        std::lock_guard<std::mutex> lock(data_mutex_);
        last_error_ = "failed to save debug image";
      }
      setResponse(*response, kSaveFailed, "failed to save debug image");
      response->sample_id = sample_id;
      response->sample_count = sampleCount();
      response->image_path = recordPath(raw_image_file);
      response->debug_image_path = recordPath(debug_image_file);
      response->sample_file = recordPath(sample_file);
      return;
    }

    if (publish_debug_image_) {
      cv_bridge::CvImage debug_msg;
      debug_msg.encoding = sensor_msgs::image_encodings::BGR8;
      debug_msg.header = header;
      debug_msg.image = annotated_image;
      debug_image_pub_->publish(*debug_msg.toImageMsg());
    }

    {
      std::lock_guard<std::mutex> lock(data_mutex_);
      samples_.push_back(sample);
      has_robot_pose_ = true;
      last_sample_id_ = sample_id;
      last_reprojection_error_px_ = reprojection_error_px;
      last_error_.clear();
      last_sample_file_ = recordPath(sample_file);
    }

    setResponse(*response, kSuccess, "sample stored");
    response->sample_id = sample_id;
    response->sample_count = sampleCount();
    response->reprojection_error_px = reprojection_error_px;
    response->image_path = recordPath(raw_image_file);
    response->debug_image_path = recordPath(debug_image_file);
    response->sample_file = recordPath(sample_file);
  } catch (const std::exception & e) {
    {
      std::lock_guard<std::mutex> lock(data_mutex_);
      last_error_ = e.what();
    }
    setResponse(*response, kException, e.what());
    response->sample_id = -1;
    response->sample_count = sampleCount();
  }
}

void HandEyeCalibrationNode::clearSamplesCallback(
  const std::shared_ptr<gas_interfaces::srv::HandEyeClearSamples::Request> /*request*/,
  std::shared_ptr<gas_interfaces::srv::HandEyeClearSamples::Response> response)
{
  std::lock_guard<std::mutex> lock(data_mutex_);
  samples_.clear();
  has_robot_pose_ = false;
  has_calibration_ = false;
  last_reprojection_error_px_ = -1.0;
  last_sample_id_ = -1;
  last_error_.clear();
  last_sample_file_.clear();
  last_result_file_.clear();
  last_T_tool_camera_.release();
  last_T_camera_tool_.release();
  response->success = true;
  response->error_code = kSuccess;
  response->message = "samples cleared";
  response->sample_count = 0;
}

void HandEyeCalibrationNode::computeCallback(
  const std::shared_ptr<gas_interfaces::srv::HandEyeCompute::Request> request,
  std::shared_ptr<gas_interfaces::srv::HandEyeCompute::Response> response)
{
  try {
    std::vector<Sample> samples_copy;
    {
      std::lock_guard<std::mutex> lock(data_mutex_);
      samples_copy = samples_;
    }

    if (samples_copy.size() < static_cast<size_t>(min_samples_)) {
      {
        std::lock_guard<std::mutex> lock(data_mutex_);
        last_error_ = "not enough samples";
      }
      setResponse(*response, kNotEnoughSamples, "not enough samples");
      response->sample_count = static_cast<int32_t>(samples_copy.size());
      response->rms_reprojection_error_px = -1.0;
      return;
    }

    std::vector<cv::Mat> R_gripper2base;
    std::vector<cv::Mat> t_gripper2base;
    std::vector<cv::Mat> R_target2cam;
    std::vector<cv::Mat> t_target2cam;
    R_gripper2base.reserve(samples_copy.size());
    t_gripper2base.reserve(samples_copy.size());
    R_target2cam.reserve(samples_copy.size());
    t_target2cam.reserve(samples_copy.size());

    double reprojection_error_sq_weight_sum = 0.0;
    double reprojection_point_count = 0.0;
    for (const auto & sample : samples_copy) {
      cv::Mat R_gripper = sample.T_base_tool(cv::Range(0, 3), cv::Range(0, 3)).clone();
      cv::Mat t_gripper = sample.T_base_tool(cv::Range(0, 3), cv::Range(3, 4)).clone();
      cv::Mat R_target = sample.T_camera_board(cv::Range(0, 3), cv::Range(0, 3)).clone();
      cv::Mat t_target = sample.T_camera_board(cv::Range(0, 3), cv::Range(3, 4)).clone();
      R_gripper2base.push_back(R_gripper);
      t_gripper2base.push_back(t_gripper);
      R_target2cam.push_back(R_target);
      t_target2cam.push_back(t_target);
      const double point_count = static_cast<double>(std::max<size_t>(1, sample.charuco_ids.size()));
      reprojection_error_sq_weight_sum +=
        sample.reprojection_error_px * sample.reprojection_error_px * point_count;
      reprojection_point_count += point_count;
    }

    cv::Mat R_cam2gripper;
    cv::Mat t_cam2gripper;
    const int method = handEyeMethodFromString(handeye_method_);
    cv::calibrateHandEye(
      R_gripper2base,
      t_gripper2base,
      R_target2cam,
      t_target2cam,
      R_cam2gripper,
      t_cam2gripper,
      static_cast<cv::HandEyeCalibrationMethod>(method));

    cv::Mat T_tool_camera = makeHomogeneousMatrix(R_cam2gripper, t_cam2gripper);
    cv::Mat T_camera_tool = invertHomogeneousMatrix(T_tool_camera);

    std::vector<cv::Mat> T_base_board_list;
    T_base_board_list.reserve(samples_copy.size());
    for (const auto & sample : samples_copy) {
      const cv::Mat T_base_board = sample.T_base_tool * T_tool_camera * sample.T_camera_board;
      T_base_board_list.push_back(T_base_board);
    }

    double closure_translation_rms_m = 0.0;
    double closure_rotation_rms_deg = 0.0;
    if (!T_base_board_list.empty()) {
      const cv::Mat T_ref = T_base_board_list.front();
      double trans_sq_sum = 0.0;
      double rot_sq_sum = 0.0;
      for (const auto & T_i : T_base_board_list) {
        const cv::Mat T_rel = invertHomogeneousMatrix(T_ref) * T_i;
        const cv::Mat R_rel = T_rel(cv::Range(0, 3), cv::Range(0, 3));
        const cv::Mat t_rel = T_rel(cv::Range(0, 3), cv::Range(3, 4));
        const double trans_err = cv::norm(t_rel);
        const double trace = R_rel.at<double>(0, 0) + R_rel.at<double>(1, 1) + R_rel.at<double>(2, 2);
        const double angle_rad = std::acos(clampDouble((trace - 1.0) * 0.5, -1.0, 1.0));
        trans_sq_sum += trans_err * trans_err;
        rot_sq_sum += angle_rad * angle_rad;
      }
      closure_translation_rms_m = std::sqrt(trans_sq_sum / static_cast<double>(T_base_board_list.size()));
      closure_rotation_rms_deg =
        std::sqrt(rot_sq_sum / static_cast<double>(T_base_board_list.size())) * 180.0 / M_PI;
    }

    const std::string output_path = request->output_path.empty()
      ? makeResultFile("")
      : makeResultFile(request->output_path);

    std::string result_file;
    std::string save_error;
    const double reprojection_rms_px = reprojection_point_count > 0.0
      ? std::sqrt(reprojection_error_sq_weight_sum / reprojection_point_count)
      : 0.0;
    if (!saveResultFile(
          output_path, T_tool_camera, T_camera_tool, samples_copy, reprojection_rms_px,
          closure_translation_rms_m, closure_rotation_rms_deg, result_file, save_error)) {
      {
        std::lock_guard<std::mutex> lock(data_mutex_);
        last_error_ = save_error;
      }
      setResponse(*response, kSaveFailed, save_error);
      response->sample_count = static_cast<int32_t>(samples_copy.size());
      response->rms_reprojection_error_px = reprojection_rms_px;
      return;
    }

    {
      std::lock_guard<std::mutex> lock(data_mutex_);
      has_calibration_ = true;
      last_T_tool_camera_ = T_tool_camera.clone();
      last_T_camera_tool_ = T_camera_tool.clone();
      last_result_file_ = result_file;
      last_reprojection_error_px_ = reprojection_rms_px;
      last_error_.clear();
    }

    response->success = true;
    response->error_code = kSuccess;
    response->message = "hand-eye calibration computed";
    response->sample_count = static_cast<int32_t>(samples_copy.size());
    response->rms_reprojection_error_px = reprojection_rms_px;
    response->tool_camera_matrix = matrixToArray16(T_tool_camera);
    response->camera_tool_matrix = matrixToArray16(T_camera_tool);
    response->result_file = result_file;
  } catch (const std::exception & e) {
    {
      std::lock_guard<std::mutex> lock(data_mutex_);
      last_error_ = e.what();
    }
    setResponse(*response, kException, e.what());
    response->sample_count = sampleCount();
    response->rms_reprojection_error_px = -1.0;
  }
}

void HandEyeCalibrationNode::statusCallback(
  const std::shared_ptr<gas_interfaces::srv::HandEyeGetStatus::Request> /*request*/,
  std::shared_ptr<gas_interfaces::srv::HandEyeGetStatus::Response> response)
{
  std::lock_guard<std::mutex> lock(data_mutex_);
  response->success = true;
  response->sample_count = static_cast<int32_t>(samples_.size());
  response->has_image = has_image_;
  response->has_camera_info = has_camera_info_;
  response->has_robot_pose = has_robot_pose_;
  response->has_calibration = has_calibration_;
  response->last_reprojection_error_px = last_reprojection_error_px_;
  response->last_error = last_error_;
  response->last_sample_id = last_sample_id_;
  response->last_sample_file = last_sample_file_;
  response->result_file = last_result_file_;
}

bool HandEyeCalibrationNode::getLatestSnapshot(
  cv::Mat & image_bgr,
  std_msgs::msg::Header & header,
  cv::Mat & camera_matrix,
  cv::Mat & dist_coeffs,
  std::string & error_message) const
{
  std::lock_guard<std::mutex> lock(data_mutex_);
  if (!has_image_) {
    error_message = "no color image received";
    return false;
  }
  if (!has_camera_info_) {
    error_message = "no camera info received";
    return false;
  }
  image_bgr = latest_image_bgr_.clone();
  header = latest_image_header_;
  camera_matrix = latest_camera_matrix_.clone();
  dist_coeffs = latest_dist_coeffs_.clone();
  return true;
}

int32_t HandEyeCalibrationNode::sampleCount() const
{
  std::lock_guard<std::mutex> lock(data_mutex_);
  return static_cast<int32_t>(samples_.size());
}

bool HandEyeCalibrationNode::requestRobotPose(cv::Mat & T_base_tool, std::string & error_message)
{
  if (!robot_pose_client_) {
    error_message = "robot pose client not initialized";
    return false;
  }
  if (!robot_pose_client_->wait_for_service(std::chrono::milliseconds(robot_pose_timeout_ms_))) {
    error_message = "robot pose service unavailable";
    return false;
  }

  auto request = std::make_shared<gas_interfaces::srv::RobotGetPose::Request>();
  auto future = robot_pose_client_->async_send_request(request);
  const auto status = future.wait_for(std::chrono::milliseconds(robot_pose_timeout_ms_));
  if (status != std::future_status::ready) {
    error_message = "robot pose request timeout";
    return false;
  }

  auto response = future.get();
  if (!response->success) {
    std::ostringstream oss;
    oss << "robot pose request failed: " << response->error_code << " " << response->message;
    error_message = oss.str();
    return false;
  }
  if (response->tcp_xyz_m_rpy_rad.size() != 6) {
    error_message = "robot pose response size is not 6";
    return false;
  }

  const double x = response->tcp_xyz_m_rpy_rad[0];
  const double y = response->tcp_xyz_m_rpy_rad[1];
  const double z = response->tcp_xyz_m_rpy_rad[2];
  const double rx = response->tcp_xyz_m_rpy_rad[3];
  const double ry = response->tcp_xyz_m_rpy_rad[4];
  const double rz = response->tcp_xyz_m_rpy_rad[5];

  const cv::Mat R = rpyToRotationMatrix(rx, ry, rz);
  const cv::Mat t = (cv::Mat_<double>(3, 1) << x, y, z);
  T_base_tool = makeHomogeneousMatrix(R, t);
  return true;
}

bool HandEyeCalibrationNode::estimateBoardPose(
  const cv::Mat & image_bgr,
  const cv::Mat & camera_matrix,
  const cv::Mat & dist_coeffs,
  std::vector<cv::Point2f> & charuco_corners,
  std::vector<int> & charuco_ids,
  cv::Vec3d & rvec,
  cv::Vec3d & tvec,
  double & reprojection_error_px,
  cv::Mat & annotated_image,
  std::string & error_message) const
{
  std::vector<std::vector<cv::Point2f>> marker_corners;
  std::vector<int> marker_ids;
  std::vector<std::vector<cv::Point2f>> rejected;
  cv::aruco::detectMarkers(
    image_bgr,
    dictionary_,
    marker_corners,
    marker_ids,
    detector_params_,
    rejected);

  if (marker_ids.empty()) {
    error_message = "no aruco markers detected";
    return false;
  }

  const int interpolated_count = cv::aruco::interpolateCornersCharuco(
    marker_corners,
    marker_ids,
    image_bgr,
    board_,
    charuco_corners,
    charuco_ids,
    camera_matrix,
    dist_coeffs);

  if (interpolated_count <= 0 || charuco_ids.empty()) {
    error_message = "no charuco corners interpolated";
    return false;
  }

  if (!cv::aruco::estimatePoseCharucoBoard(
        charuco_corners,
        charuco_ids,
        board_,
        camera_matrix,
        dist_coeffs,
        rvec,
        tvec)) {
    error_message = "estimatePoseCharucoBoard failed";
    return false;
  }

  annotated_image = image_bgr.clone();
  cv::aruco::drawDetectedMarkers(annotated_image, marker_corners, marker_ids);
  cv::aruco::drawDetectedCornersCharuco(annotated_image, charuco_corners, charuco_ids);
  const cv::Mat rvec_mat = (cv::Mat_<double>(3, 1) << rvec[0], rvec[1], rvec[2]);
  const cv::Mat tvec_mat = (cv::Mat_<double>(3, 1) << tvec[0], tvec[1], tvec[2]);
  cv::drawFrameAxes(
    annotated_image, camera_matrix, dist_coeffs, rvec_mat, tvec_mat,
    static_cast<float>(board_square_length_m_ * 2.0));

  std::vector<cv::Point3f> object_points;
  object_points.reserve(charuco_ids.size());
  for (int id : charuco_ids) {
    if (id < 0 || id >= static_cast<int>(board_->chessboardCorners.size())) {
      continue;
    }
    object_points.push_back(board_->chessboardCorners[static_cast<size_t>(id)]);
  }

  if (object_points.size() != charuco_corners.size()) {
    error_message = "object point and image point count mismatch";
    return false;
  }

  std::vector<cv::Point2f> projected_points;
  cv::projectPoints(object_points, rvec, tvec, camera_matrix, dist_coeffs, projected_points);
  if (projected_points.size() != charuco_corners.size()) {
    error_message = "projected point count mismatch";
    return false;
  }

  double err_sq_sum = 0.0;
  for (size_t i = 0; i < projected_points.size(); ++i) {
    const cv::Point2f diff = projected_points[i] - charuco_corners[i];
    err_sq_sum += static_cast<double>(diff.x * diff.x + diff.y * diff.y);
  }
  reprojection_error_px = std::sqrt(err_sq_sum / static_cast<double>(projected_points.size()));

  std::ostringstream text;
  text << "charuco=" << charuco_ids.size() << " rms=" << std::fixed << std::setprecision(2)
       << reprojection_error_px << " px";
  cv::putText(
    annotated_image, text.str(), cv::Point(20, 40), cv::FONT_HERSHEY_SIMPLEX, 1.0,
    cv::Scalar(0, 255, 0), 2, cv::LINE_AA);
  return true;
}

bool HandEyeCalibrationNode::saveSampleFiles(const Sample & sample, std::string & error_message) const
{
  try {
    cv::FileStorage fs(sample.sample_file, cv::FileStorage::WRITE);
    if (!fs.isOpened()) {
      error_message = "failed to open sample file for write";
      return false;
    }

    fs << "sample_id" << sample.sample_id;
    fs << "stamp_sec" << static_cast<double>(sample.stamp.seconds());
    fs << "frame_id" << sample.frame_id;
    fs << "image_file" << recordPath(sample.image_file);
    fs << "debug_image_file" << recordPath(sample.debug_image_file);
    fs << "reprojection_error_px" << sample.reprojection_error_px;
    fs << "camera_matrix" << sample.camera_matrix;
    fs << "dist_coeffs" << sample.dist_coeffs;
    const cv::Mat board_rvec_mat = (cv::Mat_<double>(3, 1) <<
      sample.board_rvec[0], sample.board_rvec[1], sample.board_rvec[2]);
    const cv::Mat board_tvec_mat = (cv::Mat_<double>(3, 1) <<
      sample.board_tvec[0], sample.board_tvec[1], sample.board_tvec[2]);
    fs << "board_rvec" << board_rvec_mat;
    fs << "board_tvec" << board_tvec_mat;
    fs << "T_base_tool" << sample.T_base_tool;
    fs << "T_camera_board" << sample.T_camera_board;
    fs << "charuco_ids" << "[";
    for (int id : sample.charuco_ids) {
      fs << id;
    }
    fs << "]";
    fs << "charuco_corners" << "[";
    for (const auto & corner : sample.charuco_corners) {
      fs << corner.x << corner.y;
    }
    fs << "]";
    fs.release();
    return true;
  } catch (const std::exception & e) {
    error_message = e.what();
    return false;
  }
}

bool HandEyeCalibrationNode::saveSessionMetadata() const
{
  try {
    fs::create_directories(session_dir_);
    cv::FileStorage fs(session_metadata_file_, cv::FileStorage::WRITE);
    if (!fs.isOpened()) {
      return false;
    }
    fs << "node_name" << get_name();
    fs << "service_namespace" << service_namespace_;
    fs << "image_topic" << image_topic_;
    fs << "camera_info_topic" << camera_info_topic_;
    fs << "robot_pose_service" << robot_pose_service_;
    fs << "save_root_dir" << recordPath(save_root_dir_);
    fs << "session_name" << session_name_;
    fs << "publish_debug_image" << publish_debug_image_;
    fs << "robot_pose_timeout_ms" << robot_pose_timeout_ms_;
    fs << "board_dictionary_id" << board_dictionary_id_;
    fs << "board_squares_x" << board_squares_x_;
    fs << "board_squares_y" << board_squares_y_;
    fs << "board_square_length_m" << board_square_length_m_;
    fs << "board_marker_length_m" << board_marker_length_m_;
    fs << "handeye_method" << handeye_method_;
    fs << "min_samples" << min_samples_;
    fs.release();
    return true;
  } catch (...) {
    return false;
  }
}

bool HandEyeCalibrationNode::saveResultFile(
  const std::string & output_path,
  const cv::Mat & T_tool_camera,
  const cv::Mat & T_camera_tool,
  const std::vector<Sample> & samples,
  double rms_reprojection_error_px,
  double closure_translation_rms_m,
  double closure_rotation_rms_deg,
  std::string & result_file,
  std::string & error_message) const
{
  try {
    result_file = output_path;
    if (result_file.empty()) {
      result_file = (fs::path(results_dir_) / "handeye_result.yaml").string();
    }
    const fs::path result_parent = fs::path(result_file).parent_path();
    if (!result_parent.empty()) {
      fs::create_directories(result_parent);
    }

    cv::FileStorage fs(result_file, cv::FileStorage::WRITE);
    if (!fs.isOpened()) {
      error_message = "failed to open result file for write";
      return false;
    }
    fs << "node_name" << get_name();
    fs << "service_namespace" << service_namespace_;
    fs << "sample_count" << static_cast<int>(samples.size());
    fs << "handeye_method" << handeye_method_;
    fs << "tool_camera_matrix" << T_tool_camera;
    fs << "camera_tool_matrix" << T_camera_tool;
    fs << "rms_reprojection_error_px" << rms_reprojection_error_px;
    fs << "closure_translation_rms_m" << closure_translation_rms_m;
    fs << "closure_rotation_rms_deg" << closure_rotation_rms_deg;
    fs << "samples" << "[";
    for (const auto & sample : samples) {
      fs << "{";
      fs << "sample_id" << sample.sample_id;
      fs << "sample_file" << recordPath(sample.sample_file);
      fs << "image_file" << recordPath(sample.image_file);
      fs << "debug_image_file" << recordPath(sample.debug_image_file);
      fs << "reprojection_error_px" << sample.reprojection_error_px;
      fs << "T_base_tool" << sample.T_base_tool;
      fs << "T_camera_board" << sample.T_camera_board;
      fs << "}";
    }
    fs << "]";
    fs.release();
    result_file = recordPath(result_file);
    return true;
  } catch (const std::exception & e) {
    error_message = e.what();
    return false;
  }
}

cv::Mat HandEyeCalibrationNode::rpyToRotationMatrix(double rx, double ry, double rz)
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
  const cv::Matx33d R = Rz * Ry * Rx;
  return cv::Mat(R);
}

cv::Mat HandEyeCalibrationNode::makeHomogeneousMatrix(const cv::Mat & R, const cv::Mat & t)
{
  cv::Mat T = cv::Mat::eye(4, 4, CV_64F);
  CV_Assert(R.rows == 3 && R.cols == 3);
  CV_Assert(t.rows == 3 && t.cols == 1);
  R.copyTo(T(cv::Range(0, 3), cv::Range(0, 3)));
  t.copyTo(T(cv::Range(0, 3), cv::Range(3, 4)));
  return T;
}

cv::Mat HandEyeCalibrationNode::invertHomogeneousMatrix(const cv::Mat & T)
{
  CV_Assert(matrixIsValidHomogeneous(T));
  const cv::Mat R = T(cv::Range(0, 3), cv::Range(0, 3));
  const cv::Mat t = T(cv::Range(0, 3), cv::Range(3, 4));
  cv::Mat R_inv = R.t();
  cv::Mat t_inv = -R_inv * t;
  return makeHomogeneousMatrix(R_inv, t_inv);
}

std::array<double, 16> HandEyeCalibrationNode::matrixToArray16(const cv::Mat & T)
{
  std::array<double, 16> out{};
  if (T.rows != 4 || T.cols != 4 || T.type() != CV_64F) {
    return out;
  }
  for (int r = 0; r < 4; ++r) {
    for (int c = 0; c < 4; ++c) {
      out[static_cast<size_t>(r * 4 + c)] = T.at<double>(r, c);
    }
  }
  return out;
}

std::string HandEyeCalibrationNode::nowString()
{
  const auto now = std::chrono::system_clock::now();
  const std::time_t now_time = std::chrono::system_clock::to_time_t(now);
  std::tm tm{};
#if defined(_WIN32)
  localtime_s(&tm, &now_time);
#else
  localtime_r(&now_time, &tm);
#endif
  std::ostringstream oss;
  oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
  return oss.str();
}

std::string HandEyeCalibrationNode::sanitizeMethod(const std::string & method)
{
  return toUpper(method);
}

int HandEyeCalibrationNode::handEyeMethodFromString(const std::string & method)
{
  const std::string upper = sanitizeMethod(method);
  if (upper == "TSAI") {
    return cv::CALIB_HAND_EYE_TSAI;
  }
  if (upper == "PARK") {
    return cv::CALIB_HAND_EYE_PARK;
  }
  if (upper == "HORAUD") {
    return cv::CALIB_HAND_EYE_HORAUD;
  }
  if (upper == "ANDREFF") {
    return cv::CALIB_HAND_EYE_ANDREFF;
  }
  if (upper == "DANIILIDIS") {
    return cv::CALIB_HAND_EYE_DANIILIDIS;
  }
  return cv::CALIB_HAND_EYE_TSAI;
}

std::string HandEyeCalibrationNode::serviceName(
  const std::string & service_namespace, const std::string & name)
{
  if (service_namespace.empty() || service_namespace == "/") {
    return "/" + name;
  }
  if (service_namespace.back() == '/') {
    return service_namespace + name;
  }
  return service_namespace + "/" + name;
}

bool HandEyeCalibrationNode::matrixIsValidHomogeneous(const cv::Mat & T)
{
  return T.rows == 4 && T.cols == 4 && T.type() == CV_64F;
}

cv::Mat HandEyeCalibrationNode::buildCameraMatrixFromInfo(
  const sensor_msgs::msg::CameraInfo & msg) const
{
  if (msg.k.size() != 9) {
    return cv::Mat();
  }
  cv::Mat K(3, 3, CV_64F);
  for (size_t i = 0; i < msg.k.size(); ++i) {
    K.at<double>(static_cast<int>(i / 3), static_cast<int>(i % 3)) = msg.k[i];
  }
  return K;
}

cv::Mat HandEyeCalibrationNode::buildDistCoeffsFromInfo(
  const sensor_msgs::msg::CameraInfo & msg) const
{
  if (msg.d.empty()) {
    return cv::Mat::zeros(1, 5, CV_64F);
  }
  cv::Mat D(1, static_cast<int>(msg.d.size()), CV_64F);
  for (size_t i = 0; i < msg.d.size(); ++i) {
    D.at<double>(0, static_cast<int>(i)) = msg.d[i];
  }
  return D;
}

std::string HandEyeCalibrationNode::makeSamplePrefix(int sample_id) const
{
  std::ostringstream oss;
  oss << "sample_" << std::setw(4) << std::setfill('0') << sample_id;
  return oss.str();
}

std::string HandEyeCalibrationNode::makeSampleImageFile(int sample_id) const
{
  return (fs::path(samples_dir_) / (makeSamplePrefix(sample_id) + "_raw.png")).string();
}

std::string HandEyeCalibrationNode::makeSampleDebugFile(int sample_id) const
{
  return (fs::path(debug_dir_) / (makeSamplePrefix(sample_id) + "_debug.png")).string();
}

std::string HandEyeCalibrationNode::makeSampleYamlFile(int sample_id) const
{
  return (fs::path(samples_dir_) / (makeSamplePrefix(sample_id) + ".yaml")).string();
}

std::string HandEyeCalibrationNode::makeResultFile(const std::string & output_path) const
{
  if (output_path.empty()) {
    return (fs::path(results_dir_) / "handeye_result.yaml").string();
  }
  return output_path;
}

std::string HandEyeCalibrationNode::makeSessionMetadataFile() const
{
  return (fs::path(session_dir_) / "session.yaml").string();
}

}  // namespace gas
