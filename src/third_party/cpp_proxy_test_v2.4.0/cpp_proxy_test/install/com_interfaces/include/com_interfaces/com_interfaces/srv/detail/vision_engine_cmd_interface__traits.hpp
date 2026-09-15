// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from com_interfaces:srv/VisionEngineCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__TRAITS_HPP_
#define COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "com_interfaces/srv/detail/vision_engine_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const VisionEngineCmdInterface_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: desc
  {
    if (msg.desc.size() == 0) {
      out << "desc: []";
    } else {
      out << "desc: [";
      size_t pending_items = msg.desc.size();
      for (auto item : msg.desc) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: model_path
  {
    out << "model_path: ";
    rosidl_generator_traits::value_to_yaml(msg.model_path, out);
    out << ", ";
  }

  // member: input_height
  {
    out << "input_height: ";
    rosidl_generator_traits::value_to_yaml(msg.input_height, out);
    out << ", ";
  }

  // member: input_width
  {
    out << "input_width: ";
    rosidl_generator_traits::value_to_yaml(msg.input_width, out);
    out << ", ";
  }

  // member: confidence_threshold
  {
    out << "confidence_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence_threshold, out);
    out << ", ";
  }

  // member: nms_threshold
  {
    out << "nms_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.nms_threshold, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VisionEngineCmdInterface_Request & msg,
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

  // member: desc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.desc.size() == 0) {
      out << "desc: []\n";
    } else {
      out << "desc:\n";
      for (auto item : msg.desc) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: model_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "model_path: ";
    rosidl_generator_traits::value_to_yaml(msg.model_path, out);
    out << "\n";
  }

  // member: input_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_height: ";
    rosidl_generator_traits::value_to_yaml(msg.input_height, out);
    out << "\n";
  }

  // member: input_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_width: ";
    rosidl_generator_traits::value_to_yaml(msg.input_width, out);
    out << "\n";
  }

  // member: confidence_threshold
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence_threshold, out);
    out << "\n";
  }

  // member: nms_threshold
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nms_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.nms_threshold, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VisionEngineCmdInterface_Request & msg, bool use_flow_style = false)
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
  const com_interfaces::srv::VisionEngineCmdInterface_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::VisionEngineCmdInterface_Request & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::VisionEngineCmdInterface_Request>()
{
  return "com_interfaces::srv::VisionEngineCmdInterface_Request";
}

template<>
inline const char * name<com_interfaces::srv::VisionEngineCmdInterface_Request>()
{
  return "com_interfaces/srv/VisionEngineCmdInterface_Request";
}

template<>
struct has_fixed_size<com_interfaces::srv::VisionEngineCmdInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::srv::VisionEngineCmdInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::srv::VisionEngineCmdInterface_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'results'
#include "com_interfaces/msg/detail/yolo_result__traits.hpp"
// Member 'sphere_loc'
#include "com_interfaces/msg/detail/sphere_loc__traits.hpp"

namespace com_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const VisionEngineCmdInterface_Response & msg,
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

  // member: results
  {
    if (msg.results.size() == 0) {
      out << "results: []";
    } else {
      out << "results: [";
      size_t pending_items = msg.results.size();
      for (auto item : msg.results) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: sphere_loc
  {
    out << "sphere_loc: ";
    to_flow_style_yaml(msg.sphere_loc, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VisionEngineCmdInterface_Response & msg,
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

  // member: results
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.results.size() == 0) {
      out << "results: []\n";
    } else {
      out << "results:\n";
      for (auto item : msg.results) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: sphere_loc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sphere_loc:\n";
    to_block_style_yaml(msg.sphere_loc, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VisionEngineCmdInterface_Response & msg, bool use_flow_style = false)
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
  const com_interfaces::srv::VisionEngineCmdInterface_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  com_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use com_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const com_interfaces::srv::VisionEngineCmdInterface_Response & msg)
{
  return com_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<com_interfaces::srv::VisionEngineCmdInterface_Response>()
{
  return "com_interfaces::srv::VisionEngineCmdInterface_Response";
}

template<>
inline const char * name<com_interfaces::srv::VisionEngineCmdInterface_Response>()
{
  return "com_interfaces/srv/VisionEngineCmdInterface_Response";
}

template<>
struct has_fixed_size<com_interfaces::srv::VisionEngineCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<com_interfaces::srv::VisionEngineCmdInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<com_interfaces::srv::VisionEngineCmdInterface_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<com_interfaces::srv::VisionEngineCmdInterface>()
{
  return "com_interfaces::srv::VisionEngineCmdInterface";
}

template<>
inline const char * name<com_interfaces::srv::VisionEngineCmdInterface>()
{
  return "com_interfaces/srv/VisionEngineCmdInterface";
}

template<>
struct has_fixed_size<com_interfaces::srv::VisionEngineCmdInterface>
  : std::integral_constant<
    bool,
    has_fixed_size<com_interfaces::srv::VisionEngineCmdInterface_Request>::value &&
    has_fixed_size<com_interfaces::srv::VisionEngineCmdInterface_Response>::value
  >
{
};

template<>
struct has_bounded_size<com_interfaces::srv::VisionEngineCmdInterface>
  : std::integral_constant<
    bool,
    has_bounded_size<com_interfaces::srv::VisionEngineCmdInterface_Request>::value &&
    has_bounded_size<com_interfaces::srv::VisionEngineCmdInterface_Response>::value
  >
{
};

template<>
struct is_service<com_interfaces::srv::VisionEngineCmdInterface>
  : std::true_type
{
};

template<>
struct is_service_request<com_interfaces::srv::VisionEngineCmdInterface_Request>
  : std::true_type
{
};

template<>
struct is_service_response<com_interfaces::srv::VisionEngineCmdInterface_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__TRAITS_HPP_
