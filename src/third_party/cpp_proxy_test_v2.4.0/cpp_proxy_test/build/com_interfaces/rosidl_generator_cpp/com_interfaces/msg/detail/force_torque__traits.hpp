// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/ForceTorque.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/force_torque__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ForceTorque & msg,
  std::ostream & out)
{
  out << "{";
  // member: fx
  {
    out << "fx: ";
    rosidl_generator_traits::value_to_yaml(msg.fx, out);
    out << ", ";
  }

  // member: fy
  {
    out << "fy: ";
    rosidl_generator_traits::value_to_yaml(msg.fy, out);
    out << ", ";
  }

  // member: fz
  {
    out << "fz: ";
    rosidl_generator_traits::value_to_yaml(msg.fz, out);
    out << ", ";
  }

  // member: tx
  {
    out << "tx: ";
    rosidl_generator_traits::value_to_yaml(msg.tx, out);
    out << ", ";
  }

  // member: ty
  {
    out << "ty: ";
    rosidl_generator_traits::value_to_yaml(msg.ty, out);
    out << ", ";
  }

  // member: tz
  {
    out << "tz: ";
    rosidl_generator_traits::value_to_yaml(msg.tz, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ForceTorque & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: fx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fx: ";
    rosidl_generator_traits::value_to_yaml(msg.fx, out);
    out << "\n";
  }

  // member: fy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fy: ";
    rosidl_generator_traits::value_to_yaml(msg.fy, out);
    out << "\n";
  }

  // member: fz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fz: ";
    rosidl_generator_traits::value_to_yaml(msg.fz, out);
    out << "\n";
  }

  // member: tx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tx: ";
    rosidl_generator_traits::value_to_yaml(msg.tx, out);
    out << "\n";
  }

  // member: ty
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ty: ";
    rosidl_generator_traits::value_to_yaml(msg.ty, out);
    out << "\n";
  }

  // member: tz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tz: ";
    rosidl_generator_traits::value_to_yaml(msg.tz, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ForceTorque & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::ForceTorque & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::ForceTorque & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::ForceTorque>()
{
  return "com_interfaces::msg::ForceTorque";
}

template<>
inline const char * name<com_interfaces::msg::ForceTorque>()
{
  return "com_interfaces/msg/ForceTorque";
}

template<>
struct has_fixed_size<com_interfaces::msg::ForceTorque>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<com_interfaces::msg::ForceTorque>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<com_interfaces::msg::ForceTorque>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__TRAITS_HPP_
