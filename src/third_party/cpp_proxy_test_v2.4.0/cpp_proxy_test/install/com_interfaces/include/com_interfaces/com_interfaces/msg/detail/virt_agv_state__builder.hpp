// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/VirtAgvState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__VIRT_AGV_STATE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__VIRT_AGV_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/virt_agv_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_VirtAgvState_vel_ang
{
public:
  explicit Init_VirtAgvState_vel_ang(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::VirtAgvState vel_ang(::com_interfaces::msg::VirtAgvState::_vel_ang_type arg)
  {
    msg_.vel_ang = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_vel_y
{
public:
  explicit Init_VirtAgvState_vel_y(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_vel_ang vel_y(::com_interfaces::msg::VirtAgvState::_vel_y_type arg)
  {
    msg_.vel_y = std::move(arg);
    return Init_VirtAgvState_vel_ang(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_vel_x
{
public:
  explicit Init_VirtAgvState_vel_x(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_vel_y vel_x(::com_interfaces::msg::VirtAgvState::_vel_x_type arg)
  {
    msg_.vel_x = std::move(arg);
    return Init_VirtAgvState_vel_y(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_last_station
{
public:
  explicit Init_VirtAgvState_last_station(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_vel_x last_station(::com_interfaces::msg::VirtAgvState::_last_station_type arg)
  {
    msg_.last_station = std::move(arg);
    return Init_VirtAgvState_vel_x(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_current_station
{
public:
  explicit Init_VirtAgvState_current_station(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_last_station current_station(::com_interfaces::msg::VirtAgvState::_current_station_type arg)
  {
    msg_.current_station = std::move(arg);
    return Init_VirtAgvState_last_station(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_confidence
{
public:
  explicit Init_VirtAgvState_confidence(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_current_station confidence(::com_interfaces::msg::VirtAgvState::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_VirtAgvState_current_station(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_angle
{
public:
  explicit Init_VirtAgvState_angle(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_confidence angle(::com_interfaces::msg::VirtAgvState::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_VirtAgvState_confidence(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_pose_y
{
public:
  explicit Init_VirtAgvState_pose_y(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_angle pose_y(::com_interfaces::msg::VirtAgvState::_pose_y_type arg)
  {
    msg_.pose_y = std::move(arg);
    return Init_VirtAgvState_angle(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_pose_x
{
public:
  explicit Init_VirtAgvState_pose_x(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_pose_y pose_x(::com_interfaces::msg::VirtAgvState::_pose_x_type arg)
  {
    msg_.pose_x = std::move(arg);
    return Init_VirtAgvState_pose_y(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_err_msg
{
public:
  explicit Init_VirtAgvState_err_msg(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_pose_x err_msg(::com_interfaces::msg::VirtAgvState::_err_msg_type arg)
  {
    msg_.err_msg = std::move(arg);
    return Init_VirtAgvState_pose_x(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_err_code
{
public:
  explicit Init_VirtAgvState_err_code(::com_interfaces::msg::VirtAgvState & msg)
  : msg_(msg)
  {}
  Init_VirtAgvState_err_msg err_code(::com_interfaces::msg::VirtAgvState::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_VirtAgvState_err_msg(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

class Init_VirtAgvState_name
{
public:
  Init_VirtAgvState_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VirtAgvState_err_code name(::com_interfaces::msg::VirtAgvState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_VirtAgvState_err_code(msg_);
  }

private:
  ::com_interfaces::msg::VirtAgvState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::VirtAgvState>()
{
  return com_interfaces::msg::builder::Init_VirtAgvState_name();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__VIRT_AGV_STATE__BUILDER_HPP_
