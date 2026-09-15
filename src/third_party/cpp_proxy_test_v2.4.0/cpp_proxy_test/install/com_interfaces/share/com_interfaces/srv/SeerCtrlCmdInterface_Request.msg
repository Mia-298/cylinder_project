int32 id # 指令ID

string station          # 站点
string[] station_list   # 站点列表

float32 manual_x         # 手动控制 x方向线速度 vx (机器人坐标系，单位 m/s)
float32 manual_y         # 手动控制 y方向线速度 vy (机器人坐标系，单位 m/s)
float32 manual_w         # 手动控制 角速度 w (单位 rad/s，逆时针为正，顺时针为负)
int32 manual_duration      # 手动控制持续时间  (单位 ms, 0 持续执行直到下条指令 | >0 持续指定时间后停止 | <0 视作忽略该参数)
string nick_name            # 抢占配置控制权时的控制权所有者昵称

