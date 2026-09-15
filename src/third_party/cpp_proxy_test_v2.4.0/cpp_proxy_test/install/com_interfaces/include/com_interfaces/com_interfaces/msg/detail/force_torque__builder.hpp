// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/ForceTorque.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/force_torque__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_ForceTorque_tz
{
public:
  explicit Init_ForceTorque_tz(::com_interfaces::msg::ForceTorque & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::ForceTorque tz(::com_interfaces::msg::ForceTorque::_tz_type arg)
  {
    msg_.tz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::ForceTorque msg_;
};

class Init_ForceTorque_ty
{
public:
  explicit Init_ForceTorque_ty(::com_interfaces::msg::ForceTorque & msg)
  : msg_(msg)
  {}
  Init_ForceTorque_tz ty(::com_interfaces::msg::ForceTorque::_ty_type arg)
  {
    msg_.ty = std::move(arg);
    return Init_ForceTorque_tz(msg_);
  }

private:
  ::com_interfaces::msg::ForceTorque msg_;
};

class Init_ForceTorque_tx
{
public:
  explicit Init_ForceTorque_tx(::com_interfaces::msg::ForceTorque & msg)
  : msg_(msg)
  {}
  Init_ForceTorque_ty tx(::com_interfaces::msg::ForceTorque::_tx_type arg)
  {
    msg_.tx = std::move(arg);
    return Init_ForceTorque_ty(msg_);
  }

private:
  ::com_interfaces::msg::ForceTorque msg_;
};

class Init_ForceTorque_fz
{
public:
  explicit Init_ForceTorque_fz(::com_interfaces::msg::ForceTorque & msg)
  : msg_(msg)
  {}
  Init_ForceTorque_tx fz(::com_interfaces::msg::ForceTorque::_fz_type arg)
  {
    msg_.fz = std::move(arg);
    return Init_ForceTorque_tx(msg_);
  }

private:
  ::com_interfaces::msg::ForceTorque msg_;
};

class Init_ForceTorque_fy
{
public:
  explicit Init_ForceTorque_fy(::com_interfaces::msg::ForceTorque & msg)
  : msg_(msg)
  {}
  Init_ForceTorque_fz fy(::com_interfaces::msg::ForceTorque::_fy_type arg)
  {
    msg_.fy = std::move(arg);
    return Init_ForceTorque_fz(msg_);
  }

private:
  ::com_interfaces::msg::ForceTorque msg_;
};

class Init_ForceTorque_fx
{
public:
  Init_ForceTorque_fx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ForceTorque_fy fx(::com_interfaces::msg::ForceTorque::_fx_type arg)
  {
    msg_.fx = std::move(arg);
    return Init_ForceTorque_fy(msg_);
  }

private:
  ::com_interfaces::msg::ForceTorque msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::ForceTorque>()
{
  return com_interfaces::msg::builder::Init_ForceTorque_fx();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__BUILDER_HPP_
