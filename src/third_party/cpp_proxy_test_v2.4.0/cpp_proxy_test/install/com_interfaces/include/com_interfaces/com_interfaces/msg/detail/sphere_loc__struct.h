// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/SphereLoc.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__SPHERE_LOC__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__SPHERE_LOC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SphereLoc in the package com_interfaces.
/**
  * 球体坐标, m
 */
typedef struct com_interfaces__msg__SphereLoc
{
  double x;
  double y;
  double z;
} com_interfaces__msg__SphereLoc;

// Struct for a sequence of com_interfaces__msg__SphereLoc.
typedef struct com_interfaces__msg__SphereLoc__Sequence
{
  com_interfaces__msg__SphereLoc * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__SphereLoc__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__SPHERE_LOC__STRUCT_H_
