// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:srv/VirtAgvCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__VIRT_AGV_CMD_INTERFACE__TRAITS_HPP_
#define COM_INTERFACES__SRV__DETAIL__VIRT_AGV_CMD_INTERFACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const VirtAgvCmdInterface_Request & msg,
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VirtAgvCmdInterface_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VirtAgvCmdInterface_Request & msg, bool use_flow_style = false)
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
  const com_interfaces::srv::VirtAgvCmdInterface_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::VirtAgvCmdInterface_Request & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::VirtAgvCmdInterface_Request>()
{
  return "com_interfaces::srv::VirtAgvCmdInterface_Request";
}

template<>
inline const char * name<com_interfaces::srv::VirtAgvCmdInterface_Request>()
{
  return "com_interfaces/srv/VirtAgvCmdInterface_Request";
}

template<>
struct has_fixed_size<com_interfaces::srv::VirtAgvCmdInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::srv::VirtAgvCmdInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::srv::VirtAgvCmdInterface_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'current_station'
// Member 'station_list'
#include "com_interfaces/msg/detail/agv_station__traits.hpp"

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const VirtAgvCmdInterface_Response & msg,
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
  const VirtAgvCmdInterface_Response & msg,
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

inline std::string to_yaml(const VirtAgvCmdInterface_Response & msg, bool use_flow_style = false)
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
  const com_interfaces::srv::VirtAgvCmdInterface_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::VirtAgvCmdInterface_Response & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::VirtAgvCmdInterface_Response>()
{
  return "com_interfaces::srv::VirtAgvCmdInterface_Response";
}

template<>
inline const char * name<com_interfaces::srv::VirtAgvCmdInterface_Response>()
{
  return "com_interfaces/srv/VirtAgvCmdInterface_Response";
}

template<>
struct has_fixed_size<com_interfaces::srv::VirtAgvCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::srv::VirtAgvCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::srv::VirtAgvCmdInterface_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<com_interfaces::srv::VirtAgvCmdInterface>()
{
  return "com_interfaces::srv::VirtAgvCmdInterface";
}

template<>
inline const char * name<com_interfaces::srv::VirtAgvCmdInterface>()
{
  return "com_interfaces/srv/VirtAgvCmdInterface";
}

template<>
struct has_fixed_size<com_interfaces::srv::VirtAgvCmdInterface>
  : std::integral_constant<
    bool,
    has_fixed_size<com_interfaces::srv::VirtAgvCmdInterface_Request>::value &&
    has_fixed_size<com_interfaces::srv::VirtAgvCmdInterface_Response>::value
  >
{
};

template<>
struct has_bounded_size<com_interfaces::srv::VirtAgvCmdInterface>
  : std::integral_constant<
    bool,
    has_bounded_size<com_interfaces::srv::VirtAgvCmdInterface_Request>::value &&
    has_bounded_size<com_interfaces::srv::VirtAgvCmdInterface_Response>::value
  >
{
};

template<>
struct is_service<com_interfaces::srv::VirtAgvCmdInterface>
  : std::true_type
{
};

template<>
struct is_service_request<com_interfaces::srv::VirtAgvCmdInterface_Request>
  : std::true_type
{
};

template<>
struct is_service_response<com_interfaces::srv::VirtAgvCmdInterface_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__SRV__DETAIL__VIRT_AGV_CMD_INTERFACE__TRAITS_HPP_
