// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:srv/SmartMoreCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SMART_MORE_CMD_INTERFACE__BUILDER_HPP_
#define COM_INTERFACES__SRV__DETAIL__SMART_MORE_CMD_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/srv/detail/smart_more_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_SmartMoreCmdInterface_Request_req
{
public:
  explicit Init_SmartMoreCmdInterface_Request_req(::com_interfaces::srv::SmartMoreCmdInterface_Request & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::SmartMoreCmdInterface_Request req(::com_interfaces::srv::SmartMoreCmdInterface_Request::_req_type arg)
  {
    msg_.req = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::SmartMoreCmdInterface_Request msg_;
};

class Init_SmartMoreCmdInterface_Request_id
{
public:
  Init_SmartMoreCmdInterface_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartMoreCmdInterface_Request_req id(::com_interfaces::srv::SmartMoreCmdInterface_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SmartMoreCmdInterface_Request_req(msg_);
  }

private:
  ::com_interfaces::srv::SmartMoreCmdInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::SmartMoreCmdInterface_Request>()
{
  return com_interfaces::srv::builder::Init_SmartMoreCmdInterface_Request_id();
}

}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_SmartMoreCmdInterface_Response_res
{
public:
  explicit Init_SmartMoreCmdInterface_Response_res(::com_interfaces::srv::SmartMoreCmdInterface_Response & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::SmartMoreCmdInterface_Response res(::com_interfaces::srv::SmartMoreCmdInterface_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::SmartMoreCmdInterface_Response msg_;
};

class Init_SmartMoreCmdInterface_Response_msg
{
public:
  explicit Init_SmartMoreCmdInterface_Response_msg(::com_interfaces::srv::SmartMoreCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_SmartMoreCmdInterface_Response_res msg(::com_interfaces::srv::SmartMoreCmdInterface_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return Init_SmartMoreCmdInterface_Response_res(msg_);
  }

private:
  ::com_interfaces::srv::SmartMoreCmdInterface_Response msg_;
};

class Init_SmartMoreCmdInterface_Response_err_code
{
public:
  Init_SmartMoreCmdInterface_Response_err_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartMoreCmdInterface_Response_msg err_code(::com_interfaces::srv::SmartMoreCmdInterface_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_SmartMoreCmdInterface_Response_msg(msg_);
  }

private:
  ::com_interfaces::srv::SmartMoreCmdInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::SmartMoreCmdInterface_Response>()
{
  return com_interfaces::srv::builder::Init_SmartMoreCmdInterface_Response_err_code();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__SMART_MORE_CMD_INTERFACE__BUILDER_HPP_
