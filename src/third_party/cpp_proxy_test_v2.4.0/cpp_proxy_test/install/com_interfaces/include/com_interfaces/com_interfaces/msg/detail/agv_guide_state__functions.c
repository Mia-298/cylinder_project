// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:msg/AgvGuideState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/agv_guide_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_station`
#include "rosidl_runtime_c/string_functions.h"

bool
com_interfaces__msg__AgvGuideState__init(com_interfaces__msg__AgvGuideState * msg)
{
  if (!msg) {
    return false;
  }
  // task_status
  // task_type
  // target_station
  if (!rosidl_runtime_c__String__init(&msg->target_station)) {
    com_interfaces__msg__AgvGuideState__fini(msg);
    return false;
  }
  return true;
}

void
com_interfaces__msg__AgvGuideState__fini(com_interfaces__msg__AgvGuideState * msg)
{
  if (!msg) {
    return;
  }
  // task_status
  // task_type
  // target_station
  rosidl_runtime_c__String__fini(&msg->target_station);
}

bool
com_interfaces__msg__AgvGuideState__are_equal(const com_interfaces__msg__AgvGuideState * lhs, const com_interfaces__msg__AgvGuideState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_status
  if (lhs->task_status != rhs->task_status) {
    return false;
  }
  // task_type
  if (lhs->task_type != rhs->task_type) {
    return false;
  }
  // target_station
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target_station), &(rhs->target_station)))
  {
    return false;
  }
  return true;
}

bool
com_interfaces__msg__AgvGuideState__copy(
  const com_interfaces__msg__AgvGuideState * input,
  com_interfaces__msg__AgvGuideState * output)
{
  if (!input || !output) {
    return false;
  }
  // task_status
  output->task_status = input->task_status;
  // task_type
  output->task_type = input->task_type;
  // target_station
  if (!rosidl_runtime_c__String__copy(
      &(input->target_station), &(output->target_station)))
  {
    return false;
  }
  return true;
}

com_interfaces__msg__AgvGuideState *
com_interfaces__msg__AgvGuideState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__AgvGuideState * msg = (com_interfaces__msg__AgvGuideState *)allocator.allocate(sizeof(com_interfaces__msg__AgvGuideState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__msg__AgvGuideState));
  bool success = com_interfaces__msg__AgvGuideState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__msg__AgvGuideState__destroy(com_interfaces__msg__AgvGuideState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__msg__AgvGuideState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__msg__AgvGuideState__Sequence__init(com_interfaces__msg__AgvGuideState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__AgvGuideState * data = NULL;

  if (size) {
    data = (com_interfaces__msg__AgvGuideState *)allocator.zero_allocate(size, sizeof(com_interfaces__msg__AgvGuideState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__msg__AgvGuideState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__msg__AgvGuideState__fini(&data[i - 1]);
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
com_interfaces__msg__AgvGuideState__Sequence__fini(com_interfaces__msg__AgvGuideState__Sequence * array)
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
      com_interfaces__msg__AgvGuideState__fini(&array->data[i]);
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

com_interfaces__msg__AgvGuideState__Sequence *
com_interfaces__msg__AgvGuideState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__AgvGuideState__Sequence * array = (com_interfaces__msg__AgvGuideState__Sequence *)allocator.allocate(sizeof(com_interfaces__msg__AgvGuideState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__msg__AgvGuideState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__msg__AgvGuideState__Sequence__destroy(com_interfaces__msg__AgvGuideState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__msg__AgvGuideState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__msg__AgvGuideState__Sequence__are_equal(const com_interfaces__msg__AgvGuideState__Sequence * lhs, const com_interfaces__msg__AgvGuideState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__msg__AgvGuideState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__msg__AgvGuideState__Sequence__copy(
  const com_interfaces__msg__AgvGuideState__Sequence * input,
  com_interfaces__msg__AgvGuideState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__msg__AgvGuideState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__msg__AgvGuideState * data =
      (com_interfaces__msg__AgvGuideState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__msg__AgvGuideState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__msg__AgvGuideState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__msg__AgvGuideState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
