// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/VisionEngineState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__VISION_ENGINE_STATE__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__VISION_ENGINE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/vision_engine_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const VisionEngineState & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: err_code
  {
    out << "err_code: ";
    rosidl_generator_traits::value_to_yaml(msg.err_code, out);
    out << ", ";
  }

  // member: err_msg
  {
    out << "err_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.err_msg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VisionEngineState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: err_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "err_code: ";
    rosidl_generator_traits::value_to_yaml(msg.err_code, out);
    out << "\n";
  }

  // member: err_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "err_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.err_msg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VisionEngineState & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::VisionEngineState & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::VisionEngineState & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::VisionEngineState>()
{
  return "com_interfaces::msg::VisionEngineState";
}

template<>
inline const char * name<com_interfaces::msg::VisionEngineState>()
{
  return "com_interfaces/msg/VisionEngineState";
}

template<>
struct has_fixed_size<com_interfaces::msg::VisionEngineState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::VisionEngineState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::VisionEngineState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__VISION_ENGINE_STATE__TRAITS_HPP_
