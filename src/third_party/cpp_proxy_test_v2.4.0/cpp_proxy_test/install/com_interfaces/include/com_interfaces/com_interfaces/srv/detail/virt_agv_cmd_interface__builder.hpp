// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:srv/VirtAgvCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__VIRT_AGV_CMD_INTERFACE__BUILDER_HPP_
#define COM_INTERFACES__SRV__DETAIL__VIRT_AGV_CMD_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_VirtAgvCmdInterface_Request_manual_duration
{
public:
  explicit Init_VirtAgvCmdInterface_Request_manual_duration(::com_interfaces::srv::VirtAgvCmdInterface_Request & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::VirtAgvCmdInterface_Request manual_duration(::com_interfaces::srv::VirtAgvCmdInterface_Request::_manual_duration_type arg)
  {
    msg_.manual_duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Request msg_;
};

class Init_VirtAgvCmdInterface_Request_manual_w
{
public:
  explicit Init_VirtAgvCmdInterface_Request_manual_w(::com_interfaces::srv::VirtAgvCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Request_manual_duration manual_w(::com_interfaces::srv::VirtAgvCmdInterface_Request::_manual_w_type arg)
  {
    msg_.manual_w = std::move(arg);
    return Init_VirtAgvCmdInterface_Request_manual_duration(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Request msg_;
};

class Init_VirtAgvCmdInterface_Request_manual_y
{
public:
  explicit Init_VirtAgvCmdInterface_Request_manual_y(::com_interfaces::srv::VirtAgvCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Request_manual_w manual_y(::com_interfaces::srv::VirtAgvCmdInterface_Request::_manual_y_type arg)
  {
    msg_.manual_y = std::move(arg);
    return Init_VirtAgvCmdInterface_Request_manual_w(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Request msg_;
};

class Init_VirtAgvCmdInterface_Request_manual_x
{
public:
  explicit Init_VirtAgvCmdInterface_Request_manual_x(::com_interfaces::srv::VirtAgvCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Request_manual_y manual_x(::com_interfaces::srv::VirtAgvCmdInterface_Request::_manual_x_type arg)
  {
    msg_.manual_x = std::move(arg);
    return Init_VirtAgvCmdInterface_Request_manual_y(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Request msg_;
};

class Init_VirtAgvCmdInterface_Request_station_list
{
public:
  explicit Init_VirtAgvCmdInterface_Request_station_list(::com_interfaces::srv::VirtAgvCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Request_manual_x station_list(::com_interfaces::srv::VirtAgvCmdInterface_Request::_station_list_type arg)
  {
    msg_.station_list = std::move(arg);
    return Init_VirtAgvCmdInterface_Request_manual_x(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Request msg_;
};

class Init_VirtAgvCmdInterface_Request_station
{
public:
  explicit Init_VirtAgvCmdInterface_Request_station(::com_interfaces::srv::VirtAgvCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Request_station_list station(::com_interfaces::srv::VirtAgvCmdInterface_Request::_station_type arg)
  {
    msg_.station = std::move(arg);
    return Init_VirtAgvCmdInterface_Request_station_list(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Request msg_;
};

class Init_VirtAgvCmdInterface_Request_id
{
public:
  Init_VirtAgvCmdInterface_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VirtAgvCmdInterface_Request_station id(::com_interfaces::srv::VirtAgvCmdInterface_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_VirtAgvCmdInterface_Request_station(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::VirtAgvCmdInterface_Request>()
{
  return com_interfaces::srv::builder::Init_VirtAgvCmdInterface_Request_id();
}

}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_VirtAgvCmdInterface_Response_station_list
{
public:
  explicit Init_VirtAgvCmdInterface_Response_station_list(::com_interfaces::srv::VirtAgvCmdInterface_Response & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::VirtAgvCmdInterface_Response station_list(::com_interfaces::srv::VirtAgvCmdInterface_Response::_station_list_type arg)
  {
    msg_.station_list = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Response msg_;
};

class Init_VirtAgvCmdInterface_Response_current_station
{
public:
  explicit Init_VirtAgvCmdInterface_Response_current_station(::com_interfaces::srv::VirtAgvCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Response_station_list current_station(::com_interfaces::srv::VirtAgvCmdInterface_Response::_current_station_type arg)
  {
    msg_.current_station = std::move(arg);
    return Init_VirtAgvCmdInterface_Response_station_list(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Response msg_;
};

class Init_VirtAgvCmdInterface_Response_target_station
{
public:
  explicit Init_VirtAgvCmdInterface_Response_target_station(::com_interfaces::srv::VirtAgvCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Response_current_station target_station(::com_interfaces::srv::VirtAgvCmdInterface_Response::_target_station_type arg)
  {
    msg_.target_station = std::move(arg);
    return Init_VirtAgvCmdInterface_Response_current_station(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Response msg_;
};

class Init_VirtAgvCmdInterface_Response_task_type
{
public:
  explicit Init_VirtAgvCmdInterface_Response_task_type(::com_interfaces::srv::VirtAgvCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Response_target_station task_type(::com_interfaces::srv::VirtAgvCmdInterface_Response::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_VirtAgvCmdInterface_Response_target_station(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Response msg_;
};

class Init_VirtAgvCmdInterface_Response_task_status
{
public:
  explicit Init_VirtAgvCmdInterface_Response_task_status(::com_interfaces::srv::VirtAgvCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Response_task_type task_status(::com_interfaces::srv::VirtAgvCmdInterface_Response::_task_status_type arg)
  {
    msg_.task_status = std::move(arg);
    return Init_VirtAgvCmdInterface_Response_task_type(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Response msg_;
};

class Init_VirtAgvCmdInterface_Response_msg
{
public:
  explicit Init_VirtAgvCmdInterface_Response_msg(::com_interfaces::srv::VirtAgvCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_VirtAgvCmdInterface_Response_task_status msg(::com_interfaces::srv::VirtAgvCmdInterface_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return Init_VirtAgvCmdInterface_Response_task_status(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Response msg_;
};

class Init_VirtAgvCmdInterface_Response_err_code
{
public:
  Init_VirtAgvCmdInterface_Response_err_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VirtAgvCmdInterface_Response_msg err_code(::com_interfaces::srv::VirtAgvCmdInterface_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_VirtAgvCmdInterface_Response_msg(msg_);
  }

private:
  ::com_interfaces::srv::VirtAgvCmdInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::VirtAgvCmdInterface_Response>()
{
  return com_interfaces::srv::builder::Init_VirtAgvCmdInterface_Response_err_code();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__VIRT_AGV_CMD_INTERFACE__BUILDER_HPP_
