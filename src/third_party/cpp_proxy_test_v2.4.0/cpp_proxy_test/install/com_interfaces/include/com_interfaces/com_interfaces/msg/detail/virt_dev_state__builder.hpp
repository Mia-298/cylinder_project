// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/VirtDevState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__VIRT_DEV_STATE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__VIRT_DEV_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/virt_dev_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_VirtDevState_err_msg
{
public:
  explicit Init_VirtDevState_err_msg(::com_interfaces::msg::VirtDevState & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::VirtDevState err_msg(::com_interfaces::msg::VirtDevState::_err_msg_type arg)
  {
    msg_.err_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::VirtDevState msg_;
};

class Init_VirtDevState_err_code
{
public:
  explicit Init_VirtDevState_err_code(::com_interfaces::msg::VirtDevState & msg)
  : msg_(msg)
  {}
  Init_VirtDevState_err_msg err_code(::com_interfaces::msg::VirtDevState::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_VirtDevState_err_msg(msg_);
  }

private:
  ::com_interfaces::msg::VirtDevState msg_;
};

class Init_VirtDevState_name
{
public:
  Init_VirtDevState_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VirtDevState_err_code name(::com_interfaces::msg::VirtDevState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_VirtDevState_err_code(msg_);
  }

private:
  ::com_interfaces::msg::VirtDevState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::VirtDevState>()
{
  return com_interfaces::msg::builder::Init_VirtDevState_name();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__VIRT_DEV_STATE__BUILDER_HPP_
