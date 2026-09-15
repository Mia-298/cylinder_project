// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/RealsenseState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__RealsenseState __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__RealsenseState __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RealsenseState_
{
  using Type = RealsenseState_<ContainerAllocator>;

  explicit RealsenseState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->err_code = 0l;
      this->err_msg = "";
      this->node_online = false;
      this->color_ready = false;
      this->depth_ready = false;
      this->aligned_depth_ready = false;
      this->color_info_ready = false;
      this->depth_info_ready = false;
      this->color_topic = "";
      this->depth_topic = "";
      this->aligned_depth_topic = "";
      this->color_info_topic = "";
      this->depth_info_topic = "";
      this->last_color_ts_ms = 0ull;
      this->last_depth_ts_ms = 0ull;
      this->last_aligned_depth_ts_ms = 0ull;
      this->last_color_info_ts_ms = 0ull;
      this->last_depth_info_ts_ms = 0ull;
    }
  }

  explicit RealsenseState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    err_msg(_alloc),
    color_topic(_alloc),
    depth_topic(_alloc),
    aligned_depth_topic(_alloc),
    color_info_topic(_alloc),
    depth_info_topic(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->err_code = 0l;
      this->err_msg = "";
      this->node_online = false;
      this->color_ready = false;
      this->depth_ready = false;
      this->aligned_depth_ready = false;
      this->color_info_ready = false;
      this->depth_info_ready = false;
      this->color_topic = "";
      this->depth_topic = "";
      this->aligned_depth_topic = "";
      this->color_info_topic = "";
      this->depth_info_topic = "";
      this->last_color_ts_ms = 0ull;
      this->last_depth_ts_ms = 0ull;
      this->last_aligned_depth_ts_ms = 0ull;
      this->last_color_info_ts_ms = 0ull;
      this->last_depth_info_ts_ms = 0ull;
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
  using _node_online_type =
    bool;
  _node_online_type node_online;
  using _color_ready_type =
    bool;
  _color_ready_type color_ready;
  using _depth_ready_type =
    bool;
  _depth_ready_type depth_ready;
  using _aligned_depth_ready_type =
    bool;
  _aligned_depth_ready_type aligned_depth_ready;
  using _color_info_ready_type =
    bool;
  _color_info_ready_type color_info_ready;
  using _depth_info_ready_type =
    bool;
  _depth_info_ready_type depth_info_ready;
  using _color_topic_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _color_topic_type color_topic;
  using _depth_topic_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _depth_topic_type depth_topic;
  using _aligned_depth_topic_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _aligned_depth_topic_type aligned_depth_topic;
  using _color_info_topic_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _color_info_topic_type color_info_topic;
  using _depth_info_topic_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _depth_info_topic_type depth_info_topic;
  using _last_color_ts_ms_type =
    uint64_t;
  _last_color_ts_ms_type last_color_ts_ms;
  using _last_depth_ts_ms_type =
    uint64_t;
  _last_depth_ts_ms_type last_depth_ts_ms;
  using _last_aligned_depth_ts_ms_type =
    uint64_t;
  _last_aligned_depth_ts_ms_type last_aligned_depth_ts_ms;
  using _last_color_info_ts_ms_type =
    uint64_t;
  _last_color_info_ts_ms_type last_color_info_ts_ms;
  using _last_depth_info_ts_ms_type =
    uint64_t;
  _last_depth_info_ts_ms_type last_depth_info_ts_ms;

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
  Type & set__node_online(
    const bool & _arg)
  {
    this->node_online = _arg;
    return *this;
  }
  Type & set__color_ready(
    const bool & _arg)
  {
    this->color_ready = _arg;
    return *this;
  }
  Type & set__depth_ready(
    const bool & _arg)
  {
    this->depth_ready = _arg;
    return *this;
  }
  Type & set__aligned_depth_ready(
    const bool & _arg)
  {
    this->aligned_depth_ready = _arg;
    return *this;
  }
  Type & set__color_info_ready(
    const bool & _arg)
  {
    this->color_info_ready = _arg;
    return *this;
  }
  Type & set__depth_info_ready(
    const bool & _arg)
  {
    this->depth_info_ready = _arg;
    return *this;
  }
  Type & set__color_topic(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->color_topic = _arg;
    return *this;
  }
  Type & set__depth_topic(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->depth_topic = _arg;
    return *this;
  }
  Type & set__aligned_depth_topic(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->aligned_depth_topic = _arg;
    return *this;
  }
  Type & set__color_info_topic(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->color_info_topic = _arg;
    return *this;
  }
  Type & set__depth_info_topic(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->depth_info_topic = _arg;
    return *this;
  }
  Type & set__last_color_ts_ms(
    const uint64_t & _arg)
  {
    this->last_color_ts_ms = _arg;
    return *this;
  }
  Type & set__last_depth_ts_ms(
    const uint64_t & _arg)
  {
    this->last_depth_ts_ms = _arg;
    return *this;
  }
  Type & set__last_aligned_depth_ts_ms(
    const uint64_t & _arg)
  {
    this->last_aligned_depth_ts_ms = _arg;
    return *this;
  }
  Type & set__last_color_info_ts_ms(
    const uint64_t & _arg)
  {
    this->last_color_info_ts_ms = _arg;
    return *this;
  }
  Type & set__last_depth_info_ts_ms(
    const uint64_t & _arg)
  {
    this->last_depth_info_ts_ms = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::RealsenseState_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::RealsenseState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::RealsenseState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::RealsenseState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::RealsenseState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::RealsenseState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::RealsenseState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::RealsenseState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::RealsenseState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::RealsenseState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__RealsenseState
    std::shared_ptr<com_interfaces::msg::RealsenseState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__RealsenseState
    std::shared_ptr<com_interfaces::msg::RealsenseState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RealsenseState_ & other) const
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
    if (this->node_online != other.node_online) {
      return false;
    }
    if (this->color_ready != other.color_ready) {
      return false;
    }
    if (this->depth_ready != other.depth_ready) {
      return false;
    }
    if (this->aligned_depth_ready != other.aligned_depth_ready) {
      return false;
    }
    if (this->color_info_ready != other.color_info_ready) {
      return false;
    }
    if (this->depth_info_ready != other.depth_info_ready) {
      return false;
    }
    if (this->color_topic != other.color_topic) {
      return false;
    }
    if (this->depth_topic != other.depth_topic) {
      return false;
    }
    if (this->aligned_depth_topic != other.aligned_depth_topic) {
      return false;
    }
    if (this->color_info_topic != other.color_info_topic) {
      return false;
    }
    if (this->depth_info_topic != other.depth_info_topic) {
      return false;
    }
    if (this->last_color_ts_ms != other.last_color_ts_ms) {
      return false;
    }
    if (this->last_depth_ts_ms != other.last_depth_ts_ms) {
      return false;
    }
    if (this->last_aligned_depth_ts_ms != other.last_aligned_depth_ts_ms) {
      return false;
    }
    if (this->last_color_info_ts_ms != other.last_color_info_ts_ms) {
      return false;
    }
    if (this->last_depth_info_ts_ms != other.last_depth_info_ts_ms) {
      return false;
    }
    return true;
  }
  bool operator!=(const RealsenseState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RealsenseState_

// alias to use template instance with default allocator
using RealsenseState =
  com_interfaces::msg::RealsenseState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__REALSENSE_STATE__STRUCT_HPP_
