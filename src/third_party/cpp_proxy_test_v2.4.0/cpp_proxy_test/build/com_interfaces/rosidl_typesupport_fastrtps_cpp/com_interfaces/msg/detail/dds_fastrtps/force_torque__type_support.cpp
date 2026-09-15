// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:msg/ForceTorque.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/force_torque__rosidl_typesupport_fastrtps_cpp.hpp"
#include "com_interfaces/msg/detail/force_torque__struct.hpp"

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

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_serialize(
  const com_interfaces::msg::ForceTorque & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: fx
  cdr << ros_message.fx;
  // Member: fy
  cdr << ros_message.fy;
  // Member: fz
  cdr << ros_message.fz;
  // Member: tx
  cdr << ros_message.tx;
  // Member: ty
  cdr << ros_message.ty;
  // Member: tz
  cdr << ros_message.tz;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  com_interfaces::msg::ForceTorque & ros_message)
{
  // Member: fx
  cdr >> ros_message.fx;

  // Member: fy
  cdr >> ros_message.fy;

  // Member: fz
  cdr >> ros_message.fz;

  // Member: tx
  cdr >> ros_message.tx;

  // Member: ty
  cdr >> ros_message.ty;

  // Member: tz
  cdr >> ros_message.tz;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
get_serialized_size(
  const com_interfaces::msg::ForceTorque & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: fx
  {
    size_t item_size = sizeof(ros_message.fx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fy
  {
    size_t item_size = sizeof(ros_message.fy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fz
  {
    size_t item_size = sizeof(ros_message.fz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tx
  {
    size_t item_size = sizeof(ros_message.tx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ty
  {
    size_t item_size = sizeof(ros_message.ty);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tz
  {
    size_t item_size = sizeof(ros_message.tz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
max_serialized_size_ForceTorque(
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


  // Member: fx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: fy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: fz
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tx
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ty
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tz
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
    using DataType = com_interfaces::msg::ForceTorque;
    is_plain =
      (
      offsetof(DataType, tz) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ForceTorque__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const com_interfaces::msg::ForceTorque *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ForceTorque__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<com_interfaces::msg::ForceTorque *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ForceTorque__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const com_interfaces::msg::ForceTorque *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ForceTorque__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ForceTorque(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ForceTorque__callbacks = {
  "com_interfaces::msg",
  "ForceTorque",
  _ForceTorque__cdr_serialize,
  _ForceTorque__cdr_deserialize,
  _ForceTorque__get_serialized_size,
  _ForceTorque__max_serialized_size
};

static rosidl_message_type_support_t _ForceTorque__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ForceTorque__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace com_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_com_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<com_interfaces::msg::ForceTorque>()
{
  return &com_interfaces::msg::typesupport_fastrtps_cpp::_ForceTorque__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, msg, ForceTorque)() {
  return &com_interfaces::msg::typesupport_fastrtps_cpp::_ForceTorque__handle;
}

#ifdef __cplusplus
}
#endif
