#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <limits>
#include <mutex>
#include <optional>
#include <string>
#include <vector>
#include <atomic>
#include <array>

#include <ament_index_cpp/get_package_share_directory.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <rclcpp/rclcpp.hpp>
#include <gas_interfaces/srv/detect_objects.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

#include "sphere_fitter.hpp"
#include "yolov8_detector.hpp"

struct LocatedDetection
{
    Detection detection;
    SphereFitResult sphere;
    //   包含球心等结果
};

struct DetectionSnapshot
{
    rclcpp::Time image_stamp;
    rclcpp::Time cloud_stamp;
    std::string image_frame_id;
    std::string cloud_frame_id;
    cv::Size image_size;

    std::vector<Detection> detections;
    std::vector<LocatedDetection> located_detections;
};
struct DetectionResult
{
    // YOLO 是否检测到目标
    bool yolo_success{false};

    // 球面拟合是否成功
    bool sphere_fit_success{false};

    // 相机坐标系到机械臂末端坐标系的变换是否成功
    bool tool_transform_success{false};

    // YOLO bbox 归一化信息，范围为 [0, 1]
    // 0.5为适中位置，例如x<0.5,则表示目标中心偏画面左侧
    // y<0.5表示目标中心偏画面上侧
    // width_ratio = 0.5，表示目标已经占据图像宽度的 50%，需要定义有效识别位置（>0.4m=？）来确定是否需要后退识别
    float center_x_ratio{NAN};
    float center_y_ratio{NAN};
    float width_ratio{NAN};
    float height_ratio{NAN};

    // 球心坐标，单位 m
    // 当 sphere_fit_success == false 时保持 NaN
    float x{std::numeric_limits<float>::quiet_NaN()};
    float y{std::numeric_limits<float>::quiet_NaN()};
    float z{std::numeric_limits<float>::quiet_NaN()};

    // 球心在机械臂末端/TCP坐标系下的坐标，单位 m
    // 当 tool_transform_success == false 时保持 NaN
    float tool_x{std::numeric_limits<float>::quiet_NaN()};
    float tool_y{std::numeric_limits<float>::quiet_NaN()};
    float tool_z{std::numeric_limits<float>::quiet_NaN()};
};
class YoloDetectNode : public rclcpp::Node
{
public:
    
    YoloDetectNode(bool enable_vis);
    // 置信度最高的二维 YOLO 检测结果
    DetectionResult findBestDetectionResult(
    const std::string & object_name= "class_0") const;


private:
    bool enable_vis = false;

    enum class CaptureState
    {
        Idle,
        WaitingForCloud,
        WaitingForColor,
        Processing
    };
    // 定时0.5s
    double capture_interval_sec_{0.3};
    std::unique_ptr<YoloV8Detector> detector_;
    std::unique_ptr<SphereFitter> sphere_fitter_;

    std::string model_path_;
    std::string image_topic_;
    std::string point_cloud_topic_;
    std::string sphere_target_class_;
    std::string service_name_;
    std::string handeye_result_file_;
    std::string tool_frame_id_;

    // T_tool_camera: 将相机坐标系中的点变换到机械臂末端/TCP坐标系。
    cv::Mat T_tool_camera_;
    bool has_tool_camera_transform_{false};
    std::string handeye_load_error_;

    rclcpp::TimerBase::SharedPtr capture_timer_;
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr point_cloud_subscription_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscription_;
    rclcpp::Service<gas_interfaces::srv::DetectObjects>::SharedPtr detect_service_;

    void captureTimerCallback();
    void pointCloudCallback(const sensor_msgs::msg::PointCloud2::
    ConstSharedPtr message);
    void imageCallback(const sensor_msgs::msg::Image::
    ConstSharedPtr message);
    void handleDetectObjects(
      const std::shared_ptr<gas_interfaces::srv::DetectObjects::Request> request,
      std::shared_ptr<gas_interfaces::srv::DetectObjects::Response> response);

    bool loadToolCameraMatrix(
      const std::string & result_file,
      cv::Mat & T_tool_camera,
      std::string & error_message) const;
    bool transformCameraPointToTool(
      double x_camera,
      double y_camera,
      double z_camera,
      std::array<double, 3> & point_tool_m) const;
    static bool matrixIsValidHomogeneous(const cv::Mat & T);
    static cv::Mat invertHomogeneousMatrix(const cv::Mat & T);

    
    mutable std::mutex capture_mutex_;

    CaptureState capture_state_{CaptureState::Idle};
    sensor_msgs::msg::PointCloud2::ConstSharedPtr captured_cloud_message_;
    sensor_msgs::msg::Image::ConstSharedPtr captured_image_message_;
    std::chrono::steady_clock::time_point captured_cloud_arrival_time_;
    std::uint64_t capture_cycle_count_{0};

    mutable std::mutex detection_mutex_;
    DetectionSnapshot latest_snapshot_;
    void processCapturedBundle(
    const sensor_msgs::msg::Image::ConstSharedPtr & image_message,
    const sensor_msgs::msg::PointCloud2::ConstSharedPtr & cloud_message,
    std::uint64_t cycle_index);


    
};
