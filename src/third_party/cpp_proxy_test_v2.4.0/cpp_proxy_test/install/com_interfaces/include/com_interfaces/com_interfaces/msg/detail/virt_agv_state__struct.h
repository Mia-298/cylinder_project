// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/VirtAgvState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__VIRT_AGV_STATE__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__VIRT_AGV_STATE__STRUCT_H_

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
// Member 'current_station'
// Member 'last_station'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/VirtAgvState in the package com_interfaces.
typedef struct com_interfaces__msg__VirtAgvState
{
  /// 名称
  rosidl_runtime_c__String name;
  /// 错误码
  int32_t err_code;
  /// 错误提示信息
  rosidl_runtime_c__String err_msg;
  /// 小车位置
  /// 小车的x坐标
  double pose_x;
  /// 小车的y坐标
  double pose_y;
  /// 小车的angle坐标
  double angle;
  /// 小车的定位可信度
  double confidence;
  /// 离小车最近站点的id
  rosidl_runtime_c__String current_station;
  /// 小车上一个站点的id
  rosidl_runtime_c__String last_station;
  /// 小车的速度
  /// 小车在x方向上的速度,单位:m/s
  double vel_x;
  /// 小车在y方向上的速度,单位:m/s
  double vel_y;
  /// 小车的角速度,顺时针为正,单位:rad/s
  double vel_ang;
} com_interfaces__msg__VirtAgvState;

// Struct for a sequence of com_interfaces__msg__VirtAgvState.
typedef struct com_interfaces__msg__VirtAgvState__Sequence
{
  com_interfaces__msg__VirtAgvState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__VirtAgvState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__VIRT_AGV_STATE__STRUCT_H_
