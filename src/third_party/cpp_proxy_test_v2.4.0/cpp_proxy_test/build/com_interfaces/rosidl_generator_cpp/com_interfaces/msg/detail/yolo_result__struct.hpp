// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:msg/YoloResult.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__STRUCT_HPP_
#define COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__msg__YoloResult __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__msg__YoloResult __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct YoloResult_
{
  using Type = YoloResult_<ContainerAllocator>;

  explicit YoloResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_id = 0l;
      this->confidence = 0.0;
      this->x = 0l;
      this->y = 0l;
      this->width = 0l;
      this->height = 0l;
    }
  }

  explicit YoloResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_id = 0l;
      this->confidence = 0.0;
      this->x = 0l;
      this->y = 0l;
      this->width = 0l;
      this->height = 0l;
    }
  }

  // field types and members
  using _class_id_type =
    int32_t;
  _class_id_type class_id;
  using _confidence_type =
    double;
  _confidence_type confidence;
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;
  using _width_type =
    int32_t;
  _width_type width;
  using _height_type =
    int32_t;
  _height_type height;

  // setters for named parameter idiom
  Type & set__class_id(
    const int32_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__confidence(
    const double & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__x(
    const int32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int32_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__width(
    const int32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const int32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::msg::YoloResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::msg::YoloResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::msg::YoloResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::msg::YoloResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::YoloResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::YoloResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::msg::YoloResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::msg::YoloResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::msg::YoloResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::msg::YoloResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__msg__YoloResult
    std::shared_ptr<com_interfaces::msg::YoloResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__msg__YoloResult
    std::shared_ptr<com_interfaces::msg::YoloResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloResult_ & other) const
  {
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloResult_

// alias to use template instance with default allocator
using YoloResult =
  com_interfaces::msg::YoloResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__YOLO_RESULT__STRUCT_HPP_
