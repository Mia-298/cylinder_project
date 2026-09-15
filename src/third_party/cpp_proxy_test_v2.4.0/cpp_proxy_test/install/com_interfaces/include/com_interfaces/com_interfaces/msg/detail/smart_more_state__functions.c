// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:msg/SmartMoreState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/smart_more_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `err_msg`
#include "rosidl_runtime_c/string_functions.h"

bool
com_interfaces__msg__SmartMoreState__init(com_interfaces__msg__SmartMoreState * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    com_interfaces__msg__SmartMoreState__fini(msg);
    return false;
  }
  // err_code
  // err_msg
  if (!rosidl_runtime_c__String__init(&msg->err_msg)) {
    com_interfaces__msg__SmartMoreState__fini(msg);
    return false;
  }
  return true;
}

void
com_interfaces__msg__SmartMoreState__fini(com_interfaces__msg__SmartMoreState * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // err_code
  // err_msg
  rosidl_runtime_c__String__fini(&msg->err_msg);
}

bool
com_interfaces__msg__SmartMoreState__are_equal(const com_interfaces__msg__SmartMoreState * lhs, const com_interfaces__msg__SmartMoreState * rhs)
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
  return true;
}

bool
com_interfaces__msg__SmartMoreState__copy(
  const com_interfaces__msg__SmartMoreState * input,
  com_interfaces__msg__SmartMoreState * output)
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
  return true;
}

com_interfaces__msg__SmartMoreState *
com_interfaces__msg__SmartMoreState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__SmartMoreState * msg = (com_interfaces__msg__SmartMoreState *)allocator.allocate(sizeof(com_interfaces__msg__SmartMoreState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__msg__SmartMoreState));
  bool success = com_interfaces__msg__SmartMoreState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__msg__SmartMoreState__destroy(com_interfaces__msg__SmartMoreState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__msg__SmartMoreState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__msg__SmartMoreState__Sequence__init(com_interfaces__msg__SmartMoreState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__SmartMoreState * data = NULL;

  if (size) {
    data = (com_interfaces__msg__SmartMoreState *)allocator.zero_allocate(size, sizeof(com_interfaces__msg__SmartMoreState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__msg__SmartMoreState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__msg__SmartMoreState__fini(&data[i - 1]);
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
com_interfaces__msg__SmartMoreState__Sequence__fini(com_interfaces__msg__SmartMoreState__Sequence * array)
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
      com_interfaces__msg__SmartMoreState__fini(&array->data[i]);
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

com_interfaces__msg__SmartMoreState__Sequence *
com_interfaces__msg__SmartMoreState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__SmartMoreState__Sequence * array = (com_interfaces__msg__SmartMoreState__Sequence *)allocator.allocate(sizeof(com_interfaces__msg__SmartMoreState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__msg__SmartMoreState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__msg__SmartMoreState__Sequence__destroy(com_interfaces__msg__SmartMoreState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__msg__SmartMoreState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__msg__SmartMoreState__Sequence__are_equal(const com_interfaces__msg__SmartMoreState__Sequence * lhs, const com_interfaces__msg__SmartMoreState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__msg__SmartMoreState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__msg__SmartMoreState__Sequence__copy(
  const com_interfaces__msg__SmartMoreState__Sequence * input,
  com_interfaces__msg__SmartMoreState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__msg__SmartMoreState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__msg__SmartMoreState * data =
      (com_interfaces__msg__SmartMoreState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__msg__SmartMoreState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__msg__SmartMoreState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__msg__SmartMoreState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
