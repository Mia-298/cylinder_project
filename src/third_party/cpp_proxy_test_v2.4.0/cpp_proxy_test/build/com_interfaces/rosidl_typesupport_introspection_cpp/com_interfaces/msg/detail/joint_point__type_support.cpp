// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:msg/JointPoint.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "com_interfaces/msg/detail/joint_point__struct.hpp"
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

void JointPoint_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) com_interfaces::msg::JointPoint(_init);
}

void JointPoint_fini_function(void * message_memory)
{
  auto typed_message = static_cast<com_interfaces::msg::JointPoint *>(message_memory);
  typed_message->~JointPoint();
}

size_t size_function__JointPoint__joint_point(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__JointPoint__joint_point(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__JointPoint__joint_point(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__JointPoint__joint_point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__JointPoint__joint_point(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__JointPoint__joint_point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__JointPoint__joint_point(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember JointPoint_message_member_array[1] = {
  {
    "joint_point",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::msg::JointPoint, joint_point),  // bytes offset in struct
    nullptr,  // default value
    size_function__JointPoint__joint_point,  // size() function pointer
    get_const_function__JointPoint__joint_point,  // get_const(index) function pointer
    get_function__JointPoint__joint_point,  // get(index) function pointer
    fetch_function__JointPoint__joint_point,  // fetch(index, &value) function pointer
    assign_function__JointPoint__joint_point,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers JointPoint_message_members = {
  "com_interfaces::msg",  // message namespace
  "JointPoint",  // message name
  1,  // number of fields
  sizeof(com_interfaces::msg::JointPoint),
  JointPoint_message_member_array,  // message members
  JointPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  JointPoint_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t JointPoint_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &JointPoint_message_members,
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
get_message_type_support_handle<com_interfaces::msg::JointPoint>()
{
  return &::com_interfaces::msg::rosidl_typesupport_introspection_cpp::JointPoint_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, com_interfaces, msg, JointPoint)() {
  return &::com_interfaces::msg::rosidl_typesupport_introspection_cpp::JointPoint_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
