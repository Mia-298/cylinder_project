// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:srv/VisionEngineCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__STRUCT_H_
#define COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'model_path'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/VisionEngineCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__VisionEngineCmdInterface_Request
{
  /// 指令ID
  int32_t id;
  /// 机械臂末端姿态, 笛卡尔坐标:0-2对应tran坐标的xyz,3-5对应rpy位姿的rx,ry,rz
  double desc[6];
  /// YOLO模型初始化
  /// ONNX模型路径
  rosidl_runtime_c__String model_path;
  /// 模型输入高度
  int32_t input_height;
  /// 模型输入宽度
  int32_t input_width;
  /// YOLO检测参数
  /// 置信度阈值
  double confidence_threshold;
  /// 非极大值抑制阈值
  double nms_threshold;
} com_interfaces__srv__VisionEngineCmdInterface_Request;

// Struct for a sequence of com_interfaces__srv__VisionEngineCmdInterface_Request.
typedef struct com_interfaces__srv__VisionEngineCmdInterface_Request__Sequence
{
  com_interfaces__srv__VisionEngineCmdInterface_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__VisionEngineCmdInterface_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'msg'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'results'
#include "com_interfaces/msg/detail/yolo_result__struct.h"
// Member 'sphere_loc'
#include "com_interfaces/msg/detail/sphere_loc__struct.h"

/// Struct defined in srv/VisionEngineCmdInterface in the package com_interfaces.
typedef struct com_interfaces__srv__VisionEngineCmdInterface_Response
{
  /// 错误码
  int32_t err_code;
  rosidl_runtime_c__String msg;
  /// YOLO检测结果
  com_interfaces__msg__YoloResult__Sequence results;
  /// 球体在相机坐标系中的位置,单位m
  com_interfaces__msg__SphereLoc sphere_loc;
} com_interfaces__srv__VisionEngineCmdInterface_Response;

// Struct for a sequence of com_interfaces__srv__VisionEngineCmdInterface_Response.
typedef struct com_interfaces__srv__VisionEngineCmdInterface_Response__Sequence
{
  com_interfaces__srv__VisionEngineCmdInterface_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__srv__VisionEngineCmdInterface_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__STRUCT_H_
