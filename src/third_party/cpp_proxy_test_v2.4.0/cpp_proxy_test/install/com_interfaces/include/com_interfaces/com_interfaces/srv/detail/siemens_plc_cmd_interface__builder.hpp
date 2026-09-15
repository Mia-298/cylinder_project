// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:srv/SiemensPlcCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SIEMENS_PLC_CMD_INTERFACE__BUILDER_HPP_
#define COM_INTERFACES__SRV__DETAIL__SIEMENS_PLC_CMD_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/srv/detail/siemens_plc_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_SiemensPlcCmdInterface_Request_dpin_state
{
public:
  explicit Init_SiemensPlcCmdInterface_Request_dpin_state(::com_interfaces::srv::SiemensPlcCmdInterface_Request & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::SiemensPlcCmdInterface_Request dpin_state(::com_interfaces::srv::SiemensPlcCmdInterface_Request::_dpin_state_type arg)
  {
    msg_.dpin_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::SiemensPlcCmdInterface_Request msg_;
};

class Init_SiemensPlcCmdInterface_Request_pin
{
public:
  explicit Init_SiemensPlcCmdInterface_Request_pin(::com_interfaces::srv::SiemensPlcCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_SiemensPlcCmdInterface_Request_dpin_state pin(::com_interfaces::srv::SiemensPlcCmdInterface_Request::_pin_type arg)
  {
    msg_.pin = std::move(arg);
    return Init_SiemensPlcCmdInterface_Request_dpin_state(msg_);
  }

private:
  ::com_interfaces::srv::SiemensPlcCmdInterface_Request msg_;
};

class Init_SiemensPlcCmdInterface_Request_id
{
public:
  Init_SiemensPlcCmdInterface_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SiemensPlcCmdInterface_Request_pin id(::com_interfaces::srv::SiemensPlcCmdInterface_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SiemensPlcCmdInterface_Request_pin(msg_);
  }

private:
  ::com_interfaces::srv::SiemensPlcCmdInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::SiemensPlcCmdInterface_Request>()
{
  return com_interfaces::srv::builder::Init_SiemensPlcCmdInterface_Request_id();
}

}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_SiemensPlcCmdInterface_Response_msg
{
public:
  explicit Init_SiemensPlcCmdInterface_Response_msg(::com_interfaces::srv::SiemensPlcCmdInterface_Response & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::SiemensPlcCmdInterface_Response msg(::com_interfaces::srv::SiemensPlcCmdInterface_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::SiemensPlcCmdInterface_Response msg_;
};

class Init_SiemensPlcCmdInterface_Response_err_code
{
public:
  explicit Init_SiemensPlcCmdInterface_Response_err_code(::com_interfaces::srv::SiemensPlcCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_SiemensPlcCmdInterface_Response_msg err_code(::com_interfaces::srv::SiemensPlcCmdInterface_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_SiemensPlcCmdInterface_Response_msg(msg_);
  }

private:
  ::com_interfaces::srv::SiemensPlcCmdInterface_Response msg_;
};

class Init_SiemensPlcCmdInterface_Response_dpin_state
{
public:
  Init_SiemensPlcCmdInterface_Response_dpin_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SiemensPlcCmdInterface_Response_err_code dpin_state(::com_interfaces::srv::SiemensPlcCmdInterface_Response::_dpin_state_type arg)
  {
    msg_.dpin_state = std::move(arg);
    return Init_SiemensPlcCmdInterface_Response_err_code(msg_);
  }

private:
  ::com_interfaces::srv::SiemensPlcCmdInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::SiemensPlcCmdInterface_Response>()
{
  return com_interfaces::srv::builder::Init_SiemensPlcCmdInterface_Response_dpin_state();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__SIEMENS_PLC_CMD_INTERFACE__BUILDER_HPP_
