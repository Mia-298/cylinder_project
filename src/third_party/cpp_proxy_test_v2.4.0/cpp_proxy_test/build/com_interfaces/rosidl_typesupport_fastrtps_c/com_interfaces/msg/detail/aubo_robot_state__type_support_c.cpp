// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:msg/AuboRobotState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/aubo_robot_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/msg/detail/aubo_robot_state__struct.h"
#include "com_interfaces/msg/detail/aubo_robot_state__functions.h"
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

#include "rosidl_runtime_c/string.h"  // robot_ip, robot_name, robot_soft_index, robot_type
#include "rosidl_runtime_c/string_functions.h"  // robot_ip, robot_name, robot_soft_index, robot_type

// forward declare type support functions


using _AuboRobotState__ros_msg_type = com_interfaces__msg__AuboRobotState;

static bool _AuboRobotState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AuboRobotState__ros_msg_type * ros_message = static_cast<const _AuboRobotState__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_index
  {
    cdr << ros_message->robot_index;
  }

  // Field name: robot_name
  {
    const rosidl_runtime_c__String * str = &ros_message->robot_name;
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

  // Field name: robot_type
  {
    const rosidl_runtime_c__String * str = &ros_message->robot_type;
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

  // Field name: robot_soft_index
  {
    const rosidl_runtime_c__String * str = &ros_message->robot_soft_index;
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

  // Field name: robot_ip
  {
    const rosidl_runtime_c__String * str = &ros_message->robot_ip;
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

  // Field name: mode_type
  {
    cdr << ros_message->mode_type;
  }

  // Field name: safety_mode_type
  {
    cdr << ros_message->safety_mode_type;
  }

  // Field name: robot_speed
  {
    cdr << ros_message->robot_speed;
  }

  // Field name: jt_cur_pos
  {
    size_t size = 6;
    auto array_ptr = ros_message->jt_cur_pos;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tl_cur_pos
  {
    size_t size = 6;
    auto array_ptr = ros_message->tl_cur_pos;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _AuboRobotState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AuboRobotState__ros_msg_type * ros_message = static_cast<_AuboRobotState__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_index
  {
    cdr >> ros_message->robot_index;
  }

  // Field name: robot_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->robot_name.data) {
      rosidl_runtime_c__String__init(&ros_message->robot_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->robot_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'robot_name'\n");
      return false;
    }
  }

  // Field name: robot_type
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->robot_type.data) {
      rosidl_runtime_c__String__init(&ros_message->robot_type);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->robot_type,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'robot_type'\n");
      return false;
    }
  }

  // Field name: robot_soft_index
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->robot_soft_index.data) {
      rosidl_runtime_c__String__init(&ros_message->robot_soft_index);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->robot_soft_index,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'robot_soft_index'\n");
      return false;
    }
  }

  // Field name: robot_ip
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->robot_ip.data) {
      rosidl_runtime_c__String__init(&ros_message->robot_ip);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->robot_ip,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'robot_ip'\n");
      return false;
    }
  }

  // Field name: mode_type
  {
    cdr >> ros_message->mode_type;
  }

  // Field name: safety_mode_type
  {
    cdr >> ros_message->safety_mode_type;
  }

  // Field name: robot_speed
  {
    cdr >> ros_message->robot_speed;
  }

  // Field name: jt_cur_pos
  {
    size_t size = 6;
    auto array_ptr = ros_message->jt_cur_pos;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tl_cur_pos
  {
    size_t size = 6;
    auto array_ptr = ros_message->tl_cur_pos;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__msg__AuboRobotState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AuboRobotState__ros_msg_type * ros_message = static_cast<const _AuboRobotState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name robot_index
  {
    size_t item_size = sizeof(ros_message->robot_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->robot_name.size + 1);
  // field.name robot_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->robot_type.size + 1);
  // field.name robot_soft_index
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->robot_soft_index.size + 1);
  // field.name robot_ip
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->robot_ip.size + 1);
  // field.name mode_type
  {
    size_t item_size = sizeof(ros_message->mode_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name safety_mode_type
  {
    size_t item_size = sizeof(ros_message->safety_mode_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_speed
  {
    size_t item_size = sizeof(ros_message->robot_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name jt_cur_pos
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->jt_cur_pos;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tl_cur_pos
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->tl_cur_pos;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AuboRobotState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__msg__AuboRobotState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__msg__AuboRobotState(
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

  // member: robot_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: robot_name
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
  // member: robot_type
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
  // member: robot_soft_index
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
  // member: robot_ip
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
  // member: mode_type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: safety_mode_type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: robot_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: jt_cur_pos
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tl_cur_pos
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = com_interfaces__msg__AuboRobotState;
    is_plain =
      (
      offsetof(DataType, tl_cur_pos) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _AuboRobotState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__msg__AuboRobotState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AuboRobotState = {
  "com_interfaces::msg",
  "AuboRobotState",
  _AuboRobotState__cdr_serialize,
  _AuboRobotState__cdr_deserialize,
  _AuboRobotState__get_serialized_size,
  _AuboRobotState__max_serialized_size
};

static rosidl_message_type_support_t _AuboRobotState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AuboRobotState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, AuboRobotState)() {
  return &_AuboRobotState__type_support;
}

#if defined(__cplusplus)
}
#endif
