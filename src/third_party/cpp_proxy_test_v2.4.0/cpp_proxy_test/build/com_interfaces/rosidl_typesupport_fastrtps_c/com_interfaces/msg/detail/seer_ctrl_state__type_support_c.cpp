// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:msg/SeerCtrlState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/seer_ctrl_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/msg/detail/seer_ctrl_state__struct.h"
#include "com_interfaces/msg/detail/seer_ctrl_state__functions.h"
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

#include "com_interfaces/msg/detail/agv_control__functions.h"  // control
#include "com_interfaces/msg/detail/agv_guide_state__functions.h"  // guide_state
#include "rosidl_runtime_c/string.h"  // battery_user_data, current_station, err_msg, last_station, name
#include "rosidl_runtime_c/string_functions.h"  // battery_user_data, current_station, err_msg, last_station, name

// forward declare type support functions
size_t get_serialized_size_com_interfaces__msg__AgvControl(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_com_interfaces__msg__AgvControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvControl)();
size_t get_serialized_size_com_interfaces__msg__AgvGuideState(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_com_interfaces__msg__AgvGuideState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvGuideState)();


using _SeerCtrlState__ros_msg_type = com_interfaces__msg__SeerCtrlState;

static bool _SeerCtrlState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SeerCtrlState__ros_msg_type * ros_message = static_cast<const _SeerCtrlState__ros_msg_type *>(untyped_ros_message);
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

  // Field name: pose_x
  {
    cdr << ros_message->pose_x;
  }

  // Field name: pose_y
  {
    cdr << ros_message->pose_y;
  }

  // Field name: angle
  {
    cdr << ros_message->angle;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: current_station
  {
    const rosidl_runtime_c__String * str = &ros_message->current_station;
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

  // Field name: last_station
  {
    const rosidl_runtime_c__String * str = &ros_message->last_station;
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

  // Field name: vel_x
  {
    cdr << ros_message->vel_x;
  }

  // Field name: vel_y
  {
    cdr << ros_message->vel_y;
  }

  // Field name: vel_ang
  {
    cdr << ros_message->vel_ang;
  }

  // Field name: battery_level
  {
    cdr << ros_message->battery_level;
  }

  // Field name: battery_temp
  {
    cdr << ros_message->battery_temp;
  }

  // Field name: charging
  {
    cdr << (ros_message->charging ? true : false);
  }

  // Field name: voltage
  {
    cdr << ros_message->voltage;
  }

  // Field name: current
  {
    cdr << ros_message->current;
  }

  // Field name: max_charge_voltage
  {
    cdr << ros_message->max_charge_voltage;
  }

  // Field name: max_charge_current
  {
    cdr << ros_message->max_charge_current;
  }

  // Field name: manual_charge
  {
    cdr << (ros_message->manual_charge ? true : false);
  }

  // Field name: auto_charge
  {
    cdr << (ros_message->auto_charge ? true : false);
  }

  // Field name: battery_cycle
  {
    cdr << ros_message->battery_cycle;
  }

  // Field name: battery_user_data
  {
    const rosidl_runtime_c__String * str = &ros_message->battery_user_data;
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

  // Field name: guide_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvGuideState
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->guide_state, cdr))
    {
      return false;
    }
  }

  // Field name: control
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvControl
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->control, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _SeerCtrlState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SeerCtrlState__ros_msg_type * ros_message = static_cast<_SeerCtrlState__ros_msg_type *>(untyped_ros_message);
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

  // Field name: pose_x
  {
    cdr >> ros_message->pose_x;
  }

  // Field name: pose_y
  {
    cdr >> ros_message->pose_y;
  }

  // Field name: angle
  {
    cdr >> ros_message->angle;
  }

  // Field name: confidence
  {
    cdr >> ros_message->confidence;
  }

  // Field name: current_station
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->current_station.data) {
      rosidl_runtime_c__String__init(&ros_message->current_station);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->current_station,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'current_station'\n");
      return false;
    }
  }

  // Field name: last_station
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->last_station.data) {
      rosidl_runtime_c__String__init(&ros_message->last_station);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->last_station,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'last_station'\n");
      return false;
    }
  }

  // Field name: vel_x
  {
    cdr >> ros_message->vel_x;
  }

  // Field name: vel_y
  {
    cdr >> ros_message->vel_y;
  }

  // Field name: vel_ang
  {
    cdr >> ros_message->vel_ang;
  }

  // Field name: battery_level
  {
    cdr >> ros_message->battery_level;
  }

  // Field name: battery_temp
  {
    cdr >> ros_message->battery_temp;
  }

  // Field name: charging
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->charging = tmp ? true : false;
  }

  // Field name: voltage
  {
    cdr >> ros_message->voltage;
  }

  // Field name: current
  {
    cdr >> ros_message->current;
  }

  // Field name: max_charge_voltage
  {
    cdr >> ros_message->max_charge_voltage;
  }

  // Field name: max_charge_current
  {
    cdr >> ros_message->max_charge_current;
  }

  // Field name: manual_charge
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->manual_charge = tmp ? true : false;
  }

  // Field name: auto_charge
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->auto_charge = tmp ? true : false;
  }

  // Field name: battery_cycle
  {
    cdr >> ros_message->battery_cycle;
  }

  // Field name: battery_user_data
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->battery_user_data.data) {
      rosidl_runtime_c__String__init(&ros_message->battery_user_data);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->battery_user_data,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'battery_user_data'\n");
      return false;
    }
  }

  // Field name: guide_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvGuideState
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->guide_state))
    {
      return false;
    }
  }

  // Field name: control
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvControl
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->control))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__msg__SeerCtrlState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SeerCtrlState__ros_msg_type * ros_message = static_cast<const _SeerCtrlState__ros_msg_type *>(untyped_ros_message);
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
  // field.name pose_x
  {
    size_t item_size = sizeof(ros_message->pose_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pose_y
  {
    size_t item_size = sizeof(ros_message->pose_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name angle
  {
    size_t item_size = sizeof(ros_message->angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_station
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->current_station.size + 1);
  // field.name last_station
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->last_station.size + 1);
  // field.name vel_x
  {
    size_t item_size = sizeof(ros_message->vel_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_y
  {
    size_t item_size = sizeof(ros_message->vel_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_ang
  {
    size_t item_size = sizeof(ros_message->vel_ang);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_level
  {
    size_t item_size = sizeof(ros_message->battery_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_temp
  {
    size_t item_size = sizeof(ros_message->battery_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name charging
  {
    size_t item_size = sizeof(ros_message->charging);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name voltage
  {
    size_t item_size = sizeof(ros_message->voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current
  {
    size_t item_size = sizeof(ros_message->current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_charge_voltage
  {
    size_t item_size = sizeof(ros_message->max_charge_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_charge_current
  {
    size_t item_size = sizeof(ros_message->max_charge_current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name manual_charge
  {
    size_t item_size = sizeof(ros_message->manual_charge);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name auto_charge
  {
    size_t item_size = sizeof(ros_message->auto_charge);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_cycle
  {
    size_t item_size = sizeof(ros_message->battery_cycle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_user_data
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->battery_user_data.size + 1);
  // field.name guide_state

  current_alignment += get_serialized_size_com_interfaces__msg__AgvGuideState(
    &(ros_message->guide_state), current_alignment);
  // field.name control

  current_alignment += get_serialized_size_com_interfaces__msg__AgvControl(
    &(ros_message->control), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _SeerCtrlState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__msg__SeerCtrlState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__msg__SeerCtrlState(
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
  // member: pose_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: pose_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: confidence
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: current_station
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
  // member: last_station
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
  // member: vel_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_ang
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: battery_level
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: battery_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: charging
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: max_charge_voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: max_charge_current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: manual_charge
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: auto_charge
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: battery_cycle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: battery_user_data
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
  // member: guide_state
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_com_interfaces__msg__AgvGuideState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: control
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_com_interfaces__msg__AgvControl(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = com_interfaces__msg__SeerCtrlState;
    is_plain =
      (
      offsetof(DataType, control) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SeerCtrlState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__msg__SeerCtrlState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SeerCtrlState = {
  "com_interfaces::msg",
  "SeerCtrlState",
  _SeerCtrlState__cdr_serialize,
  _SeerCtrlState__cdr_deserialize,
  _SeerCtrlState__get_serialized_size,
  _SeerCtrlState__max_serialized_size
};

static rosidl_message_type_support_t _SeerCtrlState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SeerCtrlState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, SeerCtrlState)() {
  return &_SeerCtrlState__type_support;
}

#if defined(__cplusplus)
}
#endif
