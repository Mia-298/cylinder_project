// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/AgvOrderState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__AgvOrderState __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__AgvOrderState __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AgvOrderState_
{
  using Type = AgvOrderState_<ContainerAllocator>;

  explicit AgvOrderState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->status = "";
      this->actual_robot_name = "";
      this->current_step_index = 0l;
      this->done_step_index = 0l;
      this->step_num = 0l;
      this->container_id = "";
      this->loaded = false;
      this->unloaded = false;
      this->fault = false;
      this->fault_reason = "";
      this->execution_reject = "";
    }
  }

  explicit AgvOrderState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : id(_alloc),
    status(_alloc),
    actual_robot_name(_alloc),
    container_id(_alloc),
    fault_reason(_alloc),
    execution_reject(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->status = "";
      this->actual_robot_name = "";
      this->current_step_index = 0l;
      this->done_step_index = 0l;
      this->step_num = 0l;
      this->container_id = "";
      this->loaded = false;
      this->unloaded = false;
      this->fault = false;
      this->fault_reason = "";
      this->execution_reject = "";
    }
  }

  // field types and members
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _id_type id;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;
  using _actual_robot_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _actual_robot_name_type actual_robot_name;
  using _current_step_index_type =
    int32_t;
  _current_step_index_type current_step_index;
  using _done_step_index_type =
    int32_t;
  _done_step_index_type done_step_index;
  using _step_num_type =
    int32_t;
  _step_num_type step_num;
  using _step_locations_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _step_locations_type step_locations;
  using _container_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _container_id_type container_id;
  using _loaded_type =
    bool;
  _loaded_type loaded;
  using _unloaded_type =
    bool;
  _unloaded_type unloaded;
  using _fault_type =
    bool;
  _fault_type fault;
  using _fault_reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fault_reason_type fault_reason;
  using _execution_reject_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _execution_reject_type execution_reject;

  // setters for named parameter idiom
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__actual_robot_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->actual_robot_name = _arg;
    return *this;
  }
  Type & set__current_step_index(
    const int32_t & _arg)
  {
    this->current_step_index = _arg;
    return *this;
  }
  Type & set__done_step_index(
    const int32_t & _arg)
  {
    this->done_step_index = _arg;
    return *this;
  }
  Type & set__step_num(
    const int32_t & _arg)
  {
    this->step_num = _arg;
    return *this;
  }
  Type & set__step_locations(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->step_locations = _arg;
    return *this;
  }
  Type & set__container_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->container_id = _arg;
    return *this;
  }
  Type & set__loaded(
    const bool & _arg)
  {
    this->loaded = _arg;
    return *this;
  }
  Type & set__unloaded(
    const bool & _arg)
  {
    this->unloaded = _arg;
    return *this;
  }
  Type & set__fault(
    const bool & _arg)
  {
    this->fault = _arg;
    return *this;
  }
  Type & set__fault_reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fault_reason = _arg;
    return *this;
  }
  Type & set__execution_reject(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->execution_reject = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::AgvOrderState_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::AgvOrderState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::AgvOrderState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::AgvOrderState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AgvOrderState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AgvOrderState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::AgvOrderState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::AgvOrderState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::AgvOrderState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::AgvOrderState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__AgvOrderState
    std::shared_ptr<com_interfaces::msg::AgvOrderState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__AgvOrderState
    std::shared_ptr<com_interfaces::msg::AgvOrderState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AgvOrderState_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->actual_robot_name != other.actual_robot_name) {
      return false;
    }
    if (this->current_step_index != other.current_step_index) {
      return false;
    }
    if (this->done_step_index != other.done_step_index) {
      return false;
    }
    if (this->step_num != other.step_num) {
      return false;
    }
    if (this->step_locations != other.step_locations) {
      return false;
    }
    if (this->container_id != other.container_id) {
      return false;
    }
    if (this->loaded != other.loaded) {
      return false;
    }
    if (this->unloaded != other.unloaded) {
      return false;
    }
    if (this->fault != other.fault) {
      return false;
    }
    if (this->fault_reason != other.fault_reason) {
      return false;
    }
    if (this->execution_reject != other.execution_reject) {
      return false;
    }
    return true;
  }
  bool operator!=(const AgvOrderState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AgvOrderState_

// alias to use template instance with default allocator
using AgvOrderState =
  com_interfaces::msg::AgvOrderState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__AGV_ORDER_STATE__STRUCT_HPP_
