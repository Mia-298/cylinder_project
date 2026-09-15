// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:srv/RfidReaderCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__RFID_READER_CMD_INTERFACE__STRUCT_H_
#define COM_INTERFACES__SRV__DETAIL__RFID_READER_CMD_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/RfidReaderCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__RfidReaderCmdInterface_Request
{
  /// 指令ID
  int32_t id;
  /// 读写器功率
  int32_t power;
} com_interfaces__srv__RfidReaderCmdInterface_Request;

// Struct for a sequence of com_interfaces__srv__RfidReaderCmdInterface_Request.
typedef struct com_interfaces__srv__RfidReaderCmdInterface_Request__Sequence
{
  com_interfaces__srv__RfidReaderCmdInterface_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__RfidReaderCmdInterface_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
// Member 'data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RfidReaderCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__RfidReaderCmdInterface_Response
{
  /// 错误码
  int32_t err_code;
  rosidl_runtime_c__String msg;
  /// 读取到的标签数据
  rosidl_runtime_c__String data;
} com_interfaces__srv__RfidReaderCmdInterface_Response;

// Struct for a sequence of com_interfaces__srv__RfidReaderCmdInterface_Response.
typedef struct com_interfaces__srv__RfidReaderCmdInterface_Response__Sequence
{
  com_interfaces__srv__RfidReaderCmdInterface_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__RfidReaderCmdInterface_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__SRV__DETAIL__RFID_READER_CMD_INTERFACE__STRUCT_H_
