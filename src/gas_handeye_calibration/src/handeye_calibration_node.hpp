#pragma once

#include <array>
#include <chrono>
#include <filesystem>
#include <future>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#if __has_include(<cv_bridge/cv_bridge.hpp>)
#include <cv_bridge/cv_bridge.hpp>
#elif __has_include(<cv_bridge/cv_bridge.h>)
#include <cv_bridge/cv_bridge.h>
#elif __has_include(<cv_bridge/cv_bridge/cv_bridge.h>)
#include <cv_bridge/cv_bridge/cv_bridge.h>
#else
#error "cv_bridge header not found"
#endif
#include <opencv2/aruco.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <std_msgs/msg/header.hpp>

#include <gas_interfaces/srv/hand_eye_add_sample.hpp>
#include <gas_interfaces/srv/hand_eye_clear_samples.hpp>
#include <gas_interfaces/srv/hand_eye_compute.hpp>
#include <gas_interfaces/srv/hand_eye_get_status.hpp>
#include <gas_interfaces/srv/robot_get_pose.hpp>

namespace gas
{

class HandEyeCalibrationNode : public rclcpp::Node
{
public:
  HandEyeCalibrationNode();

private:
  struct Sample
  {
    int sample_id = -1;
    rclcpp::Time stamp;
    std::string frame_id;
    std::string image_file;
    std::string debug_image_file;
    std::string sample_file;
    cv::Mat image_bgr;
    cv::Mat camera_matrix;
    cv::Mat dist_coeffs;
    std::vector<cv::Point2f> charuco_corners;
    std::vector<int> charuco_ids;
    cv::Vec3d board_rvec{0.0, 0.0, 0.0};
    cv::Vec3d board_tvec{0.0, 0.0, 0.0};
    cv::Mat T_base_tool;
    cv::Mat T_camera_board;
    double reprojection_error_px = 0.0;
  };

  void imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr msg);
  void cameraInfoCallback(const sensor_msgs::msg::CameraInfo::ConstSharedPtr msg);

  void addSampleCallback(
    const std::shared_ptr<gas_interfaces::srv::HandEyeAddSample::Request> request,
    std::shared_ptr<gas_interfaces::srv::HandEyeAddSample::Response> response);
  void clearSamplesCallback(
    const std::shared_ptr<gas_interfaces::srv::HandEyeClearSamples::Request> request,
    std::shared_ptr<gas_interfaces::srv::HandEyeClearSamples::Response> response);
  void computeCallback(
    const std::shared_ptr<gas_interfaces::srv::HandEyeCompute::Request> request,
    std::shared_ptr<gas_interfaces::srv::HandEyeCompute::Response> response);
  void statusCallback(
    const std::shared_ptr<gas_interfaces::srv::HandEyeGetStatus::Request> request,
    std::shared_ptr<gas_interfaces::srv::HandEyeGetStatus::Response> response);

  bool getLatestSnapshot(
    cv::Mat & image_bgr,
    std_msgs::msg::Header & header,
    cv::Mat & camera_matrix,
    cv::Mat & dist_coeffs,
    std::string & error_message) const;

  bool requestRobotPose(cv::Mat & T_base_tool, std::string & error_message);
  bool estimateBoardPose(
    const cv::Mat & image_bgr,
    const cv::Mat & camera_matrix,
    const cv::Mat & dist_coeffs,
    std::vector<cv::Point2f> & charuco_corners,
    std::vector<int> & charuco_ids,
    cv::Vec3d & rvec,
    cv::Vec3d & tvec,
    double & reprojection_error_px,
    cv::Mat & annotated_image,
    std::string & error_message) const;

  bool saveSampleFiles(const Sample & sample, std::string & error_message) const;
  bool saveSessionMetadata() const;
  bool saveResultFile(
    const std::string & output_path,
    const cv::Mat & T_tool_camera,
    const cv::Mat & T_camera_tool,
    const std::vector<Sample> & samples,
    double rms_reprojection_error_px,
    double closure_translation_rms_m,
    double closure_rotation_rms_deg,
    std::string & result_file,
    std::string & error_message) const;

  static cv::Mat rpyToRotationMatrix(double rx, double ry, double rz);
  static cv::Mat makeHomogeneousMatrix(const cv::Mat & R, const cv::Mat & t);
  static cv::Mat invertHomogeneousMatrix(const cv::Mat & T);
  static std::array<double, 16> matrixToArray16(const cv::Mat & T);
  static std::string nowString();
  static std::string sanitizeMethod(const std::string & method);
  static int handEyeMethodFromString(const std::string & method);
  static std::string serviceName(const std::string & service_namespace, const std::string & name);
  static bool matrixIsValidHomogeneous(const cv::Mat & T);
  int32_t sampleCount() const;

  cv::Mat buildCameraMatrixFromInfo(const sensor_msgs::msg::CameraInfo & msg) const;
  cv::Mat buildDistCoeffsFromInfo(const sensor_msgs::msg::CameraInfo & msg) const;

  std::string makeSamplePrefix(int sample_id) const;
  std::string makeSampleImageFile(int sample_id) const;
  std::string makeSampleDebugFile(int sample_id) const;
  std::string makeSampleYamlFile(int sample_id) const;
  std::string makeResultFile(const std::string & output_path) const;
  std::string makeSessionMetadataFile() const;

  mutable std::mutex data_mutex_;

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
  rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr camera_info_sub_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr debug_image_pub_;
  rclcpp::Service<gas_interfaces::srv::HandEyeAddSample>::SharedPtr add_sample_srv_;
  rclcpp::Service<gas_interfaces::srv::HandEyeClearSamples>::SharedPtr clear_samples_srv_;
  rclcpp::Service<gas_interfaces::srv::HandEyeCompute>::SharedPtr compute_srv_;
  rclcpp::Service<gas_interfaces::srv::HandEyeGetStatus>::SharedPtr status_srv_;
  rclcpp::Client<gas_interfaces::srv::RobotGetPose>::SharedPtr robot_pose_client_;
  rclcpp::CallbackGroup::SharedPtr service_group_;
  rclcpp::CallbackGroup::SharedPtr client_group_;

  cv::Ptr<cv::aruco::Dictionary> dictionary_;
  cv::Ptr<cv::aruco::CharucoBoard> board_;
  cv::Ptr<cv::aruco::DetectorParameters> detector_params_;

  std::string service_namespace_;
  std::string image_topic_;
  std::string camera_info_topic_;
  std::string robot_pose_service_;
  std::string save_root_dir_;
  std::string session_name_;
  std::string session_dir_;
  std::string samples_dir_;
  std::string debug_dir_;
  std::string results_dir_;
  std::string session_metadata_file_;

  int board_dictionary_id_ = cv::aruco::DICT_5X5_1000;
  int board_squares_x_ = 10;
  int board_squares_y_ = 7;
  double board_square_length_m_ = 0.025;
  double board_marker_length_m_ = 0.018;
  std::string handeye_method_ = "TSAI";
  int min_samples_ = 5;
  int robot_pose_timeout_ms_ = 2000;
  bool publish_debug_image_ = true;

  cv::Mat latest_image_bgr_;
  cv::Mat latest_camera_matrix_;
  cv::Mat latest_dist_coeffs_;
  std_msgs::msg::Header latest_image_header_;
  sensor_msgs::msg::CameraInfo latest_camera_info_;
  bool has_image_ = false;
  bool has_camera_info_ = false;
  bool has_robot_pose_ = false;
  bool has_calibration_ = false;

  int next_sample_id_ = 0;
  int last_sample_id_ = -1;
  double last_reprojection_error_px_ = -1.0;
  std::string last_error_;
  std::string last_sample_file_;
  std::string last_result_file_;
  cv::Mat last_T_tool_camera_;
  cv::Mat last_T_camera_tool_;

  std::vector<Sample> samples_;
};

}  // namespace gas
