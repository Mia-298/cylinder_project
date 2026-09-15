// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from com_interfaces:msg/SiemensPlcState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__SIEMENS_PLC_STATE__FUNCTIONS_H_
#define COM_INTERFACES__MSG__DETAIL__SIEMENS_PLC_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "com_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "com_interfaces/msg/detail/siemens_plc_state__struct.h"

/// Initialize msg/SiemensPlcState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * com_interfaces__msg__SiemensPlcState
 * )) before or use
 * com_interfaces__msg__SiemensPlcState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__SiemensPlcState__init(com_interfaces__msg__SiemensPlcState * msg);

/// Finalize msg/SiemensPlcState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
void
com_interfaces__msg__SiemensPlcState__fini(com_interfaces__msg__SiemensPlcState * msg);

/// Create msg/SiemensPlcState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * com_interfaces__msg__SiemensPlcState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
com_interfaces__msg__SiemensPlcState *
com_interfaces__msg__SiemensPlcState__create();

/// Destroy msg/SiemensPlcState message.
/**
 * It calls
 * com_interfaces__msg__SiemensPlcState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
void
com_interfaces__msg__SiemensPlcState__destroy(com_interfaces__msg__SiemensPlcState * msg);

/// Check for msg/SiemensPlcState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__SiemensPlcState__are_equal(const com_interfaces__msg__SiemensPlcState * lhs, const com_interfaces__msg__SiemensPlcState * rhs);

/// Copy a msg/SiemensPlcState message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__SiemensPlcState__copy(
  const com_interfaces__msg__SiemensPlcState * input,
  com_interfaces__msg__SiemensPlcState * output);

/// Initialize array of msg/SiemensPlcState messages.
/**
 * It allocates the memory for the number of elements and calls
 * com_interfaces__msg__SiemensPlcState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__SiemensPlcState__Sequence__init(com_interfaces__msg__SiemensPlcState__Sequence * array, size_t size);

/// Finalize array of msg/SiemensPlcState messages.
/**
 * It calls
 * com_interfaces__msg__SiemensPlcState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
void
com_interfaces__msg__SiemensPlcState__Sequence__fini(com_interfaces__msg__SiemensPlcState__Sequence * array);

/// Create array of msg/SiemensPlcState messages.
/**
 * It allocates the memory for the array and calls
 * com_interfaces__msg__SiemensPlcState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
com_interfaces__msg__SiemensPlcState__Sequence *
com_interfaces__msg__SiemensPlcState__Sequence__create(size_t size);

/// Destroy array of msg/SiemensPlcState messages.
/**
 * It calls
 * com_interfaces__msg__SiemensPlcState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
void
com_interfaces__msg__SiemensPlcState__Sequence__destroy(com_interfaces__msg__SiemensPlcState__Sequence * array);

/// Check for msg/SiemensPlcState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__SiemensPlcState__Sequence__are_equal(const com_interfaces__msg__SiemensPlcState__Sequence * lhs, const com_interfaces__msg__SiemensPlcState__Sequence * rhs);

/// Copy an array of msg/SiemensPlcState messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__SiemensPlcState__Sequence__copy(
  const com_interfaces__msg__SiemensPlcState__Sequence * input,
  com_interfaces__msg__SiemensPlcState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__SIEMENS_PLC_STATE__FUNCTIONS_H_
