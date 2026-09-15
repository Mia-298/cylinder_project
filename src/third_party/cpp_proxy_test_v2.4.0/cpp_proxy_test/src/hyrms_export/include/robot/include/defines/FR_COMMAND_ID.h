#ifndef FR_COMMAND_ID_H_
#define FR_COMMAND_ID_H_

// 启动指令
#define FR_CONNECT 0
#define FR_DISCONNECT 1
#define FR_ENABLE 2
#define FR_SETMODE 3
// 运动指令
#define FR_MOVEAXIS 20
#define FR_MOVEJ 21
#define FR_MOVEL 22
#define FR_SETVEC 23
#define FR_SETACC 24
#define FR_MOVEPATH 25
#define FR_CSV_MOVEPATH 26
// 写值
#define FR_SETR 40
#define FR_SETIO 41
// 获取值
#define FR_GETSTATE 50
#define FR_GETR 51
#define FR_GETIO 52
#define FR_GETJOINT 53
#define FR_GETDESC 54
#define FR_RECORD_PATH 55
#define FR_GETMOTION_DONE 56
#define FR_GETFORCEPAYLOAD 57

// 加载程序
#define FR_PROGRAM_LOAD 61

// 夹爪
#define FR_ACT_GRIPPER 70
#define FR_MOVE_GRIPPER 71

// 非阻塞运动
#define FR_START_MOVEL 80
#define FR_START_MOVEJ 81
#define FR_STOP_MOTION 82
#define FR_PAUSE_MOTION 83
#define FR_RESUME_MOTION 84

// 清除错误
#define ERRCLEAR 100

// 力传感器
#define FR_FT_ACTIVATE 110
#define FR_FT_SETZERO 111
#define FR_FT_GET_FORCE_TORQUE_RCS 112
#define FR_FT_GET_FORCE_TORQUE_ORIGIN 113

// 伺服运动
#define FR_SERVO_MOVE_START 120
#define FR_SERVO_MOVE_END 121
#define FR_SERVO_DESC_MOVE 122

#endif