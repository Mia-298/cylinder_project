// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:srv/AuboCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__AUBO_CMD_INTERFACE__STRUCT_H_
#define COM_INTERFACES__SRV__DETAIL__AUBO_CMD_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'program'
// Member 'filename'
#include "rosidl_runtime_c/string.h"
// Member 'joint_path'
#include "com_interfaces/msg/detail/joint_point__struct.h"

/// Struct defined in srv/AuboCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__AuboCmdInterface_Request
{
  /// 指令ID
  int32_t id;
  /// 是否使能
  bool en;
  /// 0-关节坐标,1-笛卡尔坐标
  bool joint_or_desc;
  /// 关节坐标运动:对应关节的6个轴;笛卡尔坐标:0-2对应tran坐标的xyz,3-5对应rpy位姿的rx,ry,rz
  double position[6];
  /// 关节轴运动
  /// 关节的轴，运动的关节轴对应1-6
  uint8_t axid;
  /// 运动的方向，0-负时针,1-顺时针
  uint8_t dir;
  /// 单位:度
  double deg;
  /// 全局设置速度
  double speed;
  /// 全局设置加速度
  double acc;
  /// 以后的工具设置
  int32_t tool;
  /// 机器人操作模式
  int32_t mode;
  /// 系统变量编号
  int32_t register_index;
  /// 系统变量的值
  double register_value;
  /// 0-DI口,1-DO口
  bool input_or_output;
  /// io口的编号 0-15
  int32_t io_index;
  /// io口的状态
  bool io_value;
  /// 加载的程序名称
  rosidl_runtime_c__String program;
  /// 记录的间隔，多少毫秒记一次
  int32_t interval;
  /// csv文件名
  rosidl_runtime_c__String filename;
  /// 关节位置
  com_interfaces__msg__JointPoint__Sequence joint_path;
  /// 夹爪编号
  int32_t gripper_index;
  /// 0-复位，1-激活
  uint8_t act;
  /// 位置百分比，范围
  int32_t gripper_pos;
  /// 速度百分比，范围
  int32_t gripper_vel;
  /// 力矩百分比，范围
  int32_t gripper_force;
  /// 最大等待时间，范围，单位ms
  int32_t max_time;
  /// 0-阻塞，1-非阻塞
  uint8_t gripper_block;
} com_interfaces__srv__AuboCmdInterface_Request;

// Struct for a sequence of com_interfaces__srv__AuboCmdInterface_Request.
typedef struct com_interfaces__srv__AuboCmdInterface_Request__Sequence
{
  com_interfaces__srv__AuboCmdInterface_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__AuboCmdInterface_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'pub_state'
#include "com_interfaces/msg/detail/aubo_robot_state__struct.h"
// Member 'ft'
#include "com_interfaces/msg/detail/force_torque__struct.h"

/// Struct defined in srv/AuboCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__AuboCmdInterface_Response
{
  /// 错误码
  int32_t err_code;
  /// 错误信息
  rosidl_runtime_c__String msg;
  /// 机器人的状态数据
  com_interfaces__msg__AuboRobotState pub_state;
  /// 机器人寄存器值-只读 与register_index同时用
  double register_val;
  /// 机器人IO口值，与input_or_output和io_index同时使用
  bool io_val;
  /// 关节位置
  double jt_pos[6];
  /// 笛卡尔位置
  double tl_pos[6];
  /// 力与力矩
  com_interfaces__msg__ForceTorque ft;
} com_interfaces__srv__AuboCmdInterface_Response;

// Struct for a sequence of com_interfaces__srv__AuboCmdInterface_Response.
typedef struct com_interfaces__srv__AuboCmdInterface_Response__Sequence
{
  com_interfaces__srv__AuboCmdInterface_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__AuboCmdInterface_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__SRV__DETAIL__AUBO_CMD_INTERFACE__STRUCT_H_
