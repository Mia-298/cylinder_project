// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/RealsenseState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__STRUCT_H_

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
// Member 'color_topic'
// Member 'depth_topic'
// Member 'aligned_depth_topic'
// Member 'color_info_topic'
// Member 'depth_info_topic'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RealsenseState in the package com_interfaces.
typedef struct com_interfaces__msg__RealsenseState
{
  /// 名称
  rosidl_runtime_c__String name;
  /// 错误码
  int32_t err_code;
  /// 错误提示信息
  rosidl_runtime_c__String err_msg;
  /// RealSense ROS2 节点是否在线
  bool node_online;
  /// 彩色图话题是否正常
  bool color_ready;
  /// 深度图话题是否正常
  bool depth_ready;
  /// 对齐深度图话题是否正常
  bool aligned_depth_ready;
  /// 彩色相机内参话题是否正常
  bool color_info_ready;
  /// 深度相机内参话题是否正常
  bool depth_info_ready;
  /// 彩色图话题名
  rosidl_runtime_c__String color_topic;
  /// 深度图话题名
  rosidl_runtime_c__String depth_topic;
  /// 对齐深度图话题名
  rosidl_runtime_c__String aligned_depth_topic;
  /// 彩色相机内参话题名
  rosidl_runtime_c__String color_info_topic;
  /// 深度相机内参话题名
  rosidl_runtime_c__String depth_info_topic;
  /// 最近一次收到彩色图消息的本地时间戳(ms)
  uint64_t last_color_ts_ms;
  /// 最近一次收到深度图消息的本地时间戳(ms)
  uint64_t last_depth_ts_ms;
  /// 最近一次收到对齐深度图消息的本地时间戳(ms)
  uint64_t last_aligned_depth_ts_ms;
  /// 最近一次收到彩色相机内参消息的本地时间戳(ms)
  uint64_t last_color_info_ts_ms;
  /// 最近一次收到深度相机内参消息的本地时间戳(ms)
  uint64_t last_depth_info_ts_ms;
} com_interfaces__msg__RealsenseState;

// Struct for a sequence of com_interfaces__msg__RealsenseState.
typedef struct com_interfaces__msg__RealsenseState__Sequence
{
  com_interfaces__msg__RealsenseState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__RealsenseState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__STRUCT_H_
