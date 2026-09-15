// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:srv/AuboCmdInterface.idl
// generated code does not contain a copyright notice
#include "com_interfaces/srv/detail/aubo_cmd_interface__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `program`
// Member `filename`
#include "rosidl_runtime_c/string_functions.h"
// Member `joint_path`
#include "com_interfaces/msg/detail/joint_point__functions.h"

bool
com_interfaces__srv__AuboCmdInterface_Request__init(com_interfaces__srv__AuboCmdInterface_Request * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // en
  // joint_or_desc
  // position
  // axid
  // dir
  // deg
  // speed
  // acc
  // tool
  // mode
  // register_index
  // register_value
  // input_or_output
  // io_index
  // io_value
  // program
  if (!rosidl_runtime_c__String__init(&msg->program)) {
    com_interfaces__srv__AuboCmdInterface_Request__fini(msg);
    return false;
  }
  // interval
  // filename
  if (!rosidl_runtime_c__String__init(&msg->filename)) {
    com_interfaces__srv__AuboCmdInterface_Request__fini(msg);
    return false;
  }
  // joint_path
  if (!com_interfaces__msg__JointPoint__Sequence__init(&msg->joint_path, 0)) {
    com_interfaces__srv__AuboCmdInterface_Request__fini(msg);
    return false;
  }
  // gripper_index
  // act
  // gripper_pos
  // gripper_vel
  // gripper_force
  // max_time
  // gripper_block
  return true;
}

void
com_interfaces__srv__AuboCmdInterface_Request__fini(com_interfaces__srv__AuboCmdInterface_Request * msg)
{
  if (!msg) {
    return;
  }
  // id
  // en
  // joint_or_desc
  // position
  // axid
  // dir
  // deg
  // speed
  // acc
  // tool
  // mode
  // register_index
  // register_value
  // input_or_output
  // io_index
  // io_value
  // program
  rosidl_runtime_c__String__fini(&msg->program);
  // interval
  // filename
  rosidl_runtime_c__String__fini(&msg->filename);
  // joint_path
  com_interfaces__msg__JointPoint__Sequence__fini(&msg->joint_path);
  // gripper_index
  // act
  // gripper_pos
  // gripper_vel
  // gripper_force
  // max_time
  // gripper_block
}

bool
com_interfaces__srv__AuboCmdInterface_Request__are_equal(const com_interfaces__srv__AuboCmdInterface_Request * lhs, const com_interfaces__srv__AuboCmdInterface_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // en
  if (lhs->en != rhs->en) {
    return false;
  }
  // joint_or_desc
  if (lhs->joint_or_desc != rhs->joint_or_desc) {
    return false;
  }
  // position
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->position[i] != rhs->position[i]) {
      return false;
    }
  }
  // axid
  if (lhs->axid != rhs->axid) {
    return false;
  }
  // dir
  if (lhs->dir != rhs->dir) {
    return false;
  }
  // deg
  if (lhs->deg != rhs->deg) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // acc
  if (lhs->acc != rhs->acc) {
    return false;
  }
  // tool
  if (lhs->tool != rhs->tool) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // register_index
  if (lhs->register_index != rhs->register_index) {
    return false;
  }
  // register_value
  if (lhs->register_value != rhs->register_value) {
    return false;
  }
  // input_or_output
  if (lhs->input_or_output != rhs->input_or_output) {
    return false;
  }
  // io_index
  if (lhs->io_index != rhs->io_index) {
    return false;
  }
  // io_value
  if (lhs->io_value != rhs->io_value) {
    return false;
  }
  // program
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->program), &(rhs->program)))
  {
    return false;
  }
  // interval
  if (lhs->interval != rhs->interval) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->filename), &(rhs->filename)))
  {
    return false;
  }
  // joint_path
  if (!com_interfaces__msg__JointPoint__Sequence__are_equal(
      &(lhs->joint_path), &(rhs->joint_path)))
  {
    return false;
  }
  // gripper_index
  if (lhs->gripper_index != rhs->gripper_index) {
    return false;
  }
  // act
  if (lhs->act != rhs->act) {
    return false;
  }
  // gripper_pos
  if (lhs->gripper_pos != rhs->gripper_pos) {
    return false;
  }
  // gripper_vel
  if (lhs->gripper_vel != rhs->gripper_vel) {
    return false;
  }
  // gripper_force
  if (lhs->gripper_force != rhs->gripper_force) {
    return false;
  }
  // max_time
  if (lhs->max_time != rhs->max_time) {
    return false;
  }
  // gripper_block
  if (lhs->gripper_block != rhs->gripper_block) {
    return false;
  }
  return true;
}

bool
com_interfaces__srv__AuboCmdInterface_Request__copy(
  const com_interfaces__srv__AuboCmdInterface_Request * input,
  com_interfaces__srv__AuboCmdInterface_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // en
  output->en = input->en;
  // joint_or_desc
  output->joint_or_desc = input->joint_or_desc;
  // position
  for (size_t i = 0; i < 6; ++i) {
    output->position[i] = input->position[i];
  }
  // axid
  output->axid = input->axid;
  // dir
  output->dir = input->dir;
  // deg
  output->deg = input->deg;
  // speed
  output->speed = input->speed;
  // acc
  output->acc = input->acc;
  // tool
  output->tool = input->tool;
  // mode
  output->mode = input->mode;
  // register_index
  output->register_index = input->register_index;
  // register_value
  output->register_value = input->register_value;
  // input_or_output
  output->input_or_output = input->input_or_output;
  // io_index
  output->io_index = input->io_index;
  // io_value
  output->io_value = input->io_value;
  // program
  if (!rosidl_runtime_c__String__copy(
      &(input->program), &(output->program)))
  {
    return false;
  }
  // interval
  output->interval = input->interval;
  // filename
  if (!rosidl_runtime_c__String__copy(
      &(input->filename), &(output->filename)))
  {
    return false;
  }
  // joint_path
  if (!com_interfaces__msg__JointPoint__Sequence__copy(
      &(input->joint_path), &(output->joint_path)))
  {
    return false;
  }
  // gripper_index
  output->gripper_index = input->gripper_index;
  // act
  output->act = input->act;
  // gripper_pos
  output->gripper_pos = input->gripper_pos;
  // gripper_vel
  output->gripper_vel = input->gripper_vel;
  // gripper_force
  output->gripper_force = input->gripper_force;
  // max_time
  output->max_time = input->max_time;
  // gripper_block
  output->gripper_block = input->gripper_block;
  return true;
}

com_interfaces__srv__AuboCmdInterface_Request *
com_interfaces__srv__AuboCmdInterface_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__AuboCmdInterface_Request * msg = (com_interfaces__srv__AuboCmdInterface_Request *)allocator.allocate(sizeof(com_interfaces__srv__AuboCmdInterface_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__srv__AuboCmdInterface_Request));
  bool success = com_interfaces__srv__AuboCmdInterface_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__srv__AuboCmdInterface_Request__destroy(com_interfaces__srv__AuboCmdInterface_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__srv__AuboCmdInterface_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__srv__AuboCmdInterface_Request__Sequence__init(com_interfaces__srv__AuboCmdInterface_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__AuboCmdInterface_Request * data = NULL;

  if (size) {
    data = (com_interfaces__srv__AuboCmdInterface_Request *)allocator.zero_allocate(size, sizeof(com_interfaces__srv__AuboCmdInterface_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__srv__AuboCmdInterface_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__srv__AuboCmdInterface_Request__fini(&data[i - 1]);
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
com_interfaces__srv__AuboCmdInterface_Request__Sequence__fini(com_interfaces__srv__AuboCmdInterface_Request__Sequence * array)
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
      com_interfaces__srv__AuboCmdInterface_Request__fini(&array->data[i]);
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

com_interfaces__srv__AuboCmdInterface_Request__Sequence *
com_interfaces__srv__AuboCmdInterface_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__AuboCmdInterface_Request__Sequence * array = (com_interfaces__srv__AuboCmdInterface_Request__Sequence *)allocator.allocate(sizeof(com_interfaces__srv__AuboCmdInterface_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__srv__AuboCmdInterface_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__srv__AuboCmdInterface_Request__Sequence__destroy(com_interfaces__srv__AuboCmdInterface_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__srv__AuboCmdInterface_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__srv__AuboCmdInterface_Request__Sequence__are_equal(const com_interfaces__srv__AuboCmdInterface_Request__Sequence * lhs, const com_interfaces__srv__AuboCmdInterface_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__srv__AuboCmdInterface_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__srv__AuboCmdInterface_Request__Sequence__copy(
  const com_interfaces__srv__AuboCmdInterface_Request__Sequence * input,
  com_interfaces__srv__AuboCmdInterface_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__srv__AuboCmdInterface_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__srv__AuboCmdInterface_Request * data =
      (com_interfaces__srv__AuboCmdInterface_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__srv__AuboCmdInterface_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__srv__AuboCmdInterface_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__srv__AuboCmdInterface_Request__copy(
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
// Member `pub_state`
#include "com_interfaces/msg/detail/aubo_robot_state__functions.h"
// Member `ft`
#include "com_interfaces/msg/detail/force_torque__functions.h"

bool
com_interfaces__srv__AuboCmdInterface_Response__init(com_interfaces__srv__AuboCmdInterface_Response * msg)
{
  if (!msg) {
    return false;
  }
  // err_code
  // msg
  if (!rosidl_runtime_c__String__init(&msg->msg)) {
    com_interfaces__srv__AuboCmdInterface_Response__fini(msg);
    return false;
  }
  // pub_state
  if (!com_interfaces__msg__AuboRobotState__init(&msg->pub_state)) {
    com_interfaces__srv__AuboCmdInterface_Response__fini(msg);
    return false;
  }
  // register_val
  // io_val
  // jt_pos
  // tl_pos
  // ft
  if (!com_interfaces__msg__ForceTorque__init(&msg->ft)) {
    com_interfaces__srv__AuboCmdInterface_Response__fini(msg);
    return false;
  }
  return true;
}

void
com_interfaces__srv__AuboCmdInterface_Response__fini(com_interfaces__srv__AuboCmdInterface_Response * msg)
{
  if (!msg) {
    return;
  }
  // err_code
  // msg
  rosidl_runtime_c__String__fini(&msg->msg);
  // pub_state
  com_interfaces__msg__AuboRobotState__fini(&msg->pub_state);
  // register_val
  // io_val
  // jt_pos
  // tl_pos
  // ft
  com_interfaces__msg__ForceTorque__fini(&msg->ft);
}

bool
com_interfaces__srv__AuboCmdInterface_Response__are_equal(const com_interfaces__srv__AuboCmdInterface_Response * lhs, const com_interfaces__srv__AuboCmdInterface_Response * rhs)
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
  // pub_state
  if (!com_interfaces__msg__AuboRobotState__are_equal(
      &(lhs->pub_state), &(rhs->pub_state)))
  {
    return false;
  }
  // register_val
  if (lhs->register_val != rhs->register_val) {
    return false;
  }
  // io_val
  if (lhs->io_val != rhs->io_val) {
    return false;
  }
  // jt_pos
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->jt_pos[i] != rhs->jt_pos[i]) {
      return false;
    }
  }
  // tl_pos
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->tl_pos[i] != rhs->tl_pos[i]) {
      return false;
    }
  }
  // ft
  if (!com_interfaces__msg__ForceTorque__are_equal(
      &(lhs->ft), &(rhs->ft)))
  {
    return false;
  }
  return true;
}

bool
com_interfaces__srv__AuboCmdInterface_Response__copy(
  const com_interfaces__srv__AuboCmdInterface_Response * input,
  com_interfaces__srv__AuboCmdInterface_Response * output)
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
  // pub_state
  if (!com_interfaces__msg__AuboRobotState__copy(
      &(input->pub_state), &(output->pub_state)))
  {
    return false;
  }
  // register_val
  output->register_val = input->register_val;
  // io_val
  output->io_val = input->io_val;
  // jt_pos
  for (size_t i = 0; i < 6; ++i) {
    output->jt_pos[i] = input->jt_pos[i];
  }
  // tl_pos
  for (size_t i = 0; i < 6; ++i) {
    output->tl_pos[i] = input->tl_pos[i];
  }
  // ft
  if (!com_interfaces__msg__ForceTorque__copy(
      &(input->ft), &(output->ft)))
  {
    return false;
  }
  return true;
}

com_interfaces__srv__AuboCmdInterface_Response *
com_interfaces__srv__AuboCmdInterface_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__AuboCmdInterface_Response * msg = (com_interfaces__srv__AuboCmdInterface_Response *)allocator.allocate(sizeof(com_interfaces__srv__AuboCmdInterface_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__srv__AuboCmdInterface_Response));
  bool success = com_interfaces__srv__AuboCmdInterface_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__srv__AuboCmdInterface_Response__destroy(com_interfaces__srv__AuboCmdInterface_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__srv__AuboCmdInterface_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__srv__AuboCmdInterface_Response__Sequence__init(com_interfaces__srv__AuboCmdInterface_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__AuboCmdInterface_Response * data = NULL;

  if (size) {
    data = (com_interfaces__srv__AuboCmdInterface_Response *)allocator.zero_allocate(size, sizeof(com_interfaces__srv__AuboCmdInterface_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__srv__AuboCmdInterface_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__srv__AuboCmdInterface_Response__fini(&data[i - 1]);
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
com_interfaces__srv__AuboCmdInterface_Response__Sequence__fini(com_interfaces__srv__AuboCmdInterface_Response__Sequence * array)
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
      com_interfaces__srv__AuboCmdInterface_Response__fini(&array->data[i]);
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

com_interfaces__srv__AuboCmdInterface_Response__Sequence *
com_interfaces__srv__AuboCmdInterface_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__srv__AuboCmdInterface_Response__Sequence * array = (com_interfaces__srv__AuboCmdInterface_Response__Sequence *)allocator.allocate(sizeof(com_interfaces__srv__AuboCmdInterface_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__srv__AuboCmdInterface_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__srv__AuboCmdInterface_Response__Sequence__destroy(com_interfaces__srv__AuboCmdInterface_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__srv__AuboCmdInterface_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__srv__AuboCmdInterface_Response__Sequence__are_equal(const com_interfaces__srv__AuboCmdInterface_Response__Sequence * lhs, const com_interfaces__srv__AuboCmdInterface_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__srv__AuboCmdInterface_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__srv__AuboCmdInterface_Response__Sequence__copy(
  const com_interfaces__srv__AuboCmdInterface_Response__Sequence * input,
  com_interfaces__srv__AuboCmdInterface_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__srv__AuboCmdInterface_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__srv__AuboCmdInterface_Response * data =
      (com_interfaces__srv__AuboCmdInterface_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__srv__AuboCmdInterface_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__srv__AuboCmdInterface_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__srv__AuboCmdInterface_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
