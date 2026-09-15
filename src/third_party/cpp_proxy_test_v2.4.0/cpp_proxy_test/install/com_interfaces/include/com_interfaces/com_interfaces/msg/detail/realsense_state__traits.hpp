// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/RealsenseState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/realsense_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RealsenseState & msg,
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

  // member: node_online
  {
    out << "node_online: ";
    rosidl_generator_traits::value_to_yaml(msg.node_online, out);
    out << ", ";
  }

  // member: color_ready
  {
    out << "color_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.color_ready, out);
    out << ", ";
  }

  // member: depth_ready
  {
    out << "depth_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_ready, out);
    out << ", ";
  }

  // member: aligned_depth_ready
  {
    out << "aligned_depth_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.aligned_depth_ready, out);
    out << ", ";
  }

  // member: color_info_ready
  {
    out << "color_info_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.color_info_ready, out);
    out << ", ";
  }

  // member: depth_info_ready
  {
    out << "depth_info_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_info_ready, out);
    out << ", ";
  }

  // member: color_topic
  {
    out << "color_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.color_topic, out);
    out << ", ";
  }

  // member: depth_topic
  {
    out << "depth_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_topic, out);
    out << ", ";
  }

  // member: aligned_depth_topic
  {
    out << "aligned_depth_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.aligned_depth_topic, out);
    out << ", ";
  }

  // member: color_info_topic
  {
    out << "color_info_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.color_info_topic, out);
    out << ", ";
  }

  // member: depth_info_topic
  {
    out << "depth_info_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_info_topic, out);
    out << ", ";
  }

  // member: last_color_ts_ms
  {
    out << "last_color_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_color_ts_ms, out);
    out << ", ";
  }

  // member: last_depth_ts_ms
  {
    out << "last_depth_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_depth_ts_ms, out);
    out << ", ";
  }

  // member: last_aligned_depth_ts_ms
  {
    out << "last_aligned_depth_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_aligned_depth_ts_ms, out);
    out << ", ";
  }

  // member: last_color_info_ts_ms
  {
    out << "last_color_info_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_color_info_ts_ms, out);
    out << ", ";
  }

  // member: last_depth_info_ts_ms
  {
    out << "last_depth_info_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_depth_info_ts_ms, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RealsenseState & msg,
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

  // member: node_online
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_online: ";
    rosidl_generator_traits::value_to_yaml(msg.node_online, out);
    out << "\n";
  }

  // member: color_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.color_ready, out);
    out << "\n";
  }

  // member: depth_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_ready, out);
    out << "\n";
  }

  // member: aligned_depth_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aligned_depth_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.aligned_depth_ready, out);
    out << "\n";
  }

  // member: color_info_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color_info_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.color_info_ready, out);
    out << "\n";
  }

  // member: depth_info_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_info_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_info_ready, out);
    out << "\n";
  }

  // member: color_topic
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.color_topic, out);
    out << "\n";
  }

  // member: depth_topic
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_topic, out);
    out << "\n";
  }

  // member: aligned_depth_topic
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aligned_depth_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.aligned_depth_topic, out);
    out << "\n";
  }

  // member: color_info_topic
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color_info_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.color_info_topic, out);
    out << "\n";
  }

  // member: depth_info_topic
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_info_topic: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_info_topic, out);
    out << "\n";
  }

  // member: last_color_ts_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_color_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_color_ts_ms, out);
    out << "\n";
  }

  // member: last_depth_ts_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_depth_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_depth_ts_ms, out);
    out << "\n";
  }

  // member: last_aligned_depth_ts_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_aligned_depth_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_aligned_depth_ts_ms, out);
    out << "\n";
  }

  // member: last_color_info_ts_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_color_info_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_color_info_ts_ms, out);
    out << "\n";
  }

  // member: last_depth_info_ts_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_depth_info_ts_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.last_depth_info_ts_ms, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RealsenseState & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::RealsenseState & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::RealsenseState & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::RealsenseState>()
{
  return "com_interfaces::msg::RealsenseState";
}

template<>
inline const char * name<com_interfaces::msg::RealsenseState>()
{
  return "com_interfaces/msg/RealsenseState";
}

template<>
struct has_fixed_size<com_interfaces::msg::RealsenseState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::RealsenseState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::RealsenseState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__TRAITS_HPP_
