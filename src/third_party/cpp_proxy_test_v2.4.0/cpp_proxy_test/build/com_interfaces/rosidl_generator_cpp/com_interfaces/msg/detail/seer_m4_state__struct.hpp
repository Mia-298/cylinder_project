// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/SeerM4State.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__SEER_M4_STATE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__SEER_M4_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'order_state'
#include "com_interfaces/msg/detail/agv_order_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__SeerM4State __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__SeerM4State __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SeerM4State_
{
  using Type = SeerM4State_<ContainerAllocator>;

  explicit SeerM4State_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : order_state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->err_code = 0l;
      this->err_msg = "";
    }
  }

  explicit SeerM4State_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    err_msg(_alloc),
    order_state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->err_code = 0l;
      this->err_msg = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _err_code_type =
    int32_t;
  _err_code_type err_code;
  using _err_msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _err_msg_type err_msg;
  using _order_state_type =
    com_interfaces::msg::AgvOrderState_<ContainerAllocator>;
  _order_state_type order_state;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__err_code(
    const int32_t & _arg)
  {
    this->err_code = _arg;
    return *this;
  }
  Type & set__err_msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->err_msg = _arg;
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
    com_interfaces::msg::SeerM4State_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::SeerM4State_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::SeerM4State_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::SeerM4State_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::SeerM4State_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::SeerM4State_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::SeerM4State_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::SeerM4State_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::SeerM4State_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::SeerM4State_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__SeerM4State
    std::shared_ptr<com_interfaces::msg::SeerM4State_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__SeerM4State
    std::shared_ptr<com_interfaces::msg::SeerM4State_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SeerM4State_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->err_code != other.err_code) {
      return false;
    }
    if (this->err_msg != other.err_msg) {
      return false;
    }
    if (this->order_state != other.order_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const SeerM4State_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SeerM4State_

// alias to use template instance with default allocator
using SeerM4State =
  com_interfaces::msg::SeerM4State_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__SEER_M4_STATE__STRUCT_HPP_
