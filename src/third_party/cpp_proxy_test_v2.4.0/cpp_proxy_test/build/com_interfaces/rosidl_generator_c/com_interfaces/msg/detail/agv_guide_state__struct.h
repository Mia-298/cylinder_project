// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/AgvGuideState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_station'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AgvGuideState in the package com_interfaces.
/**
  * 导航状态, 0 = NONE, 1 = WAITING(目前不可能出现该状态), 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED
 */
typedef struct com_interfaces__msg__AgvGuideState
{
  int32_t task_status;
  /// 导航类型, 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 7 = 平动转动, 100 = 其他
  int32_t task_type;
  /// 导航目标站点
  rosidl_runtime_c__String target_station;
} com_interfaces__msg__AgvGuideState;

// Struct for a sequence of com_interfaces__msg__AgvGuideState.
typedef struct com_interfaces__msg__AgvGuideState__Sequence
{
  com_interfaces__msg__AgvGuideState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__AgvGuideState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__STRUCT_H_
