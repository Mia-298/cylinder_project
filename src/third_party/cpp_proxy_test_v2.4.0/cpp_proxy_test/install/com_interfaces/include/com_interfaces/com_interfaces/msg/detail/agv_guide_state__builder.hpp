// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/AgvGuideState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/agv_guide_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_AgvGuideState_target_station
{
public:
  explicit Init_AgvGuideState_target_station(::com_interfaces::msg::AgvGuideState & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::AgvGuideState target_station(::com_interfaces::msg::AgvGuideState::_target_station_type arg)
  {
    msg_.target_station = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::AgvGuideState msg_;
};

class Init_AgvGuideState_task_type
{
public:
  explicit Init_AgvGuideState_task_type(::com_interfaces::msg::AgvGuideState & msg)
  : msg_(msg)
  {}
  Init_AgvGuideState_target_station task_type(::com_interfaces::msg::AgvGuideState::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_AgvGuideState_target_station(msg_);
  }

private:
  ::com_interfaces::msg::AgvGuideState msg_;
};

class Init_AgvGuideState_task_status
{
public:
  Init_AgvGuideState_task_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AgvGuideState_task_type task_status(::com_interfaces::msg::AgvGuideState::_task_status_type arg)
  {
    msg_.task_status = std::move(arg);
    return Init_AgvGuideState_task_type(msg_);
  }

private:
  ::com_interfaces::msg::AgvGuideState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::AgvGuideState>()
{
  return com_interfaces::msg::builder::Init_AgvGuideState_task_status();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__BUILDER_HPP_
