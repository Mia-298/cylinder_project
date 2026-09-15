// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:srv/SiemensPlcCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SIEMENS_PLC_CMD_INTERFACE__STRUCT_H_
#define COM_INTERFACES__SRV__DETAIL__SIEMENS_PLC_CMD_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SiemensPlcCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__SiemensPlcCmdInterface_Request
{
  /// 指令ID
  int32_t id;
  /// 引脚
  uint16_t pin;
  /// 数字引脚状态
  uint8_t dpin_state;
} com_interfaces__srv__SiemensPlcCmdInterface_Request;

// Struct for a sequence of com_interfaces__srv__SiemensPlcCmdInterface_Request.
typedef struct com_interfaces__srv__SiemensPlcCmdInterface_Request__Sequence
{
  com_interfaces__srv__SiemensPlcCmdInterface_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__SiemensPlcCmdInterface_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SiemensPlcCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__SiemensPlcCmdInterface_Response
{
  /// 数字引脚状态
  uint8_t dpin_state;
  /// 错误码
  int32_t err_code;
  rosidl_runtime_c__String msg;
} com_interfaces__srv__SiemensPlcCmdInterface_Response;

// Struct for a sequence of com_interfaces__srv__SiemensPlcCmdInterface_Response.
typedef struct com_interfaces__srv__SiemensPlcCmdInterface_Response__Sequence
{
  com_interfaces__srv__SiemensPlcCmdInterface_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__SiemensPlcCmdInterface_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__SRV__DETAIL__SIEMENS_PLC_CMD_INTERFACE__STRUCT_H_
