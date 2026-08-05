#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

#include <Eigen/Core>
#include <opencv2/core.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

struct SphereFitParameters
{
  // 设置相机-球体距离范围
  float min_depth_m{0.10F};
  float max_depth_m{2.00F};

  // 设置球体半径
  float min_radius_m{0.08F};
  float max_radius_m{0.93F};

  float distance_threshold_m{0.006F};
  int max_iterations{1200};
  double success_probability{0.995};

  std::size_t min_roi_points{120};
  std::size_t min_inliers{80};
  float min_inlier_ratio{0.25F};

  // Remove a small band near the YOLO box boundary, where background
  // and occluding structures are most likely to enter the ROI.
  float roi_shrink_ratio{0.05F};

  // 1 uses every pixel; 2 uses one point every two pixels, etc.
  int pixel_stride{1};
};

struct SphereFitResult
{
  bool success{false};
  std::string failure_reason;

  Eigen::Vector3f center_m{Eigen::Vector3f::Zero()};
  float radius_m{0.0F};

  std::size_t roi_point_count{0};
  std::size_t inlier_count{0};
  float inlier_ratio{0.0F};
  float rms_residual_m{0.0F};

  // The ROI after conversion from image coordinates to cloud coordinates.
  cv::Rect cloud_roi;
};

class SphereFitter
{
public:
  explicit SphereFitter(
    SphereFitParameters parameters = SphereFitParameters{});

  const SphereFitParameters & parameters() const noexcept;

  void setParameters(const SphereFitParameters & parameters);

  // Requirements:
  // 1. cloud must be organized (height > 1);
  // 2. cloud pixels must correspond to the color image pixels;
  // 3. image_box must use coordinates in image_size.
  SphereFitResult fit(
    const pcl::PointCloud<pcl::PointXYZ>::ConstPtr & cloud,
    const cv::Rect & image_box,
    const cv::Size & image_size) const;

private:
  static void validateParameters(
    const SphereFitParameters & parameters);

  SphereFitParameters parameters_;
};
