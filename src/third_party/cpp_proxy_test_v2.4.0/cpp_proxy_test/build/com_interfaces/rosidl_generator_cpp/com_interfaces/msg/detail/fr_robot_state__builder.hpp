// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/FrRobotState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/fr_robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_FrRobotState_emergency_stop
{
public:
  explicit Init_FrRobotState_emergency_stop(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::FrRobotState emergency_stop(::com_interfaces::msg::FrRobotState::_emergency_stop_type arg)
  {
    msg_.emergency_stop = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_tl_dgt_input_l
{
public:
  explicit Init_FrRobotState_tl_dgt_input_l(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_emergency_stop tl_dgt_input_l(::com_interfaces::msg::FrRobotState::_tl_dgt_input_l_type arg)
  {
    msg_.tl_dgt_input_l = std::move(arg);
    return Init_FrRobotState_emergency_stop(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_tl_dgt_output_l
{
public:
  explicit Init_FrRobotState_tl_dgt_output_l(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_tl_dgt_input_l tl_dgt_output_l(::com_interfaces::msg::FrRobotState::_tl_dgt_output_l_type arg)
  {
    msg_.tl_dgt_output_l = std::move(arg);
    return Init_FrRobotState_tl_dgt_input_l(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_cl_analog_output
{
public:
  explicit Init_FrRobotState_cl_analog_output(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_tl_dgt_output_l cl_analog_output(::com_interfaces::msg::FrRobotState::_cl_analog_output_type arg)
  {
    msg_.cl_analog_output = std::move(arg);
    return Init_FrRobotState_tl_dgt_output_l(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_cl_analog_input
{
public:
  explicit Init_FrRobotState_cl_analog_input(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_cl_analog_output cl_analog_input(::com_interfaces::msg::FrRobotState::_cl_analog_input_type arg)
  {
    msg_.cl_analog_input = std::move(arg);
    return Init_FrRobotState_cl_analog_output(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_cl_dgt_input_l
{
public:
  explicit Init_FrRobotState_cl_dgt_input_l(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_cl_analog_input cl_dgt_input_l(::com_interfaces::msg::FrRobotState::_cl_dgt_input_l_type arg)
  {
    msg_.cl_dgt_input_l = std::move(arg);
    return Init_FrRobotState_cl_analog_input(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_cl_dgt_input_h
{
public:
  explicit Init_FrRobotState_cl_dgt_input_h(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_cl_dgt_input_l cl_dgt_input_h(::com_interfaces::msg::FrRobotState::_cl_dgt_input_h_type arg)
  {
    msg_.cl_dgt_input_h = std::move(arg);
    return Init_FrRobotState_cl_dgt_input_l(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_cl_dgt_output_l
{
public:
  explicit Init_FrRobotState_cl_dgt_output_l(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_cl_dgt_input_h cl_dgt_output_l(::com_interfaces::msg::FrRobotState::_cl_dgt_output_l_type arg)
  {
    msg_.cl_dgt_output_l = std::move(arg);
    return Init_FrRobotState_cl_dgt_input_h(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_cl_dgt_output_h
{
public:
  explicit Init_FrRobotState_cl_dgt_output_h(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_cl_dgt_output_l cl_dgt_output_h(::com_interfaces::msg::FrRobotState::_cl_dgt_output_h_type arg)
  {
    msg_.cl_dgt_output_h = std::move(arg);
    return Init_FrRobotState_cl_dgt_output_l(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_tl_cur_pos
{
public:
  explicit Init_FrRobotState_tl_cur_pos(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_cl_dgt_output_h tl_cur_pos(::com_interfaces::msg::FrRobotState::_tl_cur_pos_type arg)
  {
    msg_.tl_cur_pos = std::move(arg);
    return Init_FrRobotState_cl_dgt_output_h(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_jt_cur_pos
{
public:
  explicit Init_FrRobotState_jt_cur_pos(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_tl_cur_pos jt_cur_pos(::com_interfaces::msg::FrRobotState::_jt_cur_pos_type arg)
  {
    msg_.jt_cur_pos = std::move(arg);
    return Init_FrRobotState_tl_cur_pos(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_robot_speed
{
public:
  explicit Init_FrRobotState_robot_speed(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_jt_cur_pos robot_speed(::com_interfaces::msg::FrRobotState::_robot_speed_type arg)
  {
    msg_.robot_speed = std::move(arg);
    return Init_FrRobotState_jt_cur_pos(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_robot_mode
{
public:
  explicit Init_FrRobotState_robot_mode(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_robot_speed robot_mode(::com_interfaces::msg::FrRobotState::_robot_mode_type arg)
  {
    msg_.robot_mode = std::move(arg);
    return Init_FrRobotState_robot_speed(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_sub_code
{
public:
  explicit Init_FrRobotState_sub_code(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_robot_mode sub_code(::com_interfaces::msg::FrRobotState::_sub_code_type arg)
  {
    msg_.sub_code = std::move(arg);
    return Init_FrRobotState_robot_mode(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_main_code
{
public:
  explicit Init_FrRobotState_main_code(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_sub_code main_code(::com_interfaces::msg::FrRobotState::_main_code_type arg)
  {
    msg_.main_code = std::move(arg);
    return Init_FrRobotState_sub_code(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_robot_err_code
{
public:
  explicit Init_FrRobotState_robot_err_code(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_main_code robot_err_code(::com_interfaces::msg::FrRobotState::_robot_err_code_type arg)
  {
    msg_.robot_err_code = std::move(arg);
    return Init_FrRobotState_main_code(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_robot_motion_done
{
public:
  explicit Init_FrRobotState_robot_motion_done(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_robot_err_code robot_motion_done(::com_interfaces::msg::FrRobotState::_robot_motion_done_type arg)
  {
    msg_.robot_motion_done = std::move(arg);
    return Init_FrRobotState_robot_err_code(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_program_state
{
public:
  explicit Init_FrRobotState_program_state(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_robot_motion_done program_state(::com_interfaces::msg::FrRobotState::_program_state_type arg)
  {
    msg_.program_state = std::move(arg);
    return Init_FrRobotState_robot_motion_done(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_curstep_index
{
public:
  explicit Init_FrRobotState_curstep_index(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_program_state curstep_index(::com_interfaces::msg::FrRobotState::_curstep_index_type arg)
  {
    msg_.curstep_index = std::move(arg);
    return Init_FrRobotState_program_state(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_curtask_index
{
public:
  explicit Init_FrRobotState_curtask_index(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_curstep_index curtask_index(::com_interfaces::msg::FrRobotState::_curtask_index_type arg)
  {
    msg_.curtask_index = std::move(arg);
    return Init_FrRobotState_curstep_index(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_robot_ip
{
public:
  explicit Init_FrRobotState_robot_ip(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_curtask_index robot_ip(::com_interfaces::msg::FrRobotState::_robot_ip_type arg)
  {
    msg_.robot_ip = std::move(arg);
    return Init_FrRobotState_curtask_index(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_robot_soft_index
{
public:
  explicit Init_FrRobotState_robot_soft_index(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_robot_ip robot_soft_index(::com_interfaces::msg::FrRobotState::_robot_soft_index_type arg)
  {
    msg_.robot_soft_index = std::move(arg);
    return Init_FrRobotState_robot_ip(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_robot_type
{
public:
  explicit Init_FrRobotState_robot_type(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_robot_soft_index robot_type(::com_interfaces::msg::FrRobotState::_robot_type_type arg)
  {
    msg_.robot_type = std::move(arg);
    return Init_FrRobotState_robot_soft_index(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_robot_name
{
public:
  explicit Init_FrRobotState_robot_name(::com_interfaces::msg::FrRobotState & msg)
  : msg_(msg)
  {}
  Init_FrRobotState_robot_type robot_name(::com_interfaces::msg::FrRobotState::_robot_name_type arg)
  {
    msg_.robot_name = std::move(arg);
    return Init_FrRobotState_robot_type(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

class Init_FrRobotState_robot_index
{
public:
  Init_FrRobotState_robot_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FrRobotState_robot_name robot_index(::com_interfaces::msg::FrRobotState::_robot_index_type arg)
  {
    msg_.robot_index = std::move(arg);
    return Init_FrRobotState_robot_name(msg_);
  }

private:
  ::com_interfaces::msg::FrRobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::FrRobotState>()
{
  return com_interfaces::msg::builder::Init_FrRobotState_robot_index();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__FR_ROBOT_STATE__BUILDER_HPP_
