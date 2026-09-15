// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:srv/FrCmdInterface.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__SRV__DETAIL__FR_CMD_INTERFACE__BUILDER_HPP_
#define COM_INTERFACES__SRV__DETAIL__FR_CMD_INTERFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/srv/detail/fr_cmd_interface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_FrCmdInterface_Request_pos_gain
{
public:
  explicit Init_FrCmdInterface_Request_pos_gain(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::FrCmdInterface_Request pos_gain(::com_interfaces::srv::FrCmdInterface_Request::_pos_gain_type arg)
  {
    msg_.pos_gain = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_cmd_t
{
public:
  explicit Init_FrCmdInterface_Request_cmd_t(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_pos_gain cmd_t(::com_interfaces::srv::FrCmdInterface_Request::_cmd_t_type arg)
  {
    msg_.cmd_t = std::move(arg);
    return Init_FrCmdInterface_Request_pos_gain(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_gripper_block
{
public:
  explicit Init_FrCmdInterface_Request_gripper_block(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_cmd_t gripper_block(::com_interfaces::srv::FrCmdInterface_Request::_gripper_block_type arg)
  {
    msg_.gripper_block = std::move(arg);
    return Init_FrCmdInterface_Request_cmd_t(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_max_time
{
public:
  explicit Init_FrCmdInterface_Request_max_time(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_gripper_block max_time(::com_interfaces::srv::FrCmdInterface_Request::_max_time_type arg)
  {
    msg_.max_time = std::move(arg);
    return Init_FrCmdInterface_Request_gripper_block(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_gripper_force
{
public:
  explicit Init_FrCmdInterface_Request_gripper_force(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_max_time gripper_force(::com_interfaces::srv::FrCmdInterface_Request::_gripper_force_type arg)
  {
    msg_.gripper_force = std::move(arg);
    return Init_FrCmdInterface_Request_max_time(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_gripper_vel
{
public:
  explicit Init_FrCmdInterface_Request_gripper_vel(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_gripper_force gripper_vel(::com_interfaces::srv::FrCmdInterface_Request::_gripper_vel_type arg)
  {
    msg_.gripper_vel = std::move(arg);
    return Init_FrCmdInterface_Request_gripper_force(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_gripper_pos
{
public:
  explicit Init_FrCmdInterface_Request_gripper_pos(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_gripper_vel gripper_pos(::com_interfaces::srv::FrCmdInterface_Request::_gripper_pos_type arg)
  {
    msg_.gripper_pos = std::move(arg);
    return Init_FrCmdInterface_Request_gripper_vel(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_act
{
public:
  explicit Init_FrCmdInterface_Request_act(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_gripper_pos act(::com_interfaces::srv::FrCmdInterface_Request::_act_type arg)
  {
    msg_.act = std::move(arg);
    return Init_FrCmdInterface_Request_gripper_pos(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_gripper_index
{
public:
  explicit Init_FrCmdInterface_Request_gripper_index(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_act gripper_index(::com_interfaces::srv::FrCmdInterface_Request::_gripper_index_type arg)
  {
    msg_.gripper_index = std::move(arg);
    return Init_FrCmdInterface_Request_act(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_joint_path
{
public:
  explicit Init_FrCmdInterface_Request_joint_path(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_gripper_index joint_path(::com_interfaces::srv::FrCmdInterface_Request::_joint_path_type arg)
  {
    msg_.joint_path = std::move(arg);
    return Init_FrCmdInterface_Request_gripper_index(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_filename
{
public:
  explicit Init_FrCmdInterface_Request_filename(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_joint_path filename(::com_interfaces::srv::FrCmdInterface_Request::_filename_type arg)
  {
    msg_.filename = std::move(arg);
    return Init_FrCmdInterface_Request_joint_path(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_interval
{
public:
  explicit Init_FrCmdInterface_Request_interval(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_filename interval(::com_interfaces::srv::FrCmdInterface_Request::_interval_type arg)
  {
    msg_.interval = std::move(arg);
    return Init_FrCmdInterface_Request_filename(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_program
{
public:
  explicit Init_FrCmdInterface_Request_program(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_interval program(::com_interfaces::srv::FrCmdInterface_Request::_program_type arg)
  {
    msg_.program = std::move(arg);
    return Init_FrCmdInterface_Request_interval(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_io_value
{
public:
  explicit Init_FrCmdInterface_Request_io_value(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_program io_value(::com_interfaces::srv::FrCmdInterface_Request::_io_value_type arg)
  {
    msg_.io_value = std::move(arg);
    return Init_FrCmdInterface_Request_program(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_io_index
{
public:
  explicit Init_FrCmdInterface_Request_io_index(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_io_value io_index(::com_interfaces::srv::FrCmdInterface_Request::_io_index_type arg)
  {
    msg_.io_index = std::move(arg);
    return Init_FrCmdInterface_Request_io_value(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_input_or_output
{
public:
  explicit Init_FrCmdInterface_Request_input_or_output(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_io_index input_or_output(::com_interfaces::srv::FrCmdInterface_Request::_input_or_output_type arg)
  {
    msg_.input_or_output = std::move(arg);
    return Init_FrCmdInterface_Request_io_index(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_register_value
{
public:
  explicit Init_FrCmdInterface_Request_register_value(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_input_or_output register_value(::com_interfaces::srv::FrCmdInterface_Request::_register_value_type arg)
  {
    msg_.register_value = std::move(arg);
    return Init_FrCmdInterface_Request_input_or_output(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_register_index
{
public:
  explicit Init_FrCmdInterface_Request_register_index(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_register_value register_index(::com_interfaces::srv::FrCmdInterface_Request::_register_index_type arg)
  {
    msg_.register_index = std::move(arg);
    return Init_FrCmdInterface_Request_register_value(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_mode
{
public:
  explicit Init_FrCmdInterface_Request_mode(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_register_index mode(::com_interfaces::srv::FrCmdInterface_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_FrCmdInterface_Request_register_index(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_tool
{
public:
  explicit Init_FrCmdInterface_Request_tool(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_mode tool(::com_interfaces::srv::FrCmdInterface_Request::_tool_type arg)
  {
    msg_.tool = std::move(arg);
    return Init_FrCmdInterface_Request_mode(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_acc
{
public:
  explicit Init_FrCmdInterface_Request_acc(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_tool acc(::com_interfaces::srv::FrCmdInterface_Request::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_FrCmdInterface_Request_tool(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_speed
{
public:
  explicit Init_FrCmdInterface_Request_speed(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_acc speed(::com_interfaces::srv::FrCmdInterface_Request::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_FrCmdInterface_Request_acc(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_deg
{
public:
  explicit Init_FrCmdInterface_Request_deg(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_speed deg(::com_interfaces::srv::FrCmdInterface_Request::_deg_type arg)
  {
    msg_.deg = std::move(arg);
    return Init_FrCmdInterface_Request_speed(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_dir
{
public:
  explicit Init_FrCmdInterface_Request_dir(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_deg dir(::com_interfaces::srv::FrCmdInterface_Request::_dir_type arg)
  {
    msg_.dir = std::move(arg);
    return Init_FrCmdInterface_Request_deg(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_axid
{
public:
  explicit Init_FrCmdInterface_Request_axid(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_dir axid(::com_interfaces::srv::FrCmdInterface_Request::_axid_type arg)
  {
    msg_.axid = std::move(arg);
    return Init_FrCmdInterface_Request_dir(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_position
{
public:
  explicit Init_FrCmdInterface_Request_position(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_axid position(::com_interfaces::srv::FrCmdInterface_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_FrCmdInterface_Request_axid(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_joint_or_desc
{
public:
  explicit Init_FrCmdInterface_Request_joint_or_desc(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_position joint_or_desc(::com_interfaces::srv::FrCmdInterface_Request::_joint_or_desc_type arg)
  {
    msg_.joint_or_desc = std::move(arg);
    return Init_FrCmdInterface_Request_position(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_en
{
public:
  explicit Init_FrCmdInterface_Request_en(::com_interfaces::srv::FrCmdInterface_Request & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Request_joint_or_desc en(::com_interfaces::srv::FrCmdInterface_Request::_en_type arg)
  {
    msg_.en = std::move(arg);
    return Init_FrCmdInterface_Request_joint_or_desc(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

class Init_FrCmdInterface_Request_id
{
public:
  Init_FrCmdInterface_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FrCmdInterface_Request_en id(::com_interfaces::srv::FrCmdInterface_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_FrCmdInterface_Request_en(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::FrCmdInterface_Request>()
{
  return com_interfaces::srv::builder::Init_FrCmdInterface_Request_id();
}

}  // namespace com_interfaces


namespace com_interfaces
{

namespace srv
{

namespace builder
{

class Init_FrCmdInterface_Response_motion_done
{
public:
  explicit Init_FrCmdInterface_Response_motion_done(::com_interfaces::srv::FrCmdInterface_Response & msg)
  : msg_(msg)
  {}
  ::com_interfaces::srv::FrCmdInterface_Response motion_done(::com_interfaces::srv::FrCmdInterface_Response::_motion_done_type arg)
  {
    msg_.motion_done = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

class Init_FrCmdInterface_Response_force_payload
{
public:
  explicit Init_FrCmdInterface_Response_force_payload(::com_interfaces::srv::FrCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Response_motion_done force_payload(::com_interfaces::srv::FrCmdInterface_Response::_force_payload_type arg)
  {
    msg_.force_payload = std::move(arg);
    return Init_FrCmdInterface_Response_motion_done(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

class Init_FrCmdInterface_Response_ft
{
public:
  explicit Init_FrCmdInterface_Response_ft(::com_interfaces::srv::FrCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Response_force_payload ft(::com_interfaces::srv::FrCmdInterface_Response::_ft_type arg)
  {
    msg_.ft = std::move(arg);
    return Init_FrCmdInterface_Response_force_payload(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

class Init_FrCmdInterface_Response_tl_pos
{
public:
  explicit Init_FrCmdInterface_Response_tl_pos(::com_interfaces::srv::FrCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Response_ft tl_pos(::com_interfaces::srv::FrCmdInterface_Response::_tl_pos_type arg)
  {
    msg_.tl_pos = std::move(arg);
    return Init_FrCmdInterface_Response_ft(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

class Init_FrCmdInterface_Response_jt_pos
{
public:
  explicit Init_FrCmdInterface_Response_jt_pos(::com_interfaces::srv::FrCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Response_tl_pos jt_pos(::com_interfaces::srv::FrCmdInterface_Response::_jt_pos_type arg)
  {
    msg_.jt_pos = std::move(arg);
    return Init_FrCmdInterface_Response_tl_pos(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

class Init_FrCmdInterface_Response_io_val
{
public:
  explicit Init_FrCmdInterface_Response_io_val(::com_interfaces::srv::FrCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Response_jt_pos io_val(::com_interfaces::srv::FrCmdInterface_Response::_io_val_type arg)
  {
    msg_.io_val = std::move(arg);
    return Init_FrCmdInterface_Response_jt_pos(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

class Init_FrCmdInterface_Response_register_val
{
public:
  explicit Init_FrCmdInterface_Response_register_val(::com_interfaces::srv::FrCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Response_io_val register_val(::com_interfaces::srv::FrCmdInterface_Response::_register_val_type arg)
  {
    msg_.register_val = std::move(arg);
    return Init_FrCmdInterface_Response_io_val(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

class Init_FrCmdInterface_Response_pub_state
{
public:
  explicit Init_FrCmdInterface_Response_pub_state(::com_interfaces::srv::FrCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Response_register_val pub_state(::com_interfaces::srv::FrCmdInterface_Response::_pub_state_type arg)
  {
    msg_.pub_state = std::move(arg);
    return Init_FrCmdInterface_Response_register_val(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

class Init_FrCmdInterface_Response_msg
{
public:
  explicit Init_FrCmdInterface_Response_msg(::com_interfaces::srv::FrCmdInterface_Response & msg)
  : msg_(msg)
  {}
  Init_FrCmdInterface_Response_pub_state msg(::com_interfaces::srv::FrCmdInterface_Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return Init_FrCmdInterface_Response_pub_state(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

class Init_FrCmdInterface_Response_err_code
{
public:
  Init_FrCmdInterface_Response_err_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FrCmdInterface_Response_msg err_code(::com_interfaces::srv::FrCmdInterface_Response::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_FrCmdInterface_Response_msg(msg_);
  }

private:
  ::com_interfaces::srv::FrCmdInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::srv::FrCmdInterface_Response>()
{
  return com_interfaces::srv::builder::Init_FrCmdInterface_Response_err_code();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__SRV__DETAIL__FR_CMD_INTERFACE__BUILDER_HPP_
