// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/RmCeuState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__RM_CEU_STATE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__RM_CEU_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/rm_ceu_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_RmCeuState_err_msg
{
public:
  explicit Init_RmCeuState_err_msg(::com_interfaces::msg::RmCeuState & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::RmCeuState err_msg(::com_interfaces::msg::RmCeuState::_err_msg_type arg)
  {
    msg_.err_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::RmCeuState msg_;
};

class Init_RmCeuState_err_code
{
public:
  explicit Init_RmCeuState_err_code(::com_interfaces::msg::RmCeuState & msg)
  : msg_(msg)
  {}
  Init_RmCeuState_err_msg err_code(::com_interfaces::msg::RmCeuState::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_RmCeuState_err_msg(msg_);
  }

private:
  ::com_interfaces::msg::RmCeuState msg_;
};

class Init_RmCeuState_name
{
public:
  Init_RmCeuState_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RmCeuState_err_code name(::com_interfaces::msg::RmCeuState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_RmCeuState_err_code(msg_);
  }

private:
  ::com_interfaces::msg::RmCeuState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::RmCeuState>()
{
  return com_interfaces::msg::builder::Init_RmCeuState_name();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__RM_CEU_STATE__BUILDER_HPP_
