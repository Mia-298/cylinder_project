// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:srv/SeerCtrlCmdInterface.idl
// generated code does not contain a copyright notice
#include "com_interfaces/srv/detail/seer_ctrl_cmd_interface__rosidl_typesupport_fastrtps_cpp.hpp"
#include "com_interfaces/srv/detail/seer_ctrl_cmd_interface__struct.hpp"

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_serialize(
  const com_interfaces::srv::SeerCtrlCmdInterface_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: id
  cdr << ros_message.id;
  // Member: station
  cdr << ros_message.station;
  // Member: station_list
  {
    cdr << ros_message.station_list;
  }
  // Member: manual_x
  cdr << ros_message.manual_x;
  // Member: manual_y
  cdr << ros_message.manual_y;
  // Member: manual_w
  cdr << ros_message.manual_w;
  // Member: manual_duration
  cdr << ros_message.manual_duration;
  // Member: nick_name
  cdr << ros_message.nick_name;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  com_interfaces::srv::SeerCtrlCmdInterface_Request & ros_message)
{
  // Member: id
  cdr >> ros_message.id;

  // Member: station
  cdr >> ros_message.station;

  // Member: station_list
  {
    cdr >> ros_message.station_list;
  }

  // Member: manual_x
  cdr >> ros_message.manual_x;

  // Member: manual_y
  cdr >> ros_message.manual_y;

  // Member: manual_w
  cdr >> ros_message.manual_w;

  // Member: manual_duration
  cdr >> ros_message.manual_duration;

  // Member: nick_name
  cdr >> ros_message.nick_name;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
get_serialized_size(
  const com_interfaces::srv::SeerCtrlCmdInterface_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: station
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.station.size() + 1);
  // Member: station_list
  {
    size_t array_size = ros_message.station_list.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.station_list[index].size() + 1);
    }
  }
  // Member: manual_x
  {
    size_t item_size = sizeof(ros_message.manual_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: manual_y
  {
    size_t item_size = sizeof(ros_message.manual_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: manual_w
  {
    size_t item_size = sizeof(ros_message.manual_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: manual_duration
  {
    size_t item_size = sizeof(ros_message.manual_duration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: nick_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.nick_name.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
max_serialized_size_SeerCtrlCmdInterface_Request(
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


  // Member: id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: station
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

  // Member: station_list
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

  // Member: manual_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: manual_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: manual_w
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: manual_duration
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: nick_name
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
    using DataType = com_interfaces::srv::SeerCtrlCmdInterface_Request;
    is_plain =
      (
      offsetof(DataType, nick_name) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SeerCtrlCmdInterface_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const com_interfaces::srv::SeerCtrlCmdInterface_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SeerCtrlCmdInterface_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<com_interfaces::srv::SeerCtrlCmdInterface_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SeerCtrlCmdInterface_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const com_interfaces::srv::SeerCtrlCmdInterface_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SeerCtrlCmdInterface_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SeerCtrlCmdInterface_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SeerCtrlCmdInterface_Request__callbacks = {
  "com_interfaces::srv",
  "SeerCtrlCmdInterface_Request",
  _SeerCtrlCmdInterface_Request__cdr_serialize,
  _SeerCtrlCmdInterface_Request__cdr_deserialize,
  _SeerCtrlCmdInterface_Request__get_serialized_size,
  _SeerCtrlCmdInterface_Request__max_serialized_size
};

static rosidl_message_type_support_t _SeerCtrlCmdInterface_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SeerCtrlCmdInterface_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace com_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_com_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<com_interfaces::srv::SeerCtrlCmdInterface_Request>()
{
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_SeerCtrlCmdInterface_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, SeerCtrlCmdInterface_Request)() {
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_SeerCtrlCmdInterface_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


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
bool cdr_serialize(
  const com_interfaces::msg::AgvLoc &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  com_interfaces::msg::AgvLoc &);
size_t get_serialized_size(
  const com_interfaces::msg::AgvLoc &,
  size_t current_alignment);
size_t
max_serialized_size_AgvLoc(
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
  const com_interfaces::msg::AgvStation &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  com_interfaces::msg::AgvStation &);
size_t get_serialized_size(
  const com_interfaces::msg::AgvStation &,
  size_t current_alignment);
size_t
max_serialized_size_AgvStation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace com_interfaces

// functions for com_interfaces::msg::AgvStation already declared above


namespace com_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_serialize(
  const com_interfaces::srv::SeerCtrlCmdInterface_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: err_code
  cdr << ros_message.err_code;
  // Member: msg
  cdr << ros_message.msg;
  // Member: guide_state
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.guide_state,
    cdr);
  // Member: control
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.control,
    cdr);
  // Member: loc
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.loc,
    cdr);
  // Member: current_station
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.current_station,
    cdr);
  // Member: station_list
  {
    size_t size = ros_message.station_list.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      com_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.station_list[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  com_interfaces::srv::SeerCtrlCmdInterface_Response & ros_message)
{
  // Member: err_code
  cdr >> ros_message.err_code;

  // Member: msg
  cdr >> ros_message.msg;

  // Member: guide_state
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.guide_state);

  // Member: control
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.control);

  // Member: loc
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.loc);

  // Member: current_station
  com_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.current_station);

  // Member: station_list
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

    ros_message.station_list.resize(size);
    for (size_t i = 0; i < size; i++) {
      com_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.station_list[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
get_serialized_size(
  const com_interfaces::srv::SeerCtrlCmdInterface_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: err_code
  {
    size_t item_size = sizeof(ros_message.err_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: msg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.msg.size() + 1);
  // Member: guide_state

  current_alignment +=
    com_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.guide_state, current_alignment);
  // Member: control

  current_alignment +=
    com_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.control, current_alignment);
  // Member: loc

  current_alignment +=
    com_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.loc, current_alignment);
  // Member: current_station

  current_alignment +=
    com_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.current_station, current_alignment);
  // Member: station_list
  {
    size_t array_size = ros_message.station_list.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        com_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.station_list[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_com_interfaces
max_serialized_size_SeerCtrlCmdInterface_Response(
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


  // Member: err_code
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: msg
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

  // Member: loc
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        com_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_AgvLoc(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: current_station
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        com_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_AgvStation(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: station_list
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
      size_t inner_size =
        com_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_AgvStation(
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
    using DataType = com_interfaces::srv::SeerCtrlCmdInterface_Response;
    is_plain =
      (
      offsetof(DataType, station_list) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SeerCtrlCmdInterface_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const com_interfaces::srv::SeerCtrlCmdInterface_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SeerCtrlCmdInterface_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<com_interfaces::srv::SeerCtrlCmdInterface_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SeerCtrlCmdInterface_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const com_interfaces::srv::SeerCtrlCmdInterface_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SeerCtrlCmdInterface_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SeerCtrlCmdInterface_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SeerCtrlCmdInterface_Response__callbacks = {
  "com_interfaces::srv",
  "SeerCtrlCmdInterface_Response",
  _SeerCtrlCmdInterface_Response__cdr_serialize,
  _SeerCtrlCmdInterface_Response__cdr_deserialize,
  _SeerCtrlCmdInterface_Response__get_serialized_size,
  _SeerCtrlCmdInterface_Response__max_serialized_size
};

static rosidl_message_type_support_t _SeerCtrlCmdInterface_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SeerCtrlCmdInterface_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace com_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_com_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<com_interfaces::srv::SeerCtrlCmdInterface_Response>()
{
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_SeerCtrlCmdInterface_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, SeerCtrlCmdInterface_Response)() {
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_SeerCtrlCmdInterface_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace com_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _SeerCtrlCmdInterface__callbacks = {
  "com_interfaces::srv",
  "SeerCtrlCmdInterface",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, SeerCtrlCmdInterface_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, SeerCtrlCmdInterface_Response)(),
};

static rosidl_service_type_support_t _SeerCtrlCmdInterface__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SeerCtrlCmdInterface__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace com_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_com_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<com_interfaces::srv::SeerCtrlCmdInterface>()
{
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_SeerCtrlCmdInterface__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, com_interfaces, srv, SeerCtrlCmdInterface)() {
  return &com_interfaces::srv::typesupport_fastrtps_cpp::_SeerCtrlCmdInterface__handle;
}

#ifdef __cplusplus
}
#endif
