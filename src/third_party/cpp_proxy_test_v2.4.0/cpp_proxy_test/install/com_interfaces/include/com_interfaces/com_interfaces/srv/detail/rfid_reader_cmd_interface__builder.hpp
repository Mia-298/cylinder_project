// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:srv/RfidReaderCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__RFID_READER_CMD_INTERFACE__BUILDER_HPP_
#define COM_INTERFACES__SRV__DETAIL__RFID_READER_CMD_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/srv/detail/rfid_reader_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_RfidReaderCmdInterface_Request_power
{
public:
  explicit Init_RfidReaderCmdInterface_Request_power(::com_interfaces::srv::RfidReaderCmdInterface_Request & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::RfidReaderCmdInterface_Request power(::com_interfaces::srv::RfidReaderCmdInterface_Request::_power_type arg)
  {
    msg_.power = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::RfidReaderCmdInterface_Request msg_;
};

class Init_RfidReaderCmdInterface_Request_id
{
public:
  Init_RfidReaderCmdInterface_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RfidReaderCmdInterface_Request_power id(::com_interfaces::srv::RfidReaderCmdInterface_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_RfidReaderCmdInterface_Request_power(msg_);
  }

private:
  ::com_interfaces::srv::RfidReaderCmdInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::RfidReaderCmdInterface_Request>()
{
  return com_interfaces::srv::builder::Init_RfidReaderCmdInterface_Request_id();
}

}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_RfidReaderCmdInterface_Response_data
{
public:
  explicit Init_RfidReaderCmdInterface_Response_data(::com_interfaces::srv::RfidReaderCmdInterface_Response & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::RfidReaderCmdInterface_Response data(::com_interfaces::srv::RfidReaderCmdInterface_Response::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::RfidReaderCmdInterface_Response msg_;
};

class Init_RfidReaderCmdInterface_Response_msg
{
public:
  explicit Init_RfidReaderCmdInterface_Response_msg(::com_interfaces::srv::RfidReaderCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_RfidReaderCmdInterface_Response_data msg(::com_interfaces::srv::RfidReaderCmdInterface_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return Init_RfidReaderCmdInterface_Response_data(msg_);
  }

private:
  ::com_interfaces::srv::RfidReaderCmdInterface_Response msg_;
};

class Init_RfidReaderCmdInterface_Response_err_code
{
public:
  Init_RfidReaderCmdInterface_Response_err_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RfidReaderCmdInterface_Response_msg err_code(::com_interfaces::srv::RfidReaderCmdInterface_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_RfidReaderCmdInterface_Response_msg(msg_);
  }

private:
  ::com_interfaces::srv::RfidReaderCmdInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::RfidReaderCmdInterface_Response>()
{
  return com_interfaces::srv::builder::Init_RfidReaderCmdInterface_Response_err_code();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__RFID_READER_CMD_INTERFACE__BUILDER_HPP_
