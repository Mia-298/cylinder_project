// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/AgvControl.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/agv_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_AgvControl_desc
{
public:
  explicit Init_AgvControl_desc(::com_interfaces::msg::AgvControl & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::AgvControl desc(::com_interfaces::msg::AgvControl::_desc_type arg)
  {
    msg_.desc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::AgvControl msg_;
};

class Init_AgvControl_time
{
public:
  explicit Init_AgvControl_time(::com_interfaces::msg::AgvControl & msg)
  : msg_(msg)
  {}
  Init_AgvControl_desc time(::com_interfaces::msg::AgvControl::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_AgvControl_desc(msg_);
  }

private:
  ::com_interfaces::msg::AgvControl msg_;
};

class Init_AgvControl_nick_name
{
public:
  explicit Init_AgvControl_nick_name(::com_interfaces::msg::AgvControl & msg)
  : msg_(msg)
  {}
  Init_AgvControl_time nick_name(::com_interfaces::msg::AgvControl::_nick_name_type arg)
  {
    msg_.nick_name = std::move(arg);
    return Init_AgvControl_time(msg_);
  }

private:
  ::com_interfaces::msg::AgvControl msg_;
};

class Init_AgvControl_type
{
public:
  explicit Init_AgvControl_type(::com_interfaces::msg::AgvControl & msg)
  : msg_(msg)
  {}
  Init_AgvControl_nick_name type(::com_interfaces::msg::AgvControl::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_AgvControl_nick_name(msg_);
  }

private:
  ::com_interfaces::msg::AgvControl msg_;
};

class Init_AgvControl_port
{
public:
  explicit Init_AgvControl_port(::com_interfaces::msg::AgvControl & msg)
  : msg_(msg)
  {}
  Init_AgvControl_type port(::com_interfaces::msg::AgvControl::_port_type arg)
  {
    msg_.port = std::move(arg);
    return Init_AgvControl_type(msg_);
  }

private:
  ::com_interfaces::msg::AgvControl msg_;
};

class Init_AgvControl_ip
{
public:
  explicit Init_AgvControl_ip(::com_interfaces::msg::AgvControl & msg)
  : msg_(msg)
  {}
  Init_AgvControl_port ip(::com_interfaces::msg::AgvControl::_ip_type arg)
  {
    msg_.ip = std::move(arg);
    return Init_AgvControl_port(msg_);
  }

private:
  ::com_interfaces::msg::AgvControl msg_;
};

class Init_AgvControl_locked
{
public:
  Init_AgvControl_locked()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AgvControl_ip locked(::com_interfaces::msg::AgvControl::_locked_type arg)
  {
    msg_.locked = std::move(arg);
    return Init_AgvControl_ip(msg_);
  }

private:
  ::com_interfaces::msg::AgvControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::AgvControl>()
{
  return com_interfaces::msg::builder::Init_AgvControl_locked();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__BUILDER_HPP_
