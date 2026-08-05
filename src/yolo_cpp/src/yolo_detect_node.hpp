#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <vector>
#include <atomic>

#include <ament_index_cpp/get_package_share_directory.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <rclcpp/rclcpp.hpp>
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
    std::string cloud_frame_id;
    cv::Size image_size;

    std::vector<Detection> detections;
    std::vector<LocatedDetection> located_detections;
};
class YoloDetectNode : public rclcpp::Node
{
public:
    
    YoloDetectNode();
    DetectionSnapshot getLatestDetections() const;
    // 置信度最高的二维 YOLO 检测结果
    std::optional<Detection> findBestDetection(
        const std::string & object_name) const;
    // 已经成功完成球面拟合的三维定位结果
    std::optional<LocatedDetection> findBestLocatedDetection(
    const std::string & object_name) const;


private:

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

    rclcpp::TimerBase::SharedPtr capture_timer_;
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr point_cloud_subscription_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscription_;

    void captureTimerCallback();
    void pointCloudCallback(const sensor_msgs::msg::PointCloud2::
    ConstSharedPtr message);
    void imageCallback(const sensor_msgs::msg::Image::
    ConstSharedPtr message);

    
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

