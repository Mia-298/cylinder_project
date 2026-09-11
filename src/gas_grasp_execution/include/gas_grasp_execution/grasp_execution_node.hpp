#pragma once

#include <array>
#include <chrono>
#include <memory>
#include <string>

#include <gas_interfaces/srv/detect_objects.hpp>
#include <gas_interfaces/srv/gripper_activate.hpp>
#include <gas_interfaces/srv/gripper_move.hpp>
#include <gas_interfaces/srv/grasp_execute.hpp>
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
    bool & has_sphere_center_tool,
    std::array<double, 3> & sphere_center_tool_m,
    std::string & sphere_tool_frame_id,
    std::string & error_message);

  bool requestRobotPose(
    std::array<double, 6> & tcp_pose,
    cv::Mat & T_base_tool,
    std::string & error_message);

  bool requestMoveL(
    const std::array<double, 6> & target_tcp_pose,
    bool wait,
    std::string & error_message);

  bool requestGripperActivation(int gripper_index, bool activate, std::string & error_message);

  bool requestGripperMove(
    int gripper_index,
    int position,
    int velocity,
    int force,
    int max_time_ms,
    bool wait,
    std::string & error_message);

  static cv::Mat rpyToRotationMatrix(double rx, double ry, double rz);
  static cv::Mat makeHomogeneousMatrix(const cv::Mat & R, const cv::Mat & t);

  rclcpp::CallbackGroup::SharedPtr service_group_;
  rclcpp::CallbackGroup::SharedPtr client_group_;

  rclcpp::Client<gas_interfaces::srv::DetectObjects>::SharedPtr yolo_client_;
  rclcpp::Client<gas_interfaces::srv::RobotGetPose>::SharedPtr robot_pose_client_;
  rclcpp::Client<gas_interfaces::srv::RobotMoveL>::SharedPtr robot_move_l_client_;
  rclcpp::Client<gas_interfaces::srv::GripperActivate>::SharedPtr gripper_activate_client_;
  rclcpp::Client<gas_interfaces::srv::GripperMove>::SharedPtr gripper_move_client_;

  rclcpp::Service<gas_interfaces::srv::GraspExecute>::SharedPtr execute_srv_;

  std::string yolo_service_name_;
  std::string robot_pose_service_;
  std::string robot_move_l_service_;
  std::string gripper_activate_service_;
  std::string gripper_move_service_;
  std::string execute_service_name_;

  // 保留 GraspExecute.srv 中 approach_offset_m 字段以兼容现有接口，
  // 但其语义现在是“目标中心到预抓取 TCP 的水平安全距离”。
  double default_approach_offset_m_{0.20};
  double min_valid_depth_m_{0.05};
  double max_valid_depth_m_{5.0};
  double min_horizontal_direction_m_{1e-4};
  int service_timeout_ms_{3000};
  int move_timeout_ms_{30000};
  int gripper_service_timeout_ms_{10000};
};

}  // namespace gas
