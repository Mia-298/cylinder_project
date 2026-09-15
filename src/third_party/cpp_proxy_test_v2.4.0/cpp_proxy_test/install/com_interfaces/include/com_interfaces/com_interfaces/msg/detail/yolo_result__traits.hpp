// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/YoloResult.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/yolo_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const YoloResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: class_id
  {
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: class_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const YoloResult & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace com_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use com_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const com_interfaces::msg::YoloResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::YoloResult & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::YoloResult>()
{
  return "com_interfaces::msg::YoloResult";
}

template<>
inline const char * name<com_interfaces::msg::YoloResult>()
{
  return "com_interfaces/msg/YoloResult";
}

template<>
struct has_fixed_size<com_interfaces::msg::YoloResult>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<com_interfaces::msg::YoloResult>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<com_interfaces::msg::YoloResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__TRAITS_HPP_
