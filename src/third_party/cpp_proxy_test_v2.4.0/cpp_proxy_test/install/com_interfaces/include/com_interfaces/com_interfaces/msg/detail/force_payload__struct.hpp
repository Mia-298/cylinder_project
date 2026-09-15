// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/ForcePayload.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__ForcePayload __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__ForcePayload __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ForcePayload_
{
  using Type = ForcePayload_<ContainerAllocator>;

  explicit ForcePayload_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->weight = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  explicit ForcePayload_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->weight = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  // field types and members
  using _weight_type =
    double;
  _weight_type weight;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;

  // setters for named parameter idiom
  Type & set__weight(
    const double & _arg)
  {
    this->weight = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::ForcePayload_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::ForcePayload_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::ForcePayload_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::ForcePayload_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::ForcePayload_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::ForcePayload_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::ForcePayload_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::ForcePayload_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::ForcePayload_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::ForcePayload_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__ForcePayload
    std::shared_ptr<com_interfaces::msg::ForcePayload_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__ForcePayload
    std::shared_ptr<com_interfaces::msg::ForcePayload_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForcePayload_ & other) const
  {
    if (this->weight != other.weight) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForcePayload_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForcePayload_

// alias to use template instance with default allocator
using ForcePayload =
  com_interfaces::msg::ForcePayload_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__FORCE_PAYLOAD__STRUCT_HPP_
