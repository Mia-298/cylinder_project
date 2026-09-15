// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:msg/FrRobotState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/fr_robot_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "com_interfaces/msg/detail/fr_robot_state__struct.hpp"

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
  const com_interfaces::msg::FrRobotState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: robot_index
  cdr << ros_message.robot_index;
  // Member: robot_name
  cdr << ros_message.robot_name;
  // Member: robot_type
  cdr << ros_message.robot_type;
  // Member: robot_soft_index
  cdr << ros_message.robot_soft_index;
  // Member: robot_ip
  cdr << ros_message.robot_ip;
  // Member: curtask_index
  cdr << ros_message.curtask_index;
  // Member: curstep_index
  cdr << ros_message.curstep_index;
  // Member: program_state
  cdr << ros_message.program_state;
  // Member: robot_motion_done
  cdr << ros_message.robot_motion_done;
  // Member: robot_err_code
  cdr << ros_message.robot_err_code;
  // Member: main_code
  cdr << ros_message.main_code;
  // Member: sub_code
  cdr << ros_message.sub_code;
  // Member: robot_mode
  cdr << ros_message.robot_mode;
  // Member: robot_speed
  cdr << ros_message.robot_speed;
  // Member: jt_cur_pos
  {
    cdr << ros_message.jt_cur_pos;
  }
  // Member: tl_cur_pos
  {
    cdr << ros_message.tl_cur_pos;
  }
  // Member: cl_dgt_output_h
  cdr << ros_message.cl_dgt_output_h;
  // Member: cl_dgt_output_l
  cdr << ros_message.cl_dgt_output_l;
  // Member: cl_dgt_input_h
  cdr << ros_message.cl_dgt_input_h;
  // Member: cl_dgt_input_l
  cdr << ros_message.cl_dgt_input_l;
  // Member: cl_analog_input
  {
    cdr << ros_message.cl_analog_input;
  }
  // Member: cl_analog_output
  {
    cdr << ros_message.cl_analog_output;
  }
  // Member: tl_dgt_output_l
  cdr << ros_message.tl_dgt_output_l;
  // Member: tl_dgt_input_l
  cdr << ros_message.tl_dgt_input_l;
  // Member: emergency_stop
  cdr << ros_message.emergency_stop;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  com_interfaces::msg::FrRobotState & ros_message)
{
  // Member: robot_index
  cdr >> ros_message.robot_index;

  // Member: robot_name
  cdr >> ros_message.robot_name;

  // Member: robot_type
  cdr >> ros_message.robot_type;

  // Member: robot_soft_index
  cdr >> ros_message.robot_soft_index;

  // Member: robot_ip
  cdr >> ros_message.robot_ip;

  // Member: curtask_index
  cdr >> ros_message.curtask_index;

  // Member: curstep_index
  cdr >> ros_message.curstep_index;

  // Member: program_state
  cdr >> ros_message.program_state;

  // Member: robot_motion_done
  cdr >> ros_message.robot_motion_done;

  // Member: robot_err_code
  cdr >> ros_message.robot_err_code;

  // Member: main_code
  cdr >> ros_message.main_code;

  // Member: sub_code
  cdr >> ros_message.sub_code;

  // Member: robot_mode
  cdr >> ros_message.robot_mode;

  // Member: robot_speed
  cdr >> ros_message.robot_speed;

  // Member: jt_cur_pos
  {
    cdr >> ros_message.jt_cur_pos;
  }

  // Member: tl_cur_pos
  {
    cdr >> ros_message.tl_cur_pos;
  }

  // Member: cl_dgt_output_h
  cdr >> ros_message.cl_dgt_output_h;

  // Member: cl_dgt_output_l
  cdr >> ros_message.cl_dgt_output_l;

  // Member: cl_dgt_input_h
  cdr >> ros_message.cl_dgt_input_h;

  // Member: cl_dgt_input_l
  cdr >> ros_message.cl_dgt_input_l;

  // Member: cl_analog_input
  {
    cdr >> ros_message.cl_analog_input;
  }

  // Member: cl_analog_output
  {
    cdr >> ros_message.cl_analog_output;
  }

  // Member: tl_dgt_output_l
  cdr >> ros_message.tl_dgt_output_l;

  // Member: tl_dgt_input_l
  cdr >> ros_message.tl_dgt_input_l;

  // Member: emergency_stop
  cdr >> ros_message.emergency_stop;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
get_serialized_size(
  const com_interfaces::msg::FrRobotState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: robot_index
  {
    size_t item_size = sizeof(ros_message.robot_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: robot_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.robot_name.size() + 1);
  // Member: robot_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.robot_type.size() + 1);
  // Member: robot_soft_index
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.robot_soft_index.size() + 1);
  // Member: robot_ip
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.robot_ip.size() + 1);
  // Member: curtask_index
  {
    size_t item_size = sizeof(ros_message.curtask_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: curstep_index
  {
    size_t item_size = sizeof(ros_message.curstep_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: program_state
  {
    size_t item_size = sizeof(ros_message.program_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: robot_motion_done
  {
    size_t item_size = sizeof(ros_message.robot_motion_done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: robot_err_code
  {
    size_t item_size = sizeof(ros_message.robot_err_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: main_code
  {
    size_t item_size = sizeof(ros_message.main_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sub_code
  {
    size_t item_size = sizeof(ros_message.sub_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: robot_mode
  {
    size_t item_size = sizeof(ros_message.robot_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: robot_speed
  {
    size_t item_size = sizeof(ros_message.robot_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: jt_cur_pos
  {
    size_t array_size = 6;
    size_t item_size = sizeof(ros_message.jt_cur_pos[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tl_cur_pos
  {
    size_t array_size = 6;
    size_t item_size = sizeof(ros_message.tl_cur_pos[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cl_dgt_output_h
  {
    size_t item_size = sizeof(ros_message.cl_dgt_output_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cl_dgt_output_l
  {
    size_t item_size = sizeof(ros_message.cl_dgt_output_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cl_dgt_input_h
  {
    size_t item_size = sizeof(ros_message.cl_dgt_input_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cl_dgt_input_l
  {
    size_t item_size = sizeof(ros_message.cl_dgt_input_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cl_analog_input
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.cl_analog_input[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cl_analog_output
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.cl_analog_output[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tl_dgt_output_l
  {
    size_t item_size = sizeof(ros_message.tl_dgt_output_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tl_dgt_input_l
  {
    size_t item_size = sizeof(ros_message.tl_dgt_input_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: emergency_stop
  {
    size_t item_size = sizeof(ros_message.emergency_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
max_serialized_size_FrRobotState(
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


  // Member: robot_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: robot_name
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

  // Member: robot_type
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

  // Member: robot_soft_index
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

  // Member: robot_ip
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

  // Member: curtask_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: curstep_index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: program_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: robot_motion_done
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: robot_err_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: main_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: sub_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: robot_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: robot_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: jt_cur_pos
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tl_cur_pos
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: cl_dgt_output_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cl_dgt_output_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cl_dgt_input_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cl_dgt_input_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cl_analog_input
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: cl_analog_output
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: tl_dgt_output_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: tl_dgt_input_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: emergency_stop
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
    using DataType = com_interfaces::msg::FrRobotState;
    is_plain =
      (
      offsetof(DataType, emergency_stop) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _FrRobotState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const com_interfaces::msg::FrRobotState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FrRobotState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<com_interfaces::msg::FrRobotState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FrRobotState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const com_interfaces::msg::FrRobotState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FrRobotState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FrRobotState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FrRobotState__callbacks = {
  "com_interfaces::msg",
  "FrRobotState",
  _FrRobotState__cdr_serialize,
  _FrRobotState__cdr_deserialize,
  _FrRobotState__get_serialized_size,
  _FrRobotState__max_serialized_size
};

static rosidl_message_type_support_t _FrRobotState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FrRobotState__callbacks,
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
get_message_type_support_handle<com_interfaces::msg::FrRobotState>()
{
  return &com_interfaces::msg::typesupport_fastrtps_cpp::_FrRobotState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, msg, FrRobotState)() {
  return &com_interfaces::msg::typesupport_fastrtps_cpp::_FrRobotState__handle;
}

#ifdef __cplusplus
}
#endif
