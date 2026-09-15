// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/AgvOrderState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/agv_order_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AgvOrderState & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: actual_robot_name
  {
    out << "actual_robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.actual_robot_name, out);
    out << ", ";
  }

  // member: current_step_index
  {
    out << "current_step_index: ";
    rosidl_generator_traits::value_to_yaml(msg.current_step_index, out);
    out << ", ";
  }

  // member: done_step_index
  {
    out << "done_step_index: ";
    rosidl_generator_traits::value_to_yaml(msg.done_step_index, out);
    out << ", ";
  }

  // member: step_num
  {
    out << "step_num: ";
    rosidl_generator_traits::value_to_yaml(msg.step_num, out);
    out << ", ";
  }

  // member: step_locations
  {
    if (msg.step_locations.size() == 0) {
      out << "step_locations: []";
    } else {
      out << "step_locations: [";
      size_t pending_items = msg.step_locations.size();
      for (auto item : msg.step_locations) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: container_id
  {
    out << "container_id: ";
    rosidl_generator_traits::value_to_yaml(msg.container_id, out);
    out << ", ";
  }

  // member: loaded
  {
    out << "loaded: ";
    rosidl_generator_traits::value_to_yaml(msg.loaded, out);
    out << ", ";
  }

  // member: unloaded
  {
    out << "unloaded: ";
    rosidl_generator_traits::value_to_yaml(msg.unloaded, out);
    out << ", ";
  }

  // member: fault
  {
    out << "fault: ";
    rosidl_generator_traits::value_to_yaml(msg.fault, out);
    out << ", ";
  }

  // member: fault_reason
  {
    out << "fault_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_reason, out);
    out << ", ";
  }

  // member: execution_reject
  {
    out << "execution_reject: ";
    rosidl_generator_traits::value_to_yaml(msg.execution_reject, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AgvOrderState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: actual_robot_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "actual_robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.actual_robot_name, out);
    out << "\n";
  }

  // member: current_step_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_step_index: ";
    rosidl_generator_traits::value_to_yaml(msg.current_step_index, out);
    out << "\n";
  }

  // member: done_step_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "done_step_index: ";
    rosidl_generator_traits::value_to_yaml(msg.done_step_index, out);
    out << "\n";
  }

  // member: step_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step_num: ";
    rosidl_generator_traits::value_to_yaml(msg.step_num, out);
    out << "\n";
  }

  // member: step_locations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.step_locations.size() == 0) {
      out << "step_locations: []\n";
    } else {
      out << "step_locations:\n";
      for (auto item : msg.step_locations) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: container_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "container_id: ";
    rosidl_generator_traits::value_to_yaml(msg.container_id, out);
    out << "\n";
  }

  // member: loaded
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "loaded: ";
    rosidl_generator_traits::value_to_yaml(msg.loaded, out);
    out << "\n";
  }

  // member: unloaded
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "unloaded: ";
    rosidl_generator_traits::value_to_yaml(msg.unloaded, out);
    out << "\n";
  }

  // member: fault
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault: ";
    rosidl_generator_traits::value_to_yaml(msg.fault, out);
    out << "\n";
  }

  // member: fault_reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_reason, out);
    out << "\n";
  }

  // member: execution_reject
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "execution_reject: ";
    rosidl_generator_traits::value_to_yaml(msg.execution_reject, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AgvOrderState & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::AgvOrderState & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::AgvOrderState & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::AgvOrderState>()
{
  return "com_interfaces::msg::AgvOrderState";
}

template<>
inline const char * name<com_interfaces::msg::AgvOrderState>()
{
  return "com_interfaces/msg/AgvOrderState";
}

template<>
struct has_fixed_size<com_interfaces::msg::AgvOrderState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::AgvOrderState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::AgvOrderState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__TRAITS_HPP_
