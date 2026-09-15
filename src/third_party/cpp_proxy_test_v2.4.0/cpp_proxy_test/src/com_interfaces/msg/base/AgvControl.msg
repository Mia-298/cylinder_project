# 当前仙工机器人配置控制权信息
bool locked # 当前控制权是否被抢占
string ip # 控制权所有者 IP
int32 port # 控制权所有者端口
uint8 type # 控制权所有者类型: 0x00 default, 0x02 roboshop, 0xDD srd
string nick_name # 控制权所有者昵称
int64 time # 抢占控制权的时间戳, Unix 秒
string desc # 控制权所有者描述
