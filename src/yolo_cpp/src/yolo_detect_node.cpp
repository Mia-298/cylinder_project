#include "yolo_detect_node.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <utility>
#include <stdexcept>
#include <vector>

#include <pcl/exceptions.h>
#include <pcl_conversions/pcl_conversions.h>
#include <rmw/qos_profiles.h>
// 测试用 可视化文件
#include <iomanip>
#include <sstream>

#include <opencv2/calib3d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <gas_interfaces/srv/detect_objects.hpp>
#include <vision_msgs/msg/detection2_d.hpp>
#include <vision_msgs/msg/detection2_d_array.hpp>
#include <vision_msgs/msg/object_hypothesis_with_pose.hpp>



YoloDetectNode::YoloDetectNode(bool enable_vis)
: Node("yolo_detect_node")
{
  this->enable_vis = enable_vis;
  const std::string package_share_directory =
    ament_index_cpp::get_package_share_directory("yolo_cpp");

  const std::string default_model_path =
    package_share_directory + "/models/best.onnx";

  model_path_ = declare_parameter<std::string>(
    "model_path",
    default_model_path);

  image_topic_ = declare_parameter<std::string>(
    "image_topic",
    "/camera/color/image_raw");

  point_cloud_topic_ = declare_parameter<std::string>(
    "point_cloud_topic",
    "/camera/depth/color/points");

  sphere_target_class_ = declare_parameter<std::string>(
    "sphere_target_class",
    "class_0");

  service_name_ = declare_parameter<std::string>(
    "service_name",
    "/yolo/detect_once");

  handeye_result_file_ = declare_parameter<std::string>(
    "handeye_result_file",
    "");

  tool_frame_id_ = declare_parameter<std::string>(
    "tool_frame_id",
    "tool");

  capture_interval_sec_ =
    declare_parameter<double>(
      "capture_interval_sec",
      0.5);
  const rclcpp::QoS camera_qos =
    rclcpp::QoS(
    rclcpp::KeepLast(10))
    .reliable()
    .durability_volatile();

  
  detector_ = std::make_unique<YoloV8Detector>(model_path_);
  SphereFitParameters sphere_parameters;
  sphere_fitter_ =
    std::make_unique<SphereFitter>(
    sphere_parameters);

  if (!handeye_result_file_.empty()) {
    has_tool_camera_transform_ = loadToolCameraMatrix(
      handeye_result_file_,
      T_tool_camera_,
      handeye_load_error_);

    if (has_tool_camera_transform_) {
      RCLCPP_INFO(
        get_logger(),
        "Loaded T_tool_camera from: %s",
        handeye_result_file_.c_str());
    } else {
      RCLCPP_WARN(
        get_logger(),
        "Tool-frame output disabled: %s",
        handeye_load_error_.c_str());
    }
  } else {
    handeye_load_error_ = "handeye_result_file is empty";
    RCLCPP_WARN(
      get_logger(),
      "Tool-frame output disabled: handeye_result_file is empty");
  }

  point_cloud_subscription_ =
    create_subscription<
    sensor_msgs::msg::PointCloud2>(
    point_cloud_topic_,
    camera_qos,
    std::bind(
      &YoloDetectNode::pointCloudCallback,
      this,
      std::placeholders::_1));

  image_subscription_ =
    create_subscription<
    sensor_msgs::msg::Image>(
    image_topic_,
    camera_qos,
    std::bind(
      &YoloDetectNode::imageCallback,
      this,
      std::placeholders::_1));

  detect_service_ =
    create_service<gas_interfaces::srv::DetectObjects>(
    service_name_,
    std::bind(
      &YoloDetectNode::handleDetectObjects,
      this,
      std::placeholders::_1,
      std::placeholders::_2));
  const auto capture_period =
    std::chrono::duration_cast<
    std::chrono::milliseconds>(
    std::chrono::duration<double>(
      capture_interval_sec_));

  if (capture_period.count() <= 0) {
    throw std::invalid_argument(
      "capture interval is shorter than one millisecond");
  }

  capture_timer_ =
    create_wall_timer(
    capture_period,
    std::bind(
      &YoloDetectNode::captureTimerCallback,
      this));
  

  RCLCPP_INFO(get_logger(), "Model path: %s", model_path_.c_str());
  RCLCPP_INFO(get_logger(), "Image topic: %s", image_topic_.c_str());
  RCLCPP_INFO(
    get_logger(),
    "Point cloud topic: %s",
    point_cloud_topic_.c_str());
  RCLCPP_INFO(
    get_logger(),
    "Service name: %s",
    service_name_.c_str());
  RCLCPP_INFO(
    get_logger(),
    "Tool frame id: %s",
    tool_frame_id_.c_str());
  RCLCPP_INFO(
    get_logger(),
    "Capture interval: %.3f s",
    capture_interval_sec_);

  RCLCPP_INFO(
    get_logger(),
    "Timestamp synchronization disabled");

}

DetectionResult
YoloDetectNode::findBestDetectionResult(
    const std::string & object_name ) const
{
    std::lock_guard<std::mutex> lock(
        detection_mutex_);

    DetectionResult result;

    /*
     * 第一步：
     * 找到指定类别中 YOLO 置信度最高的目标。
     */
    const Detection * best_detection =
        nullptr;

    for (
        const Detection & detection :
        latest_snapshot_.detections)
    {
        if (
            detection.class_name !=
            object_name)
        {
            continue;
        }

        if (
            best_detection == nullptr ||
            detection.confidence >
            best_detection->confidence)
        {
            best_detection =
                &detection;
        }
    }

    /*
     * 没有 YOLO 检测结果。
     *
     * 此时返回：
     * yolo_success       = false
     * sphere_fit_success = false
     */
    if (best_detection == nullptr) {
        return result;
    }

    /*
     * YOLO 检测成功。
     */
    const float image_width =
    static_cast<float>(
        latest_snapshot_.image_size.width);

    const float image_height =
        static_cast<float>(
            latest_snapshot_.image_size.height);

    const float center_x =
        best_detection->box.x +
        best_detection->box.width * 0.5F;

    const float center_y =
        best_detection->box.y +
        best_detection->box.height * 0.5F;

    result.center_x_ratio =
        center_x / image_width;

    result.center_y_ratio =
        center_y / image_height;

    result.width_ratio =
        static_cast<float>(
            best_detection->box.width) /
        image_width;

    result.height_ratio =
        static_cast<float>(
            best_detection->box.height) /
        image_height;

    /*
     * 第二步：
     * 查找这个 YOLO 检测框对应的球拟合结果。
     *
     * 当前 processCapturedBundle() 只会对
     * 置信度最高的目标执行球拟合，因此这里
     * 通过 class + bbox 对应两边的数据。
     */
    const LocatedDetection * located_detection =
        nullptr;

    for (
        const LocatedDetection & located :
        latest_snapshot_.located_detections)
    {
        if (
            located.detection.class_name !=
            object_name)
        {
            continue;
        }

        const cv::Rect & located_box =
            located.detection.box;

        const cv::Rect & best_box =
            best_detection->box;

        const bool same_box =
            located_box.x ==
                best_box.x &&
            located_box.y ==
                best_box.y &&
            located_box.width ==
                best_box.width &&
            located_box.height ==
                best_box.height;

        if (!same_box) {
            continue;
        }

        located_detection =
            &located;

        break;
    }

    /*
     * YOLO 成功，但是没有对应的球拟合结果。
     */
    if (located_detection == nullptr) {
        return result;
    }

    /*
     * 球拟合执行过，但是失败。
     */
    if (!located_detection->sphere.success) {
        return result;
    }

    /*
     * YOLO + 球拟合均成功。
     */
    result.sphere_fit_success = true;

    result.x =
        located_detection->sphere.center_m.x();

    result.y =
        located_detection->sphere.center_m.y();

    result.z =
        located_detection->sphere.center_m.z();

    std::array<double, 3> point_tool_m{};
    if (transformCameraPointToTool(
        static_cast<double>(result.x),
        static_cast<double>(result.y),
        static_cast<double>(result.z),
        point_tool_m))
    {
        result.tool_transform_success = true;
        result.tool_x = static_cast<float>(point_tool_m[0]);
        result.tool_y = static_cast<float>(point_tool_m[1]);
        result.tool_z = static_cast<float>(point_tool_m[2]);
    }

    return result;
}

void YoloDetectNode::handleDetectObjects(
  const std::shared_ptr<gas_interfaces::srv::DetectObjects::Request> request,
  std::shared_ptr<gas_interfaces::srv::DetectObjects::Response> response)
{
  if (request != nullptr && request->publish_debug_image) {
    RCLCPP_DEBUG(
      get_logger(),
      "publish_debug_image requested; returning cached detection snapshot");
  }

  DetectionSnapshot snapshot;
  {
    std::lock_guard<std::mutex> lock(detection_mutex_);
    snapshot = latest_snapshot_;
  }

  const std::string frame_id =
    !snapshot.image_frame_id.empty() ?
    snapshot.image_frame_id :
    snapshot.cloud_frame_id;

  response->success = true;
  response->message = "latest detection snapshot returned";
  if (snapshot.detections.empty()) {
    response->message = "no detection snapshot available yet";
  } else if (snapshot.located_detections.empty()) {
    response->message = "detections available but no sphere fit was computed";
  }
  response->detections.header.stamp = snapshot.image_stamp;
  response->detections.header.frame_id = frame_id;
  response->detections.detections.clear();
  response->detections.detections.reserve(snapshot.detections.size());

  for (const Detection & detection : snapshot.detections) {
    vision_msgs::msg::Detection2D detection_msg;
    detection_msg.header.stamp = snapshot.image_stamp;
    detection_msg.header.frame_id = frame_id;
    detection_msg.id = detection.class_name;
    detection_msg.bbox.center.position.x = static_cast<double>(detection.center.x);
    detection_msg.bbox.center.position.y = static_cast<double>(detection.center.y);

    detection_msg.bbox.center.theta = 0.0;
    detection_msg.bbox.size_x = static_cast<double>(detection.box.width);
    detection_msg.bbox.size_y = static_cast<double>(detection.box.height);

    vision_msgs::msg::ObjectHypothesisWithPose hypothesis;
    hypothesis.hypothesis.class_id = static_cast<int64_t>(detection.class_id);

    hypothesis.hypothesis.score = static_cast<float>(detection.confidence);
    detection_msg.results.push_back(std::move(hypothesis));

    response->detections.detections.push_back(std::move(detection_msg));
  }

  /*
   * 输出目标类别中 YOLO 置信度最高的检测框信息，
   * 用于点云球拟合失败后的二维 fallback。
   *
   * 像素偏移定义：
   *   best_offset_x_px = bbox_center_x - image_center_x
   *   best_offset_y_px = bbox_center_y - image_center_y
   *
   * 因此：
   *   X > 0：目标位于图像中心右侧
   *   X < 0：目标位于图像中心左侧
   *   Y > 0：目标位于图像中心下方
   *   Y < 0：目标位于图像中心上方
   */
  response->best_offset_x_px =
    std::numeric_limits<double>::quiet_NaN();
  response->best_offset_y_px =
    std::numeric_limits<double>::quiet_NaN();
  response->best_width_px =
    std::numeric_limits<double>::quiet_NaN();
  response->best_height_px =
    std::numeric_limits<double>::quiet_NaN();

  const Detection * best_detection = nullptr;

  for (const Detection & detection : snapshot.detections) {
    if (
      !sphere_target_class_.empty() &&
      detection.class_name != sphere_target_class_)
    {
      continue;
    }

    if (
      best_detection == nullptr ||
      detection.confidence > best_detection->confidence)
    {
      best_detection = &detection;
    }
  }

  if (
    best_detection != nullptr &&
    snapshot.image_size.width > 0 &&
    snapshot.image_size.height > 0)
  {
    const double image_center_x =
      static_cast<double>(snapshot.image_size.width) * 0.5;
    const double image_center_y =
      static_cast<double>(snapshot.image_size.height) * 0.5;

    const double detection_center_x =
      static_cast<double>(best_detection->box.x) +
      static_cast<double>(best_detection->box.width) * 0.5;
    const double detection_center_y =
      static_cast<double>(best_detection->box.y) +
      static_cast<double>(best_detection->box.height) * 0.5;

    response->best_offset_x_px =
      detection_center_x - image_center_x;
    response->best_offset_y_px =
      detection_center_y - image_center_y;
    response->best_width_px =
      static_cast<double>(best_detection->box.width);
    response->best_height_px =
      static_cast<double>(best_detection->box.height);
  }

  response->has_sphere_center = false;
  response->sphere_center_m.fill(std::numeric_limits<double>::quiet_NaN());
  response->sphere_radius_m = std::numeric_limits<double>::quiet_NaN();
  response->sphere_frame_id = frame_id;
  response->sphere_class_id.clear();
  response->sphere_confidence = std::numeric_limits<double>::quiet_NaN();
  response->has_sphere_center_tool = false;
  response->sphere_center_tool_m.fill(std::numeric_limits<double>::quiet_NaN());
  response->sphere_tool_frame_id = tool_frame_id_;

  if (!snapshot.located_detections.empty()) {
    const LocatedDetection & located = snapshot.located_detections.front();
    response->sphere_frame_id = frame_id;
    response->sphere_class_id = located.detection.class_name;
    response->sphere_confidence = static_cast<double>(located.detection.confidence);

    if (located.sphere.success) {
      response->has_sphere_center = true;
      response->sphere_center_m[0] = static_cast<double>(located.sphere.center_m.x());
      response->sphere_center_m[1] = static_cast<double>(located.sphere.center_m.y());
      response->sphere_center_m[2] = static_cast<double>(located.sphere.center_m.z());
      response->sphere_radius_m = static_cast<double>(located.sphere.radius_m);

      std::array<double, 3> point_tool_m{};
      if (transformCameraPointToTool(
          response->sphere_center_m[0],
          response->sphere_center_m[1],
          response->sphere_center_m[2],
          point_tool_m))
      {
        response->has_sphere_center_tool = true;
        response->sphere_center_tool_m = point_tool_m;
        response->message =
          "latest detection snapshot returned with sphere fit and tool-frame transform";
      } else {
        response->message =
          "latest detection snapshot returned with sphere fit; tool-frame transform unavailable: " +
          handeye_load_error_;
      }
    } else {
      response->message = "detections available but sphere fit is not valid";
    }
  }
}

bool YoloDetectNode::loadToolCameraMatrix(
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
      error_message =
        "hand-eye result file does not contain tool_camera_matrix or camera_tool_matrix";
      return false;
    }

    if (T_camera_tool.type() != CV_64F) {
      T_camera_tool.convertTo(T_camera_tool, CV_64F);
    }
    if (!matrixIsValidHomogeneous(T_camera_tool)) {
      error_message = "camera_tool_matrix is not a valid homogeneous 4x4 matrix";
      return false;
    }

    T_tool_camera = invertHomogeneousMatrix(T_camera_tool);
    error_message.clear();
    return true;
  }

  if (T_read.type() != CV_64F) {
    T_read.convertTo(T_read, CV_64F);
  }
  if (!matrixIsValidHomogeneous(T_read)) {
    error_message = "tool_camera_matrix is not a valid homogeneous 4x4 matrix";
    return false;
  }

  T_tool_camera = T_read.clone();
  error_message.clear();
  return true;
}

bool YoloDetectNode::transformCameraPointToTool(
  double x_camera,
  double y_camera,
  double z_camera,
  std::array<double, 3> & point_tool_m) const
{
  point_tool_m.fill(std::numeric_limits<double>::quiet_NaN());

  if (!has_tool_camera_transform_ || !matrixIsValidHomogeneous(T_tool_camera_)) {
    return false;
  }
  if (!std::isfinite(x_camera) || !std::isfinite(y_camera) || !std::isfinite(z_camera)) {
    return false;
  }

  const cv::Mat point_camera = (cv::Mat_<double>(4, 1) <<
    x_camera, y_camera, z_camera, 1.0);
  const cv::Mat point_tool = T_tool_camera_ * point_camera;

  const double x_tool = point_tool.at<double>(0, 0);
  const double y_tool = point_tool.at<double>(1, 0);
  const double z_tool = point_tool.at<double>(2, 0);
  const double w_tool = point_tool.at<double>(3, 0);

  if (!std::isfinite(x_tool) || !std::isfinite(y_tool) ||
      !std::isfinite(z_tool) || !std::isfinite(w_tool) ||
      std::abs(w_tool) < 1e-12)
  {
    return false;
  }

  point_tool_m[0] = x_tool / w_tool;
  point_tool_m[1] = y_tool / w_tool;
  point_tool_m[2] = z_tool / w_tool;
  return true;
}

bool YoloDetectNode::matrixIsValidHomogeneous(const cv::Mat & T)
{
  if (T.rows != 4 || T.cols != 4 || (T.type() != CV_64F && T.type() != CV_32F)) {
    return false;
  }

  cv::Mat T64;
  if (T.type() == CV_64F) {
    T64 = T;
  } else {
    T.convertTo(T64, CV_64F);
  }

  for (int row = 0; row < 4; ++row) {
    for (int col = 0; col < 4; ++col) {
      if (!std::isfinite(T64.at<double>(row, col))) {
        return false;
      }
    }
  }

  constexpr double kBottomRowTolerance = 1e-8;
  return
    std::abs(T64.at<double>(3, 0)) <= kBottomRowTolerance &&
    std::abs(T64.at<double>(3, 1)) <= kBottomRowTolerance &&
    std::abs(T64.at<double>(3, 2)) <= kBottomRowTolerance &&
    std::abs(T64.at<double>(3, 3) - 1.0) <= kBottomRowTolerance;
}

cv::Mat YoloDetectNode::invertHomogeneousMatrix(const cv::Mat & T)
{
  CV_Assert(matrixIsValidHomogeneous(T));

  cv::Mat T64;
  if (T.type() == CV_64F) {
    T64 = T;
  } else {
    T.convertTo(T64, CV_64F);
  }

  const cv::Mat R = T64(cv::Range(0, 3), cv::Range(0, 3));
  const cv::Mat t = T64(cv::Range(0, 3), cv::Range(3, 4));
  const cv::Mat R_inv = R.t();
  const cv::Mat t_inv = -R_inv * t;

  cv::Mat T_inv = cv::Mat::eye(4, 4, CV_64F);
  R_inv.copyTo(T_inv(cv::Range(0, 3), cv::Range(0, 3)));
  t_inv.copyTo(T_inv(cv::Range(0, 3), cv::Range(3, 4)));
  return T_inv;
}

void YoloDetectNode::captureTimerCallback()
{
  std::lock_guard<std::mutex> lock(
    capture_mutex_);

  if (capture_state_ != CaptureState::Idle) {
    RCLCPP_DEBUG(
      get_logger(),
      "Capture timer skipped because "
      "the previous cycle is still active");

    return;
  }

  captured_cloud_message_.reset();
  captured_image_message_.reset();

  ++capture_cycle_count_;

  capture_state_ =
    CaptureState::WaitingForCloud;

  RCLCPP_INFO(
    get_logger(),
    "Capture cycle %llu started; "
    "waiting for the next point cloud",
    static_cast<unsigned long long>(
      capture_cycle_count_));
}

void YoloDetectNode::imageCallback(
  sensor_msgs::msg::Image::ConstSharedPtr message)
{
  sensor_msgs::msg::PointCloud2::ConstSharedPtr
    cloud_message;

  std::chrono::steady_clock::time_point
    cloud_arrival_time;

  std::uint64_t cycle_index = 0;

  {
    std::lock_guard<std::mutex> lock(capture_mutex_);
    if (
      capture_state_ !=
      CaptureState::WaitingForColor)
    {
      return;
    }

    captured_image_message_ = message;
    cloud_message = captured_cloud_message_;
    cloud_arrival_time = captured_cloud_arrival_time_;
    cycle_index = capture_cycle_count_;
    capture_state_ = CaptureState::Processing;
  }

  if (cloud_message == nullptr) {
    RCLCPP_ERROR(
      get_logger(),
      "Capture cycle %llu entered Processing "
      "without a point cloud",
      static_cast<unsigned long long>(cycle_index));

    std::lock_guard<std::mutex> lock(capture_mutex_);

    captured_image_message_.reset();
    captured_cloud_message_.reset();

    capture_state_ = CaptureState::Idle;

    return;
  }

  const auto image_arrival_time = std::chrono::steady_clock::now();
  const double arrival_delta_ms =std::chrono::duration<
    double,
    std::milli>(image_arrival_time - cloud_arrival_time).count();

  const rclcpp::Time image_stamp(message->header.stamp);
  const rclcpp::Time cloud_stamp(cloud_message->header.stamp);
  const double header_delta_ms = std::abs(
    (image_stamp - cloud_stamp).seconds()) * 1000.0;

  RCLCPP_INFO(
    get_logger(),
    "Capture cycle %llu synchronization: "
    "arrival_delta=%.3f ms, header_delta=%.3f ms",
    static_cast<unsigned long long>(cycle_index),
    std::abs(arrival_delta_ms),
    header_delta_ms);

  processCapturedBundle(
    message,
    cloud_message,
    cycle_index);

  {
    std::lock_guard<std::mutex> lock( capture_mutex_);
    captured_image_message_.reset();
    captured_cloud_message_.reset();
    capture_state_ =
      CaptureState::Idle;
  }

}

void YoloDetectNode::pointCloudCallback(
  sensor_msgs::msg::PointCloud2::ConstSharedPtr message)
{
  {
    std::lock_guard<std::mutex> lock(capture_mutex_);
    if (
      capture_state_ !=
      CaptureState::WaitingForCloud)
    {
      return;
    }

    captured_cloud_message_ = message;
    captured_cloud_arrival_time_ = std::chrono::steady_clock::now();
    capture_state_ = CaptureState::WaitingForColor;
  }
}

void YoloDetectNode::processCapturedBundle(
  const sensor_msgs::msg::Image::ConstSharedPtr & image_message,
  const sensor_msgs::msg::PointCloud2::ConstSharedPtr & cloud_message,
  const std::uint64_t cycle_index)
{
  try {

    const cv_bridge::CvImageConstPtr cv_image =
      cv_bridge::toCvShare(
      image_message,
      "bgr8");

    const cv::Mat & frame =
      cv_image->image;

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(
      new pcl::PointCloud<pcl::PointXYZ>());

    pcl::fromROSMsg(
      *cloud_message,
      *cloud);

    const auto inference_start_time =
      std::chrono::steady_clock::now();

    std::vector<Detection> detections = detector_->infer(frame);

    const auto inference_end_time =
      std::chrono::steady_clock::now();

    const double inference_time_ms =
      std::chrono::duration<
      double,
      std::milli>(
      inference_end_time -
      inference_start_time).count();

    RCLCPP_INFO(
      get_logger(),
      "Capture cycle %llu: YOLO inference completed; "
      "detections=%zu, inference_time=%.3f ms",
      static_cast<unsigned long long>(
        cycle_index),
      detections.size(),
      inference_time_ms);

    /*
     * 输出所有检测结果。
     */
    for (
      std::size_t index = 0;
      index < detections.size();
      ++index)
    {
      const Detection & detection =
        detections.at(index);

      RCLCPP_INFO(
        get_logger(),
        "Capture cycle %llu detection[%zu]: "
        "class=%s id=%d confidence=%.3f "
        "box=[x=%d y=%d w=%d h=%d] "
        "center=[%.1f %.1f]",
        static_cast<unsigned long long>(
          cycle_index),
        index,
        detection.class_name.c_str(),
        detection.class_id,
        detection.confidence,
        detection.box.x,
        detection.box.y,
        detection.box.width,
        detection.box.height,
        detection.center.x,
        detection.center.y);
    }
    // 筛选画面中置信度最高的气缸
    const Detection * best_detection =
      nullptr;

    for (const Detection & detection :
        detections)
    {
      if (
        !sphere_target_class_.empty() &&
        detection.class_name !=
          sphere_target_class_)
      {
        continue;
      }

      if (
        best_detection == nullptr ||
        detection.confidence >
          best_detection->confidence)
      {
        best_detection = &detection;
      }
    }

    

    std::vector<LocatedDetection>
      located_detections;
    if (best_detection == nullptr) {
  RCLCPP_WARN(
    get_logger(),
    "Capture cycle %llu: no detection matched "
    "sphere target class '%s'; sphere fitting skipped",
    static_cast<unsigned long long>(
      cycle_index),
    sphere_target_class_.c_str());

} else {
  RCLCPP_INFO(
    get_logger(),
    "Capture cycle %llu: starting sphere fitting "
    "using detection box=[x=%d y=%d w=%d h=%d]",
    static_cast<unsigned long long>(
      cycle_index),
    best_detection->box.x,
    best_detection->box.y,
    best_detection->box.width,
    best_detection->box.height);

  LocatedDetection located;
  located.detection =
    *best_detection;

  const auto sphere_fit_start =
    std::chrono::steady_clock::now();

  located.sphere =
    sphere_fitter_->fit(
    cloud,
    best_detection->box,
    frame.size());

  const auto sphere_fit_end =
    std::chrono::steady_clock::now();

  const double sphere_fit_time_ms =
    std::chrono::duration<
    double,
    std::milli>(
    sphere_fit_end -
    sphere_fit_start).count();

  if (located.sphere.success) {
    RCLCPP_INFO(
      get_logger(),
      "Capture cycle %llu: sphere fit SUCCESS; "
      "center=[%.6f %.6f %.6f] m, "
      "radius=%.6f m, "
      "ROI=[x=%d y=%d w=%d h=%d], "
      "inliers=%zu/%zu, ratio=%.4f, "
      "RMS=%.6f m, fit_time=%.3f ms",
      static_cast<unsigned long long>(
        cycle_index),
      located.sphere.center_m.x(),
      located.sphere.center_m.y(),
      located.sphere.center_m.z(),
      located.sphere.radius_m,
      located.sphere.cloud_roi.x,
      located.sphere.cloud_roi.y,
      located.sphere.cloud_roi.width,
      located.sphere.cloud_roi.height,
      located.sphere.inlier_count,
      located.sphere.roi_point_count,
      located.sphere.inlier_ratio,
      located.sphere.rms_residual_m,
      sphere_fit_time_ms);

  } else {
    RCLCPP_WARN(
      get_logger(),
      "Capture cycle %llu: sphere fit FAILED; "
      "reason=%s, "
      "ROI=[x=%d y=%d w=%d h=%d], "
      "inliers=%zu/%zu, ratio=%.4f, "
      "fit_time=%.3f ms",
      static_cast<unsigned long long>(
        cycle_index),
      located.sphere.failure_reason.c_str(),
      located.sphere.cloud_roi.x,
      located.sphere.cloud_roi.y,
      located.sphere.cloud_roi.width,
      located.sphere.cloud_roi.height,
      located.sphere.inlier_count,
      located.sphere.roi_point_count,
      located.sphere.inlier_ratio,
      sphere_fit_time_ms);
  }

  located_detections.push_back(
    std::move(located));
}

  // 以下是窗口测试'
  if(this->enable_vis)
  {
  /*
   * frame 来自 cv_bridge::toCvShare，
   * 不能直接在原图上修改，因此先复制一份。
   */
  cv::Mat display_frame =
    frame.clone();

  for (const Detection & detection :
       detections)
  {
    /*
     * 绘制检测框。
     */
    cv::rectangle(
      display_frame,
      detection.box,
      cv::Scalar(0, 255, 0),
      3,
      cv::LINE_AA);

    /*
     * 构造标签：
     * class_0 0.903
     */
    std::ostringstream label_stream;

    label_stream
      << detection.class_name
      << " "
      << std::fixed
      << std::setprecision(3)
      << detection.confidence;

    const std::string label =
      label_stream.str();

    int baseline = 0;

    const cv::Size label_size =
      cv::getTextSize(
      label,
      cv::FONT_HERSHEY_SIMPLEX,
      0.7,
      2,
      &baseline);

    /*
     * 防止标签超出图像上边界。
     */
    const int label_top =
      std::max(
      detection.box.y,
      label_size.height + 10);

    const cv::Point background_left_top(
      detection.box.x,
      label_top -
      label_size.height -
      10);

    const cv::Point background_right_bottom(
      std::min(
        detection.box.x +
        label_size.width +
        10,
        display_frame.cols),
      label_top);

    cv::rectangle(
      display_frame,
      background_left_top,
      background_right_bottom,
      cv::Scalar(0, 255, 0),
      cv::FILLED);

    cv::putText(
      display_frame,
      label,
      cv::Point(
        detection.box.x + 5,
        label_top - 5),
      cv::FONT_HERSHEY_SIMPLEX,
      0.7,
      cv::Scalar(0, 0, 0),
      2,
      cv::LINE_AA);

    /*
     * 标记检测中心。
     */
    cv::circle(
      display_frame,
      detection.center,
      5,
      cv::Scalar(0, 0, 255),
      cv::FILLED,
      cv::LINE_AA);
  }

  /*
   * 没有检测结果时显示提示。
   */
  if (detections.empty()) {
    cv::putText(
      display_frame,
      "No detection",
      cv::Point(30, 50),
      cv::FONT_HERSHEY_SIMPLEX,
      1.0,
      cv::Scalar(0, 0, 255),
      2,
      cv::LINE_AA);
  }
  if(
    located_detections.empty() ||
    !located_detections.front().sphere.success)
  {
    cv::putText(
      display_frame,
      "sphere_fit_false",
      cv::Point(30, 120),
      cv::FONT_HERSHEY_SIMPLEX,
      0.65,
      cv::Scalar(0, 0, 255),
      2,
      cv::LINE_AA);
  }
  else{
    const SphereFitResult & sphere =
      located_detections.front().sphere;

    const double distance_m =
      static_cast<double>(
        sphere.center_m.norm());

    std::ostringstream text_stream;

    text_stream
      << std::fixed
      << std::setprecision(3)
      << "center: ["
      << sphere.center_m.x()
      << ", "
      << sphere.center_m.y()
      << ", "
      << sphere.center_m.z()
      << "] m"
      << "  distance: "
      << distance_m
      << " m";

    cv::putText(
      display_frame,
      text_stream.str(),
      cv::Point(30, 120),
      cv::FONT_HERSHEY_SIMPLEX,
      0.65,
      cv::Scalar(0, 255, 0),
      2,
      cv::LINE_AA);

  }

  /*
   * 显示当前采集轮次。
   */
  const std::string cycle_text =
    "Cycle: " +
    std::to_string(cycle_index);

  cv::putText(
    display_frame,
    cycle_text,
    cv::Point(30, 90),
    cv::FONT_HERSHEY_SIMPLEX,
    0.8,
    cv::Scalar(255, 255, 0),
    2,
    cv::LINE_AA);

  cv::imshow(
    "onnx_result",
    display_frame);

  /*
   * 必须调用 waitKey，OpenCV 才会处理窗口刷新事件。
   * 1 ms 不会明显影响当前推理周期。
   */
  cv::waitKey(1);
  }
    {
      std::lock_guard<std::mutex> lock(
        detection_mutex_);

      latest_snapshot_.image_stamp =
        rclcpp::Time(
        image_message->header.stamp);

      latest_snapshot_.image_frame_id =
        image_message->header.frame_id;

      latest_snapshot_.cloud_stamp =
        rclcpp::Time(
        cloud_message->header.stamp);

      latest_snapshot_.cloud_frame_id =
        cloud_message->header.frame_id;

      latest_snapshot_.image_size =
        frame.size();

      latest_snapshot_.detections =
        std::move(detections);

      latest_snapshot_.located_detections =
        std::move(located_detections);
    }

  } catch (const cv_bridge::Exception & error) {
    RCLCPP_ERROR(
      get_logger(),
      "Capture cycle %llu: cv_bridge conversion failed: %s",
      static_cast<unsigned long long>(
        cycle_index),
      error.what());

  } catch (const Ort::Exception & error) {
    RCLCPP_ERROR(
      get_logger(),
      "Capture cycle %llu: ONNX Runtime inference failed: %s",
      static_cast<unsigned long long>(
        cycle_index),
      error.what());

  } catch (const cv::Exception & error) {
    RCLCPP_ERROR(
      get_logger(),
      "Capture cycle %llu: OpenCV processing failed: %s",
      static_cast<unsigned long long>(
        cycle_index),
      error.what());

  } catch (const std::exception & error) {
    RCLCPP_ERROR(
      get_logger(),
      "Capture cycle %llu: YOLO pipeline failed: %s",
      static_cast<unsigned long long>(
        cycle_index),
      error.what());
  }
}