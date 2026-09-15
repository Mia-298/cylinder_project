// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:srv/VisionEngineCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__STRUCT_HPP_
#define COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__VisionEngineCmdInterface_Request __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__VisionEngineCmdInterface_Request __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct VisionEngineCmdInterface_Request_
{
  using Type = VisionEngineCmdInterface_Request_<ContainerAllocator>;

  explicit VisionEngineCmdInterface_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      std::fill<typename std::array<double, 6>::iterator, double>(this->desc.begin(), this->desc.end(), 0.0);
      this->model_path = "";
      this->input_height = 0l;
      this->input_width = 0l;
      this->confidence_threshold = 0.0;
      this->nms_threshold = 0.0;
    }
  }

  explicit VisionEngineCmdInterface_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : desc(_alloc),
    model_path(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      std::fill<typename std::array<double, 6>::iterator, double>(this->desc.begin(), this->desc.end(), 0.0);
      this->model_path = "";
      this->input_height = 0l;
      this->input_width = 0l;
      this->confidence_threshold = 0.0;
      this->nms_threshold = 0.0;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _desc_type =
    std::array<double, 6>;
  _desc_type desc;
  using _model_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _model_path_type model_path;
  using _input_height_type =
    int32_t;
  _input_height_type input_height;
  using _input_width_type =
    int32_t;
  _input_width_type input_width;
  using _confidence_threshold_type =
    double;
  _confidence_threshold_type confidence_threshold;
  using _nms_threshold_type =
    double;
  _nms_threshold_type nms_threshold;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__desc(
    const std::array<double, 6> & _arg)
  {
    this->desc = _arg;
    return *this;
  }
  Type & set__model_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->model_path = _arg;
    return *this;
  }
  Type & set__input_height(
    const int32_t & _arg)
  {
    this->input_height = _arg;
    return *this;
  }
  Type & set__input_width(
    const int32_t & _arg)
  {
    this->input_width = _arg;
    return *this;
  }
  Type & set__confidence_threshold(
    const double & _arg)
  {
    this->confidence_threshold = _arg;
    return *this;
  }
  Type & set__nms_threshold(
    const double & _arg)
  {
    this->nms_threshold = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__VisionEngineCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__VisionEngineCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::VisionEngineCmdInterface_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VisionEngineCmdInterface_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->desc != other.desc) {
      return false;
    }
    if (this->model_path != other.model_path) {
      return false;
    }
    if (this->input_height != other.input_height) {
      return false;
    }
    if (this->input_width != other.input_width) {
      return false;
    }
    if (this->confidence_threshold != other.confidence_threshold) {
      return false;
    }
    if (this->nms_threshold != other.nms_threshold) {
      return false;
    }
    return true;
  }
  bool operator!=(const VisionEngineCmdInterface_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VisionEngineCmdInterface_Request_

// alias to use template instance with default allocator
using VisionEngineCmdInterface_Request =
  com_interfaces::srv::VisionEngineCmdInterface_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces


// Include directives for member types
// Member 'results'
#include "com_interfaces/msg/detail/yolo_result__struct.hpp"
// Member 'sphere_loc'
#include "com_interfaces/msg/detail/sphere_loc__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__VisionEngineCmdInterface_Response __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__VisionEngineCmdInterface_Response __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct VisionEngineCmdInterface_Response_
{
  using Type = VisionEngineCmdInterface_Response_<ContainerAllocator>;

  explicit VisionEngineCmdInterface_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sphere_loc(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->err_code = 0l;
      this->msg = "";
    }
  }

  explicit VisionEngineCmdInterface_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc),
    sphere_loc(_alloc, _init)
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
  using _results_type =
    std::vector<com_interfaces::msg::YoloResult_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<com_interfaces::msg::YoloResult_<ContainerAllocator>>>;
  _results_type results;
  using _sphere_loc_type =
    com_interfaces::msg::SphereLoc_<ContainerAllocator>;
  _sphere_loc_type sphere_loc;

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
  Type & set__results(
    const std::vector<com_interfaces::msg::YoloResult_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<com_interfaces::msg::YoloResult_<ContainerAllocator>>> & _arg)
  {
    this->results = _arg;
    return *this;
  }
  Type & set__sphere_loc(
    const com_interfaces::msg::SphereLoc_<ContainerAllocator> & _arg)
  {
    this->sphere_loc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__VisionEngineCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__VisionEngineCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::VisionEngineCmdInterface_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VisionEngineCmdInterface_Response_ & other) const
  {
    if (this->err_code != other.err_code) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    if (this->results != other.results) {
      return false;
    }
    if (this->sphere_loc != other.sphere_loc) {
      return false;
    }
    return true;
  }
  bool operator!=(const VisionEngineCmdInterface_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VisionEngineCmdInterface_Response_

// alias to use template instance with default allocator
using VisionEngineCmdInterface_Response =
  com_interfaces::srv::VisionEngineCmdInterface_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces

namespace com_interfaces
{

namespace srv
{

struct VisionEngineCmdInterface
{
  using Request = com_interfaces::srv::VisionEngineCmdInterface_Request;
  using Response = com_interfaces::srv::VisionEngineCmdInterface_Response;
};

}  // namespace srv

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__VISION_ENGINE_CMD_INTERFACE__STRUCT_HPP_
