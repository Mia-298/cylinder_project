// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:srv/VisionEngineCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__BUILDER_HPP_
#define COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/srv/detail/vision_engine_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_VisionEngineCmdInterface_Request_nms_threshold
{
public:
  explicit Init_VisionEngineCmdInterface_Request_nms_threshold(::com_interfaces::srv::VisionEngineCmdInterface_Request & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::VisionEngineCmdInterface_Request nms_threshold(::com_interfaces::srv::VisionEngineCmdInterface_Request::_nms_threshold_type arg)
  {
    msg_.nms_threshold = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Request msg_;
};

class Init_VisionEngineCmdInterface_Request_confidence_threshold
{
public:
  explicit Init_VisionEngineCmdInterface_Request_confidence_threshold(::com_interfaces::srv::VisionEngineCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VisionEngineCmdInterface_Request_nms_threshold confidence_threshold(::com_interfaces::srv::VisionEngineCmdInterface_Request::_confidence_threshold_type arg)
  {
    msg_.confidence_threshold = std::move(arg);
    return Init_VisionEngineCmdInterface_Request_nms_threshold(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Request msg_;
};

class Init_VisionEngineCmdInterface_Request_input_width
{
public:
  explicit Init_VisionEngineCmdInterface_Request_input_width(::com_interfaces::srv::VisionEngineCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VisionEngineCmdInterface_Request_confidence_threshold input_width(::com_interfaces::srv::VisionEngineCmdInterface_Request::_input_width_type arg)
  {
    msg_.input_width = std::move(arg);
    return Init_VisionEngineCmdInterface_Request_confidence_threshold(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Request msg_;
};

class Init_VisionEngineCmdInterface_Request_input_height
{
public:
  explicit Init_VisionEngineCmdInterface_Request_input_height(::com_interfaces::srv::VisionEngineCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VisionEngineCmdInterface_Request_input_width input_height(::com_interfaces::srv::VisionEngineCmdInterface_Request::_input_height_type arg)
  {
    msg_.input_height = std::move(arg);
    return Init_VisionEngineCmdInterface_Request_input_width(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Request msg_;
};

class Init_VisionEngineCmdInterface_Request_model_path
{
public:
  explicit Init_VisionEngineCmdInterface_Request_model_path(::com_interfaces::srv::VisionEngineCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VisionEngineCmdInterface_Request_input_height model_path(::com_interfaces::srv::VisionEngineCmdInterface_Request::_model_path_type arg)
  {
    msg_.model_path = std::move(arg);
    return Init_VisionEngineCmdInterface_Request_input_height(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Request msg_;
};

class Init_VisionEngineCmdInterface_Request_desc
{
public:
  explicit Init_VisionEngineCmdInterface_Request_desc(::com_interfaces::srv::VisionEngineCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_VisionEngineCmdInterface_Request_model_path desc(::com_interfaces::srv::VisionEngineCmdInterface_Request::_desc_type arg)
  {
    msg_.desc = std::move(arg);
    return Init_VisionEngineCmdInterface_Request_model_path(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Request msg_;
};

class Init_VisionEngineCmdInterface_Request_id
{
public:
  Init_VisionEngineCmdInterface_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisionEngineCmdInterface_Request_desc id(::com_interfaces::srv::VisionEngineCmdInterface_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_VisionEngineCmdInterface_Request_desc(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::VisionEngineCmdInterface_Request>()
{
  return com_interfaces::srv::builder::Init_VisionEngineCmdInterface_Request_id();
}

}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_VisionEngineCmdInterface_Response_sphere_loc
{
public:
  explicit Init_VisionEngineCmdInterface_Response_sphere_loc(::com_interfaces::srv::VisionEngineCmdInterface_Response & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::VisionEngineCmdInterface_Response sphere_loc(::com_interfaces::srv::VisionEngineCmdInterface_Response::_sphere_loc_type arg)
  {
    msg_.sphere_loc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Response msg_;
};

class Init_VisionEngineCmdInterface_Response_results
{
public:
  explicit Init_VisionEngineCmdInterface_Response_results(::com_interfaces::srv::VisionEngineCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_VisionEngineCmdInterface_Response_sphere_loc results(::com_interfaces::srv::VisionEngineCmdInterface_Response::_results_type arg)
  {
    msg_.results = std::move(arg);
    return Init_VisionEngineCmdInterface_Response_sphere_loc(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Response msg_;
};

class Init_VisionEngineCmdInterface_Response_msg
{
public:
  explicit Init_VisionEngineCmdInterface_Response_msg(::com_interfaces::srv::VisionEngineCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_VisionEngineCmdInterface_Response_results msg(::com_interfaces::srv::VisionEngineCmdInterface_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return Init_VisionEngineCmdInterface_Response_results(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Response msg_;
};

class Init_VisionEngineCmdInterface_Response_err_code
{
public:
  Init_VisionEngineCmdInterface_Response_err_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisionEngineCmdInterface_Response_msg err_code(::com_interfaces::srv::VisionEngineCmdInterface_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_VisionEngineCmdInterface_Response_msg(msg_);
  }

private:
  ::com_interfaces::srv::VisionEngineCmdInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::VisionEngineCmdInterface_Response>()
{
  return com_interfaces::srv::builder::Init_VisionEngineCmdInterface_Response_err_code();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__BUILDER_HPP_
