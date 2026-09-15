// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:srv/RealsenseCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__REALSENSE_CMD_INTERFACE__TRAITS_HPP_
#define COM_INTERFACES__SRV__DETAIL__REALSENSE_CMD_INTERFACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/srv/detail/realsense_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RealsenseCmdInterface_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RealsenseCmdInterface_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RealsenseCmdInterface_Request & msg, bool use_flow_style = false)
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
  const com_interfaces::srv::RealsenseCmdInterface_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::RealsenseCmdInterface_Request & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::RealsenseCmdInterface_Request>()
{
  return "com_interfaces::srv::RealsenseCmdInterface_Request";
}

template<>
inline const char * name<com_interfaces::srv::RealsenseCmdInterface_Request>()
{
  return "com_interfaces/srv/RealsenseCmdInterface_Request";
}

template<>
struct has_fixed_size<com_interfaces::srv::RealsenseCmdInterface_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<com_interfaces::srv::RealsenseCmdInterface_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<com_interfaces::srv::RealsenseCmdInterface_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RealsenseCmdInterface_Response & msg,
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RealsenseCmdInterface_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RealsenseCmdInterface_Response & msg, bool use_flow_style = false)
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
  const com_interfaces::srv::RealsenseCmdInterface_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::RealsenseCmdInterface_Response & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::RealsenseCmdInterface_Response>()
{
  return "com_interfaces::srv::RealsenseCmdInterface_Response";
}

template<>
inline const char * name<com_interfaces::srv::RealsenseCmdInterface_Response>()
{
  return "com_interfaces/srv/RealsenseCmdInterface_Response";
}

template<>
struct has_fixed_size<com_interfaces::srv::RealsenseCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::srv::RealsenseCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::srv::RealsenseCmdInterface_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<com_interfaces::srv::RealsenseCmdInterface>()
{
  return "com_interfaces::srv::RealsenseCmdInterface";
}

template<>
inline const char * name<com_interfaces::srv::RealsenseCmdInterface>()
{
  return "com_interfaces/srv/RealsenseCmdInterface";
}

template<>
struct has_fixed_size<com_interfaces::srv::RealsenseCmdInterface>
  : std::integral_constant<
    bool,
    has_fixed_size<com_interfaces::srv::RealsenseCmdInterface_Request>::value &&
    has_fixed_size<com_interfaces::srv::RealsenseCmdInterface_Response>::value
  >
{
};

template<>
struct has_bounded_size<com_interfaces::srv::RealsenseCmdInterface>
  : std::integral_constant<
    bool,
    has_bounded_size<com_interfaces::srv::RealsenseCmdInterface_Request>::value &&
    has_bounded_size<com_interfaces::srv::RealsenseCmdInterface_Response>::value
  >
{
};

template<>
struct is_service<com_interfaces::srv::RealsenseCmdInterface>
  : std::true_type
{
};

template<>
struct is_service_request<com_interfaces::srv::RealsenseCmdInterface_Request>
  : std::true_type
{
};

template<>
struct is_service_response<com_interfaces::srv::RealsenseCmdInterface_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__SRV__DETAIL__REALSENSE_CMD_INTERFACE__TRAITS_HPP_
