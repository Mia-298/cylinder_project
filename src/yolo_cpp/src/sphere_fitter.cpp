#include "sphere_fitter.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <utility>

#include <pcl/ModelCoefficients.h>
#include <pcl/PointIndices.h>
#include <pcl/segmentation/sac_segmentation.h>

namespace
{

bool isFinitePoint(const pcl::PointXYZ & point)
{
  return std::isfinite(point.x) &&
         std::isfinite(point.y) &&
         std::isfinite(point.z);
}

cv::Rect clipAndShrinkRoi(
  const cv::Rect & image_box,
  const cv::Size & image_size,
  const float horizontal_shrink_ratio,
  const float top_shrink_ratio,
  const float bottom_shrink_ratio)
{
  const cv::Rect image_bounds(
    0,
    0,
    image_size.width,
    image_size.height);

  /*
   * 先把 YOLO 框限制在图像范围内。
   */
  const cv::Rect clipped =
    image_box & image_bounds;

  if (
    clipped.width <= 0 ||
    clipped.height <= 0)
  {
    return {};
  }

  /*
   * 左右对称裁剪。
   * 当前设置为 0.0，因此左右不裁剪。
   */
  const int shrink_x =
    static_cast<int>(
    std::lround(
      static_cast<double>(clipped.width) *
      static_cast<double>(
        horizontal_shrink_ratio)));

  /*
   * 上下分别采用不同的裁剪比例。
   */
  const int shrink_top =
    static_cast<int>(
    std::lround(
      static_cast<double>(clipped.height) *
      static_cast<double>(
        top_shrink_ratio)));

  const int shrink_bottom =
    static_cast<int>(
    std::lround(
      static_cast<double>(clipped.height) *
      static_cast<double>(
        bottom_shrink_ratio)));

  const int new_x =
    clipped.x + shrink_x;

  const int new_y =
    clipped.y + shrink_top;

  const int new_width =
    clipped.width -
    2 * shrink_x;

  const int new_height =
    clipped.height -
    shrink_top -
    shrink_bottom;

  if (
    new_width <= 0 ||
    new_height <= 0)
  {
    return {};
  }

  return cv::Rect(
    new_x,
    new_y,
    new_width,
    new_height);
}

cv::Rect imageRoiToCloudRoi(
  const cv::Rect & image_roi,
  const cv::Size & image_size,
  const std::uint32_t cloud_width,
  const std::uint32_t cloud_height)
{
  const double scale_x =
    static_cast<double>(cloud_width) /
    static_cast<double>(image_size.width);

  const double scale_y =
    static_cast<double>(cloud_height) /
    static_cast<double>(image_size.height);

  int left = static_cast<int>(
    std::floor(
      static_cast<double>(image_roi.x) * scale_x));

  int top = static_cast<int>(
    std::floor(
      static_cast<double>(image_roi.y) * scale_y));

  int right = static_cast<int>(
    std::ceil(
      static_cast<double>(image_roi.x + image_roi.width) * scale_x));

  int bottom = static_cast<int>(
    std::ceil(
      static_cast<double>(image_roi.y + image_roi.height) * scale_y));

  left = std::clamp(left, 0, static_cast<int>(cloud_width));
  top = std::clamp(top, 0, static_cast<int>(cloud_height));
  right = std::clamp(right, 0, static_cast<int>(cloud_width));
  bottom = std::clamp(bottom, 0, static_cast<int>(cloud_height));

  if (right <= left || bottom <= top) {
    return {};
  }

  return cv::Rect(
    left,
    top,
    right - left,
    bottom - top);
}

}  // namespace

SphereFitter::SphereFitter(
  SphereFitParameters parameters)
: parameters_(std::move(parameters))
{
  validateParameters(parameters_);
}

const SphereFitParameters &
SphereFitter::parameters() const noexcept
{
  return parameters_;
}

void SphereFitter::setParameters(
  const SphereFitParameters & parameters)
{
  validateParameters(parameters);
  parameters_ = parameters;
}

void SphereFitter::validateParameters(
  const SphereFitParameters & parameters)
{
  if (parameters.min_depth_m < 0.0F ||
      parameters.max_depth_m <= parameters.min_depth_m)
  {
    throw std::invalid_argument(
      "SphereFitter: invalid depth limits");
  }

  if (parameters.min_radius_m <= 0.0F ||
      parameters.max_radius_m <= parameters.min_radius_m)
  {
    throw std::invalid_argument(
      "SphereFitter: invalid radius limits");
  }

  if (parameters.distance_threshold_m <= 0.0F) {
    throw std::invalid_argument(
      "SphereFitter: distance_threshold_m must be positive");
  }

  if (parameters.max_iterations <= 0) {
    throw std::invalid_argument(
      "SphereFitter: max_iterations must be positive");
  }

  if (parameters.success_probability <= 0.0 ||
      parameters.success_probability >= 1.0)
  {
    throw std::invalid_argument(
      "SphereFitter: success_probability must be in (0, 1)");
  }

  if (parameters.min_roi_points < 4U ||
      parameters.min_inliers < 4U)
  {
    throw std::invalid_argument(
      "SphereFitter: at least four points are required");
  }

  if (parameters.min_inlier_ratio <= 0.0F ||
      parameters.min_inlier_ratio > 1.0F)
  {
    throw std::invalid_argument(
      "SphereFitter: min_inlier_ratio must be in (0, 1]");
  }

  if (parameters.roi_shrink_ratio < 0.0F ||
      parameters.roi_shrink_ratio >= 0.5F)
  {
    throw std::invalid_argument(
      "SphereFitter: roi_shrink_ratio must be in [0, 0.5)");
  }

  if (parameters.pixel_stride <= 0) {
    throw std::invalid_argument(
      "SphereFitter: pixel_stride must be positive");
  }
}

SphereFitResult SphereFitter::fit(
  const pcl::PointCloud<pcl::PointXYZ>::ConstPtr & cloud,
  const cv::Rect & image_box,
  const cv::Size & image_size) const
{
  SphereFitResult result;

  if (!cloud) {
    result.failure_reason = "point cloud pointer is null";
    return result;
  }

  if (image_size.width <= 0 || image_size.height <= 0) {
    result.failure_reason = "image size is invalid";
    return result;
  }

  if (image_box.width <= 0 || image_box.height <= 0) {
    result.failure_reason = "detection box is invalid";
    return result;
  }

  if (!cloud->isOrganized() || cloud->height <= 1U) {
    result.failure_reason =
      "point cloud is not organized; enable ordered point cloud output";
    return result;
  }

  const std::size_t expected_point_count =
    static_cast<std::size_t>(cloud->width) *
    static_cast<std::size_t>(cloud->height);

  if (cloud->points.size() < expected_point_count) {
    result.failure_reason =
      "organized cloud dimensions exceed point storage";
    return result;
  }

  const cv::Rect image_roi = clipAndShrinkRoi(
    image_box,
    image_size,
    parameters_.roi_shrink_ratio,
    parameters_.roi_shrink_top_ratio,
    parameters_.roi_shrink_bottom_ratio);

  if (image_roi.width <= 0 || image_roi.height <= 0) {
    result.failure_reason =
      "detection box does not overlap the image";
    return result;
  }

  result.cloud_roi = imageRoiToCloudRoi(
    image_roi,
    image_size,
    cloud->width,
    cloud->height);

  if (result.cloud_roi.width <= 0 ||
      result.cloud_roi.height <= 0)
  {
    result.failure_reason =
      "mapped point-cloud ROI is empty";
    return result;
  }

  pcl::PointCloud<pcl::PointXYZ>::Ptr roi_cloud(
    new pcl::PointCloud<pcl::PointXYZ>());

  const std::size_t reserve_count =
    static_cast<std::size_t>(result.cloud_roi.width) *
    static_cast<std::size_t>(result.cloud_roi.height) /
    static_cast<std::size_t>(
      parameters_.pixel_stride * parameters_.pixel_stride);

  roi_cloud->points.reserve(reserve_count);

  const int right =
    result.cloud_roi.x + result.cloud_roi.width;

  const int bottom =
    result.cloud_roi.y + result.cloud_roi.height;

  for (
    int v = result.cloud_roi.y;
    v < bottom;
    v += parameters_.pixel_stride)
  {
    for (
      int u = result.cloud_roi.x;
      u < right;
      u += parameters_.pixel_stride)
    {
      const pcl::PointXYZ & point = cloud->at(
        static_cast<std::uint32_t>(u),
        static_cast<std::uint32_t>(v));

      if (!isFinitePoint(point)) {
        continue;
      }

      if (point.z < parameters_.min_depth_m ||
          point.z > parameters_.max_depth_m)
      {
        continue;
      }

      roi_cloud->points.push_back(point);
    }
  }

  roi_cloud->width = static_cast<std::uint32_t>(
    roi_cloud->points.size());
  roi_cloud->height = 1U;
  roi_cloud->is_dense = true;

  result.roi_point_count = roi_cloud->points.size();

  if (result.roi_point_count < parameters_.min_roi_points) {
    result.failure_reason =
      "too few finite points inside the detection ROI";
    return result;
  }

  pcl::SACSegmentation<pcl::PointXYZ> segmentation;
  segmentation.setOptimizeCoefficients(true);
  segmentation.setModelType(pcl::SACMODEL_SPHERE);
  segmentation.setMethodType(pcl::SAC_RANSAC);
  segmentation.setDistanceThreshold(
    parameters_.distance_threshold_m);
  segmentation.setMaxIterations(
    parameters_.max_iterations);
  segmentation.setProbability(
    parameters_.success_probability);
  segmentation.setRadiusLimits(
    parameters_.min_radius_m,
    parameters_.max_radius_m);
  segmentation.setInputCloud(roi_cloud);

  pcl::PointIndices inliers;
  pcl::ModelCoefficients coefficients;
  segmentation.segment(inliers, coefficients);

  result.inlier_count = inliers.indices.size();

  result.inlier_ratio =
    result.roi_point_count == 0U ?
    0.0F :
    static_cast<float>(result.inlier_count) /
    static_cast<float>(result.roi_point_count);

  if (coefficients.values.size() < 4U) {
    result.failure_reason =
      "RANSAC did not return sphere coefficients";
    return result;
  }

  if (result.inlier_count < parameters_.min_inliers) {
    result.failure_reason =
      "sphere inlier count is below the acceptance threshold";
    return result;
  }

  if (result.inlier_ratio < parameters_.min_inlier_ratio) {
    result.failure_reason =
      "sphere inlier ratio is below the acceptance threshold";
    return result;
  }

  const Eigen::Vector3f center(
    coefficients.values.at(0),
    coefficients.values.at(1),
    coefficients.values.at(2));

  const float radius = coefficients.values.at(3);

  if (!center.allFinite() || !std::isfinite(radius)) {
    result.failure_reason =
      "sphere coefficients contain non-finite values";
    return result;
  }

  if (radius < parameters_.min_radius_m ||
      radius > parameters_.max_radius_m)
  {
    result.failure_reason =
      "fitted radius is outside the configured limits";
    return result;
  }

  double squared_residual_sum = 0.0;
  std::size_t valid_residual_count = 0U;

  for (const int index : inliers.indices) {
    if (index < 0 ||
        static_cast<std::size_t>(index) >= roi_cloud->points.size())
    {
      continue;
    }

    const pcl::PointXYZ & point =
      roi_cloud->points.at(static_cast<std::size_t>(index));

    const Eigen::Vector3f point_vector(
      point.x,
      point.y,
      point.z);

    const double residual = std::abs(
      static_cast<double>((point_vector - center).norm()) -
      static_cast<double>(radius));

    squared_residual_sum += residual * residual;
    ++valid_residual_count;
  }

  if (valid_residual_count == 0U) {
    result.failure_reason =
      "no valid residuals could be calculated";
    return result;
  }

  result.center_m = center;
  result.radius_m = radius;
  result.rms_residual_m = static_cast<float>(
    std::sqrt(
      squared_residual_sum /
      static_cast<double>(valid_residual_count)));
  result.success = true;
  result.failure_reason.clear();

  return result;
}
