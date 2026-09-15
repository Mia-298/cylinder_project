// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:msg/FrRobotState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__TRAITS_HPP_
#define COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/msg/detail/fr_robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FrRobotState & msg,
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

  // member: curtask_index
  {
    out << "curtask_index: ";
    rosidl_generator_traits::value_to_yaml(msg.curtask_index, out);
    out << ", ";
  }

  // member: curstep_index
  {
    out << "curstep_index: ";
    rosidl_generator_traits::value_to_yaml(msg.curstep_index, out);
    out << ", ";
  }

  // member: program_state
  {
    out << "program_state: ";
    rosidl_generator_traits::value_to_yaml(msg.program_state, out);
    out << ", ";
  }

  // member: robot_motion_done
  {
    out << "robot_motion_done: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_motion_done, out);
    out << ", ";
  }

  // member: robot_err_code
  {
    out << "robot_err_code: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_err_code, out);
    out << ", ";
  }

  // member: main_code
  {
    out << "main_code: ";
    rosidl_generator_traits::value_to_yaml(msg.main_code, out);
    out << ", ";
  }

  // member: sub_code
  {
    out << "sub_code: ";
    rosidl_generator_traits::value_to_yaml(msg.sub_code, out);
    out << ", ";
  }

  // member: robot_mode
  {
    out << "robot_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_mode, out);
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
    out << ", ";
  }

  // member: cl_dgt_output_h
  {
    out << "cl_dgt_output_h: ";
    rosidl_generator_traits::value_to_yaml(msg.cl_dgt_output_h, out);
    out << ", ";
  }

  // member: cl_dgt_output_l
  {
    out << "cl_dgt_output_l: ";
    rosidl_generator_traits::value_to_yaml(msg.cl_dgt_output_l, out);
    out << ", ";
  }

  // member: cl_dgt_input_h
  {
    out << "cl_dgt_input_h: ";
    rosidl_generator_traits::value_to_yaml(msg.cl_dgt_input_h, out);
    out << ", ";
  }

  // member: cl_dgt_input_l
  {
    out << "cl_dgt_input_l: ";
    rosidl_generator_traits::value_to_yaml(msg.cl_dgt_input_l, out);
    out << ", ";
  }

  // member: cl_analog_input
  {
    if (msg.cl_analog_input.size() == 0) {
      out << "cl_analog_input: []";
    } else {
      out << "cl_analog_input: [";
      size_t pending_items = msg.cl_analog_input.size();
      for (auto item : msg.cl_analog_input) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: cl_analog_output
  {
    if (msg.cl_analog_output.size() == 0) {
      out << "cl_analog_output: []";
    } else {
      out << "cl_analog_output: [";
      size_t pending_items = msg.cl_analog_output.size();
      for (auto item : msg.cl_analog_output) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tl_dgt_output_l
  {
    out << "tl_dgt_output_l: ";
    rosidl_generator_traits::value_to_yaml(msg.tl_dgt_output_l, out);
    out << ", ";
  }

  // member: tl_dgt_input_l
  {
    out << "tl_dgt_input_l: ";
    rosidl_generator_traits::value_to_yaml(msg.tl_dgt_input_l, out);
    out << ", ";
  }

  // member: emergency_stop
  {
    out << "emergency_stop: ";
    rosidl_generator_traits::value_to_yaml(msg.emergency_stop, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FrRobotState & msg,
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

  // member: curtask_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "curtask_index: ";
    rosidl_generator_traits::value_to_yaml(msg.curtask_index, out);
    out << "\n";
  }

  // member: curstep_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "curstep_index: ";
    rosidl_generator_traits::value_to_yaml(msg.curstep_index, out);
    out << "\n";
  }

  // member: program_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "program_state: ";
    rosidl_generator_traits::value_to_yaml(msg.program_state, out);
    out << "\n";
  }

  // member: robot_motion_done
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_motion_done: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_motion_done, out);
    out << "\n";
  }

  // member: robot_err_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_err_code: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_err_code, out);
    out << "\n";
  }

  // member: main_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "main_code: ";
    rosidl_generator_traits::value_to_yaml(msg.main_code, out);
    out << "\n";
  }

  // member: sub_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sub_code: ";
    rosidl_generator_traits::value_to_yaml(msg.sub_code, out);
    out << "\n";
  }

  // member: robot_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_mode, out);
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

  // member: cl_dgt_output_h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cl_dgt_output_h: ";
    rosidl_generator_traits::value_to_yaml(msg.cl_dgt_output_h, out);
    out << "\n";
  }

  // member: cl_dgt_output_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cl_dgt_output_l: ";
    rosidl_generator_traits::value_to_yaml(msg.cl_dgt_output_l, out);
    out << "\n";
  }

  // member: cl_dgt_input_h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cl_dgt_input_h: ";
    rosidl_generator_traits::value_to_yaml(msg.cl_dgt_input_h, out);
    out << "\n";
  }

  // member: cl_dgt_input_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cl_dgt_input_l: ";
    rosidl_generator_traits::value_to_yaml(msg.cl_dgt_input_l, out);
    out << "\n";
  }

  // member: cl_analog_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cl_analog_input.size() == 0) {
      out << "cl_analog_input: []\n";
    } else {
      out << "cl_analog_input:\n";
      for (auto item : msg.cl_analog_input) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: cl_analog_output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cl_analog_output.size() == 0) {
      out << "cl_analog_output: []\n";
    } else {
      out << "cl_analog_output:\n";
      for (auto item : msg.cl_analog_output) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tl_dgt_output_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tl_dgt_output_l: ";
    rosidl_generator_traits::value_to_yaml(msg.tl_dgt_output_l, out);
    out << "\n";
  }

  // member: tl_dgt_input_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tl_dgt_input_l: ";
    rosidl_generator_traits::value_to_yaml(msg.tl_dgt_input_l, out);
    out << "\n";
  }

  // member: emergency_stop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "emergency_stop: ";
    rosidl_generator_traits::value_to_yaml(msg.emergency_stop, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FrRobotState & msg, bool use_flow_style = false)
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
  const com_interfaces::msg::FrRobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::msg::FrRobotState & msg)
{
  return com_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::msg::FrRobotState>()
{
  return "com_interfaces::msg::FrRobotState";
}

template<>
inline const char * name<com_interfaces::msg::FrRobotState>()
{
  return "com_interfaces/msg/FrRobotState";
}

template<>
struct has_fixed_size<com_interfaces::msg::FrRobotState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::msg::FrRobotState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::msg::FrRobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__TRAITS_HPP_
