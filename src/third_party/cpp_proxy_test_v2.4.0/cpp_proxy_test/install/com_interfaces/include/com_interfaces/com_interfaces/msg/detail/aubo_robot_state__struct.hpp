// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/AuboRobotState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AUBO_ROBOT_STATE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__AUBO_ROBOT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__AuboRobotState __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__AuboRobotState __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AuboRobotState_
{
  using Type = AuboRobotState_<ContainerAllocator>;

  explicit AuboRobotState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_index = 0l;
      this->robot_name = "";
      this->robot_type = "";
      this->robot_soft_index = "";
      this->robot_ip = "";
      this->mode_type = 0l;
      this->safety_mode_type = 0l;
      this->robot_speed = 0.0;
      std::fill<typename std::array<double, 6>::iterator, double>(this->jt_cur_pos.begin(), this->jt_cur_pos.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->tl_cur_pos.begin(), this->tl_cur_pos.end(), 0.0);
    }
  }

  explicit AuboRobotState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_name(_alloc),
    robot_type(_alloc),
    robot_soft_index(_alloc),
    robot_ip(_alloc),
    jt_cur_pos(_alloc),
    tl_cur_pos(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_index = 0l;
      this->robot_name = "";
      this->robot_type = "";
      this->robot_soft_index = "";
      this->robot_ip = "";
      this->mode_type = 0l;
      this->safety_mode_type = 0l;
      this->robot_speed = 0.0;
      std::fill<typename std::array<double, 6>::iterator, double>(this->jt_cur_pos.begin(), this->jt_cur_pos.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->tl_cur_pos.begin(), this->tl_cur_pos.end(), 0.0);
    }
  }

  // field types and members
  using _robot_index_type =
    int32_t;
  _robot_index_type robot_index;
  using _robot_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_name_type robot_name;
  using _robot_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_type_type robot_type;
  using _robot_soft_index_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_soft_index_type robot_soft_index;
  using _robot_ip_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_ip_type robot_ip;
  using _mode_type_type =
    int32_t;
  _mode_type_type mode_type;
  using _safety_mode_type_type =
    int32_t;
  _safety_mode_type_type safety_mode_type;
  using _robot_speed_type =
    double;
  _robot_speed_type robot_speed;
  using _jt_cur_pos_type =
    std::array<double, 6>;
  _jt_cur_pos_type jt_cur_pos;
  using _tl_cur_pos_type =
    std::array<double, 6>;
  _tl_cur_pos_type tl_cur_pos;

  // setters for named parameter idiom
  Type & set__robot_index(
    const int32_t & _arg)
  {
    this->robot_index = _arg;
    return *this;
  }
  Type & set__robot_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_name = _arg;
    return *this;
  }
  Type & set__robot_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_type = _arg;
    return *this;
  }
  Type & set__robot_soft_index(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_soft_index = _arg;
    return *this;
  }
  Type & set__robot_ip(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_ip = _arg;
    return *this;
  }
  Type & set__mode_type(
    const int32_t & _arg)
  {
    this->mode_type = _arg;
    return *this;
  }
  Type & set__safety_mode_type(
    const int32_t & _arg)
  {
    this->safety_mode_type = _arg;
    return *this;
  }
  Type & set__robot_speed(
    const double & _arg)
  {
    this->robot_speed = _arg;
    return *this;
  }
  Type & set__jt_cur_pos(
    const std::array<double, 6> & _arg)
  {
    this->jt_cur_pos = _arg;
    return *this;
  }
  Type & set__tl_cur_pos(
    const std::array<double, 6> & _arg)
  {
    this->tl_cur_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::AuboRobotState_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::AuboRobotState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::AuboRobotState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::AuboRobotState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AuboRobotState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AuboRobotState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AuboRobotState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AuboRobotState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::AuboRobotState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::AuboRobotState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__AuboRobotState
    std::shared_ptr<com_interfaces::msg::AuboRobotState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__AuboRobotState
    std::shared_ptr<com_interfaces::msg::AuboRobotState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AuboRobotState_ & other) const
  {
    if (this->robot_index != other.robot_index) {
      return false;
    }
    if (this->robot_name != other.robot_name) {
      return false;
    }
    if (this->robot_type != other.robot_type) {
      return false;
    }
    if (this->robot_soft_index != other.robot_soft_index) {
      return false;
    }
    if (this->robot_ip != other.robot_ip) {
      return false;
    }
    if (this->mode_type != other.mode_type) {
      return false;
    }
    if (this->safety_mode_type != other.safety_mode_type) {
      return false;
    }
    if (this->robot_speed != other.robot_speed) {
      return false;
    }
    if (this->jt_cur_pos != other.jt_cur_pos) {
      return false;
    }
    if (this->tl_cur_pos != other.tl_cur_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const AuboRobotState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AuboRobotState_

// alias to use template instance with default allocator
using AuboRobotState =
  com_interfaces::msg::AuboRobotState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AUBO_ROBOT_STATE__STRUCT_HPP_
