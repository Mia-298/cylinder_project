string id # 单号
# 单据状态 
# 运单的状态有 8 个枚举值：
# - ToBeAllocated
# - Allocated
# - Pending
# - Executing
# - Done
# - Cancelling
# - Cancelled
# - Withdrawing
string status
# 实际执行机器人
string actual_robot_name
# 当前正在执行的运单步骤
int32 current_step_index
# 已完成执行的运单步骤
int32 done_step_index
# 运单由几个步骤构成
int32 step_num
# 运单点位列表
string[] step_locations
# 搬运的容器编号
string container_id
# 是否已完成取货
bool loaded
# 是否已完成放货
bool unloaded
# 运单执行出现故障
bool fault
# 故障原因
string fault_reason
# 此运单无法被执行的原因
string execution_reject
