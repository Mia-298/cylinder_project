// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:msg/VirtAgvState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/virt_agv_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `err_msg`
// Member `current_station`
// Member `last_station`
#include "rosidl_runtime_c/string_functions.h"

bool
com_interfaces__msg__VirtAgvState__init(com_interfaces__msg__VirtAgvState * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    com_interfaces__msg__VirtAgvState__fini(msg);
    return false;
  }
  // err_code
  // err_msg
  if (!rosidl_runtime_c__String__init(&msg->err_msg)) {
    com_interfaces__msg__VirtAgvState__fini(msg);
    return false;
  }
  // pose_x
  // pose_y
  // angle
  // confidence
  // current_station
  if (!rosidl_runtime_c__String__init(&msg->current_station)) {
    com_interfaces__msg__VirtAgvState__fini(msg);
    return false;
  }
  // last_station
  if (!rosidl_runtime_c__String__init(&msg->last_station)) {
    com_interfaces__msg__VirtAgvState__fini(msg);
    return false;
  }
  // vel_x
  // vel_y
  // vel_ang
  return true;
}

void
com_interfaces__msg__VirtAgvState__fini(com_interfaces__msg__VirtAgvState * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // err_code
  // err_msg
  rosidl_runtime_c__String__fini(&msg->err_msg);
  // pose_x
  // pose_y
  // angle
  // confidence
  // current_station
  rosidl_runtime_c__String__fini(&msg->current_station);
  // last_station
  rosidl_runtime_c__String__fini(&msg->last_station);
  // vel_x
  // vel_y
  // vel_ang
}

bool
com_interfaces__msg__VirtAgvState__are_equal(const com_interfaces__msg__VirtAgvState * lhs, const com_interfaces__msg__VirtAgvState * rhs)
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
  // pose_x
  if (lhs->pose_x != rhs->pose_x) {
    return false;
  }
  // pose_y
  if (lhs->pose_y != rhs->pose_y) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // current_station
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->current_station), &(rhs->current_station)))
  {
    return false;
  }
  // last_station
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->last_station), &(rhs->last_station)))
  {
    return false;
  }
  // vel_x
  if (lhs->vel_x != rhs->vel_x) {
    return false;
  }
  // vel_y
  if (lhs->vel_y != rhs->vel_y) {
    return false;
  }
  // vel_ang
  if (lhs->vel_ang != rhs->vel_ang) {
    return false;
  }
  return true;
}

bool
com_interfaces__msg__VirtAgvState__copy(
  const com_interfaces__msg__VirtAgvState * input,
  com_interfaces__msg__VirtAgvState * output)
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
  // pose_x
  output->pose_x = input->pose_x;
  // pose_y
  output->pose_y = input->pose_y;
  // angle
  output->angle = input->angle;
  // confidence
  output->confidence = input->confidence;
  // current_station
  if (!rosidl_runtime_c__String__copy(
      &(input->current_station), &(output->current_station)))
  {
    return false;
  }
  // last_station
  if (!rosidl_runtime_c__String__copy(
      &(input->last_station), &(output->last_station)))
  {
    return false;
  }
  // vel_x
  output->vel_x = input->vel_x;
  // vel_y
  output->vel_y = input->vel_y;
  // vel_ang
  output->vel_ang = input->vel_ang;
  return true;
}

com_interfaces__msg__VirtAgvState *
com_interfaces__msg__VirtAgvState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__VirtAgvState * msg = (com_interfaces__msg__VirtAgvState *)allocator.allocate(sizeof(com_interfaces__msg__VirtAgvState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__msg__VirtAgvState));
  bool success = com_interfaces__msg__VirtAgvState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__msg__VirtAgvState__destroy(com_interfaces__msg__VirtAgvState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__msg__VirtAgvState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__msg__VirtAgvState__Sequence__init(com_interfaces__msg__VirtAgvState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__VirtAgvState * data = NULL;

  if (size) {
    data = (com_interfaces__msg__VirtAgvState *)allocator.zero_allocate(size, sizeof(com_interfaces__msg__VirtAgvState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__msg__VirtAgvState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__msg__VirtAgvState__fini(&data[i - 1]);
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
com_interfaces__msg__VirtAgvState__Sequence__fini(com_interfaces__msg__VirtAgvState__Sequence * array)
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
      com_interfaces__msg__VirtAgvState__fini(&array->data[i]);
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

com_interfaces__msg__VirtAgvState__Sequence *
com_interfaces__msg__VirtAgvState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__VirtAgvState__Sequence * array = (com_interfaces__msg__VirtAgvState__Sequence *)allocator.allocate(sizeof(com_interfaces__msg__VirtAgvState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__msg__VirtAgvState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__msg__VirtAgvState__Sequence__destroy(com_interfaces__msg__VirtAgvState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__msg__VirtAgvState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__msg__VirtAgvState__Sequence__are_equal(const com_interfaces__msg__VirtAgvState__Sequence * lhs, const com_interfaces__msg__VirtAgvState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__msg__VirtAgvState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__msg__VirtAgvState__Sequence__copy(
  const com_interfaces__msg__VirtAgvState__Sequence * input,
  com_interfaces__msg__VirtAgvState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__msg__VirtAgvState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__msg__VirtAgvState * data =
      (com_interfaces__msg__VirtAgvState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__msg__VirtAgvState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__msg__VirtAgvState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__msg__VirtAgvState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
