// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/ForcePayload.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/force_payload__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_ForcePayload_z
{
public:
  explicit Init_ForcePayload_z(::com_interfaces::msg::ForcePayload & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::ForcePayload z(::com_interfaces::msg::ForcePayload::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::ForcePayload msg_;
};

class Init_ForcePayload_y
{
public:
  explicit Init_ForcePayload_y(::com_interfaces::msg::ForcePayload & msg)
  : msg_(msg)
  {}
  Init_ForcePayload_z y(::com_interfaces::msg::ForcePayload::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ForcePayload_z(msg_);
  }

private:
  ::com_interfaces::msg::ForcePayload msg_;
};

class Init_ForcePayload_x
{
public:
  explicit Init_ForcePayload_x(::com_interfaces::msg::ForcePayload & msg)
  : msg_(msg)
  {}
  Init_ForcePayload_y x(::com_interfaces::msg::ForcePayload::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ForcePayload_y(msg_);
  }

private:
  ::com_interfaces::msg::ForcePayload msg_;
};

class Init_ForcePayload_weight
{
public:
  Init_ForcePayload_weight()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForcePayload_x weight(::com_interfaces::msg::ForcePayload::_weight_type arg)
  {
    msg_.weight = std::move(arg);
    return Init_ForcePayload_x(msg_);
  }

private:
  ::com_interfaces::msg::ForcePayload msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::ForcePayload>()
{
  return com_interfaces::msg::builder::Init_ForcePayload_weight();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__BUILDER_HPP_
