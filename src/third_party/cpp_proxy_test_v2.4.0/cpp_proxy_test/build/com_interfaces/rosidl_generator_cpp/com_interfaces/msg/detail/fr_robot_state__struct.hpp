// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/FrRobotState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__FrRobotState __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__FrRobotState __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FrRobotState_
{
  using Type = FrRobotState_<ContainerAllocator>;

  explicit FrRobotState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_index = 0l;
      this->robot_name = "";
      this->robot_type = "";
      this->robot_soft_index = "";
      this->robot_ip = "";
      this->curtask_index = 0l;
      this->curstep_index = 0l;
      this->program_state = 0;
      this->robot_motion_done = 0;
      this->robot_err_code = 0;
      this->main_code = 0l;
      this->sub_code = 0l;
      this->robot_mode = 0;
      this->robot_speed = 0.0;
      std::fill<typename std::array<double, 6>::iterator, double>(this->jt_cur_pos.begin(), this->jt_cur_pos.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->tl_cur_pos.begin(), this->tl_cur_pos.end(), 0.0);
      this->cl_dgt_output_h = 0;
      this->cl_dgt_output_l = 0;
      this->cl_dgt_input_h = 0;
      this->cl_dgt_input_l = 0;
      std::fill<typename std::array<uint16_t, 2>::iterator, uint16_t>(this->cl_analog_input.begin(), this->cl_analog_input.end(), 0);
      std::fill<typename std::array<uint16_t, 2>::iterator, uint16_t>(this->cl_analog_output.begin(), this->cl_analog_output.end(), 0);
      this->tl_dgt_output_l = 0;
      this->tl_dgt_input_l = 0;
      this->emergency_stop = 0;
    }
  }

  explicit FrRobotState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_name(_alloc),
    robot_type(_alloc),
    robot_soft_index(_alloc),
    robot_ip(_alloc),
    jt_cur_pos(_alloc),
    tl_cur_pos(_alloc),
    cl_analog_input(_alloc),
    cl_analog_output(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_index = 0l;
      this->robot_name = "";
      this->robot_type = "";
      this->robot_soft_index = "";
      this->robot_ip = "";
      this->curtask_index = 0l;
      this->curstep_index = 0l;
      this->program_state = 0;
      this->robot_motion_done = 0;
      this->robot_err_code = 0;
      this->main_code = 0l;
      this->sub_code = 0l;
      this->robot_mode = 0;
      this->robot_speed = 0.0;
      std::fill<typename std::array<double, 6>::iterator, double>(this->jt_cur_pos.begin(), this->jt_cur_pos.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->tl_cur_pos.begin(), this->tl_cur_pos.end(), 0.0);
      this->cl_dgt_output_h = 0;
      this->cl_dgt_output_l = 0;
      this->cl_dgt_input_h = 0;
      this->cl_dgt_input_l = 0;
      std::fill<typename std::array<uint16_t, 2>::iterator, uint16_t>(this->cl_analog_input.begin(), this->cl_analog_input.end(), 0);
      std::fill<typename std::array<uint16_t, 2>::iterator, uint16_t>(this->cl_analog_output.begin(), this->cl_analog_output.end(), 0);
      this->tl_dgt_output_l = 0;
      this->tl_dgt_input_l = 0;
      this->emergency_stop = 0;
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
  using _curtask_index_type =
    int32_t;
  _curtask_index_type curtask_index;
  using _curstep_index_type =
    int32_t;
  _curstep_index_type curstep_index;
  using _program_state_type =
    uint8_t;
  _program_state_type program_state;
  using _robot_motion_done_type =
    uint8_t;
  _robot_motion_done_type robot_motion_done;
  using _robot_err_code_type =
    uint8_t;
  _robot_err_code_type robot_err_code;
  using _main_code_type =
    int32_t;
  _main_code_type main_code;
  using _sub_code_type =
    int32_t;
  _sub_code_type sub_code;
  using _robot_mode_type =
    uint8_t;
  _robot_mode_type robot_mode;
  using _robot_speed_type =
    double;
  _robot_speed_type robot_speed;
  using _jt_cur_pos_type =
    std::array<double, 6>;
  _jt_cur_pos_type jt_cur_pos;
  using _tl_cur_pos_type =
    std::array<double, 6>;
  _tl_cur_pos_type tl_cur_pos;
  using _cl_dgt_output_h_type =
    uint8_t;
  _cl_dgt_output_h_type cl_dgt_output_h;
  using _cl_dgt_output_l_type =
    uint8_t;
  _cl_dgt_output_l_type cl_dgt_output_l;
  using _cl_dgt_input_h_type =
    uint8_t;
  _cl_dgt_input_h_type cl_dgt_input_h;
  using _cl_dgt_input_l_type =
    uint8_t;
  _cl_dgt_input_l_type cl_dgt_input_l;
  using _cl_analog_input_type =
    std::array<uint16_t, 2>;
  _cl_analog_input_type cl_analog_input;
  using _cl_analog_output_type =
    std::array<uint16_t, 2>;
  _cl_analog_output_type cl_analog_output;
  using _tl_dgt_output_l_type =
    uint8_t;
  _tl_dgt_output_l_type tl_dgt_output_l;
  using _tl_dgt_input_l_type =
    uint8_t;
  _tl_dgt_input_l_type tl_dgt_input_l;
  using _emergency_stop_type =
    uint8_t;
  _emergency_stop_type emergency_stop;

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
  Type & set__curtask_index(
    const int32_t & _arg)
  {
    this->curtask_index = _arg;
    return *this;
  }
  Type & set__curstep_index(
    const int32_t & _arg)
  {
    this->curstep_index = _arg;
    return *this;
  }
  Type & set__program_state(
    const uint8_t & _arg)
  {
    this->program_state = _arg;
    return *this;
  }
  Type & set__robot_motion_done(
    const uint8_t & _arg)
  {
    this->robot_motion_done = _arg;
    return *this;
  }
  Type & set__robot_err_code(
    const uint8_t & _arg)
  {
    this->robot_err_code = _arg;
    return *this;
  }
  Type & set__main_code(
    const int32_t & _arg)
  {
    this->main_code = _arg;
    return *this;
  }
  Type & set__sub_code(
    const int32_t & _arg)
  {
    this->sub_code = _arg;
    return *this;
  }
  Type & set__robot_mode(
    const uint8_t & _arg)
  {
    this->robot_mode = _arg;
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
  Type & set__cl_dgt_output_h(
    const uint8_t & _arg)
  {
    this->cl_dgt_output_h = _arg;
    return *this;
  }
  Type & set__cl_dgt_output_l(
    const uint8_t & _arg)
  {
    this->cl_dgt_output_l = _arg;
    return *this;
  }
  Type & set__cl_dgt_input_h(
    const uint8_t & _arg)
  {
    this->cl_dgt_input_h = _arg;
    return *this;
  }
  Type & set__cl_dgt_input_l(
    const uint8_t & _arg)
  {
    this->cl_dgt_input_l = _arg;
    return *this;
  }
  Type & set__cl_analog_input(
    const std::array<uint16_t, 2> & _arg)
  {
    this->cl_analog_input = _arg;
    return *this;
  }
  Type & set__cl_analog_output(
    const std::array<uint16_t, 2> & _arg)
  {
    this->cl_analog_output = _arg;
    return *this;
  }
  Type & set__tl_dgt_output_l(
    const uint8_t & _arg)
  {
    this->tl_dgt_output_l = _arg;
    return *this;
  }
  Type & set__tl_dgt_input_l(
    const uint8_t & _arg)
  {
    this->tl_dgt_input_l = _arg;
    return *this;
  }
  Type & set__emergency_stop(
    const uint8_t & _arg)
  {
    this->emergency_stop = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::FrRobotState_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::FrRobotState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::FrRobotState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::FrRobotState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::FrRobotState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::FrRobotState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::FrRobotState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::FrRobotState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::FrRobotState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::FrRobotState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__FrRobotState
    std::shared_ptr<com_interfaces::msg::FrRobotState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__FrRobotState
    std::shared_ptr<com_interfaces::msg::FrRobotState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrRobotState_ & other) const
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
    if (this->curtask_index != other.curtask_index) {
      return false;
    }
    if (this->curstep_index != other.curstep_index) {
      return false;
    }
    if (this->program_state != other.program_state) {
      return false;
    }
    if (this->robot_motion_done != other.robot_motion_done) {
      return false;
    }
    if (this->robot_err_code != other.robot_err_code) {
      return false;
    }
    if (this->main_code != other.main_code) {
      return false;
    }
    if (this->sub_code != other.sub_code) {
      return false;
    }
    if (this->robot_mode != other.robot_mode) {
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
    if (this->cl_dgt_output_h != other.cl_dgt_output_h) {
      return false;
    }
    if (this->cl_dgt_output_l != other.cl_dgt_output_l) {
      return false;
    }
    if (this->cl_dgt_input_h != other.cl_dgt_input_h) {
      return false;
    }
    if (this->cl_dgt_input_l != other.cl_dgt_input_l) {
      return false;
    }
    if (this->cl_analog_input != other.cl_analog_input) {
      return false;
    }
    if (this->cl_analog_output != other.cl_analog_output) {
      return false;
    }
    if (this->tl_dgt_output_l != other.tl_dgt_output_l) {
      return false;
    }
    if (this->tl_dgt_input_l != other.tl_dgt_input_l) {
      return false;
    }
    if (this->emergency_stop != other.emergency_stop) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrRobotState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrRobotState_

// alias to use template instance with default allocator
using FrRobotState =
  com_interfaces::msg::FrRobotState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__STRUCT_HPP_
