// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/AgvOrderState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/agv_order_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_AgvOrderState_execution_reject
{
public:
  explicit Init_AgvOrderState_execution_reject(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::AgvOrderState execution_reject(::com_interfaces::msg::AgvOrderState::_execution_reject_type arg)
  {
    msg_.execution_reject = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_fault_reason
{
public:
  explicit Init_AgvOrderState_fault_reason(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_execution_reject fault_reason(::com_interfaces::msg::AgvOrderState::_fault_reason_type arg)
  {
    msg_.fault_reason = std::move(arg);
    return Init_AgvOrderState_execution_reject(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_fault
{
public:
  explicit Init_AgvOrderState_fault(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_fault_reason fault(::com_interfaces::msg::AgvOrderState::_fault_type arg)
  {
    msg_.fault = std::move(arg);
    return Init_AgvOrderState_fault_reason(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_unloaded
{
public:
  explicit Init_AgvOrderState_unloaded(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_fault unloaded(::com_interfaces::msg::AgvOrderState::_unloaded_type arg)
  {
    msg_.unloaded = std::move(arg);
    return Init_AgvOrderState_fault(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_loaded
{
public:
  explicit Init_AgvOrderState_loaded(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_unloaded loaded(::com_interfaces::msg::AgvOrderState::_loaded_type arg)
  {
    msg_.loaded = std::move(arg);
    return Init_AgvOrderState_unloaded(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_container_id
{
public:
  explicit Init_AgvOrderState_container_id(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_loaded container_id(::com_interfaces::msg::AgvOrderState::_container_id_type arg)
  {
    msg_.container_id = std::move(arg);
    return Init_AgvOrderState_loaded(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_step_locations
{
public:
  explicit Init_AgvOrderState_step_locations(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_container_id step_locations(::com_interfaces::msg::AgvOrderState::_step_locations_type arg)
  {
    msg_.step_locations = std::move(arg);
    return Init_AgvOrderState_container_id(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_step_num
{
public:
  explicit Init_AgvOrderState_step_num(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_step_locations step_num(::com_interfaces::msg::AgvOrderState::_step_num_type arg)
  {
    msg_.step_num = std::move(arg);
    return Init_AgvOrderState_step_locations(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_done_step_index
{
public:
  explicit Init_AgvOrderState_done_step_index(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_step_num done_step_index(::com_interfaces::msg::AgvOrderState::_done_step_index_type arg)
  {
    msg_.done_step_index = std::move(arg);
    return Init_AgvOrderState_step_num(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_current_step_index
{
public:
  explicit Init_AgvOrderState_current_step_index(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_done_step_index current_step_index(::com_interfaces::msg::AgvOrderState::_current_step_index_type arg)
  {
    msg_.current_step_index = std::move(arg);
    return Init_AgvOrderState_done_step_index(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_actual_robot_name
{
public:
  explicit Init_AgvOrderState_actual_robot_name(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_current_step_index actual_robot_name(::com_interfaces::msg::AgvOrderState::_actual_robot_name_type arg)
  {
    msg_.actual_robot_name = std::move(arg);
    return Init_AgvOrderState_current_step_index(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_status
{
public:
  explicit Init_AgvOrderState_status(::com_interfaces::msg::AgvOrderState & msg)
  : msg_(msg)
  {}
  Init_AgvOrderState_actual_robot_name status(::com_interfaces::msg::AgvOrderState::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_AgvOrderState_actual_robot_name(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

class Init_AgvOrderState_id
{
public:
  Init_AgvOrderState_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AgvOrderState_status id(::com_interfaces::msg::AgvOrderState::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_AgvOrderState_status(msg_);
  }

private:
  ::com_interfaces::msg::AgvOrderState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::AgvOrderState>()
{
  return com_interfaces::msg::builder::Init_AgvOrderState_id();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__BUILDER_HPP_
