// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from com_interfaces:msg/SeerCtrlState.idl
// generated code does not contain a copyright notice

#ifndef COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__BUILDER_HPP_
#define COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "com_interfaces/msg/detail/seer_ctrl_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace com_interfaces
{

namespace msg
{

namespace builder
{

class Init_SeerCtrlState_control
{
public:
  explicit Init_SeerCtrlState_control(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  ::com_interfaces::msg::SeerCtrlState control(::com_interfaces::msg::SeerCtrlState::_control_type arg)
  {
    msg_.control = std::move(arg);
    return std::move(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_guide_state
{
public:
  explicit Init_SeerCtrlState_guide_state(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_control guide_state(::com_interfaces::msg::SeerCtrlState::_guide_state_type arg)
  {
    msg_.guide_state = std::move(arg);
    return Init_SeerCtrlState_control(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_battery_user_data
{
public:
  explicit Init_SeerCtrlState_battery_user_data(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_guide_state battery_user_data(::com_interfaces::msg::SeerCtrlState::_battery_user_data_type arg)
  {
    msg_.battery_user_data = std::move(arg);
    return Init_SeerCtrlState_guide_state(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_battery_cycle
{
public:
  explicit Init_SeerCtrlState_battery_cycle(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_battery_user_data battery_cycle(::com_interfaces::msg::SeerCtrlState::_battery_cycle_type arg)
  {
    msg_.battery_cycle = std::move(arg);
    return Init_SeerCtrlState_battery_user_data(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_auto_charge
{
public:
  explicit Init_SeerCtrlState_auto_charge(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_battery_cycle auto_charge(::com_interfaces::msg::SeerCtrlState::_auto_charge_type arg)
  {
    msg_.auto_charge = std::move(arg);
    return Init_SeerCtrlState_battery_cycle(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_manual_charge
{
public:
  explicit Init_SeerCtrlState_manual_charge(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_auto_charge manual_charge(::com_interfaces::msg::SeerCtrlState::_manual_charge_type arg)
  {
    msg_.manual_charge = std::move(arg);
    return Init_SeerCtrlState_auto_charge(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_max_charge_current
{
public:
  explicit Init_SeerCtrlState_max_charge_current(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_manual_charge max_charge_current(::com_interfaces::msg::SeerCtrlState::_max_charge_current_type arg)
  {
    msg_.max_charge_current = std::move(arg);
    return Init_SeerCtrlState_manual_charge(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_max_charge_voltage
{
public:
  explicit Init_SeerCtrlState_max_charge_voltage(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_max_charge_current max_charge_voltage(::com_interfaces::msg::SeerCtrlState::_max_charge_voltage_type arg)
  {
    msg_.max_charge_voltage = std::move(arg);
    return Init_SeerCtrlState_max_charge_current(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_current
{
public:
  explicit Init_SeerCtrlState_current(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_max_charge_voltage current(::com_interfaces::msg::SeerCtrlState::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_SeerCtrlState_max_charge_voltage(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_voltage
{
public:
  explicit Init_SeerCtrlState_voltage(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_current voltage(::com_interfaces::msg::SeerCtrlState::_voltage_type arg)
  {
    msg_.voltage = std::move(arg);
    return Init_SeerCtrlState_current(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_charging
{
public:
  explicit Init_SeerCtrlState_charging(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_voltage charging(::com_interfaces::msg::SeerCtrlState::_charging_type arg)
  {
    msg_.charging = std::move(arg);
    return Init_SeerCtrlState_voltage(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_battery_temp
{
public:
  explicit Init_SeerCtrlState_battery_temp(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_charging battery_temp(::com_interfaces::msg::SeerCtrlState::_battery_temp_type arg)
  {
    msg_.battery_temp = std::move(arg);
    return Init_SeerCtrlState_charging(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_battery_level
{
public:
  explicit Init_SeerCtrlState_battery_level(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_battery_temp battery_level(::com_interfaces::msg::SeerCtrlState::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_SeerCtrlState_battery_temp(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_vel_ang
{
public:
  explicit Init_SeerCtrlState_vel_ang(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_battery_level vel_ang(::com_interfaces::msg::SeerCtrlState::_vel_ang_type arg)
  {
    msg_.vel_ang = std::move(arg);
    return Init_SeerCtrlState_battery_level(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_vel_y
{
public:
  explicit Init_SeerCtrlState_vel_y(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_vel_ang vel_y(::com_interfaces::msg::SeerCtrlState::_vel_y_type arg)
  {
    msg_.vel_y = std::move(arg);
    return Init_SeerCtrlState_vel_ang(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_vel_x
{
public:
  explicit Init_SeerCtrlState_vel_x(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_vel_y vel_x(::com_interfaces::msg::SeerCtrlState::_vel_x_type arg)
  {
    msg_.vel_x = std::move(arg);
    return Init_SeerCtrlState_vel_y(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_last_station
{
public:
  explicit Init_SeerCtrlState_last_station(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_vel_x last_station(::com_interfaces::msg::SeerCtrlState::_last_station_type arg)
  {
    msg_.last_station = std::move(arg);
    return Init_SeerCtrlState_vel_x(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_current_station
{
public:
  explicit Init_SeerCtrlState_current_station(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_last_station current_station(::com_interfaces::msg::SeerCtrlState::_current_station_type arg)
  {
    msg_.current_station = std::move(arg);
    return Init_SeerCtrlState_last_station(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_confidence
{
public:
  explicit Init_SeerCtrlState_confidence(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_current_station confidence(::com_interfaces::msg::SeerCtrlState::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_SeerCtrlState_current_station(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_angle
{
public:
  explicit Init_SeerCtrlState_angle(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_confidence angle(::com_interfaces::msg::SeerCtrlState::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_SeerCtrlState_confidence(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_pose_y
{
public:
  explicit Init_SeerCtrlState_pose_y(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_angle pose_y(::com_interfaces::msg::SeerCtrlState::_pose_y_type arg)
  {
    msg_.pose_y = std::move(arg);
    return Init_SeerCtrlState_angle(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_pose_x
{
public:
  explicit Init_SeerCtrlState_pose_x(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_pose_y pose_x(::com_interfaces::msg::SeerCtrlState::_pose_x_type arg)
  {
    msg_.pose_x = std::move(arg);
    return Init_SeerCtrlState_pose_y(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_err_msg
{
public:
  explicit Init_SeerCtrlState_err_msg(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_pose_x err_msg(::com_interfaces::msg::SeerCtrlState::_err_msg_type arg)
  {
    msg_.err_msg = std::move(arg);
    return Init_SeerCtrlState_pose_x(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_err_code
{
public:
  explicit Init_SeerCtrlState_err_code(::com_interfaces::msg::SeerCtrlState & msg)
  : msg_(msg)
  {}
  Init_SeerCtrlState_err_msg err_code(::com_interfaces::msg::SeerCtrlState::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_SeerCtrlState_err_msg(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

class Init_SeerCtrlState_name
{
public:
  Init_SeerCtrlState_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SeerCtrlState_err_code name(::com_interfaces::msg::SeerCtrlState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_SeerCtrlState_err_code(msg_);
  }

private:
  ::com_interfaces::msg::SeerCtrlState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::com_interfaces::msg::SeerCtrlState>()
{
  return com_interfaces::msg::builder::Init_SeerCtrlState_name();
}

}  // namespace com_interfaces

#endif  // COM_INTERFACES__MSG__DETAIL__SEER_CTRL_STATE__BUILDER_HPP_
