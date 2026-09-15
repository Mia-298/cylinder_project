
int32 err_code # 错误码
string msg #错误信息
FrRobotState pub_state # 机器人的状态数据
float64 register_val    #机器人寄存器值-只读 与register_index同时用
bool io_val #机器人IO口值，与input_or_output和io_index同时使用
float64[6] jt_pos # 关节位置
float64[6] tl_pos # 笛卡尔位置
ForceTorque ft # 力与力矩
ForcePayload force_payload # 力传感器负载重量和质心
bool motion_done # 运动是否完成
