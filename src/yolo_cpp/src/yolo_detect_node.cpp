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

namespace
{
// -----------------------------------------------------------------------------
// RGB sphere localization parameters
// -----------------------------------------------------------------------------
// Camera intrinsics copied from /camera/color/camera_info (1280 x 720).
constexpr double kRgbFx = 609.7733764648438;
constexpr double kRgbFy = 610.0523071289062;
constexpr double kRgbCx = 637.7689208984375;
constexpr double kRgbCy = 364.3594055175781;

// plumb_bob distortion coefficients: k1, k2, p1, p2, k3.
constexpr double kRgbK1 = -0.034665949642658234;
constexpr double kRgbK2 =  0.038352519273757935;
constexpr double kRgbP1 =  0.0004620052932295948;
constexpr double kRgbP2 =  0.0001331235107500106;
constexpr double kRgbK3 = -0.01328078843653202;

// IMPORTANT: set this to the measured physical radius of the spherical body.
constexpr double kPhysicalSphereRadiusM = 0.090;

// Keep only the middle part of the full-cylinder YOLO box.
constexpr double kRgbTopCropRatio = 0.28;
constexpr double kRgbBottomCropRatio = 0.18;
constexpr double kRgbHorizontalCropRatio = 0.03;

struct RgbSphereEstimate
{
  bool success{false};
  std::string failure_reason;
  cv::Rect roi;
  cv::RotatedRect ellipse;
  cv::Point2f center_px{0.0F, 0.0F};
  double equivalent_radius_px{0.0};
  cv::Vec3d center_m{0.0, 0.0, 0.0};
  double center_distance_m{0.0};
  std::size_t edge_point_count{0U};
  cv::Mat edge_debug;
};

cv::Rect clipRectToImage(
  const cv::Rect & rectangle,
  const cv::Size & image_size)
{
  const cv::Rect image_rectangle(
    0,
    0,
    image_size.width,
    image_size.height);

  return rectangle & image_rectangle;
}

cv::Mat rgbCameraMatrix()
{
  return (cv::Mat_<double>(3, 3) <<
    kRgbFx, 0.0, kRgbCx,
    0.0, kRgbFy, kRgbCy,
    0.0, 0.0, 1.0);
}

cv::Mat rgbDistortionCoefficients()
{
  return (cv::Mat_<double>(1, 5) <<
    kRgbK1,
    kRgbK2,
    kRgbP1,
    kRgbP2,
    kRgbK3);
}

RgbSphereEstimate estimateSphereFromRgb(
  const cv::Mat & frame,
  const cv::Rect & detection_box)
{
  RgbSphereEstimate result;

  if (frame.empty()) {
    result.failure_reason = "RGB frame is empty";
    return result;
  }

  const cv::Rect clipped_box =
    clipRectToImage(detection_box, frame.size());

  if (clipped_box.width < 40 || clipped_box.height < 40) {
    result.failure_reason = "YOLO box is too small for RGB sphere fitting";
    return result;
  }

  const int crop_left = static_cast<int>(std::lround(
    static_cast<double>(clipped_box.width) * kRgbHorizontalCropRatio));
  const int crop_right = crop_left;
  const int crop_top = static_cast<int>(std::lround(
    static_cast<double>(clipped_box.height) * kRgbTopCropRatio));
  const int crop_bottom = static_cast<int>(std::lround(
    static_cast<double>(clipped_box.height) * kRgbBottomCropRatio));

  result.roi = cv::Rect(
    clipped_box.x + crop_left,
    clipped_box.y + crop_top,
    clipped_box.width - crop_left - crop_right,
    clipped_box.height - crop_top - crop_bottom);

  result.roi = clipRectToImage(result.roi, frame.size());

  if (result.roi.width < 40 || result.roi.height < 40) {
    result.failure_reason = "middle RGB ROI is too small";
    return result;
  }

  cv::Mat gray;
  cv::cvtColor(frame(result.roi), gray, cv::COLOR_BGR2GRAY);
  cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(2.0, cv::Size(8, 8));
  cv::Mat enhanced;
  clahe->apply(gray, enhanced);

  cv::GaussianBlur(
    enhanced,
    enhanced,
    cv::Size(5, 5),
    1.2,
    1.2);

  cv::Mat edges;
  cv::Canny(
    enhanced,
    edges,
    45.0,
    135.0,
    3,
    true);
  const cv::Mat kernel = cv::getStructuringElement(
    cv::MORPH_ELLIPSE,
    cv::Size(3, 3));
  cv::morphologyEx(edges, edges, cv::MORPH_CLOSE, kernel);

  result.edge_debug = edges.clone();
  std::vector<cv::Point2f> silhouette_points;
  silhouette_points.reserve(
    static_cast<std::size_t>(result.roi.height) * 2U);

  const int center_x = result.roi.width / 2;
  const int min_half_span =
    std::max(10, static_cast<int>(0.16 * result.roi.width));
  const int min_total_span =
    std::max(20, static_cast<int>(0.40 * result.roi.width));
  const int border_margin =
    std::max(2, static_cast<int>(0.015 * result.roi.width));

  for (int y = 0; y < edges.rows; ++y) {
    const std::uint8_t * row = edges.ptr<std::uint8_t>(y);

    int left_x = -1;
    int right_x = -1;

    for (int x = border_margin; x < edges.cols - border_margin; ++x) {
      if (row[x] == 0U) {
        continue;
      }

      if (x < center_x - min_half_span && left_x < 0) {
        left_x = x;
      }

      if (x > center_x + min_half_span) {
        right_x = x;
      }
    }

    if (left_x < 0 || right_x < 0) {
      continue;
    }

    if (right_x - left_x < min_total_span) {
      continue;
    }

    silhouette_points.emplace_back(
      static_cast<float>(left_x + result.roi.x),
      static_cast<float>(y + result.roi.y));

    silhouette_points.emplace_back(
      static_cast<float>(right_x + result.roi.x),
      static_cast<float>(y + result.roi.y));
  }

  result.edge_point_count = silhouette_points.size();

  if (silhouette_points.size() < 30U) {
    result.failure_reason = "too few left/right sphere silhouette points";
    return result;
  }

  result.ellipse = cv::fitEllipse(silhouette_points);
  result.center_px = result.ellipse.center;

  const double axis_width =
    static_cast<double>(result.ellipse.size.width);
  const double axis_height =
    static_cast<double>(result.ellipse.size.height);

  const double major_axis = std::max(axis_width, axis_height);
  const double minor_axis = std::min(axis_width, axis_height);

  if (!std::isfinite(major_axis) || !std::isfinite(minor_axis) ||
      minor_axis <= 1.0)
  {
    result.failure_reason = "RGB ellipse axes are invalid";
    return result;
  }
  const double axis_ratio = major_axis / minor_axis;
  if (axis_ratio > 1.40) {
    result.failure_reason = "RGB fitted ellipse is too elongated";
    return result;
  }

  if (major_axis < 0.35 * clipped_box.width ||
      major_axis > 1.30 * clipped_box.width)
  {
    result.failure_reason = "RGB fitted ellipse size is inconsistent with YOLO box";
    return result;
  }

  result.equivalent_radius_px =
    0.5 * std::sqrt(axis_width * axis_height);

  const double angle_rad =
    static_cast<double>(result.ellipse.angle) * CV_PI / 180.0;

  const cv::Point2f axis_x(
    static_cast<float>(std::cos(angle_rad)),
    static_cast<float>(std::sin(angle_rad)));
  const cv::Point2f axis_y(-axis_x.y, axis_x.x);

  const float half_width = 0.5F * result.ellipse.size.width;
  const float half_height = 0.5F * result.ellipse.size.height;

  std::vector<cv::Point2f> distorted_points{
    result.center_px,
    result.center_px + axis_x * half_width,
    result.center_px - axis_x * half_width,
    result.center_px + axis_y * half_height,
    result.center_px - axis_y * half_height};

  std::vector<cv::Point2f> normalized_points;
  cv::undistortPoints(
    distorted_points,
    normalized_points,
    rgbCameraMatrix(),
    rgbDistortionCoefficients());

  if (normalized_points.size() != distorted_points.size()) {
    result.failure_reason = "failed to undistort RGB ellipse points";
    return result;
  }

  const cv::Point2f normalized_center = normalized_points[0];

  double normalized_radius = 0.0;
  for (std::size_t index = 1U; index < normalized_points.size(); ++index) {
    const cv::Point2f delta = normalized_points[index] - normalized_center;
    normalized_radius += std::sqrt(
      static_cast<double>(delta.x) * static_cast<double>(delta.x) +
      static_cast<double>(delta.y) * static_cast<double>(delta.y));
  }
  normalized_radius /= 4.0;

  if (!std::isfinite(normalized_radius) || normalized_radius <= 1.0e-6) {
    result.failure_reason = "RGB normalized sphere radius is invalid";
    return result;
  }
  const double alpha = std::atan(normalized_radius);
  const double sin_alpha = std::sin(alpha);

  if (!std::isfinite(sin_alpha) || sin_alpha <= 1.0e-6) {
    result.failure_reason = "RGB apparent sphere angle is invalid";
    return result;
  }

  result.center_distance_m =
    kPhysicalSphereRadiusM / sin_alpha;

  cv::Vec3d ray(
    static_cast<double>(normalized_center.x),
    static_cast<double>(normalized_center.y),
    1.0);

  const double ray_norm = cv::norm(ray);
  if (!std::isfinite(ray_norm) || ray_norm <= 1.0e-9) {
    result.failure_reason = "RGB sphere center ray is invalid";
    return result;
  }

  ray /= ray_norm;
  result.center_m = ray * result.center_distance_m;

  if (!std::isfinite(result.center_m[0]) ||
      !std::isfinite(result.center_m[1]) ||
      !std::isfinite(result.center_m[2]) ||
      result.center_m[2] <= 0.0)
  {
    result.failure_reason = "RGB sphere XYZ is invalid";
    return result;
  }

  result.success = true;
  return result;
}

}  // namespace

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
  response->detections.header.stamp = snapshot.image_stamp.to_msg();
  response->detections.header.frame_id = frame_id;
  response->detections.detections.clear();
  response->detections.detections.reserve(snapshot.detections.size());

  for (const Detection & detection : snapshot.detections) {
    vision_msgs::msg::Detection2D detection_msg;
    detection_msg.header.stamp = snapshot.image_stamp.to_msg();
    detection_msg.header.frame_id = frame_id;
    detection_msg.id = detection.class_name;
    detection_msg.bbox.center.x = static_cast<double>(detection.center.x);
    detection_msg.bbox.center.y = static_cast<double>(detection.center.y);
    detection_msg.bbox.center.theta = 0.0;
    detection_msg.bbox.size_x = static_cast<double>(detection.box.width);
    detection_msg.bbox.size_y = static_cast<double>(detection.box.height);

    vision_msgs::msg::ObjectHypothesisWithPose hypothesis;
    hypothesis.hypothesis.id = static_cast<int64_t>(detection.class_id);
    hypothesis.hypothesis.score = static_cast<float>(detection.confidence);
    detection_msg.results.push_back(std::move(hypothesis));

    response->detections.detections.push_back(std::move(detection_msg));
  }

  response->has_sphere_center = false;
  response->sphere_center_m.fill(std::numeric_limits<double>::quiet_NaN());
  response->sphere_radius_m = std::numeric_limits<double>::quiet_NaN();
  response->sphere_frame_id = frame_id;
  response->sphere_class_id.clear();
  response->sphere_confidence = std::numeric_limits<double>::quiet_NaN();

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
      response->message = "latest detection snapshot returned with sphere fit";
    } else {
      response->message = "detections available but sphere fit is not valid";
    }
  }
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
  std::uint64_t cycle_index = 0;
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
    cycle_index = capture_cycle_count_;
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
    const auto cloud_conversion_start =
      std::chrono::steady_clock::now();

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(
      new pcl::PointCloud<pcl::PointXYZ>());

    pcl::fromROSMsg(
      *cloud_message,
      *cloud);

    const auto cloud_conversion_end =
      std::chrono::steady_clock::now();

    const double cloud_conversion_time_ms =
      std::chrono::duration<
      double,
      std::milli>(
      cloud_conversion_end -
      cloud_conversion_start).count();

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

    RgbSphereEstimate rgb_sphere;

    if (best_detection != nullptr) {
      rgb_sphere = estimateSphereFromRgb(
        frame,
        best_detection->box);

      if (rgb_sphere.success) {
        RCLCPP_INFO(
          get_logger(),
          "Capture cycle %llu: RGB sphere SUCCESS; "
          "center_px=[%.2f %.2f], radius_px=%.2f, "
          "ellipse=[%.2f x %.2f], edge_points=%zu, "
          "XYZ=[%.6f %.6f %.6f] m, range=%.6f m",
          static_cast<unsigned long long>(cycle_index),
          rgb_sphere.center_px.x,
          rgb_sphere.center_px.y,
          rgb_sphere.equivalent_radius_px,
          rgb_sphere.ellipse.size.width,
          rgb_sphere.ellipse.size.height,
          rgb_sphere.edge_point_count,
          rgb_sphere.center_m[0],
          rgb_sphere.center_m[1],
          rgb_sphere.center_m[2],
          rgb_sphere.center_distance_m);
      } else {
        RCLCPP_WARN(
          get_logger(),
          "Capture cycle %llu: RGB sphere FAILED; reason=%s, "
          "ROI=[x=%d y=%d w=%d h=%d], edge_points=%zu",
          static_cast<unsigned long long>(cycle_index),
          rgb_sphere.failure_reason.c_str(),
          rgb_sphere.roi.x,
          rgb_sphere.roi.y,
          rgb_sphere.roi.width,
          rgb_sphere.roi.height,
          rgb_sphere.edge_point_count);
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

  // -----------------------------------------------------------------------
  // RGB sphere visualization.
  // Yellow rectangle: middle ROI used for Canny.
  // Cyan ellipse: fitted spherical silhouette.
  // Magenta point: estimated 2-D projection center of the sphere.
  // -----------------------------------------------------------------------
  if (best_detection != nullptr && rgb_sphere.roi.area() > 0) {
    cv::rectangle(
      display_frame,
      rgb_sphere.roi,
      cv::Scalar(0, 255, 255),
      2,
      cv::LINE_AA);
  }

  if (rgb_sphere.success) {
    cv::ellipse(
      display_frame,
      rgb_sphere.ellipse,
      cv::Scalar(255, 255, 0),
      3,
      cv::LINE_AA);

    cv::circle(
      display_frame,
      rgb_sphere.center_px,
      6,
      cv::Scalar(255, 0, 255),
      cv::FILLED,
      cv::LINE_AA);

    std::ostringstream rgb_text_stream;
    rgb_text_stream
      << std::fixed
      << std::setprecision(3)
      << "RGB XYZ: ["
      << rgb_sphere.center_m[0] << ", "
      << rgb_sphere.center_m[1] << ", "
      << rgb_sphere.center_m[2] << "] m"
      << "  r_px="
      << std::setprecision(1)
      << rgb_sphere.equivalent_radius_px;

    cv::putText(
      display_frame,
      rgb_text_stream.str(),
      cv::Point(30, 155),
      cv::FONT_HERSHEY_SIMPLEX,
      0.65,
      cv::Scalar(255, 255, 0),
      2,
      cv::LINE_AA);
  } else if (best_detection != nullptr) {
    cv::putText(
      display_frame,
      "RGB sphere fit false",
      cv::Point(30, 155),
      cv::FONT_HERSHEY_SIMPLEX,
      0.65,
      cv::Scalar(0, 165, 255),
      2,
      cv::LINE_AA);
  }

  if (!rgb_sphere.edge_debug.empty()) {
    cv::imshow(
      "rgb_sphere_edges",
      rgb_sphere.edge_debug);
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
