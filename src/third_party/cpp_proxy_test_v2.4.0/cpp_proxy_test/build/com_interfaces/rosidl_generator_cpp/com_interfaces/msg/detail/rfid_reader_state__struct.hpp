// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/RfidReaderState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__RFID_READER_STATE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__RFID_READER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__RfidReaderState __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__RfidReaderState __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RfidReaderState_
{
  using Type = RfidReaderState_<ContainerAllocator>;

  explicit RfidReaderState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->err_code = 0l;
      this->err_msg = "";
    }
  }

  explicit RfidReaderState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    err_msg(_alloc)
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

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::RfidReaderState_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::RfidReaderState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::RfidReaderState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::RfidReaderState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::RfidReaderState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::RfidReaderState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::RfidReaderState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::RfidReaderState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::RfidReaderState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::RfidReaderState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__RfidReaderState
    std::shared_ptr<com_interfaces::msg::RfidReaderState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__RfidReaderState
    std::shared_ptr<com_interfaces::msg::RfidReaderState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RfidReaderState_ & other) const
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
    return true;
  }
  bool operator!=(const RfidReaderState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RfidReaderState_

// alias to use template instance with default allocator
using RfidReaderState =
  com_interfaces::msg::RfidReaderState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__RFID_READER_STATE__STRUCT_HPP_
