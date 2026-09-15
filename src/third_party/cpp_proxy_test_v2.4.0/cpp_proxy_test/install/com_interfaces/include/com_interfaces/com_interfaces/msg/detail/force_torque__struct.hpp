// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/ForceTorque.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__ForceTorque __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__ForceTorque __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ForceTorque_
{
  using Type = ForceTorque_<ContainerAllocator>;

  explicit ForceTorque_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fx = 0.0;
      this->fy = 0.0;
      this->fz = 0.0;
      this->tx = 0.0;
      this->ty = 0.0;
      this->tz = 0.0;
    }
  }

  explicit ForceTorque_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fx = 0.0;
      this->fy = 0.0;
      this->fz = 0.0;
      this->tx = 0.0;
      this->ty = 0.0;
      this->tz = 0.0;
    }
  }

  // field types and members
  using _fx_type =
    double;
  _fx_type fx;
  using _fy_type =
    double;
  _fy_type fy;
  using _fz_type =
    double;
  _fz_type fz;
  using _tx_type =
    double;
  _tx_type tx;
  using _ty_type =
    double;
  _ty_type ty;
  using _tz_type =
    double;
  _tz_type tz;

  // setters for named parameter idiom
  Type & set__fx(
    const double & _arg)
  {
    this->fx = _arg;
    return *this;
  }
  Type & set__fy(
    const double & _arg)
  {
    this->fy = _arg;
    return *this;
  }
  Type & set__fz(
    const double & _arg)
  {
    this->fz = _arg;
    return *this;
  }
  Type & set__tx(
    const double & _arg)
  {
    this->tx = _arg;
    return *this;
  }
  Type & set__ty(
    const double & _arg)
  {
    this->ty = _arg;
    return *this;
  }
  Type & set__tz(
    const double & _arg)
  {
    this->tz = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::ForceTorque_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::ForceTorque_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::ForceTorque_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::ForceTorque_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::ForceTorque_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::ForceTorque_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::ForceTorque_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::ForceTorque_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::ForceTorque_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::ForceTorque_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__ForceTorque
    std::shared_ptr<com_interfaces::msg::ForceTorque_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__ForceTorque
    std::shared_ptr<com_interfaces::msg::ForceTorque_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ForceTorque_ & other) const
  {
    if (this->fx != other.fx) {
      return false;
    }
    if (this->fy != other.fy) {
      return false;
    }
    if (this->fz != other.fz) {
      return false;
    }
    if (this->tx != other.tx) {
      return false;
    }
    if (this->ty != other.ty) {
      return false;
    }
    if (this->tz != other.tz) {
      return false;
    }
    return true;
  }
  bool operator!=(const ForceTorque_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ForceTorque_

// alias to use template instance with default allocator
using ForceTorque =
  com_interfaces::msg::ForceTorque_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__FORCE_TORQUE__STRUCT_HPP_
