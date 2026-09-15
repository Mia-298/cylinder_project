// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:srv/VirtAgvCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__VIRT_AGV_CMD_INTERFACE__STRUCT_H_
#define COM_INTERFACES__SRV__DETAIL__VIRT_AGV_CMD_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'station'
// Member 'station_list'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/VirtAgvCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__VirtAgvCmdInterface_Request
{
  /// 指令ID
  int32_t id;
  /// 站点
  rosidl_runtime_c__String station;
  /// 站点列表
  rosidl_runtime_c__String__Sequence station_list;
  /// 手动控制 x方向线速度 vx (机器人坐标系，单位 m/s)
  float manual_x;
  /// 手动控制 y方向线速度 vy (机器人坐标系，单位 m/s)
  float manual_y;
  /// 手动控制 角速度 w (单位 rad/s，逆时针为正，顺时针为负)
  float manual_w;
  /// 手动控制持续时间  (单位 ms, 0 持续执行直到下条指令 | >0 持续指定时间后停止 | <0 视作忽略该参数)
  int32_t manual_duration;
} com_interfaces__srv__VirtAgvCmdInterface_Request;

// Struct for a sequence of com_interfaces__srv__VirtAgvCmdInterface_Request.
typedef struct com_interfaces__srv__VirtAgvCmdInterface_Request__Sequence
{
  com_interfaces__srv__VirtAgvCmdInterface_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__VirtAgvCmdInterface_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
// Member 'target_station'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'current_station'
// Member 'station_list'
#include "com_interfaces/msg/detail/agv_station__struct.h"

/// Struct defined in srv/VirtAgvCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__VirtAgvCmdInterface_Response
{
  /// 错误码
  int32_t err_code;
  rosidl_runtime_c__String msg;
  /// 导航状态 0 = NONE, 1 = WAITING(目前不可能出现该状态), 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED
  int32_t task_status;
  /// 导航类型 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 7 = 平动转动, 100 = 其他
  int32_t task_type;
  /// 导航目标站点
  rosidl_runtime_c__String target_station;
  com_interfaces__msg__AgvStation current_station;
  com_interfaces__msg__AgvStation__Sequence station_list;
} com_interfaces__srv__VirtAgvCmdInterface_Response;

// Struct for a sequence of com_interfaces__srv__VirtAgvCmdInterface_Response.
typedef struct com_interfaces__srv__VirtAgvCmdInterface_Response__Sequence
{
  com_interfaces__srv__VirtAgvCmdInterface_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__VirtAgvCmdInterface_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__SRV__DETAIL__VIRT_AGV_CMD_INTERFACE__STRUCT_H_
