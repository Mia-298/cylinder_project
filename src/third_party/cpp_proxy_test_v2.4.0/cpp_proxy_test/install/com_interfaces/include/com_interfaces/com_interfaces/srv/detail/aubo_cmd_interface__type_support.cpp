// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:srv/AuboCmdInterface.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "com_interfaces/srv/detail/aubo_cmd_interface__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace com_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void AuboCmdInterface_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) com_interfaces::srv::AuboCmdInterface_Request(_init);
}

void AuboCmdInterface_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<com_interfaces::srv::AuboCmdInterface_Request *>(message_memory);
  typed_message->~AuboCmdInterface_Request();
}

size_t size_function__AuboCmdInterface_Request__position(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__AuboCmdInterface_Request__position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__AuboCmdInterface_Request__position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__AuboCmdInterface_Request__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__AuboCmdInterface_Request__position(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__AuboCmdInterface_Request__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__AuboCmdInterface_Request__position(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__AuboCmdInterface_Request__joint_path(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<com_interfaces::msg::JointPoint> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AuboCmdInterface_Request__joint_path(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<com_interfaces::msg::JointPoint> *>(untyped_member);
  return &member[index];
}

void * get_function__AuboCmdInterface_Request__joint_path(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<com_interfaces::msg::JointPoint> *>(untyped_member);
  return &member[index];
}

void fetch_function__AuboCmdInterface_Request__joint_path(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const com_interfaces::msg::JointPoint *>(
    get_const_function__AuboCmdInterface_Request__joint_path(untyped_member, index));
  auto & value = *reinterpret_cast<com_interfaces::msg::JointPoint *>(untyped_value);
  value = item;
}

void assign_function__AuboCmdInterface_Request__joint_path(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<com_interfaces::msg::JointPoint *>(
    get_function__AuboCmdInterface_Request__joint_path(untyped_member, index));
  const auto & value = *reinterpret_cast<const com_interfaces::msg::JointPoint *>(untyped_value);
  item = value;
}

void resize_function__AuboCmdInterface_Request__joint_path(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<com_interfaces::msg::JointPoint> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AuboCmdInterface_Request_message_member_array[27] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "en",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, en),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_or_desc",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, joint_or_desc),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, position),  // bytes offset in struct
    nullptr,  // default value
    size_function__AuboCmdInterface_Request__position,  // size() function pointer
    get_const_function__AuboCmdInterface_Request__position,  // get_const(index) function pointer
    get_function__AuboCmdInterface_Request__position,  // get(index) function pointer
    fetch_function__AuboCmdInterface_Request__position,  // fetch(index, &value) function pointer
    assign_function__AuboCmdInterface_Request__position,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "axid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, axid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "dir",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, dir),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "deg",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, deg),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "acc",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, acc),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tool",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, tool),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "register_index",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, register_index),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "register_value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, register_value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "input_or_output",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, input_or_output),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "io_index",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, io_index),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "io_value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, io_value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "program",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, program),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "interval",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, interval),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "filename",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, filename),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<com_interfaces::msg::JointPoint>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, joint_path),  // bytes offset in struct
    nullptr,  // default value
    size_function__AuboCmdInterface_Request__joint_path,  // size() function pointer
    get_const_function__AuboCmdInterface_Request__joint_path,  // get_const(index) function pointer
    get_function__AuboCmdInterface_Request__joint_path,  // get(index) function pointer
    fetch_function__AuboCmdInterface_Request__joint_path,  // fetch(index, &value) function pointer
    assign_function__AuboCmdInterface_Request__joint_path,  // assign(index, value) function pointer
    resize_function__AuboCmdInterface_Request__joint_path  // resize(index) function pointer
  },
  {
    "gripper_index",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, gripper_index),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "act",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, act),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gripper_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, gripper_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gripper_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, gripper_vel),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gripper_force",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, gripper_force),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "max_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, max_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gripper_block",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Request, gripper_block),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AuboCmdInterface_Request_message_members = {
  "com_interfaces::srv",  // message namespace
  "AuboCmdInterface_Request",  // message name
  27,  // number of fields
  sizeof(com_interfaces::srv::AuboCmdInterface_Request),
  AuboCmdInterface_Request_message_member_array,  // message members
  AuboCmdInterface_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  AuboCmdInterface_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AuboCmdInterface_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AuboCmdInterface_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace com_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<com_interfaces::srv::AuboCmdInterface_Request>()
{
  return &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::AuboCmdInterface_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, com_interfaces, srv, AuboCmdInterface_Request)() {
  return &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::AuboCmdInterface_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "com_interfaces/srv/detail/aubo_cmd_interface__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace com_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void AuboCmdInterface_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) com_interfaces::srv::AuboCmdInterface_Response(_init);
}

void AuboCmdInterface_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<com_interfaces::srv::AuboCmdInterface_Response *>(message_memory);
  typed_message->~AuboCmdInterface_Response();
}

size_t size_function__AuboCmdInterface_Response__jt_pos(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__AuboCmdInterface_Response__jt_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__AuboCmdInterface_Response__jt_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__AuboCmdInterface_Response__jt_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__AuboCmdInterface_Response__jt_pos(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__AuboCmdInterface_Response__jt_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__AuboCmdInterface_Response__jt_pos(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__AuboCmdInterface_Response__tl_pos(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__AuboCmdInterface_Response__tl_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__AuboCmdInterface_Response__tl_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__AuboCmdInterface_Response__tl_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__AuboCmdInterface_Response__tl_pos(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__AuboCmdInterface_Response__tl_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__AuboCmdInterface_Response__tl_pos(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AuboCmdInterface_Response_message_member_array[8] = {
  {
    "err_code",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Response, err_code),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "msg",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Response, msg),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pub_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<com_interfaces::msg::AuboRobotState>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Response, pub_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "register_val",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Response, register_val),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "io_val",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Response, io_val),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "jt_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Response, jt_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__AuboCmdInterface_Response__jt_pos,  // size() function pointer
    get_const_function__AuboCmdInterface_Response__jt_pos,  // get_const(index) function pointer
    get_function__AuboCmdInterface_Response__jt_pos,  // get(index) function pointer
    fetch_function__AuboCmdInterface_Response__jt_pos,  // fetch(index, &value) function pointer
    assign_function__AuboCmdInterface_Response__jt_pos,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tl_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Response, tl_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__AuboCmdInterface_Response__tl_pos,  // size() function pointer
    get_const_function__AuboCmdInterface_Response__tl_pos,  // get_const(index) function pointer
    get_function__AuboCmdInterface_Response__tl_pos,  // get(index) function pointer
    fetch_function__AuboCmdInterface_Response__tl_pos,  // fetch(index, &value) function pointer
    assign_function__AuboCmdInterface_Response__tl_pos,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ft",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<com_interfaces::msg::ForceTorque>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::AuboCmdInterface_Response, ft),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AuboCmdInterface_Response_message_members = {
  "com_interfaces::srv",  // message namespace
  "AuboCmdInterface_Response",  // message name
  8,  // number of fields
  sizeof(com_interfaces::srv::AuboCmdInterface_Response),
  AuboCmdInterface_Response_message_member_array,  // message members
  AuboCmdInterface_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  AuboCmdInterface_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AuboCmdInterface_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AuboCmdInterface_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace com_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<com_interfaces::srv::AuboCmdInterface_Response>()
{
  return &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::AuboCmdInterface_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, com_interfaces, srv, AuboCmdInterface_Response)() {
  return &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::AuboCmdInterface_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "com_interfaces/srv/detail/aubo_cmd_interface__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace com_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers AuboCmdInterface_service_members = {
  "com_interfaces::srv",  // service namespace
  "AuboCmdInterface",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<com_interfaces::srv::AuboCmdInterface>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t AuboCmdInterface_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AuboCmdInterface_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace com_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<com_interfaces::srv::AuboCmdInterface>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::AuboCmdInterface_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::com_interfaces::srv::AuboCmdInterface_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::com_interfaces::srv::AuboCmdInterface_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, com_interfaces, srv, AuboCmdInterface)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<com_interfaces::srv::AuboCmdInterface>();
}

#ifdef __cplusplus
}
#endif
