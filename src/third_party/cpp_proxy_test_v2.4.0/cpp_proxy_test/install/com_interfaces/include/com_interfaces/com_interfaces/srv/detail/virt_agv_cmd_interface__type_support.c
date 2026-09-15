// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from com_interfaces:srv/VirtAgvCmdInterface.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "com_interfaces/srv/detail/virt_agv_cmd_interface__rosidl_typesupport_introspection_c.h"
#include "com_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "com_interfaces/srv/detail/virt_agv_cmd_interface__functions.h"
#include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.h"


// Include directives for member types
// Member `station`
// Member `station_list`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  com_interfaces__srv__VirtAgvCmdInterface_Request__init(message_memory);
}

void com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_fini_function(void * message_memory)
{
  com_interfaces__srv__VirtAgvCmdInterface_Request__fini(message_memory);
}

size_t com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__size_function__VirtAgvCmdInterface_Request__station_list(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__VirtAgvCmdInterface_Request__station_list(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__VirtAgvCmdInterface_Request__station_list(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__fetch_function__VirtAgvCmdInterface_Request__station_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__VirtAgvCmdInterface_Request__station_list(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__assign_function__VirtAgvCmdInterface_Request__station_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__VirtAgvCmdInterface_Request__station_list(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__resize_function__VirtAgvCmdInterface_Request__station_list(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_message_member_array[7] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Request, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "station",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Request, station),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "station_list",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Request, station_list),  // bytes offset in struct
    NULL,  // default value
    com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__size_function__VirtAgvCmdInterface_Request__station_list,  // size() function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__VirtAgvCmdInterface_Request__station_list,  // get_const(index) function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__VirtAgvCmdInterface_Request__station_list,  // get(index) function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__fetch_function__VirtAgvCmdInterface_Request__station_list,  // fetch(index, &value) function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__assign_function__VirtAgvCmdInterface_Request__station_list,  // assign(index, value) function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__resize_function__VirtAgvCmdInterface_Request__station_list  // resize(index) function pointer
  },
  {
    "manual_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Request, manual_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "manual_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Request, manual_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "manual_w",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Request, manual_w),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "manual_duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Request, manual_duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_message_members = {
  "com_interfaces__srv",  // message namespace
  "VirtAgvCmdInterface_Request",  // message name
  7,  // number of fields
  sizeof(com_interfaces__srv__VirtAgvCmdInterface_Request),
  com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_message_member_array,  // message members
  com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_message_type_support_handle = {
  0,
  &com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_com_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, VirtAgvCmdInterface_Request)() {
  if (!com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_message_type_support_handle.typesupport_identifier) {
    com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &com_interfaces__srv__VirtAgvCmdInterface_Request__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__rosidl_typesupport_introspection_c.h"
// already included above
// #include "com_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__functions.h"
// already included above
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.h"


// Include directives for member types
// Member `msg`
// Member `target_station`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `current_station`
// Member `station_list`
#include "com_interfaces/msg/agv_station.h"
// Member `current_station`
// Member `station_list`
#include "com_interfaces/msg/detail/agv_station__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  com_interfaces__srv__VirtAgvCmdInterface_Response__init(message_memory);
}

void com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_fini_function(void * message_memory)
{
  com_interfaces__srv__VirtAgvCmdInterface_Response__fini(message_memory);
}

size_t com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__size_function__VirtAgvCmdInterface_Response__station_list(
  const void * untyped_member)
{
  const com_interfaces__msg__AgvStation__Sequence * member =
    (const com_interfaces__msg__AgvStation__Sequence *)(untyped_member);
  return member->size;
}

const void * com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__get_const_function__VirtAgvCmdInterface_Response__station_list(
  const void * untyped_member, size_t index)
{
  const com_interfaces__msg__AgvStation__Sequence * member =
    (const com_interfaces__msg__AgvStation__Sequence *)(untyped_member);
  return &member->data[index];
}

void * com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__get_function__VirtAgvCmdInterface_Response__station_list(
  void * untyped_member, size_t index)
{
  com_interfaces__msg__AgvStation__Sequence * member =
    (com_interfaces__msg__AgvStation__Sequence *)(untyped_member);
  return &member->data[index];
}

void com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__fetch_function__VirtAgvCmdInterface_Response__station_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const com_interfaces__msg__AgvStation * item =
    ((const com_interfaces__msg__AgvStation *)
    com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__get_const_function__VirtAgvCmdInterface_Response__station_list(untyped_member, index));
  com_interfaces__msg__AgvStation * value =
    (com_interfaces__msg__AgvStation *)(untyped_value);
  *value = *item;
}

void com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__assign_function__VirtAgvCmdInterface_Response__station_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  com_interfaces__msg__AgvStation * item =
    ((com_interfaces__msg__AgvStation *)
    com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__get_function__VirtAgvCmdInterface_Response__station_list(untyped_member, index));
  const com_interfaces__msg__AgvStation * value =
    (const com_interfaces__msg__AgvStation *)(untyped_value);
  *item = *value;
}

bool com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__resize_function__VirtAgvCmdInterface_Response__station_list(
  void * untyped_member, size_t size)
{
  com_interfaces__msg__AgvStation__Sequence * member =
    (com_interfaces__msg__AgvStation__Sequence *)(untyped_member);
  com_interfaces__msg__AgvStation__Sequence__fini(member);
  return com_interfaces__msg__AgvStation__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_member_array[7] = {
  {
    "err_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Response, err_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Response, msg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "task_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Response, task_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "task_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Response, task_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_station",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Response, target_station),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_station",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Response, current_station),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "station_list",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__VirtAgvCmdInterface_Response, station_list),  // bytes offset in struct
    NULL,  // default value
    com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__size_function__VirtAgvCmdInterface_Response__station_list,  // size() function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__get_const_function__VirtAgvCmdInterface_Response__station_list,  // get_const(index) function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__get_function__VirtAgvCmdInterface_Response__station_list,  // get(index) function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__fetch_function__VirtAgvCmdInterface_Response__station_list,  // fetch(index, &value) function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__assign_function__VirtAgvCmdInterface_Response__station_list,  // assign(index, value) function pointer
    com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__resize_function__VirtAgvCmdInterface_Response__station_list  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_members = {
  "com_interfaces__srv",  // message namespace
  "VirtAgvCmdInterface_Response",  // message name
  7,  // number of fields
  sizeof(com_interfaces__srv__VirtAgvCmdInterface_Response),
  com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_member_array,  // message members
  com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_type_support_handle = {
  0,
  &com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_com_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, VirtAgvCmdInterface_Response)() {
  com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, msg, AgvStation)();
  com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, msg, AgvStation)();
  if (!com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_type_support_handle.typesupport_identifier) {
    com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &com_interfaces__srv__VirtAgvCmdInterface_Response__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "com_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers com_interfaces__srv__detail__virt_agv_cmd_interface__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_service_members = {
  "com_interfaces__srv",  // service namespace
  "VirtAgvCmdInterface",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // com_interfaces__srv__detail__virt_agv_cmd_interface__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Request_message_type_support_handle,
  NULL  // response message
  // com_interfaces__srv__detail__virt_agv_cmd_interface__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_Response_message_type_support_handle
};

static rosidl_service_type_support_t com_interfaces__srv__detail__virt_agv_cmd_interface__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_service_type_support_handle = {
  0,
  &com_interfaces__srv__detail__virt_agv_cmd_interface__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, VirtAgvCmdInterface_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, VirtAgvCmdInterface_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_com_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, VirtAgvCmdInterface)() {
  if (!com_interfaces__srv__detail__virt_agv_cmd_interface__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_service_type_support_handle.typesupport_identifier) {
    com_interfaces__srv__detail__virt_agv_cmd_interface__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)com_interfaces__srv__detail__virt_agv_cmd_interface__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, VirtAgvCmdInterface_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, VirtAgvCmdInterface_Response)()->data;
  }

  return &com_interfaces__srv__detail__virt_agv_cmd_interface__rosidl_typesupport_introspection_c__VirtAgvCmdInterface_service_type_support_handle;
}
