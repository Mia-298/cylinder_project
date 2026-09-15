// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/JointPoint.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__JOINT_POINT__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__JOINT_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/JointPoint in the package com_interfaces.
typedef struct com_interfaces__msg__JointPoint
{
  double joint_point[6];
} com_interfaces__msg__JointPoint;

// Struct for a sequence of com_interfaces__msg__JointPoint.
typedef struct com_interfaces__msg__JointPoint__Sequence
{
  com_interfaces__msg__JointPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__JointPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__JOINT_POINT__STRUCT_H_
