// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from com_interfaces:srv/VisionEngineCmdInterface.idl
// generated code does not contain a copyright notice
#include "com_interfaces/srv/detail/vision_engine_cmd_interface__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "com_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "com_interfaces/srv/detail/vision_engine_cmd_interface__struct.h"
#include "com_interfaces/srv/detail/vision_engine_cmd_interface__functions.h"
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

#include "rosidl_runtime_c/string.h"  // model_path
#include "rosidl_runtime_c/string_functions.h"  // model_path

// forward declare type support functions


using _VisionEngineCmdInterface_Request__ros_msg_type = com_interfaces__srv__VisionEngineCmdInterface_Request;

static bool _VisionEngineCmdInterface_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VisionEngineCmdInterface_Request__ros_msg_type * ros_message = static_cast<const _VisionEngineCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr << ros_message->id;
  }

  // Field name: desc
  {
    size_t size = 6;
    auto array_ptr = ros_message->desc;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: model_path
  {
    const rosidl_runtime_c__String * str = &ros_message->model_path;
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

  // Field name: input_height
  {
    cdr << ros_message->input_height;
  }

  // Field name: input_width
  {
    cdr << ros_message->input_width;
  }

  // Field name: confidence_threshold
  {
    cdr << ros_message->confidence_threshold;
  }

  // Field name: nms_threshold
  {
    cdr << ros_message->nms_threshold;
  }

  return true;
}

static bool _VisionEngineCmdInterface_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VisionEngineCmdInterface_Request__ros_msg_type * ros_message = static_cast<_VisionEngineCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: id
  {
    cdr >> ros_message->id;
  }

  // Field name: desc
  {
    size_t size = 6;
    auto array_ptr = ros_message->desc;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: model_path
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->model_path.data) {
      rosidl_runtime_c__String__init(&ros_message->model_path);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->model_path,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'model_path'\n");
      return false;
    }
  }

  // Field name: input_height
  {
    cdr >> ros_message->input_height;
  }

  // Field name: input_width
  {
    cdr >> ros_message->input_width;
  }

  // Field name: confidence_threshold
  {
    cdr >> ros_message->confidence_threshold;
  }

  // Field name: nms_threshold
  {
    cdr >> ros_message->nms_threshold;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__srv__VisionEngineCmdInterface_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VisionEngineCmdInterface_Request__ros_msg_type * ros_message = static_cast<const _VisionEngineCmdInterface_Request__ros_msg_type *>(untyped_ros_message);
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
  // field.name desc
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->desc;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name model_path
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->model_path.size + 1);
  // field.name input_height
  {
    size_t item_size = sizeof(ros_message->input_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name input_width
  {
    size_t item_size = sizeof(ros_message->input_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name confidence_threshold
  {
    size_t item_size = sizeof(ros_message->confidence_threshold);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nms_threshold
  {
    size_t item_size = sizeof(ros_message->nms_threshold);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VisionEngineCmdInterface_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__srv__VisionEngineCmdInterface_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__srv__VisionEngineCmdInterface_Request(
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
  // member: desc
  {
    size_t array_size = 6;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: model_path
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
  // member: input_height
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: input_width
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: confidence_threshold
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: nms_threshold
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
    using DataType = com_interfaces__srv__VisionEngineCmdInterface_Request;
    is_plain =
      (
      offsetof(DataType, nms_threshold) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _VisionEngineCmdInterface_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__srv__VisionEngineCmdInterface_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_VisionEngineCmdInterface_Request = {
  "com_interfaces::srv",
  "VisionEngineCmdInterface_Request",
  _VisionEngineCmdInterface_Request__cdr_serialize,
  _VisionEngineCmdInterface_Request__cdr_deserialize,
  _VisionEngineCmdInterface_Request__get_serialized_size,
  _VisionEngineCmdInterface_Request__max_serialized_size
};

static rosidl_message_type_support_t _VisionEngineCmdInterface_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VisionEngineCmdInterface_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VisionEngineCmdInterface_Request)() {
  return &_VisionEngineCmdInterface_Request__type_support;
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
// #include "com_interfaces/srv/detail/vision_engine_cmd_interface__struct.h"
// already included above
// #include "com_interfaces/srv/detail/vision_engine_cmd_interface__functions.h"
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

#include "com_interfaces/msg/detail/sphere_loc__functions.h"  // sphere_loc
#include "com_interfaces/msg/detail/yolo_result__functions.h"  // results
// already included above
// #include "rosidl_runtime_c/string.h"  // msg
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // msg

// forward declare type support functions
size_t get_serialized_size_com_interfaces__msg__SphereLoc(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_com_interfaces__msg__SphereLoc(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, SphereLoc)();
size_t get_serialized_size_com_interfaces__msg__YoloResult(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_com_interfaces__msg__YoloResult(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, msg, YoloResult)();


using _VisionEngineCmdInterface_Response__ros_msg_type = com_interfaces__srv__VisionEngineCmdInterface_Response;

static bool _VisionEngineCmdInterface_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VisionEngineCmdInterface_Response__ros_msg_type * ros_message = static_cast<const _VisionEngineCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
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

  // Field name: results
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, YoloResult
      )()->data);
    size_t size = ros_message->results.size;
    auto array_ptr = ros_message->results.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: sphere_loc
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, SphereLoc
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->sphere_loc, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _VisionEngineCmdInterface_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VisionEngineCmdInterface_Response__ros_msg_type * ros_message = static_cast<_VisionEngineCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
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

  // Field name: results
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, YoloResult
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

    if (ros_message->results.data) {
      com_interfaces__msg__YoloResult__Sequence__fini(&ros_message->results);
    }
    if (!com_interfaces__msg__YoloResult__Sequence__init(&ros_message->results, size)) {
      fprintf(stderr, "failed to create array for field 'results'");
      return false;
    }
    auto array_ptr = ros_message->results.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: sphere_loc
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, com_interfaces, msg, SphereLoc
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->sphere_loc))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t get_serialized_size_com_interfaces__srv__VisionEngineCmdInterface_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VisionEngineCmdInterface_Response__ros_msg_type * ros_message = static_cast<const _VisionEngineCmdInterface_Response__ros_msg_type *>(untyped_ros_message);
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
  // field.name results
  {
    size_t array_size = ros_message->results.size;
    auto array_ptr = ros_message->results.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_com_interfaces__msg__YoloResult(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name sphere_loc

  current_alignment += get_serialized_size_com_interfaces__msg__SphereLoc(
    &(ros_message->sphere_loc), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _VisionEngineCmdInterface_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_com_interfaces__srv__VisionEngineCmdInterface_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_com_interfaces
size_t max_serialized_size_com_interfaces__srv__VisionEngineCmdInterface_Response(
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
  // member: results
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
        max_serialized_size_com_interfaces__msg__YoloResult(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: sphere_loc
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_com_interfaces__msg__SphereLoc(
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
    using DataType = com_interfaces__srv__VisionEngineCmdInterface_Response;
    is_plain =
      (
      offsetof(DataType, sphere_loc) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _VisionEngineCmdInterface_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_com_interfaces__srv__VisionEngineCmdInterface_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_VisionEngineCmdInterface_Response = {
  "com_interfaces::srv",
  "VisionEngineCmdInterface_Response",
  _VisionEngineCmdInterface_Response__cdr_serialize,
  _VisionEngineCmdInterface_Response__cdr_deserialize,
  _VisionEngineCmdInterface_Response__get_serialized_size,
  _VisionEngineCmdInterface_Response__max_serialized_size
};

static rosidl_message_type_support_t _VisionEngineCmdInterface_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VisionEngineCmdInterface_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VisionEngineCmdInterface_Response)() {
  return &_VisionEngineCmdInterface_Response__type_support;
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
#include "com_interfaces/srv/vision_engine_cmd_interface.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t VisionEngineCmdInterface__callbacks = {
  "com_interfaces::srv",
  "VisionEngineCmdInterface",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VisionEngineCmdInterface_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VisionEngineCmdInterface_Response)(),
};

static rosidl_service_type_support_t VisionEngineCmdInterface__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &VisionEngineCmdInterface__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, com_interfaces, srv, VisionEngineCmdInterface)() {
  return &VisionEngineCmdInterface__handle;
}

#if defined(__cplusplus)
}
#endif
