// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/AgvControl.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ip'
// Member 'nick_name'
// Member 'desc'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AgvControl in the package com_interfaces.
/**
  * 当前仙工机器人配置控制权信息
 */
typedef struct com_interfaces__msg__AgvControl
{
  /// 当前控制权是否被抢占
  bool locked;
  /// 控制权所有者 IP
  rosidl_runtime_c__String ip;
  /// 控制权所有者端口
  int32_t port;
  /// 控制权所有者类型: 0x00 default, 0x02 roboshop, 0xDD srd
  uint8_t type;
  /// 控制权所有者昵称
  rosidl_runtime_c__String nick_name;
  /// 抢占控制权的时间戳, Unix 秒
  int64_t time;
  /// 控制权所有者描述
  rosidl_runtime_c__String desc;
} com_interfaces__msg__AgvControl;

// Struct for a sequence of com_interfaces__msg__AgvControl.
typedef struct com_interfaces__msg__AgvControl__Sequence
{
  com_interfaces__msg__AgvControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__AgvControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__STRUCT_H_
