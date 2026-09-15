string name # 名称
int32 err_code # 错误码
string err_msg # 错误提示信息

bool node_online # RealSense ROS2 节点是否在线
bool color_ready # 彩色图话题是否正常
bool depth_ready # 深度图话题是否正常
bool aligned_depth_ready # 对齐深度图话题是否正常
bool color_info_ready # 彩色相机内参话题是否正常
bool depth_info_ready # 深度相机内参话题是否正常

string color_topic # 彩色图话题名
string depth_topic # 深度图话题名
string aligned_depth_topic # 对齐深度图话题名
string color_info_topic # 彩色相机内参话题名
string depth_info_topic # 深度相机内参话题名

uint64 last_color_ts_ms # 最近一次收到彩色图消息的本地时间戳(ms)
uint64 last_depth_ts_ms # 最近一次收到深度图消息的本地时间戳(ms)
uint64 last_aligned_depth_ts_ms # 最近一次收到对齐深度图消息的本地时间戳(ms)
uint64 last_color_info_ts_ms # 最近一次收到彩色相机内参消息的本地时间戳(ms)
uint64 last_depth_info_ts_ms # 最近一次收到深度相机内参消息的本地时间戳(ms)
