// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from com_interfaces:msg/JointPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "com_interfaces/msg/detail/joint_point__rosidl_typesupport_introspection_c.h"
#include "com_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "com_interfaces/msg/detail/joint_point__functions.h"
#include "com_interfaces/msg/detail/joint_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  com_interfaces__msg__JointPoint__init(message_memory);
}

void com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_fini_function(void * message_memory)
{
  com_interfaces__msg__JointPoint__fini(message_memory);
}

size_t com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__size_function__JointPoint__joint_point(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__get_const_function__JointPoint__joint_point(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__get_function__JointPoint__joint_point(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__fetch_function__JointPoint__joint_point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__get_const_function__JointPoint__joint_point(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__assign_function__JointPoint__joint_point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__get_function__JointPoint__joint_point(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_message_member_array[1] = {
  {
    "joint_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__msg__JointPoint, joint_point),  // bytes offset in struct
    NULL,  // default value
    com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__size_function__JointPoint__joint_point,  // size() function pointer
    com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__get_const_function__JointPoint__joint_point,  // get_const(index) function pointer
    com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__get_function__JointPoint__joint_point,  // get(index) function pointer
    com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__fetch_function__JointPoint__joint_point,  // fetch(index, &value) function pointer
    com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__assign_function__JointPoint__joint_point,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_message_members = {
  "com_interfaces__msg",  // message namespace
  "JointPoint",  // message name
  1,  // number of fields
  sizeof(com_interfaces__msg__JointPoint),
  com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_message_member_array,  // message members
  com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_message_type_support_handle = {
  0,
  &com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_com_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, msg, JointPoint)() {
  if (!com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_message_type_support_handle.typesupport_identifier) {
    com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &com_interfaces__msg__JointPoint__rosidl_typesupport_introspection_c__JointPoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
