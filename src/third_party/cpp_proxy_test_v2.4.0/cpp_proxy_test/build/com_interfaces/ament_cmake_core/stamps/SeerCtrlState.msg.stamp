string name # 名称
int32 err_code # 错误码
string err_msg # 错误提示信息

# 小车位置
float64 pose_x             # 小车的x坐标
float64 pose_y             # 小车的y坐标
float64 angle              # 小车的angle坐标
float64 confidence         # 小车的定位可信度
string current_station     # 离小车最近站点的id
string last_station        # 小车上一个站点的id

# 小车的速度
float64 vel_x              # 小车在x方向上的速度,单位:m/s
float64 vel_y              # 小车在y方向上的速度,单位:m/s
float64 vel_ang            # 小车的角速度,顺时针为正,单位:rad/s

# 小车电池状态
float64 battery_level      # 电池电量,范围:[0,1]
float64 battery_temp       # 电池温度,单位:℃
bool charging              # 电池是否正在充电
float64 voltage            # 电池电压,单位:V
float64 current            # 电池电流,单位:A
float64 max_charge_voltage # 允许充电的最大电压,-1表示不支持,单位:V
float64 max_charge_current # 允许充电的最大电流,-1表示不支持,单位:A
bool manual_charge         # 是否连接手动充电器
bool auto_charge           # 是否连接自动充电桩
int32 battery_cycle        # 电池循环次数
string battery_user_data   # 电池用户自定义数据

# 小车导航状态
AgvGuideState guide_state

# 小车控制权信息
AgvControl control