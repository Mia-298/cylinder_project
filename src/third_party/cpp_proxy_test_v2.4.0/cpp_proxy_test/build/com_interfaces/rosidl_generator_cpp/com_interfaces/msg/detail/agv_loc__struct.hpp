// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/AgvLoc.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_LOC__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_LOC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__AgvLoc __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__AgvLoc __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AgvLoc_
{
  using Type = AgvLoc_<ContainerAllocator>;

  explicit AgvLoc_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->angle = 0.0;
      this->confidence = 0.0;
      this->current_station = "";
      this->last_station = "";
      this->loc_method = 0l;
    }
  }

  explicit AgvLoc_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_station(_alloc),
    last_station(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->angle = 0.0;
      this->confidence = 0.0;
      this->current_station = "";
      this->last_station = "";
      this->loc_method = 0l;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _angle_type =
    double;
  _angle_type angle;
  using _confidence_type =
    double;
  _confidence_type confidence;
  using _current_station_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _current_station_type current_station;
  using _last_station_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _last_station_type last_station;
  using _loc_method_type =
    int32_t;
  _loc_method_type loc_method;

  // setters for named parameter idiom
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
  Type & set__angle(
    const double & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__confidence(
    const double & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__current_station(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->current_station = _arg;
    return *this;
  }
  Type & set__last_station(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->last_station = _arg;
    return *this;
  }
  Type & set__loc_method(
    const int32_t & _arg)
  {
    this->loc_method = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::AgvLoc_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::AgvLoc_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::AgvLoc_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::AgvLoc_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AgvLoc_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AgvLoc_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AgvLoc_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AgvLoc_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::AgvLoc_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::AgvLoc_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__AgvLoc
    std::shared_ptr<com_interfaces::msg::AgvLoc_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__AgvLoc
    std::shared_ptr<com_interfaces::msg::AgvLoc_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AgvLoc_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->current_station != other.current_station) {
      return false;
    }
    if (this->last_station != other.last_station) {
      return false;
    }
    if (this->loc_method != other.loc_method) {
      return false;
    }
    return true;
  }
  bool operator!=(const AgvLoc_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AgvLoc_

// alias to use template instance with default allocator
using AgvLoc =
  com_interfaces::msg::AgvLoc_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_LOC__STRUCT_HPP_
