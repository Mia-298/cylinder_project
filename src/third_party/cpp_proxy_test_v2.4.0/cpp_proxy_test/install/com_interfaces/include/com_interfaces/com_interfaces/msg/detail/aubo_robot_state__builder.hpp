// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/AuboRobotState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AUBO_ROBOT_STATE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__AUBO_ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/aubo_robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_AuboRobotState_tl_cur_pos
{
public:
  explicit Init_AuboRobotState_tl_cur_pos(::com_interfaces::msg::AuboRobotState & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::AuboRobotState tl_cur_pos(::com_interfaces::msg::AuboRobotState::_tl_cur_pos_type arg)
  {
    msg_.tl_cur_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

class Init_AuboRobotState_jt_cur_pos
{
public:
  explicit Init_AuboRobotState_jt_cur_pos(::com_interfaces::msg::AuboRobotState & msg)
  : msg_(msg)
  {}
  Init_AuboRobotState_tl_cur_pos jt_cur_pos(::com_interfaces::msg::AuboRobotState::_jt_cur_pos_type arg)
  {
    msg_.jt_cur_pos = std::move(arg);
    return Init_AuboRobotState_tl_cur_pos(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

class Init_AuboRobotState_robot_speed
{
public:
  explicit Init_AuboRobotState_robot_speed(::com_interfaces::msg::AuboRobotState & msg)
  : msg_(msg)
  {}
  Init_AuboRobotState_jt_cur_pos robot_speed(::com_interfaces::msg::AuboRobotState::_robot_speed_type arg)
  {
    msg_.robot_speed = std::move(arg);
    return Init_AuboRobotState_jt_cur_pos(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

class Init_AuboRobotState_safety_mode_type
{
public:
  explicit Init_AuboRobotState_safety_mode_type(::com_interfaces::msg::AuboRobotState & msg)
  : msg_(msg)
  {}
  Init_AuboRobotState_robot_speed safety_mode_type(::com_interfaces::msg::AuboRobotState::_safety_mode_type_type arg)
  {
    msg_.safety_mode_type = std::move(arg);
    return Init_AuboRobotState_robot_speed(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

class Init_AuboRobotState_mode_type
{
public:
  explicit Init_AuboRobotState_mode_type(::com_interfaces::msg::AuboRobotState & msg)
  : msg_(msg)
  {}
  Init_AuboRobotState_safety_mode_type mode_type(::com_interfaces::msg::AuboRobotState::_mode_type_type arg)
  {
    msg_.mode_type = std::move(arg);
    return Init_AuboRobotState_safety_mode_type(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

class Init_AuboRobotState_robot_ip
{
public:
  explicit Init_AuboRobotState_robot_ip(::com_interfaces::msg::AuboRobotState & msg)
  : msg_(msg)
  {}
  Init_AuboRobotState_mode_type robot_ip(::com_interfaces::msg::AuboRobotState::_robot_ip_type arg)
  {
    msg_.robot_ip = std::move(arg);
    return Init_AuboRobotState_mode_type(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

class Init_AuboRobotState_robot_soft_index
{
public:
  explicit Init_AuboRobotState_robot_soft_index(::com_interfaces::msg::AuboRobotState & msg)
  : msg_(msg)
  {}
  Init_AuboRobotState_robot_ip robot_soft_index(::com_interfaces::msg::AuboRobotState::_robot_soft_index_type arg)
  {
    msg_.robot_soft_index = std::move(arg);
    return Init_AuboRobotState_robot_ip(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

class Init_AuboRobotState_robot_type
{
public:
  explicit Init_AuboRobotState_robot_type(::com_interfaces::msg::AuboRobotState & msg)
  : msg_(msg)
  {}
  Init_AuboRobotState_robot_soft_index robot_type(::com_interfaces::msg::AuboRobotState::_robot_type_type arg)
  {
    msg_.robot_type = std::move(arg);
    return Init_AuboRobotState_robot_soft_index(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

class Init_AuboRobotState_robot_name
{
public:
  explicit Init_AuboRobotState_robot_name(::com_interfaces::msg::AuboRobotState & msg)
  : msg_(msg)
  {}
  Init_AuboRobotState_robot_type robot_name(::com_interfaces::msg::AuboRobotState::_robot_name_type arg)
  {
    msg_.robot_name = std::move(arg);
    return Init_AuboRobotState_robot_type(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

class Init_AuboRobotState_robot_index
{
public:
  Init_AuboRobotState_robot_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AuboRobotState_robot_name robot_index(::com_interfaces::msg::AuboRobotState::_robot_index_type arg)
  {
    msg_.robot_index = std::move(arg);
    return Init_AuboRobotState_robot_name(msg_);
  }

private:
  ::com_interfaces::msg::AuboRobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::AuboRobotState>()
{
  return com_interfaces::msg::builder::Init_AuboRobotState_robot_index();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AUBO_ROBOT_STATE__BUILDER_HPP_
