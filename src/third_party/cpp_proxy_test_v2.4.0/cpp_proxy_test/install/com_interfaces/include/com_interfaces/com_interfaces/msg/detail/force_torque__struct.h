// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/ForceTorque.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ForceTorque in the package com_interfaces.
typedef struct com_interfaces__msg__ForceTorque
{
  double fx;
  double fy;
  double fz;
  double tx;
  double ty;
  double tz;
} com_interfaces__msg__ForceTorque;

// Struct for a sequence of com_interfaces__msg__ForceTorque.
typedef struct com_interfaces__msg__ForceTorque__Sequence
{
  com_interfaces__msg__ForceTorque * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__ForceTorque__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__STRUCT_H_
