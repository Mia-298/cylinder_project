// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:msg/SiemensPlcState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "com_interfaces/msg/detail/siemens_plc_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace com_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SiemensPlcState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) com_interfaces::msg::SiemensPlcState(_init);
}

void SiemensPlcState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<com_interfaces::msg::SiemensPlcState *>(message_memory);
  typed_message->~SiemensPlcState();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SiemensPlcState_message_member_array[3] = {
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::msg::SiemensPlcState, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "err_code",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::msg::SiemensPlcState, err_code),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "err_msg",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::msg::SiemensPlcState, err_msg),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SiemensPlcState_message_members = {
  "com_interfaces::msg",  // message namespace
  "SiemensPlcState",  // message name
  3,  // number of fields
  sizeof(com_interfaces::msg::SiemensPlcState),
  SiemensPlcState_message_member_array,  // message members
  SiemensPlcState_init_function,  // function to initialize message memory (memory has to be allocated)
  SiemensPlcState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SiemensPlcState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SiemensPlcState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace com_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<com_interfaces::msg::SiemensPlcState>()
{
  return &::com_interfaces::msg::rosidl_typesupport_introspection_cpp::SiemensPlcState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, com_interfaces, msg, SiemensPlcState)() {
  return &::com_interfaces::msg::rosidl_typesupport_introspection_cpp::SiemensPlcState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
