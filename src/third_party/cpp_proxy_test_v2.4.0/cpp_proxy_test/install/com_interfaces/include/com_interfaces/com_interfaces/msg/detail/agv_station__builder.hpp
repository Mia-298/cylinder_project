// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/AgvStation.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_STATION__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_STATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/agv_station__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_AgvStation_name
{
public:
  Init_AgvStation_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::com_interfaces::msg::AgvStation name(::com_interfaces::msg::AgvStation::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::AgvStation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::AgvStation>()
{
  return com_interfaces::msg::builder::Init_AgvStation_name();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_STATION__BUILDER_HPP_
