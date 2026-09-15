// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from com_interfaces:srv/SiemensPlcCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__SIEMENS_PLC_CMD_INTERFACE__STRUCT_HPP_
#define COM_INTERFACES__SRV__DETAIL__SIEMENS_PLC_CMD_INTERFACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__SiemensPlcCmdInterface_Request __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__SiemensPlcCmdInterface_Request __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SiemensPlcCmdInterface_Request_
{
  using Type = SiemensPlcCmdInterface_Request_<ContainerAllocator>;

  explicit SiemensPlcCmdInterface_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->pin = 0;
      this->dpin_state = 0;
    }
  }

  explicit SiemensPlcCmdInterface_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->pin = 0;
      this->dpin_state = 0;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _pin_type =
    uint16_t;
  _pin_type pin;
  using _dpin_state_type =
    uint8_t;
  _dpin_state_type dpin_state;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__pin(
    const uint16_t & _arg)
  {
    this->pin = _arg;
    return *this;
  }
  Type & set__dpin_state(
    const uint8_t & _arg)
  {
    this->dpin_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__SiemensPlcCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__SiemensPlcCmdInterface_Request
    std::shared_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SiemensPlcCmdInterface_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->pin != other.pin) {
      return false;
    }
    if (this->dpin_state != other.dpin_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const SiemensPlcCmdInterface_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SiemensPlcCmdInterface_Request_

// alias to use template instance with default allocator
using SiemensPlcCmdInterface_Request =
  com_interfaces::srv::SiemensPlcCmdInterface_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces


#ifndef _WIN32
# define DEPRECATED__com_interfaces__srv__SiemensPlcCmdInterface_Response __attribute__((deprecated))
#else
# define DEPRECATED__com_interfaces__srv__SiemensPlcCmdInterface_Response __declspec(deprecated)
#endif

namespace com_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SiemensPlcCmdInterface_Response_
{
  using Type = SiemensPlcCmdInterface_Response_<ContainerAllocator>;

  explicit SiemensPlcCmdInterface_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dpin_state = 0;
      this->err_code = 0l;
      this->msg = "";
    }
  }

  explicit SiemensPlcCmdInterface_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : msg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dpin_state = 0;
      this->err_code = 0l;
      this->msg = "";
    }
  }

  // field types and members
  using _dpin_state_type =
    uint8_t;
  _dpin_state_type dpin_state;
  using _err_code_type =
    int32_t;
  _err_code_type err_code;
  using _msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _msg_type msg;

  // setters for named parameter idiom
  Type & set__dpin_state(
    const uint8_t & _arg)
  {
    this->dpin_state = _arg;
    return *this;
  }
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

  // constant declarations

  // pointer types
  using RawPtr =
    com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__com_interfaces__srv__SiemensPlcCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__com_interfaces__srv__SiemensPlcCmdInterface_Response
    std::shared_ptr<com_interfaces::srv::SiemensPlcCmdInterface_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SiemensPlcCmdInterface_Response_ & other) const
  {
    if (this->dpin_state != other.dpin_state) {
      return false;
    }
    if (this->err_code != other.err_code) {
      return false;
    }
    if (this->msg != other.msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const SiemensPlcCmdInterface_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SiemensPlcCmdInterface_Response_

// alias to use template instance with default allocator
using SiemensPlcCmdInterface_Response =
  com_interfaces::srv::SiemensPlcCmdInterface_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace com_interfaces

namespace com_interfaces
{

namespace srv
{

struct SiemensPlcCmdInterface
{
  using Request = com_interfaces::srv::SiemensPlcCmdInterface_Request;
  using Response = com_interfaces::srv::SiemensPlcCmdInterface_Response;
};

}  // namespace srv

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__SIEMENS_PLC_CMD_INTERFACE__STRUCT_HPP_
