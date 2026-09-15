// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:srv/FrCmdInterface.idl
// generated code does not contain a copyright notice
#include "com_interfaces/srv/detail/fr_cmd_interface__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/srv/detail/fr_cmd_interface__struct.h"
#include "com_interfaces/srv/detail/fr_cmd_interface__functions.h"
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

#include "com_interfaces/msg/detail/joint_point__functions.h"  // joint_path
#include "rosidl_runtime_c/string.h"  // filename, program
#include "rosidl_runtime_c/string_functions.h"  // filename, program

// forward declare type support functions
size_t get_serialized_size_com_interfaces__msg__JointPoint(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_com_interfaces__msg__JointPoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, JointPoint)();


using _FrCmdInterface_Request__ros_msg_type = com_interfaces__srv__FrCmdInterface_Request;

static bool _FrCmdInterface_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FrCmdInterface_Request__ros_msg_type * ros_message = static_cast<const _FrCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: en
  {
    cdr << (ros_message->en ? true : false);
  }

  // Field name: joint_or_desc
  {
    cdr << (ros_message->joint_or_desc ? true : false);
  }

  // Field name: position
  {
    size_t size = 6;
    auto array_ptr = ros_message->position;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: axid
  {
    cdr << ros_message->axid;
  }

  // Field name: dir
  {
    cdr << ros_message->dir;
  }

  // Field name: deg
  {
    cdr << ros_message->deg;
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: acc
  {
    cdr << ros_message->acc;
  }

  // Field name: tool
  {
    cdr << ros_message->tool;
  }

  // Field name: mode
  {
    cdr << ros_message->mode;
  }

  // Field name: register_index
  {
    cdr << ros_message->register_index;
  }

  // Field name: register_value
  {
    cdr << ros_message->register_value;
  }

  // Field name: input_or_output
  {
    cdr << (ros_message->input_or_output ? true : false);
  }

  // Field name: io_index
  {
    cdr << ros_message->io_index;
  }

  // Field name: io_value
  {
    cdr << (ros_message->io_value ? true : false);
  }

  // Field name: program
  {
    const rosidl_runtime_c__String * str = &ros_message->program;
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

  // Field name: interval
  {
    cdr << ros_message->interval;
  }

  // Field name: filename
  {
    const rosidl_runtime_c__String * str = &ros_message->filename;
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

  // Field name: joint_path
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, JointPoint
      )()->data);
    size_t size = ros_message->joint_path.size;
    auto array_ptr = ros_message->joint_path.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: gripper_index
  {
    cdr << ros_message->gripper_index;
  }

  // Field name: act
  {
    cdr << ros_message->act;
  }

  // Field name: gripper_pos
  {
    cdr << ros_message->gripper_pos;
  }

  // Field name: gripper_vel
  {
    cdr << ros_message->gripper_vel;
  }

  // Field name: gripper_force
  {
    cdr << ros_message->gripper_force;
  }

  // Field name: max_time
  {
    cdr << ros_message->max_time;
  }

  // Field name: gripper_block
  {
    cdr << ros_message->gripper_block;
  }

  // Field name: cmd_t
  {
    cdr << ros_message->cmd_t;
  }

  // Field name: pos_gain
  {
    size_t size = 6;
    auto array_ptr = ros_message->pos_gain;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _FrCmdInterface_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FrCmdInterface_Request__ros_msg_type * ros_message = static_cast<_FrCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr >> ros_message->id;
  }

  // Field name: en
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->en = tmp ? true : false;
  }

  // Field name: joint_or_desc
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->joint_or_desc = tmp ? true : false;
  }

  // Field name: position
  {
    size_t size = 6;
    auto array_ptr = ros_message->position;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: axid
  {
    cdr >> ros_message->axid;
  }

  // Field name: dir
  {
    cdr >> ros_message->dir;
  }

  // Field name: deg
  {
    cdr >> ros_message->deg;
  }

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  // Field name: acc
  {
    cdr >> ros_message->acc;
  }

  // Field name: tool
  {
    cdr >> ros_message->tool;
  }

  // Field name: mode
  {
    cdr >> ros_message->mode;
  }

  // Field name: register_index
  {
    cdr >> ros_message->register_index;
  }

  // Field name: register_value
  {
    cdr >> ros_message->register_value;
  }

  // Field name: input_or_output
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->input_or_output = tmp ? true : false;
  }

  // Field name: io_index
  {
    cdr >> ros_message->io_index;
  }

  // Field name: io_value
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->io_value = tmp ? true : false;
  }

  // Field name: program
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->program.data) {
      rosidl_runtime_c__String__init(&ros_message->program);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->program,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'program'\n");
      return false;
    }
  }

  // Field name: interval
  {
    cdr >> ros_message->interval;
  }

  // Field name: filename
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->filename.data) {
      rosidl_runtime_c__String__init(&ros_message->filename);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->filename,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'filename'\n");
      return false;
    }
  }

  // Field name: joint_path
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, JointPoint
      )()->data);
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

    if (ros_message->joint_path.data) {
      com_interfaces__msg__JointPoint__Sequence__fini(&ros_message->joint_path);
    }
    if (!com_interfaces__msg__JointPoint__Sequence__init(&ros_message->joint_path, size)) {
      fprintf(stderr, "failed to create array for field 'joint_path'");
      return false;
    }
    auto array_ptr = ros_message->joint_path.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: gripper_index
  {
    cdr >> ros_message->gripper_index;
  }

  // Field name: act
  {
    cdr >> ros_message->act;
  }

  // Field name: gripper_pos
  {
    cdr >> ros_message->gripper_pos;
  }

  // Field name: gripper_vel
  {
    cdr >> ros_message->gripper_vel;
  }

  // Field name: gripper_force
  {
    cdr >> ros_message->gripper_force;
  }

  // Field name: max_time
  {
    cdr >> ros_message->max_time;
  }

  // Field name: gripper_block
  {
    cdr >> ros_message->gripper_block;
  }

  // Field name: cmd_t
  {
    cdr >> ros_message->cmd_t;
  }

  // Field name: pos_gain
  {
    size_t size = 6;
    auto array_ptr = ros_message->pos_gain;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__srv__FrCmdInterface_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FrCmdInterface_Request__ros_msg_type * ros_message = static_cast<const _FrCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name id
  {
    size_t item_size = sizeof(ros_message->id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name en
  {
    size_t item_size = sizeof(ros_message->en);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_or_desc
  {
    size_t item_size = sizeof(ros_message->joint_or_desc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name position
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->position;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name axid
  {
    size_t item_size = sizeof(ros_message->axid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dir
  {
    size_t item_size = sizeof(ros_message->dir);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name deg
  {
    size_t item_size = sizeof(ros_message->deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acc
  {
    size_t item_size = sizeof(ros_message->acc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tool
  {
    size_t item_size = sizeof(ros_message->tool);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mode
  {
    size_t item_size = sizeof(ros_message->mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name register_index
  {
    size_t item_size = sizeof(ros_message->register_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name register_value
  {
    size_t item_size = sizeof(ros_message->register_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name input_or_output
  {
    size_t item_size = sizeof(ros_message->input_or_output);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name io_index
  {
    size_t item_size = sizeof(ros_message->io_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name io_value
  {
    size_t item_size = sizeof(ros_message->io_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name program
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->program.size + 1);
  // field.name interval
  {
    size_t item_size = sizeof(ros_message->interval);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name filename
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->filename.size + 1);
  // field.name joint_path
  {
    size_t array_size = ros_message->joint_path.size;
    auto array_ptr = ros_message->joint_path.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_com_interfaces__msg__JointPoint(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name gripper_index
  {
    size_t item_size = sizeof(ros_message->gripper_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name act
  {
    size_t item_size = sizeof(ros_message->act);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gripper_pos
  {
    size_t item_size = sizeof(ros_message->gripper_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gripper_vel
  {
    size_t item_size = sizeof(ros_message->gripper_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gripper_force
  {
    size_t item_size = sizeof(ros_message->gripper_force);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_time
  {
    size_t item_size = sizeof(ros_message->max_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gripper_block
  {
    size_t item_size = sizeof(ros_message->gripper_block);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cmd_t
  {
    size_t item_size = sizeof(ros_message->cmd_t);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos_gain
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->pos_gain;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FrCmdInterface_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__srv__FrCmdInterface_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__srv__FrCmdInterface_Request(
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

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: en
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: joint_or_desc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: position
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: axid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: dir
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: deg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: acc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tool
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: register_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: register_value
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: input_or_output
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: io_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: io_value
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: program
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
  // member: interval
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: filename
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
  // member: joint_path
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
      size_t inner_size;
      inner_size =
        max_serialized_size_com_interfaces__msg__JointPoint(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: gripper_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: act
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: gripper_pos
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gripper_vel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gripper_force
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: max_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gripper_block
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cmd_t
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pos_gain
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = com_interfaces__srv__FrCmdInterface_Request;
    is_plain =
      (
      offsetof(DataType, pos_gain) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FrCmdInterface_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__srv__FrCmdInterface_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FrCmdInterface_Request = {
  "com_interfaces::srv",
  "FrCmdInterface_Request",
  _FrCmdInterface_Request__cdr_serialize,
  _FrCmdInterface_Request__cdr_deserialize,
  _FrCmdInterface_Request__get_serialized_size,
  _FrCmdInterface_Request__max_serialized_size
};

static rosidl_message_type_support_t _FrCmdInterface_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FrCmdInterface_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, FrCmdInterface_Request)() {
  return &_FrCmdInterface_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "com_interfaces/srv/detail/fr_cmd_interface__struct.h"
// already included above
// #include "com_interfaces/srv/detail/fr_cmd_interface__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "com_interfaces/msg/detail/force_payload__functions.h"  // force_payload
#include "com_interfaces/msg/detail/force_torque__functions.h"  // ft
#include "com_interfaces/msg/detail/fr_robot_state__functions.h"  // pub_state
// already included above
// #include "rosidl_runtime_c/string.h"  // msg
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // msg

// forward declare type support functions
size_t get_serialized_size_com_interfaces__msg__ForcePayload(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_com_interfaces__msg__ForcePayload(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, ForcePayload)();
size_t get_serialized_size_com_interfaces__msg__ForceTorque(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_com_interfaces__msg__ForceTorque(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, ForceTorque)();
size_t get_serialized_size_com_interfaces__msg__FrRobotState(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_com_interfaces__msg__FrRobotState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, FrRobotState)();


using _FrCmdInterface_Response__ros_msg_type = com_interfaces__srv__FrCmdInterface_Response;

static bool _FrCmdInterface_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FrCmdInterface_Response__ros_msg_type * ros_message = static_cast<const _FrCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: err_code
  {
    cdr << ros_message->err_code;
  }

  // Field name: msg
  {
    const rosidl_runtime_c__String * str = &ros_message->msg;
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

  // Field name: pub_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, FrRobotState
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->pub_state, cdr))
    {
      return false;
    }
  }

  // Field name: register_val
  {
    cdr << ros_message->register_val;
  }

  // Field name: io_val
  {
    cdr << (ros_message->io_val ? true : false);
  }

  // Field name: jt_pos
  {
    size_t size = 6;
    auto array_ptr = ros_message->jt_pos;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tl_pos
  {
    size_t size = 6;
    auto array_ptr = ros_message->tl_pos;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: ft
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, ForceTorque
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->ft, cdr))
    {
      return false;
    }
  }

  // Field name: force_payload
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, ForcePayload
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->force_payload, cdr))
    {
      return false;
    }
  }

  // Field name: motion_done
  {
    cdr << (ros_message->motion_done ? true : false);
  }

  return true;
}

static bool _FrCmdInterface_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FrCmdInterface_Response__ros_msg_type * ros_message = static_cast<_FrCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: err_code
  {
    cdr >> ros_message->err_code;
  }

  // Field name: msg
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->msg.data) {
      rosidl_runtime_c__String__init(&ros_message->msg);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->msg,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'msg'\n");
      return false;
    }
  }

  // Field name: pub_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, FrRobotState
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->pub_state))
    {
      return false;
    }
  }

  // Field name: register_val
  {
    cdr >> ros_message->register_val;
  }

  // Field name: io_val
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->io_val = tmp ? true : false;
  }

  // Field name: jt_pos
  {
    size_t size = 6;
    auto array_ptr = ros_message->jt_pos;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tl_pos
  {
    size_t size = 6;
    auto array_ptr = ros_message->tl_pos;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: ft
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, ForceTorque
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->ft))
    {
      return false;
    }
  }

  // Field name: force_payload
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, ForcePayload
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->force_payload))
    {
      return false;
    }
  }

  // Field name: motion_done
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->motion_done = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__srv__FrCmdInterface_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FrCmdInterface_Response__ros_msg_type * ros_message = static_cast<const _FrCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name err_code
  {
    size_t item_size = sizeof(ros_message->err_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name msg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->msg.size + 1);
  // field.name pub_state

  current_alignment += get_serialized_size_com_interfaces__msg__FrRobotState(
    &(ros_message->pub_state), current_alignment);
  // field.name register_val
  {
    size_t item_size = sizeof(ros_message->register_val);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name io_val
  {
    size_t item_size = sizeof(ros_message->io_val);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name jt_pos
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->jt_pos;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tl_pos
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->tl_pos;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ft

  current_alignment += get_serialized_size_com_interfaces__msg__ForceTorque(
    &(ros_message->ft), current_alignment);
  // field.name force_payload

  current_alignment += get_serialized_size_com_interfaces__msg__ForcePayload(
    &(ros_message->force_payload), current_alignment);
  // field.name motion_done
  {
    size_t item_size = sizeof(ros_message->motion_done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FrCmdInterface_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__srv__FrCmdInterface_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__srv__FrCmdInterface_Response(
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

  // member: err_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: msg
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
  // member: pub_state
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_com_interfaces__msg__FrRobotState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: register_val
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: io_val
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: jt_pos
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tl_pos
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ft
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_com_interfaces__msg__ForceTorque(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: force_payload
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_com_interfaces__msg__ForcePayload(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: motion_done
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
    using DataType = com_interfaces__srv__FrCmdInterface_Response;
    is_plain =
      (
      offsetof(DataType, motion_done) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FrCmdInterface_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__srv__FrCmdInterface_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FrCmdInterface_Response = {
  "com_interfaces::srv",
  "FrCmdInterface_Response",
  _FrCmdInterface_Response__cdr_serialize,
  _FrCmdInterface_Response__cdr_deserialize,
  _FrCmdInterface_Response__get_serialized_size,
  _FrCmdInterface_Response__max_serialized_size
};

static rosidl_message_type_support_t _FrCmdInterface_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FrCmdInterface_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, FrCmdInterface_Response)() {
  return &_FrCmdInterface_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/srv/fr_cmd_interface.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t FrCmdInterface__callbacks = {
  "com_interfaces::srv",
  "FrCmdInterface",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, FrCmdInterface_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, FrCmdInterface_Response)(),
};

static rosidl_service_type_support_t FrCmdInterface__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &FrCmdInterface__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, FrCmdInterface)() {
  return &FrCmdInterface__handle;
}

#if defined(__cplusplus)
}
#endif
