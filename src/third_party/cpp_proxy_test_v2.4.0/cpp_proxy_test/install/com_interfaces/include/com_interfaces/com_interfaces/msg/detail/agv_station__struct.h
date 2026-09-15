// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/AgvStation.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_STATION__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__AGV_STATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AgvStation in the package com_interfaces.
typedef struct com_interfaces__msg__AgvStation
{
  rosidl_runtime_c__String name;
} com_interfaces__msg__AgvStation;

// Struct for a sequence of com_interfaces__msg__AgvStation.
typedef struct com_interfaces__msg__AgvStation__Sequence
{
  com_interfaces__msg__AgvStation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__AgvStation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_STATION__STRUCT_H_
