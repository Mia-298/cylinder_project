// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:srv/VirtAgvCmdInterface.idl
// generated code does not contain a copyright notice
#include "com_interfaces/srv/detail/virt_agv_cmd_interface__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.h"
#include "com_interfaces/srv/detail/virt_agv_cmd_interface__functions.h"
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

#include "rosidl_runtime_c/string.h"  // station, station_list
#include "rosidl_runtime_c/string_functions.h"  // station, station_list

// forward declare type support functions


using _VirtAgvCmdInterface_Request__ros_msg_type = com_interfaces__srv__VirtAgvCmdInterface_Request;

static bool _VirtAgvCmdInterface_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VirtAgvCmdInterface_Request__ros_msg_type * ros_message = static_cast<const _VirtAgvCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: station
  {
    const rosidl_runtime_c__String * str = &ros_message->station;
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

  // Field name: station_list
  {
    size_t size = ros_message->station_list.size;
    auto array_ptr = ros_message->station_list.data;
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

  // Field name: manual_x
  {
    cdr << ros_message->manual_x;
  }

  // Field name: manual_y
  {
    cdr << ros_message->manual_y;
  }

  // Field name: manual_w
  {
    cdr << ros_message->manual_w;
  }

  // Field name: manual_duration
  {
    cdr << ros_message->manual_duration;
  }

  return true;
}

static bool _VirtAgvCmdInterface_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VirtAgvCmdInterface_Request__ros_msg_type * ros_message = static_cast<_VirtAgvCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr >> ros_message->id;
  }

  // Field name: station
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->station.data) {
      rosidl_runtime_c__String__init(&ros_message->station);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->station,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'station'\n");
      return false;
    }
  }

  // Field name: station_list
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

    if (ros_message->station_list.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->station_list);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->station_list, size)) {
      fprintf(stderr, "failed to create array for field 'station_list'");
      return false;
    }
    auto array_ptr = ros_message->station_list.data;
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
        fprintf(stderr, "failed to assign string into field 'station_list'\n");
        return false;
      }
    }
  }

  // Field name: manual_x
  {
    cdr >> ros_message->manual_x;
  }

  // Field name: manual_y
  {
    cdr >> ros_message->manual_y;
  }

  // Field name: manual_w
  {
    cdr >> ros_message->manual_w;
  }

  // Field name: manual_duration
  {
    cdr >> ros_message->manual_duration;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__srv__VirtAgvCmdInterface_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VirtAgvCmdInterface_Request__ros_msg_type * ros_message = static_cast<const _VirtAgvCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
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
  // field.name station
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->station.size + 1);
  // field.name station_list
  {
    size_t array_size = ros_message->station_list.size;
    auto array_ptr = ros_message->station_list.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name manual_x
  {
    size_t item_size = sizeof(ros_message->manual_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name manual_y
  {
    size_t item_size = sizeof(ros_message->manual_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name manual_w
  {
    size_t item_size = sizeof(ros_message->manual_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name manual_duration
  {
    size_t item_size = sizeof(ros_message->manual_duration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VirtAgvCmdInterface_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__srv__VirtAgvCmdInterface_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__srv__VirtAgvCmdInterface_Request(
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
  // member: station
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
  // member: station_list
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
  // member: manual_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: manual_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: manual_w
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: manual_duration
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = com_interfaces__srv__VirtAgvCmdInterface_Request;
    is_plain =
      (
      offsetof(DataType, manual_duration) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _VirtAgvCmdInterface_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__srv__VirtAgvCmdInterface_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_VirtAgvCmdInterface_Request = {
  "com_interfaces::srv",
  "VirtAgvCmdInterface_Request",
  _VirtAgvCmdInterface_Request__cdr_serialize,
  _VirtAgvCmdInterface_Request__cdr_deserialize,
  _VirtAgvCmdInterface_Request__get_serialized_size,
  _VirtAgvCmdInterface_Request__max_serialized_size
};

static rosidl_message_type_support_t _VirtAgvCmdInterface_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VirtAgvCmdInterface_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VirtAgvCmdInterface_Request)() {
  return &_VirtAgvCmdInterface_Request__type_support;
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
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.h"
// already included above
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__functions.h"
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

#include "com_interfaces/msg/detail/agv_station__functions.h"  // current_station, station_list
// already included above
// #include "rosidl_runtime_c/string.h"  // msg, target_station
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // msg, target_station

// forward declare type support functions
size_t get_serialized_size_com_interfaces__msg__AgvStation(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_com_interfaces__msg__AgvStation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvStation)();


using _VirtAgvCmdInterface_Response__ros_msg_type = com_interfaces__srv__VirtAgvCmdInterface_Response;

static bool _VirtAgvCmdInterface_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VirtAgvCmdInterface_Response__ros_msg_type * ros_message = static_cast<const _VirtAgvCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
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

  // Field name: task_status
  {
    cdr << ros_message->task_status;
  }

  // Field name: task_type
  {
    cdr << ros_message->task_type;
  }

  // Field name: target_station
  {
    const rosidl_runtime_c__String * str = &ros_message->target_station;
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

  // Field name: current_station
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvStation
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->current_station, cdr))
    {
      return false;
    }
  }

  // Field name: station_list
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvStation
      )()->data);
    size_t size = ros_message->station_list.size;
    auto array_ptr = ros_message->station_list.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _VirtAgvCmdInterface_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VirtAgvCmdInterface_Response__ros_msg_type * ros_message = static_cast<_VirtAgvCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
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

  // Field name: task_status
  {
    cdr >> ros_message->task_status;
  }

  // Field name: task_type
  {
    cdr >> ros_message->task_type;
  }

  // Field name: target_station
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->target_station.data) {
      rosidl_runtime_c__String__init(&ros_message->target_station);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->target_station,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'target_station'\n");
      return false;
    }
  }

  // Field name: current_station
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvStation
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->current_station))
    {
      return false;
    }
  }

  // Field name: station_list
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, AgvStation
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

    if (ros_message->station_list.data) {
      com_interfaces__msg__AgvStation__Sequence__fini(&ros_message->station_list);
    }
    if (!com_interfaces__msg__AgvStation__Sequence__init(&ros_message->station_list, size)) {
      fprintf(stderr, "failed to create array for field 'station_list'");
      return false;
    }
    auto array_ptr = ros_message->station_list.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__srv__VirtAgvCmdInterface_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VirtAgvCmdInterface_Response__ros_msg_type * ros_message = static_cast<const _VirtAgvCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
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
  // field.name task_status
  {
    size_t item_size = sizeof(ros_message->task_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_type
  {
    size_t item_size = sizeof(ros_message->task_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_station
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->target_station.size + 1);
  // field.name current_station

  current_alignment += get_serialized_size_com_interfaces__msg__AgvStation(
    &(ros_message->current_station), current_alignment);
  // field.name station_list
  {
    size_t array_size = ros_message->station_list.size;
    auto array_ptr = ros_message->station_list.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_com_interfaces__msg__AgvStation(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VirtAgvCmdInterface_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__srv__VirtAgvCmdInterface_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__srv__VirtAgvCmdInterface_Response(
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
  // member: task_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: task_type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_station
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
  // member: current_station
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_com_interfaces__msg__AgvStation(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: station_list
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
        max_serialized_size_com_interfaces__msg__AgvStation(
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
    using DataType = com_interfaces__srv__VirtAgvCmdInterface_Response;
    is_plain =
      (
      offsetof(DataType, station_list) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _VirtAgvCmdInterface_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__srv__VirtAgvCmdInterface_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_VirtAgvCmdInterface_Response = {
  "com_interfaces::srv",
  "VirtAgvCmdInterface_Response",
  _VirtAgvCmdInterface_Response__cdr_serialize,
  _VirtAgvCmdInterface_Response__cdr_deserialize,
  _VirtAgvCmdInterface_Response__get_serialized_size,
  _VirtAgvCmdInterface_Response__max_serialized_size
};

static rosidl_message_type_support_t _VirtAgvCmdInterface_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VirtAgvCmdInterface_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VirtAgvCmdInterface_Response)() {
  return &_VirtAgvCmdInterface_Response__type_support;
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
#include "com_interfaces/srv/virt_agv_cmd_interface.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t VirtAgvCmdInterface__callbacks = {
  "com_interfaces::srv",
  "VirtAgvCmdInterface",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VirtAgvCmdInterface_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VirtAgvCmdInterface_Response)(),
};

static rosidl_service_type_support_t VirtAgvCmdInterface__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &VirtAgvCmdInterface__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VirtAgvCmdInterface)() {
  return &VirtAgvCmdInterface__handle;
}

#if defined(__cplusplus)
}
#endif
