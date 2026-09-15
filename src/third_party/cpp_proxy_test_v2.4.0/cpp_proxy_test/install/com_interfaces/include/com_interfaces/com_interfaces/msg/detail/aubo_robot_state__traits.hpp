// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/AuboRobotState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AUBO_ROBOT_STATE__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__AUBO_ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/aubo_robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AuboRobotState & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_index
  {
    out << "robot_index: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_index, out);
    out << ", ";
  }

  // member: robot_name
  {
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
    out << ", ";
  }

  // member: robot_type
  {
    out << "robot_type: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_type, out);
    out << ", ";
  }

  // member: robot_soft_index
  {
    out << "robot_soft_index: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_soft_index, out);
    out << ", ";
  }

  // member: robot_ip
  {
    out << "robot_ip: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_ip, out);
    out << ", ";
  }

  // member: mode_type
  {
    out << "mode_type: ";
    rosidl_generator_traits::value_to_yaml(msg.mode_type, out);
    out << ", ";
  }

  // member: safety_mode_type
  {
    out << "safety_mode_type: ";
    rosidl_generator_traits::value_to_yaml(msg.safety_mode_type, out);
    out << ", ";
  }

  // member: robot_speed
  {
    out << "robot_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_speed, out);
    out << ", ";
  }

  // member: jt_cur_pos
  {
    if (msg.jt_cur_pos.size() == 0) {
      out << "jt_cur_pos: []";
    } else {
      out << "jt_cur_pos: [";
      size_t pending_items = msg.jt_cur_pos.size();
      for (auto item : msg.jt_cur_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tl_cur_pos
  {
    if (msg.tl_cur_pos.size() == 0) {
      out << "tl_cur_pos: []";
    } else {
      out << "tl_cur_pos: [";
      size_t pending_items = msg.tl_cur_pos.size();
      for (auto item : msg.tl_cur_pos) {
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
  const AuboRobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_index: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_index, out);
    out << "\n";
  }

  // member: robot_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
    out << "\n";
  }

  // member: robot_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_type: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_type, out);
    out << "\n";
  }

  // member: robot_soft_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_soft_index: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_soft_index, out);
    out << "\n";
  }

  // member: robot_ip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_ip: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_ip, out);
    out << "\n";
  }

  // member: mode_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode_type: ";
    rosidl_generator_traits::value_to_yaml(msg.mode_type, out);
    out << "\n";
  }

  // member: safety_mode_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safety_mode_type: ";
    rosidl_generator_traits::value_to_yaml(msg.safety_mode_type, out);
    out << "\n";
  }

  // member: robot_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_speed, out);
    out << "\n";
  }

  // member: jt_cur_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.jt_cur_pos.size() == 0) {
      out << "jt_cur_pos: []\n";
    } else {
      out << "jt_cur_pos:\n";
      for (auto item : msg.jt_cur_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tl_cur_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tl_cur_pos.size() == 0) {
      out << "tl_cur_pos: []\n";
    } else {
      out << "tl_cur_pos:\n";
      for (auto item : msg.tl_cur_pos) {
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

inline std::string to_yaml(const AuboRobotState & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::AuboRobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::AuboRobotState & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::AuboRobotState>()
{
  return "com_interfaces::msg::AuboRobotState";
}

template<>
inline const char * name<com_interfaces::msg::AuboRobotState>()
{
  return "com_interfaces/msg/AuboRobotState";
}

template<>
struct has_fixed_size<com_interfaces::msg::AuboRobotState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::AuboRobotState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::AuboRobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__AUBO_ROBOT_STATE__TRAITS_HPP_
