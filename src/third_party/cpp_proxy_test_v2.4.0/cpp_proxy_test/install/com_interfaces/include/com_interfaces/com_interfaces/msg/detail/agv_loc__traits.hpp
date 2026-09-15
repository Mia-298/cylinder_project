// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/AgvLoc.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_LOC__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_LOC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/agv_loc__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AgvLoc & msg,
  std::ostream & out)
{
  out << "{";
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

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: current_station
  {
    out << "current_station: ";
    rosidl_generator_traits::value_to_yaml(msg.current_station, out);
    out << ", ";
  }

  // member: last_station
  {
    out << "last_station: ";
    rosidl_generator_traits::value_to_yaml(msg.last_station, out);
    out << ", ";
  }

  // member: loc_method
  {
    out << "loc_method: ";
    rosidl_generator_traits::value_to_yaml(msg.loc_method, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AgvLoc & msg,
  std::ostream & out, size_t indentation = 0)
{
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

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
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

  // member: current_station
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_station: ";
    rosidl_generator_traits::value_to_yaml(msg.current_station, out);
    out << "\n";
  }

  // member: last_station
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_station: ";
    rosidl_generator_traits::value_to_yaml(msg.last_station, out);
    out << "\n";
  }

  // member: loc_method
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "loc_method: ";
    rosidl_generator_traits::value_to_yaml(msg.loc_method, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AgvLoc & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::AgvLoc & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::AgvLoc & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::AgvLoc>()
{
  return "com_interfaces::msg::AgvLoc";
}

template<>
inline const char * name<com_interfaces::msg::AgvLoc>()
{
  return "com_interfaces/msg/AgvLoc";
}

template<>
struct has_fixed_size<com_interfaces::msg::AgvLoc>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::AgvLoc>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::AgvLoc>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_LOC__TRAITS_HPP_
