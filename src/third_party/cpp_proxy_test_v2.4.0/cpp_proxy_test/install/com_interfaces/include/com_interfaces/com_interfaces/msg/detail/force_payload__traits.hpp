// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/ForcePayload.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/force_payload__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ForcePayload & msg,
  std::ostream & out)
{
  out << "{";
  // member: weight
  {
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
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

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ForcePayload & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
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

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ForcePayload & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::ForcePayload & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::ForcePayload & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::ForcePayload>()
{
  return "com_interfaces::msg::ForcePayload";
}

template<>
inline const char * name<com_interfaces::msg::ForcePayload>()
{
  return "com_interfaces/msg/ForcePayload";
}

template<>
struct has_fixed_size<com_interfaces::msg::ForcePayload>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<com_interfaces::msg::ForcePayload>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<com_interfaces::msg::ForcePayload>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__TRAITS_HPP_
