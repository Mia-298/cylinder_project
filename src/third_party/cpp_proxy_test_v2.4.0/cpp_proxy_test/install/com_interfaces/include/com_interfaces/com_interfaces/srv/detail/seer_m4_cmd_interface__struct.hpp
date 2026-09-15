// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:srv/SeerM4CmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SEER_M4_CMD_INTERFACE__STRUCT_HPP_
#define COM_INTERFACES__SRV__DETAIL__SEER_M4_CMD_INTERFACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__SeerM4CmdInterface_Request __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__SeerM4CmdInterface_Request __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SeerM4CmdInterface_Request_
{
  using Type = SeerM4CmdInterface_Request_<ContainerAllocator>;

  explicit SeerM4CmdInterface_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->point = "";
      this->container_id = "";
      this->order_id = "";
    }
  }

  explicit SeerM4CmdInterface_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_alloc),
    container_id(_alloc),
    order_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->point = "";
      this->container_id = "";
      this->order_id = "";
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _point_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _point_type point;
  using _container_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _container_id_type container_id;
  using _order_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _order_id_type order_id;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__point(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->point = _arg;
    return *this;
  }
  Type & set__container_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->container_id = _arg;
    return *this;
  }
  Type & set__order_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->order_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__SeerM4CmdInterface_Request
    std::shared_ptr<com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__SeerM4CmdInterface_Request
    std::shared_ptr<com_interfaces::srv::SeerM4CmdInterface_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SeerM4CmdInterface_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    if (this->container_id != other.container_id) {
      return false;
    }
    if (this->order_id != other.order_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const SeerM4CmdInterface_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SeerM4CmdInterface_Request_

// alias to use template instance with default allocator
using SeerM4CmdInterface_Request =
  com_interfaces::srv::SeerM4CmdInterface_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces


// Include directives for member types
// Member 'order_state'
#include "com_interfaces/msg/detail/agv_order_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__SeerM4CmdInterface_Response __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__SeerM4CmdInterface_Response __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SeerM4CmdInterface_Response_
{
  using Type = SeerM4CmdInterface_Response_<ContainerAllocator>;

  explicit SeerM4CmdInterface_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : order_state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->msg = "";
      this->order_id = "";
    }
  }

  explicit SeerM4CmdInterface_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc),
    order_id(_alloc),
    order_state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->msg = "";
      this->order_id = "";
    }
  }

  // field types and members
  using _err_code_type =
    int32_t;
  _err_code_type err_code;
  using _msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_type msg;
  using _order_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _order_id_type order_id;
  using _order_state_type =
    com_interfaces::msg::AgvOrderState_<ContainerAllocator>;
  _order_state_type order_state;

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
  Type & set__order_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->order_id = _arg;
    return *this;
  }
  Type & set__order_state(
    const com_interfaces::msg::AgvOrderState_<ContainerAllocator> & _arg)
  {
    this->order_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__SeerM4CmdInterface_Response
    std::shared_ptr<com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__SeerM4CmdInterface_Response
    std::shared_ptr<com_interfaces::srv::SeerM4CmdInterface_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SeerM4CmdInterface_Response_ & other) const
  {
    if (this->err_code != other.err_code) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    if (this->order_id != other.order_id) {
      return false;
    }
    if (this->order_state != other.order_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const SeerM4CmdInterface_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SeerM4CmdInterface_Response_

// alias to use template instance with default allocator
using SeerM4CmdInterface_Response =
  com_interfaces::srv::SeerM4CmdInterface_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces

namespace com_interfaces
{

namespace srv
{

struct SeerM4CmdInterface
{
  using Request = com_interfaces::srv::SeerM4CmdInterface_Request;
  using Response = com_interfaces::srv::SeerM4CmdInterface_Response;
};

}  // namespace srv

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__SEER_M4_CMD_INTERFACE__STRUCT_HPP_
