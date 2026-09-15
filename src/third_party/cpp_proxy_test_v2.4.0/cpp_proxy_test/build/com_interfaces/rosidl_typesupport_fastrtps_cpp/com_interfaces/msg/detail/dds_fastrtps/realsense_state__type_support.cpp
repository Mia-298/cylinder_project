// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:msg/RealsenseState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/realsense_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "com_interfaces/msg/detail/realsense_state__struct.hpp"

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
  const com_interfaces::msg::RealsenseState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;
  // Member: err_code
  cdr << ros_message.err_code;
  // Member: err_msg
  cdr << ros_message.err_msg;
  // Member: node_online
  cdr << (ros_message.node_online ? true : false);
  // Member: color_ready
  cdr << (ros_message.color_ready ? true : false);
  // Member: depth_ready
  cdr << (ros_message.depth_ready ? true : false);
  // Member: aligned_depth_ready
  cdr << (ros_message.aligned_depth_ready ? true : false);
  // Member: color_info_ready
  cdr << (ros_message.color_info_ready ? true : false);
  // Member: depth_info_ready
  cdr << (ros_message.depth_info_ready ? true : false);
  // Member: color_topic
  cdr << ros_message.color_topic;
  // Member: depth_topic
  cdr << ros_message.depth_topic;
  // Member: aligned_depth_topic
  cdr << ros_message.aligned_depth_topic;
  // Member: color_info_topic
  cdr << ros_message.color_info_topic;
  // Member: depth_info_topic
  cdr << ros_message.depth_info_topic;
  // Member: last_color_ts_ms
  cdr << ros_message.last_color_ts_ms;
  // Member: last_depth_ts_ms
  cdr << ros_message.last_depth_ts_ms;
  // Member: last_aligned_depth_ts_ms
  cdr << ros_message.last_aligned_depth_ts_ms;
  // Member: last_color_info_ts_ms
  cdr << ros_message.last_color_info_ts_ms;
  // Member: last_depth_info_ts_ms
  cdr << ros_message.last_depth_info_ts_ms;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  com_interfaces::msg::RealsenseState & ros_message)
{
  // Member: name
  cdr >> ros_message.name;

  // Member: err_code
  cdr >> ros_message.err_code;

  // Member: err_msg
  cdr >> ros_message.err_msg;

  // Member: node_online
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.node_online = tmp ? true : false;
  }

  // Member: color_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.color_ready = tmp ? true : false;
  }

  // Member: depth_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.depth_ready = tmp ? true : false;
  }

  // Member: aligned_depth_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.aligned_depth_ready = tmp ? true : false;
  }

  // Member: color_info_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.color_info_ready = tmp ? true : false;
  }

  // Member: depth_info_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.depth_info_ready = tmp ? true : false;
  }

  // Member: color_topic
  cdr >> ros_message.color_topic;

  // Member: depth_topic
  cdr >> ros_message.depth_topic;

  // Member: aligned_depth_topic
  cdr >> ros_message.aligned_depth_topic;

  // Member: color_info_topic
  cdr >> ros_message.color_info_topic;

  // Member: depth_info_topic
  cdr >> ros_message.depth_info_topic;

  // Member: last_color_ts_ms
  cdr >> ros_message.last_color_ts_ms;

  // Member: last_depth_ts_ms
  cdr >> ros_message.last_depth_ts_ms;

  // Member: last_aligned_depth_ts_ms
  cdr >> ros_message.last_aligned_depth_ts_ms;

  // Member: last_color_info_ts_ms
  cdr >> ros_message.last_color_info_ts_ms;

  // Member: last_depth_info_ts_ms
  cdr >> ros_message.last_depth_info_ts_ms;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
get_serialized_size(
  const com_interfaces::msg::RealsenseState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);
  // Member: err_code
  {
    size_t item_size = sizeof(ros_message.err_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: err_msg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.err_msg.size() + 1);
  // Member: node_online
  {
    size_t item_size = sizeof(ros_message.node_online);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: color_ready
  {
    size_t item_size = sizeof(ros_message.color_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: depth_ready
  {
    size_t item_size = sizeof(ros_message.depth_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: aligned_depth_ready
  {
    size_t item_size = sizeof(ros_message.aligned_depth_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: color_info_ready
  {
    size_t item_size = sizeof(ros_message.color_info_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: depth_info_ready
  {
    size_t item_size = sizeof(ros_message.depth_info_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: color_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.color_topic.size() + 1);
  // Member: depth_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.depth_topic.size() + 1);
  // Member: aligned_depth_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.aligned_depth_topic.size() + 1);
  // Member: color_info_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.color_info_topic.size() + 1);
  // Member: depth_info_topic
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.depth_info_topic.size() + 1);
  // Member: last_color_ts_ms
  {
    size_t item_size = sizeof(ros_message.last_color_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: last_depth_ts_ms
  {
    size_t item_size = sizeof(ros_message.last_depth_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: last_aligned_depth_ts_ms
  {
    size_t item_size = sizeof(ros_message.last_aligned_depth_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: last_color_info_ts_ms
  {
    size_t item_size = sizeof(ros_message.last_color_info_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: last_depth_info_ts_ms
  {
    size_t item_size = sizeof(ros_message.last_depth_info_ts_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
max_serialized_size_RealsenseState(
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


  // Member: name
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

  // Member: err_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: err_msg
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

  // Member: node_online
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: color_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: depth_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: aligned_depth_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: color_info_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: depth_info_ready
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: color_topic
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

  // Member: depth_topic
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

  // Member: aligned_depth_topic
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

  // Member: color_info_topic
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

  // Member: depth_info_topic
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

  // Member: last_color_ts_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: last_depth_ts_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: last_aligned_depth_ts_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: last_color_info_ts_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: last_depth_info_ts_ms
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
    using DataType = com_interfaces::msg::RealsenseState;
    is_plain =
      (
      offsetof(DataType, last_depth_info_ts_ms) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RealsenseState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const com_interfaces::msg::RealsenseState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RealsenseState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<com_interfaces::msg::RealsenseState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RealsenseState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const com_interfaces::msg::RealsenseState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RealsenseState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RealsenseState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RealsenseState__callbacks = {
  "com_interfaces::msg",
  "RealsenseState",
  _RealsenseState__cdr_serialize,
  _RealsenseState__cdr_deserialize,
  _RealsenseState__get_serialized_size,
  _RealsenseState__max_serialized_size
};

static rosidl_message_type_support_t _RealsenseState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RealsenseState__callbacks,
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
get_message_type_support_handle<com_interfaces::msg::RealsenseState>()
{
  return &com_interfaces::msg::typesupport_fastrtps_cpp::_RealsenseState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, msg, RealsenseState)() {
  return &com_interfaces::msg::typesupport_fastrtps_cpp::_RealsenseState__handle;
}

#ifdef __cplusplus
}
#endif
