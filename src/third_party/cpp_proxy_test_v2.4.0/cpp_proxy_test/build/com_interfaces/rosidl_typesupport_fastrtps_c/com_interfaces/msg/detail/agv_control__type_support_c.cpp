// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:msg/AgvControl.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/agv_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/msg/detail/agv_control__struct.h"
#include "com_interfaces/msg/detail/agv_control__functions.h"
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

#include "rosidl_runtime_c/string.h"  // desc, ip, nick_name
#include "rosidl_runtime_c/string_functions.h"  // desc, ip, nick_name

// forward declare type support functions


using _AgvControl__ros_msg_type = com_interfaces__msg__AgvControl;

static bool _AgvControl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AgvControl__ros_msg_type * ros_message = static_cast<const _AgvControl__ros_msg_type *>(untyped_ros_message);
  // Field name: locked
  {
    cdr << (ros_message->locked ? true : false);
  }

  // Field name: ip
  {
    const rosidl_runtime_c__String * str = &ros_message->ip;
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

  // Field name: port
  {
    cdr << ros_message->port;
  }

  // Field name: type
  {
    cdr << ros_message->type;
  }

  // Field name: nick_name
  {
    const rosidl_runtime_c__String * str = &ros_message->nick_name;
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

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: desc
  {
    const rosidl_runtime_c__String * str = &ros_message->desc;
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

  return true;
}

static bool _AgvControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AgvControl__ros_msg_type * ros_message = static_cast<_AgvControl__ros_msg_type *>(untyped_ros_message);
  // Field name: locked
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->locked = tmp ? true : false;
  }

  // Field name: ip
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->ip.data) {
      rosidl_runtime_c__String__init(&ros_message->ip);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->ip,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'ip'\n");
      return false;
    }
  }

  // Field name: port
  {
    cdr >> ros_message->port;
  }

  // Field name: type
  {
    cdr >> ros_message->type;
  }

  // Field name: nick_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->nick_name.data) {
      rosidl_runtime_c__String__init(&ros_message->nick_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->nick_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'nick_name'\n");
      return false;
    }
  }

  // Field name: time
  {
    cdr >> ros_message->time;
  }

  // Field name: desc
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->desc.data) {
      rosidl_runtime_c__String__init(&ros_message->desc);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->desc,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'desc'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__msg__AgvControl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AgvControl__ros_msg_type * ros_message = static_cast<const _AgvControl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name locked
  {
    size_t item_size = sizeof(ros_message->locked);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ip
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ip.size + 1);
  // field.name port
  {
    size_t item_size = sizeof(ros_message->port);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name type
  {
    size_t item_size = sizeof(ros_message->type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nick_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->nick_name.size + 1);
  // field.name time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name desc
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->desc.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _AgvControl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__msg__AgvControl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__msg__AgvControl(
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

  // member: locked
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ip
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
  // member: port
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: nick_name
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
  // member: time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: desc
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

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = com_interfaces__msg__AgvControl;
    is_plain =
      (
      offsetof(DataType, desc) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _AgvControl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__msg__AgvControl(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AgvControl = {
  "com_interfaces::msg",
  "AgvControl",
  _AgvControl__cdr_serialize,
  _AgvControl__cdr_deserialize,
  _AgvControl__get_serialized_size,
  _AgvControl__max_serialized_size
};

static rosidl_message_type_support_t _AgvControl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AgvControl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvControl)() {
  return &_AgvControl__type_support;
}

#if defined(__cplusplus)
}
#endif
