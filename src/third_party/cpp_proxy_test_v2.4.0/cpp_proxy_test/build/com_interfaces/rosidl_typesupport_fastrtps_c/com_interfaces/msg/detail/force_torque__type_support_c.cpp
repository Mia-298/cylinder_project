// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:msg/ForceTorque.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/force_torque__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/msg/detail/force_torque__struct.h"
#include "com_interfaces/msg/detail/force_torque__functions.h"
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


// forward declare type support functions


using _ForceTorque__ros_msg_type = com_interfaces__msg__ForceTorque;

static bool _ForceTorque__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ForceTorque__ros_msg_type * ros_message = static_cast<const _ForceTorque__ros_msg_type *>(untyped_ros_message);
  // Field name: fx
  {
    cdr << ros_message->fx;
  }

  // Field name: fy
  {
    cdr << ros_message->fy;
  }

  // Field name: fz
  {
    cdr << ros_message->fz;
  }

  // Field name: tx
  {
    cdr << ros_message->tx;
  }

  // Field name: ty
  {
    cdr << ros_message->ty;
  }

  // Field name: tz
  {
    cdr << ros_message->tz;
  }

  return true;
}

static bool _ForceTorque__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ForceTorque__ros_msg_type * ros_message = static_cast<_ForceTorque__ros_msg_type *>(untyped_ros_message);
  // Field name: fx
  {
    cdr >> ros_message->fx;
  }

  // Field name: fy
  {
    cdr >> ros_message->fy;
  }

  // Field name: fz
  {
    cdr >> ros_message->fz;
  }

  // Field name: tx
  {
    cdr >> ros_message->tx;
  }

  // Field name: ty
  {
    cdr >> ros_message->ty;
  }

  // Field name: tz
  {
    cdr >> ros_message->tz;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__msg__ForceTorque(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ForceTorque__ros_msg_type * ros_message = static_cast<const _ForceTorque__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name fx
  {
    size_t item_size = sizeof(ros_message->fx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fy
  {
    size_t item_size = sizeof(ros_message->fy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fz
  {
    size_t item_size = sizeof(ros_message->fz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tx
  {
    size_t item_size = sizeof(ros_message->tx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ty
  {
    size_t item_size = sizeof(ros_message->ty);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tz
  {
    size_t item_size = sizeof(ros_message->tz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ForceTorque__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__msg__ForceTorque(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__msg__ForceTorque(
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

  // member: fx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: fy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: fz
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ty
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tz
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
    using DataType = com_interfaces__msg__ForceTorque;
    is_plain =
      (
      offsetof(DataType, tz) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ForceTorque__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__msg__ForceTorque(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ForceTorque = {
  "com_interfaces::msg",
  "ForceTorque",
  _ForceTorque__cdr_serialize,
  _ForceTorque__cdr_deserialize,
  _ForceTorque__get_serialized_size,
  _ForceTorque__max_serialized_size
};

static rosidl_message_type_support_t _ForceTorque__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ForceTorque,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, ForceTorque)() {
  return &_ForceTorque__type_support;
}

#if defined(__cplusplus)
}
#endif
