// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:srv/VisionEngineCmdInterface.idl
// generated code does not contain a copyright notice
#include "com_interfaces/srv/detail/vision_engine_cmd_interface__rosidl_typesupport_fastrtps_cpp.hpp"
#include "com_interfaces/srv/detail/vision_engine_cmd_interface__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace com_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_serialize(
  const com_interfaces::srv::VisionEngineCmdInterface_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: id
  cdr << ros_message.id;
  // Member: desc
  {
    cdr << ros_message.desc;
  }
  // Member: model_path
  cdr << ros_message.model_path;
  // Member: input_height
  cdr << ros_message.input_height;
  // Member: input_width
  cdr << ros_message.input_width;
  // Member: confidence_threshold
  cdr << ros_message.confidence_threshold;
  // Member: nms_threshold
  cdr << ros_message.nms_threshold;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  com_interfaces::srv::VisionEngineCmdInterface_Request & ros_message)
{
  // Member: id
  cdr >> ros_message.id;

  // Member: desc
  {
    cdr >> ros_message.desc;
  }

  // Member: model_path
  cdr >> ros_message.model_path;

  // Member: input_height
  cdr >> ros_message.input_height;

  // Member: input_width
  cdr >> ros_message.input_width;

  // Member: confidence_threshold
  cdr >> ros_message.confidence_threshold;

  // Member: nms_threshold
  cdr >> ros_message.nms_threshold;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
get_serialized_size(
  const com_interfaces::srv::VisionEngineCmdInterface_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: desc
  {
    size_t array_size = 6;
    size_t item_size = sizeof(ros_message.desc[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: model_path
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.model_path.size() + 1);
  // Member: input_height
  {
    size_t item_size = sizeof(ros_message.input_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: input_width
  {
    size_t item_size = sizeof(ros_message.input_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: confidence_threshold
  {
    size_t item_size = sizeof(ros_message.confidence_threshold);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: nms_threshold
  {
    size_t item_size = sizeof(ros_message.nms_threshold);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
max_serialized_size_VisionEngineCmdInterface_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: desc
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: model_path
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: input_height
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: input_width
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: confidence_threshold
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: nms_threshold
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = com_interfaces::srv::VisionEngineCmdInterface_Request;
    is_plain =
      (
      offsetof(DataType, nms_threshold) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _VisionEngineCmdInterface_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const com_interfaces::srv::VisionEngineCmdInterface_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _VisionEngineCmdInterface_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<com_interfaces::srv::VisionEngineCmdInterface_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _VisionEngineCmdInterface_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const com_interfaces::srv::VisionEngineCmdInterface_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _VisionEngineCmdInterface_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_VisionEngineCmdInterface_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _VisionEngineCmdInterface_Request__callbacks = {
  "com_interfaces::srv",
  "VisionEngineCmdInterface_Request",
  _VisionEngineCmdInterface_Request__cdr_serialize,
  _VisionEngineCmdInterface_Request__cdr_deserialize,
  _VisionEngineCmdInterface_Request__get_serialized_size,
  _VisionEngineCmdInterface_Request__max_serialized_size
};

static rosidl_message_type_support_t _VisionEngineCmdInterface_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_VisionEngineCmdInterface_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace com_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_com_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<com_interfaces::srv::VisionEngineCmdInterface_Request>()
{
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_VisionEngineCmdInterface_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, VisionEngineCmdInterface_Request)() {
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_VisionEngineCmdInterface_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace com_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const com_interfaces::msg::YoloResult &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  com_interfaces::msg::YoloResult &);
size_t get_serialized_size(
  const com_interfaces::msg::YoloResult &,
  size_t current_alignment);
size_t
max_serialized_size_YoloResult(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace com_interfaces

namespace com_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const com_interfaces::msg::SphereLoc &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  com_interfaces::msg::SphereLoc &);
size_t get_serialized_size(
  const com_interfaces::msg::SphereLoc &,
  size_t current_alignment);
size_t
max_serialized_size_SphereLoc(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_serialize(
  const com_interfaces::srv::VisionEngineCmdInterface_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: err_code
  cdr << ros_message.err_code;
  // Member: msg
  cdr << ros_message.msg;
  // Member: results
  {
    size_t size = ros_message.results.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      com_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.results[i],
        cdr);
    }
  }
  // Member: sphere_loc
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.sphere_loc,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  com_interfaces::srv::VisionEngineCmdInterface_Response & ros_message)
{
  // Member: err_code
  cdr >> ros_message.err_code;

  // Member: msg
  cdr >> ros_message.msg;

  // Member: results
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    ros_message.results.resize(size);
    for (size_t i = 0; i < size; i++) {
      com_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.results[i]);
    }
  }

  // Member: sphere_loc
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.sphere_loc);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
get_serialized_size(
  const com_interfaces::srv::VisionEngineCmdInterface_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: err_code
  {
    size_t item_size = sizeof(ros_message.err_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: msg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.msg.size() + 1);
  // Member: results
  {
    size_t array_size = ros_message.results.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        com_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.results[index], current_alignment);
    }
  }
  // Member: sphere_loc

  current_alignment +=
    com_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.sphere_loc, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
max_serialized_size_VisionEngineCmdInterface_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: err_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: msg
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: results
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        com_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_YoloResult(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: sphere_loc
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        com_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_SphereLoc(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = com_interfaces::srv::VisionEngineCmdInterface_Response;
    is_plain =
      (
      offsetof(DataType, sphere_loc) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _VisionEngineCmdInterface_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const com_interfaces::srv::VisionEngineCmdInterface_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _VisionEngineCmdInterface_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<com_interfaces::srv::VisionEngineCmdInterface_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _VisionEngineCmdInterface_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const com_interfaces::srv::VisionEngineCmdInterface_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _VisionEngineCmdInterface_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_VisionEngineCmdInterface_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _VisionEngineCmdInterface_Response__callbacks = {
  "com_interfaces::srv",
  "VisionEngineCmdInterface_Response",
  _VisionEngineCmdInterface_Response__cdr_serialize,
  _VisionEngineCmdInterface_Response__cdr_deserialize,
  _VisionEngineCmdInterface_Response__get_serialized_size,
  _VisionEngineCmdInterface_Response__max_serialized_size
};

static rosidl_message_type_support_t _VisionEngineCmdInterface_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_VisionEngineCmdInterface_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace com_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_com_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<com_interfaces::srv::VisionEngineCmdInterface_Response>()
{
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_VisionEngineCmdInterface_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, VisionEngineCmdInterface_Response)() {
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_VisionEngineCmdInterface_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace com_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _VisionEngineCmdInterface__callbacks = {
  "com_interfaces::srv",
  "VisionEngineCmdInterface",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, VisionEngineCmdInterface_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, VisionEngineCmdInterface_Response)(),
};

static rosidl_service_type_support_t _VisionEngineCmdInterface__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_VisionEngineCmdInterface__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace com_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_com_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<com_interfaces::srv::VisionEngineCmdInterface>()
{
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_VisionEngineCmdInterface__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, VisionEngineCmdInterface)() {
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_VisionEngineCmdInterface__handle;
}

#ifdef __cplusplus
}
#endif
