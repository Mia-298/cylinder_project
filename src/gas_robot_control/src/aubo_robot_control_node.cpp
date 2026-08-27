#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <exception>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include <rclcpp/rclcpp.hpp>

#include <gas_interfaces/srv/robot_connect.hpp>
#include <gas_interfaces/srv/robot_get_pose.hpp>
#include <gas_interfaces/srv/robot_move_j.hpp>
#include <gas_interfaces/srv/robot_move_l.hpp>
#include <gas_interfaces/srv/robot_set_handguide.hpp>
#include <gas_interfaces/srv/robot_set_enable.hpp>
#include <gas_interfaces/srv/robot_set_motion_params.hpp>
#include <gas_interfaces/srv/robot_stop.hpp>

#include "aubo/aubo_sdk/rpc.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace
{
constexpr int kSuccess = 0;
constexpr int kNoRobotInterface = -1001;
constexpr int kInvalidRequest = -1002;
constexpr int kTimeout = -1003;
constexpr int kException = -1004;

std::string serviceName(const std::string & service_namespace, const std::string & name)
{
  if(service_namespace.empty() || service_namespace == "/") {
    return "/" + name;
  }

  if(service_namespace.back() == '/') {
    return service_namespace + name;
  }

  return service_namespace + "/" + name;
}

template<typename ResponseT>
void setResponse(ResponseT & response, int error_code, const std::string & message)
{
  response.success = (error_code == kSuccess);
  response.error_code = error_code;
  response.message = message;
}

template<typename ResponseT>
void setExceptionResponse(ResponseT & response, const std::exception & e)
{
  response.success = false;
  response.error_code = kException;
  response.message = e.what();
}

std::vector<double> fixedArrayToVector(const std::array<double, 6> & values)
{
  return std::vector<double>(values.begin(), values.end());
}
}  // namespace

class AuboRobotControlNode : public rclcpp::Node
{
public:
  AuboRobotControlNode()
  : Node("aubo_robot_control_node")
  {
    robot_ip_ = this->declare_parameter<std::string>("robot_ip", "192.168.31.80");
    robot_port_ = static_cast<uint16_t>(this->declare_parameter<int>("robot_port", 30004));
    username_ = this->declare_parameter<std::string>("username", "aubo");
    password_ = this->declare_parameter<std::string>("password", "123456");
    request_timeout_ms_ = this->declare_parameter<int>("request_timeout_ms", 2000);
    auto_connect_ = this->declare_parameter<bool>("auto_connect", false);
    auto_enable_ = this->declare_parameter<bool>("auto_enable", false);
    auto_handguide_ = this->declare_parameter<bool>("auto_handguide", false);
    service_namespace_ = this->declare_parameter<std::string>("service_namespace", "/robot");
    velocity_rad_s_ = this->declare_parameter<double>("velocity_rad_s", 20.0 * M_PI / 180.0);
    acceleration_rad_s2_ =
      this->declare_parameter<double>("acceleration_rad_s2", 30.0 * M_PI / 180.0);
    blend_radius_m_ = this->declare_parameter<double>("blend_radius_m", 0.0);
    duration_s_ = this->declare_parameter<double>("duration_s", 0.0);
    motion_timeout_sec_ = this->declare_parameter<double>("motion_timeout_sec", 120.0);

    rpc_ = std::make_shared<arcs::aubo_sdk::RpcClient>();
    rpc_->setRequestTimeout(request_timeout_ms_);

    connect_srv_ = this->create_service<gas_interfaces::srv::RobotConnect>(
      serviceName(service_namespace_, "connect"),
      std::bind(
        &AuboRobotControlNode::connectCallback, this, std::placeholders::_1,
        std::placeholders::_2));
    enable_srv_ = this->create_service<gas_interfaces::srv::RobotSetEnable>(
      serviceName(service_namespace_, "enable"),
      std::bind(
        &AuboRobotControlNode::enableCallback, this, std::placeholders::_1,
        std::placeholders::_2));
    get_pose_srv_ = this->create_service<gas_interfaces::srv::RobotGetPose>(
      serviceName(service_namespace_, "get_pose"),
      std::bind(
        &AuboRobotControlNode::getPoseCallback, this, std::placeholders::_1,
        std::placeholders::_2));
    move_j_srv_ = this->create_service<gas_interfaces::srv::RobotMoveJ>(
      serviceName(service_namespace_, "move_j"),
      std::bind(
        &AuboRobotControlNode::moveJCallback, this, std::placeholders::_1,
        std::placeholders::_2));
    move_l_srv_ = this->create_service<gas_interfaces::srv::RobotMoveL>(
      serviceName(service_namespace_, "move_l"),
      std::bind(
        &AuboRobotControlNode::moveLCallback, this, std::placeholders::_1,
        std::placeholders::_2));
    stop_srv_ = this->create_service<gas_interfaces::srv::RobotStop>(
      serviceName(service_namespace_, "stop"),
      std::bind(
        &AuboRobotControlNode::stopCallback, this, std::placeholders::_1,
        std::placeholders::_2));
    set_motion_params_srv_ =
      this->create_service<gas_interfaces::srv::RobotSetMotionParams>(
        serviceName(service_namespace_, "set_motion_params"),
        std::bind(
          &AuboRobotControlNode::setMotionParamsCallback, this, std::placeholders::_1,
          std::placeholders::_2));
    handguide_srv_ = this->create_service<gas_interfaces::srv::RobotSetHandguide>(
      serviceName(service_namespace_, "handguide"),
      std::bind(
        &AuboRobotControlNode::handguideCallback, this, std::placeholders::_1,
        std::placeholders::_2));

    RCLCPP_INFO(
      this->get_logger(), "AUBO services ready under namespace: %s",
      service_namespace_.c_str());

    if(auto_connect_) {
      std::lock_guard<std::mutex> lock(robot_mutex_);
      const int result = connectLocked(robot_ip_, robot_port_, username_, password_);
      if(result != kSuccess) {
        RCLCPP_ERROR(this->get_logger(), "AUBO auto-connect failed: %d", result);
      } else {
        RCLCPP_INFO(this->get_logger(), "Auto-connected to AUBO robot: %s", robot_ip_.c_str());
        if(auto_enable_ || auto_handguide_) {
          const int enable_result = setEnableLocked(true);
          if(enable_result != kSuccess) {
            RCLCPP_ERROR(this->get_logger(), "AUBO auto-enable failed: %d", enable_result);
          } else if(auto_handguide_) {
            const int handguide_result = setHandguideLocked(true);
            if(handguide_result != kSuccess) {
              RCLCPP_ERROR(this->get_logger(), "AUBO auto-handguide failed: %d", handguide_result);
            } else {
              RCLCPP_INFO(this->get_logger(), "AUBO entered hand-guiding mode automatically.");
            }
          }
        }
      }
    }
  }

  ~AuboRobotControlNode() override
  {
    std::lock_guard<std::mutex> lock(robot_mutex_);
    disconnectLocked();
  }

private:
  arcs::common_interface::RobotInterfacePtr robotInterfaceLocked()
  {
    if(!rpc_ || !rpc_->hasConnected() || !rpc_->hasLogined()) {
      return nullptr;
    }

    if(robot_interface_) {
      return robot_interface_;
    }

    const auto robot_names = rpc_->getRobotNames();
    if(robot_names.empty()) {
      return nullptr;
    }

    robot_name_ = robot_names.front();
    robot_interface_ = rpc_->getRobotInterface(robot_name_);
    return robot_interface_;
  }

  int connectLocked(
    const std::string & ip,
    uint16_t port,
    const std::string & username,
    const std::string & password)
  {
    robot_ip_ = ip.empty() ? robot_ip_ : ip;
    robot_port_ = port == 0 ? robot_port_ : port;
    username_ = username.empty() ? username_ : username;
    password_ = password.empty() ? password_ : password;

    if(!rpc_) {
      rpc_ = std::make_shared<arcs::aubo_sdk::RpcClient>();
    }
    rpc_->setRequestTimeout(request_timeout_ms_);

    robot_interface_.reset();
    robot_name_.clear();

    int result = kSuccess;
    if(!rpc_->hasConnected()) {
      result = rpc_->connect(robot_ip_, robot_port_);
      if(result != kSuccess) {
        return result;
      }
    }

    if(!rpc_->hasLogined()) {
      result = rpc_->login(username_, password_);
      if(result != kSuccess) {
        return result;
      }
    }

    return robotInterfaceLocked() ? kSuccess : kNoRobotInterface;
  }

  void disconnectLocked()
  {
    robot_interface_.reset();
    robot_name_.clear();

    if(!rpc_) {
      return;
    }

    if(rpc_->hasLogined()) {
      rpc_->logout();
    }
    if(rpc_->hasConnected()) {
      rpc_->disconnect();
    }
  }

  bool waitForModeLocked(
    arcs::common_interface::RobotInterfacePtr robot_interface,
    arcs::common_interface::RobotModeType target_mode,
    double timeout_sec)
  {
    const auto deadline = std::chrono::steady_clock::now() +
      std::chrono::duration<double>(timeout_sec);

    while(std::chrono::steady_clock::now() < deadline) {
      if(robot_interface->getRobotState()->getRobotModeType() == target_mode) {
        return true;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return false;
  }

  int setEnableLocked(bool enable)
  {
    auto robot_interface = robotInterfaceLocked();
    if(!robot_interface) {
      return kNoRobotInterface;
    }

    if(enable) {
      const double mass = 0.0;
      const std::vector<double> cog(3, 0.0);
      const std::vector<double> aom(3, 0.0);
      const std::vector<double> inertia(6, 0.0);
      robot_interface->getRobotConfig()->setPayload(mass, cog, aom, inertia);

      if(robot_interface->getRobotState()->getRobotModeType() ==
         arcs::common_interface::RobotModeType::Running)
      {
        return kSuccess;
      }

      int result = robot_interface->getRobotManage()->poweron();
      if(result != kSuccess) {
        return result;
      }
      if(!waitForModeLocked(
          robot_interface, arcs::common_interface::RobotModeType::Idle, motion_timeout_sec_))
      {
        return kTimeout;
      }

      result = robot_interface->getRobotManage()->startup();
      if(result != kSuccess) {
        return result;
      }
      if(!waitForModeLocked(
          robot_interface, arcs::common_interface::RobotModeType::Running, motion_timeout_sec_))
      {
        return kTimeout;
      }

      return kSuccess;
    }

    const int result = robot_interface->getRobotManage()->poweroff();
    if(result != kSuccess) {
      return result;
    }

    if(!waitForModeLocked(
        robot_interface, arcs::common_interface::RobotModeType::PowerOff, motion_timeout_sec_))
    {
      return kTimeout;
    }

    return kSuccess;
  }

  int setHandguideLocked(bool enable)
  {
    auto robot_interface = robotInterfaceLocked();
    if(!robot_interface) {
      return kNoRobotInterface;
    }

    const bool is_enabled = robot_interface->getRobotManage()->isHandguideEnabled();
    if(enable && is_enabled) {
      return kSuccess;
    }
    if(!enable && !is_enabled) {
      return kSuccess;
    }

    if(enable && robot_interface->getRobotState()->getRobotModeType() !=
      arcs::common_interface::RobotModeType::Running)
    {
      const int enable_result = setEnableLocked(true);
      if(enable_result != kSuccess) {
        return enable_result;
      }
    }

    std::vector<int> free_axes(6, 1);
    std::vector<double> feature(6, 0.0);

    int result = kSuccess;
    if(enable) {
      result = robot_interface->getRobotManage()->handguideMode(free_axes, feature);
      if(result != kSuccess) {
        result = robot_interface->getRobotManage()->freedrive(true);
      }
    } else {
      result = robot_interface->getRobotManage()->exitHandguideMode();
      if(result != kSuccess) {
        result = robot_interface->getRobotManage()->freedrive(false);
      }
    }

    return result;
  }

  int waitArrivalLocked(arcs::common_interface::RobotInterfacePtr robot_interface)
  {
    const auto start_deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(300);
    while(robot_interface->getMotionControl()->getExecId() == -1 &&
          std::chrono::steady_clock::now() < start_deadline)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    const auto motion_deadline = std::chrono::steady_clock::now() +
      std::chrono::duration<double>(motion_timeout_sec_);
    while(robot_interface->getMotionControl()->getExecId() != -1) {
      if(std::chrono::steady_clock::now() >= motion_deadline) {
        return kTimeout;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return kSuccess;
  }

  void connectCallback(
    std::shared_ptr<gas_interfaces::srv::RobotConnect::Request> request,
    std::shared_ptr<gas_interfaces::srv::RobotConnect::Response> response)
  {
    try {
      std::lock_guard<std::mutex> lock(robot_mutex_);
      const int result =
        connectLocked(request->ip, request->port, request->username, request->password);
      setResponse(*response, result, result == kSuccess ? "Connected." : "Connect failed.");
    } catch(const std::exception & e) {
      setExceptionResponse(*response, e);
    }
  }

  void enableCallback(
    std::shared_ptr<gas_interfaces::srv::RobotSetEnable::Request> request,
    std::shared_ptr<gas_interfaces::srv::RobotSetEnable::Response> response)
  {
    try {
      std::lock_guard<std::mutex> lock(robot_mutex_);
      const int result = setEnableLocked(request->enable);
      setResponse(*response, result, result == kSuccess ? "Enable command completed." :
        "Enable command failed.");
    } catch(const std::exception & e) {
      setExceptionResponse(*response, e);
    }
  }

  void getPoseCallback(
    const std::shared_ptr<gas_interfaces::srv::RobotGetPose::Request>,
    std::shared_ptr<gas_interfaces::srv::RobotGetPose::Response> response)
  {
    try {
      std::lock_guard<std::mutex> lock(robot_mutex_);
      auto robot_interface = robotInterfaceLocked();
      if(!robot_interface) {
        setResponse(*response, kNoRobotInterface, "Robot is not connected or logged in.");
        return;
      }

      const auto joint_positions = robot_interface->getRobotState()->getJointPositions();
      const auto tcp_pose = robot_interface->getRobotState()->getTcpPose();
      if(joint_positions.size() < 6 || tcp_pose.size() < 6) {
        setResponse(*response, kInvalidRequest, "SDK returned pose vectors with size < 6.");
        return;
      }

      for(size_t i = 0; i < 6; ++i) {
        response->joint_rad[i] = joint_positions.at(i);
        response->tcp_xyz_m_rpy_rad[i] = tcp_pose.at(i);
      }
      setResponse(*response, kSuccess, "Pose read.");
    } catch(const std::exception & e) {
      setExceptionResponse(*response, e);
    }
  }

  void moveJCallback(
    std::shared_ptr<gas_interfaces::srv::RobotMoveJ::Request> request,
    std::shared_ptr<gas_interfaces::srv::RobotMoveJ::Response> response)
  {
    try {
      std::lock_guard<std::mutex> lock(robot_mutex_);
      auto robot_interface = robotInterfaceLocked();
      if(!robot_interface) {
        setResponse(*response, kNoRobotInterface, "Robot is not connected or logged in.");
        return;
      }

      const auto joint_rad = fixedArrayToVector(request->joint_rad);
      int result = robot_interface->getMotionControl()->moveJoint(
        joint_rad, acceleration_rad_s2_, velocity_rad_s_, blend_radius_m_, duration_s_);
      if(result == kSuccess && request->wait) {
        result = waitArrivalLocked(robot_interface);
      }
      setResponse(*response, result, result == kSuccess ? "MoveJ completed." : "MoveJ failed.");
    } catch(const std::exception & e) {
      setExceptionResponse(*response, e);
    }
  }

  void moveLCallback(
    std::shared_ptr<gas_interfaces::srv::RobotMoveL::Request> request,
    std::shared_ptr<gas_interfaces::srv::RobotMoveL::Response> response)
  {
    try {
      std::lock_guard<std::mutex> lock(robot_mutex_);
      auto robot_interface = robotInterfaceLocked();
      if(!robot_interface) {
        setResponse(*response, kNoRobotInterface, "Robot is not connected or logged in.");
        return;
      }

      const auto tcp_pose = fixedArrayToVector(request->tcp_xyz_m_rpy_rad);
      int result = robot_interface->getMotionControl()->moveLine(
        tcp_pose, acceleration_rad_s2_, velocity_rad_s_, blend_radius_m_, duration_s_);
      if(result == kSuccess && request->wait) {
        result = waitArrivalLocked(robot_interface);
      }
      setResponse(*response, result, result == kSuccess ? "MoveL completed." : "MoveL failed.");
    } catch(const std::exception & e) {
      setExceptionResponse(*response, e);
    }
  }

  void stopCallback(
    const std::shared_ptr<gas_interfaces::srv::RobotStop::Request>,
    std::shared_ptr<gas_interfaces::srv::RobotStop::Response> response)
  {
    try {
      std::lock_guard<std::mutex> lock(robot_mutex_);
      auto robot_interface = robotInterfaceLocked();
      if(!robot_interface) {
        setResponse(*response, kNoRobotInterface, "Robot is not connected or logged in.");
        return;
      }

      const int result = robot_interface->getMotionControl()->stopMove(true, true);
      setResponse(*response, result, result == kSuccess ? "Stop command sent." : "Stop failed.");
    } catch(const std::exception & e) {
      setExceptionResponse(*response, e);
    }
  }

  void handguideCallback(
    std::shared_ptr<gas_interfaces::srv::RobotSetHandguide::Request> request,
    std::shared_ptr<gas_interfaces::srv::RobotSetHandguide::Response> response)
  {
    try {
      std::lock_guard<std::mutex> lock(robot_mutex_);
      const int result = setHandguideLocked(request->enable);
      setResponse(*response, result, result == kSuccess ? "Handguide command completed." :
        "Handguide command failed.");
    } catch(const std::exception & e) {
      setExceptionResponse(*response, e);
    }
  }

  void setMotionParamsCallback(
    std::shared_ptr<gas_interfaces::srv::RobotSetMotionParams::Request> request,
    std::shared_ptr<gas_interfaces::srv::RobotSetMotionParams::Response> response)
  {
    try {
      if(request->velocity_rad_s <= 0.0 || request->acceleration_rad_s2 <= 0.0 ||
         request->blend_radius_m < 0.0 || request->duration_s < 0.0)
      {
        setResponse(*response, kInvalidRequest, "Invalid motion parameters.");
        return;
      }

      std::lock_guard<std::mutex> lock(robot_mutex_);
      velocity_rad_s_ = request->velocity_rad_s;
      acceleration_rad_s2_ = request->acceleration_rad_s2;
      blend_radius_m_ = request->blend_radius_m;
      duration_s_ = request->duration_s;
      setResponse(*response, kSuccess, "Motion parameters updated.");
    } catch(const std::exception & e) {
      setExceptionResponse(*response, e);
    }
  }

  std::shared_ptr<arcs::aubo_sdk::RpcClient> rpc_;
  arcs::common_interface::RobotInterfacePtr robot_interface_;
  std::string robot_name_;
  std::mutex robot_mutex_;

  std::string robot_ip_;
  uint16_t robot_port_{30004};
  std::string username_;
  std::string password_;
  int request_timeout_ms_{2000};
  bool auto_connect_{false};
  bool auto_enable_{false};
  bool auto_handguide_{false};
  std::string service_namespace_{"/robot"};
  double velocity_rad_s_{20.0 * M_PI / 180.0};
  double acceleration_rad_s2_{30.0 * M_PI / 180.0};
  double blend_radius_m_{0.0};
  double duration_s_{0.0};
  double motion_timeout_sec_{120.0};

  rclcpp::Service<gas_interfaces::srv::RobotConnect>::SharedPtr connect_srv_;
  rclcpp::Service<gas_interfaces::srv::RobotSetEnable>::SharedPtr enable_srv_;
  rclcpp::Service<gas_interfaces::srv::RobotGetPose>::SharedPtr get_pose_srv_;
  rclcpp::Service<gas_interfaces::srv::RobotMoveJ>::SharedPtr move_j_srv_;
  rclcpp::Service<gas_interfaces::srv::RobotMoveL>::SharedPtr move_l_srv_;
  rclcpp::Service<gas_interfaces::srv::RobotStop>::SharedPtr stop_srv_;
  rclcpp::Service<gas_interfaces::srv::RobotSetMotionParams>::SharedPtr set_motion_params_srv_;
  rclcpp::Service<gas_interfaces::srv::RobotSetHandguide>::SharedPtr handguide_srv_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AuboRobotControlNode>());
  rclcpp::shutdown();
  return 0;
}
