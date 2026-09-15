// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/VirtAgvState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__VIRT_AGV_STATE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__VIRT_AGV_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__VirtAgvState __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__VirtAgvState __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VirtAgvState_
{
  using Type = VirtAgvState_<ContainerAllocator>;

  explicit VirtAgvState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->err_code = 0l;
      this->err_msg = "";
      this->pose_x = 0.0;
      this->pose_y = 0.0;
      this->angle = 0.0;
      this->confidence = 0.0;
      this->current_station = "";
      this->last_station = "";
      this->vel_x = 0.0;
      this->vel_y = 0.0;
      this->vel_ang = 0.0;
    }
  }

  explicit VirtAgvState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    err_msg(_alloc),
    current_station(_alloc),
    last_station(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->err_code = 0l;
      this->err_msg = "";
      this->pose_x = 0.0;
      this->pose_y = 0.0;
      this->angle = 0.0;
      this->confidence = 0.0;
      this->current_station = "";
      this->last_station = "";
      this->vel_x = 0.0;
      this->vel_y = 0.0;
      this->vel_ang = 0.0;
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
  using _pose_x_type =
    double;
  _pose_x_type pose_x;
  using _pose_y_type =
    double;
  _pose_y_type pose_y;
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
  using _vel_x_type =
    double;
  _vel_x_type vel_x;
  using _vel_y_type =
    double;
  _vel_y_type vel_y;
  using _vel_ang_type =
    double;
  _vel_ang_type vel_ang;

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
  Type & set__pose_x(
    const double & _arg)
  {
    this->pose_x = _arg;
    return *this;
  }
  Type & set__pose_y(
    const double & _arg)
  {
    this->pose_y = _arg;
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
  Type & set__vel_x(
    const double & _arg)
  {
    this->vel_x = _arg;
    return *this;
  }
  Type & set__vel_y(
    const double & _arg)
  {
    this->vel_y = _arg;
    return *this;
  }
  Type & set__vel_ang(
    const double & _arg)
  {
    this->vel_ang = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::VirtAgvState_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::VirtAgvState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::VirtAgvState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::VirtAgvState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::VirtAgvState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::VirtAgvState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::VirtAgvState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::VirtAgvState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::VirtAgvState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::VirtAgvState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__VirtAgvState
    std::shared_ptr<com_interfaces::msg::VirtAgvState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__VirtAgvState
    std::shared_ptr<com_interfaces::msg::VirtAgvState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VirtAgvState_ & other) const
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
    if (this->pose_x != other.pose_x) {
      return false;
    }
    if (this->pose_y != other.pose_y) {
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
    if (this->vel_x != other.vel_x) {
      return false;
    }
    if (this->vel_y != other.vel_y) {
      return false;
    }
    if (this->vel_ang != other.vel_ang) {
      return false;
    }
    return true;
  }
  bool operator!=(const VirtAgvState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VirtAgvState_

// alias to use template instance with default allocator
using VirtAgvState =
  com_interfaces::msg::VirtAgvState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__VIRT_AGV_STATE__STRUCT_HPP_
