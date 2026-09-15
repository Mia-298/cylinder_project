// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/JointPoint.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__JOINT_POINT__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__JOINT_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/joint_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_JointPoint_joint_point
{
public:
  Init_JointPoint_joint_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::com_interfaces::msg::JointPoint joint_point(::com_interfaces::msg::JointPoint::_joint_point_type arg)
  {
    msg_.joint_point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::JointPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::JointPoint>()
{
  return com_interfaces::msg::builder::Init_JointPoint_joint_point();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__JOINT_POINT__BUILDER_HPP_
