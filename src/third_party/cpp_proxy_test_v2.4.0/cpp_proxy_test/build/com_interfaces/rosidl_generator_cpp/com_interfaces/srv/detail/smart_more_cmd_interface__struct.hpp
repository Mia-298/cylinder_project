// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:srv/SmartMoreCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SMART_MORE_CMD_INTERFACE__STRUCT_HPP_
#define COM_INTERFACES__SRV__DETAIL__SMART_MORE_CMD_INTERFACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__SmartMoreCmdInterface_Request __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__SmartMoreCmdInterface_Request __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SmartMoreCmdInterface_Request_
{
  using Type = SmartMoreCmdInterface_Request_<ContainerAllocator>;

  explicit SmartMoreCmdInterface_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->req = "";
    }
  }

  explicit SmartMoreCmdInterface_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : req(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->req = "";
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _req_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _req_type req;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__req(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->req = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__SmartMoreCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__SmartMoreCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::SmartMoreCmdInterface_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartMoreCmdInterface_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->req != other.req) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartMoreCmdInterface_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartMoreCmdInterface_Request_

// alias to use template instance with default allocator
using SmartMoreCmdInterface_Request =
  com_interfaces::srv::SmartMoreCmdInterface_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces


#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__SmartMoreCmdInterface_Response __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__SmartMoreCmdInterface_Response __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SmartMoreCmdInterface_Response_
{
  using Type = SmartMoreCmdInterface_Response_<ContainerAllocator>;

  explicit SmartMoreCmdInterface_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->msg = "";
      this->res = "";
    }
  }

  explicit SmartMoreCmdInterface_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc),
    res(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->msg = "";
      this->res = "";
    }
  }

  // field types and members
  using _err_code_type =
    int32_t;
  _err_code_type err_code;
  using _msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_type msg;
  using _res_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _res_type res;

  // setters for named parameter idiom
  Type & set__err_code(
    const int32_t & _arg)
  {
    this->err_code = _arg;
    return *this;
  }
  Type & set__msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->msg = _arg;
    return *this;
  }
  Type & set__res(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->res = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__SmartMoreCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__SmartMoreCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::SmartMoreCmdInterface_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartMoreCmdInterface_Response_ & other) const
  {
    if (this->err_code != other.err_code) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    if (this->res != other.res) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartMoreCmdInterface_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartMoreCmdInterface_Response_

// alias to use template instance with default allocator
using SmartMoreCmdInterface_Response =
  com_interfaces::srv::SmartMoreCmdInterface_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces

namespace com_interfaces
{

namespace srv
{

struct SmartMoreCmdInterface
{
  using Request = com_interfaces::srv::SmartMoreCmdInterface_Request;
  using Response = com_interfaces::srv::SmartMoreCmdInterface_Response;
};

}  // namespace srv

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__SMART_MORE_CMD_INTERFACE__STRUCT_HPP_
