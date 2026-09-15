#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AuboRobotState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__AuboRobotState__init(msg: *mut AuboRobotState) -> bool;
    fn com_interfaces__msg__AuboRobotState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AuboRobotState>, size: usize) -> bool;
    fn com_interfaces__msg__AuboRobotState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AuboRobotState>);
    fn com_interfaces__msg__AuboRobotState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AuboRobotState>, out_seq: *mut rosidl_runtime_rs::Sequence<AuboRobotState>) -> bool;
}

// Corresponds to com_interfaces__msg__AuboRobotState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AuboRobotState {
    /// 多机械臂需通过编号来区别
    pub robot_index: i32,

    /// 表示机械臂的作用或任务
    pub robot_name: rosidl_runtime_rs::String,

    /// 机械臂型号
    pub robot_type: rosidl_runtime_rs::String,

    /// 机械臂软件版本
    pub robot_soft_index: rosidl_runtime_rs::String,

    /// 机器人的IP号
    pub robot_ip: rosidl_runtime_rs::String,

    /// 机械臂控制器状态说明：
    /// NoController    (-1)：  示教器专用状态，aubo_control 进程崩溃或未运行。
    /// Disconnected    (0)：   控制器与机械臂本体通信断开（接口板、EtherCAT 等总线断开）。
    /// ConfirmSafety   (1)：   正在进行安全配置，仅允许在断电状态下执行。
    /// Booting         (2)：   机械臂本体正在上电初始化。
    /// PowerOff        (3)：   机械臂本体已断电。
    /// PowerOn         (4)：   机械臂上电完成，刹车未松开，尚未获取关节初始状态。
    /// Idle            (5)：   机械臂上电完成，刹车未松开，电机未使能，已获取关节初始状态。
    /// BrakeReleasing  (6)：   机械臂正在释放刹车。
    /// BackDrive       (7)：   反向拖动模式，刹车已松开，电机不通电。
    /// Running         (8)：   运行模式，刹车已松开，控制权已移交软件。
    /// Maintaince      (9)：   维护模式，用于固件升级、参数写入等维护操作。
    /// Error           (10)：  机械臂处于错误状态。
    /// PowerOffing     (11)：  机械臂正在执行断电流程。
    pub mode_type: i32,

    /// 机械臂安全状态说明：
    /// Undefined           (0)：  安全状态待定。
    /// Normal              (1)：  正常运行模式。
    /// ReducedMode         (2)：  缩减运行模式。
    /// Recovery            (3)：  Recovery 模式。启动时若机械臂位于安全限制范围之外，则进入该模式进行恢复。
    /// Violation           (4)：  安全限制违规状态，如速度超限等超出安全配置限制。
    /// ProtectiveStop      (5)：  保护停机。由软件触发，保持当前轨迹，不抱闸，不断电。
    /// SafeguardStop       (6)：  防护停机。由安全 IO 触发，不保持轨迹，抱闸，不断电。
    /// SystemEmergencyStop (7)：  系统急停。由外部可配置急停输入触发，不向外输出急停信号。
    /// RobotEmergencyStop  (8)：  机器人急停。由控制柜急停输入或示教器急停按键触发，并向外输出急停信号。
    /// Fault               (9)：  故障状态。机械臂硬件故障或系统故障。
    pub safety_mode_type: i32,

    /// 机器人速度 返回百分比
    pub robot_speed: f64,

    /// 关节位置
    pub jt_cur_pos: [f64; 6],

    /// 笛卡尔位置
    pub tl_cur_pos: [f64; 6],

}



impl Default for AuboRobotState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__AuboRobotState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__AuboRobotState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AuboRobotState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AuboRobotState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AuboRobotState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AuboRobotState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AuboRobotState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AuboRobotState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/AuboRobotState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AuboRobotState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__FrRobotState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__FrRobotState__init(msg: *mut FrRobotState) -> bool;
    fn com_interfaces__msg__FrRobotState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FrRobotState>, size: usize) -> bool;
    fn com_interfaces__msg__FrRobotState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FrRobotState>);
    fn com_interfaces__msg__FrRobotState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FrRobotState>, out_seq: *mut rosidl_runtime_rs::Sequence<FrRobotState>) -> bool;
}

// Corresponds to com_interfaces__msg__FrRobotState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrRobotState {
    /// 多机械臂需通过编号来区别
    pub robot_index: i32,

    /// 表示机械臂的作用或任务
    pub robot_name: rosidl_runtime_rs::String,

    /// 机械臂型号
    pub robot_type: rosidl_runtime_rs::String,

    /// 机械臂软件版本
    pub robot_soft_index: rosidl_runtime_rs::String,

    /// 机器人的IP号
    pub robot_ip: rosidl_runtime_rs::String,

    /// 当前任务
    pub curtask_index: i32,

    /// 当前任务的执行步骤
    pub curstep_index: i32,

    /// 程序运行状态
    pub program_state: u8,

    /// 运动状态
    pub robot_motion_done: u8,

    /// 错误码
    pub robot_err_code: u8,

    /// 主故障码 弃用
    pub main_code: i32,

    /// 子故障码 弃用
    pub sub_code: i32,

    /// 机器人模式 手动或者自动
    pub robot_mode: u8,

    /// 机器人速度 返回百分比
    pub robot_speed: f64,

    /// 关节位置
    pub jt_cur_pos: [f64; 6],

    /// 笛卡尔位置
    pub tl_cur_pos: [f64; 6],

    /// 控制箱数字量IO输出15-8
    pub cl_dgt_output_h: u8,

    /// 控制箱数字量IO输出7-0
    pub cl_dgt_output_l: u8,

    /// 控制箱数字量IO输入15-8
    pub cl_dgt_input_h: u8,

    /// 控制箱数字量IO输入7-0
    pub cl_dgt_input_l: u8,

    /// 控制箱模拟输入AI
    pub cl_analog_input: [u16; 2],

    /// 控制箱模拟输出AO
    pub cl_analog_output: [u16; 2],

    /// 工具数字量IO输出7-0 仅bit0和bit1
    pub tl_dgt_output_l: u8,

    /// 工具数字量IO输入7-0 仅bit0和bit1
    pub tl_dgt_input_l: u8,

    /// 急停标志
    pub emergency_stop: u8,

}



impl Default for FrRobotState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__FrRobotState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__FrRobotState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FrRobotState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__FrRobotState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__FrRobotState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__FrRobotState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FrRobotState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FrRobotState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/FrRobotState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__FrRobotState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__RealsenseState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__RealsenseState__init(msg: *mut RealsenseState) -> bool;
    fn com_interfaces__msg__RealsenseState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RealsenseState>, size: usize) -> bool;
    fn com_interfaces__msg__RealsenseState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RealsenseState>);
    fn com_interfaces__msg__RealsenseState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RealsenseState>, out_seq: *mut rosidl_runtime_rs::Sequence<RealsenseState>) -> bool;
}

// Corresponds to com_interfaces__msg__RealsenseState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RealsenseState {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

    /// RealSense ROS2 节点是否在线
    pub node_online: bool,

    /// 彩色图话题是否正常
    pub color_ready: bool,

    /// 深度图话题是否正常
    pub depth_ready: bool,

    /// 对齐深度图话题是否正常
    pub aligned_depth_ready: bool,

    /// 彩色相机内参话题是否正常
    pub color_info_ready: bool,

    /// 深度相机内参话题是否正常
    pub depth_info_ready: bool,

    /// 彩色图话题名
    pub color_topic: rosidl_runtime_rs::String,

    /// 深度图话题名
    pub depth_topic: rosidl_runtime_rs::String,

    /// 对齐深度图话题名
    pub aligned_depth_topic: rosidl_runtime_rs::String,

    /// 彩色相机内参话题名
    pub color_info_topic: rosidl_runtime_rs::String,

    /// 深度相机内参话题名
    pub depth_info_topic: rosidl_runtime_rs::String,

    /// 最近一次收到彩色图消息的本地时间戳(ms)
    pub last_color_ts_ms: u64,

    /// 最近一次收到深度图消息的本地时间戳(ms)
    pub last_depth_ts_ms: u64,

    /// 最近一次收到对齐深度图消息的本地时间戳(ms)
    pub last_aligned_depth_ts_ms: u64,

    /// 最近一次收到彩色相机内参消息的本地时间戳(ms)
    pub last_color_info_ts_ms: u64,

    /// 最近一次收到深度相机内参消息的本地时间戳(ms)
    pub last_depth_info_ts_ms: u64,

}



impl Default for RealsenseState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__RealsenseState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__RealsenseState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RealsenseState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__RealsenseState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__RealsenseState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__RealsenseState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RealsenseState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RealsenseState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/RealsenseState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__RealsenseState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__RfidReaderState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__RfidReaderState__init(msg: *mut RfidReaderState) -> bool;
    fn com_interfaces__msg__RfidReaderState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RfidReaderState>, size: usize) -> bool;
    fn com_interfaces__msg__RfidReaderState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RfidReaderState>);
    fn com_interfaces__msg__RfidReaderState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RfidReaderState>, out_seq: *mut rosidl_runtime_rs::Sequence<RfidReaderState>) -> bool;
}

// Corresponds to com_interfaces__msg__RfidReaderState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RfidReaderState {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

}



impl Default for RfidReaderState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__RfidReaderState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__RfidReaderState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RfidReaderState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__RfidReaderState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__RfidReaderState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__RfidReaderState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RfidReaderState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RfidReaderState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/RfidReaderState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__RfidReaderState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__RmCeuState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__RmCeuState__init(msg: *mut RmCeuState) -> bool;
    fn com_interfaces__msg__RmCeuState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RmCeuState>, size: usize) -> bool;
    fn com_interfaces__msg__RmCeuState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RmCeuState>);
    fn com_interfaces__msg__RmCeuState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RmCeuState>, out_seq: *mut rosidl_runtime_rs::Sequence<RmCeuState>) -> bool;
}

// Corresponds to com_interfaces__msg__RmCeuState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RmCeuState {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

}



impl Default for RmCeuState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__RmCeuState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__RmCeuState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RmCeuState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__RmCeuState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__RmCeuState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__RmCeuState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RmCeuState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RmCeuState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/RmCeuState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__RmCeuState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SeerCtrlState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__SeerCtrlState__init(msg: *mut SeerCtrlState) -> bool;
    fn com_interfaces__msg__SeerCtrlState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SeerCtrlState>, size: usize) -> bool;
    fn com_interfaces__msg__SeerCtrlState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SeerCtrlState>);
    fn com_interfaces__msg__SeerCtrlState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SeerCtrlState>, out_seq: *mut rosidl_runtime_rs::Sequence<SeerCtrlState>) -> bool;
}

// Corresponds to com_interfaces__msg__SeerCtrlState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerCtrlState {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

    /// 小车位置
    /// 小车的x坐标
    pub pose_x: f64,

    /// 小车的y坐标
    pub pose_y: f64,

    /// 小车的angle坐标
    pub angle: f64,

    /// 小车的定位可信度
    pub confidence: f64,

    /// 离小车最近站点的id
    pub current_station: rosidl_runtime_rs::String,

    /// 小车上一个站点的id
    pub last_station: rosidl_runtime_rs::String,

    /// 小车的速度
    /// 小车在x方向上的速度,单位:m/s
    pub vel_x: f64,

    /// 小车在y方向上的速度,单位:m/s
    pub vel_y: f64,

    /// 小车的角速度,顺时针为正,单位:rad/s
    pub vel_ang: f64,

    /// 小车电池状态
    /// 电池电量,范围:[0,1]
    pub battery_level: f64,

    /// 电池温度,单位:℃
    pub battery_temp: f64,

    /// 电池是否正在充电
    pub charging: bool,

    /// 电池电压,单位:V
    pub voltage: f64,

    /// 电池电流,单位:A
    pub current: f64,

    /// 允许充电的最大电压,-1表示不支持,单位:V
    pub max_charge_voltage: f64,

    /// 允许充电的最大电流,-1表示不支持,单位:A
    pub max_charge_current: f64,

    /// 是否连接手动充电器
    pub manual_charge: bool,

    /// 是否连接自动充电桩
    pub auto_charge: bool,

    /// 电池循环次数
    pub battery_cycle: i32,

    /// 电池用户自定义数据
    pub battery_user_data: rosidl_runtime_rs::String,

    /// 小车导航状态
    pub guide_state: super::super::msg::rmw::AgvGuideState,

    /// 小车控制权信息
    pub control: super::super::msg::rmw::AgvControl,

}



impl Default for SeerCtrlState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__SeerCtrlState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__SeerCtrlState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SeerCtrlState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SeerCtrlState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SeerCtrlState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SeerCtrlState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SeerCtrlState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SeerCtrlState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/SeerCtrlState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SeerCtrlState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SeerM4State() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__SeerM4State__init(msg: *mut SeerM4State) -> bool;
    fn com_interfaces__msg__SeerM4State__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SeerM4State>, size: usize) -> bool;
    fn com_interfaces__msg__SeerM4State__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SeerM4State>);
    fn com_interfaces__msg__SeerM4State__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SeerM4State>, out_seq: *mut rosidl_runtime_rs::Sequence<SeerM4State>) -> bool;
}

// Corresponds to com_interfaces__msg__SeerM4State
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerM4State {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

    /// agv运单状态
    pub order_state: super::super::msg::rmw::AgvOrderState,

}



impl Default for SeerM4State {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__SeerM4State__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__SeerM4State__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SeerM4State {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SeerM4State__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SeerM4State__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SeerM4State__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SeerM4State {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SeerM4State where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/SeerM4State";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SeerM4State() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SiemensPlcState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__SiemensPlcState__init(msg: *mut SiemensPlcState) -> bool;
    fn com_interfaces__msg__SiemensPlcState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SiemensPlcState>, size: usize) -> bool;
    fn com_interfaces__msg__SiemensPlcState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SiemensPlcState>);
    fn com_interfaces__msg__SiemensPlcState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SiemensPlcState>, out_seq: *mut rosidl_runtime_rs::Sequence<SiemensPlcState>) -> bool;
}

// Corresponds to com_interfaces__msg__SiemensPlcState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SiemensPlcState {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

}



impl Default for SiemensPlcState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__SiemensPlcState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__SiemensPlcState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SiemensPlcState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SiemensPlcState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SiemensPlcState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SiemensPlcState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SiemensPlcState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SiemensPlcState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/SiemensPlcState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SiemensPlcState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SmartMoreState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__SmartMoreState__init(msg: *mut SmartMoreState) -> bool;
    fn com_interfaces__msg__SmartMoreState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartMoreState>, size: usize) -> bool;
    fn com_interfaces__msg__SmartMoreState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartMoreState>);
    fn com_interfaces__msg__SmartMoreState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartMoreState>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartMoreState>) -> bool;
}

// Corresponds to com_interfaces__msg__SmartMoreState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartMoreState {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

}



impl Default for SmartMoreState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__SmartMoreState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__SmartMoreState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartMoreState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SmartMoreState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SmartMoreState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SmartMoreState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartMoreState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartMoreState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/SmartMoreState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SmartMoreState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__VirtAgvState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__VirtAgvState__init(msg: *mut VirtAgvState) -> bool;
    fn com_interfaces__msg__VirtAgvState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VirtAgvState>, size: usize) -> bool;
    fn com_interfaces__msg__VirtAgvState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VirtAgvState>);
    fn com_interfaces__msg__VirtAgvState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VirtAgvState>, out_seq: *mut rosidl_runtime_rs::Sequence<VirtAgvState>) -> bool;
}

// Corresponds to com_interfaces__msg__VirtAgvState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtAgvState {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

    /// 小车位置
    /// 小车的x坐标
    pub pose_x: f64,

    /// 小车的y坐标
    pub pose_y: f64,

    /// 小车的angle坐标
    pub angle: f64,

    /// 小车的定位可信度
    pub confidence: f64,

    /// 离小车最近站点的id
    pub current_station: rosidl_runtime_rs::String,

    /// 小车上一个站点的id
    pub last_station: rosidl_runtime_rs::String,

    /// 小车的速度
    /// 小车在x方向上的速度,单位:m/s
    pub vel_x: f64,

    /// 小车在y方向上的速度,单位:m/s
    pub vel_y: f64,

    /// 小车的角速度,顺时针为正,单位:rad/s
    pub vel_ang: f64,

}



impl Default for VirtAgvState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__VirtAgvState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__VirtAgvState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VirtAgvState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__VirtAgvState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__VirtAgvState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__VirtAgvState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VirtAgvState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VirtAgvState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/VirtAgvState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__VirtAgvState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__VirtDevState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__VirtDevState__init(msg: *mut VirtDevState) -> bool;
    fn com_interfaces__msg__VirtDevState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VirtDevState>, size: usize) -> bool;
    fn com_interfaces__msg__VirtDevState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VirtDevState>);
    fn com_interfaces__msg__VirtDevState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VirtDevState>, out_seq: *mut rosidl_runtime_rs::Sequence<VirtDevState>) -> bool;
}

// Corresponds to com_interfaces__msg__VirtDevState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtDevState {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

}



impl Default for VirtDevState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__VirtDevState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__VirtDevState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VirtDevState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__VirtDevState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__VirtDevState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__VirtDevState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VirtDevState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VirtDevState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/VirtDevState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__VirtDevState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__VisionEngineState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__VisionEngineState__init(msg: *mut VisionEngineState) -> bool;
    fn com_interfaces__msg__VisionEngineState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VisionEngineState>, size: usize) -> bool;
    fn com_interfaces__msg__VisionEngineState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VisionEngineState>);
    fn com_interfaces__msg__VisionEngineState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VisionEngineState>, out_seq: *mut rosidl_runtime_rs::Sequence<VisionEngineState>) -> bool;
}

// Corresponds to com_interfaces__msg__VisionEngineState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VisionEngineState {
    /// 名称
    pub name: rosidl_runtime_rs::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: rosidl_runtime_rs::String,

}



impl Default for VisionEngineState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__VisionEngineState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__VisionEngineState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VisionEngineState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__VisionEngineState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__VisionEngineState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__VisionEngineState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VisionEngineState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VisionEngineState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/VisionEngineState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__VisionEngineState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvControl() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__AgvControl__init(msg: *mut AgvControl) -> bool;
    fn com_interfaces__msg__AgvControl__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AgvControl>, size: usize) -> bool;
    fn com_interfaces__msg__AgvControl__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AgvControl>);
    fn com_interfaces__msg__AgvControl__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AgvControl>, out_seq: *mut rosidl_runtime_rs::Sequence<AgvControl>) -> bool;
}

// Corresponds to com_interfaces__msg__AgvControl
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// 当前仙工机器人配置控制权信息

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AgvControl {
    /// 当前控制权是否被抢占
    pub locked: bool,

    /// 控制权所有者 IP
    pub ip: rosidl_runtime_rs::String,

    /// 控制权所有者端口
    pub port: i32,

    /// 控制权所有者类型: 0x00 default, 0x02 roboshop, 0xDD srd
    pub type_: u8,

    /// 控制权所有者昵称
    pub nick_name: rosidl_runtime_rs::String,

    /// 抢占控制权的时间戳, Unix 秒
    pub time: i64,

    /// 控制权所有者描述
    pub desc: rosidl_runtime_rs::String,

}



impl Default for AgvControl {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__AgvControl__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__AgvControl__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AgvControl {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvControl__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvControl__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvControl__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AgvControl {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AgvControl where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/AgvControl";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvControl() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvGuideState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__AgvGuideState__init(msg: *mut AgvGuideState) -> bool;
    fn com_interfaces__msg__AgvGuideState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AgvGuideState>, size: usize) -> bool;
    fn com_interfaces__msg__AgvGuideState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AgvGuideState>);
    fn com_interfaces__msg__AgvGuideState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AgvGuideState>, out_seq: *mut rosidl_runtime_rs::Sequence<AgvGuideState>) -> bool;
}

// Corresponds to com_interfaces__msg__AgvGuideState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// 导航状态, 0 = NONE, 1 = WAITING(目前不可能出现该状态), 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AgvGuideState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub task_status: i32,

    /// 导航类型, 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 7 = 平动转动, 100 = 其他
    pub task_type: i32,

    /// 导航目标站点
    pub target_station: rosidl_runtime_rs::String,

}



impl Default for AgvGuideState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__AgvGuideState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__AgvGuideState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AgvGuideState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvGuideState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvGuideState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvGuideState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AgvGuideState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AgvGuideState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/AgvGuideState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvGuideState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvLoc() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__AgvLoc__init(msg: *mut AgvLoc) -> bool;
    fn com_interfaces__msg__AgvLoc__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AgvLoc>, size: usize) -> bool;
    fn com_interfaces__msg__AgvLoc__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AgvLoc>);
    fn com_interfaces__msg__AgvLoc__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AgvLoc>, out_seq: *mut rosidl_runtime_rs::Sequence<AgvLoc>) -> bool;
}

// Corresponds to com_interfaces__msg__AgvLoc
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// 机器人在世界坐标系中的位置

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AgvLoc {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub angle: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_station: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub last_station: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub loc_method: i32,

}



impl Default for AgvLoc {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__AgvLoc__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__AgvLoc__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AgvLoc {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvLoc__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvLoc__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvLoc__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AgvLoc {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AgvLoc where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/AgvLoc";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvLoc() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvOrderState() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__AgvOrderState__init(msg: *mut AgvOrderState) -> bool;
    fn com_interfaces__msg__AgvOrderState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AgvOrderState>, size: usize) -> bool;
    fn com_interfaces__msg__AgvOrderState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AgvOrderState>);
    fn com_interfaces__msg__AgvOrderState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AgvOrderState>, out_seq: *mut rosidl_runtime_rs::Sequence<AgvOrderState>) -> bool;
}

// Corresponds to com_interfaces__msg__AgvOrderState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AgvOrderState {
    /// 单号
    pub id: rosidl_runtime_rs::String,

    /// 单据状态
    /// 运单的状态有 8 个枚举值：
    /// - ToBeAllocated
    /// - Allocated
    /// - Pending
    /// - Executing
    /// - Done
    /// - Cancelling
    /// - Cancelled
    /// - Withdrawing
    pub status: rosidl_runtime_rs::String,

    /// 实际执行机器人
    pub actual_robot_name: rosidl_runtime_rs::String,

    /// 当前正在执行的运单步骤
    pub current_step_index: i32,

    /// 已完成执行的运单步骤
    pub done_step_index: i32,

    /// 运单由几个步骤构成
    pub step_num: i32,

    /// 运单点位列表
    pub step_locations: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// 搬运的容器编号
    pub container_id: rosidl_runtime_rs::String,

    /// 是否已完成取货
    pub loaded: bool,

    /// 是否已完成放货
    pub unloaded: bool,

    /// 运单执行出现故障
    pub fault: bool,

    /// 故障原因
    pub fault_reason: rosidl_runtime_rs::String,

    /// 此运单无法被执行的原因
    pub execution_reject: rosidl_runtime_rs::String,

}



impl Default for AgvOrderState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__AgvOrderState__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__AgvOrderState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AgvOrderState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvOrderState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvOrderState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvOrderState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AgvOrderState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AgvOrderState where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/AgvOrderState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvOrderState() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvStation() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__AgvStation__init(msg: *mut AgvStation) -> bool;
    fn com_interfaces__msg__AgvStation__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AgvStation>, size: usize) -> bool;
    fn com_interfaces__msg__AgvStation__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AgvStation>);
    fn com_interfaces__msg__AgvStation__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AgvStation>, out_seq: *mut rosidl_runtime_rs::Sequence<AgvStation>) -> bool;
}

// Corresponds to com_interfaces__msg__AgvStation
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AgvStation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub name: rosidl_runtime_rs::String,

}



impl Default for AgvStation {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__AgvStation__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__AgvStation__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AgvStation {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvStation__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvStation__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__AgvStation__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AgvStation {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AgvStation where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/AgvStation";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__AgvStation() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__ForcePayload() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__ForcePayload__init(msg: *mut ForcePayload) -> bool;
    fn com_interfaces__msg__ForcePayload__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForcePayload>, size: usize) -> bool;
    fn com_interfaces__msg__ForcePayload__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForcePayload>);
    fn com_interfaces__msg__ForcePayload__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForcePayload>, out_seq: *mut rosidl_runtime_rs::Sequence<ForcePayload>) -> bool;
}

// Corresponds to com_interfaces__msg__ForcePayload
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForcePayload {

    // This member is not documented.
    #[allow(missing_docs)]
    pub weight: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f64,

}



impl Default for ForcePayload {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__ForcePayload__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__ForcePayload__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForcePayload {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__ForcePayload__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__ForcePayload__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__ForcePayload__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForcePayload {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForcePayload where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/ForcePayload";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__ForcePayload() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__ForceTorque() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__ForceTorque__init(msg: *mut ForceTorque) -> bool;
    fn com_interfaces__msg__ForceTorque__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ForceTorque>, size: usize) -> bool;
    fn com_interfaces__msg__ForceTorque__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ForceTorque>);
    fn com_interfaces__msg__ForceTorque__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ForceTorque>, out_seq: *mut rosidl_runtime_rs::Sequence<ForceTorque>) -> bool;
}

// Corresponds to com_interfaces__msg__ForceTorque
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ForceTorque {

    // This member is not documented.
    #[allow(missing_docs)]
    pub fx: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub fy: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub fz: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tx: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ty: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tz: f64,

}



impl Default for ForceTorque {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__ForceTorque__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__ForceTorque__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ForceTorque {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__ForceTorque__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__ForceTorque__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__ForceTorque__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ForceTorque {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ForceTorque where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/ForceTorque";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__ForceTorque() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__JointPoint() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__JointPoint__init(msg: *mut JointPoint) -> bool;
    fn com_interfaces__msg__JointPoint__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<JointPoint>, size: usize) -> bool;
    fn com_interfaces__msg__JointPoint__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<JointPoint>);
    fn com_interfaces__msg__JointPoint__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<JointPoint>, out_seq: *mut rosidl_runtime_rs::Sequence<JointPoint>) -> bool;
}

// Corresponds to com_interfaces__msg__JointPoint
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct JointPoint {

    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_point: [f64; 6],

}



impl Default for JointPoint {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__JointPoint__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__JointPoint__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for JointPoint {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__JointPoint__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__JointPoint__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__JointPoint__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for JointPoint {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for JointPoint where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/JointPoint";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__JointPoint() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SphereLoc() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__SphereLoc__init(msg: *mut SphereLoc) -> bool;
    fn com_interfaces__msg__SphereLoc__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SphereLoc>, size: usize) -> bool;
    fn com_interfaces__msg__SphereLoc__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SphereLoc>);
    fn com_interfaces__msg__SphereLoc__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SphereLoc>, out_seq: *mut rosidl_runtime_rs::Sequence<SphereLoc>) -> bool;
}

// Corresponds to com_interfaces__msg__SphereLoc
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// 球体坐标, m

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SphereLoc {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f64,

}



impl Default for SphereLoc {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__SphereLoc__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__SphereLoc__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SphereLoc {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SphereLoc__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SphereLoc__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__SphereLoc__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SphereLoc {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SphereLoc where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/SphereLoc";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__SphereLoc() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__YoloResult() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__msg__YoloResult__init(msg: *mut YoloResult) -> bool;
    fn com_interfaces__msg__YoloResult__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<YoloResult>, size: usize) -> bool;
    fn com_interfaces__msg__YoloResult__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<YoloResult>);
    fn com_interfaces__msg__YoloResult__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<YoloResult>, out_seq: *mut rosidl_runtime_rs::Sequence<YoloResult>) -> bool;
}

// Corresponds to com_interfaces__msg__YoloResult
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct YoloResult {

    // This member is not documented.
    #[allow(missing_docs)]
    pub class_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub width: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub height: i32,

}



impl Default for YoloResult {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__msg__YoloResult__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__msg__YoloResult__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for YoloResult {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__YoloResult__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__YoloResult__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__msg__YoloResult__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for YoloResult {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for YoloResult where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/msg/YoloResult";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__msg__YoloResult() }
  }
}


