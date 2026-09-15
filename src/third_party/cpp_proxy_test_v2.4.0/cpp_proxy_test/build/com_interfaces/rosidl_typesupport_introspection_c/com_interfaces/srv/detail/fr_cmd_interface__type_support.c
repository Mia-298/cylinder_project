// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from com_interfaces:srv/FrCmdInterface.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "com_interfaces/srv/detail/fr_cmd_interface__rosidl_typesupport_introspection_c.h"
#include "com_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "com_interfaces/srv/detail/fr_cmd_interface__functions.h"
#include "com_interfaces/srv/detail/fr_cmd_interface__struct.h"


// Include directives for member types
// Member `program`
// Member `filename`
#include "rosidl_runtime_c/string_functions.h"
// Member `joint_path`
#include "com_interfaces/msg/joint_point.h"
// Member `joint_path`
#include "com_interfaces/msg/detail/joint_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  com_interfaces__srv__FrCmdInterface_Request__init(message_memory);
}

void com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_fini_function(void * message_memory)
{
  com_interfaces__srv__FrCmdInterface_Request__fini(message_memory);
}

size_t com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Request__position(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Request__position(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Request__position(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Request__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Request__position(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Request__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Request__position(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Request__joint_path(
  const void * untyped_member)
{
  const com_interfaces__msg__JointPoint__Sequence * member =
    (const com_interfaces__msg__JointPoint__Sequence *)(untyped_member);
  return member->size;
}

const void * com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Request__joint_path(
  const void * untyped_member, size_t index)
{
  const com_interfaces__msg__JointPoint__Sequence * member =
    (const com_interfaces__msg__JointPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Request__joint_path(
  void * untyped_member, size_t index)
{
  com_interfaces__msg__JointPoint__Sequence * member =
    (com_interfaces__msg__JointPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Request__joint_path(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const com_interfaces__msg__JointPoint * item =
    ((const com_interfaces__msg__JointPoint *)
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Request__joint_path(untyped_member, index));
  com_interfaces__msg__JointPoint * value =
    (com_interfaces__msg__JointPoint *)(untyped_value);
  *value = *item;
}

void com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Request__joint_path(
  void * untyped_member, size_t index, const void * untyped_value)
{
  com_interfaces__msg__JointPoint * item =
    ((com_interfaces__msg__JointPoint *)
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Request__joint_path(untyped_member, index));
  const com_interfaces__msg__JointPoint * value =
    (const com_interfaces__msg__JointPoint *)(untyped_value);
  *item = *value;
}

bool com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__resize_function__FrCmdInterface_Request__joint_path(
  void * untyped_member, size_t size)
{
  com_interfaces__msg__JointPoint__Sequence * member =
    (com_interfaces__msg__JointPoint__Sequence *)(untyped_member);
  com_interfaces__msg__JointPoint__Sequence__fini(member);
  return com_interfaces__msg__JointPoint__Sequence__init(member, size);
}

size_t com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Request__pos_gain(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Request__pos_gain(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Request__pos_gain(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Request__pos_gain(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Request__pos_gain(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Request__pos_gain(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Request__pos_gain(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_member_array[29] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "en",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, en),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_or_desc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, joint_or_desc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, position),  // bytes offset in struct
    NULL,  // default value
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Request__position,  // size() function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Request__position,  // get_const(index) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Request__position,  // get(index) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Request__position,  // fetch(index, &value) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Request__position,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "axid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, axid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dir",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, dir),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "deg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, deg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, acc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tool",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, tool),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "register_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, register_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "register_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, register_value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "input_or_output",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, input_or_output),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "io_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, io_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "io_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, io_value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "program",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, program),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "interval",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, interval),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "filename",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, filename),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, joint_path),  // bytes offset in struct
    NULL,  // default value
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Request__joint_path,  // size() function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Request__joint_path,  // get_const(index) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Request__joint_path,  // get(index) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Request__joint_path,  // fetch(index, &value) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Request__joint_path,  // assign(index, value) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__resize_function__FrCmdInterface_Request__joint_path  // resize(index) function pointer
  },
  {
    "gripper_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, gripper_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "act",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, act),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, gripper_pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, gripper_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_force",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, gripper_force),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, max_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_block",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, gripper_block),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cmd_t",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, cmd_t),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos_gain",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Request, pos_gain),  // bytes offset in struct
    NULL,  // default value
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Request__pos_gain,  // size() function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Request__pos_gain,  // get_const(index) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Request__pos_gain,  // get(index) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Request__pos_gain,  // fetch(index, &value) function pointer
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Request__pos_gain,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_members = {
  "com_interfaces__srv",  // message namespace
  "FrCmdInterface_Request",  // message name
  29,  // number of fields
  sizeof(com_interfaces__srv__FrCmdInterface_Request),
  com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_member_array,  // message members
  com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_type_support_handle = {
  0,
  &com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_com_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, FrCmdInterface_Request)() {
  com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_member_array[19].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, msg, JointPoint)();
  if (!com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_type_support_handle.typesupport_identifier) {
    com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &com_interfaces__srv__FrCmdInterface_Request__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "com_interfaces/srv/detail/fr_cmd_interface__rosidl_typesupport_introspection_c.h"
// already included above
// #include "com_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "com_interfaces/srv/detail/fr_cmd_interface__functions.h"
// already included above
// #include "com_interfaces/srv/detail/fr_cmd_interface__struct.h"


// Include directives for member types
// Member `msg`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `pub_state`
#include "com_interfaces/msg/fr_robot_state.h"
// Member `pub_state`
#include "com_interfaces/msg/detail/fr_robot_state__rosidl_typesupport_introspection_c.h"
// Member `ft`
#include "com_interfaces/msg/force_torque.h"
// Member `ft`
#include "com_interfaces/msg/detail/force_torque__rosidl_typesupport_introspection_c.h"
// Member `force_payload`
#include "com_interfaces/msg/force_payload.h"
// Member `force_payload`
#include "com_interfaces/msg/detail/force_payload__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  com_interfaces__srv__FrCmdInterface_Response__init(message_memory);
}

void com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_fini_function(void * message_memory)
{
  com_interfaces__srv__FrCmdInterface_Response__fini(message_memory);
}

size_t com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Response__jt_pos(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Response__jt_pos(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Response__jt_pos(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Response__jt_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Response__jt_pos(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Response__jt_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Response__jt_pos(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Response__tl_pos(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Response__tl_pos(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Response__tl_pos(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Response__tl_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Response__tl_pos(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Response__tl_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Response__tl_pos(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_member_array[10] = {
  {
    "err_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Response, err_code),  // bytes offset in struct
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
    offsetof(com_interfaces__srv__FrCmdInterface_Response, msg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pub_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Response, pub_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "register_val",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Response, register_val),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "io_val",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Response, io_val),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "jt_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Response, jt_pos),  // bytes offset in struct
    NULL,  // default value
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Response__jt_pos,  // size() function pointer
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Response__jt_pos,  // get_const(index) function pointer
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Response__jt_pos,  // get(index) function pointer
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Response__jt_pos,  // fetch(index, &value) function pointer
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Response__jt_pos,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tl_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Response, tl_pos),  // bytes offset in struct
    NULL,  // default value
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__size_function__FrCmdInterface_Response__tl_pos,  // size() function pointer
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_const_function__FrCmdInterface_Response__tl_pos,  // get_const(index) function pointer
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__get_function__FrCmdInterface_Response__tl_pos,  // get(index) function pointer
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__fetch_function__FrCmdInterface_Response__tl_pos,  // fetch(index, &value) function pointer
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__assign_function__FrCmdInterface_Response__tl_pos,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ft",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Response, ft),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "force_payload",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Response, force_payload),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motion_done",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces__srv__FrCmdInterface_Response, motion_done),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_members = {
  "com_interfaces__srv",  // message namespace
  "FrCmdInterface_Response",  // message name
  10,  // number of fields
  sizeof(com_interfaces__srv__FrCmdInterface_Response),
  com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_member_array,  // message members
  com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_type_support_handle = {
  0,
  &com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_com_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, FrCmdInterface_Response)() {
  com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, msg, FrRobotState)();
  com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, msg, ForceTorque)();
  com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, msg, ForcePayload)();
  if (!com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_type_support_handle.typesupport_identifier) {
    com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &com_interfaces__srv__FrCmdInterface_Response__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "com_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "com_interfaces/srv/detail/fr_cmd_interface__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers com_interfaces__srv__detail__fr_cmd_interface__rosidl_typesupport_introspection_c__FrCmdInterface_service_members = {
  "com_interfaces__srv",  // service namespace
  "FrCmdInterface",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // com_interfaces__srv__detail__fr_cmd_interface__rosidl_typesupport_introspection_c__FrCmdInterface_Request_message_type_support_handle,
  NULL  // response message
  // com_interfaces__srv__detail__fr_cmd_interface__rosidl_typesupport_introspection_c__FrCmdInterface_Response_message_type_support_handle
};

static rosidl_service_type_support_t com_interfaces__srv__detail__fr_cmd_interface__rosidl_typesupport_introspection_c__FrCmdInterface_service_type_support_handle = {
  0,
  &com_interfaces__srv__detail__fr_cmd_interface__rosidl_typesupport_introspection_c__FrCmdInterface_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, FrCmdInterface_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, FrCmdInterface_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_com_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, FrCmdInterface)() {
  if (!com_interfaces__srv__detail__fr_cmd_interface__rosidl_typesupport_introspection_c__FrCmdInterface_service_type_support_handle.typesupport_identifier) {
    com_interfaces__srv__detail__fr_cmd_interface__rosidl_typesupport_introspection_c__FrCmdInterface_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)com_interfaces__srv__detail__fr_cmd_interface__rosidl_typesupport_introspection_c__FrCmdInterface_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, FrCmdInterface_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, com_interfaces, srv, FrCmdInterface_Response)()->data;
  }

  return &com_interfaces__srv__detail__fr_cmd_interface__rosidl_typesupport_introspection_c__FrCmdInterface_service_type_support_handle;
}
