
int32 robot_index # 多机械臂需通过编号来区别
string robot_name # 表示机械臂的作用或任务
string robot_type # 机械臂型号
string robot_soft_index # 机械臂软件版本
string robot_ip # 机器人的IP号

# 机械臂控制器状态说明：
# NoController    (-1)：  示教器专用状态，aubo_control 进程崩溃或未运行。
# Disconnected    (0)：   控制器与机械臂本体通信断开（接口板、EtherCAT 等总线断开）。
# ConfirmSafety   (1)：   正在进行安全配置，仅允许在断电状态下执行。
# Booting         (2)：   机械臂本体正在上电初始化。
# PowerOff        (3)：   机械臂本体已断电。
# PowerOn         (4)：   机械臂上电完成，刹车未松开，尚未获取关节初始状态。
# Idle            (5)：   机械臂上电完成，刹车未松开，电机未使能，已获取关节初始状态。
# BrakeReleasing  (6)：   机械臂正在释放刹车。
# BackDrive       (7)：   反向拖动模式，刹车已松开，电机不通电。
# Running         (8)：   运行模式，刹车已松开，控制权已移交软件。
# Maintaince      (9)：   维护模式，用于固件升级、参数写入等维护操作。
# Error           (10)：  机械臂处于错误状态。
# PowerOffing     (11)：  机械臂正在执行断电流程。
int32 mode_type
# 机械臂安全状态说明：
# Undefined           (0)：  安全状态待定。
# Normal              (1)：  正常运行模式。
# ReducedMode         (2)：  缩减运行模式。
# Recovery            (3)：  Recovery 模式。启动时若机械臂位于安全限制范围之外，则进入该模式进行恢复。
# Violation           (4)：  安全限制违规状态，如速度超限等超出安全配置限制。
# ProtectiveStop      (5)：  保护停机。由软件触发，保持当前轨迹，不抱闸，不断电。
# SafeguardStop       (6)：  防护停机。由安全 IO 触发，不保持轨迹，抱闸，不断电。
# SystemEmergencyStop (7)：  系统急停。由外部可配置急停输入触发，不向外输出急停信号。
# RobotEmergencyStop  (8)：  机器人急停。由控制柜急停输入或示教器急停按键触发，并向外输出急停信号。
# Fault               (9)：  故障状态。机械臂硬件故障或系统故障。
int32 safety_mode_type

float64 robot_speed # 机器人速度 返回百分比
float64[6] jt_cur_pos # 关节位置
float64[6] tl_cur_pos # 笛卡尔位置

