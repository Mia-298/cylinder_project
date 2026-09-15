// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from com_interfaces:msg/YoloResult.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__STRUCT_H_
#define COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/YoloResult in the package com_interfaces.
typedef struct com_interfaces__msg__YoloResult
{
  int32_t class_id;
  double confidence;
  int32_t x;
  int32_t y;
  int32_t width;
  int32_t height;
} com_interfaces__msg__YoloResult;

// Struct for a sequence of com_interfaces__msg__YoloResult.
typedef struct com_interfaces__msg__YoloResult__Sequence
{
  com_interfaces__msg__YoloResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} com_interfaces__msg__YoloResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__STRUCT_H_
