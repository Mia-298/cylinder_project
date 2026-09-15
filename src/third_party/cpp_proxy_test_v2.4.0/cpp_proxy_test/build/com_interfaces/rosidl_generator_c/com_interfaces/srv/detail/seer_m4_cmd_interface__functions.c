// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:srv/SeerM4CmdInterface.idl
// generated code does not contain a copyright notice
#include "com_interfaces/srv/detail/seer_m4_cmd_interface__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `point`
// Member `container_id`
// Member `order_id`
#include "rosidl_runtime_c/string_functions.h"

bool
com_interfaces__srv__SeerM4CmdInterface_Request__init(com_interfaces__srv__SeerM4CmdInterface_Request * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // point
  if (!rosidl_runtime_c__String__init(&msg->point)) {
    com_interfaces__srv__SeerM4CmdInterface_Request__fini(msg);
    return false;
  }
  // container_id
  if (!rosidl_runtime_c__String__init(&msg->container_id)) {
    com_interfaces__srv__SeerM4CmdInterface_Request__fini(msg);
    return false;
  }
  // order_id
  if (!rosidl_runtime_c__String__init(&msg->order_id)) {
    com_interfaces__srv__SeerM4CmdInterface_Request__fini(msg);
    return false;
  }
  return true;
}

void
com_interfaces__srv__SeerM4CmdInterface_Request__fini(com_interfaces__srv__SeerM4CmdInterface_Request * msg)
{
  if (!msg) {
    return;
  }
  // id
  // point
  rosidl_runtime_c__String__fini(&msg->point);
  // container_id
  rosidl_runtime_c__String__fini(&msg->container_id);
  // order_id
  rosidl_runtime_c__String__fini(&msg->order_id);
}

bool
com_interfaces__srv__SeerM4CmdInterface_Request__are_equal(const com_interfaces__srv__SeerM4CmdInterface_Request * lhs, const com_interfaces__srv__SeerM4CmdInterface_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // point
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  // container_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->container_id), &(rhs->container_id)))
  {
    return false;
  }
  // order_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->order_id), &(rhs->order_id)))
  {
    return false;
  }
  return true;
}

bool
com_interfaces__srv__SeerM4CmdInterface_Request__copy(
  const com_interfaces__srv__SeerM4CmdInterface_Request * input,
  com_interfaces__srv__SeerM4CmdInterface_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // point
  if (!rosidl_runtime_c__String__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  // container_id
  if (!rosidl_runtime_c__String__copy(
      &(input->container_id), &(output->container_id)))
  {
    return false;
  }
  // order_id
  if (!rosidl_runtime_c__String__copy(
      &(input->order_id), &(output->order_id)))
  {
    return false;
  }
  return true;
}

com_interfaces__srv__SeerM4CmdInterface_Request *
com_interfaces__srv__SeerM4CmdInterface_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerM4CmdInterface_Request * msg = (com_interfaces__srv__SeerM4CmdInterface_Request *)allocator.allocate(sizeof(com_interfaces__srv__SeerM4CmdInterface_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__srv__SeerM4CmdInterface_Request));
  bool success = com_interfaces__srv__SeerM4CmdInterface_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__srv__SeerM4CmdInterface_Request__destroy(com_interfaces__srv__SeerM4CmdInterface_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__srv__SeerM4CmdInterface_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__init(com_interfaces__srv__SeerM4CmdInterface_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerM4CmdInterface_Request * data = NULL;

  if (size) {
    data = (com_interfaces__srv__SeerM4CmdInterface_Request *)allocator.zero_allocate(size, sizeof(com_interfaces__srv__SeerM4CmdInterface_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__srv__SeerM4CmdInterface_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__srv__SeerM4CmdInterface_Request__fini(&data[i - 1]);
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
com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__fini(com_interfaces__srv__SeerM4CmdInterface_Request__Sequence * array)
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
      com_interfaces__srv__SeerM4CmdInterface_Request__fini(&array->data[i]);
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

com_interfaces__srv__SeerM4CmdInterface_Request__Sequence *
com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerM4CmdInterface_Request__Sequence * array = (com_interfaces__srv__SeerM4CmdInterface_Request__Sequence *)allocator.allocate(sizeof(com_interfaces__srv__SeerM4CmdInterface_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__destroy(com_interfaces__srv__SeerM4CmdInterface_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__are_equal(const com_interfaces__srv__SeerM4CmdInterface_Request__Sequence * lhs, const com_interfaces__srv__SeerM4CmdInterface_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__srv__SeerM4CmdInterface_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__copy(
  const com_interfaces__srv__SeerM4CmdInterface_Request__Sequence * input,
  com_interfaces__srv__SeerM4CmdInterface_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__srv__SeerM4CmdInterface_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__srv__SeerM4CmdInterface_Request * data =
      (com_interfaces__srv__SeerM4CmdInterface_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__srv__SeerM4CmdInterface_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__srv__SeerM4CmdInterface_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__srv__SeerM4CmdInterface_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `msg`
// Member `order_id`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `order_state`
#include "com_interfaces/msg/detail/agv_order_state__functions.h"

bool
com_interfaces__srv__SeerM4CmdInterface_Response__init(com_interfaces__srv__SeerM4CmdInterface_Response * msg)
{
  if (!msg) {
    return false;
  }
  // err_code
  // msg
  if (!rosidl_runtime_c__String__init(&msg->msg)) {
    com_interfaces__srv__SeerM4CmdInterface_Response__fini(msg);
    return false;
  }
  // order_id
  if (!rosidl_runtime_c__String__init(&msg->order_id)) {
    com_interfaces__srv__SeerM4CmdInterface_Response__fini(msg);
    return false;
  }
  // order_state
  if (!com_interfaces__msg__AgvOrderState__init(&msg->order_state)) {
    com_interfaces__srv__SeerM4CmdInterface_Response__fini(msg);
    return false;
  }
  return true;
}

void
com_interfaces__srv__SeerM4CmdInterface_Response__fini(com_interfaces__srv__SeerM4CmdInterface_Response * msg)
{
  if (!msg) {
    return;
  }
  // err_code
  // msg
  rosidl_runtime_c__String__fini(&msg->msg);
  // order_id
  rosidl_runtime_c__String__fini(&msg->order_id);
  // order_state
  com_interfaces__msg__AgvOrderState__fini(&msg->order_state);
}

bool
com_interfaces__srv__SeerM4CmdInterface_Response__are_equal(const com_interfaces__srv__SeerM4CmdInterface_Response * lhs, const com_interfaces__srv__SeerM4CmdInterface_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // err_code
  if (lhs->err_code != rhs->err_code) {
    return false;
  }
  // msg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->msg), &(rhs->msg)))
  {
    return false;
  }
  // order_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->order_id), &(rhs->order_id)))
  {
    return false;
  }
  // order_state
  if (!com_interfaces__msg__AgvOrderState__are_equal(
      &(lhs->order_state), &(rhs->order_state)))
  {
    return false;
  }
  return true;
}

bool
com_interfaces__srv__SeerM4CmdInterface_Response__copy(
  const com_interfaces__srv__SeerM4CmdInterface_Response * input,
  com_interfaces__srv__SeerM4CmdInterface_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // err_code
  output->err_code = input->err_code;
  // msg
  if (!rosidl_runtime_c__String__copy(
      &(input->msg), &(output->msg)))
  {
    return false;
  }
  // order_id
  if (!rosidl_runtime_c__String__copy(
      &(input->order_id), &(output->order_id)))
  {
    return false;
  }
  // order_state
  if (!com_interfaces__msg__AgvOrderState__copy(
      &(input->order_state), &(output->order_state)))
  {
    return false;
  }
  return true;
}

com_interfaces__srv__SeerM4CmdInterface_Response *
com_interfaces__srv__SeerM4CmdInterface_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerM4CmdInterface_Response * msg = (com_interfaces__srv__SeerM4CmdInterface_Response *)allocator.allocate(sizeof(com_interfaces__srv__SeerM4CmdInterface_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__srv__SeerM4CmdInterface_Response));
  bool success = com_interfaces__srv__SeerM4CmdInterface_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__srv__SeerM4CmdInterface_Response__destroy(com_interfaces__srv__SeerM4CmdInterface_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__srv__SeerM4CmdInterface_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__init(com_interfaces__srv__SeerM4CmdInterface_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerM4CmdInterface_Response * data = NULL;

  if (size) {
    data = (com_interfaces__srv__SeerM4CmdInterface_Response *)allocator.zero_allocate(size, sizeof(com_interfaces__srv__SeerM4CmdInterface_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__srv__SeerM4CmdInterface_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__srv__SeerM4CmdInterface_Response__fini(&data[i - 1]);
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
com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__fini(com_interfaces__srv__SeerM4CmdInterface_Response__Sequence * array)
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
      com_interfaces__srv__SeerM4CmdInterface_Response__fini(&array->data[i]);
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

com_interfaces__srv__SeerM4CmdInterface_Response__Sequence *
com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerM4CmdInterface_Response__Sequence * array = (com_interfaces__srv__SeerM4CmdInterface_Response__Sequence *)allocator.allocate(sizeof(com_interfaces__srv__SeerM4CmdInterface_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__destroy(com_interfaces__srv__SeerM4CmdInterface_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__are_equal(const com_interfaces__srv__SeerM4CmdInterface_Response__Sequence * lhs, const com_interfaces__srv__SeerM4CmdInterface_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__srv__SeerM4CmdInterface_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__copy(
  const com_interfaces__srv__SeerM4CmdInterface_Response__Sequence * input,
  com_interfaces__srv__SeerM4CmdInterface_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__srv__SeerM4CmdInterface_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__srv__SeerM4CmdInterface_Response * data =
      (com_interfaces__srv__SeerM4CmdInterface_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__srv__SeerM4CmdInterface_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__srv__SeerM4CmdInterface_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__srv__SeerM4CmdInterface_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
