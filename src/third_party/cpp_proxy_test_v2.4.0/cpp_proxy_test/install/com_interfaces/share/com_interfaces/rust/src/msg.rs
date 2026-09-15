#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to com_interfaces__msg__AuboRobotState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AuboRobotState {
    /// 多机械臂需通过编号来区别
    pub robot_index: i32,

    /// 表示机械臂的作用或任务
    pub robot_name: std::string::String,

    /// 机械臂型号
    pub robot_type: std::string::String,

    /// 机械臂软件版本
    pub robot_soft_index: std::string::String,

    /// 机器人的IP号
    pub robot_ip: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AuboRobotState::default())
  }
}

impl rosidl_runtime_rs::Message for AuboRobotState {
  type RmwMsg = super::msg::rmw::AuboRobotState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        robot_index: msg.robot_index,
        robot_name: msg.robot_name.as_str().into(),
        robot_type: msg.robot_type.as_str().into(),
        robot_soft_index: msg.robot_soft_index.as_str().into(),
        robot_ip: msg.robot_ip.as_str().into(),
        mode_type: msg.mode_type,
        safety_mode_type: msg.safety_mode_type,
        robot_speed: msg.robot_speed,
        jt_cur_pos: msg.jt_cur_pos,
        tl_cur_pos: msg.tl_cur_pos,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      robot_index: msg.robot_index,
        robot_name: msg.robot_name.as_str().into(),
        robot_type: msg.robot_type.as_str().into(),
        robot_soft_index: msg.robot_soft_index.as_str().into(),
        robot_ip: msg.robot_ip.as_str().into(),
      mode_type: msg.mode_type,
      safety_mode_type: msg.safety_mode_type,
      robot_speed: msg.robot_speed,
        jt_cur_pos: msg.jt_cur_pos,
        tl_cur_pos: msg.tl_cur_pos,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      robot_index: msg.robot_index,
      robot_name: msg.robot_name.to_string(),
      robot_type: msg.robot_type.to_string(),
      robot_soft_index: msg.robot_soft_index.to_string(),
      robot_ip: msg.robot_ip.to_string(),
      mode_type: msg.mode_type,
      safety_mode_type: msg.safety_mode_type,
      robot_speed: msg.robot_speed,
      jt_cur_pos: msg.jt_cur_pos,
      tl_cur_pos: msg.tl_cur_pos,
    }
  }
}


// Corresponds to com_interfaces__msg__FrRobotState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrRobotState {
    /// 多机械臂需通过编号来区别
    pub robot_index: i32,

    /// 表示机械臂的作用或任务
    pub robot_name: std::string::String,

    /// 机械臂型号
    pub robot_type: std::string::String,

    /// 机械臂软件版本
    pub robot_soft_index: std::string::String,

    /// 机器人的IP号
    pub robot_ip: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FrRobotState::default())
  }
}

impl rosidl_runtime_rs::Message for FrRobotState {
  type RmwMsg = super::msg::rmw::FrRobotState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        robot_index: msg.robot_index,
        robot_name: msg.robot_name.as_str().into(),
        robot_type: msg.robot_type.as_str().into(),
        robot_soft_index: msg.robot_soft_index.as_str().into(),
        robot_ip: msg.robot_ip.as_str().into(),
        curtask_index: msg.curtask_index,
        curstep_index: msg.curstep_index,
        program_state: msg.program_state,
        robot_motion_done: msg.robot_motion_done,
        robot_err_code: msg.robot_err_code,
        main_code: msg.main_code,
        sub_code: msg.sub_code,
        robot_mode: msg.robot_mode,
        robot_speed: msg.robot_speed,
        jt_cur_pos: msg.jt_cur_pos,
        tl_cur_pos: msg.tl_cur_pos,
        cl_dgt_output_h: msg.cl_dgt_output_h,
        cl_dgt_output_l: msg.cl_dgt_output_l,
        cl_dgt_input_h: msg.cl_dgt_input_h,
        cl_dgt_input_l: msg.cl_dgt_input_l,
        cl_analog_input: msg.cl_analog_input,
        cl_analog_output: msg.cl_analog_output,
        tl_dgt_output_l: msg.tl_dgt_output_l,
        tl_dgt_input_l: msg.tl_dgt_input_l,
        emergency_stop: msg.emergency_stop,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      robot_index: msg.robot_index,
        robot_name: msg.robot_name.as_str().into(),
        robot_type: msg.robot_type.as_str().into(),
        robot_soft_index: msg.robot_soft_index.as_str().into(),
        robot_ip: msg.robot_ip.as_str().into(),
      curtask_index: msg.curtask_index,
      curstep_index: msg.curstep_index,
      program_state: msg.program_state,
      robot_motion_done: msg.robot_motion_done,
      robot_err_code: msg.robot_err_code,
      main_code: msg.main_code,
      sub_code: msg.sub_code,
      robot_mode: msg.robot_mode,
      robot_speed: msg.robot_speed,
        jt_cur_pos: msg.jt_cur_pos,
        tl_cur_pos: msg.tl_cur_pos,
      cl_dgt_output_h: msg.cl_dgt_output_h,
      cl_dgt_output_l: msg.cl_dgt_output_l,
      cl_dgt_input_h: msg.cl_dgt_input_h,
      cl_dgt_input_l: msg.cl_dgt_input_l,
        cl_analog_input: msg.cl_analog_input,
        cl_analog_output: msg.cl_analog_output,
      tl_dgt_output_l: msg.tl_dgt_output_l,
      tl_dgt_input_l: msg.tl_dgt_input_l,
      emergency_stop: msg.emergency_stop,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      robot_index: msg.robot_index,
      robot_name: msg.robot_name.to_string(),
      robot_type: msg.robot_type.to_string(),
      robot_soft_index: msg.robot_soft_index.to_string(),
      robot_ip: msg.robot_ip.to_string(),
      curtask_index: msg.curtask_index,
      curstep_index: msg.curstep_index,
      program_state: msg.program_state,
      robot_motion_done: msg.robot_motion_done,
      robot_err_code: msg.robot_err_code,
      main_code: msg.main_code,
      sub_code: msg.sub_code,
      robot_mode: msg.robot_mode,
      robot_speed: msg.robot_speed,
      jt_cur_pos: msg.jt_cur_pos,
      tl_cur_pos: msg.tl_cur_pos,
      cl_dgt_output_h: msg.cl_dgt_output_h,
      cl_dgt_output_l: msg.cl_dgt_output_l,
      cl_dgt_input_h: msg.cl_dgt_input_h,
      cl_dgt_input_l: msg.cl_dgt_input_l,
      cl_analog_input: msg.cl_analog_input,
      cl_analog_output: msg.cl_analog_output,
      tl_dgt_output_l: msg.tl_dgt_output_l,
      tl_dgt_input_l: msg.tl_dgt_input_l,
      emergency_stop: msg.emergency_stop,
    }
  }
}


// Corresponds to com_interfaces__msg__RealsenseState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RealsenseState {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

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
    pub color_topic: std::string::String,

    /// 深度图话题名
    pub depth_topic: std::string::String,

    /// 对齐深度图话题名
    pub aligned_depth_topic: std::string::String,

    /// 彩色相机内参话题名
    pub color_info_topic: std::string::String,

    /// 深度相机内参话题名
    pub depth_info_topic: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RealsenseState::default())
  }
}

impl rosidl_runtime_rs::Message for RealsenseState {
  type RmwMsg = super::msg::rmw::RealsenseState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
        node_online: msg.node_online,
        color_ready: msg.color_ready,
        depth_ready: msg.depth_ready,
        aligned_depth_ready: msg.aligned_depth_ready,
        color_info_ready: msg.color_info_ready,
        depth_info_ready: msg.depth_info_ready,
        color_topic: msg.color_topic.as_str().into(),
        depth_topic: msg.depth_topic.as_str().into(),
        aligned_depth_topic: msg.aligned_depth_topic.as_str().into(),
        color_info_topic: msg.color_info_topic.as_str().into(),
        depth_info_topic: msg.depth_info_topic.as_str().into(),
        last_color_ts_ms: msg.last_color_ts_ms,
        last_depth_ts_ms: msg.last_depth_ts_ms,
        last_aligned_depth_ts_ms: msg.last_aligned_depth_ts_ms,
        last_color_info_ts_ms: msg.last_color_info_ts_ms,
        last_depth_info_ts_ms: msg.last_depth_info_ts_ms,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      node_online: msg.node_online,
      color_ready: msg.color_ready,
      depth_ready: msg.depth_ready,
      aligned_depth_ready: msg.aligned_depth_ready,
      color_info_ready: msg.color_info_ready,
      depth_info_ready: msg.depth_info_ready,
        color_topic: msg.color_topic.as_str().into(),
        depth_topic: msg.depth_topic.as_str().into(),
        aligned_depth_topic: msg.aligned_depth_topic.as_str().into(),
        color_info_topic: msg.color_info_topic.as_str().into(),
        depth_info_topic: msg.depth_info_topic.as_str().into(),
      last_color_ts_ms: msg.last_color_ts_ms,
      last_depth_ts_ms: msg.last_depth_ts_ms,
      last_aligned_depth_ts_ms: msg.last_aligned_depth_ts_ms,
      last_color_info_ts_ms: msg.last_color_info_ts_ms,
      last_depth_info_ts_ms: msg.last_depth_info_ts_ms,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
      node_online: msg.node_online,
      color_ready: msg.color_ready,
      depth_ready: msg.depth_ready,
      aligned_depth_ready: msg.aligned_depth_ready,
      color_info_ready: msg.color_info_ready,
      depth_info_ready: msg.depth_info_ready,
      color_topic: msg.color_topic.to_string(),
      depth_topic: msg.depth_topic.to_string(),
      aligned_depth_topic: msg.aligned_depth_topic.to_string(),
      color_info_topic: msg.color_info_topic.to_string(),
      depth_info_topic: msg.depth_info_topic.to_string(),
      last_color_ts_ms: msg.last_color_ts_ms,
      last_depth_ts_ms: msg.last_depth_ts_ms,
      last_aligned_depth_ts_ms: msg.last_aligned_depth_ts_ms,
      last_color_info_ts_ms: msg.last_color_info_ts_ms,
      last_depth_info_ts_ms: msg.last_depth_info_ts_ms,
    }
  }
}


// Corresponds to com_interfaces__msg__RfidReaderState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RfidReaderState {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

}



impl Default for RfidReaderState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RfidReaderState::default())
  }
}

impl rosidl_runtime_rs::Message for RfidReaderState {
  type RmwMsg = super::msg::rmw::RfidReaderState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__RmCeuState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RmCeuState {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

}



impl Default for RmCeuState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RmCeuState::default())
  }
}

impl rosidl_runtime_rs::Message for RmCeuState {
  type RmwMsg = super::msg::rmw::RmCeuState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__SeerCtrlState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerCtrlState {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

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
    pub current_station: std::string::String,

    /// 小车上一个站点的id
    pub last_station: std::string::String,

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
    pub battery_user_data: std::string::String,

    /// 小车导航状态
    pub guide_state: super::msg::AgvGuideState,

    /// 小车控制权信息
    pub control: super::msg::AgvControl,

}



impl Default for SeerCtrlState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SeerCtrlState::default())
  }
}

impl rosidl_runtime_rs::Message for SeerCtrlState {
  type RmwMsg = super::msg::rmw::SeerCtrlState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
        pose_x: msg.pose_x,
        pose_y: msg.pose_y,
        angle: msg.angle,
        confidence: msg.confidence,
        current_station: msg.current_station.as_str().into(),
        last_station: msg.last_station.as_str().into(),
        vel_x: msg.vel_x,
        vel_y: msg.vel_y,
        vel_ang: msg.vel_ang,
        battery_level: msg.battery_level,
        battery_temp: msg.battery_temp,
        charging: msg.charging,
        voltage: msg.voltage,
        current: msg.current,
        max_charge_voltage: msg.max_charge_voltage,
        max_charge_current: msg.max_charge_current,
        manual_charge: msg.manual_charge,
        auto_charge: msg.auto_charge,
        battery_cycle: msg.battery_cycle,
        battery_user_data: msg.battery_user_data.as_str().into(),
        guide_state: super::msg::AgvGuideState::into_rmw_message(std::borrow::Cow::Owned(msg.guide_state)).into_owned(),
        control: super::msg::AgvControl::into_rmw_message(std::borrow::Cow::Owned(msg.control)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      pose_x: msg.pose_x,
      pose_y: msg.pose_y,
      angle: msg.angle,
      confidence: msg.confidence,
        current_station: msg.current_station.as_str().into(),
        last_station: msg.last_station.as_str().into(),
      vel_x: msg.vel_x,
      vel_y: msg.vel_y,
      vel_ang: msg.vel_ang,
      battery_level: msg.battery_level,
      battery_temp: msg.battery_temp,
      charging: msg.charging,
      voltage: msg.voltage,
      current: msg.current,
      max_charge_voltage: msg.max_charge_voltage,
      max_charge_current: msg.max_charge_current,
      manual_charge: msg.manual_charge,
      auto_charge: msg.auto_charge,
      battery_cycle: msg.battery_cycle,
        battery_user_data: msg.battery_user_data.as_str().into(),
        guide_state: super::msg::AgvGuideState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.guide_state)).into_owned(),
        control: super::msg::AgvControl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.control)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
      pose_x: msg.pose_x,
      pose_y: msg.pose_y,
      angle: msg.angle,
      confidence: msg.confidence,
      current_station: msg.current_station.to_string(),
      last_station: msg.last_station.to_string(),
      vel_x: msg.vel_x,
      vel_y: msg.vel_y,
      vel_ang: msg.vel_ang,
      battery_level: msg.battery_level,
      battery_temp: msg.battery_temp,
      charging: msg.charging,
      voltage: msg.voltage,
      current: msg.current,
      max_charge_voltage: msg.max_charge_voltage,
      max_charge_current: msg.max_charge_current,
      manual_charge: msg.manual_charge,
      auto_charge: msg.auto_charge,
      battery_cycle: msg.battery_cycle,
      battery_user_data: msg.battery_user_data.to_string(),
      guide_state: super::msg::AgvGuideState::from_rmw_message(msg.guide_state),
      control: super::msg::AgvControl::from_rmw_message(msg.control),
    }
  }
}


// Corresponds to com_interfaces__msg__SeerM4State

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerM4State {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

    /// agv运单状态
    pub order_state: super::msg::AgvOrderState,

}



impl Default for SeerM4State {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SeerM4State::default())
  }
}

impl rosidl_runtime_rs::Message for SeerM4State {
  type RmwMsg = super::msg::rmw::SeerM4State;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
        order_state: super::msg::AgvOrderState::into_rmw_message(std::borrow::Cow::Owned(msg.order_state)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
        order_state: super::msg::AgvOrderState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.order_state)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
      order_state: super::msg::AgvOrderState::from_rmw_message(msg.order_state),
    }
  }
}


// Corresponds to com_interfaces__msg__SiemensPlcState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SiemensPlcState {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

}



impl Default for SiemensPlcState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SiemensPlcState::default())
  }
}

impl rosidl_runtime_rs::Message for SiemensPlcState {
  type RmwMsg = super::msg::rmw::SiemensPlcState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__SmartMoreState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartMoreState {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

}



impl Default for SmartMoreState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SmartMoreState::default())
  }
}

impl rosidl_runtime_rs::Message for SmartMoreState {
  type RmwMsg = super::msg::rmw::SmartMoreState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__VirtAgvState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtAgvState {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

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
    pub current_station: std::string::String,

    /// 小车上一个站点的id
    pub last_station: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::VirtAgvState::default())
  }
}

impl rosidl_runtime_rs::Message for VirtAgvState {
  type RmwMsg = super::msg::rmw::VirtAgvState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
        pose_x: msg.pose_x,
        pose_y: msg.pose_y,
        angle: msg.angle,
        confidence: msg.confidence,
        current_station: msg.current_station.as_str().into(),
        last_station: msg.last_station.as_str().into(),
        vel_x: msg.vel_x,
        vel_y: msg.vel_y,
        vel_ang: msg.vel_ang,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      pose_x: msg.pose_x,
      pose_y: msg.pose_y,
      angle: msg.angle,
      confidence: msg.confidence,
        current_station: msg.current_station.as_str().into(),
        last_station: msg.last_station.as_str().into(),
      vel_x: msg.vel_x,
      vel_y: msg.vel_y,
      vel_ang: msg.vel_ang,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
      pose_x: msg.pose_x,
      pose_y: msg.pose_y,
      angle: msg.angle,
      confidence: msg.confidence,
      current_station: msg.current_station.to_string(),
      last_station: msg.last_station.to_string(),
      vel_x: msg.vel_x,
      vel_y: msg.vel_y,
      vel_ang: msg.vel_ang,
    }
  }
}


// Corresponds to com_interfaces__msg__VirtDevState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtDevState {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

}



impl Default for VirtDevState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::VirtDevState::default())
  }
}

impl rosidl_runtime_rs::Message for VirtDevState {
  type RmwMsg = super::msg::rmw::VirtDevState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__VisionEngineState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VisionEngineState {
    /// 名称
    pub name: std::string::String,

    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub err_msg: std::string::String,

}



impl Default for VisionEngineState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::VisionEngineState::default())
  }
}

impl rosidl_runtime_rs::Message for VisionEngineState {
  type RmwMsg = super::msg::rmw::VisionEngineState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      err_code: msg.err_code,
        err_msg: msg.err_msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      err_code: msg.err_code,
      err_msg: msg.err_msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__AgvControl
/// 当前仙工机器人配置控制权信息

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AgvControl {
    /// 当前控制权是否被抢占
    pub locked: bool,

    /// 控制权所有者 IP
    pub ip: std::string::String,

    /// 控制权所有者端口
    pub port: i32,

    /// 控制权所有者类型: 0x00 default, 0x02 roboshop, 0xDD srd
    pub type_: u8,

    /// 控制权所有者昵称
    pub nick_name: std::string::String,

    /// 抢占控制权的时间戳, Unix 秒
    pub time: i64,

    /// 控制权所有者描述
    pub desc: std::string::String,

}



impl Default for AgvControl {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AgvControl::default())
  }
}

impl rosidl_runtime_rs::Message for AgvControl {
  type RmwMsg = super::msg::rmw::AgvControl;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        locked: msg.locked,
        ip: msg.ip.as_str().into(),
        port: msg.port,
        type_: msg.type_,
        nick_name: msg.nick_name.as_str().into(),
        time: msg.time,
        desc: msg.desc.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      locked: msg.locked,
        ip: msg.ip.as_str().into(),
      port: msg.port,
      type_: msg.type_,
        nick_name: msg.nick_name.as_str().into(),
      time: msg.time,
        desc: msg.desc.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      locked: msg.locked,
      ip: msg.ip.to_string(),
      port: msg.port,
      type_: msg.type_,
      nick_name: msg.nick_name.to_string(),
      time: msg.time,
      desc: msg.desc.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__AgvGuideState
/// 导航状态, 0 = NONE, 1 = WAITING(目前不可能出现该状态), 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AgvGuideState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub task_status: i32,

    /// 导航类型, 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 7 = 平动转动, 100 = 其他
    pub task_type: i32,

    /// 导航目标站点
    pub target_station: std::string::String,

}



impl Default for AgvGuideState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AgvGuideState::default())
  }
}

impl rosidl_runtime_rs::Message for AgvGuideState {
  type RmwMsg = super::msg::rmw::AgvGuideState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_status: msg.task_status,
        task_type: msg.task_type,
        target_station: msg.target_station.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      task_status: msg.task_status,
      task_type: msg.task_type,
        target_station: msg.target_station.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_status: msg.task_status,
      task_type: msg.task_type,
      target_station: msg.target_station.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__AgvLoc
/// 机器人在世界坐标系中的位置

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub current_station: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub last_station: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub loc_method: i32,

}



impl Default for AgvLoc {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AgvLoc::default())
  }
}

impl rosidl_runtime_rs::Message for AgvLoc {
  type RmwMsg = super::msg::rmw::AgvLoc;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        angle: msg.angle,
        confidence: msg.confidence,
        current_station: msg.current_station.as_str().into(),
        last_station: msg.last_station.as_str().into(),
        loc_method: msg.loc_method,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      angle: msg.angle,
      confidence: msg.confidence,
        current_station: msg.current_station.as_str().into(),
        last_station: msg.last_station.as_str().into(),
      loc_method: msg.loc_method,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      angle: msg.angle,
      confidence: msg.confidence,
      current_station: msg.current_station.to_string(),
      last_station: msg.last_station.to_string(),
      loc_method: msg.loc_method,
    }
  }
}


// Corresponds to com_interfaces__msg__AgvOrderState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AgvOrderState {
    /// 单号
    pub id: std::string::String,

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
    pub status: std::string::String,

    /// 实际执行机器人
    pub actual_robot_name: std::string::String,

    /// 当前正在执行的运单步骤
    pub current_step_index: i32,

    /// 已完成执行的运单步骤
    pub done_step_index: i32,

    /// 运单由几个步骤构成
    pub step_num: i32,

    /// 运单点位列表
    pub step_locations: Vec<std::string::String>,

    /// 搬运的容器编号
    pub container_id: std::string::String,

    /// 是否已完成取货
    pub loaded: bool,

    /// 是否已完成放货
    pub unloaded: bool,

    /// 运单执行出现故障
    pub fault: bool,

    /// 故障原因
    pub fault_reason: std::string::String,

    /// 此运单无法被执行的原因
    pub execution_reject: std::string::String,

}



impl Default for AgvOrderState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AgvOrderState::default())
  }
}

impl rosidl_runtime_rs::Message for AgvOrderState {
  type RmwMsg = super::msg::rmw::AgvOrderState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id.as_str().into(),
        status: msg.status.as_str().into(),
        actual_robot_name: msg.actual_robot_name.as_str().into(),
        current_step_index: msg.current_step_index,
        done_step_index: msg.done_step_index,
        step_num: msg.step_num,
        step_locations: msg.step_locations
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        container_id: msg.container_id.as_str().into(),
        loaded: msg.loaded,
        unloaded: msg.unloaded,
        fault: msg.fault,
        fault_reason: msg.fault_reason.as_str().into(),
        execution_reject: msg.execution_reject.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id.as_str().into(),
        status: msg.status.as_str().into(),
        actual_robot_name: msg.actual_robot_name.as_str().into(),
      current_step_index: msg.current_step_index,
      done_step_index: msg.done_step_index,
      step_num: msg.step_num,
        step_locations: msg.step_locations
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        container_id: msg.container_id.as_str().into(),
      loaded: msg.loaded,
      unloaded: msg.unloaded,
      fault: msg.fault,
        fault_reason: msg.fault_reason.as_str().into(),
        execution_reject: msg.execution_reject.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id.to_string(),
      status: msg.status.to_string(),
      actual_robot_name: msg.actual_robot_name.to_string(),
      current_step_index: msg.current_step_index,
      done_step_index: msg.done_step_index,
      step_num: msg.step_num,
      step_locations: msg.step_locations
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      container_id: msg.container_id.to_string(),
      loaded: msg.loaded,
      unloaded: msg.unloaded,
      fault: msg.fault,
      fault_reason: msg.fault_reason.to_string(),
      execution_reject: msg.execution_reject.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__AgvStation

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AgvStation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub name: std::string::String,

}



impl Default for AgvStation {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AgvStation::default())
  }
}

impl rosidl_runtime_rs::Message for AgvStation {
  type RmwMsg = super::msg::rmw::AgvStation;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
    }
  }
}


// Corresponds to com_interfaces__msg__ForcePayload

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ForcePayload::default())
  }
}

impl rosidl_runtime_rs::Message for ForcePayload {
  type RmwMsg = super::msg::rmw::ForcePayload;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        weight: msg.weight,
        x: msg.x,
        y: msg.y,
        z: msg.z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      weight: msg.weight,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      weight: msg.weight,
      x: msg.x,
      y: msg.y,
      z: msg.z,
    }
  }
}


// Corresponds to com_interfaces__msg__ForceTorque

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ForceTorque::default())
  }
}

impl rosidl_runtime_rs::Message for ForceTorque {
  type RmwMsg = super::msg::rmw::ForceTorque;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        fx: msg.fx,
        fy: msg.fy,
        fz: msg.fz,
        tx: msg.tx,
        ty: msg.ty,
        tz: msg.tz,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      fx: msg.fx,
      fy: msg.fy,
      fz: msg.fz,
      tx: msg.tx,
      ty: msg.ty,
      tz: msg.tz,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      fx: msg.fx,
      fy: msg.fy,
      fz: msg.fz,
      tx: msg.tx,
      ty: msg.ty,
      tz: msg.tz,
    }
  }
}


// Corresponds to com_interfaces__msg__JointPoint

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct JointPoint {

    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_point: [f64; 6],

}



impl Default for JointPoint {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::JointPoint::default())
  }
}

impl rosidl_runtime_rs::Message for JointPoint {
  type RmwMsg = super::msg::rmw::JointPoint;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        joint_point: msg.joint_point,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        joint_point: msg.joint_point,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      joint_point: msg.joint_point,
    }
  }
}


// Corresponds to com_interfaces__msg__SphereLoc
/// 球体坐标, m

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SphereLoc::default())
  }
}

impl rosidl_runtime_rs::Message for SphereLoc {
  type RmwMsg = super::msg::rmw::SphereLoc;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        z: msg.z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      z: msg.z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      z: msg.z,
    }
  }
}


// Corresponds to com_interfaces__msg__YoloResult

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::YoloResult::default())
  }
}

impl rosidl_runtime_rs::Message for YoloResult {
  type RmwMsg = super::msg::rmw::YoloResult;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        class_id: msg.class_id,
        confidence: msg.confidence,
        x: msg.x,
        y: msg.y,
        width: msg.width,
        height: msg.height,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      class_id: msg.class_id,
      confidence: msg.confidence,
      x: msg.x,
      y: msg.y,
      width: msg.width,
      height: msg.height,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      class_id: msg.class_id,
      confidence: msg.confidence,
      x: msg.x,
      y: msg.y,
      width: msg.width,
      height: msg.height,
    }
  }
}


