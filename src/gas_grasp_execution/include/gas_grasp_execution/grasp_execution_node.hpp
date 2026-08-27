#pragma once

#include <array>
#include <chrono>
#include <memory>
#include <string>

#include <gas_interfaces/srv/detect_objects.hpp>
#include <gas_interfaces/srv/grasp_execute.hpp>
#include <gas_interfaces/srv/hand_eye_get_status.hpp>
#include <gas_interfaces/srv/robot_get_pose.hpp>
#include <gas_interfaces/srv/robot_move_l.hpp>
#include <opencv2/core.hpp>
#include <rclcpp/rclcpp.hpp>

namespace gas
{

class GraspExecutionNode : public rclcpp::Node
{
public:
  GraspExecutionNode();

private:
  void executeCallback(
    const std::shared_ptr<gas_interfaces::srv::GraspExecute::Request> request,
    std::shared_ptr<gas_interfaces::srv::GraspExecute::Response> response);

  bool requestYoloDetection(
    bool publish_debug_image,
    bool & has_sphere_center,
    std::array<double, 3> & sphere_center_m,
    double & sphere_radius_m,
    std::string & sphere_frame_id,
    std::string & sphere_class_id,
    double & sphere_confidence,
    std::string & error_message);
  bool requestRobotPose(std::array<double, 6> & tcp_pose, cv::Mat & T_base_tool,
    std::string & error_message);
  bool requestMoveL(
    const std::array<double, 6> & target_tcp_pose,
    bool wait,
    std::string & error_message);
  bool resolveHandeyeResultFile(std::string & result_file, std::string & error_message);
  bool loadToolCameraMatrix(
    const std::string & result_file,
    cv::Mat & T_tool_camera,
    std::string & error_message) const;

  static cv::Mat rpyToRotationMatrix(double rx, double ry, double rz);
  static cv::Mat makeHomogeneousMatrix(const cv::Mat & R, const cv::Mat & t);
  static cv::Mat invertHomogeneousMatrix(const cv::Mat & T);
  static bool matrixIsValidHomogeneous(const cv::Mat & T);
  static std::array<double, 16> matrixToArray16(const cv::Mat & T);
  static std::string serviceName(const std::string & service_namespace, const std::string & name);

  rclcpp::CallbackGroup::SharedPtr service_group_;
  rclcpp::CallbackGroup::SharedPtr client_group_;

  rclcpp::Client<gas_interfaces::srv::DetectObjects>::SharedPtr yolo_client_;
  rclcpp::Client<gas_interfaces::srv::RobotGetPose>::SharedPtr robot_pose_client_;
  rclcpp::Client<gas_interfaces::srv::RobotMoveL>::SharedPtr robot_move_l_client_;
  rclcpp::Client<gas_interfaces::srv::HandEyeGetStatus>::SharedPtr handeye_status_client_;

  rclcpp::Service<gas_interfaces::srv::GraspExecute>::SharedPtr execute_srv_;

  std::string yolo_service_name_;
  std::string robot_pose_service_;
  std::string robot_move_l_service_;
  std::string handeye_status_service_;
  std::string handeye_result_file_;
  std::string execute_service_name_;

  double default_approach_offset_m_{0.10};
  double min_valid_depth_m_{0.05};
  double max_valid_depth_m_{5.0};
  int service_timeout_ms_{3000};
  int move_timeout_ms_{30000};
};

}  // namespace gas
