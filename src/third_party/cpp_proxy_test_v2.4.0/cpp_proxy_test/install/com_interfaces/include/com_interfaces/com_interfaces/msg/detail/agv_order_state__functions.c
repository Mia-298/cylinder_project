// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:msg/AgvOrderState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/agv_order_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `id`
// Member `status`
// Member `actual_robot_name`
// Member `step_locations`
// Member `container_id`
// Member `fault_reason`
// Member `execution_reject`
#include "rosidl_runtime_c/string_functions.h"

bool
com_interfaces__msg__AgvOrderState__init(com_interfaces__msg__AgvOrderState * msg)
{
  if (!msg) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__init(&msg->id)) {
    com_interfaces__msg__AgvOrderState__fini(msg);
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    com_interfaces__msg__AgvOrderState__fini(msg);
    return false;
  }
  // actual_robot_name
  if (!rosidl_runtime_c__String__init(&msg->actual_robot_name)) {
    com_interfaces__msg__AgvOrderState__fini(msg);
    return false;
  }
  // current_step_index
  // done_step_index
  // step_num
  // step_locations
  if (!rosidl_runtime_c__String__Sequence__init(&msg->step_locations, 0)) {
    com_interfaces__msg__AgvOrderState__fini(msg);
    return false;
  }
  // container_id
  if (!rosidl_runtime_c__String__init(&msg->container_id)) {
    com_interfaces__msg__AgvOrderState__fini(msg);
    return false;
  }
  // loaded
  // unloaded
  // fault
  // fault_reason
  if (!rosidl_runtime_c__String__init(&msg->fault_reason)) {
    com_interfaces__msg__AgvOrderState__fini(msg);
    return false;
  }
  // execution_reject
  if (!rosidl_runtime_c__String__init(&msg->execution_reject)) {
    com_interfaces__msg__AgvOrderState__fini(msg);
    return false;
  }
  return true;
}

void
com_interfaces__msg__AgvOrderState__fini(com_interfaces__msg__AgvOrderState * msg)
{
  if (!msg) {
    return;
  }
  // id
  rosidl_runtime_c__String__fini(&msg->id);
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // actual_robot_name
  rosidl_runtime_c__String__fini(&msg->actual_robot_name);
  // current_step_index
  // done_step_index
  // step_num
  // step_locations
  rosidl_runtime_c__String__Sequence__fini(&msg->step_locations);
  // container_id
  rosidl_runtime_c__String__fini(&msg->container_id);
  // loaded
  // unloaded
  // fault
  // fault_reason
  rosidl_runtime_c__String__fini(&msg->fault_reason);
  // execution_reject
  rosidl_runtime_c__String__fini(&msg->execution_reject);
}

bool
com_interfaces__msg__AgvOrderState__are_equal(const com_interfaces__msg__AgvOrderState * lhs, const com_interfaces__msg__AgvOrderState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // actual_robot_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->actual_robot_name), &(rhs->actual_robot_name)))
  {
    return false;
  }
  // current_step_index
  if (lhs->current_step_index != rhs->current_step_index) {
    return false;
  }
  // done_step_index
  if (lhs->done_step_index != rhs->done_step_index) {
    return false;
  }
  // step_num
  if (lhs->step_num != rhs->step_num) {
    return false;
  }
  // step_locations
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->step_locations), &(rhs->step_locations)))
  {
    return false;
  }
  // container_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->container_id), &(rhs->container_id)))
  {
    return false;
  }
  // loaded
  if (lhs->loaded != rhs->loaded) {
    return false;
  }
  // unloaded
  if (lhs->unloaded != rhs->unloaded) {
    return false;
  }
  // fault
  if (lhs->fault != rhs->fault) {
    return false;
  }
  // fault_reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->fault_reason), &(rhs->fault_reason)))
  {
    return false;
  }
  // execution_reject
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->execution_reject), &(rhs->execution_reject)))
  {
    return false;
  }
  return true;
}

bool
com_interfaces__msg__AgvOrderState__copy(
  const com_interfaces__msg__AgvOrderState * input,
  com_interfaces__msg__AgvOrderState * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // actual_robot_name
  if (!rosidl_runtime_c__String__copy(
      &(input->actual_robot_name), &(output->actual_robot_name)))
  {
    return false;
  }
  // current_step_index
  output->current_step_index = input->current_step_index;
  // done_step_index
  output->done_step_index = input->done_step_index;
  // step_num
  output->step_num = input->step_num;
  // step_locations
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->step_locations), &(output->step_locations)))
  {
    return false;
  }
  // container_id
  if (!rosidl_runtime_c__String__copy(
      &(input->container_id), &(output->container_id)))
  {
    return false;
  }
  // loaded
  output->loaded = input->loaded;
  // unloaded
  output->unloaded = input->unloaded;
  // fault
  output->fault = input->fault;
  // fault_reason
  if (!rosidl_runtime_c__String__copy(
      &(input->fault_reason), &(output->fault_reason)))
  {
    return false;
  }
  // execution_reject
  if (!rosidl_runtime_c__String__copy(
      &(input->execution_reject), &(output->execution_reject)))
  {
    return false;
  }
  return true;
}

com_interfaces__msg__AgvOrderState *
com_interfaces__msg__AgvOrderState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__AgvOrderState * msg = (com_interfaces__msg__AgvOrderState *)allocator.allocate(sizeof(com_interfaces__msg__AgvOrderState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__msg__AgvOrderState));
  bool success = com_interfaces__msg__AgvOrderState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__msg__AgvOrderState__destroy(com_interfaces__msg__AgvOrderState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__msg__AgvOrderState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__msg__AgvOrderState__Sequence__init(com_interfaces__msg__AgvOrderState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__AgvOrderState * data = NULL;

  if (size) {
    data = (com_interfaces__msg__AgvOrderState *)allocator.zero_allocate(size, sizeof(com_interfaces__msg__AgvOrderState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__msg__AgvOrderState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__msg__AgvOrderState__fini(&data[i - 1]);
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
com_interfaces__msg__AgvOrderState__Sequence__fini(com_interfaces__msg__AgvOrderState__Sequence * array)
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
      com_interfaces__msg__AgvOrderState__fini(&array->data[i]);
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

com_interfaces__msg__AgvOrderState__Sequence *
com_interfaces__msg__AgvOrderState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__AgvOrderState__Sequence * array = (com_interfaces__msg__AgvOrderState__Sequence *)allocator.allocate(sizeof(com_interfaces__msg__AgvOrderState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__msg__AgvOrderState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__msg__AgvOrderState__Sequence__destroy(com_interfaces__msg__AgvOrderState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__msg__AgvOrderState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__msg__AgvOrderState__Sequence__are_equal(const com_interfaces__msg__AgvOrderState__Sequence * lhs, const com_interfaces__msg__AgvOrderState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__msg__AgvOrderState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__msg__AgvOrderState__Sequence__copy(
  const com_interfaces__msg__AgvOrderState__Sequence * input,
  com_interfaces__msg__AgvOrderState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__msg__AgvOrderState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__msg__AgvOrderState * data =
      (com_interfaces__msg__AgvOrderState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__msg__AgvOrderState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__msg__AgvOrderState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__msg__AgvOrderState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
