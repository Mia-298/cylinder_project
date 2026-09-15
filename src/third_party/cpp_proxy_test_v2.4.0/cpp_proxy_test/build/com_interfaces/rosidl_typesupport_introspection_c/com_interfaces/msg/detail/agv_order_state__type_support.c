// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from com_interfaces:msg/AgvOrderState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "com_interfaces/msg/detail/agv_order_state__rosidl_typesupport_introspection_c.h"
#include "com_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "com_interfaces/msg/detail/agv_order_state__functions.h"
#include "com_interfaces/msg/detail/agv_order_state__struct.h"


// Include directives for member types
// Member `id`
// Member `status`
// Member `actual_robot_name`
// Member `step_locations`
// Member `container_id`
// Member `fault_reason`
// Member `execution_reject`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  com_interfaces__msg__AgvOrderState__init(message_memory);
}

void com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_fini_function(void * message_memory)
{
  com_interfaces__msg__AgvOrderState__fini(message_memory);
}

size_t com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__size_function__AgvOrderState__step_locations(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__get_const_function__AgvOrderState__step_locations(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__get_function__AgvOrderState__step_locations(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__fetch_function__AgvOrderState__step_locations(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__get_const_function__AgvOrderState__step_locations(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__assign_function__AgvOrderState__step_locations(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__get_function__AgvOrderState__step_locations(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__resize_function__AgvOrderState__step_locations(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_message_member_array[13] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "actual_robot_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, actual_robot_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_step_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, current_step_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "done_step_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, done_step_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "step_num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, step_num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "step_locations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, step_locations),  // bytes offset in struct
    NULL,  // default value
    com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__size_function__AgvOrderState__step_locations,  // size() function pointer
    com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__get_const_function__AgvOrderState__step_locations,  // get_const(index) function pointer
    com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__get_function__AgvOrderState__step_locations,  // get(index) function pointer
    com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__fetch_function__AgvOrderState__step_locations,  // fetch(index, &value) function pointer
    com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__assign_function__AgvOrderState__step_locations,  // assign(index, value) function pointer
    com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__resize_function__AgvOrderState__step_locations  // resize(index) function pointer
  },
  {
    "container_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, container_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "loaded",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, loaded),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "unloaded",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, unloaded),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fault",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, fault),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fault_reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, fault_reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "execution_reject",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__AgvOrderState, execution_reject),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_message_members = {
  "com_interfaces__msg",  // message namespace
  "AgvOrderState",  // message name
  13,  // number of fields
  sizeof(com_interfaces__msg__AgvOrderState),
  com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_message_member_array,  // message members
  com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_init_function,  // function to initialize message memory (memory has to be allocated)
  com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_message_type_support_handle = {
  0,
  &com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_com_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, msg, AgvOrderState)() {
  if (!com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_message_type_support_handle.typesupport_identifier) {
    com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &com_interfaces__msg__AgvOrderState__rosidl_typesupport_introspection_c__AgvOrderState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
