// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:msg/RealsenseState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/realsense_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/msg/detail/realsense_state__struct.h"
#include "com_interfaces/msg/detail/realsense_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // aligned_depth_topic, color_info_topic, color_topic, depth_info_topic, depth_topic, err_msg, name
#include "rosidl_runtime_c/string_functions.h"  // aligned_depth_topic, color_info_topic, color_topic, depth_info_topic, depth_topic, err_msg, name

// forward declare type support functions


using _RealsenseState__ros_msg_type = com_interfaces__msg__RealsenseState;

static bool _RealsenseState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RealsenseState__ros_msg_type * ros_message = static_cast<const _RealsenseState__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: err_code
  {
    cdr << ros_message->err_code;
  }

  // Field name: err_msg
  {
    const rosidl_runtime_c__String * str = &ros_message->err_msg;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: node_online
  {
    cdr << (ros_message->node_online ? true : false);
  }

  // Field name: color_ready
  {
    cdr << (ros_message->color_ready ? true : false);
  }

  // Field name: depth_ready
  {
    cdr << (ros_message->depth_ready ? true : false);
  }

  // Field name: aligned_depth_ready
  {
    cdr << (ros_message->aligned_depth_ready ? true : false);
  }

  // Field name: color_info_ready
  {
    cdr << (ros_message->color_info_ready ? true : false);
  }

  // Field name: depth_info_ready
  {
    cdr << (ros_message->depth_info_ready ? true : false);
  }

  // Field name: color_topic
  {
    const rosidl_runtime_c__String * str = &ros_message->color_topic;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: depth_topic
  {
    const rosidl_runtime_c__String * str = &ros_message->depth_topic;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: aligned_depth_topic
  {
    const rosidl_runtime_c__String * str = &ros_message->aligned_depth_topic;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: color_info_topic
  {
    const rosidl_runtime_c__String * str = &ros_message->color_info_topic;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: depth_info_topic
  {
    const rosidl_runtime_c__String * str = &ros_message->depth_info_topic;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: last_color_ts_ms
  {
    cdr << ros_message->last_color_ts_ms;
  }

  // Field name: last_depth_ts_ms
  {
    cdr << ros_message->last_depth_ts_ms;
  }

  // Field name: last_aligned_depth_ts_ms
  {
    cdr << ros_message->last_aligned_depth_ts_ms;
  }

  // Field name: last_color_info_ts_ms
  {
    cdr << ros_message->last_color_info_ts_ms;
  }

  // Field name: last_depth_info_ts_ms
  {
    cdr << ros_message->last_depth_info_ts_ms;
  }

  return true;
}

static bool _RealsenseState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RealsenseState__ros_msg_type * ros_message = static_cast<_RealsenseState__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: err_code
  {
    cdr >> ros_message->err_code;
  }

  // Field name: err_msg
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->err_msg.data) {
      rosidl_runtime_c__String__init(&ros_message->err_msg);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->err_msg,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'err_msg'\n");
      return false;
    }
  }

  // Field name: node_online
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->node_online = tmp ? true : false;
  }

  // Field name: color_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->color_ready = tmp ? true : false;
  }

  // Field name: depth_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->depth_ready = tmp ? true : false;
  }

  // Field name: aligned_depth_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->aligned_depth_ready = tmp ? true : false;
  }

  // Field name: color_info_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->color_info_ready = tmp ? true : false;
  }

  // Field name: depth_info_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->depth_info_ready = tmp ? true : false;
  }

  // Field name: color_topic
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->color_topic.data) {
      rosidl_runtime_c__String__init(&ros_message->color_topic);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->color_topic,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'color_topic'\n");
      return false;
    }
  }

  // Field name: depth_topic
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->depth_topic.data) {
      rosidl_runtime_c__String__init(&ros_message->depth_topic);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->depth_topic,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'depth_topic'\n");
      return false;
    }
  }

  // Field name: aligned_depth_topic
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->aligned_depth_topic.data) {
      rosidl_runtime_c__String__init(&ros_message->aligned_depth_topic);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->aligned_depth_topic,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'aligned_depth_topic'\n");
      return false;
    }
  }

  // Field name: color_info_topic
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->color_info_topic.data) {
      rosidl_runtime_c__String__init(&ros_message->color_info_topic);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->color_info_topic,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'color_info_topic'\n");
      return false;
    }
  }

  // Field name: depth_info_topic
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->depth_info_topic.data) {
      rosidl_runtime_c__String__init(&ros_message->depth_info_topic);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->depth_info_topic,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'depth_info_topic'\n");
      return false;
    }
  }

  // Field name: last_color_ts_ms
  {
    cdr >> ros_message->last_color_ts_ms;
  }

  // Field name: last_depth_ts_ms
  {
    cdr >> ros_message->last_depth_ts_ms;
  }

  // Field name: last_aligned_depth_ts_ms
  {
    cdr >> ros_message->last_aligned_depth_ts_ms;
  }

  // Field name: last_color_info_ts_ms
  {
    cdr >> ros_message->last_color_info_ts_ms;
  }

  // Field name: last_depth_info_ts_ms
  {
    cdr >> ros_message->last_depth_info_ts_ms;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__msg__RealsenseState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RealsenseState__ros_msg_type * ros_message = static_cast<const _RealsenseState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);
  // field.name err_code
  {
    size_t item_size = sizeof(ros_message->err_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name err_msg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->err_msg.size + 1);
  // field.name node_online
  {
    size_t item_size = sizeof(ros_message->node_online);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name color_ready
  {
    size_t item_size = sizeof(ros_message->color_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name depth_ready
  {
    size_t item_size = sizeof(ros_message->depth_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name aligned_depth_ready
  {
    size_t item_size = sizeof(ros_message->aligned_depth_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name color_info_ready
  {
    size_t item_size = sizeof(ros_message->color_info_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name depth_info_ready
  {
    size_t item_size = sizeof(ros_message->depth_info_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name color_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->color_topic.size + 1);
  // field.name depth_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->depth_topic.size + 1);
  // field.name aligned_depth_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->aligned_depth_topic.size + 1);
  // field.name color_info_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->color_info_topic.size + 1);
  // field.name depth_info_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->depth_info_topic.size + 1);
  // field.name last_color_ts_ms
  {
    size_t item_size = sizeof(ros_message->last_color_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name last_depth_ts_ms
  {
    size_t item_size = sizeof(ros_message->last_depth_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name last_aligned_depth_ts_ms
  {
    size_t item_size = sizeof(ros_message->last_aligned_depth_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name last_color_info_ts_ms
  {
    size_t item_size = sizeof(ros_message->last_color_info_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name last_depth_info_ts_ms
  {
    size_t item_size = sizeof(ros_message->last_depth_info_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RealsenseState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__msg__RealsenseState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__msg__RealsenseState(
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

  // member: name
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
  // member: err_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: err_msg
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
  // member: node_online
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: color_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: depth_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: aligned_depth_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: color_info_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: depth_info_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: color_topic
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
  // member: depth_topic
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
  // member: aligned_depth_topic
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
  // member: color_info_topic
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
  // member: depth_info_topic
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
  // member: last_color_ts_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: last_depth_ts_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: last_aligned_depth_ts_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: last_color_info_ts_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: last_depth_info_ts_ms
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
    using DataType = com_interfaces__msg__RealsenseState;
    is_plain =
      (
      offsetof(DataType, last_depth_info_ts_ms) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RealsenseState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__msg__RealsenseState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RealsenseState = {
  "com_interfaces::msg",
  "RealsenseState",
  _RealsenseState__cdr_serialize,
  _RealsenseState__cdr_deserialize,
  _RealsenseState__get_serialized_size,
  _RealsenseState__max_serialized_size
};

static rosidl_message_type_support_t _RealsenseState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RealsenseState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, RealsenseState)() {
  return &_RealsenseState__type_support;
}

#if defined(__cplusplus)
}
#endif
