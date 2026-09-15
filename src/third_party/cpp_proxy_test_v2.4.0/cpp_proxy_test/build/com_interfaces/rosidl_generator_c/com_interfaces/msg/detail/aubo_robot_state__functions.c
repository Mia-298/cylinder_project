// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:msg/AuboRobotState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/aubo_robot_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_name`
// Member `robot_type`
// Member `robot_soft_index`
// Member `robot_ip`
#include "rosidl_runtime_c/string_functions.h"

bool
com_interfaces__msg__AuboRobotState__init(com_interfaces__msg__AuboRobotState * msg)
{
  if (!msg) {
    return false;
  }
  // robot_index
  // robot_name
  if (!rosidl_runtime_c__String__init(&msg->robot_name)) {
    com_interfaces__msg__AuboRobotState__fini(msg);
    return false;
  }
  // robot_type
  if (!rosidl_runtime_c__String__init(&msg->robot_type)) {
    com_interfaces__msg__AuboRobotState__fini(msg);
    return false;
  }
  // robot_soft_index
  if (!rosidl_runtime_c__String__init(&msg->robot_soft_index)) {
    com_interfaces__msg__AuboRobotState__fini(msg);
    return false;
  }
  // robot_ip
  if (!rosidl_runtime_c__String__init(&msg->robot_ip)) {
    com_interfaces__msg__AuboRobotState__fini(msg);
    return false;
  }
  // mode_type
  // safety_mode_type
  // robot_speed
  // jt_cur_pos
  // tl_cur_pos
  return true;
}

void
com_interfaces__msg__AuboRobotState__fini(com_interfaces__msg__AuboRobotState * msg)
{
  if (!msg) {
    return;
  }
  // robot_index
  // robot_name
  rosidl_runtime_c__String__fini(&msg->robot_name);
  // robot_type
  rosidl_runtime_c__String__fini(&msg->robot_type);
  // robot_soft_index
  rosidl_runtime_c__String__fini(&msg->robot_soft_index);
  // robot_ip
  rosidl_runtime_c__String__fini(&msg->robot_ip);
  // mode_type
  // safety_mode_type
  // robot_speed
  // jt_cur_pos
  // tl_cur_pos
}

bool
com_interfaces__msg__AuboRobotState__are_equal(const com_interfaces__msg__AuboRobotState * lhs, const com_interfaces__msg__AuboRobotState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_index
  if (lhs->robot_index != rhs->robot_index) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_name), &(rhs->robot_name)))
  {
    return false;
  }
  // robot_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_type), &(rhs->robot_type)))
  {
    return false;
  }
  // robot_soft_index
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_soft_index), &(rhs->robot_soft_index)))
  {
    return false;
  }
  // robot_ip
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_ip), &(rhs->robot_ip)))
  {
    return false;
  }
  // mode_type
  if (lhs->mode_type != rhs->mode_type) {
    return false;
  }
  // safety_mode_type
  if (lhs->safety_mode_type != rhs->safety_mode_type) {
    return false;
  }
  // robot_speed
  if (lhs->robot_speed != rhs->robot_speed) {
    return false;
  }
  // jt_cur_pos
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->jt_cur_pos[i] != rhs->jt_cur_pos[i]) {
      return false;
    }
  }
  // tl_cur_pos
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->tl_cur_pos[i] != rhs->tl_cur_pos[i]) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__msg__AuboRobotState__copy(
  const com_interfaces__msg__AuboRobotState * input,
  com_interfaces__msg__AuboRobotState * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_index
  output->robot_index = input->robot_index;
  // robot_name
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_name), &(output->robot_name)))
  {
    return false;
  }
  // robot_type
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_type), &(output->robot_type)))
  {
    return false;
  }
  // robot_soft_index
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_soft_index), &(output->robot_soft_index)))
  {
    return false;
  }
  // robot_ip
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_ip), &(output->robot_ip)))
  {
    return false;
  }
  // mode_type
  output->mode_type = input->mode_type;
  // safety_mode_type
  output->safety_mode_type = input->safety_mode_type;
  // robot_speed
  output->robot_speed = input->robot_speed;
  // jt_cur_pos
  for (size_t i = 0; i < 6; ++i) {
    output->jt_cur_pos[i] = input->jt_cur_pos[i];
  }
  // tl_cur_pos
  for (size_t i = 0; i < 6; ++i) {
    output->tl_cur_pos[i] = input->tl_cur_pos[i];
  }
  return true;
}

com_interfaces__msg__AuboRobotState *
com_interfaces__msg__AuboRobotState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__AuboRobotState * msg = (com_interfaces__msg__AuboRobotState *)allocator.allocate(sizeof(com_interfaces__msg__AuboRobotState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__msg__AuboRobotState));
  bool success = com_interfaces__msg__AuboRobotState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__msg__AuboRobotState__destroy(com_interfaces__msg__AuboRobotState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__msg__AuboRobotState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__msg__AuboRobotState__Sequence__init(com_interfaces__msg__AuboRobotState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__AuboRobotState * data = NULL;

  if (size) {
    data = (com_interfaces__msg__AuboRobotState *)allocator.zero_allocate(size, sizeof(com_interfaces__msg__AuboRobotState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__msg__AuboRobotState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__msg__AuboRobotState__fini(&data[i - 1]);
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
com_interfaces__msg__AuboRobotState__Sequence__fini(com_interfaces__msg__AuboRobotState__Sequence * array)
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
      com_interfaces__msg__AuboRobotState__fini(&array->data[i]);
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

com_interfaces__msg__AuboRobotState__Sequence *
com_interfaces__msg__AuboRobotState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__AuboRobotState__Sequence * array = (com_interfaces__msg__AuboRobotState__Sequence *)allocator.allocate(sizeof(com_interfaces__msg__AuboRobotState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__msg__AuboRobotState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__msg__AuboRobotState__Sequence__destroy(com_interfaces__msg__AuboRobotState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__msg__AuboRobotState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__msg__AuboRobotState__Sequence__are_equal(const com_interfaces__msg__AuboRobotState__Sequence * lhs, const com_interfaces__msg__AuboRobotState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__msg__AuboRobotState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__msg__AuboRobotState__Sequence__copy(
  const com_interfaces__msg__AuboRobotState__Sequence * input,
  com_interfaces__msg__AuboRobotState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__msg__AuboRobotState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__msg__AuboRobotState * data =
      (com_interfaces__msg__AuboRobotState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__msg__AuboRobotState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__msg__AuboRobotState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__msg__AuboRobotState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
