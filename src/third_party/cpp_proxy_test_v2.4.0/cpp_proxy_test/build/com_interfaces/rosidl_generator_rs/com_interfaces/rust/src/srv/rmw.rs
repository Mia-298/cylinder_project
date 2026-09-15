#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__AuboCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__AuboCmdInterface_Request__init(msg: *mut AuboCmdInterface_Request) -> bool;
    fn com_interfaces__srv__AuboCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AuboCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__AuboCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AuboCmdInterface_Request>);
    fn com_interfaces__srv__AuboCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AuboCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<AuboCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__AuboCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AuboCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 是否使能
    pub en: bool,

    /// 0-关节坐标,1-笛卡尔坐标
    pub joint_or_desc: bool,

    /// 关节坐标运动:对应关节的6个轴;笛卡尔坐标:0-2对应tran坐标的xyz,3-5对应rpy位姿的rx,ry,rz
    pub position: [f64; 6],

    /// 关节轴运动
    /// 关节的轴，运动的关节轴对应1-6
    pub axid: u8,

    /// 运动的方向，0-负时针,1-顺时针
    pub dir: u8,

    /// 单位:度
    pub deg: f64,

    /// 全局设置速度
    pub speed: f64,

    /// 全局设置加速度
    pub acc: f64,

    /// 以后的工具设置
    pub tool: i32,

    /// 机器人操作模式
    pub mode: i32,

    /// 系统变量编号
    pub register_index: i32,

    /// 系统变量的值
    pub register_value: f64,

    /// 0-DI口,1-DO口
    pub input_or_output: bool,

    /// io口的编号 0-15
    pub io_index: i32,

    /// io口的状态
    pub io_value: bool,

    /// 加载的程序名称
    pub program: rosidl_runtime_rs::String,

    /// 记录的间隔，多少毫秒记一次
    pub interval: i32,

    /// csv文件名
    pub filename: rosidl_runtime_rs::String,

    /// 关节位置
    pub joint_path: rosidl_runtime_rs::Sequence<super::super::msg::rmw::JointPoint>,

    /// 夹爪编号
    pub gripper_index: i32,

    /// 0-复位，1-激活
    pub act: u8,

    /// 位置百分比，范围
    pub gripper_pos: i32,

    /// 速度百分比，范围
    pub gripper_vel: i32,

    /// 力矩百分比，范围
    pub gripper_force: i32,

    /// 最大等待时间，范围，单位ms
    pub max_time: i32,

    /// 0-阻塞，1-非阻塞
    pub gripper_block: u8,

}



impl Default for AuboCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__AuboCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__AuboCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AuboCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__AuboCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__AuboCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__AuboCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AuboCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AuboCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/AuboCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__AuboCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__AuboCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__AuboCmdInterface_Response__init(msg: *mut AuboCmdInterface_Response) -> bool;
    fn com_interfaces__srv__AuboCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AuboCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__AuboCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AuboCmdInterface_Response>);
    fn com_interfaces__srv__AuboCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AuboCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<AuboCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__AuboCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AuboCmdInterface_Response {
    /// 错误码
    pub err_code: i32,

    /// 错误信息
    pub msg: rosidl_runtime_rs::String,

    /// 机器人的状态数据
    pub pub_state: super::super::msg::rmw::AuboRobotState,

    /// 机器人寄存器值-只读 与register_index同时用
    pub register_val: f64,

    /// 机器人IO口值，与input_or_output和io_index同时使用
    pub io_val: bool,

    /// 关节位置
    pub jt_pos: [f64; 6],

    /// 笛卡尔位置
    pub tl_pos: [f64; 6],

    /// 力与力矩
    pub ft: super::super::msg::rmw::ForceTorque,

}



impl Default for AuboCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__AuboCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__AuboCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AuboCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__AuboCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__AuboCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__AuboCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AuboCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AuboCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/AuboCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__AuboCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__FrCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__FrCmdInterface_Request__init(msg: *mut FrCmdInterface_Request) -> bool;
    fn com_interfaces__srv__FrCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FrCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__FrCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FrCmdInterface_Request>);
    fn com_interfaces__srv__FrCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FrCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<FrCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__FrCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 是否使能
    pub en: bool,

    /// 0-关节坐标,1-笛卡尔坐标
    pub joint_or_desc: bool,

    /// 关节坐标运动:对应关节的6个轴;笛卡尔坐标:0-2对应tran坐标的xyz,3-5对应rpy位姿的rx,ry,rz
    pub position: [f64; 6],

    /// 关节轴运动
    /// 关节的轴，运动的关节轴对应1-6
    pub axid: u8,

    /// 运动的方向，0-负时针,1-顺时针
    pub dir: u8,

    /// 单位:度
    pub deg: f64,

    /// 全局设置速度
    pub speed: i32,

    /// 全局设置加速度
    pub acc: f64,

    /// 以后的工具设置
    pub tool: i32,

    /// 1. 机器人操作模式
    /// 2. 笛卡尔空间伺服模式运动 0-绝对运动(基坐标系)，1-增量运动(基坐标系)，2-增量运动(工具坐标系)
    pub mode: i32,

    /// 系统变量编号
    pub register_index: i32,

    /// 系统变量的值
    pub register_value: f64,

    /// 0-DI口,1-DO口
    pub input_or_output: bool,

    /// io口的编号 0-15
    pub io_index: i32,

    /// io口的状态
    pub io_value: bool,

    /// 加载的程序名称
    pub program: rosidl_runtime_rs::String,

    /// 记录的间隔，多少毫秒记一次
    pub interval: i32,

    /// csv文件名
    pub filename: rosidl_runtime_rs::String,

    /// 关节位置
    pub joint_path: rosidl_runtime_rs::Sequence<super::super::msg::rmw::JointPoint>,

    /// 夹爪编号
    pub gripper_index: i32,

    /// 0-复位，1-激活
    pub act: u8,

    /// 位置百分比，范围
    pub gripper_pos: i32,

    /// 速度百分比，范围
    pub gripper_vel: i32,

    /// 力矩百分比，范围
    pub gripper_force: i32,

    /// 最大等待时间，范围，单位ms
    pub max_time: i32,

    /// 0-阻塞，1-非阻塞
    pub gripper_block: u8,

    /// 伺服模式运动
    /// 指令下发周期，单位s，建议范围
    pub cmd_t: f32,

    /// 笛卡尔空间伺服模式运动
    /// 位姿增量比例系数，仅在增量运动下生效，范围
    pub pos_gain: [f32; 6],

}



impl Default for FrCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__FrCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__FrCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FrCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__FrCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__FrCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__FrCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FrCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FrCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/FrCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__FrCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__FrCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__FrCmdInterface_Response__init(msg: *mut FrCmdInterface_Response) -> bool;
    fn com_interfaces__srv__FrCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FrCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__FrCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FrCmdInterface_Response>);
    fn com_interfaces__srv__FrCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FrCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<FrCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__FrCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrCmdInterface_Response {
    /// 错误码
    pub err_code: i32,

    /// 错误信息
    pub msg: rosidl_runtime_rs::String,

    /// 机器人的状态数据
    pub pub_state: super::super::msg::rmw::FrRobotState,

    /// 机器人寄存器值-只读 与register_index同时用
    pub register_val: f64,

    /// 机器人IO口值，与input_or_output和io_index同时使用
    pub io_val: bool,

    /// 关节位置
    pub jt_pos: [f64; 6],

    /// 笛卡尔位置
    pub tl_pos: [f64; 6],

    /// 力与力矩
    pub ft: super::super::msg::rmw::ForceTorque,

    /// 力传感器负载重量和质心
    pub force_payload: super::super::msg::rmw::ForcePayload,

    /// 运动是否完成
    pub motion_done: bool,

}



impl Default for FrCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__FrCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__FrCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FrCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__FrCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__FrCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__FrCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FrCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FrCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/FrCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__FrCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RealsenseCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__RealsenseCmdInterface_Request__init(msg: *mut RealsenseCmdInterface_Request) -> bool;
    fn com_interfaces__srv__RealsenseCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RealsenseCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__RealsenseCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RealsenseCmdInterface_Request>);
    fn com_interfaces__srv__RealsenseCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RealsenseCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<RealsenseCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__RealsenseCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RealsenseCmdInterface_Request {
    /// 指令ID
    pub id: i32,

}



impl Default for RealsenseCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__RealsenseCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__RealsenseCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RealsenseCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RealsenseCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RealsenseCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RealsenseCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RealsenseCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RealsenseCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/RealsenseCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RealsenseCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RealsenseCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__RealsenseCmdInterface_Response__init(msg: *mut RealsenseCmdInterface_Response) -> bool;
    fn com_interfaces__srv__RealsenseCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RealsenseCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__RealsenseCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RealsenseCmdInterface_Response>);
    fn com_interfaces__srv__RealsenseCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RealsenseCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<RealsenseCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__RealsenseCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RealsenseCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: rosidl_runtime_rs::String,

}



impl Default for RealsenseCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__RealsenseCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__RealsenseCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RealsenseCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RealsenseCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RealsenseCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RealsenseCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RealsenseCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RealsenseCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/RealsenseCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RealsenseCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RfidReaderCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__RfidReaderCmdInterface_Request__init(msg: *mut RfidReaderCmdInterface_Request) -> bool;
    fn com_interfaces__srv__RfidReaderCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RfidReaderCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__RfidReaderCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RfidReaderCmdInterface_Request>);
    fn com_interfaces__srv__RfidReaderCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RfidReaderCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<RfidReaderCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__RfidReaderCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RfidReaderCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 读写器功率
    pub power: i32,

}



impl Default for RfidReaderCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__RfidReaderCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__RfidReaderCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RfidReaderCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RfidReaderCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RfidReaderCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RfidReaderCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RfidReaderCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RfidReaderCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/RfidReaderCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RfidReaderCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RfidReaderCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__RfidReaderCmdInterface_Response__init(msg: *mut RfidReaderCmdInterface_Response) -> bool;
    fn com_interfaces__srv__RfidReaderCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RfidReaderCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__RfidReaderCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RfidReaderCmdInterface_Response>);
    fn com_interfaces__srv__RfidReaderCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RfidReaderCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<RfidReaderCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__RfidReaderCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RfidReaderCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: rosidl_runtime_rs::String,

    /// 读取到的标签数据
    pub data: rosidl_runtime_rs::String,

}



impl Default for RfidReaderCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__RfidReaderCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__RfidReaderCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RfidReaderCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RfidReaderCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RfidReaderCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RfidReaderCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RfidReaderCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RfidReaderCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/RfidReaderCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RfidReaderCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RmCeuCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__RmCeuCmdInterface_Request__init(msg: *mut RmCeuCmdInterface_Request) -> bool;
    fn com_interfaces__srv__RmCeuCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RmCeuCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__RmCeuCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RmCeuCmdInterface_Request>);
    fn com_interfaces__srv__RmCeuCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RmCeuCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<RmCeuCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__RmCeuCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RmCeuCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 点位编号
    pub point: i32,

}



impl Default for RmCeuCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__RmCeuCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__RmCeuCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RmCeuCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RmCeuCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RmCeuCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RmCeuCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RmCeuCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RmCeuCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/RmCeuCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RmCeuCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RmCeuCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__RmCeuCmdInterface_Response__init(msg: *mut RmCeuCmdInterface_Response) -> bool;
    fn com_interfaces__srv__RmCeuCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RmCeuCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__RmCeuCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RmCeuCmdInterface_Response>);
    fn com_interfaces__srv__RmCeuCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RmCeuCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<RmCeuCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__RmCeuCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RmCeuCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: rosidl_runtime_rs::String,

}



impl Default for RmCeuCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__RmCeuCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__RmCeuCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RmCeuCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RmCeuCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RmCeuCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__RmCeuCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RmCeuCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RmCeuCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/RmCeuCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__RmCeuCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SeerCtrlCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__SeerCtrlCmdInterface_Request__init(msg: *mut SeerCtrlCmdInterface_Request) -> bool;
    fn com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SeerCtrlCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SeerCtrlCmdInterface_Request>);
    fn com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SeerCtrlCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SeerCtrlCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__SeerCtrlCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerCtrlCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 站点
    pub station: rosidl_runtime_rs::String,

    /// 站点列表
    pub station_list: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// 手动控制 x方向线速度 vx (机器人坐标系，单位 m/s)
    pub manual_x: f32,

    /// 手动控制 y方向线速度 vy (机器人坐标系，单位 m/s)
    pub manual_y: f32,

    /// 手动控制 角速度 w (单位 rad/s，逆时针为正，顺时针为负)
    pub manual_w: f32,

    /// 手动控制持续时间  (单位 ms, 0 持续执行直到下条指令 | >0 持续指定时间后停止 | <0 视作忽略该参数)
    pub manual_duration: i32,

    /// 抢占配置控制权时的控制权所有者昵称
    pub nick_name: rosidl_runtime_rs::String,

}



impl Default for SeerCtrlCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__SeerCtrlCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__SeerCtrlCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SeerCtrlCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerCtrlCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SeerCtrlCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SeerCtrlCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/SeerCtrlCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SeerCtrlCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SeerCtrlCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__SeerCtrlCmdInterface_Response__init(msg: *mut SeerCtrlCmdInterface_Response) -> bool;
    fn com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SeerCtrlCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SeerCtrlCmdInterface_Response>);
    fn com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SeerCtrlCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SeerCtrlCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__SeerCtrlCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerCtrlCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: rosidl_runtime_rs::String,

    /// 导航状态
    pub guide_state: super::super::msg::rmw::AgvGuideState,

    /// 当前控制权信息
    pub control: super::super::msg::rmw::AgvControl,

    /// 机器人在世界坐标系中的位置
    pub loc: super::super::msg::rmw::AgvLoc,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_station: super::super::msg::rmw::AgvStation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub station_list: rosidl_runtime_rs::Sequence<super::super::msg::rmw::AgvStation>,

}



impl Default for SeerCtrlCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__SeerCtrlCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__SeerCtrlCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SeerCtrlCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerCtrlCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SeerCtrlCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SeerCtrlCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/SeerCtrlCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SeerCtrlCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SeerM4CmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__SeerM4CmdInterface_Request__init(msg: *mut SeerM4CmdInterface_Request) -> bool;
    fn com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SeerM4CmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SeerM4CmdInterface_Request>);
    fn com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SeerM4CmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SeerM4CmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__SeerM4CmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerM4CmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 点位
    pub point: rosidl_runtime_rs::String,

    /// 货箱ID
    pub container_id: rosidl_runtime_rs::String,

    /// 运单号
    pub order_id: rosidl_runtime_rs::String,

}



impl Default for SeerM4CmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__SeerM4CmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__SeerM4CmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SeerM4CmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerM4CmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SeerM4CmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SeerM4CmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/SeerM4CmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SeerM4CmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SeerM4CmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__SeerM4CmdInterface_Response__init(msg: *mut SeerM4CmdInterface_Response) -> bool;
    fn com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SeerM4CmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SeerM4CmdInterface_Response>);
    fn com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SeerM4CmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SeerM4CmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__SeerM4CmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerM4CmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: rosidl_runtime_rs::String,

    /// 运单号
    pub order_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub order_state: super::super::msg::rmw::AgvOrderState,

}



impl Default for SeerM4CmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__SeerM4CmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__SeerM4CmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SeerM4CmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SeerM4CmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SeerM4CmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SeerM4CmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/SeerM4CmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SeerM4CmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SiemensPlcCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__SiemensPlcCmdInterface_Request__init(msg: *mut SiemensPlcCmdInterface_Request) -> bool;
    fn com_interfaces__srv__SiemensPlcCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SiemensPlcCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__SiemensPlcCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SiemensPlcCmdInterface_Request>);
    fn com_interfaces__srv__SiemensPlcCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SiemensPlcCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SiemensPlcCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__SiemensPlcCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SiemensPlcCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 引脚
    pub pin: u16,

    /// 数字引脚状态
    pub dpin_state: u8,

}



impl Default for SiemensPlcCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__SiemensPlcCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__SiemensPlcCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SiemensPlcCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SiemensPlcCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SiemensPlcCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SiemensPlcCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SiemensPlcCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SiemensPlcCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/SiemensPlcCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SiemensPlcCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SiemensPlcCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__SiemensPlcCmdInterface_Response__init(msg: *mut SiemensPlcCmdInterface_Response) -> bool;
    fn com_interfaces__srv__SiemensPlcCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SiemensPlcCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__SiemensPlcCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SiemensPlcCmdInterface_Response>);
    fn com_interfaces__srv__SiemensPlcCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SiemensPlcCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SiemensPlcCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__SiemensPlcCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SiemensPlcCmdInterface_Response {
    /// 数字引脚状态
    pub dpin_state: u8,

    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: rosidl_runtime_rs::String,

}



impl Default for SiemensPlcCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__SiemensPlcCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__SiemensPlcCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SiemensPlcCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SiemensPlcCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SiemensPlcCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SiemensPlcCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SiemensPlcCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SiemensPlcCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/SiemensPlcCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SiemensPlcCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SmartMoreCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__SmartMoreCmdInterface_Request__init(msg: *mut SmartMoreCmdInterface_Request) -> bool;
    fn com_interfaces__srv__SmartMoreCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartMoreCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__SmartMoreCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartMoreCmdInterface_Request>);
    fn com_interfaces__srv__SmartMoreCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartMoreCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartMoreCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__SmartMoreCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartMoreCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 请求消息
    pub req: rosidl_runtime_rs::String,

}



impl Default for SmartMoreCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__SmartMoreCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__SmartMoreCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartMoreCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SmartMoreCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SmartMoreCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SmartMoreCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartMoreCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartMoreCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/SmartMoreCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SmartMoreCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SmartMoreCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__SmartMoreCmdInterface_Response__init(msg: *mut SmartMoreCmdInterface_Response) -> bool;
    fn com_interfaces__srv__SmartMoreCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartMoreCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__SmartMoreCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartMoreCmdInterface_Response>);
    fn com_interfaces__srv__SmartMoreCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartMoreCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartMoreCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__SmartMoreCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartMoreCmdInterface_Response {
    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub msg: rosidl_runtime_rs::String,

    /// 设备响应消息
    pub res: rosidl_runtime_rs::String,

}



impl Default for SmartMoreCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__SmartMoreCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__SmartMoreCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartMoreCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SmartMoreCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SmartMoreCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__SmartMoreCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartMoreCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartMoreCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/SmartMoreCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__SmartMoreCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VirtAgvCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__VirtAgvCmdInterface_Request__init(msg: *mut VirtAgvCmdInterface_Request) -> bool;
    fn com_interfaces__srv__VirtAgvCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VirtAgvCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__VirtAgvCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VirtAgvCmdInterface_Request>);
    fn com_interfaces__srv__VirtAgvCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VirtAgvCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<VirtAgvCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__VirtAgvCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtAgvCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 站点
    pub station: rosidl_runtime_rs::String,

    /// 站点列表
    pub station_list: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// 手动控制 x方向线速度 vx (机器人坐标系，单位 m/s)
    pub manual_x: f32,

    /// 手动控制 y方向线速度 vy (机器人坐标系，单位 m/s)
    pub manual_y: f32,

    /// 手动控制 角速度 w (单位 rad/s，逆时针为正，顺时针为负)
    pub manual_w: f32,

    /// 手动控制持续时间  (单位 ms, 0 持续执行直到下条指令 | >0 持续指定时间后停止 | <0 视作忽略该参数)
    pub manual_duration: i32,

}



impl Default for VirtAgvCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__VirtAgvCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__VirtAgvCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VirtAgvCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtAgvCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtAgvCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtAgvCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VirtAgvCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VirtAgvCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/VirtAgvCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VirtAgvCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VirtAgvCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__VirtAgvCmdInterface_Response__init(msg: *mut VirtAgvCmdInterface_Response) -> bool;
    fn com_interfaces__srv__VirtAgvCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VirtAgvCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__VirtAgvCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VirtAgvCmdInterface_Response>);
    fn com_interfaces__srv__VirtAgvCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VirtAgvCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<VirtAgvCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__VirtAgvCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtAgvCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: rosidl_runtime_rs::String,

    /// 导航状态 0 = NONE, 1 = WAITING(目前不可能出现该状态), 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED
    pub task_status: i32,

    /// 导航类型 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 7 = 平动转动, 100 = 其他
    pub task_type: i32,

    /// 导航目标站点
    pub target_station: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_station: super::super::msg::rmw::AgvStation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub station_list: rosidl_runtime_rs::Sequence<super::super::msg::rmw::AgvStation>,

}



impl Default for VirtAgvCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__VirtAgvCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__VirtAgvCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VirtAgvCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtAgvCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtAgvCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtAgvCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VirtAgvCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VirtAgvCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/VirtAgvCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VirtAgvCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VirtDevCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__VirtDevCmdInterface_Request__init(msg: *mut VirtDevCmdInterface_Request) -> bool;
    fn com_interfaces__srv__VirtDevCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VirtDevCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__VirtDevCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VirtDevCmdInterface_Request>);
    fn com_interfaces__srv__VirtDevCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VirtDevCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<VirtDevCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__VirtDevCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtDevCmdInterface_Request {
    /// 指令ID
    pub id: i32,

}



impl Default for VirtDevCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__VirtDevCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__VirtDevCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VirtDevCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtDevCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtDevCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtDevCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VirtDevCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VirtDevCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/VirtDevCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VirtDevCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VirtDevCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__VirtDevCmdInterface_Response__init(msg: *mut VirtDevCmdInterface_Response) -> bool;
    fn com_interfaces__srv__VirtDevCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VirtDevCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__VirtDevCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VirtDevCmdInterface_Response>);
    fn com_interfaces__srv__VirtDevCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VirtDevCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<VirtDevCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__VirtDevCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtDevCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: rosidl_runtime_rs::String,

}



impl Default for VirtDevCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__VirtDevCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__VirtDevCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VirtDevCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtDevCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtDevCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VirtDevCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VirtDevCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VirtDevCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/VirtDevCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VirtDevCmdInterface_Response() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VisionEngineCmdInterface_Request() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__VisionEngineCmdInterface_Request__init(msg: *mut VisionEngineCmdInterface_Request) -> bool;
    fn com_interfaces__srv__VisionEngineCmdInterface_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VisionEngineCmdInterface_Request>, size: usize) -> bool;
    fn com_interfaces__srv__VisionEngineCmdInterface_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VisionEngineCmdInterface_Request>);
    fn com_interfaces__srv__VisionEngineCmdInterface_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VisionEngineCmdInterface_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<VisionEngineCmdInterface_Request>) -> bool;
}

// Corresponds to com_interfaces__srv__VisionEngineCmdInterface_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VisionEngineCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 机械臂末端姿态, 笛卡尔坐标:0-2对应tran坐标的xyz,3-5对应rpy位姿的rx,ry,rz
    pub desc: [f64; 6],

    /// YOLO模型初始化
    /// ONNX模型路径
    pub model_path: rosidl_runtime_rs::String,

    /// 模型输入高度
    pub input_height: i32,

    /// 模型输入宽度
    pub input_width: i32,

    /// YOLO检测参数
    /// 置信度阈值
    pub confidence_threshold: f64,

    /// 非极大值抑制阈值
    pub nms_threshold: f64,

}



impl Default for VisionEngineCmdInterface_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__VisionEngineCmdInterface_Request__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__VisionEngineCmdInterface_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VisionEngineCmdInterface_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VisionEngineCmdInterface_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VisionEngineCmdInterface_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VisionEngineCmdInterface_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VisionEngineCmdInterface_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VisionEngineCmdInterface_Request where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/VisionEngineCmdInterface_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VisionEngineCmdInterface_Request() }
  }
}


#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VisionEngineCmdInterface_Response() -> *const std::ffi::c_void;
}

#[link(name = "com_interfaces__rosidl_generator_c")]
extern "C" {
    fn com_interfaces__srv__VisionEngineCmdInterface_Response__init(msg: *mut VisionEngineCmdInterface_Response) -> bool;
    fn com_interfaces__srv__VisionEngineCmdInterface_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VisionEngineCmdInterface_Response>, size: usize) -> bool;
    fn com_interfaces__srv__VisionEngineCmdInterface_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VisionEngineCmdInterface_Response>);
    fn com_interfaces__srv__VisionEngineCmdInterface_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VisionEngineCmdInterface_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<VisionEngineCmdInterface_Response>) -> bool;
}

// Corresponds to com_interfaces__srv__VisionEngineCmdInterface_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VisionEngineCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: rosidl_runtime_rs::String,

    /// YOLO检测结果
    pub results: rosidl_runtime_rs::Sequence<super::super::msg::rmw::YoloResult>,

    /// 球体在相机坐标系中的位置,单位m
    pub sphere_loc: super::super::msg::rmw::SphereLoc,

}



impl Default for VisionEngineCmdInterface_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !com_interfaces__srv__VisionEngineCmdInterface_Response__init(&mut msg as *mut _) {
        panic!("Call to com_interfaces__srv__VisionEngineCmdInterface_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VisionEngineCmdInterface_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VisionEngineCmdInterface_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VisionEngineCmdInterface_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { com_interfaces__srv__VisionEngineCmdInterface_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VisionEngineCmdInterface_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VisionEngineCmdInterface_Response where Self: Sized {
  const TYPE_NAME: &'static str = "com_interfaces/srv/VisionEngineCmdInterface_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__com_interfaces__srv__VisionEngineCmdInterface_Response() }
  }
}






#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__AuboCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__AuboCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct AuboCmdInterface;

impl rosidl_runtime_rs::Service for AuboCmdInterface {
    type Request = AuboCmdInterface_Request;
    type Response = AuboCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__AuboCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__FrCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__FrCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct FrCmdInterface;

impl rosidl_runtime_rs::Service for FrCmdInterface {
    type Request = FrCmdInterface_Request;
    type Response = FrCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__FrCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__RealsenseCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__RealsenseCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct RealsenseCmdInterface;

impl rosidl_runtime_rs::Service for RealsenseCmdInterface {
    type Request = RealsenseCmdInterface_Request;
    type Response = RealsenseCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__RealsenseCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__RfidReaderCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__RfidReaderCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct RfidReaderCmdInterface;

impl rosidl_runtime_rs::Service for RfidReaderCmdInterface {
    type Request = RfidReaderCmdInterface_Request;
    type Response = RfidReaderCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__RfidReaderCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__RmCeuCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__RmCeuCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct RmCeuCmdInterface;

impl rosidl_runtime_rs::Service for RmCeuCmdInterface {
    type Request = RmCeuCmdInterface_Request;
    type Response = RmCeuCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__RmCeuCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__SeerCtrlCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__SeerCtrlCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct SeerCtrlCmdInterface;

impl rosidl_runtime_rs::Service for SeerCtrlCmdInterface {
    type Request = SeerCtrlCmdInterface_Request;
    type Response = SeerCtrlCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__SeerCtrlCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__SeerM4CmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__SeerM4CmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct SeerM4CmdInterface;

impl rosidl_runtime_rs::Service for SeerM4CmdInterface {
    type Request = SeerM4CmdInterface_Request;
    type Response = SeerM4CmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__SeerM4CmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__SiemensPlcCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__SiemensPlcCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct SiemensPlcCmdInterface;

impl rosidl_runtime_rs::Service for SiemensPlcCmdInterface {
    type Request = SiemensPlcCmdInterface_Request;
    type Response = SiemensPlcCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__SiemensPlcCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__SmartMoreCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__SmartMoreCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct SmartMoreCmdInterface;

impl rosidl_runtime_rs::Service for SmartMoreCmdInterface {
    type Request = SmartMoreCmdInterface_Request;
    type Response = SmartMoreCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__SmartMoreCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__VirtAgvCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__VirtAgvCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct VirtAgvCmdInterface;

impl rosidl_runtime_rs::Service for VirtAgvCmdInterface {
    type Request = VirtAgvCmdInterface_Request;
    type Response = VirtAgvCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__VirtAgvCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__VirtDevCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__VirtDevCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct VirtDevCmdInterface;

impl rosidl_runtime_rs::Service for VirtDevCmdInterface {
    type Request = VirtDevCmdInterface_Request;
    type Response = VirtDevCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__VirtDevCmdInterface() }
    }
}




#[link(name = "com_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__VisionEngineCmdInterface() -> *const std::ffi::c_void;
}

// Corresponds to com_interfaces__srv__VisionEngineCmdInterface
#[allow(missing_docs, non_camel_case_types)]
pub struct VisionEngineCmdInterface;

impl rosidl_runtime_rs::Service for VisionEngineCmdInterface {
    type Request = VisionEngineCmdInterface_Request;
    type Response = VisionEngineCmdInterface_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__com_interfaces__srv__VisionEngineCmdInterface() }
    }
}


