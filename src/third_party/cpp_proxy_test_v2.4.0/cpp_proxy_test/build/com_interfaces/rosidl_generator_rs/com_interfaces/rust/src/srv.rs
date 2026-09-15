#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to com_interfaces__srv__AuboCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub program: std::string::String,

    /// 记录的间隔，多少毫秒记一次
    pub interval: i32,

    /// csv文件名
    pub filename: std::string::String,

    /// 关节位置
    pub joint_path: Vec<super::msg::JointPoint>,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AuboCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for AuboCmdInterface_Request {
  type RmwMsg = super::srv::rmw::AuboCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        en: msg.en,
        joint_or_desc: msg.joint_or_desc,
        position: msg.position,
        axid: msg.axid,
        dir: msg.dir,
        deg: msg.deg,
        speed: msg.speed,
        acc: msg.acc,
        tool: msg.tool,
        mode: msg.mode,
        register_index: msg.register_index,
        register_value: msg.register_value,
        input_or_output: msg.input_or_output,
        io_index: msg.io_index,
        io_value: msg.io_value,
        program: msg.program.as_str().into(),
        interval: msg.interval,
        filename: msg.filename.as_str().into(),
        joint_path: msg.joint_path
          .into_iter()
          .map(|elem| super::msg::JointPoint::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        gripper_index: msg.gripper_index,
        act: msg.act,
        gripper_pos: msg.gripper_pos,
        gripper_vel: msg.gripper_vel,
        gripper_force: msg.gripper_force,
        max_time: msg.max_time,
        gripper_block: msg.gripper_block,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      en: msg.en,
      joint_or_desc: msg.joint_or_desc,
        position: msg.position,
      axid: msg.axid,
      dir: msg.dir,
      deg: msg.deg,
      speed: msg.speed,
      acc: msg.acc,
      tool: msg.tool,
      mode: msg.mode,
      register_index: msg.register_index,
      register_value: msg.register_value,
      input_or_output: msg.input_or_output,
      io_index: msg.io_index,
      io_value: msg.io_value,
        program: msg.program.as_str().into(),
      interval: msg.interval,
        filename: msg.filename.as_str().into(),
        joint_path: msg.joint_path
          .iter()
          .map(|elem| super::msg::JointPoint::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      gripper_index: msg.gripper_index,
      act: msg.act,
      gripper_pos: msg.gripper_pos,
      gripper_vel: msg.gripper_vel,
      gripper_force: msg.gripper_force,
      max_time: msg.max_time,
      gripper_block: msg.gripper_block,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      en: msg.en,
      joint_or_desc: msg.joint_or_desc,
      position: msg.position,
      axid: msg.axid,
      dir: msg.dir,
      deg: msg.deg,
      speed: msg.speed,
      acc: msg.acc,
      tool: msg.tool,
      mode: msg.mode,
      register_index: msg.register_index,
      register_value: msg.register_value,
      input_or_output: msg.input_or_output,
      io_index: msg.io_index,
      io_value: msg.io_value,
      program: msg.program.to_string(),
      interval: msg.interval,
      filename: msg.filename.to_string(),
      joint_path: msg.joint_path
          .into_iter()
          .map(super::msg::JointPoint::from_rmw_message)
          .collect(),
      gripper_index: msg.gripper_index,
      act: msg.act,
      gripper_pos: msg.gripper_pos,
      gripper_vel: msg.gripper_vel,
      gripper_force: msg.gripper_force,
      max_time: msg.max_time,
      gripper_block: msg.gripper_block,
    }
  }
}


// Corresponds to com_interfaces__srv__AuboCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AuboCmdInterface_Response {
    /// 错误码
    pub err_code: i32,

    /// 错误信息
    pub msg: std::string::String,

    /// 机器人的状态数据
    pub pub_state: super::msg::AuboRobotState,

    /// 机器人寄存器值-只读 与register_index同时用
    pub register_val: f64,

    /// 机器人IO口值，与input_or_output和io_index同时使用
    pub io_val: bool,

    /// 关节位置
    pub jt_pos: [f64; 6],

    /// 笛卡尔位置
    pub tl_pos: [f64; 6],

    /// 力与力矩
    pub ft: super::msg::ForceTorque,

}



impl Default for AuboCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AuboCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for AuboCmdInterface_Response {
  type RmwMsg = super::srv::rmw::AuboCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        pub_state: super::msg::AuboRobotState::into_rmw_message(std::borrow::Cow::Owned(msg.pub_state)).into_owned(),
        register_val: msg.register_val,
        io_val: msg.io_val,
        jt_pos: msg.jt_pos,
        tl_pos: msg.tl_pos,
        ft: super::msg::ForceTorque::into_rmw_message(std::borrow::Cow::Owned(msg.ft)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        pub_state: super::msg::AuboRobotState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pub_state)).into_owned(),
      register_val: msg.register_val,
      io_val: msg.io_val,
        jt_pos: msg.jt_pos,
        tl_pos: msg.tl_pos,
        ft: super::msg::ForceTorque::into_rmw_message(std::borrow::Cow::Borrowed(&msg.ft)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
      pub_state: super::msg::AuboRobotState::from_rmw_message(msg.pub_state),
      register_val: msg.register_val,
      io_val: msg.io_val,
      jt_pos: msg.jt_pos,
      tl_pos: msg.tl_pos,
      ft: super::msg::ForceTorque::from_rmw_message(msg.ft),
    }
  }
}


// Corresponds to com_interfaces__srv__FrCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub program: std::string::String,

    /// 记录的间隔，多少毫秒记一次
    pub interval: i32,

    /// csv文件名
    pub filename: std::string::String,

    /// 关节位置
    pub joint_path: Vec<super::msg::JointPoint>,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::FrCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for FrCmdInterface_Request {
  type RmwMsg = super::srv::rmw::FrCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        en: msg.en,
        joint_or_desc: msg.joint_or_desc,
        position: msg.position,
        axid: msg.axid,
        dir: msg.dir,
        deg: msg.deg,
        speed: msg.speed,
        acc: msg.acc,
        tool: msg.tool,
        mode: msg.mode,
        register_index: msg.register_index,
        register_value: msg.register_value,
        input_or_output: msg.input_or_output,
        io_index: msg.io_index,
        io_value: msg.io_value,
        program: msg.program.as_str().into(),
        interval: msg.interval,
        filename: msg.filename.as_str().into(),
        joint_path: msg.joint_path
          .into_iter()
          .map(|elem| super::msg::JointPoint::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        gripper_index: msg.gripper_index,
        act: msg.act,
        gripper_pos: msg.gripper_pos,
        gripper_vel: msg.gripper_vel,
        gripper_force: msg.gripper_force,
        max_time: msg.max_time,
        gripper_block: msg.gripper_block,
        cmd_t: msg.cmd_t,
        pos_gain: msg.pos_gain,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      en: msg.en,
      joint_or_desc: msg.joint_or_desc,
        position: msg.position,
      axid: msg.axid,
      dir: msg.dir,
      deg: msg.deg,
      speed: msg.speed,
      acc: msg.acc,
      tool: msg.tool,
      mode: msg.mode,
      register_index: msg.register_index,
      register_value: msg.register_value,
      input_or_output: msg.input_or_output,
      io_index: msg.io_index,
      io_value: msg.io_value,
        program: msg.program.as_str().into(),
      interval: msg.interval,
        filename: msg.filename.as_str().into(),
        joint_path: msg.joint_path
          .iter()
          .map(|elem| super::msg::JointPoint::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      gripper_index: msg.gripper_index,
      act: msg.act,
      gripper_pos: msg.gripper_pos,
      gripper_vel: msg.gripper_vel,
      gripper_force: msg.gripper_force,
      max_time: msg.max_time,
      gripper_block: msg.gripper_block,
      cmd_t: msg.cmd_t,
        pos_gain: msg.pos_gain,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      en: msg.en,
      joint_or_desc: msg.joint_or_desc,
      position: msg.position,
      axid: msg.axid,
      dir: msg.dir,
      deg: msg.deg,
      speed: msg.speed,
      acc: msg.acc,
      tool: msg.tool,
      mode: msg.mode,
      register_index: msg.register_index,
      register_value: msg.register_value,
      input_or_output: msg.input_or_output,
      io_index: msg.io_index,
      io_value: msg.io_value,
      program: msg.program.to_string(),
      interval: msg.interval,
      filename: msg.filename.to_string(),
      joint_path: msg.joint_path
          .into_iter()
          .map(super::msg::JointPoint::from_rmw_message)
          .collect(),
      gripper_index: msg.gripper_index,
      act: msg.act,
      gripper_pos: msg.gripper_pos,
      gripper_vel: msg.gripper_vel,
      gripper_force: msg.gripper_force,
      max_time: msg.max_time,
      gripper_block: msg.gripper_block,
      cmd_t: msg.cmd_t,
      pos_gain: msg.pos_gain,
    }
  }
}


// Corresponds to com_interfaces__srv__FrCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrCmdInterface_Response {
    /// 错误码
    pub err_code: i32,

    /// 错误信息
    pub msg: std::string::String,

    /// 机器人的状态数据
    pub pub_state: super::msg::FrRobotState,

    /// 机器人寄存器值-只读 与register_index同时用
    pub register_val: f64,

    /// 机器人IO口值，与input_or_output和io_index同时使用
    pub io_val: bool,

    /// 关节位置
    pub jt_pos: [f64; 6],

    /// 笛卡尔位置
    pub tl_pos: [f64; 6],

    /// 力与力矩
    pub ft: super::msg::ForceTorque,

    /// 力传感器负载重量和质心
    pub force_payload: super::msg::ForcePayload,

    /// 运动是否完成
    pub motion_done: bool,

}



impl Default for FrCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::FrCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for FrCmdInterface_Response {
  type RmwMsg = super::srv::rmw::FrCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        pub_state: super::msg::FrRobotState::into_rmw_message(std::borrow::Cow::Owned(msg.pub_state)).into_owned(),
        register_val: msg.register_val,
        io_val: msg.io_val,
        jt_pos: msg.jt_pos,
        tl_pos: msg.tl_pos,
        ft: super::msg::ForceTorque::into_rmw_message(std::borrow::Cow::Owned(msg.ft)).into_owned(),
        force_payload: super::msg::ForcePayload::into_rmw_message(std::borrow::Cow::Owned(msg.force_payload)).into_owned(),
        motion_done: msg.motion_done,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        pub_state: super::msg::FrRobotState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pub_state)).into_owned(),
      register_val: msg.register_val,
      io_val: msg.io_val,
        jt_pos: msg.jt_pos,
        tl_pos: msg.tl_pos,
        ft: super::msg::ForceTorque::into_rmw_message(std::borrow::Cow::Borrowed(&msg.ft)).into_owned(),
        force_payload: super::msg::ForcePayload::into_rmw_message(std::borrow::Cow::Borrowed(&msg.force_payload)).into_owned(),
      motion_done: msg.motion_done,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
      pub_state: super::msg::FrRobotState::from_rmw_message(msg.pub_state),
      register_val: msg.register_val,
      io_val: msg.io_val,
      jt_pos: msg.jt_pos,
      tl_pos: msg.tl_pos,
      ft: super::msg::ForceTorque::from_rmw_message(msg.ft),
      force_payload: super::msg::ForcePayload::from_rmw_message(msg.force_payload),
      motion_done: msg.motion_done,
    }
  }
}


// Corresponds to com_interfaces__srv__RealsenseCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RealsenseCmdInterface_Request {
    /// 指令ID
    pub id: i32,

}



impl Default for RealsenseCmdInterface_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RealsenseCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for RealsenseCmdInterface_Request {
  type RmwMsg = super::srv::rmw::RealsenseCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
    }
  }
}


// Corresponds to com_interfaces__srv__RealsenseCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RealsenseCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: std::string::String,

}



impl Default for RealsenseCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RealsenseCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for RealsenseCmdInterface_Response {
  type RmwMsg = super::srv::rmw::RealsenseCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__srv__RfidReaderCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RfidReaderCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 读写器功率
    pub power: i32,

}



impl Default for RfidReaderCmdInterface_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RfidReaderCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for RfidReaderCmdInterface_Request {
  type RmwMsg = super::srv::rmw::RfidReaderCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        power: msg.power,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      power: msg.power,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      power: msg.power,
    }
  }
}


// Corresponds to com_interfaces__srv__RfidReaderCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RfidReaderCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: std::string::String,

    /// 读取到的标签数据
    pub data: std::string::String,

}



impl Default for RfidReaderCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RfidReaderCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for RfidReaderCmdInterface_Response {
  type RmwMsg = super::srv::rmw::RfidReaderCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        data: msg.data.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        data: msg.data.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
      data: msg.data.to_string(),
    }
  }
}


// Corresponds to com_interfaces__srv__RmCeuCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RmCeuCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 点位编号
    pub point: i32,

}



impl Default for RmCeuCmdInterface_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RmCeuCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for RmCeuCmdInterface_Request {
  type RmwMsg = super::srv::rmw::RmCeuCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        point: msg.point,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      point: msg.point,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      point: msg.point,
    }
  }
}


// Corresponds to com_interfaces__srv__RmCeuCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RmCeuCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: std::string::String,

}



impl Default for RmCeuCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RmCeuCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for RmCeuCmdInterface_Response {
  type RmwMsg = super::srv::rmw::RmCeuCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__srv__SeerCtrlCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerCtrlCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 站点
    pub station: std::string::String,

    /// 站点列表
    pub station_list: Vec<std::string::String>,

    /// 手动控制 x方向线速度 vx (机器人坐标系，单位 m/s)
    pub manual_x: f32,

    /// 手动控制 y方向线速度 vy (机器人坐标系，单位 m/s)
    pub manual_y: f32,

    /// 手动控制 角速度 w (单位 rad/s，逆时针为正，顺时针为负)
    pub manual_w: f32,

    /// 手动控制持续时间  (单位 ms, 0 持续执行直到下条指令 | >0 持续指定时间后停止 | <0 视作忽略该参数)
    pub manual_duration: i32,

    /// 抢占配置控制权时的控制权所有者昵称
    pub nick_name: std::string::String,

}



impl Default for SeerCtrlCmdInterface_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SeerCtrlCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SeerCtrlCmdInterface_Request {
  type RmwMsg = super::srv::rmw::SeerCtrlCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        station: msg.station.as_str().into(),
        station_list: msg.station_list
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        manual_x: msg.manual_x,
        manual_y: msg.manual_y,
        manual_w: msg.manual_w,
        manual_duration: msg.manual_duration,
        nick_name: msg.nick_name.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        station: msg.station.as_str().into(),
        station_list: msg.station_list
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      manual_x: msg.manual_x,
      manual_y: msg.manual_y,
      manual_w: msg.manual_w,
      manual_duration: msg.manual_duration,
        nick_name: msg.nick_name.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      station: msg.station.to_string(),
      station_list: msg.station_list
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      manual_x: msg.manual_x,
      manual_y: msg.manual_y,
      manual_w: msg.manual_w,
      manual_duration: msg.manual_duration,
      nick_name: msg.nick_name.to_string(),
    }
  }
}


// Corresponds to com_interfaces__srv__SeerCtrlCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerCtrlCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: std::string::String,

    /// 导航状态
    pub guide_state: super::msg::AgvGuideState,

    /// 当前控制权信息
    pub control: super::msg::AgvControl,

    /// 机器人在世界坐标系中的位置
    pub loc: super::msg::AgvLoc,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_station: super::msg::AgvStation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub station_list: Vec<super::msg::AgvStation>,

}



impl Default for SeerCtrlCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SeerCtrlCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SeerCtrlCmdInterface_Response {
  type RmwMsg = super::srv::rmw::SeerCtrlCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        guide_state: super::msg::AgvGuideState::into_rmw_message(std::borrow::Cow::Owned(msg.guide_state)).into_owned(),
        control: super::msg::AgvControl::into_rmw_message(std::borrow::Cow::Owned(msg.control)).into_owned(),
        loc: super::msg::AgvLoc::into_rmw_message(std::borrow::Cow::Owned(msg.loc)).into_owned(),
        current_station: super::msg::AgvStation::into_rmw_message(std::borrow::Cow::Owned(msg.current_station)).into_owned(),
        station_list: msg.station_list
          .into_iter()
          .map(|elem| super::msg::AgvStation::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        guide_state: super::msg::AgvGuideState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.guide_state)).into_owned(),
        control: super::msg::AgvControl::into_rmw_message(std::borrow::Cow::Borrowed(&msg.control)).into_owned(),
        loc: super::msg::AgvLoc::into_rmw_message(std::borrow::Cow::Borrowed(&msg.loc)).into_owned(),
        current_station: super::msg::AgvStation::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_station)).into_owned(),
        station_list: msg.station_list
          .iter()
          .map(|elem| super::msg::AgvStation::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
      guide_state: super::msg::AgvGuideState::from_rmw_message(msg.guide_state),
      control: super::msg::AgvControl::from_rmw_message(msg.control),
      loc: super::msg::AgvLoc::from_rmw_message(msg.loc),
      current_station: super::msg::AgvStation::from_rmw_message(msg.current_station),
      station_list: msg.station_list
          .into_iter()
          .map(super::msg::AgvStation::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to com_interfaces__srv__SeerM4CmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerM4CmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 点位
    pub point: std::string::String,

    /// 货箱ID
    pub container_id: std::string::String,

    /// 运单号
    pub order_id: std::string::String,

}



impl Default for SeerM4CmdInterface_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SeerM4CmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SeerM4CmdInterface_Request {
  type RmwMsg = super::srv::rmw::SeerM4CmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        point: msg.point.as_str().into(),
        container_id: msg.container_id.as_str().into(),
        order_id: msg.order_id.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        point: msg.point.as_str().into(),
        container_id: msg.container_id.as_str().into(),
        order_id: msg.order_id.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      point: msg.point.to_string(),
      container_id: msg.container_id.to_string(),
      order_id: msg.order_id.to_string(),
    }
  }
}


// Corresponds to com_interfaces__srv__SeerM4CmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeerM4CmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: std::string::String,

    /// 运单号
    pub order_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub order_state: super::msg::AgvOrderState,

}



impl Default for SeerM4CmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SeerM4CmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SeerM4CmdInterface_Response {
  type RmwMsg = super::srv::rmw::SeerM4CmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        order_id: msg.order_id.as_str().into(),
        order_state: super::msg::AgvOrderState::into_rmw_message(std::borrow::Cow::Owned(msg.order_state)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        order_id: msg.order_id.as_str().into(),
        order_state: super::msg::AgvOrderState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.order_state)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
      order_id: msg.order_id.to_string(),
      order_state: super::msg::AgvOrderState::from_rmw_message(msg.order_state),
    }
  }
}


// Corresponds to com_interfaces__srv__SiemensPlcCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SiemensPlcCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SiemensPlcCmdInterface_Request {
  type RmwMsg = super::srv::rmw::SiemensPlcCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        pin: msg.pin,
        dpin_state: msg.dpin_state,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      pin: msg.pin,
      dpin_state: msg.dpin_state,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      pin: msg.pin,
      dpin_state: msg.dpin_state,
    }
  }
}


// Corresponds to com_interfaces__srv__SiemensPlcCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SiemensPlcCmdInterface_Response {
    /// 数字引脚状态
    pub dpin_state: u8,

    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: std::string::String,

}



impl Default for SiemensPlcCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SiemensPlcCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SiemensPlcCmdInterface_Response {
  type RmwMsg = super::srv::rmw::SiemensPlcCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        dpin_state: msg.dpin_state,
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      dpin_state: msg.dpin_state,
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      dpin_state: msg.dpin_state,
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__srv__SmartMoreCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartMoreCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 请求消息
    pub req: std::string::String,

}



impl Default for SmartMoreCmdInterface_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SmartMoreCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SmartMoreCmdInterface_Request {
  type RmwMsg = super::srv::rmw::SmartMoreCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        req: msg.req.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        req: msg.req.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      req: msg.req.to_string(),
    }
  }
}


// Corresponds to com_interfaces__srv__SmartMoreCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartMoreCmdInterface_Response {
    /// 错误码
    pub err_code: i32,

    /// 错误提示信息
    pub msg: std::string::String,

    /// 设备响应消息
    pub res: std::string::String,

}



impl Default for SmartMoreCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SmartMoreCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SmartMoreCmdInterface_Response {
  type RmwMsg = super::srv::rmw::SmartMoreCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        res: msg.res.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        res: msg.res.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
      res: msg.res.to_string(),
    }
  }
}


// Corresponds to com_interfaces__srv__VirtAgvCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtAgvCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 站点
    pub station: std::string::String,

    /// 站点列表
    pub station_list: Vec<std::string::String>,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::VirtAgvCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for VirtAgvCmdInterface_Request {
  type RmwMsg = super::srv::rmw::VirtAgvCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        station: msg.station.as_str().into(),
        station_list: msg.station_list
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        manual_x: msg.manual_x,
        manual_y: msg.manual_y,
        manual_w: msg.manual_w,
        manual_duration: msg.manual_duration,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        station: msg.station.as_str().into(),
        station_list: msg.station_list
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      manual_x: msg.manual_x,
      manual_y: msg.manual_y,
      manual_w: msg.manual_w,
      manual_duration: msg.manual_duration,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      station: msg.station.to_string(),
      station_list: msg.station_list
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      manual_x: msg.manual_x,
      manual_y: msg.manual_y,
      manual_w: msg.manual_w,
      manual_duration: msg.manual_duration,
    }
  }
}


// Corresponds to com_interfaces__srv__VirtAgvCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtAgvCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: std::string::String,

    /// 导航状态 0 = NONE, 1 = WAITING(目前不可能出现该状态), 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED
    pub task_status: i32,

    /// 导航类型 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 7 = 平动转动, 100 = 其他
    pub task_type: i32,

    /// 导航目标站点
    pub target_station: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_station: super::msg::AgvStation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub station_list: Vec<super::msg::AgvStation>,

}



impl Default for VirtAgvCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::VirtAgvCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for VirtAgvCmdInterface_Response {
  type RmwMsg = super::srv::rmw::VirtAgvCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        task_status: msg.task_status,
        task_type: msg.task_type,
        target_station: msg.target_station.as_str().into(),
        current_station: super::msg::AgvStation::into_rmw_message(std::borrow::Cow::Owned(msg.current_station)).into_owned(),
        station_list: msg.station_list
          .into_iter()
          .map(|elem| super::msg::AgvStation::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
      task_status: msg.task_status,
      task_type: msg.task_type,
        target_station: msg.target_station.as_str().into(),
        current_station: super::msg::AgvStation::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_station)).into_owned(),
        station_list: msg.station_list
          .iter()
          .map(|elem| super::msg::AgvStation::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
      task_status: msg.task_status,
      task_type: msg.task_type,
      target_station: msg.target_station.to_string(),
      current_station: super::msg::AgvStation::from_rmw_message(msg.current_station),
      station_list: msg.station_list
          .into_iter()
          .map(super::msg::AgvStation::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to com_interfaces__srv__VirtDevCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtDevCmdInterface_Request {
    /// 指令ID
    pub id: i32,

}



impl Default for VirtDevCmdInterface_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::VirtDevCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for VirtDevCmdInterface_Request {
  type RmwMsg = super::srv::rmw::VirtDevCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
    }
  }
}


// Corresponds to com_interfaces__srv__VirtDevCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VirtDevCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: std::string::String,

}



impl Default for VirtDevCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::VirtDevCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for VirtDevCmdInterface_Response {
  type RmwMsg = super::srv::rmw::VirtDevCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
    }
  }
}


// Corresponds to com_interfaces__srv__VisionEngineCmdInterface_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VisionEngineCmdInterface_Request {
    /// 指令ID
    pub id: i32,

    /// 机械臂末端姿态, 笛卡尔坐标:0-2对应tran坐标的xyz,3-5对应rpy位姿的rx,ry,rz
    pub desc: [f64; 6],

    /// YOLO模型初始化
    /// ONNX模型路径
    pub model_path: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::VisionEngineCmdInterface_Request::default())
  }
}

impl rosidl_runtime_rs::Message for VisionEngineCmdInterface_Request {
  type RmwMsg = super::srv::rmw::VisionEngineCmdInterface_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        desc: msg.desc,
        model_path: msg.model_path.as_str().into(),
        input_height: msg.input_height,
        input_width: msg.input_width,
        confidence_threshold: msg.confidence_threshold,
        nms_threshold: msg.nms_threshold,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        desc: msg.desc,
        model_path: msg.model_path.as_str().into(),
      input_height: msg.input_height,
      input_width: msg.input_width,
      confidence_threshold: msg.confidence_threshold,
      nms_threshold: msg.nms_threshold,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      desc: msg.desc,
      model_path: msg.model_path.to_string(),
      input_height: msg.input_height,
      input_width: msg.input_width,
      confidence_threshold: msg.confidence_threshold,
      nms_threshold: msg.nms_threshold,
    }
  }
}


// Corresponds to com_interfaces__srv__VisionEngineCmdInterface_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VisionEngineCmdInterface_Response {
    /// 错误码
    pub err_code: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub msg: std::string::String,

    /// YOLO检测结果
    pub results: Vec<super::msg::YoloResult>,

    /// 球体在相机坐标系中的位置,单位m
    pub sphere_loc: super::msg::SphereLoc,

}



impl Default for VisionEngineCmdInterface_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::VisionEngineCmdInterface_Response::default())
  }
}

impl rosidl_runtime_rs::Message for VisionEngineCmdInterface_Response {
  type RmwMsg = super::srv::rmw::VisionEngineCmdInterface_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        results: msg.results
          .into_iter()
          .map(|elem| super::msg::YoloResult::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        sphere_loc: super::msg::SphereLoc::into_rmw_message(std::borrow::Cow::Owned(msg.sphere_loc)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      err_code: msg.err_code,
        msg: msg.msg.as_str().into(),
        results: msg.results
          .iter()
          .map(|elem| super::msg::YoloResult::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        sphere_loc: super::msg::SphereLoc::into_rmw_message(std::borrow::Cow::Borrowed(&msg.sphere_loc)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      err_code: msg.err_code,
      msg: msg.msg.to_string(),
      results: msg.results
          .into_iter()
          .map(super::msg::YoloResult::from_rmw_message)
          .collect(),
      sphere_loc: super::msg::SphereLoc::from_rmw_message(msg.sphere_loc),
    }
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


