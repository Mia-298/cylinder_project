#include "yolo_detect_node.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <stdexcept>

#include <pcl/exceptions.h>
#include <pcl_conversions/pcl_conversions.h>
#include <rmw/qos_profiles.h>
// 测试用 可视化文件
#include <iomanip>
#include <sstream>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

YoloDetectNode::YoloDetectNode()
: Node("yolo_detect_node")
{
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
    "/camera/depth_registered/points");

  sphere_target_class_ = declare_parameter<std::string>(
    "sphere_target_class",
    "class_0");

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
    "Capture interval: %.3f s",
    capture_interval_sec_);

  RCLCPP_INFO(
    get_logger(),
    "Timestamp synchronization disabled");

}

DetectionSnapshot YoloDetectNode::getLatestDetections() const
{
  std::lock_guard<std::mutex> lock(detection_mutex_);
  return latest_snapshot_;
}

std::optional<Detection> YoloDetectNode::findBestDetection(
  const std::string & object_name) const
{
  std::lock_guard<std::mutex> lock(detection_mutex_);

  const Detection * best_detection = nullptr;

  for (const Detection & detection : latest_snapshot_.detections) {
    if (detection.class_name != object_name) {
      continue;
    }

    if (best_detection == nullptr ||
        detection.confidence > best_detection->confidence)
    {
      best_detection = &detection;
    }
  }

  if (best_detection == nullptr) {
    return std::nullopt;
  }

  return *best_detection;
}

std::optional<LocatedDetection>
YoloDetectNode::findBestLocatedDetection(
  const std::string & object_name) const
{
  std::lock_guard<std::mutex> lock(detection_mutex_);

  const LocatedDetection * best_detection = nullptr;

  for (const LocatedDetection & located :
       latest_snapshot_.located_detections)
  {
    if (!located.sphere.success ||
        located.detection.class_name != object_name)
    {
      continue;
    }

    if (best_detection == nullptr ||
        located.detection.confidence >
        best_detection->detection.confidence)
    {
      best_detection = &located;
    }
  }

  if (best_detection == nullptr) {
    return std::nullopt;
  }

  return *best_detection;
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

  // 以下是窗口测试
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
  if(located_detections.empty()){
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