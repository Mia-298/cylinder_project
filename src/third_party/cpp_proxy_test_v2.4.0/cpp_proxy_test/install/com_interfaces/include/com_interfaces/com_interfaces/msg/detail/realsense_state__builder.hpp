// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/RealsenseState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/realsense_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_RealsenseState_last_depth_info_ts_ms
{
public:
  explicit Init_RealsenseState_last_depth_info_ts_ms(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::RealsenseState last_depth_info_ts_ms(::com_interfaces::msg::RealsenseState::_last_depth_info_ts_ms_type arg)
  {
    msg_.last_depth_info_ts_ms = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_last_color_info_ts_ms
{
public:
  explicit Init_RealsenseState_last_color_info_ts_ms(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_last_depth_info_ts_ms last_color_info_ts_ms(::com_interfaces::msg::RealsenseState::_last_color_info_ts_ms_type arg)
  {
    msg_.last_color_info_ts_ms = std::move(arg);
    return Init_RealsenseState_last_depth_info_ts_ms(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_last_aligned_depth_ts_ms
{
public:
  explicit Init_RealsenseState_last_aligned_depth_ts_ms(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_last_color_info_ts_ms last_aligned_depth_ts_ms(::com_interfaces::msg::RealsenseState::_last_aligned_depth_ts_ms_type arg)
  {
    msg_.last_aligned_depth_ts_ms = std::move(arg);
    return Init_RealsenseState_last_color_info_ts_ms(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_last_depth_ts_ms
{
public:
  explicit Init_RealsenseState_last_depth_ts_ms(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_last_aligned_depth_ts_ms last_depth_ts_ms(::com_interfaces::msg::RealsenseState::_last_depth_ts_ms_type arg)
  {
    msg_.last_depth_ts_ms = std::move(arg);
    return Init_RealsenseState_last_aligned_depth_ts_ms(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_last_color_ts_ms
{
public:
  explicit Init_RealsenseState_last_color_ts_ms(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_last_depth_ts_ms last_color_ts_ms(::com_interfaces::msg::RealsenseState::_last_color_ts_ms_type arg)
  {
    msg_.last_color_ts_ms = std::move(arg);
    return Init_RealsenseState_last_depth_ts_ms(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_depth_info_topic
{
public:
  explicit Init_RealsenseState_depth_info_topic(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_last_color_ts_ms depth_info_topic(::com_interfaces::msg::RealsenseState::_depth_info_topic_type arg)
  {
    msg_.depth_info_topic = std::move(arg);
    return Init_RealsenseState_last_color_ts_ms(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_color_info_topic
{
public:
  explicit Init_RealsenseState_color_info_topic(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_depth_info_topic color_info_topic(::com_interfaces::msg::RealsenseState::_color_info_topic_type arg)
  {
    msg_.color_info_topic = std::move(arg);
    return Init_RealsenseState_depth_info_topic(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_aligned_depth_topic
{
public:
  explicit Init_RealsenseState_aligned_depth_topic(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_color_info_topic aligned_depth_topic(::com_interfaces::msg::RealsenseState::_aligned_depth_topic_type arg)
  {
    msg_.aligned_depth_topic = std::move(arg);
    return Init_RealsenseState_color_info_topic(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_depth_topic
{
public:
  explicit Init_RealsenseState_depth_topic(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_aligned_depth_topic depth_topic(::com_interfaces::msg::RealsenseState::_depth_topic_type arg)
  {
    msg_.depth_topic = std::move(arg);
    return Init_RealsenseState_aligned_depth_topic(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_color_topic
{
public:
  explicit Init_RealsenseState_color_topic(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_depth_topic color_topic(::com_interfaces::msg::RealsenseState::_color_topic_type arg)
  {
    msg_.color_topic = std::move(arg);
    return Init_RealsenseState_depth_topic(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_depth_info_ready
{
public:
  explicit Init_RealsenseState_depth_info_ready(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_color_topic depth_info_ready(::com_interfaces::msg::RealsenseState::_depth_info_ready_type arg)
  {
    msg_.depth_info_ready = std::move(arg);
    return Init_RealsenseState_color_topic(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_color_info_ready
{
public:
  explicit Init_RealsenseState_color_info_ready(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_depth_info_ready color_info_ready(::com_interfaces::msg::RealsenseState::_color_info_ready_type arg)
  {
    msg_.color_info_ready = std::move(arg);
    return Init_RealsenseState_depth_info_ready(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_aligned_depth_ready
{
public:
  explicit Init_RealsenseState_aligned_depth_ready(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_color_info_ready aligned_depth_ready(::com_interfaces::msg::RealsenseState::_aligned_depth_ready_type arg)
  {
    msg_.aligned_depth_ready = std::move(arg);
    return Init_RealsenseState_color_info_ready(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_depth_ready
{
public:
  explicit Init_RealsenseState_depth_ready(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_aligned_depth_ready depth_ready(::com_interfaces::msg::RealsenseState::_depth_ready_type arg)
  {
    msg_.depth_ready = std::move(arg);
    return Init_RealsenseState_aligned_depth_ready(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_color_ready
{
public:
  explicit Init_RealsenseState_color_ready(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_depth_ready color_ready(::com_interfaces::msg::RealsenseState::_color_ready_type arg)
  {
    msg_.color_ready = std::move(arg);
    return Init_RealsenseState_depth_ready(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_node_online
{
public:
  explicit Init_RealsenseState_node_online(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_color_ready node_online(::com_interfaces::msg::RealsenseState::_node_online_type arg)
  {
    msg_.node_online = std::move(arg);
    return Init_RealsenseState_color_ready(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_err_msg
{
public:
  explicit Init_RealsenseState_err_msg(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_node_online err_msg(::com_interfaces::msg::RealsenseState::_err_msg_type arg)
  {
    msg_.err_msg = std::move(arg);
    return Init_RealsenseState_node_online(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_err_code
{
public:
  explicit Init_RealsenseState_err_code(::com_interfaces::msg::RealsenseState & msg)
  : msg_(msg)
  {}
  Init_RealsenseState_err_msg err_code(::com_interfaces::msg::RealsenseState::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_RealsenseState_err_msg(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

class Init_RealsenseState_name
{
public:
  Init_RealsenseState_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RealsenseState_err_code name(::com_interfaces::msg::RealsenseState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_RealsenseState_err_code(msg_);
  }

private:
  ::com_interfaces::msg::RealsenseState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::RealsenseState>()
{
  return com_interfaces::msg::builder::Init_RealsenseState_name();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__BUILDER_HPP_
