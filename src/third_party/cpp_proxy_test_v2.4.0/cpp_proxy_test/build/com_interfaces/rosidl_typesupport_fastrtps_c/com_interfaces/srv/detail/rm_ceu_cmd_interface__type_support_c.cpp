// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:srv/RmCeuCmdInterface.idl
// generated code does not contain a copyright notice
#include "com_interfaces/srv/detail/rm_ceu_cmd_interface__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/srv/detail/rm_ceu_cmd_interface__struct.h"
#include "com_interfaces/srv/detail/rm_ceu_cmd_interface__functions.h"
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


// forward declare type support functions


using _RmCeuCmdInterface_Request__ros_msg_type = com_interfaces__srv__RmCeuCmdInterface_Request;

static bool _RmCeuCmdInterface_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RmCeuCmdInterface_Request__ros_msg_type * ros_message = static_cast<const _RmCeuCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: point
  {
    cdr << ros_message->point;
  }

  return true;
}

static bool _RmCeuCmdInterface_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RmCeuCmdInterface_Request__ros_msg_type * ros_message = static_cast<_RmCeuCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr >> ros_message->id;
  }

  // Field name: point
  {
    cdr >> ros_message->point;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__srv__RmCeuCmdInterface_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RmCeuCmdInterface_Request__ros_msg_type * ros_message = static_cast<const _RmCeuCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
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
  // field.name point
  {
    size_t item_size = sizeof(ros_message->point);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RmCeuCmdInterface_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__srv__RmCeuCmdInterface_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__srv__RmCeuCmdInterface_Request(
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
  // member: point
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
    using DataType = com_interfaces__srv__RmCeuCmdInterface_Request;
    is_plain =
      (
      offsetof(DataType, point) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RmCeuCmdInterface_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__srv__RmCeuCmdInterface_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RmCeuCmdInterface_Request = {
  "com_interfaces::srv",
  "RmCeuCmdInterface_Request",
  _RmCeuCmdInterface_Request__cdr_serialize,
  _RmCeuCmdInterface_Request__cdr_deserialize,
  _RmCeuCmdInterface_Request__get_serialized_size,
  _RmCeuCmdInterface_Request__max_serialized_size
};

static rosidl_message_type_support_t _RmCeuCmdInterface_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RmCeuCmdInterface_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, RmCeuCmdInterface_Request)() {
  return &_RmCeuCmdInterface_Request__type_support;
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
// #include "com_interfaces/srv/detail/rm_ceu_cmd_interface__struct.h"
// already included above
// #include "com_interfaces/srv/detail/rm_ceu_cmd_interface__functions.h"
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

#include "rosidl_runtime_c/string.h"  // msg
#include "rosidl_runtime_c/string_functions.h"  // msg

// forward declare type support functions


using _RmCeuCmdInterface_Response__ros_msg_type = com_interfaces__srv__RmCeuCmdInterface_Response;

static bool _RmCeuCmdInterface_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RmCeuCmdInterface_Response__ros_msg_type * ros_message = static_cast<const _RmCeuCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
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

  return true;
}

static bool _RmCeuCmdInterface_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RmCeuCmdInterface_Response__ros_msg_type * ros_message = static_cast<_RmCeuCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
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

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__srv__RmCeuCmdInterface_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RmCeuCmdInterface_Response__ros_msg_type * ros_message = static_cast<const _RmCeuCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
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

  return current_alignment - initial_alignment;
}

static uint32_t _RmCeuCmdInterface_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__srv__RmCeuCmdInterface_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__srv__RmCeuCmdInterface_Response(
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

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = com_interfaces__srv__RmCeuCmdInterface_Response;
    is_plain =
      (
      offsetof(DataType, msg) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RmCeuCmdInterface_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__srv__RmCeuCmdInterface_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RmCeuCmdInterface_Response = {
  "com_interfaces::srv",
  "RmCeuCmdInterface_Response",
  _RmCeuCmdInterface_Response__cdr_serialize,
  _RmCeuCmdInterface_Response__cdr_deserialize,
  _RmCeuCmdInterface_Response__get_serialized_size,
  _RmCeuCmdInterface_Response__max_serialized_size
};

static rosidl_message_type_support_t _RmCeuCmdInterface_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RmCeuCmdInterface_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, RmCeuCmdInterface_Response)() {
  return &_RmCeuCmdInterface_Response__type_support;
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
#include "com_interfaces/srv/rm_ceu_cmd_interface.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t RmCeuCmdInterface__callbacks = {
  "com_interfaces::srv",
  "RmCeuCmdInterface",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, RmCeuCmdInterface_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, RmCeuCmdInterface_Response)(),
};

static rosidl_service_type_support_t RmCeuCmdInterface__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &RmCeuCmdInterface__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, RmCeuCmdInterface)() {
  return &RmCeuCmdInterface__handle;
}

#if defined(__cplusplus)
}
#endif
