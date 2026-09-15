// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/AgvControl.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/agv_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AgvControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: locked
  {
    out << "locked: ";
    rosidl_generator_traits::value_to_yaml(msg.locked, out);
    out << ", ";
  }

  // member: ip
  {
    out << "ip: ";
    rosidl_generator_traits::value_to_yaml(msg.ip, out);
    out << ", ";
  }

  // member: port
  {
    out << "port: ";
    rosidl_generator_traits::value_to_yaml(msg.port, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: nick_name
  {
    out << "nick_name: ";
    rosidl_generator_traits::value_to_yaml(msg.nick_name, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << ", ";
  }

  // member: desc
  {
    out << "desc: ";
    rosidl_generator_traits::value_to_yaml(msg.desc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AgvControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: locked
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "locked: ";
    rosidl_generator_traits::value_to_yaml(msg.locked, out);
    out << "\n";
  }

  // member: ip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ip: ";
    rosidl_generator_traits::value_to_yaml(msg.ip, out);
    out << "\n";
  }

  // member: port
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "port: ";
    rosidl_generator_traits::value_to_yaml(msg.port, out);
    out << "\n";
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: nick_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nick_name: ";
    rosidl_generator_traits::value_to_yaml(msg.nick_name, out);
    out << "\n";
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }

  // member: desc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "desc: ";
    rosidl_generator_traits::value_to_yaml(msg.desc, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AgvControl & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::AgvControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::AgvControl & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::AgvControl>()
{
  return "com_interfaces::msg::AgvControl";
}

template<>
inline const char * name<com_interfaces::msg::AgvControl>()
{
  return "com_interfaces/msg/AgvControl";
}

template<>
struct has_fixed_size<com_interfaces::msg::AgvControl>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::AgvControl>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::AgvControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__TRAITS_HPP_
