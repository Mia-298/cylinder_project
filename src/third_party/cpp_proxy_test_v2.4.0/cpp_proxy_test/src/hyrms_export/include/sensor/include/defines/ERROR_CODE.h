#ifndef SENSOR_ERROR_CODE_H_
#define SENSOR_ERROR_CODE_H_

// RFID 读写器错误码，0 表示成功，负数表示设备或通信错误。

#define ERR_DEV_SENSOR_OTHERS -1500                    // 未分类错误
#define ERR_DEV_SENSOR_CONNECT_FAILED -1501            // 连接失败
#define ERR_DEV_SENSOR_NO_SUCH_MSG -1502               // 不支持的指令
#define ERR_DEV_SENSOR_SUCCESS 0                       // 操作成功
#define ERR_DEV_SENSOR_PORT_OPEN_FAILED -1503         // 打开串口失败
#define ERR_DEV_SENSOR_PORT_GET_ATTR_FAILED -1504     // 读取串口配置失败
#define ERR_DEV_SENSOR_PORT_SET_ATTR_FAILED -1505     // 设置串口配置失败
#define ERR_DEV_SENSOR_PORT_CLOSE_FAILED -1506        // 关闭串口失败
#define ERR_DEV_SENSOR_PORT_NOT_OPEN -1507             // 串口未打开
#define ERR_DEV_SENSOR_START_READ_FAILED -1508         // 启动读取失败
#define ERR_DEV_SENSOR_STOP_READ_FAILED -1509          // 停止读取失败
#define ERR_DEV_SENSOR_POWER_INVALID -1510             // 功率参数无效
#define ERR_DEV_SENSOR_POWER_WRITE_FAILED -1511        // 功率指令发送失败
#define ERR_DEV_SENSOR_RESPONSE_TIMEOUT -1512         // 等待读写器响应超时
#define ERR_DEV_SENSOR_DEVICE_ERROR -1513             // 读写器返回错误
#define ERR_DEV_SENSOR_RESPONSE_INVALID -1514         // 读写器响应异常
#define ERR_DEV_SENSOR_READ_FAILED -1515              // 读取串口失败
#define ERR_DEV_SENSOR_NO_DATA -1516                  // 暂无完整数据
#define ERR_DEV_SENSOR_FRAME_INVALID -1517            // 数据帧格式错误
#define ERR_DEV_SENSOR_READ_TIMEOUT -1518             // 读取标签超时

#endif
