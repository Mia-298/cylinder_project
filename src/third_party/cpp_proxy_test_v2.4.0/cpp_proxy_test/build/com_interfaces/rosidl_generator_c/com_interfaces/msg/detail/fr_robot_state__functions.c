// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from com_interfaces:msg/FrRobotState.idl
// generated code does not contain a copyright notice
#include "com_interfaces/msg/detail/fr_robot_state__functions.h"

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
com_interfaces__msg__FrRobotState__init(com_interfaces__msg__FrRobotState * msg)
{
  if (!msg) {
    return false;
  }
  // robot_index
  // robot_name
  if (!rosidl_runtime_c__String__init(&msg->robot_name)) {
    com_interfaces__msg__FrRobotState__fini(msg);
    return false;
  }
  // robot_type
  if (!rosidl_runtime_c__String__init(&msg->robot_type)) {
    com_interfaces__msg__FrRobotState__fini(msg);
    return false;
  }
  // robot_soft_index
  if (!rosidl_runtime_c__String__init(&msg->robot_soft_index)) {
    com_interfaces__msg__FrRobotState__fini(msg);
    return false;
  }
  // robot_ip
  if (!rosidl_runtime_c__String__init(&msg->robot_ip)) {
    com_interfaces__msg__FrRobotState__fini(msg);
    return false;
  }
  // curtask_index
  // curstep_index
  // program_state
  // robot_motion_done
  // robot_err_code
  // main_code
  // sub_code
  // robot_mode
  // robot_speed
  // jt_cur_pos
  // tl_cur_pos
  // cl_dgt_output_h
  // cl_dgt_output_l
  // cl_dgt_input_h
  // cl_dgt_input_l
  // cl_analog_input
  // cl_analog_output
  // tl_dgt_output_l
  // tl_dgt_input_l
  // emergency_stop
  return true;
}

void
com_interfaces__msg__FrRobotState__fini(com_interfaces__msg__FrRobotState * msg)
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
  // curtask_index
  // curstep_index
  // program_state
  // robot_motion_done
  // robot_err_code
  // main_code
  // sub_code
  // robot_mode
  // robot_speed
  // jt_cur_pos
  // tl_cur_pos
  // cl_dgt_output_h
  // cl_dgt_output_l
  // cl_dgt_input_h
  // cl_dgt_input_l
  // cl_analog_input
  // cl_analog_output
  // tl_dgt_output_l
  // tl_dgt_input_l
  // emergency_stop
}

bool
com_interfaces__msg__FrRobotState__are_equal(const com_interfaces__msg__FrRobotState * lhs, const com_interfaces__msg__FrRobotState * rhs)
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
  // curtask_index
  if (lhs->curtask_index != rhs->curtask_index) {
    return false;
  }
  // curstep_index
  if (lhs->curstep_index != rhs->curstep_index) {
    return false;
  }
  // program_state
  if (lhs->program_state != rhs->program_state) {
    return false;
  }
  // robot_motion_done
  if (lhs->robot_motion_done != rhs->robot_motion_done) {
    return false;
  }
  // robot_err_code
  if (lhs->robot_err_code != rhs->robot_err_code) {
    return false;
  }
  // main_code
  if (lhs->main_code != rhs->main_code) {
    return false;
  }
  // sub_code
  if (lhs->sub_code != rhs->sub_code) {
    return false;
  }
  // robot_mode
  if (lhs->robot_mode != rhs->robot_mode) {
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
  // cl_dgt_output_h
  if (lhs->cl_dgt_output_h != rhs->cl_dgt_output_h) {
    return false;
  }
  // cl_dgt_output_l
  if (lhs->cl_dgt_output_l != rhs->cl_dgt_output_l) {
    return false;
  }
  // cl_dgt_input_h
  if (lhs->cl_dgt_input_h != rhs->cl_dgt_input_h) {
    return false;
  }
  // cl_dgt_input_l
  if (lhs->cl_dgt_input_l != rhs->cl_dgt_input_l) {
    return false;
  }
  // cl_analog_input
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->cl_analog_input[i] != rhs->cl_analog_input[i]) {
      return false;
    }
  }
  // cl_analog_output
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->cl_analog_output[i] != rhs->cl_analog_output[i]) {
      return false;
    }
  }
  // tl_dgt_output_l
  if (lhs->tl_dgt_output_l != rhs->tl_dgt_output_l) {
    return false;
  }
  // tl_dgt_input_l
  if (lhs->tl_dgt_input_l != rhs->tl_dgt_input_l) {
    return false;
  }
  // emergency_stop
  if (lhs->emergency_stop != rhs->emergency_stop) {
    return false;
  }
  return true;
}

bool
com_interfaces__msg__FrRobotState__copy(
  const com_interfaces__msg__FrRobotState * input,
  com_interfaces__msg__FrRobotState * output)
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
  // curtask_index
  output->curtask_index = input->curtask_index;
  // curstep_index
  output->curstep_index = input->curstep_index;
  // program_state
  output->program_state = input->program_state;
  // robot_motion_done
  output->robot_motion_done = input->robot_motion_done;
  // robot_err_code
  output->robot_err_code = input->robot_err_code;
  // main_code
  output->main_code = input->main_code;
  // sub_code
  output->sub_code = input->sub_code;
  // robot_mode
  output->robot_mode = input->robot_mode;
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
  // cl_dgt_output_h
  output->cl_dgt_output_h = input->cl_dgt_output_h;
  // cl_dgt_output_l
  output->cl_dgt_output_l = input->cl_dgt_output_l;
  // cl_dgt_input_h
  output->cl_dgt_input_h = input->cl_dgt_input_h;
  // cl_dgt_input_l
  output->cl_dgt_input_l = input->cl_dgt_input_l;
  // cl_analog_input
  for (size_t i = 0; i < 2; ++i) {
    output->cl_analog_input[i] = input->cl_analog_input[i];
  }
  // cl_analog_output
  for (size_t i = 0; i < 2; ++i) {
    output->cl_analog_output[i] = input->cl_analog_output[i];
  }
  // tl_dgt_output_l
  output->tl_dgt_output_l = input->tl_dgt_output_l;
  // tl_dgt_input_l
  output->tl_dgt_input_l = input->tl_dgt_input_l;
  // emergency_stop
  output->emergency_stop = input->emergency_stop;
  return true;
}

com_interfaces__msg__FrRobotState *
com_interfaces__msg__FrRobotState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__FrRobotState * msg = (com_interfaces__msg__FrRobotState *)allocator.allocate(sizeof(com_interfaces__msg__FrRobotState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(com_interfaces__msg__FrRobotState));
  bool success = com_interfaces__msg__FrRobotState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
com_interfaces__msg__FrRobotState__destroy(com_interfaces__msg__FrRobotState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    com_interfaces__msg__FrRobotState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
com_interfaces__msg__FrRobotState__Sequence__init(com_interfaces__msg__FrRobotState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__FrRobotState * data = NULL;

  if (size) {
    data = (com_interfaces__msg__FrRobotState *)allocator.zero_allocate(size, sizeof(com_interfaces__msg__FrRobotState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = com_interfaces__msg__FrRobotState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        com_interfaces__msg__FrRobotState__fini(&data[i - 1]);
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
com_interfaces__msg__FrRobotState__Sequence__fini(com_interfaces__msg__FrRobotState__Sequence * array)
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
      com_interfaces__msg__FrRobotState__fini(&array->data[i]);
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

com_interfaces__msg__FrRobotState__Sequence *
com_interfaces__msg__FrRobotState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  com_interfaces__msg__FrRobotState__Sequence * array = (com_interfaces__msg__FrRobotState__Sequence *)allocator.allocate(sizeof(com_interfaces__msg__FrRobotState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = com_interfaces__msg__FrRobotState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
com_interfaces__msg__FrRobotState__Sequence__destroy(com_interfaces__msg__FrRobotState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    com_interfaces__msg__FrRobotState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
com_interfaces__msg__FrRobotState__Sequence__are_equal(const com_interfaces__msg__FrRobotState__Sequence * lhs, const com_interfaces__msg__FrRobotState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!com_interfaces__msg__FrRobotState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
com_interfaces__msg__FrRobotState__Sequence__copy(
  const com_interfaces__msg__FrRobotState__Sequence * input,
  com_interfaces__msg__FrRobotState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(com_interfaces__msg__FrRobotState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    com_interfaces__msg__FrRobotState * data =
      (com_interfaces__msg__FrRobotState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!com_interfaces__msg__FrRobotState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          com_interfaces__msg__FrRobotState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!com_interfaces__msg__FrRobotState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
