// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/ForcePayload.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ForcePayload in the package com_interfaces.
typedef struct com_interfaces__msg__ForcePayload
{
  double weight;
  double x;
  double y;
  double z;
} com_interfaces__msg__ForcePayload;

// Struct for a sequence of com_interfaces__msg__ForcePayload.
typedef struct com_interfaces__msg__ForcePayload__Sequence
{
  com_interfaces__msg__ForcePayload * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__ForcePayload__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__STRUCT_H_
