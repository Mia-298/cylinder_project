// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/AgvGuideState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/agv_guide_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AgvGuideState & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_status
  {
    out << "task_status: ";
    rosidl_generator_traits::value_to_yaml(msg.task_status, out);
    out << ", ";
  }

  // member: task_type
  {
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
    out << ", ";
  }

  // member: target_station
  {
    out << "target_station: ";
    rosidl_generator_traits::value_to_yaml(msg.target_station, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AgvGuideState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_status: ";
    rosidl_generator_traits::value_to_yaml(msg.task_status, out);
    out << "\n";
  }

  // member: task_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
    out << "\n";
  }

  // member: target_station
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_station: ";
    rosidl_generator_traits::value_to_yaml(msg.target_station, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AgvGuideState & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::AgvGuideState & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::AgvGuideState & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::AgvGuideState>()
{
  return "com_interfaces::msg::AgvGuideState";
}

template<>
inline const char * name<com_interfaces::msg::AgvGuideState>()
{
  return "com_interfaces/msg/AgvGuideState";
}

template<>
struct has_fixed_size<com_interfaces::msg::AgvGuideState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::AgvGuideState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::AgvGuideState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__TRAITS_HPP_
