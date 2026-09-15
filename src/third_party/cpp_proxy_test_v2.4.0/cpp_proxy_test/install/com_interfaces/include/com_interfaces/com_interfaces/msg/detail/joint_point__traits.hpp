// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/JointPoint.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__JOINT_POINT__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__JOINT_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/joint_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const JointPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint_point
  {
    if (msg.joint_point.size() == 0) {
      out << "joint_point: []";
    } else {
      out << "joint_point: [";
      size_t pending_items = msg.joint_point.size();
      for (auto item : msg.joint_point) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JointPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_point.size() == 0) {
      out << "joint_point: []\n";
    } else {
      out << "joint_point:\n";
      for (auto item : msg.joint_point) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JointPoint & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::JointPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::JointPoint & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::JointPoint>()
{
  return "com_interfaces::msg::JointPoint";
}

template<>
inline const char * name<com_interfaces::msg::JointPoint>()
{
  return "com_interfaces/msg/JointPoint";
}

template<>
struct has_fixed_size<com_interfaces::msg::JointPoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<com_interfaces::msg::JointPoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<com_interfaces::msg::JointPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__JOINT_POINT__TRAITS_HPP_
