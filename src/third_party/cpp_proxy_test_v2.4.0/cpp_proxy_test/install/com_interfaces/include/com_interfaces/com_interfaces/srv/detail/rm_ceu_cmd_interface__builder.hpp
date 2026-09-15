// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:srv/RmCeuCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__RM_CEU_CMD_INTERFACE__BUILDER_HPP_
#define COM_INTERFACES__SRV__DETAIL__RM_CEU_CMD_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/srv/detail/rm_ceu_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_RmCeuCmdInterface_Request_point
{
public:
  explicit Init_RmCeuCmdInterface_Request_point(::com_interfaces::srv::RmCeuCmdInterface_Request & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::RmCeuCmdInterface_Request point(::com_interfaces::srv::RmCeuCmdInterface_Request::_point_type arg)
  {
    msg_.point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::RmCeuCmdInterface_Request msg_;
};

class Init_RmCeuCmdInterface_Request_id
{
public:
  Init_RmCeuCmdInterface_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RmCeuCmdInterface_Request_point id(::com_interfaces::srv::RmCeuCmdInterface_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_RmCeuCmdInterface_Request_point(msg_);
  }

private:
  ::com_interfaces::srv::RmCeuCmdInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::RmCeuCmdInterface_Request>()
{
  return com_interfaces::srv::builder::Init_RmCeuCmdInterface_Request_id();
}

}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_RmCeuCmdInterface_Response_msg
{
public:
  explicit Init_RmCeuCmdInterface_Response_msg(::com_interfaces::srv::RmCeuCmdInterface_Response & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::RmCeuCmdInterface_Response msg(::com_interfaces::srv::RmCeuCmdInterface_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::RmCeuCmdInterface_Response msg_;
};

class Init_RmCeuCmdInterface_Response_err_code
{
public:
  Init_RmCeuCmdInterface_Response_err_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RmCeuCmdInterface_Response_msg err_code(::com_interfaces::srv::RmCeuCmdInterface_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_RmCeuCmdInterface_Response_msg(msg_);
  }

private:
  ::com_interfaces::srv::RmCeuCmdInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::RmCeuCmdInterface_Response>()
{
  return com_interfaces::srv::builder::Init_RmCeuCmdInterface_Response_err_code();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__RM_CEU_CMD_INTERFACE__BUILDER_HPP_
