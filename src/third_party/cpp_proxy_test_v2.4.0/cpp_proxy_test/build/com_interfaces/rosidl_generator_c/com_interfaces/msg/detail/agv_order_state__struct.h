// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/AgvOrderState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'id'
// Member 'status'
// Member 'actual_robot_name'
// Member 'step_locations'
// Member 'container_id'
// Member 'fault_reason'
// Member 'execution_reject'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AgvOrderState in the package com_interfaces.
typedef struct com_interfaces__msg__AgvOrderState
{
  /// 单号
  rosidl_runtime_c__String id;
  /// 单据状态
  /// 运单的状态有 8 个枚举值：
  /// - ToBeAllocated
  /// - Allocated
  /// - Pending
  /// - Executing
  /// - Done
  /// - Cancelling
  /// - Cancelled
  /// - Withdrawing
  rosidl_runtime_c__String status;
  /// 实际执行机器人
  rosidl_runtime_c__String actual_robot_name;
  /// 当前正在执行的运单步骤
  int32_t current_step_index;
  /// 已完成执行的运单步骤
  int32_t done_step_index;
  /// 运单由几个步骤构成
  int32_t step_num;
  /// 运单点位列表
  rosidl_runtime_c__String__Sequence step_locations;
  /// 搬运的容器编号
  rosidl_runtime_c__String container_id;
  /// 是否已完成取货
  bool loaded;
  /// 是否已完成放货
  bool unloaded;
  /// 运单执行出现故障
  bool fault;
  /// 故障原因
  rosidl_runtime_c__String fault_reason;
  /// 此运单无法被执行的原因
  rosidl_runtime_c__String execution_reject;
} com_interfaces__msg__AgvOrderState;

// Struct for a sequence of com_interfaces__msg__AgvOrderState.
typedef struct com_interfaces__msg__AgvOrderState__Sequence
{
  com_interfaces__msg__AgvOrderState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__AgvOrderState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__STRUCT_H_
