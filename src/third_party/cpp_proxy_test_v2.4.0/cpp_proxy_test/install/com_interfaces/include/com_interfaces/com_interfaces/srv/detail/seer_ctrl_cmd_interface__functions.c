// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:srv/SeerCtrlCmdInterface.idl
// generated code does not contain a copyright notice
#include "com_interfaces/srv/detail/seer_ctrl_cmd_interface__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `station`
// Member `station_list`
// Member `nick_name`
#include "rosidl_runtime_c/string_functions.h"

bool
com_interfaces__srv__SeerCtrlCmdInterface_Request__init(com_interfaces__srv__SeerCtrlCmdInterface_Request * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // station
  if (!rosidl_runtime_c__String__init(&msg->station)) {
    com_interfaces__srv__SeerCtrlCmdInterface_Request__fini(msg);
    return false;
  }
  // station_list
  if (!rosidl_runtime_c__String__Sequence__init(&msg->station_list, 0)) {
    com_interfaces__srv__SeerCtrlCmdInterface_Request__fini(msg);
    return false;
  }
  // manual_x
  // manual_y
  // manual_w
  // manual_duration
  // nick_name
  if (!rosidl_runtime_c__String__init(&msg->nick_name)) {
    com_interfaces__srv__SeerCtrlCmdInterface_Request__fini(msg);
    return false;
  }
  return true;
}

void
com_interfaces__srv__SeerCtrlCmdInterface_Request__fini(com_interfaces__srv__SeerCtrlCmdInterface_Request * msg)
{
  if (!msg) {
    return;
  }
  // id
  // station
  rosidl_runtime_c__String__fini(&msg->station);
  // station_list
  rosidl_runtime_c__String__Sequence__fini(&msg->station_list);
  // manual_x
  // manual_y
  // manual_w
  // manual_duration
  // nick_name
  rosidl_runtime_c__String__fini(&msg->nick_name);
}

bool
com_interfaces__srv__SeerCtrlCmdInterface_Request__are_equal(const com_interfaces__srv__SeerCtrlCmdInterface_Request * lhs, const com_interfaces__srv__SeerCtrlCmdInterface_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // station
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->station), &(rhs->station)))
  {
    return false;
  }
  // station_list
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->station_list), &(rhs->station_list)))
  {
    return false;
  }
  // manual_x
  if (lhs->manual_x != rhs->manual_x) {
    return false;
  }
  // manual_y
  if (lhs->manual_y != rhs->manual_y) {
    return false;
  }
  // manual_w
  if (lhs->manual_w != rhs->manual_w) {
    return false;
  }
  // manual_duration
  if (lhs->manual_duration != rhs->manual_duration) {
    return false;
  }
  // nick_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->nick_name), &(rhs->nick_name)))
  {
    return false;
  }
  return true;
}

bool
com_interfaces__srv__SeerCtrlCmdInterface_Request__copy(
  const com_interfaces__srv__SeerCtrlCmdInterface_Request * input,
  com_interfaces__srv__SeerCtrlCmdInterface_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // station
  if (!rosidl_runtime_c__String__copy(
      &(input->station), &(output->station)))
  {
    return false;
  }
  // station_list
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->station_list), &(output->station_list)))
  {
    return false;
  }
  // manual_x
  output->manual_x = input->manual_x;
  // manual_y
  output->manual_y = input->manual_y;
  // manual_w
  output->manual_w = input->manual_w;
  // manual_duration
  output->manual_duration = input->manual_duration;
  // nick_name
  if (!rosidl_runtime_c__String__copy(
      &(input->nick_name), &(output->nick_name)))
  {
    return false;
  }
  return true;
}

com_interfaces__srv__SeerCtrlCmdInterface_Request *
com_interfaces__srv__SeerCtrlCmdInterface_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerCtrlCmdInterface_Request * msg = (com_interfaces__srv__SeerCtrlCmdInterface_Request *)allocator.allocate(sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Request));
  bool success = com_interfaces__srv__SeerCtrlCmdInterface_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__srv__SeerCtrlCmdInterface_Request__destroy(com_interfaces__srv__SeerCtrlCmdInterface_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__srv__SeerCtrlCmdInterface_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__init(com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerCtrlCmdInterface_Request * data = NULL;

  if (size) {
    data = (com_interfaces__srv__SeerCtrlCmdInterface_Request *)allocator.zero_allocate(size, sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__srv__SeerCtrlCmdInterface_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__srv__SeerCtrlCmdInterface_Request__fini(&data[i - 1]);
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
com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__fini(com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence * array)
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
      com_interfaces__srv__SeerCtrlCmdInterface_Request__fini(&array->data[i]);
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

com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence *
com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence * array = (com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence *)allocator.allocate(sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__destroy(com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__are_equal(const com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence * lhs, const com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__srv__SeerCtrlCmdInterface_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__copy(
  const com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence * input,
  com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__srv__SeerCtrlCmdInterface_Request * data =
      (com_interfaces__srv__SeerCtrlCmdInterface_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__srv__SeerCtrlCmdInterface_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__srv__SeerCtrlCmdInterface_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__srv__SeerCtrlCmdInterface_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `msg`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `guide_state`
#include "com_interfaces/msg/detail/agv_guide_state__functions.h"
// Member `control`
#include "com_interfaces/msg/detail/agv_control__functions.h"
// Member `loc`
#include "com_interfaces/msg/detail/agv_loc__functions.h"
// Member `current_station`
// Member `station_list`
#include "com_interfaces/msg/detail/agv_station__functions.h"

bool
com_interfaces__srv__SeerCtrlCmdInterface_Response__init(com_interfaces__srv__SeerCtrlCmdInterface_Response * msg)
{
  if (!msg) {
    return false;
  }
  // err_code
  // msg
  if (!rosidl_runtime_c__String__init(&msg->msg)) {
    com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(msg);
    return false;
  }
  // guide_state
  if (!com_interfaces__msg__AgvGuideState__init(&msg->guide_state)) {
    com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(msg);
    return false;
  }
  // control
  if (!com_interfaces__msg__AgvControl__init(&msg->control)) {
    com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(msg);
    return false;
  }
  // loc
  if (!com_interfaces__msg__AgvLoc__init(&msg->loc)) {
    com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(msg);
    return false;
  }
  // current_station
  if (!com_interfaces__msg__AgvStation__init(&msg->current_station)) {
    com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(msg);
    return false;
  }
  // station_list
  if (!com_interfaces__msg__AgvStation__Sequence__init(&msg->station_list, 0)) {
    com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(msg);
    return false;
  }
  return true;
}

void
com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(com_interfaces__srv__SeerCtrlCmdInterface_Response * msg)
{
  if (!msg) {
    return;
  }
  // err_code
  // msg
  rosidl_runtime_c__String__fini(&msg->msg);
  // guide_state
  com_interfaces__msg__AgvGuideState__fini(&msg->guide_state);
  // control
  com_interfaces__msg__AgvControl__fini(&msg->control);
  // loc
  com_interfaces__msg__AgvLoc__fini(&msg->loc);
  // current_station
  com_interfaces__msg__AgvStation__fini(&msg->current_station);
  // station_list
  com_interfaces__msg__AgvStation__Sequence__fini(&msg->station_list);
}

bool
com_interfaces__srv__SeerCtrlCmdInterface_Response__are_equal(const com_interfaces__srv__SeerCtrlCmdInterface_Response * lhs, const com_interfaces__srv__SeerCtrlCmdInterface_Response * rhs)
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
  // guide_state
  if (!com_interfaces__msg__AgvGuideState__are_equal(
      &(lhs->guide_state), &(rhs->guide_state)))
  {
    return false;
  }
  // control
  if (!com_interfaces__msg__AgvControl__are_equal(
      &(lhs->control), &(rhs->control)))
  {
    return false;
  }
  // loc
  if (!com_interfaces__msg__AgvLoc__are_equal(
      &(lhs->loc), &(rhs->loc)))
  {
    return false;
  }
  // current_station
  if (!com_interfaces__msg__AgvStation__are_equal(
      &(lhs->current_station), &(rhs->current_station)))
  {
    return false;
  }
  // station_list
  if (!com_interfaces__msg__AgvStation__Sequence__are_equal(
      &(lhs->station_list), &(rhs->station_list)))
  {
    return false;
  }
  return true;
}

bool
com_interfaces__srv__SeerCtrlCmdInterface_Response__copy(
  const com_interfaces__srv__SeerCtrlCmdInterface_Response * input,
  com_interfaces__srv__SeerCtrlCmdInterface_Response * output)
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
  // guide_state
  if (!com_interfaces__msg__AgvGuideState__copy(
      &(input->guide_state), &(output->guide_state)))
  {
    return false;
  }
  // control
  if (!com_interfaces__msg__AgvControl__copy(
      &(input->control), &(output->control)))
  {
    return false;
  }
  // loc
  if (!com_interfaces__msg__AgvLoc__copy(
      &(input->loc), &(output->loc)))
  {
    return false;
  }
  // current_station
  if (!com_interfaces__msg__AgvStation__copy(
      &(input->current_station), &(output->current_station)))
  {
    return false;
  }
  // station_list
  if (!com_interfaces__msg__AgvStation__Sequence__copy(
      &(input->station_list), &(output->station_list)))
  {
    return false;
  }
  return true;
}

com_interfaces__srv__SeerCtrlCmdInterface_Response *
com_interfaces__srv__SeerCtrlCmdInterface_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerCtrlCmdInterface_Response * msg = (com_interfaces__srv__SeerCtrlCmdInterface_Response *)allocator.allocate(sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Response));
  bool success = com_interfaces__srv__SeerCtrlCmdInterface_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__srv__SeerCtrlCmdInterface_Response__destroy(com_interfaces__srv__SeerCtrlCmdInterface_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__init(com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerCtrlCmdInterface_Response * data = NULL;

  if (size) {
    data = (com_interfaces__srv__SeerCtrlCmdInterface_Response *)allocator.zero_allocate(size, sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__srv__SeerCtrlCmdInterface_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(&data[i - 1]);
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
com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__fini(com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence * array)
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
      com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(&array->data[i]);
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

com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence *
com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence * array = (com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence *)allocator.allocate(sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__destroy(com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__are_equal(const com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence * lhs, const com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__srv__SeerCtrlCmdInterface_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__copy(
  const com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence * input,
  com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__srv__SeerCtrlCmdInterface_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__srv__SeerCtrlCmdInterface_Response * data =
      (com_interfaces__srv__SeerCtrlCmdInterface_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__srv__SeerCtrlCmdInterface_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__srv__SeerCtrlCmdInterface_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__srv__SeerCtrlCmdInterface_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
