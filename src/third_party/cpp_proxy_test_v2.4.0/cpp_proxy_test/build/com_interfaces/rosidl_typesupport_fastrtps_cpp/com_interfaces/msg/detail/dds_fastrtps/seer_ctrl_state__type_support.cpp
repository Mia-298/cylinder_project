// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:msg/SeerCtrlState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/seer_ctrl_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "com_interfaces/msg/detail/seer_ctrl_state__struct.hpp"

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
bool cdr_serialize(
  const com_interfaces::msg::AgvGuideState &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  com_interfaces::msg::AgvGuideState &);
size_t get_serialized_size(
  const com_interfaces::msg::AgvGuideState &,
  size_t current_alignment);
size_t
max_serialized_size_AgvGuideState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace com_interfaces

namespace com_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const com_interfaces::msg::AgvControl &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  com_interfaces::msg::AgvControl &);
size_t get_serialized_size(
  const com_interfaces::msg::AgvControl &,
  size_t current_alignment);
size_t
max_serialized_size_AgvControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace com_interfaces


namespace com_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_serialize(
  const com_interfaces::msg::SeerCtrlState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;
  // Member: err_code
  cdr << ros_message.err_code;
  // Member: err_msg
  cdr << ros_message.err_msg;
  // Member: pose_x
  cdr << ros_message.pose_x;
  // Member: pose_y
  cdr << ros_message.pose_y;
  // Member: angle
  cdr << ros_message.angle;
  // Member: confidence
  cdr << ros_message.confidence;
  // Member: current_station
  cdr << ros_message.current_station;
  // Member: last_station
  cdr << ros_message.last_station;
  // Member: vel_x
  cdr << ros_message.vel_x;
  // Member: vel_y
  cdr << ros_message.vel_y;
  // Member: vel_ang
  cdr << ros_message.vel_ang;
  // Member: battery_level
  cdr << ros_message.battery_level;
  // Member: battery_temp
  cdr << ros_message.battery_temp;
  // Member: charging
  cdr << (ros_message.charging ? true : false);
  // Member: voltage
  cdr << ros_message.voltage;
  // Member: current
  cdr << ros_message.current;
  // Member: max_charge_voltage
  cdr << ros_message.max_charge_voltage;
  // Member: max_charge_current
  cdr << ros_message.max_charge_current;
  // Member: manual_charge
  cdr << (ros_message.manual_charge ? true : false);
  // Member: auto_charge
  cdr << (ros_message.auto_charge ? true : false);
  // Member: battery_cycle
  cdr << ros_message.battery_cycle;
  // Member: battery_user_data
  cdr << ros_message.battery_user_data;
  // Member: guide_state
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.guide_state,
    cdr);
  // Member: control
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.control,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  com_interfaces::msg::SeerCtrlState & ros_message)
{
  // Member: name
  cdr >> ros_message.name;

  // Member: err_code
  cdr >> ros_message.err_code;

  // Member: err_msg
  cdr >> ros_message.err_msg;

  // Member: pose_x
  cdr >> ros_message.pose_x;

  // Member: pose_y
  cdr >> ros_message.pose_y;

  // Member: angle
  cdr >> ros_message.angle;

  // Member: confidence
  cdr >> ros_message.confidence;

  // Member: current_station
  cdr >> ros_message.current_station;

  // Member: last_station
  cdr >> ros_message.last_station;

  // Member: vel_x
  cdr >> ros_message.vel_x;

  // Member: vel_y
  cdr >> ros_message.vel_y;

  // Member: vel_ang
  cdr >> ros_message.vel_ang;

  // Member: battery_level
  cdr >> ros_message.battery_level;

  // Member: battery_temp
  cdr >> ros_message.battery_temp;

  // Member: charging
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.charging = tmp ? true : false;
  }

  // Member: voltage
  cdr >> ros_message.voltage;

  // Member: current
  cdr >> ros_message.current;

  // Member: max_charge_voltage
  cdr >> ros_message.max_charge_voltage;

  // Member: max_charge_current
  cdr >> ros_message.max_charge_current;

  // Member: manual_charge
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.manual_charge = tmp ? true : false;
  }

  // Member: auto_charge
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.auto_charge = tmp ? true : false;
  }

  // Member: battery_cycle
  cdr >> ros_message.battery_cycle;

  // Member: battery_user_data
  cdr >> ros_message.battery_user_data;

  // Member: guide_state
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.guide_state);

  // Member: control
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.control);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
get_serialized_size(
  const com_interfaces::msg::SeerCtrlState & ros_message,
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
  // Member: pose_x
  {
    size_t item_size = sizeof(ros_message.pose_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pose_y
  {
    size_t item_size = sizeof(ros_message.pose_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle
  {
    size_t item_size = sizeof(ros_message.angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: confidence
  {
    size_t item_size = sizeof(ros_message.confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_station
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.current_station.size() + 1);
  // Member: last_station
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.last_station.size() + 1);
  // Member: vel_x
  {
    size_t item_size = sizeof(ros_message.vel_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_y
  {
    size_t item_size = sizeof(ros_message.vel_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vel_ang
  {
    size_t item_size = sizeof(ros_message.vel_ang);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: battery_level
  {
    size_t item_size = sizeof(ros_message.battery_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: battery_temp
  {
    size_t item_size = sizeof(ros_message.battery_temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: charging
  {
    size_t item_size = sizeof(ros_message.charging);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: voltage
  {
    size_t item_size = sizeof(ros_message.voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current
  {
    size_t item_size = sizeof(ros_message.current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_charge_voltage
  {
    size_t item_size = sizeof(ros_message.max_charge_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_charge_current
  {
    size_t item_size = sizeof(ros_message.max_charge_current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: manual_charge
  {
    size_t item_size = sizeof(ros_message.manual_charge);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: auto_charge
  {
    size_t item_size = sizeof(ros_message.auto_charge);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: battery_cycle
  {
    size_t item_size = sizeof(ros_message.battery_cycle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: battery_user_data
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.battery_user_data.size() + 1);
  // Member: guide_state

  current_alignment +=
    com_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.guide_state, current_alignment);
  // Member: control

  current_alignment +=
    com_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.control, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
max_serialized_size_SeerCtrlState(
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

  // Member: pose_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pose_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: confidence
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: current_station
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

  // Member: last_station
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

  // Member: vel_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vel_ang
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: battery_level
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: battery_temp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: charging
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: max_charge_voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: max_charge_current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: manual_charge
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: auto_charge
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: battery_cycle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: battery_user_data
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

  // Member: guide_state
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        com_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_AgvGuideState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: control
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        com_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_AgvControl(
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
    using DataType = com_interfaces::msg::SeerCtrlState;
    is_plain =
      (
      offsetof(DataType, control) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SeerCtrlState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const com_interfaces::msg::SeerCtrlState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SeerCtrlState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<com_interfaces::msg::SeerCtrlState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SeerCtrlState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const com_interfaces::msg::SeerCtrlState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SeerCtrlState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SeerCtrlState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SeerCtrlState__callbacks = {
  "com_interfaces::msg",
  "SeerCtrlState",
  _SeerCtrlState__cdr_serialize,
  _SeerCtrlState__cdr_deserialize,
  _SeerCtrlState__get_serialized_size,
  _SeerCtrlState__max_serialized_size
};

static rosidl_message_type_support_t _SeerCtrlState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SeerCtrlState__callbacks,
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
get_message_type_support_handle<com_interfaces::msg::SeerCtrlState>()
{
  return &com_interfaces::msg::typesupport_fastrtps_cpp::_SeerCtrlState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, msg, SeerCtrlState)() {
  return &com_interfaces::msg::typesupport_fastrtps_cpp::_SeerCtrlState__handle;
}

#ifdef __cplusplus
}
#endif
