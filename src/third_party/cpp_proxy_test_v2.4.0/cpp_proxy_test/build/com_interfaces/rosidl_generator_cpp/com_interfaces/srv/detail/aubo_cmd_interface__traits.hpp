// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:srv/AuboCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__AUBO_CMD_INTERFACE__TRAITS_HPP_
#define COM_INTERFACES__SRV__DETAIL__AUBO_CMD_INTERFACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/srv/detail/aubo_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'joint_path'
#include "com_interfaces/msg/detail/joint_point__traits.hpp"

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AuboCmdInterface_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: en
  {
    out << "en: ";
    rosidl_generator_traits::value_to_yaml(msg.en, out);
    out << ", ";
  }

  // member: joint_or_desc
  {
    out << "joint_or_desc: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_or_desc, out);
    out << ", ";
  }

  // member: position
  {
    if (msg.position.size() == 0) {
      out << "position: []";
    } else {
      out << "position: [";
      size_t pending_items = msg.position.size();
      for (auto item : msg.position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: axid
  {
    out << "axid: ";
    rosidl_generator_traits::value_to_yaml(msg.axid, out);
    out << ", ";
  }

  // member: dir
  {
    out << "dir: ";
    rosidl_generator_traits::value_to_yaml(msg.dir, out);
    out << ", ";
  }

  // member: deg
  {
    out << "deg: ";
    rosidl_generator_traits::value_to_yaml(msg.deg, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: acc
  {
    out << "acc: ";
    rosidl_generator_traits::value_to_yaml(msg.acc, out);
    out << ", ";
  }

  // member: tool
  {
    out << "tool: ";
    rosidl_generator_traits::value_to_yaml(msg.tool, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: register_index
  {
    out << "register_index: ";
    rosidl_generator_traits::value_to_yaml(msg.register_index, out);
    out << ", ";
  }

  // member: register_value
  {
    out << "register_value: ";
    rosidl_generator_traits::value_to_yaml(msg.register_value, out);
    out << ", ";
  }

  // member: input_or_output
  {
    out << "input_or_output: ";
    rosidl_generator_traits::value_to_yaml(msg.input_or_output, out);
    out << ", ";
  }

  // member: io_index
  {
    out << "io_index: ";
    rosidl_generator_traits::value_to_yaml(msg.io_index, out);
    out << ", ";
  }

  // member: io_value
  {
    out << "io_value: ";
    rosidl_generator_traits::value_to_yaml(msg.io_value, out);
    out << ", ";
  }

  // member: program
  {
    out << "program: ";
    rosidl_generator_traits::value_to_yaml(msg.program, out);
    out << ", ";
  }

  // member: interval
  {
    out << "interval: ";
    rosidl_generator_traits::value_to_yaml(msg.interval, out);
    out << ", ";
  }

  // member: filename
  {
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << ", ";
  }

  // member: joint_path
  {
    if (msg.joint_path.size() == 0) {
      out << "joint_path: []";
    } else {
      out << "joint_path: [";
      size_t pending_items = msg.joint_path.size();
      for (auto item : msg.joint_path) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: gripper_index
  {
    out << "gripper_index: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_index, out);
    out << ", ";
  }

  // member: act
  {
    out << "act: ";
    rosidl_generator_traits::value_to_yaml(msg.act, out);
    out << ", ";
  }

  // member: gripper_pos
  {
    out << "gripper_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_pos, out);
    out << ", ";
  }

  // member: gripper_vel
  {
    out << "gripper_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_vel, out);
    out << ", ";
  }

  // member: gripper_force
  {
    out << "gripper_force: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_force, out);
    out << ", ";
  }

  // member: max_time
  {
    out << "max_time: ";
    rosidl_generator_traits::value_to_yaml(msg.max_time, out);
    out << ", ";
  }

  // member: gripper_block
  {
    out << "gripper_block: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_block, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AuboCmdInterface_Request & msg,
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

  // member: en
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "en: ";
    rosidl_generator_traits::value_to_yaml(msg.en, out);
    out << "\n";
  }

  // member: joint_or_desc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_or_desc: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_or_desc, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position.size() == 0) {
      out << "position: []\n";
    } else {
      out << "position:\n";
      for (auto item : msg.position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: axid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "axid: ";
    rosidl_generator_traits::value_to_yaml(msg.axid, out);
    out << "\n";
  }

  // member: dir
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dir: ";
    rosidl_generator_traits::value_to_yaml(msg.dir, out);
    out << "\n";
  }

  // member: deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deg: ";
    rosidl_generator_traits::value_to_yaml(msg.deg, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc: ";
    rosidl_generator_traits::value_to_yaml(msg.acc, out);
    out << "\n";
  }

  // member: tool
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tool: ";
    rosidl_generator_traits::value_to_yaml(msg.tool, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: register_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "register_index: ";
    rosidl_generator_traits::value_to_yaml(msg.register_index, out);
    out << "\n";
  }

  // member: register_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "register_value: ";
    rosidl_generator_traits::value_to_yaml(msg.register_value, out);
    out << "\n";
  }

  // member: input_or_output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_or_output: ";
    rosidl_generator_traits::value_to_yaml(msg.input_or_output, out);
    out << "\n";
  }

  // member: io_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "io_index: ";
    rosidl_generator_traits::value_to_yaml(msg.io_index, out);
    out << "\n";
  }

  // member: io_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "io_value: ";
    rosidl_generator_traits::value_to_yaml(msg.io_value, out);
    out << "\n";
  }

  // member: program
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "program: ";
    rosidl_generator_traits::value_to_yaml(msg.program, out);
    out << "\n";
  }

  // member: interval
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "interval: ";
    rosidl_generator_traits::value_to_yaml(msg.interval, out);
    out << "\n";
  }

  // member: filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << "\n";
  }

  // member: joint_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_path.size() == 0) {
      out << "joint_path: []\n";
    } else {
      out << "joint_path:\n";
      for (auto item : msg.joint_path) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: gripper_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_index: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_index, out);
    out << "\n";
  }

  // member: act
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "act: ";
    rosidl_generator_traits::value_to_yaml(msg.act, out);
    out << "\n";
  }

  // member: gripper_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_pos, out);
    out << "\n";
  }

  // member: gripper_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_vel, out);
    out << "\n";
  }

  // member: gripper_force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_force: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_force, out);
    out << "\n";
  }

  // member: max_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_time: ";
    rosidl_generator_traits::value_to_yaml(msg.max_time, out);
    out << "\n";
  }

  // member: gripper_block
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_block: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_block, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AuboCmdInterface_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace com_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use com_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const com_interfaces::srv::AuboCmdInterface_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::AuboCmdInterface_Request & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::AuboCmdInterface_Request>()
{
  return "com_interfaces::srv::AuboCmdInterface_Request";
}

template<>
inline const char * name<com_interfaces::srv::AuboCmdInterface_Request>()
{
  return "com_interfaces/srv/AuboCmdInterface_Request";
}

template<>
struct has_fixed_size<com_interfaces::srv::AuboCmdInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::srv::AuboCmdInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::srv::AuboCmdInterface_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'pub_state'
#include "com_interfaces/msg/detail/aubo_robot_state__traits.hpp"
// Member 'ft'
#include "com_interfaces/msg/detail/force_torque__traits.hpp"

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AuboCmdInterface_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: err_code
  {
    out << "err_code: ";
    rosidl_generator_traits::value_to_yaml(msg.err_code, out);
    out << ", ";
  }

  // member: msg
  {
    out << "msg: ";
    rosidl_generator_traits::value_to_yaml(msg.msg, out);
    out << ", ";
  }

  // member: pub_state
  {
    out << "pub_state: ";
    to_flow_style_yaml(msg.pub_state, out);
    out << ", ";
  }

  // member: register_val
  {
    out << "register_val: ";
    rosidl_generator_traits::value_to_yaml(msg.register_val, out);
    out << ", ";
  }

  // member: io_val
  {
    out << "io_val: ";
    rosidl_generator_traits::value_to_yaml(msg.io_val, out);
    out << ", ";
  }

  // member: jt_pos
  {
    if (msg.jt_pos.size() == 0) {
      out << "jt_pos: []";
    } else {
      out << "jt_pos: [";
      size_t pending_items = msg.jt_pos.size();
      for (auto item : msg.jt_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tl_pos
  {
    if (msg.tl_pos.size() == 0) {
      out << "tl_pos: []";
    } else {
      out << "tl_pos: [";
      size_t pending_items = msg.tl_pos.size();
      for (auto item : msg.tl_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: ft
  {
    out << "ft: ";
    to_flow_style_yaml(msg.ft, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AuboCmdInterface_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: err_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "err_code: ";
    rosidl_generator_traits::value_to_yaml(msg.err_code, out);
    out << "\n";
  }

  // member: msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg: ";
    rosidl_generator_traits::value_to_yaml(msg.msg, out);
    out << "\n";
  }

  // member: pub_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pub_state:\n";
    to_block_style_yaml(msg.pub_state, out, indentation + 2);
  }

  // member: register_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "register_val: ";
    rosidl_generator_traits::value_to_yaml(msg.register_val, out);
    out << "\n";
  }

  // member: io_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "io_val: ";
    rosidl_generator_traits::value_to_yaml(msg.io_val, out);
    out << "\n";
  }

  // member: jt_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.jt_pos.size() == 0) {
      out << "jt_pos: []\n";
    } else {
      out << "jt_pos:\n";
      for (auto item : msg.jt_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tl_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tl_pos.size() == 0) {
      out << "tl_pos: []\n";
    } else {
      out << "tl_pos:\n";
      for (auto item : msg.tl_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: ft
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ft:\n";
    to_block_style_yaml(msg.ft, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AuboCmdInterface_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace com_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use com_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const com_interfaces::srv::AuboCmdInterface_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::AuboCmdInterface_Response & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::AuboCmdInterface_Response>()
{
  return "com_interfaces::srv::AuboCmdInterface_Response";
}

template<>
inline const char * name<com_interfaces::srv::AuboCmdInterface_Response>()
{
  return "com_interfaces/srv/AuboCmdInterface_Response";
}

template<>
struct has_fixed_size<com_interfaces::srv::AuboCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::srv::AuboCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::srv::AuboCmdInterface_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<com_interfaces::srv::AuboCmdInterface>()
{
  return "com_interfaces::srv::AuboCmdInterface";
}

template<>
inline const char * name<com_interfaces::srv::AuboCmdInterface>()
{
  return "com_interfaces/srv/AuboCmdInterface";
}

template<>
struct has_fixed_size<com_interfaces::srv::AuboCmdInterface>
  : std::integral_constant<
    bool,
    has_fixed_size<com_interfaces::srv::AuboCmdInterface_Request>::value &&
    has_fixed_size<com_interfaces::srv::AuboCmdInterface_Response>::value
  >
{
};

template<>
struct has_bounded_size<com_interfaces::srv::AuboCmdInterface>
  : std::integral_constant<
    bool,
    has_bounded_size<com_interfaces::srv::AuboCmdInterface_Request>::value &&
    has_bounded_size<com_interfaces::srv::AuboCmdInterface_Response>::value
  >
{
};

template<>
struct is_service<com_interfaces::srv::AuboCmdInterface>
  : std::true_type
{
};

template<>
struct is_service_request<com_interfaces::srv::AuboCmdInterface_Request>
  : std::true_type
{
};

template<>
struct is_service_response<com_interfaces::srv::AuboCmdInterface_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__SRV__DETAIL__AUBO_CMD_INTERFACE__TRAITS_HPP_
