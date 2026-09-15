// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/YoloResult.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/yolo_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_YoloResult_height
{
public:
  explicit Init_YoloResult_height(::com_interfaces::msg::YoloResult & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::YoloResult height(::com_interfaces::msg::YoloResult::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::YoloResult msg_;
};

class Init_YoloResult_width
{
public:
  explicit Init_YoloResult_width(::com_interfaces::msg::YoloResult & msg)
  : msg_(msg)
  {}
  Init_YoloResult_height width(::com_interfaces::msg::YoloResult::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_YoloResult_height(msg_);
  }

private:
  ::com_interfaces::msg::YoloResult msg_;
};

class Init_YoloResult_y
{
public:
  explicit Init_YoloResult_y(::com_interfaces::msg::YoloResult & msg)
  : msg_(msg)
  {}
  Init_YoloResult_width y(::com_interfaces::msg::YoloResult::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_YoloResult_width(msg_);
  }

private:
  ::com_interfaces::msg::YoloResult msg_;
};

class Init_YoloResult_x
{
public:
  explicit Init_YoloResult_x(::com_interfaces::msg::YoloResult & msg)
  : msg_(msg)
  {}
  Init_YoloResult_y x(::com_interfaces::msg::YoloResult::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_YoloResult_y(msg_);
  }

private:
  ::com_interfaces::msg::YoloResult msg_;
};

class Init_YoloResult_confidence
{
public:
  explicit Init_YoloResult_confidence(::com_interfaces::msg::YoloResult & msg)
  : msg_(msg)
  {}
  Init_YoloResult_x confidence(::com_interfaces::msg::YoloResult::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_YoloResult_x(msg_);
  }

private:
  ::com_interfaces::msg::YoloResult msg_;
};

class Init_YoloResult_class_id
{
public:
  Init_YoloResult_class_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloResult_confidence class_id(::com_interfaces::msg::YoloResult::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_YoloResult_confidence(msg_);
  }

private:
  ::com_interfaces::msg::YoloResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::YoloResult>()
{
  return com_interfaces::msg::builder::Init_YoloResult_class_id();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__BUILDER_HPP_
