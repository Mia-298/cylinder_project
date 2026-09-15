// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/AgvControl.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__AgvControl __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__AgvControl __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AgvControl_
{
  using Type = AgvControl_<ContainerAllocator>;

  explicit AgvControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->locked = false;
      this->ip = "";
      this->port = 0l;
      this->type = 0;
      this->nick_name = "";
      this->time = 0ll;
      this->desc = "";
    }
  }

  explicit AgvControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : ip(_alloc),
    nick_name(_alloc),
    desc(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->locked = false;
      this->ip = "";
      this->port = 0l;
      this->type = 0;
      this->nick_name = "";
      this->time = 0ll;
      this->desc = "";
    }
  }

  // field types and members
  using _locked_type =
    bool;
  _locked_type locked;
  using _ip_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ip_type ip;
  using _port_type =
    int32_t;
  _port_type port;
  using _type_type =
    uint8_t;
  _type_type type;
  using _nick_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _nick_name_type nick_name;
  using _time_type =
    int64_t;
  _time_type time;
  using _desc_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _desc_type desc;

  // setters for named parameter idiom
  Type & set__locked(
    const bool & _arg)
  {
    this->locked = _arg;
    return *this;
  }
  Type & set__ip(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ip = _arg;
    return *this;
  }
  Type & set__port(
    const int32_t & _arg)
  {
    this->port = _arg;
    return *this;
  }
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__nick_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->nick_name = _arg;
    return *this;
  }
  Type & set__time(
    const int64_t & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__desc(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->desc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::AgvControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::AgvControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::AgvControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::AgvControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AgvControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AgvControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AgvControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AgvControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::AgvControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::AgvControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__AgvControl
    std::shared_ptr<com_interfaces::msg::AgvControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__AgvControl
    std::shared_ptr<com_interfaces::msg::AgvControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AgvControl_ & other) const
  {
    if (this->locked != other.locked) {
      return false;
    }
    if (this->ip != other.ip) {
      return false;
    }
    if (this->port != other.port) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->nick_name != other.nick_name) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    if (this->desc != other.desc) {
      return false;
    }
    return true;
  }
  bool operator!=(const AgvControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AgvControl_

// alias to use template instance with default allocator
using AgvControl =
  com_interfaces::msg::AgvControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_CONTROL__STRUCT_HPP_
