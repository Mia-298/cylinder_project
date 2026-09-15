// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:msg/FrRobotState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/fr_robot_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/msg/detail/fr_robot_state__struct.h"
#include "com_interfaces/msg/detail/fr_robot_state__functions.h"
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


using _FrRobotState__ros_msg_type = com_interfaces__msg__FrRobotState;

static bool _FrRobotState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FrRobotState__ros_msg_type * ros_message = static_cast<const _FrRobotState__ros_msg_type *>(untyped_ros_message);
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

  // Field name: curtask_index
  {
    cdr << ros_message->curtask_index;
  }

  // Field name: curstep_index
  {
    cdr << ros_message->curstep_index;
  }

  // Field name: program_state
  {
    cdr << ros_message->program_state;
  }

  // Field name: robot_motion_done
  {
    cdr << ros_message->robot_motion_done;
  }

  // Field name: robot_err_code
  {
    cdr << ros_message->robot_err_code;
  }

  // Field name: main_code
  {
    cdr << ros_message->main_code;
  }

  // Field name: sub_code
  {
    cdr << ros_message->sub_code;
  }

  // Field name: robot_mode
  {
    cdr << ros_message->robot_mode;
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

  // Field name: cl_dgt_output_h
  {
    cdr << ros_message->cl_dgt_output_h;
  }

  // Field name: cl_dgt_output_l
  {
    cdr << ros_message->cl_dgt_output_l;
  }

  // Field name: cl_dgt_input_h
  {
    cdr << ros_message->cl_dgt_input_h;
  }

  // Field name: cl_dgt_input_l
  {
    cdr << ros_message->cl_dgt_input_l;
  }

  // Field name: cl_analog_input
  {
    size_t size = 2;
    auto array_ptr = ros_message->cl_analog_input;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: cl_analog_output
  {
    size_t size = 2;
    auto array_ptr = ros_message->cl_analog_output;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tl_dgt_output_l
  {
    cdr << ros_message->tl_dgt_output_l;
  }

  // Field name: tl_dgt_input_l
  {
    cdr << ros_message->tl_dgt_input_l;
  }

  // Field name: emergency_stop
  {
    cdr << ros_message->emergency_stop;
  }

  return true;
}

static bool _FrRobotState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FrRobotState__ros_msg_type * ros_message = static_cast<_FrRobotState__ros_msg_type *>(untyped_ros_message);
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

  // Field name: curtask_index
  {
    cdr >> ros_message->curtask_index;
  }

  // Field name: curstep_index
  {
    cdr >> ros_message->curstep_index;
  }

  // Field name: program_state
  {
    cdr >> ros_message->program_state;
  }

  // Field name: robot_motion_done
  {
    cdr >> ros_message->robot_motion_done;
  }

  // Field name: robot_err_code
  {
    cdr >> ros_message->robot_err_code;
  }

  // Field name: main_code
  {
    cdr >> ros_message->main_code;
  }

  // Field name: sub_code
  {
    cdr >> ros_message->sub_code;
  }

  // Field name: robot_mode
  {
    cdr >> ros_message->robot_mode;
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

  // Field name: cl_dgt_output_h
  {
    cdr >> ros_message->cl_dgt_output_h;
  }

  // Field name: cl_dgt_output_l
  {
    cdr >> ros_message->cl_dgt_output_l;
  }

  // Field name: cl_dgt_input_h
  {
    cdr >> ros_message->cl_dgt_input_h;
  }

  // Field name: cl_dgt_input_l
  {
    cdr >> ros_message->cl_dgt_input_l;
  }

  // Field name: cl_analog_input
  {
    size_t size = 2;
    auto array_ptr = ros_message->cl_analog_input;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: cl_analog_output
  {
    size_t size = 2;
    auto array_ptr = ros_message->cl_analog_output;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tl_dgt_output_l
  {
    cdr >> ros_message->tl_dgt_output_l;
  }

  // Field name: tl_dgt_input_l
  {
    cdr >> ros_message->tl_dgt_input_l;
  }

  // Field name: emergency_stop
  {
    cdr >> ros_message->emergency_stop;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__msg__FrRobotState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FrRobotState__ros_msg_type * ros_message = static_cast<const _FrRobotState__ros_msg_type *>(untyped_ros_message);
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
  // field.name curtask_index
  {
    size_t item_size = sizeof(ros_message->curtask_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name curstep_index
  {
    size_t item_size = sizeof(ros_message->curstep_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name program_state
  {
    size_t item_size = sizeof(ros_message->program_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_motion_done
  {
    size_t item_size = sizeof(ros_message->robot_motion_done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_err_code
  {
    size_t item_size = sizeof(ros_message->robot_err_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name main_code
  {
    size_t item_size = sizeof(ros_message->main_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sub_code
  {
    size_t item_size = sizeof(ros_message->sub_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_mode
  {
    size_t item_size = sizeof(ros_message->robot_mode);
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
  // field.name cl_dgt_output_h
  {
    size_t item_size = sizeof(ros_message->cl_dgt_output_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cl_dgt_output_l
  {
    size_t item_size = sizeof(ros_message->cl_dgt_output_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cl_dgt_input_h
  {
    size_t item_size = sizeof(ros_message->cl_dgt_input_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cl_dgt_input_l
  {
    size_t item_size = sizeof(ros_message->cl_dgt_input_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cl_analog_input
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->cl_analog_input;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cl_analog_output
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->cl_analog_output;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tl_dgt_output_l
  {
    size_t item_size = sizeof(ros_message->tl_dgt_output_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tl_dgt_input_l
  {
    size_t item_size = sizeof(ros_message->tl_dgt_input_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name emergency_stop
  {
    size_t item_size = sizeof(ros_message->emergency_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FrRobotState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__msg__FrRobotState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__msg__FrRobotState(
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
  // member: curtask_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: curstep_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: program_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: robot_motion_done
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: robot_err_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: main_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: sub_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: robot_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
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
  // member: cl_dgt_output_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cl_dgt_output_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cl_dgt_input_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cl_dgt_input_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cl_analog_input
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: cl_analog_output
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: tl_dgt_output_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: tl_dgt_input_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: emergency_stop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = com_interfaces__msg__FrRobotState;
    is_plain =
      (
      offsetof(DataType, emergency_stop) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FrRobotState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__msg__FrRobotState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FrRobotState = {
  "com_interfaces::msg",
  "FrRobotState",
  _FrRobotState__cdr_serialize,
  _FrRobotState__cdr_deserialize,
  _FrRobotState__get_serialized_size,
  _FrRobotState__max_serialized_size
};

static rosidl_message_type_support_t _FrRobotState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FrRobotState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, FrRobotState)() {
  return &_FrRobotState__type_support;
}

#if defined(__cplusplus)
}
#endif
