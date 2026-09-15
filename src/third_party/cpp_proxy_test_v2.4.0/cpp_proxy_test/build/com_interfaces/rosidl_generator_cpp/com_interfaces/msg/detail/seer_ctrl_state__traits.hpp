// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/SeerCtrlState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/seer_ctrl_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'guide_state'
#include "com_interfaces/msg/detail/agv_guide_state__traits.hpp"
// Member 'control'
#include "com_interfaces/msg/detail/agv_control__traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SeerCtrlState & msg,
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

  // member: pose_x
  {
    out << "pose_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_x, out);
    out << ", ";
  }

  // member: pose_y
  {
    out << "pose_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_y, out);
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

  // member: vel_x
  {
    out << "vel_x: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_x, out);
    out << ", ";
  }

  // member: vel_y
  {
    out << "vel_y: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_y, out);
    out << ", ";
  }

  // member: vel_ang
  {
    out << "vel_ang: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_ang, out);
    out << ", ";
  }

  // member: battery_level
  {
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
    out << ", ";
  }

  // member: battery_temp
  {
    out << "battery_temp: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_temp, out);
    out << ", ";
  }

  // member: charging
  {
    out << "charging: ";
    rosidl_generator_traits::value_to_yaml(msg.charging, out);
    out << ", ";
  }

  // member: voltage
  {
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << ", ";
  }

  // member: current
  {
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << ", ";
  }

  // member: max_charge_voltage
  {
    out << "max_charge_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.max_charge_voltage, out);
    out << ", ";
  }

  // member: max_charge_current
  {
    out << "max_charge_current: ";
    rosidl_generator_traits::value_to_yaml(msg.max_charge_current, out);
    out << ", ";
  }

  // member: manual_charge
  {
    out << "manual_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_charge, out);
    out << ", ";
  }

  // member: auto_charge
  {
    out << "auto_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.auto_charge, out);
    out << ", ";
  }

  // member: battery_cycle
  {
    out << "battery_cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_cycle, out);
    out << ", ";
  }

  // member: battery_user_data
  {
    out << "battery_user_data: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_user_data, out);
    out << ", ";
  }

  // member: guide_state
  {
    out << "guide_state: ";
    to_flow_style_yaml(msg.guide_state, out);
    out << ", ";
  }

  // member: control
  {
    out << "control: ";
    to_flow_style_yaml(msg.control, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SeerCtrlState & msg,
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

  // member: pose_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_x, out);
    out << "\n";
  }

  // member: pose_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_y, out);
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

  // member: vel_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_x: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_x, out);
    out << "\n";
  }

  // member: vel_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_y: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_y, out);
    out << "\n";
  }

  // member: vel_ang
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_ang: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_ang, out);
    out << "\n";
  }

  // member: battery_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
    out << "\n";
  }

  // member: battery_temp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_temp: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_temp, out);
    out << "\n";
  }

  // member: charging
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charging: ";
    rosidl_generator_traits::value_to_yaml(msg.charging, out);
    out << "\n";
  }

  // member: voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << "\n";
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << "\n";
  }

  // member: max_charge_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_charge_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.max_charge_voltage, out);
    out << "\n";
  }

  // member: max_charge_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_charge_current: ";
    rosidl_generator_traits::value_to_yaml(msg.max_charge_current, out);
    out << "\n";
  }

  // member: manual_charge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "manual_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_charge, out);
    out << "\n";
  }

  // member: auto_charge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "auto_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.auto_charge, out);
    out << "\n";
  }

  // member: battery_cycle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_cycle, out);
    out << "\n";
  }

  // member: battery_user_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_user_data: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_user_data, out);
    out << "\n";
  }

  // member: guide_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "guide_state:\n";
    to_block_style_yaml(msg.guide_state, out, indentation + 2);
  }

  // member: control
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control:\n";
    to_block_style_yaml(msg.control, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SeerCtrlState & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::SeerCtrlState & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::SeerCtrlState & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::SeerCtrlState>()
{
  return "com_interfaces::msg::SeerCtrlState";
}

template<>
inline const char * name<com_interfaces::msg::SeerCtrlState>()
{
  return "com_interfaces/msg/SeerCtrlState";
}

template<>
struct has_fixed_size<com_interfaces::msg::SeerCtrlState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::SeerCtrlState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::SeerCtrlState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__TRAITS_HPP_
