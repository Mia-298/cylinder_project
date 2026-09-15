// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/FrRobotState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_name'
// Member 'robot_type'
// Member 'robot_soft_index'
// Member 'robot_ip'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/FrRobotState in the package com_interfaces.
typedef struct com_interfaces__msg__FrRobotState
{
  /// 多机械臂需通过编号来区别
  int32_t robot_index;
  /// 表示机械臂的作用或任务
  rosidl_runtime_c__String robot_name;
  /// 机械臂型号
  rosidl_runtime_c__String robot_type;
  /// 机械臂软件版本
  rosidl_runtime_c__String robot_soft_index;
  /// 机器人的IP号
  rosidl_runtime_c__String robot_ip;
  /// 当前任务
  int32_t curtask_index;
  /// 当前任务的执行步骤
  int32_t curstep_index;
  /// 程序运行状态
  uint8_t program_state;
  /// 运动状态
  uint8_t robot_motion_done;
  /// 错误码
  uint8_t robot_err_code;
  /// 主故障码 弃用
  int32_t main_code;
  /// 子故障码 弃用
  int32_t sub_code;
  /// 机器人模式 手动或者自动
  uint8_t robot_mode;
  /// 机器人速度 返回百分比
  double robot_speed;
  /// 关节位置
  double jt_cur_pos[6];
  /// 笛卡尔位置
  double tl_cur_pos[6];
  /// 控制箱数字量IO输出15-8
  uint8_t cl_dgt_output_h;
  /// 控制箱数字量IO输出7-0
  uint8_t cl_dgt_output_l;
  /// 控制箱数字量IO输入15-8
  uint8_t cl_dgt_input_h;
  /// 控制箱数字量IO输入7-0
  uint8_t cl_dgt_input_l;
  /// 控制箱模拟输入AI
  uint16_t cl_analog_input[2];
  /// 控制箱模拟输出AO
  uint16_t cl_analog_output[2];
  /// 工具数字量IO输出7-0 仅bit0和bit1
  uint8_t tl_dgt_output_l;
  /// 工具数字量IO输入7-0 仅bit0和bit1
  uint8_t tl_dgt_input_l;
  /// 急停标志
  uint8_t emergency_stop;
} com_interfaces__msg__FrRobotState;

// Struct for a sequence of com_interfaces__msg__FrRobotState.
typedef struct com_interfaces__msg__FrRobotState__Sequence
{
  com_interfaces__msg__FrRobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__FrRobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__STRUCT_H_
