// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/AgvLoc.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_LOC__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_LOC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/agv_loc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_AgvLoc_loc_method
{
public:
  explicit Init_AgvLoc_loc_method(::com_interfaces::msg::AgvLoc & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::AgvLoc loc_method(::com_interfaces::msg::AgvLoc::_loc_method_type arg)
  {
    msg_.loc_method = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::AgvLoc msg_;
};

class Init_AgvLoc_last_station
{
public:
  explicit Init_AgvLoc_last_station(::com_interfaces::msg::AgvLoc & msg)
  : msg_(msg)
  {}
  Init_AgvLoc_loc_method last_station(::com_interfaces::msg::AgvLoc::_last_station_type arg)
  {
    msg_.last_station = std::move(arg);
    return Init_AgvLoc_loc_method(msg_);
  }

private:
  ::com_interfaces::msg::AgvLoc msg_;
};

class Init_AgvLoc_current_station
{
public:
  explicit Init_AgvLoc_current_station(::com_interfaces::msg::AgvLoc & msg)
  : msg_(msg)
  {}
  Init_AgvLoc_last_station current_station(::com_interfaces::msg::AgvLoc::_current_station_type arg)
  {
    msg_.current_station = std::move(arg);
    return Init_AgvLoc_last_station(msg_);
  }

private:
  ::com_interfaces::msg::AgvLoc msg_;
};

class Init_AgvLoc_confidence
{
public:
  explicit Init_AgvLoc_confidence(::com_interfaces::msg::AgvLoc & msg)
  : msg_(msg)
  {}
  Init_AgvLoc_current_station confidence(::com_interfaces::msg::AgvLoc::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_AgvLoc_current_station(msg_);
  }

private:
  ::com_interfaces::msg::AgvLoc msg_;
};

class Init_AgvLoc_angle
{
public:
  explicit Init_AgvLoc_angle(::com_interfaces::msg::AgvLoc & msg)
  : msg_(msg)
  {}
  Init_AgvLoc_confidence angle(::com_interfaces::msg::AgvLoc::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_AgvLoc_confidence(msg_);
  }

private:
  ::com_interfaces::msg::AgvLoc msg_;
};

class Init_AgvLoc_y
{
public:
  explicit Init_AgvLoc_y(::com_interfaces::msg::AgvLoc & msg)
  : msg_(msg)
  {}
  Init_AgvLoc_angle y(::com_interfaces::msg::AgvLoc::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_AgvLoc_angle(msg_);
  }

private:
  ::com_interfaces::msg::AgvLoc msg_;
};

class Init_AgvLoc_x
{
public:
  Init_AgvLoc_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AgvLoc_y x(::com_interfaces::msg::AgvLoc::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_AgvLoc_y(msg_);
  }

private:
  ::com_interfaces::msg::AgvLoc msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::AgvLoc>()
{
  return com_interfaces::msg::builder::Init_AgvLoc_x();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_LOC__BUILDER_HPP_
