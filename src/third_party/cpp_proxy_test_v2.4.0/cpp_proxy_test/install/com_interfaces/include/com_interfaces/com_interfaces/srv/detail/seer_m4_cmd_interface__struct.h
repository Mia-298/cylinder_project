// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:srv/SeerM4CmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SEER_M4_CMD_INTERFACE__STRUCT_H_
#define COM_INTERFACES__SRV__DETAIL__SEER_M4_CMD_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'point'
// Member 'container_id'
// Member 'order_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SeerM4CmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__SeerM4CmdInterface_Request
{
  /// 指令ID
  int32_t id;
  /// 点位
  rosidl_runtime_c__String point;
  /// 货箱ID
  rosidl_runtime_c__String container_id;
  /// 运单号
  rosidl_runtime_c__String order_id;
} com_interfaces__srv__SeerM4CmdInterface_Request;

// Struct for a sequence of com_interfaces__srv__SeerM4CmdInterface_Request.
typedef struct com_interfaces__srv__SeerM4CmdInterface_Request__Sequence
{
  com_interfaces__srv__SeerM4CmdInterface_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__SeerM4CmdInterface_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
// Member 'order_id'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'order_state'
#include "com_interfaces/msg/detail/agv_order_state__struct.h"

/// Struct defined in srv/SeerM4CmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__SeerM4CmdInterface_Response
{
  /// 错误码
  int32_t err_code;
  rosidl_runtime_c__String msg;
  /// 运单号
  rosidl_runtime_c__String order_id;
  com_interfaces__msg__AgvOrderState order_state;
} com_interfaces__srv__SeerM4CmdInterface_Response;

// Struct for a sequence of com_interfaces__srv__SeerM4CmdInterface_Response.
typedef struct com_interfaces__srv__SeerM4CmdInterface_Response__Sequence
{
  com_interfaces__srv__SeerM4CmdInterface_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__SeerM4CmdInterface_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__SRV__DETAIL__SEER_M4_CMD_INTERFACE__STRUCT_H_
