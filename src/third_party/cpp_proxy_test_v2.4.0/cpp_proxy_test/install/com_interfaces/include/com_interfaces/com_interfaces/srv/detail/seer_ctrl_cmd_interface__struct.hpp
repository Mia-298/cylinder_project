// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:srv/SeerCtrlCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__STRUCT_HPP_
#define COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__SeerCtrlCmdInterface_Request __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__SeerCtrlCmdInterface_Request __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SeerCtrlCmdInterface_Request_
{
  using Type = SeerCtrlCmdInterface_Request_<ContainerAllocator>;

  explicit SeerCtrlCmdInterface_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->station = "";
      this->manual_x = 0.0f;
      this->manual_y = 0.0f;
      this->manual_w = 0.0f;
      this->manual_duration = 0l;
      this->nick_name = "";
    }
  }

  explicit SeerCtrlCmdInterface_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : station(_alloc),
    nick_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->station = "";
      this->manual_x = 0.0f;
      this->manual_y = 0.0f;
      this->manual_w = 0.0f;
      this->manual_duration = 0l;
      this->nick_name = "";
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _station_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _station_type station;
  using _station_list_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _station_list_type station_list;
  using _manual_x_type =
    float;
  _manual_x_type manual_x;
  using _manual_y_type =
    float;
  _manual_y_type manual_y;
  using _manual_w_type =
    float;
  _manual_w_type manual_w;
  using _manual_duration_type =
    int32_t;
  _manual_duration_type manual_duration;
  using _nick_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _nick_name_type nick_name;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__station(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->station = _arg;
    return *this;
  }
  Type & set__station_list(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->station_list = _arg;
    return *this;
  }
  Type & set__manual_x(
    const float & _arg)
  {
    this->manual_x = _arg;
    return *this;
  }
  Type & set__manual_y(
    const float & _arg)
  {
    this->manual_y = _arg;
    return *this;
  }
  Type & set__manual_w(
    const float & _arg)
  {
    this->manual_w = _arg;
    return *this;
  }
  Type & set__manual_duration(
    const int32_t & _arg)
  {
    this->manual_duration = _arg;
    return *this;
  }
  Type & set__nick_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->nick_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__SeerCtrlCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__SeerCtrlCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SeerCtrlCmdInterface_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->station != other.station) {
      return false;
    }
    if (this->station_list != other.station_list) {
      return false;
    }
    if (this->manual_x != other.manual_x) {
      return false;
    }
    if (this->manual_y != other.manual_y) {
      return false;
    }
    if (this->manual_w != other.manual_w) {
      return false;
    }
    if (this->manual_duration != other.manual_duration) {
      return false;
    }
    if (this->nick_name != other.nick_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const SeerCtrlCmdInterface_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SeerCtrlCmdInterface_Request_

// alias to use template instance with default allocator
using SeerCtrlCmdInterface_Request =
  com_interfaces::srv::SeerCtrlCmdInterface_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces


// Include directives for member types
// Member 'guide_state'
#include "com_interfaces/msg/detail/agv_guide_state__struct.hpp"
// Member 'control'
#include "com_interfaces/msg/detail/agv_control__struct.hpp"
// Member 'loc'
#include "com_interfaces/msg/detail/agv_loc__struct.hpp"
// Member 'current_station'
// Member 'station_list'
#include "com_interfaces/msg/detail/agv_station__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__SeerCtrlCmdInterface_Response __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__SeerCtrlCmdInterface_Response __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SeerCtrlCmdInterface_Response_
{
  using Type = SeerCtrlCmdInterface_Response_<ContainerAllocator>;

  explicit SeerCtrlCmdInterface_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : guide_state(_init),
    control(_init),
    loc(_init),
    current_station(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->msg = "";
    }
  }

  explicit SeerCtrlCmdInterface_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc),
    guide_state(_alloc, _init),
    control(_alloc, _init),
    loc(_alloc, _init),
    current_station(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->msg = "";
    }
  }

  // field types and members
  using _err_code_type =
    int32_t;
  _err_code_type err_code;
  using _msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_type msg;
  using _guide_state_type =
    com_interfaces::msg::AgvGuideState_<ContainerAllocator>;
  _guide_state_type guide_state;
  using _control_type =
    com_interfaces::msg::AgvControl_<ContainerAllocator>;
  _control_type control;
  using _loc_type =
    com_interfaces::msg::AgvLoc_<ContainerAllocator>;
  _loc_type loc;
  using _current_station_type =
    com_interfaces::msg::AgvStation_<ContainerAllocator>;
  _current_station_type current_station;
  using _station_list_type =
    std::vector<com_interfaces::msg::AgvStation_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<com_interfaces::msg::AgvStation_<ContainerAllocator>>>;
  _station_list_type station_list;

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
  Type & set__loc(
    const com_interfaces::msg::AgvLoc_<ContainerAllocator> & _arg)
  {
    this->loc = _arg;
    return *this;
  }
  Type & set__current_station(
    const com_interfaces::msg::AgvStation_<ContainerAllocator> & _arg)
  {
    this->current_station = _arg;
    return *this;
  }
  Type & set__station_list(
    const std::vector<com_interfaces::msg::AgvStation_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<com_interfaces::msg::AgvStation_<ContainerAllocator>>> & _arg)
  {
    this->station_list = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__SeerCtrlCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__SeerCtrlCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::SeerCtrlCmdInterface_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SeerCtrlCmdInterface_Response_ & other) const
  {
    if (this->err_code != other.err_code) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    if (this->guide_state != other.guide_state) {
      return false;
    }
    if (this->control != other.control) {
      return false;
    }
    if (this->loc != other.loc) {
      return false;
    }
    if (this->current_station != other.current_station) {
      return false;
    }
    if (this->station_list != other.station_list) {
      return false;
    }
    return true;
  }
  bool operator!=(const SeerCtrlCmdInterface_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SeerCtrlCmdInterface_Response_

// alias to use template instance with default allocator
using SeerCtrlCmdInterface_Response =
  com_interfaces::srv::SeerCtrlCmdInterface_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces

namespace com_interfaces
{

namespace srv
{

struct SeerCtrlCmdInterface
{
  using Request = com_interfaces::srv::SeerCtrlCmdInterface_Request;
  using Response = com_interfaces::srv::SeerCtrlCmdInterface_Response;
};

}  // namespace srv

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__SEER_CTRL_CMD_INTERFACE__STRUCT_HPP_
