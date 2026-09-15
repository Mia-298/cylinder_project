// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/SeerM4State.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__SEER_M4_STATE__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__SEER_M4_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/seer_m4_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'order_state'
#include "com_interfaces/msg/detail/agv_order_state__traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SeerM4State & msg,
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
    out << ", ";
  }

  // member: order_state
  {
    out << "order_state: ";
    to_flow_style_yaml(msg.order_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SeerM4State & msg,
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

  // member: order_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_state:\n";
    to_block_style_yaml(msg.order_state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SeerM4State & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::SeerM4State & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::SeerM4State & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::SeerM4State>()
{
  return "com_interfaces::msg::SeerM4State";
}

template<>
inline const char * name<com_interfaces::msg::SeerM4State>()
{
  return "com_interfaces/msg/SeerM4State";
}

template<>
struct has_fixed_size<com_interfaces::msg::SeerM4State>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::SeerM4State>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::SeerM4State>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__SEER_M4_STATE__TRAITS_HPP_
