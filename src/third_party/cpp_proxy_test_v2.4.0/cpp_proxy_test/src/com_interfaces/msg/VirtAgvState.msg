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