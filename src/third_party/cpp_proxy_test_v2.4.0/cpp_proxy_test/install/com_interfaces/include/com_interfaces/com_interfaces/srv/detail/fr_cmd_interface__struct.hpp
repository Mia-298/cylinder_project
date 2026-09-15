// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:srv/FrCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__FR_CMD_INTERFACE__STRUCT_HPP_
#define COM_INTERFACES__SRV__DETAIL__FR_CMD_INTERFACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'joint_path'
#include "com_interfaces/msg/detail/joint_point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__FrCmdInterface_Request __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__FrCmdInterface_Request __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FrCmdInterface_Request_
{
  using Type = FrCmdInterface_Request_<ContainerAllocator>;

  explicit FrCmdInterface_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->en = false;
      this->joint_or_desc = false;
      std::fill<typename std::array<double, 6>::iterator, double>(this->position.begin(), this->position.end(), 0.0);
      this->axid = 0;
      this->dir = 0;
      this->deg = 0.0;
      this->speed = 0l;
      this->acc = 0.0;
      this->tool = 0l;
      this->mode = 0l;
      this->register_index = 0l;
      this->register_value = 0.0;
      this->input_or_output = false;
      this->io_index = 0l;
      this->io_value = false;
      this->program = "";
      this->interval = 0l;
      this->filename = "";
      this->gripper_index = 0l;
      this->act = 0;
      this->gripper_pos = 0l;
      this->gripper_vel = 0l;
      this->gripper_force = 0l;
      this->max_time = 0l;
      this->gripper_block = 0;
      this->cmd_t = 0.0f;
      std::fill<typename std::array<float, 6>::iterator, float>(this->pos_gain.begin(), this->pos_gain.end(), 0.0f);
    }
  }

  explicit FrCmdInterface_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc),
    program(_alloc),
    filename(_alloc),
    pos_gain(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->en = false;
      this->joint_or_desc = false;
      std::fill<typename std::array<double, 6>::iterator, double>(this->position.begin(), this->position.end(), 0.0);
      this->axid = 0;
      this->dir = 0;
      this->deg = 0.0;
      this->speed = 0l;
      this->acc = 0.0;
      this->tool = 0l;
      this->mode = 0l;
      this->register_index = 0l;
      this->register_value = 0.0;
      this->input_or_output = false;
      this->io_index = 0l;
      this->io_value = false;
      this->program = "";
      this->interval = 0l;
      this->filename = "";
      this->gripper_index = 0l;
      this->act = 0;
      this->gripper_pos = 0l;
      this->gripper_vel = 0l;
      this->gripper_force = 0l;
      this->max_time = 0l;
      this->gripper_block = 0;
      this->cmd_t = 0.0f;
      std::fill<typename std::array<float, 6>::iterator, float>(this->pos_gain.begin(), this->pos_gain.end(), 0.0f);
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _en_type =
    bool;
  _en_type en;
  using _joint_or_desc_type =
    bool;
  _joint_or_desc_type joint_or_desc;
  using _position_type =
    std::array<double, 6>;
  _position_type position;
  using _axid_type =
    uint8_t;
  _axid_type axid;
  using _dir_type =
    uint8_t;
  _dir_type dir;
  using _deg_type =
    double;
  _deg_type deg;
  using _speed_type =
    int32_t;
  _speed_type speed;
  using _acc_type =
    double;
  _acc_type acc;
  using _tool_type =
    int32_t;
  _tool_type tool;
  using _mode_type =
    int32_t;
  _mode_type mode;
  using _register_index_type =
    int32_t;
  _register_index_type register_index;
  using _register_value_type =
    double;
  _register_value_type register_value;
  using _input_or_output_type =
    bool;
  _input_or_output_type input_or_output;
  using _io_index_type =
    int32_t;
  _io_index_type io_index;
  using _io_value_type =
    bool;
  _io_value_type io_value;
  using _program_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _program_type program;
  using _interval_type =
    int32_t;
  _interval_type interval;
  using _filename_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _filename_type filename;
  using _joint_path_type =
    std::vector<com_interfaces::msg::JointPoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<com_interfaces::msg::JointPoint_<ContainerAllocator>>>;
  _joint_path_type joint_path;
  using _gripper_index_type =
    int32_t;
  _gripper_index_type gripper_index;
  using _act_type =
    uint8_t;
  _act_type act;
  using _gripper_pos_type =
    int32_t;
  _gripper_pos_type gripper_pos;
  using _gripper_vel_type =
    int32_t;
  _gripper_vel_type gripper_vel;
  using _gripper_force_type =
    int32_t;
  _gripper_force_type gripper_force;
  using _max_time_type =
    int32_t;
  _max_time_type max_time;
  using _gripper_block_type =
    uint8_t;
  _gripper_block_type gripper_block;
  using _cmd_t_type =
    float;
  _cmd_t_type cmd_t;
  using _pos_gain_type =
    std::array<float, 6>;
  _pos_gain_type pos_gain;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__en(
    const bool & _arg)
  {
    this->en = _arg;
    return *this;
  }
  Type & set__joint_or_desc(
    const bool & _arg)
  {
    this->joint_or_desc = _arg;
    return *this;
  }
  Type & set__position(
    const std::array<double, 6> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__axid(
    const uint8_t & _arg)
  {
    this->axid = _arg;
    return *this;
  }
  Type & set__dir(
    const uint8_t & _arg)
  {
    this->dir = _arg;
    return *this;
  }
  Type & set__deg(
    const double & _arg)
  {
    this->deg = _arg;
    return *this;
  }
  Type & set__speed(
    const int32_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__acc(
    const double & _arg)
  {
    this->acc = _arg;
    return *this;
  }
  Type & set__tool(
    const int32_t & _arg)
  {
    this->tool = _arg;
    return *this;
  }
  Type & set__mode(
    const int32_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__register_index(
    const int32_t & _arg)
  {
    this->register_index = _arg;
    return *this;
  }
  Type & set__register_value(
    const double & _arg)
  {
    this->register_value = _arg;
    return *this;
  }
  Type & set__input_or_output(
    const bool & _arg)
  {
    this->input_or_output = _arg;
    return *this;
  }
  Type & set__io_index(
    const int32_t & _arg)
  {
    this->io_index = _arg;
    return *this;
  }
  Type & set__io_value(
    const bool & _arg)
  {
    this->io_value = _arg;
    return *this;
  }
  Type & set__program(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->program = _arg;
    return *this;
  }
  Type & set__interval(
    const int32_t & _arg)
  {
    this->interval = _arg;
    return *this;
  }
  Type & set__filename(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->filename = _arg;
    return *this;
  }
  Type & set__joint_path(
    const std::vector<com_interfaces::msg::JointPoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<com_interfaces::msg::JointPoint_<ContainerAllocator>>> & _arg)
  {
    this->joint_path = _arg;
    return *this;
  }
  Type & set__gripper_index(
    const int32_t & _arg)
  {
    this->gripper_index = _arg;
    return *this;
  }
  Type & set__act(
    const uint8_t & _arg)
  {
    this->act = _arg;
    return *this;
  }
  Type & set__gripper_pos(
    const int32_t & _arg)
  {
    this->gripper_pos = _arg;
    return *this;
  }
  Type & set__gripper_vel(
    const int32_t & _arg)
  {
    this->gripper_vel = _arg;
    return *this;
  }
  Type & set__gripper_force(
    const int32_t & _arg)
  {
    this->gripper_force = _arg;
    return *this;
  }
  Type & set__max_time(
    const int32_t & _arg)
  {
    this->max_time = _arg;
    return *this;
  }
  Type & set__gripper_block(
    const uint8_t & _arg)
  {
    this->gripper_block = _arg;
    return *this;
  }
  Type & set__cmd_t(
    const float & _arg)
  {
    this->cmd_t = _arg;
    return *this;
  }
  Type & set__pos_gain(
    const std::array<float, 6> & _arg)
  {
    this->pos_gain = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__FrCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__FrCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::FrCmdInterface_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrCmdInterface_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->en != other.en) {
      return false;
    }
    if (this->joint_or_desc != other.joint_or_desc) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->axid != other.axid) {
      return false;
    }
    if (this->dir != other.dir) {
      return false;
    }
    if (this->deg != other.deg) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->acc != other.acc) {
      return false;
    }
    if (this->tool != other.tool) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->register_index != other.register_index) {
      return false;
    }
    if (this->register_value != other.register_value) {
      return false;
    }
    if (this->input_or_output != other.input_or_output) {
      return false;
    }
    if (this->io_index != other.io_index) {
      return false;
    }
    if (this->io_value != other.io_value) {
      return false;
    }
    if (this->program != other.program) {
      return false;
    }
    if (this->interval != other.interval) {
      return false;
    }
    if (this->filename != other.filename) {
      return false;
    }
    if (this->joint_path != other.joint_path) {
      return false;
    }
    if (this->gripper_index != other.gripper_index) {
      return false;
    }
    if (this->act != other.act) {
      return false;
    }
    if (this->gripper_pos != other.gripper_pos) {
      return false;
    }
    if (this->gripper_vel != other.gripper_vel) {
      return false;
    }
    if (this->gripper_force != other.gripper_force) {
      return false;
    }
    if (this->max_time != other.max_time) {
      return false;
    }
    if (this->gripper_block != other.gripper_block) {
      return false;
    }
    if (this->cmd_t != other.cmd_t) {
      return false;
    }
    if (this->pos_gain != other.pos_gain) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrCmdInterface_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrCmdInterface_Request_

// alias to use template instance with default allocator
using FrCmdInterface_Request =
  com_interfaces::srv::FrCmdInterface_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces


// Include directives for member types
// Member 'pub_state'
#include "com_interfaces/msg/detail/fr_robot_state__struct.hpp"
// Member 'ft'
#include "com_interfaces/msg/detail/force_torque__struct.hpp"
// Member 'force_payload'
#include "com_interfaces/msg/detail/force_payload__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__FrCmdInterface_Response __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__FrCmdInterface_Response __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FrCmdInterface_Response_
{
  using Type = FrCmdInterface_Response_<ContainerAllocator>;

  explicit FrCmdInterface_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pub_state(_init),
    ft(_init),
    force_payload(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->msg = "";
      this->register_val = 0.0;
      this->io_val = false;
      std::fill<typename std::array<double, 6>::iterator, double>(this->jt_pos.begin(), this->jt_pos.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->tl_pos.begin(), this->tl_pos.end(), 0.0);
      this->motion_done = false;
    }
  }

  explicit FrCmdInterface_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc),
    pub_state(_alloc, _init),
    jt_pos(_alloc),
    tl_pos(_alloc),
    ft(_alloc, _init),
    force_payload(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->msg = "";
      this->register_val = 0.0;
      this->io_val = false;
      std::fill<typename std::array<double, 6>::iterator, double>(this->jt_pos.begin(), this->jt_pos.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->tl_pos.begin(), this->tl_pos.end(), 0.0);
      this->motion_done = false;
    }
  }

  // field types and members
  using _err_code_type =
    int32_t;
  _err_code_type err_code;
  using _msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_type msg;
  using _pub_state_type =
    com_interfaces::msg::FrRobotState_<ContainerAllocator>;
  _pub_state_type pub_state;
  using _register_val_type =
    double;
  _register_val_type register_val;
  using _io_val_type =
    bool;
  _io_val_type io_val;
  using _jt_pos_type =
    std::array<double, 6>;
  _jt_pos_type jt_pos;
  using _tl_pos_type =
    std::array<double, 6>;
  _tl_pos_type tl_pos;
  using _ft_type =
    com_interfaces::msg::ForceTorque_<ContainerAllocator>;
  _ft_type ft;
  using _force_payload_type =
    com_interfaces::msg::ForcePayload_<ContainerAllocator>;
  _force_payload_type force_payload;
  using _motion_done_type =
    bool;
  _motion_done_type motion_done;

  // setters for named parameter idiom
  Type & set__err_code(
    const int32_t & _arg)
  {
    this->err_code = _arg;
    return *this;
  }
  Type & set__msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->msg = _arg;
    return *this;
  }
  Type & set__pub_state(
    const com_interfaces::msg::FrRobotState_<ContainerAllocator> & _arg)
  {
    this->pub_state = _arg;
    return *this;
  }
  Type & set__register_val(
    const double & _arg)
  {
    this->register_val = _arg;
    return *this;
  }
  Type & set__io_val(
    const bool & _arg)
  {
    this->io_val = _arg;
    return *this;
  }
  Type & set__jt_pos(
    const std::array<double, 6> & _arg)
  {
    this->jt_pos = _arg;
    return *this;
  }
  Type & set__tl_pos(
    const std::array<double, 6> & _arg)
  {
    this->tl_pos = _arg;
    return *this;
  }
  Type & set__ft(
    const com_interfaces::msg::ForceTorque_<ContainerAllocator> & _arg)
  {
    this->ft = _arg;
    return *this;
  }
  Type & set__force_payload(
    const com_interfaces::msg::ForcePayload_<ContainerAllocator> & _arg)
  {
    this->force_payload = _arg;
    return *this;
  }
  Type & set__motion_done(
    const bool & _arg)
  {
    this->motion_done = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__FrCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__FrCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::FrCmdInterface_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrCmdInterface_Response_ & other) const
  {
    if (this->err_code != other.err_code) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    if (this->pub_state != other.pub_state) {
      return false;
    }
    if (this->register_val != other.register_val) {
      return false;
    }
    if (this->io_val != other.io_val) {
      return false;
    }
    if (this->jt_pos != other.jt_pos) {
      return false;
    }
    if (this->tl_pos != other.tl_pos) {
      return false;
    }
    if (this->ft != other.ft) {
      return false;
    }
    if (this->force_payload != other.force_payload) {
      return false;
    }
    if (this->motion_done != other.motion_done) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrCmdInterface_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrCmdInterface_Response_

// alias to use template instance with default allocator
using FrCmdInterface_Response =
  com_interfaces::srv::FrCmdInterface_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces

namespace com_interfaces
{

namespace srv
{

struct FrCmdInterface
{
  using Request = com_interfaces::srv::FrCmdInterface_Request;
  using Response = com_interfaces::srv::FrCmdInterface_Response;
};

}  // namespace srv

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__FR_CMD_INTERFACE__STRUCT_HPP_
