// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from com_interfaces:srv/VirtAgvCmdInterface.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.hpp"
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

void VirtAgvCmdInterface_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) com_interfaces::srv::VirtAgvCmdInterface_Request(_init);
}

void VirtAgvCmdInterface_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<com_interfaces::srv::VirtAgvCmdInterface_Request *>(message_memory);
  typed_message->~VirtAgvCmdInterface_Request();
}

size_t size_function__VirtAgvCmdInterface_Request__station_list(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__VirtAgvCmdInterface_Request__station_list(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__VirtAgvCmdInterface_Request__station_list(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__VirtAgvCmdInterface_Request__station_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__VirtAgvCmdInterface_Request__station_list(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__VirtAgvCmdInterface_Request__station_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__VirtAgvCmdInterface_Request__station_list(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__VirtAgvCmdInterface_Request__station_list(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VirtAgvCmdInterface_Request_message_member_array[7] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Request, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "station",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Request, station),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "station_list",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Request, station_list),  // bytes offset in struct
    nullptr,  // default value
    size_function__VirtAgvCmdInterface_Request__station_list,  // size() function pointer
    get_const_function__VirtAgvCmdInterface_Request__station_list,  // get_const(index) function pointer
    get_function__VirtAgvCmdInterface_Request__station_list,  // get(index) function pointer
    fetch_function__VirtAgvCmdInterface_Request__station_list,  // fetch(index, &value) function pointer
    assign_function__VirtAgvCmdInterface_Request__station_list,  // assign(index, value) function pointer
    resize_function__VirtAgvCmdInterface_Request__station_list  // resize(index) function pointer
  },
  {
    "manual_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Request, manual_x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "manual_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Request, manual_y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "manual_w",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Request, manual_w),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "manual_duration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Request, manual_duration),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VirtAgvCmdInterface_Request_message_members = {
  "com_interfaces::srv",  // message namespace
  "VirtAgvCmdInterface_Request",  // message name
  7,  // number of fields
  sizeof(com_interfaces::srv::VirtAgvCmdInterface_Request),
  VirtAgvCmdInterface_Request_message_member_array,  // message members
  VirtAgvCmdInterface_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  VirtAgvCmdInterface_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VirtAgvCmdInterface_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VirtAgvCmdInterface_Request_message_members,
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
get_message_type_support_handle<com_interfaces::srv::VirtAgvCmdInterface_Request>()
{
  return &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::VirtAgvCmdInterface_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, com_interfaces, srv, VirtAgvCmdInterface_Request)() {
  return &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::VirtAgvCmdInterface_Request_message_type_support_handle;
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
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.hpp"
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

void VirtAgvCmdInterface_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) com_interfaces::srv::VirtAgvCmdInterface_Response(_init);
}

void VirtAgvCmdInterface_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<com_interfaces::srv::VirtAgvCmdInterface_Response *>(message_memory);
  typed_message->~VirtAgvCmdInterface_Response();
}

size_t size_function__VirtAgvCmdInterface_Response__station_list(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<com_interfaces::msg::AgvStation> *>(untyped_member);
  return member->size();
}

const void * get_const_function__VirtAgvCmdInterface_Response__station_list(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<com_interfaces::msg::AgvStation> *>(untyped_member);
  return &member[index];
}

void * get_function__VirtAgvCmdInterface_Response__station_list(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<com_interfaces::msg::AgvStation> *>(untyped_member);
  return &member[index];
}

void fetch_function__VirtAgvCmdInterface_Response__station_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const com_interfaces::msg::AgvStation *>(
    get_const_function__VirtAgvCmdInterface_Response__station_list(untyped_member, index));
  auto & value = *reinterpret_cast<com_interfaces::msg::AgvStation *>(untyped_value);
  value = item;
}

void assign_function__VirtAgvCmdInterface_Response__station_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<com_interfaces::msg::AgvStation *>(
    get_function__VirtAgvCmdInterface_Response__station_list(untyped_member, index));
  const auto & value = *reinterpret_cast<const com_interfaces::msg::AgvStation *>(untyped_value);
  item = value;
}

void resize_function__VirtAgvCmdInterface_Response__station_list(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<com_interfaces::msg::AgvStation> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VirtAgvCmdInterface_Response_message_member_array[7] = {
  {
    "err_code",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Response, err_code),  // bytes offset in struct
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
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Response, msg),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "task_status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Response, task_status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "task_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Response, task_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "target_station",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Response, target_station),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "current_station",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<com_interfaces::msg::AgvStation>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Response, current_station),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "station_list",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<com_interfaces::msg::AgvStation>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(com_interfaces::srv::VirtAgvCmdInterface_Response, station_list),  // bytes offset in struct
    nullptr,  // default value
    size_function__VirtAgvCmdInterface_Response__station_list,  // size() function pointer
    get_const_function__VirtAgvCmdInterface_Response__station_list,  // get_const(index) function pointer
    get_function__VirtAgvCmdInterface_Response__station_list,  // get(index) function pointer
    fetch_function__VirtAgvCmdInterface_Response__station_list,  // fetch(index, &value) function pointer
    assign_function__VirtAgvCmdInterface_Response__station_list,  // assign(index, value) function pointer
    resize_function__VirtAgvCmdInterface_Response__station_list  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VirtAgvCmdInterface_Response_message_members = {
  "com_interfaces::srv",  // message namespace
  "VirtAgvCmdInterface_Response",  // message name
  7,  // number of fields
  sizeof(com_interfaces::srv::VirtAgvCmdInterface_Response),
  VirtAgvCmdInterface_Response_message_member_array,  // message members
  VirtAgvCmdInterface_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  VirtAgvCmdInterface_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VirtAgvCmdInterface_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VirtAgvCmdInterface_Response_message_members,
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
get_message_type_support_handle<com_interfaces::srv::VirtAgvCmdInterface_Response>()
{
  return &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::VirtAgvCmdInterface_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, com_interfaces, srv, VirtAgvCmdInterface_Response)() {
  return &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::VirtAgvCmdInterface_Response_message_type_support_handle;
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
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.hpp"
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
static ::rosidl_typesupport_introspection_cpp::ServiceMembers VirtAgvCmdInterface_service_members = {
  "com_interfaces::srv",  // service namespace
  "VirtAgvCmdInterface",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<com_interfaces::srv::VirtAgvCmdInterface>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t VirtAgvCmdInterface_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VirtAgvCmdInterface_service_members,
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
get_service_type_support_handle<com_interfaces::srv::VirtAgvCmdInterface>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::com_interfaces::srv::rosidl_typesupport_introspection_cpp::VirtAgvCmdInterface_service_type_support_handle;
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
        ::com_interfaces::srv::VirtAgvCmdInterface_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::com_interfaces::srv::VirtAgvCmdInterface_Response
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, com_interfaces, srv, VirtAgvCmdInterface)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<com_interfaces::srv::VirtAgvCmdInterface>();
}

#ifdef __cplusplus
}
#endif
