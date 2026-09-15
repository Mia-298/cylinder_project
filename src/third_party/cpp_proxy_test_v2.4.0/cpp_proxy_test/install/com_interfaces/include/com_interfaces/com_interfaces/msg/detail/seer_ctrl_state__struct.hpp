// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/SeerCtrlState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'guide_state'
#include "com_interfaces/msg/detail/agv_guide_state__struct.hpp"
// Member 'control'
#include "com_interfaces/msg/detail/agv_control__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__SeerCtrlState __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__SeerCtrlState __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SeerCtrlState_
{
  using Type = SeerCtrlState_<ContainerAllocator>;

  explicit SeerCtrlState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : guide_state(_init),
    control(_init)
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
      this->battery_level = 0.0;
      this->battery_temp = 0.0;
      this->charging = false;
      this->voltage = 0.0;
      this->current = 0.0;
      this->max_charge_voltage = 0.0;
      this->max_charge_current = 0.0;
      this->manual_charge = false;
      this->auto_charge = false;
      this->battery_cycle = 0l;
      this->battery_user_data = "";
    }
  }

  explicit SeerCtrlState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    err_msg(_alloc),
    current_station(_alloc),
    last_station(_alloc),
    battery_user_data(_alloc),
    guide_state(_alloc, _init),
    control(_alloc, _init)
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
      this->battery_level = 0.0;
      this->battery_temp = 0.0;
      this->charging = false;
      this->voltage = 0.0;
      this->current = 0.0;
      this->max_charge_voltage = 0.0;
      this->max_charge_current = 0.0;
      this->manual_charge = false;
      this->auto_charge = false;
      this->battery_cycle = 0l;
      this->battery_user_data = "";
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
  using _battery_level_type =
    double;
  _battery_level_type battery_level;
  using _battery_temp_type =
    double;
  _battery_temp_type battery_temp;
  using _charging_type =
    bool;
  _charging_type charging;
  using _voltage_type =
    double;
  _voltage_type voltage;
  using _current_type =
    double;
  _current_type current;
  using _max_charge_voltage_type =
    double;
  _max_charge_voltage_type max_charge_voltage;
  using _max_charge_current_type =
    double;
  _max_charge_current_type max_charge_current;
  using _manual_charge_type =
    bool;
  _manual_charge_type manual_charge;
  using _auto_charge_type =
    bool;
  _auto_charge_type auto_charge;
  using _battery_cycle_type =
    int32_t;
  _battery_cycle_type battery_cycle;
  using _battery_user_data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _battery_user_data_type battery_user_data;
  using _guide_state_type =
    com_interfaces::msg::AgvGuideState_<ContainerAllocator>;
  _guide_state_type guide_state;
  using _control_type =
    com_interfaces::msg::AgvControl_<ContainerAllocator>;
  _control_type control;

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
  Type & set__battery_level(
    const double & _arg)
  {
    this->battery_level = _arg;
    return *this;
  }
  Type & set__battery_temp(
    const double & _arg)
  {
    this->battery_temp = _arg;
    return *this;
  }
  Type & set__charging(
    const bool & _arg)
  {
    this->charging = _arg;
    return *this;
  }
  Type & set__voltage(
    const double & _arg)
  {
    this->voltage = _arg;
    return *this;
  }
  Type & set__current(
    const double & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__max_charge_voltage(
    const double & _arg)
  {
    this->max_charge_voltage = _arg;
    return *this;
  }
  Type & set__max_charge_current(
    const double & _arg)
  {
    this->max_charge_current = _arg;
    return *this;
  }
  Type & set__manual_charge(
    const bool & _arg)
  {
    this->manual_charge = _arg;
    return *this;
  }
  Type & set__auto_charge(
    const bool & _arg)
  {
    this->auto_charge = _arg;
    return *this;
  }
  Type & set__battery_cycle(
    const int32_t & _arg)
  {
    this->battery_cycle = _arg;
    return *this;
  }
  Type & set__battery_user_data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->battery_user_data = _arg;
    return *this;
  }
  Type & set__guide_state(
    const com_interfaces::msg::AgvGuideState_<ContainerAllocator> & _arg)
  {
    this->guide_state = _arg;
    return *this;
  }
  Type & set__control(
    const com_interfaces::msg::AgvControl_<ContainerAllocator> & _arg)
  {
    this->control = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::SeerCtrlState_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::SeerCtrlState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::SeerCtrlState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::SeerCtrlState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::SeerCtrlState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::SeerCtrlState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::SeerCtrlState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::SeerCtrlState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::SeerCtrlState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::SeerCtrlState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__SeerCtrlState
    std::shared_ptr<com_interfaces::msg::SeerCtrlState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__SeerCtrlState
    std::shared_ptr<com_interfaces::msg::SeerCtrlState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SeerCtrlState_ & other) const
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
    if (this->battery_level != other.battery_level) {
      return false;
    }
    if (this->battery_temp != other.battery_temp) {
      return false;
    }
    if (this->charging != other.charging) {
      return false;
    }
    if (this->voltage != other.voltage) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->max_charge_voltage != other.max_charge_voltage) {
      return false;
    }
    if (this->max_charge_current != other.max_charge_current) {
      return false;
    }
    if (this->manual_charge != other.manual_charge) {
      return false;
    }
    if (this->auto_charge != other.auto_charge) {
      return false;
    }
    if (this->battery_cycle != other.battery_cycle) {
      return false;
    }
    if (this->battery_user_data != other.battery_user_data) {
      return false;
    }
    if (this->guide_state != other.guide_state) {
      return false;
    }
    if (this->control != other.control) {
      return false;
    }
    return true;
  }
  bool operator!=(const SeerCtrlState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SeerCtrlState_

// alias to use template instance with default allocator
using SeerCtrlState =
  com_interfaces::msg::SeerCtrlState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__STRUCT_HPP_
