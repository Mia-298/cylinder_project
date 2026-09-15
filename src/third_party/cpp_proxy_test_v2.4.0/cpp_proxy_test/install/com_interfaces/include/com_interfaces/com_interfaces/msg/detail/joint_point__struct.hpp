// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/JointPoint.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__JOINT_POINT__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__JOINT_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__JointPoint __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__JointPoint __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointPoint_
{
  using Type = JointPoint_<ContainerAllocator>;

  explicit JointPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->joint_point.begin(), this->joint_point.end(), 0.0);
    }
  }

  explicit JointPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint_point(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->joint_point.begin(), this->joint_point.end(), 0.0);
    }
  }

  // field types and members
  using _joint_point_type =
    std::array<double, 6>;
  _joint_point_type joint_point;

  // setters for named parameter idiom
  Type & set__joint_point(
    const std::array<double, 6> & _arg)
  {
    this->joint_point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::JointPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::JointPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::JointPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::JointPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::JointPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::JointPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::JointPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::JointPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::JointPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::JointPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__JointPoint
    std::shared_ptr<com_interfaces::msg::JointPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__JointPoint
    std::shared_ptr<com_interfaces::msg::JointPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointPoint_ & other) const
  {
    if (this->joint_point != other.joint_point) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointPoint_

// alias to use template instance with default allocator
using JointPoint =
  com_interfaces::msg::JointPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__JOINT_POINT__STRUCT_HPP_
