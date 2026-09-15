// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:srv/SeerM4CmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SEER_M4_CMD_INTERFACE__BUILDER_HPP_
#define COM_INTERFACES__SRV__DETAIL__SEER_M4_CMD_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/srv/detail/seer_m4_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_SeerM4CmdInterface_Request_order_id
{
public:
  explicit Init_SeerM4CmdInterface_Request_order_id(::com_interfaces::srv::SeerM4CmdInterface_Request & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::SeerM4CmdInterface_Request order_id(::com_interfaces::srv::SeerM4CmdInterface_Request::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::SeerM4CmdInterface_Request msg_;
};

class Init_SeerM4CmdInterface_Request_container_id
{
public:
  explicit Init_SeerM4CmdInterface_Request_container_id(::com_interfaces::srv::SeerM4CmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_SeerM4CmdInterface_Request_order_id container_id(::com_interfaces::srv::SeerM4CmdInterface_Request::_container_id_type arg)
  {
    msg_.container_id = std::move(arg);
    return Init_SeerM4CmdInterface_Request_order_id(msg_);
  }

private:
  ::com_interfaces::srv::SeerM4CmdInterface_Request msg_;
};

class Init_SeerM4CmdInterface_Request_point
{
public:
  explicit Init_SeerM4CmdInterface_Request_point(::com_interfaces::srv::SeerM4CmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_SeerM4CmdInterface_Request_container_id point(::com_interfaces::srv::SeerM4CmdInterface_Request::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_SeerM4CmdInterface_Request_container_id(msg_);
  }

private:
  ::com_interfaces::srv::SeerM4CmdInterface_Request msg_;
};

class Init_SeerM4CmdInterface_Request_id
{
public:
  Init_SeerM4CmdInterface_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SeerM4CmdInterface_Request_point id(::com_interfaces::srv::SeerM4CmdInterface_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SeerM4CmdInterface_Request_point(msg_);
  }

private:
  ::com_interfaces::srv::SeerM4CmdInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::SeerM4CmdInterface_Request>()
{
  return com_interfaces::srv::builder::Init_SeerM4CmdInterface_Request_id();
}

}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_SeerM4CmdInterface_Response_order_state
{
public:
  explicit Init_SeerM4CmdInterface_Response_order_state(::com_interfaces::srv::SeerM4CmdInterface_Response & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::SeerM4CmdInterface_Response order_state(::com_interfaces::srv::SeerM4CmdInterface_Response::_order_state_type arg)
  {
    msg_.order_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::SeerM4CmdInterface_Response msg_;
};

class Init_SeerM4CmdInterface_Response_order_id
{
public:
  explicit Init_SeerM4CmdInterface_Response_order_id(::com_interfaces::srv::SeerM4CmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_SeerM4CmdInterface_Response_order_state order_id(::com_interfaces::srv::SeerM4CmdInterface_Response::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return Init_SeerM4CmdInterface_Response_order_state(msg_);
  }

private:
  ::com_interfaces::srv::SeerM4CmdInterface_Response msg_;
};

class Init_SeerM4CmdInterface_Response_msg
{
public:
  explicit Init_SeerM4CmdInterface_Response_msg(::com_interfaces::srv::SeerM4CmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_SeerM4CmdInterface_Response_order_id msg(::com_interfaces::srv::SeerM4CmdInterface_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return Init_SeerM4CmdInterface_Response_order_id(msg_);
  }

private:
  ::com_interfaces::srv::SeerM4CmdInterface_Response msg_;
};

class Init_SeerM4CmdInterface_Response_err_code
{
public:
  Init_SeerM4CmdInterface_Response_err_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SeerM4CmdInterface_Response_msg err_code(::com_interfaces::srv::SeerM4CmdInterface_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_SeerM4CmdInterface_Response_msg(msg_);
  }

private:
  ::com_interfaces::srv::SeerM4CmdInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::SeerM4CmdInterface_Response>()
{
  return com_interfaces::srv::builder::Init_SeerM4CmdInterface_Response_err_code();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__SEER_M4_CMD_INTERFACE__BUILDER_HPP_
