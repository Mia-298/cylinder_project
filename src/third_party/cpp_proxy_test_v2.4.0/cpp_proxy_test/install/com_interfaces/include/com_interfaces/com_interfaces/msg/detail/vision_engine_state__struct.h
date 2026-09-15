// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/VisionEngineState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__VISION_ENGINE_STATE__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__VISION_ENGINE_STATE__STRUCT_H_

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
// Member 'err_msg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/VisionEngineState in the package com_interfaces.
typedef struct com_interfaces__msg__VisionEngineState
{
  /// 名称
  rosidl_runtime_c__String name;
  /// 错误码
  int32_t err_code;
  /// 错误提示信息
  rosidl_runtime_c__String err_msg;
} com_interfaces__msg__VisionEngineState;

// Struct for a sequence of com_interfaces__msg__VisionEngineState.
typedef struct com_interfaces__msg__VisionEngineState__Sequence
{
  com_interfaces__msg__VisionEngineState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__VisionEngineState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__VISION_ENGINE_STATE__STRUCT_H_
