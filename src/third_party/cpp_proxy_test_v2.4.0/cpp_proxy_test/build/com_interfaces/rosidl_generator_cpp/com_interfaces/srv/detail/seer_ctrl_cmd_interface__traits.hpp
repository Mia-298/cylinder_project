// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:srv/SeerCtrlCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__TRAITS_HPP_
#define COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/srv/detail/seer_ctrl_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SeerCtrlCmdInterface_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: station
  {
    out << "station: ";
    rosidl_generator_traits::value_to_yaml(msg.station, out);
    out << ", ";
  }

  // member: station_list
  {
    if (msg.station_list.size() == 0) {
      out << "station_list: []";
    } else {
      out << "station_list: [";
      size_t pending_items = msg.station_list.size();
      for (auto item : msg.station_list) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: manual_x
  {
    out << "manual_x: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_x, out);
    out << ", ";
  }

  // member: manual_y
  {
    out << "manual_y: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_y, out);
    out << ", ";
  }

  // member: manual_w
  {
    out << "manual_w: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_w, out);
    out << ", ";
  }

  // member: manual_duration
  {
    out << "manual_duration: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_duration, out);
    out << ", ";
  }

  // member: nick_name
  {
    out << "nick_name: ";
    rosidl_generator_traits::value_to_yaml(msg.nick_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SeerCtrlCmdInterface_Request & msg,
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

  // member: station
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "station: ";
    rosidl_generator_traits::value_to_yaml(msg.station, out);
    out << "\n";
  }

  // member: station_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.station_list.size() == 0) {
      out << "station_list: []\n";
    } else {
      out << "station_list:\n";
      for (auto item : msg.station_list) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: manual_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "manual_x: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_x, out);
    out << "\n";
  }

  // member: manual_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "manual_y: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_y, out);
    out << "\n";
  }

  // member: manual_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "manual_w: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_w, out);
    out << "\n";
  }

  // member: manual_duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "manual_duration: ";
    rosidl_generator_traits::value_to_yaml(msg.manual_duration, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SeerCtrlCmdInterface_Request & msg, bool use_flow_style = false)
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
  const com_interfaces::srv::SeerCtrlCmdInterface_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::SeerCtrlCmdInterface_Request & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::SeerCtrlCmdInterface_Request>()
{
  return "com_interfaces::srv::SeerCtrlCmdInterface_Request";
}

template<>
inline const char * name<com_interfaces::srv::SeerCtrlCmdInterface_Request>()
{
  return "com_interfaces/srv/SeerCtrlCmdInterface_Request";
}

template<>
struct has_fixed_size<com_interfaces::srv::SeerCtrlCmdInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::srv::SeerCtrlCmdInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::srv::SeerCtrlCmdInterface_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'guide_state'
#include "com_interfaces/msg/detail/agv_guide_state__traits.hpp"
// Member 'control'
#include "com_interfaces/msg/detail/agv_control__traits.hpp"
// Member 'loc'
#include "com_interfaces/msg/detail/agv_loc__traits.hpp"
// Member 'current_station'
// Member 'station_list'
#include "com_interfaces/msg/detail/agv_station__traits.hpp"

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SeerCtrlCmdInterface_Response & msg,
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
    out << ", ";
  }

  // member: loc
  {
    out << "loc: ";
    to_flow_style_yaml(msg.loc, out);
    out << ", ";
  }

  // member: current_station
  {
    out << "current_station: ";
    to_flow_style_yaml(msg.current_station, out);
    out << ", ";
  }

  // member: station_list
  {
    if (msg.station_list.size() == 0) {
      out << "station_list: []";
    } else {
      out << "station_list: [";
      size_t pending_items = msg.station_list.size();
      for (auto item : msg.station_list) {
        to_flow_style_yaml(item, out);
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
  const SeerCtrlCmdInterface_Response & msg,
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

  // member: loc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "loc:\n";
    to_block_style_yaml(msg.loc, out, indentation + 2);
  }

  // member: current_station
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_station:\n";
    to_block_style_yaml(msg.current_station, out, indentation + 2);
  }

  // member: station_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.station_list.size() == 0) {
      out << "station_list: []\n";
    } else {
      out << "station_list:\n";
      for (auto item : msg.station_list) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SeerCtrlCmdInterface_Response & msg, bool use_flow_style = false)
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
  const com_interfaces::srv::SeerCtrlCmdInterface_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::SeerCtrlCmdInterface_Response & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::SeerCtrlCmdInterface_Response>()
{
  return "com_interfaces::srv::SeerCtrlCmdInterface_Response";
}

template<>
inline const char * name<com_interfaces::srv::SeerCtrlCmdInterface_Response>()
{
  return "com_interfaces/srv/SeerCtrlCmdInterface_Response";
}

template<>
struct has_fixed_size<com_interfaces::srv::SeerCtrlCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::srv::SeerCtrlCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::srv::SeerCtrlCmdInterface_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<com_interfaces::srv::SeerCtrlCmdInterface>()
{
  return "com_interfaces::srv::SeerCtrlCmdInterface";
}

template<>
inline const char * name<com_interfaces::srv::SeerCtrlCmdInterface>()
{
  return "com_interfaces/srv/SeerCtrlCmdInterface";
}

template<>
struct has_fixed_size<com_interfaces::srv::SeerCtrlCmdInterface>
  : std::integral_constant<
    bool,
    has_fixed_size<com_interfaces::srv::SeerCtrlCmdInterface_Request>::value &&
    has_fixed_size<com_interfaces::srv::SeerCtrlCmdInterface_Response>::value
  >
{
};

template<>
struct has_bounded_size<com_interfaces::srv::SeerCtrlCmdInterface>
  : std::integral_constant<
    bool,
    has_bounded_size<com_interfaces::srv::SeerCtrlCmdInterface_Request>::value &&
    has_bounded_size<com_interfaces::srv::SeerCtrlCmdInterface_Response>::value
  >
{
};

template<>
struct is_service<com_interfaces::srv::SeerCtrlCmdInterface>
  : std::true_type
{
};

template<>
struct is_service_request<com_interfaces::srv::SeerCtrlCmdInterface_Request>
  : std::true_type
{
};

template<>
struct is_service_response<com_interfaces::srv::SeerCtrlCmdInterface_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__TRAITS_HPP_
