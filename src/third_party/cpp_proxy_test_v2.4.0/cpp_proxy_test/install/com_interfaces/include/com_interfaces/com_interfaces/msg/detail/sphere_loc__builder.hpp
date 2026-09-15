// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/SphereLoc.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__SPHERE_LOC__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__SPHERE_LOC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/sphere_loc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_SphereLoc_z
{
public:
  explicit Init_SphereLoc_z(::com_interfaces::msg::SphereLoc & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::SphereLoc z(::com_interfaces::msg::SphereLoc::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::SphereLoc msg_;
};

class Init_SphereLoc_y
{
public:
  explicit Init_SphereLoc_y(::com_interfaces::msg::SphereLoc & msg)
  : msg_(msg)
  {}
  Init_SphereLoc_z y(::com_interfaces::msg::SphereLoc::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SphereLoc_z(msg_);
  }

private:
  ::com_interfaces::msg::SphereLoc msg_;
};

class Init_SphereLoc_x
{
public:
  Init_SphereLoc_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SphereLoc_y x(::com_interfaces::msg::SphereLoc::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SphereLoc_y(msg_);
  }

private:
  ::com_interfaces::msg::SphereLoc msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::SphereLoc>()
{
  return com_interfaces::msg::builder::Init_SphereLoc_x();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__SPHERE_LOC__BUILDER_HPP_
