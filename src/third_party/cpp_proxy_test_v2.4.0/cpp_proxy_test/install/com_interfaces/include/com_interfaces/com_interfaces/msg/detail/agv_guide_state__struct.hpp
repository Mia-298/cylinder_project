// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/AgvGuideState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__AgvGuideState __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__AgvGuideState __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AgvGuideState_
{
  using Type = AgvGuideState_<ContainerAllocator>;

  explicit AgvGuideState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_status = 0l;
      this->task_type = 0l;
      this->target_station = "";
    }
  }

  explicit AgvGuideState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_station(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_status = 0l;
      this->task_type = 0l;
      this->target_station = "";
    }
  }

  // field types and members
  using _task_status_type =
    int32_t;
  _task_status_type task_status;
  using _task_type_type =
    int32_t;
  _task_type_type task_type;
  using _target_station_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_station_type target_station;

  // setters for named parameter idiom
  Type & set__task_status(
    const int32_t & _arg)
  {
    this->task_status = _arg;
    return *this;
  }
  Type & set__task_type(
    const int32_t & _arg)
  {
    this->task_type = _arg;
    return *this;
  }
  Type & set__target_station(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target_station = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::AgvGuideState_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::AgvGuideState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::AgvGuideState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::AgvGuideState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AgvGuideState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AgvGuideState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AgvGuideState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AgvGuideState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::AgvGuideState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::AgvGuideState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__AgvGuideState
    std::shared_ptr<com_interfaces::msg::AgvGuideState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__AgvGuideState
    std::shared_ptr<com_interfaces::msg::AgvGuideState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AgvGuideState_ & other) const
  {
    if (this->task_status != other.task_status) {
      return false;
    }
    if (this->task_type != other.task_type) {
      return false;
    }
    if (this->target_station != other.target_station) {
      return false;
    }
    return true;
  }
  bool operator!=(const AgvGuideState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AgvGuideState_

// alias to use template instance with default allocator
using AgvGuideState =
  com_interfaces::msg::AgvGuideState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_GUIDE_STATE__STRUCT_HPP_
