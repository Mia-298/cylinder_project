// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/SeerCtrlState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__STRUCT_H_

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
// Member 'battery_user_data'
#include "rosidl_runtime_c/string.h"
// Member 'guide_state'
#include "com_interfaces/msg/detail/agv_guide_state__struct.h"
// Member 'control'
#include "com_interfaces/msg/detail/agv_control__struct.h"

/// Struct defined in msg/SeerCtrlState in the package com_interfaces.
typedef struct com_interfaces__msg__SeerCtrlState
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
  /// 小车电池状态
  /// 电池电量,范围:[0,1]
  double battery_level;
  /// 电池温度,单位:℃
  double battery_temp;
  /// 电池是否正在充电
  bool charging;
  /// 电池电压,单位:V
  double voltage;
  /// 电池电流,单位:A
  double current;
  /// 允许充电的最大电压,-1表示不支持,单位:V
  double max_charge_voltage;
  /// 允许充电的最大电流,-1表示不支持,单位:A
  double max_charge_current;
  /// 是否连接手动充电器
  bool manual_charge;
  /// 是否连接自动充电桩
  bool auto_charge;
  /// 电池循环次数
  int32_t battery_cycle;
  /// 电池用户自定义数据
  rosidl_runtime_c__String battery_user_data;
  /// 小车导航状态
  com_interfaces__msg__AgvGuideState guide_state;
  /// 小车控制权信息
  com_interfaces__msg__AgvControl control;
} com_interfaces__msg__SeerCtrlState;

// Struct for a sequence of com_interfaces__msg__SeerCtrlState.
typedef struct com_interfaces__msg__SeerCtrlState__Sequence
{
  com_interfaces__msg__SeerCtrlState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__SeerCtrlState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__STRUCT_H_
