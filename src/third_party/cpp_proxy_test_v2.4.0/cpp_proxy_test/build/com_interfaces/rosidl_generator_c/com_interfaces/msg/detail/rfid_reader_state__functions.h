// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from com_interfaces:msg/RfidReaderState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__RFID_READER_STATE__FUNCTIONS_H_
#define COM_INTERFACES__MSG__DETAIL__RFID_READER_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "com_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "com_interfaces/msg/detail/rfid_reader_state__struct.h"

/// Initialize msg/RfidReaderState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * com_interfaces__msg__RfidReaderState
 * )) before or use
 * com_interfaces__msg__RfidReaderState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__RfidReaderState__init(com_interfaces__msg__RfidReaderState * msg);

/// Finalize msg/RfidReaderState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
void
com_interfaces__msg__RfidReaderState__fini(com_interfaces__msg__RfidReaderState * msg);

/// Create msg/RfidReaderState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * com_interfaces__msg__RfidReaderState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
com_interfaces__msg__RfidReaderState *
com_interfaces__msg__RfidReaderState__create();

/// Destroy msg/RfidReaderState message.
/**
 * It calls
 * com_interfaces__msg__RfidReaderState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
void
com_interfaces__msg__RfidReaderState__destroy(com_interfaces__msg__RfidReaderState * msg);

/// Check for msg/RfidReaderState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__RfidReaderState__are_equal(const com_interfaces__msg__RfidReaderState * lhs, const com_interfaces__msg__RfidReaderState * rhs);

/// Copy a msg/RfidReaderState message.
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
com_interfaces__msg__RfidReaderState__copy(
  const com_interfaces__msg__RfidReaderState * input,
  com_interfaces__msg__RfidReaderState * output);

/// Initialize array of msg/RfidReaderState messages.
/**
 * It allocates the memory for the number of elements and calls
 * com_interfaces__msg__RfidReaderState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__RfidReaderState__Sequence__init(com_interfaces__msg__RfidReaderState__Sequence * array, size_t size);

/// Finalize array of msg/RfidReaderState messages.
/**
 * It calls
 * com_interfaces__msg__RfidReaderState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
void
com_interfaces__msg__RfidReaderState__Sequence__fini(com_interfaces__msg__RfidReaderState__Sequence * array);

/// Create array of msg/RfidReaderState messages.
/**
 * It allocates the memory for the array and calls
 * com_interfaces__msg__RfidReaderState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
com_interfaces__msg__RfidReaderState__Sequence *
com_interfaces__msg__RfidReaderState__Sequence__create(size_t size);

/// Destroy array of msg/RfidReaderState messages.
/**
 * It calls
 * com_interfaces__msg__RfidReaderState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
void
com_interfaces__msg__RfidReaderState__Sequence__destroy(com_interfaces__msg__RfidReaderState__Sequence * array);

/// Check for msg/RfidReaderState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_com_interfaces
bool
com_interfaces__msg__RfidReaderState__Sequence__are_equal(const com_interfaces__msg__RfidReaderState__Sequence * lhs, const com_interfaces__msg__RfidReaderState__Sequence * rhs);

/// Copy an array of msg/RfidReaderState messages.
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
com_interfaces__msg__RfidReaderState__Sequence__copy(
  const com_interfaces__msg__RfidReaderState__Sequence * input,
  com_interfaces__msg__RfidReaderState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // COM_INTERFACES__MSG__DETAIL__RFID_READER_STATE__FUNCTIONS_H_
