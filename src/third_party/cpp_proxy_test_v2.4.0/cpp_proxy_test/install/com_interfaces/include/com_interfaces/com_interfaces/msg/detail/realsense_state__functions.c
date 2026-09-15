// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:msg/RealsenseState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/realsense_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `err_msg`
// Member `color_topic`
// Member `depth_topic`
// Member `aligned_depth_topic`
// Member `color_info_topic`
// Member `depth_info_topic`
#include "rosidl_runtime_c/string_functions.h"

bool
com_interfaces__msg__RealsenseState__init(com_interfaces__msg__RealsenseState * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    com_interfaces__msg__RealsenseState__fini(msg);
    return false;
  }
  // err_code
  // err_msg
  if (!rosidl_runtime_c__String__init(&msg->err_msg)) {
    com_interfaces__msg__RealsenseState__fini(msg);
    return false;
  }
  // node_online
  // color_ready
  // depth_ready
  // aligned_depth_ready
  // color_info_ready
  // depth_info_ready
  // color_topic
  if (!rosidl_runtime_c__String__init(&msg->color_topic)) {
    com_interfaces__msg__RealsenseState__fini(msg);
    return false;
  }
  // depth_topic
  if (!rosidl_runtime_c__String__init(&msg->depth_topic)) {
    com_interfaces__msg__RealsenseState__fini(msg);
    return false;
  }
  // aligned_depth_topic
  if (!rosidl_runtime_c__String__init(&msg->aligned_depth_topic)) {
    com_interfaces__msg__RealsenseState__fini(msg);
    return false;
  }
  // color_info_topic
  if (!rosidl_runtime_c__String__init(&msg->color_info_topic)) {
    com_interfaces__msg__RealsenseState__fini(msg);
    return false;
  }
  // depth_info_topic
  if (!rosidl_runtime_c__String__init(&msg->depth_info_topic)) {
    com_interfaces__msg__RealsenseState__fini(msg);
    return false;
  }
  // last_color_ts_ms
  // last_depth_ts_ms
  // last_aligned_depth_ts_ms
  // last_color_info_ts_ms
  // last_depth_info_ts_ms
  return true;
}

void
com_interfaces__msg__RealsenseState__fini(com_interfaces__msg__RealsenseState * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // err_code
  // err_msg
  rosidl_runtime_c__String__fini(&msg->err_msg);
  // node_online
  // color_ready
  // depth_ready
  // aligned_depth_ready
  // color_info_ready
  // depth_info_ready
  // color_topic
  rosidl_runtime_c__String__fini(&msg->color_topic);
  // depth_topic
  rosidl_runtime_c__String__fini(&msg->depth_topic);
  // aligned_depth_topic
  rosidl_runtime_c__String__fini(&msg->aligned_depth_topic);
  // color_info_topic
  rosidl_runtime_c__String__fini(&msg->color_info_topic);
  // depth_info_topic
  rosidl_runtime_c__String__fini(&msg->depth_info_topic);
  // last_color_ts_ms
  // last_depth_ts_ms
  // last_aligned_depth_ts_ms
  // last_color_info_ts_ms
  // last_depth_info_ts_ms
}

bool
com_interfaces__msg__RealsenseState__are_equal(const com_interfaces__msg__RealsenseState * lhs, const com_interfaces__msg__RealsenseState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // err_code
  if (lhs->err_code != rhs->err_code) {
    return false;
  }
  // err_msg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->err_msg), &(rhs->err_msg)))
  {
    return false;
  }
  // node_online
  if (lhs->node_online != rhs->node_online) {
    return false;
  }
  // color_ready
  if (lhs->color_ready != rhs->color_ready) {
    return false;
  }
  // depth_ready
  if (lhs->depth_ready != rhs->depth_ready) {
    return false;
  }
  // aligned_depth_ready
  if (lhs->aligned_depth_ready != rhs->aligned_depth_ready) {
    return false;
  }
  // color_info_ready
  if (lhs->color_info_ready != rhs->color_info_ready) {
    return false;
  }
  // depth_info_ready
  if (lhs->depth_info_ready != rhs->depth_info_ready) {
    return false;
  }
  // color_topic
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->color_topic), &(rhs->color_topic)))
  {
    return false;
  }
  // depth_topic
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->depth_topic), &(rhs->depth_topic)))
  {
    return false;
  }
  // aligned_depth_topic
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->aligned_depth_topic), &(rhs->aligned_depth_topic)))
  {
    return false;
  }
  // color_info_topic
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->color_info_topic), &(rhs->color_info_topic)))
  {
    return false;
  }
  // depth_info_topic
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->depth_info_topic), &(rhs->depth_info_topic)))
  {
    return false;
  }
  // last_color_ts_ms
  if (lhs->last_color_ts_ms != rhs->last_color_ts_ms) {
    return false;
  }
  // last_depth_ts_ms
  if (lhs->last_depth_ts_ms != rhs->last_depth_ts_ms) {
    return false;
  }
  // last_aligned_depth_ts_ms
  if (lhs->last_aligned_depth_ts_ms != rhs->last_aligned_depth_ts_ms) {
    return false;
  }
  // last_color_info_ts_ms
  if (lhs->last_color_info_ts_ms != rhs->last_color_info_ts_ms) {
    return false;
  }
  // last_depth_info_ts_ms
  if (lhs->last_depth_info_ts_ms != rhs->last_depth_info_ts_ms) {
    return false;
  }
  return true;
}

bool
com_interfaces__msg__RealsenseState__copy(
  const com_interfaces__msg__RealsenseState * input,
  com_interfaces__msg__RealsenseState * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // err_code
  output->err_code = input->err_code;
  // err_msg
  if (!rosidl_runtime_c__String__copy(
      &(input->err_msg), &(output->err_msg)))
  {
    return false;
  }
  // node_online
  output->node_online = input->node_online;
  // color_ready
  output->color_ready = input->color_ready;
  // depth_ready
  output->depth_ready = input->depth_ready;
  // aligned_depth_ready
  output->aligned_depth_ready = input->aligned_depth_ready;
  // color_info_ready
  output->color_info_ready = input->color_info_ready;
  // depth_info_ready
  output->depth_info_ready = input->depth_info_ready;
  // color_topic
  if (!rosidl_runtime_c__String__copy(
      &(input->color_topic), &(output->color_topic)))
  {
    return false;
  }
  // depth_topic
  if (!rosidl_runtime_c__String__copy(
      &(input->depth_topic), &(output->depth_topic)))
  {
    return false;
  }
  // aligned_depth_topic
  if (!rosidl_runtime_c__String__copy(
      &(input->aligned_depth_topic), &(output->aligned_depth_topic)))
  {
    return false;
  }
  // color_info_topic
  if (!rosidl_runtime_c__String__copy(
      &(input->color_info_topic), &(output->color_info_topic)))
  {
    return false;
  }
  // depth_info_topic
  if (!rosidl_runtime_c__String__copy(
      &(input->depth_info_topic), &(output->depth_info_topic)))
  {
    return false;
  }
  // last_color_ts_ms
  output->last_color_ts_ms = input->last_color_ts_ms;
  // last_depth_ts_ms
  output->last_depth_ts_ms = input->last_depth_ts_ms;
  // last_aligned_depth_ts_ms
  output->last_aligned_depth_ts_ms = input->last_aligned_depth_ts_ms;
  // last_color_info_ts_ms
  output->last_color_info_ts_ms = input->last_color_info_ts_ms;
  // last_depth_info_ts_ms
  output->last_depth_info_ts_ms = input->last_depth_info_ts_ms;
  return true;
}

com_interfaces__msg__RealsenseState *
com_interfaces__msg__RealsenseState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__RealsenseState * msg = (com_interfaces__msg__RealsenseState *)allocator.allocate(sizeof(com_interfaces__msg__RealsenseState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__msg__RealsenseState));
  bool success = com_interfaces__msg__RealsenseState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__msg__RealsenseState__destroy(com_interfaces__msg__RealsenseState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__msg__RealsenseState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__msg__RealsenseState__Sequence__init(com_interfaces__msg__RealsenseState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__RealsenseState * data = NULL;

  if (size) {
    data = (com_interfaces__msg__RealsenseState *)allocator.zero_allocate(size, sizeof(com_interfaces__msg__RealsenseState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__msg__RealsenseState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__msg__RealsenseState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
com_interfaces__msg__RealsenseState__Sequence__fini(com_interfaces__msg__RealsenseState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      com_interfaces__msg__RealsenseState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

com_interfaces__msg__RealsenseState__Sequence *
com_interfaces__msg__RealsenseState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__RealsenseState__Sequence * array = (com_interfaces__msg__RealsenseState__Sequence *)allocator.allocate(sizeof(com_interfaces__msg__RealsenseState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__msg__RealsenseState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__msg__RealsenseState__Sequence__destroy(com_interfaces__msg__RealsenseState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__msg__RealsenseState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__msg__RealsenseState__Sequence__are_equal(const com_interfaces__msg__RealsenseState__Sequence * lhs, const com_interfaces__msg__RealsenseState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__msg__RealsenseState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__msg__RealsenseState__Sequence__copy(
  const com_interfaces__msg__RealsenseState__Sequence * input,
  com_interfaces__msg__RealsenseState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__msg__RealsenseState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__msg__RealsenseState * data =
      (com_interfaces__msg__RealsenseState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__msg__RealsenseState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__msg__RealsenseState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__msg__RealsenseState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
