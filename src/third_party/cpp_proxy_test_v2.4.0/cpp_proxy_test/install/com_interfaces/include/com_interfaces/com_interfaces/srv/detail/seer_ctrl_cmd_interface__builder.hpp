// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:srv/SeerCtrlCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__BUILDER_HPP_
#define COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/srv/detail/seer_ctrl_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_SeerCtrlCmdInterface_Request_nick_name
{
public:
  explicit Init_SeerCtrlCmdInterface_Request_nick_name(::com_interfaces::srv::SeerCtrlCmdInterface_Request & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::SeerCtrlCmdInterface_Request nick_name(::com_interfaces::srv::SeerCtrlCmdInterface_Request::_nick_name_type arg)
  {
    msg_.nick_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Request msg_;
};

class Init_SeerCtrlCmdInterface_Request_manual_duration
{
public:
  explicit Init_SeerCtrlCmdInterface_Request_manual_duration(::com_interfaces::srv::SeerCtrlCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Request_nick_name manual_duration(::com_interfaces::srv::SeerCtrlCmdInterface_Request::_manual_duration_type arg)
  {
    msg_.manual_duration = std::move(arg);
    return Init_SeerCtrlCmdInterface_Request_nick_name(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Request msg_;
};

class Init_SeerCtrlCmdInterface_Request_manual_w
{
public:
  explicit Init_SeerCtrlCmdInterface_Request_manual_w(::com_interfaces::srv::SeerCtrlCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Request_manual_duration manual_w(::com_interfaces::srv::SeerCtrlCmdInterface_Request::_manual_w_type arg)
  {
    msg_.manual_w = std::move(arg);
    return Init_SeerCtrlCmdInterface_Request_manual_duration(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Request msg_;
};

class Init_SeerCtrlCmdInterface_Request_manual_y
{
public:
  explicit Init_SeerCtrlCmdInterface_Request_manual_y(::com_interfaces::srv::SeerCtrlCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Request_manual_w manual_y(::com_interfaces::srv::SeerCtrlCmdInterface_Request::_manual_y_type arg)
  {
    msg_.manual_y = std::move(arg);
    return Init_SeerCtrlCmdInterface_Request_manual_w(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Request msg_;
};

class Init_SeerCtrlCmdInterface_Request_manual_x
{
public:
  explicit Init_SeerCtrlCmdInterface_Request_manual_x(::com_interfaces::srv::SeerCtrlCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Request_manual_y manual_x(::com_interfaces::srv::SeerCtrlCmdInterface_Request::_manual_x_type arg)
  {
    msg_.manual_x = std::move(arg);
    return Init_SeerCtrlCmdInterface_Request_manual_y(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Request msg_;
};

class Init_SeerCtrlCmdInterface_Request_station_list
{
public:
  explicit Init_SeerCtrlCmdInterface_Request_station_list(::com_interfaces::srv::SeerCtrlCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Request_manual_x station_list(::com_interfaces::srv::SeerCtrlCmdInterface_Request::_station_list_type arg)
  {
    msg_.station_list = std::move(arg);
    return Init_SeerCtrlCmdInterface_Request_manual_x(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Request msg_;
};

class Init_SeerCtrlCmdInterface_Request_station
{
public:
  explicit Init_SeerCtrlCmdInterface_Request_station(::com_interfaces::srv::SeerCtrlCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Request_station_list station(::com_interfaces::srv::SeerCtrlCmdInterface_Request::_station_type arg)
  {
    msg_.station = std::move(arg);
    return Init_SeerCtrlCmdInterface_Request_station_list(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Request msg_;
};

class Init_SeerCtrlCmdInterface_Request_id
{
public:
  Init_SeerCtrlCmdInterface_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SeerCtrlCmdInterface_Request_station id(::com_interfaces::srv::SeerCtrlCmdInterface_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SeerCtrlCmdInterface_Request_station(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::SeerCtrlCmdInterface_Request>()
{
  return com_interfaces::srv::builder::Init_SeerCtrlCmdInterface_Request_id();
}

}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_SeerCtrlCmdInterface_Response_station_list
{
public:
  explicit Init_SeerCtrlCmdInterface_Response_station_list(::com_interfaces::srv::SeerCtrlCmdInterface_Response & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::SeerCtrlCmdInterface_Response station_list(::com_interfaces::srv::SeerCtrlCmdInterface_Response::_station_list_type arg)
  {
    msg_.station_list = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Response msg_;
};

class Init_SeerCtrlCmdInterface_Response_current_station
{
public:
  explicit Init_SeerCtrlCmdInterface_Response_current_station(::com_interfaces::srv::SeerCtrlCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Response_station_list current_station(::com_interfaces::srv::SeerCtrlCmdInterface_Response::_current_station_type arg)
  {
    msg_.current_station = std::move(arg);
    return Init_SeerCtrlCmdInterface_Response_station_list(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Response msg_;
};

class Init_SeerCtrlCmdInterface_Response_loc
{
public:
  explicit Init_SeerCtrlCmdInterface_Response_loc(::com_interfaces::srv::SeerCtrlCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Response_current_station loc(::com_interfaces::srv::SeerCtrlCmdInterface_Response::_loc_type arg)
  {
    msg_.loc = std::move(arg);
    return Init_SeerCtrlCmdInterface_Response_current_station(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Response msg_;
};

class Init_SeerCtrlCmdInterface_Response_control
{
public:
  explicit Init_SeerCtrlCmdInterface_Response_control(::com_interfaces::srv::SeerCtrlCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Response_loc control(::com_interfaces::srv::SeerCtrlCmdInterface_Response::_control_type arg)
  {
    msg_.control = std::move(arg);
    return Init_SeerCtrlCmdInterface_Response_loc(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Response msg_;
};

class Init_SeerCtrlCmdInterface_Response_guide_state
{
public:
  explicit Init_SeerCtrlCmdInterface_Response_guide_state(::com_interfaces::srv::SeerCtrlCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Response_control guide_state(::com_interfaces::srv::SeerCtrlCmdInterface_Response::_guide_state_type arg)
  {
    msg_.guide_state = std::move(arg);
    return Init_SeerCtrlCmdInterface_Response_control(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Response msg_;
};

class Init_SeerCtrlCmdInterface_Response_msg
{
public:
  explicit Init_SeerCtrlCmdInterface_Response_msg(::com_interfaces::srv::SeerCtrlCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlCmdInterface_Response_guide_state msg(::com_interfaces::srv::SeerCtrlCmdInterface_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return Init_SeerCtrlCmdInterface_Response_guide_state(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Response msg_;
};

class Init_SeerCtrlCmdInterface_Response_err_code
{
public:
  Init_SeerCtrlCmdInterface_Response_err_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SeerCtrlCmdInterface_Response_msg err_code(::com_interfaces::srv::SeerCtrlCmdInterface_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_SeerCtrlCmdInterface_Response_msg(msg_);
  }

private:
  ::com_interfaces::srv::SeerCtrlCmdInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::SeerCtrlCmdInterface_Response>()
{
  return com_interfaces::srv::builder::Init_SeerCtrlCmdInterface_Response_err_code();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__BUILDER_HPP_
