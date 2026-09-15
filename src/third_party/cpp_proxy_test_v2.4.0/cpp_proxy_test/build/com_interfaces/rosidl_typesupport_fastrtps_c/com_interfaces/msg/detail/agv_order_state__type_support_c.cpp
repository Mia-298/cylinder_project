// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:msg/AgvOrderState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/agv_order_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/msg/detail/agv_order_state__struct.h"
#include "com_interfaces/msg/detail/agv_order_state__functions.h"
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

#include "rosidl_runtime_c/string.h"  // actual_robot_name, container_id, execution_reject, fault_reason, id, status, step_locations
#include "rosidl_runtime_c/string_functions.h"  // actual_robot_name, container_id, execution_reject, fault_reason, id, status, step_locations

// forward declare type support functions


using _AgvOrderState__ros_msg_type = com_interfaces__msg__AgvOrderState;

static bool _AgvOrderState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AgvOrderState__ros_msg_type * ros_message = static_cast<const _AgvOrderState__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    const rosidl_runtime_c__String * str = &ros_message->id;
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

  // Field name: status
  {
    const rosidl_runtime_c__String * str = &ros_message->status;
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

  // Field name: actual_robot_name
  {
    const rosidl_runtime_c__String * str = &ros_message->actual_robot_name;
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

  // Field name: current_step_index
  {
    cdr << ros_message->current_step_index;
  }

  // Field name: done_step_index
  {
    cdr << ros_message->done_step_index;
  }

  // Field name: step_num
  {
    cdr << ros_message->step_num;
  }

  // Field name: step_locations
  {
    size_t size = ros_message->step_locations.size;
    auto array_ptr = ros_message->step_locations.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  // Field name: container_id
  {
    const rosidl_runtime_c__String * str = &ros_message->container_id;
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

  // Field name: loaded
  {
    cdr << (ros_message->loaded ? true : false);
  }

  // Field name: unloaded
  {
    cdr << (ros_message->unloaded ? true : false);
  }

  // Field name: fault
  {
    cdr << (ros_message->fault ? true : false);
  }

  // Field name: fault_reason
  {
    const rosidl_runtime_c__String * str = &ros_message->fault_reason;
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

  // Field name: execution_reject
  {
    const rosidl_runtime_c__String * str = &ros_message->execution_reject;
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

static bool _AgvOrderState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AgvOrderState__ros_msg_type * ros_message = static_cast<_AgvOrderState__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->id.data) {
      rosidl_runtime_c__String__init(&ros_message->id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'id'\n");
      return false;
    }
  }

  // Field name: status
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->status.data) {
      rosidl_runtime_c__String__init(&ros_message->status);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->status,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'status'\n");
      return false;
    }
  }

  // Field name: actual_robot_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->actual_robot_name.data) {
      rosidl_runtime_c__String__init(&ros_message->actual_robot_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->actual_robot_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'actual_robot_name'\n");
      return false;
    }
  }

  // Field name: current_step_index
  {
    cdr >> ros_message->current_step_index;
  }

  // Field name: done_step_index
  {
    cdr >> ros_message->done_step_index;
  }

  // Field name: step_num
  {
    cdr >> ros_message->step_num;
  }

  // Field name: step_locations
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

    if (ros_message->step_locations.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->step_locations);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->step_locations, size)) {
      fprintf(stderr, "failed to create array for field 'step_locations'");
      return false;
    }
    auto array_ptr = ros_message->step_locations.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'step_locations'\n");
        return false;
      }
    }
  }

  // Field name: container_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->container_id.data) {
      rosidl_runtime_c__String__init(&ros_message->container_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->container_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'container_id'\n");
      return false;
    }
  }

  // Field name: loaded
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->loaded = tmp ? true : false;
  }

  // Field name: unloaded
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->unloaded = tmp ? true : false;
  }

  // Field name: fault
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->fault = tmp ? true : false;
  }

  // Field name: fault_reason
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->fault_reason.data) {
      rosidl_runtime_c__String__init(&ros_message->fault_reason);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->fault_reason,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'fault_reason'\n");
      return false;
    }
  }

  // Field name: execution_reject
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->execution_reject.data) {
      rosidl_runtime_c__String__init(&ros_message->execution_reject);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->execution_reject,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'execution_reject'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__msg__AgvOrderState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AgvOrderState__ros_msg_type * ros_message = static_cast<const _AgvOrderState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->id.size + 1);
  // field.name status
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->status.size + 1);
  // field.name actual_robot_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->actual_robot_name.size + 1);
  // field.name current_step_index
  {
    size_t item_size = sizeof(ros_message->current_step_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name done_step_index
  {
    size_t item_size = sizeof(ros_message->done_step_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name step_num
  {
    size_t item_size = sizeof(ros_message->step_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name step_locations
  {
    size_t array_size = ros_message->step_locations.size;
    auto array_ptr = ros_message->step_locations.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name container_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->container_id.size + 1);
  // field.name loaded
  {
    size_t item_size = sizeof(ros_message->loaded);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name unloaded
  {
    size_t item_size = sizeof(ros_message->unloaded);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fault
  {
    size_t item_size = sizeof(ros_message->fault);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fault_reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->fault_reason.size + 1);
  // field.name execution_reject
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->execution_reject.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _AgvOrderState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__msg__AgvOrderState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__msg__AgvOrderState(
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

  // member: id
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
  // member: status
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
  // member: actual_robot_name
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
  // member: current_step_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: done_step_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: step_num
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: step_locations
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: container_id
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
  // member: loaded
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: unloaded
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: fault
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: fault_reason
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
  // member: execution_reject
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
    using DataType = com_interfaces__msg__AgvOrderState;
    is_plain =
      (
      offsetof(DataType, execution_reject) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _AgvOrderState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__msg__AgvOrderState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AgvOrderState = {
  "com_interfaces::msg",
  "AgvOrderState",
  _AgvOrderState__cdr_serialize,
  _AgvOrderState__cdr_deserialize,
  _AgvOrderState__get_serialized_size,
  _AgvOrderState__max_serialized_size
};

static rosidl_message_type_support_t _AgvOrderState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AgvOrderState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvOrderState)() {
  return &_AgvOrderState__type_support;
}

#if defined(__cplusplus)
}
#endif
