// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:srv/SeerCtrlCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__STRUCT_H_
#define COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__STRUCT_H_

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
// Member 'nick_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SeerCtrlCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__SeerCtrlCmdInterface_Request
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
  /// 抢占配置控制权时的控制权所有者昵称
  rosidl_runtime_c__String nick_name;
} com_interfaces__srv__SeerCtrlCmdInterface_Request;

// Struct for a sequence of com_interfaces__srv__SeerCtrlCmdInterface_Request.
typedef struct com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence
{
  com_interfaces__srv__SeerCtrlCmdInterface_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'guide_state'
#include "com_interfaces/msg/detail/agv_guide_state__struct.h"
// Member 'control'
#include "com_interfaces/msg/detail/agv_control__struct.h"
// Member 'loc'
#include "com_interfaces/msg/detail/agv_loc__struct.h"
// Member 'current_station'
// Member 'station_list'
#include "com_interfaces/msg/detail/agv_station__struct.h"

/// Struct defined in srv/SeerCtrlCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__SeerCtrlCmdInterface_Response
{
  /// 错误码
  int32_t err_code;
  rosidl_runtime_c__String msg;
  /// 导航状态
  com_interfaces__msg__AgvGuideState guide_state;
  /// 当前控制权信息
  com_interfaces__msg__AgvControl control;
  /// 机器人在世界坐标系中的位置
  com_interfaces__msg__AgvLoc loc;
  com_interfaces__msg__AgvStation current_station;
  com_interfaces__msg__AgvStation__Sequence station_list;
} com_interfaces__srv__SeerCtrlCmdInterface_Response;

// Struct for a sequence of com_interfaces__srv__SeerCtrlCmdInterface_Response.
typedef struct com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence
{
  com_interfaces__srv__SeerCtrlCmdInterface_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__STRUCT_H_
