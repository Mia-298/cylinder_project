# HyRMS C++ SDK 使用手册

本文档说明 HyRMS C++ Proxy SDK 的安装、`agent/cpp_proxy_test` 的使用方式，以及当前版本以下设备的 C++ 接口：

- 遨博机械臂：`RobotProxy::AuboRobot`
- RFID 读写器：`SensorProxy::RfidReader`
- 夹爪：`GripperProxy::RmCeu`

当前 SDK 是 ROS 2 Proxy SDK。Proxy 不直接在调用进程中连接遨博 SDK、串口或 Modbus 设备，而是通过 ROS 2 service 调用 HyRMS 中已经上线的设备 linker，并通过 ROS 2 topic 接收设备状态。

## 一、SDK 文件

SDK 包由两个压缩包组成：

```text
HyRMS_cpp_sdk_v2.4.0-vis.1_202609091643.tar.gz
HyRMS_com_export_v2.4.0-vis.1_202609091644.tar.gz
```

解压后，C++ 工程需要以下内容：

```text
hyrms_export/
├── include/                         # C++ Proxy 头文件和错误码定义
├── lib/libhyrms_export.so           # C++ Proxy 动态库
└── share/hyrms_export/              # ROS 2 包环境文件

com_interfaces/
├── msg/                             # 设备状态消息
├── srv/                             # 设备命令 service
└── CMakeLists.txt
```

三个设备对应的头文件：

```cpp
#include "dev/robot/robot.hpp"
#include "dev/sensor/sensor.hpp"
#include "dev/gripper/gripper.hpp"
```

## 二、设备 ID 与 ROS 资源

设备 ID 必须使用 HyRMS 中已经注册的完整十位设备 ID。Proxy 构造函数接收的是 ROS 2 节点名，通常在设备 ID 后增加 `_proxy`。

| 设备 | C++ 类 | 设备 ID 示例 | 命令 service | 状态 topic |
| --- | --- | --- | --- | --- |
| 遨博机械臂 | `RobotProxy::AuboRobot` | `robAub0001` | `robAub0001_cmd` | `robAub0001_state` |
| RFID 读写器 | `SensorProxy::RfidReader` | `snsRrd0001` | `snsRrd0001_cmd` | `snsRrd0001_state` |
| 夹爪 | `GripperProxy::RmCeu` | `griRmc0001` | `griRmc0001_cmd` | `griRmc0001_state` |

构造 Proxy：

```cpp
auto robot = std::make_shared<RobotProxy::AuboRobot>("robAub0001_proxy");
auto rfid = std::make_shared<SensorProxy::RfidReader>("snsRrd0001_proxy");
auto gripper = std::make_shared<GripperProxy::RmCeu>("griRmc0001_proxy");
```

`_proxy` 前面的部分必须与目标设备 ID 一致。Proxy 会根据节点名生成对应的命令 service 和状态 topic 名称。

## 三、使用前提

调用 C++ Proxy 前，目标 HyRMS 必须满足：

1. 对应设备已经在 HyRMS 配置中注册。
2. 对应的 `<device_id>_cmd` service 已经创建。
3. 对应的 `<device_id>_state` topic 已经发布。
4. 设备 linker 所需的 IP、串口路径或其他地址已经配置。

C++ Proxy 的构造函数只接收 ROS 2 节点名，不接收设备 IP 或串口路径。设备地址由目标 HyRMS 的 linker 配置提供：

- 遨博机械臂地址由遨博 linker 配置提供。
- RFID 串口地址由 RFID linker 的 `linker_addr` 配置提供。
- 夹爪串口地址由夹爪 linker 的 `linker_addr` 配置提供。

设备上线前提不满足时，Proxy 只能创建本地 ROS 2 节点，设备调用会返回 service 不可用或请求超时。

## 四、返回值和错误处理

设备操作接口统一返回 `int32_t`：

```cpp
int32_t ret = device->connect();
if (ret != 0)
{
    std::cerr << "调用失败: " << ret << ", " << device->msg << std::endl;
}
```

返回值定义：

| 返回值 | 含义 |
| ---: | --- |
| `0` | 调用成功 |
| `-1001` | Proxy 等待 service 响应超时 |
| `-1002` | Proxy 请求参数错误 |
| `-1009` | Proxy 发送请求时发生其他错误 |
| 其他值 | 设备 linker 返回的设备错误码 |

设备类的 `msg` 保存最近一次 service 调用的消息。调用失败时应同时记录返回值和 `msg`。

对带输出参数或输出成员的查询接口，只有返回值为 `0` 时才使用输出数据。

## 五、ROS 2 executor 要求

Proxy 构造时会创建 ROS 2 client 和 state subscription。调用 service 前必须把 Proxy 节点加入 executor，并保持 executor 在其他线程中运行。

最小结构：

```cpp
#include <iostream>
#include <memory>
#include <thread>

#include <rclcpp/rclcpp.hpp>

#include "dev/robot/robot.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto robot = std::make_shared<RobotProxy::AuboRobot>("robAub0001_proxy");

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(robot);

    std::thread spin_thread([&executor]()
                             { executor.spin(); });

    int32_t ret = robot->connect();
    if (ret != 0)
    {
        std::cerr << "connect failed: " << ret << ", " << robot->msg << std::endl;
    }

    rclcpp::shutdown();
    spin_thread.join();
    return ret;
}
```

多个设备可以加入同一个 executor：

```cpp
executor.add_node(robot);
executor.add_node(rfid);
executor.add_node(gripper);
```

## 六、agent/cpp_proxy_test 使用手册

### 1. 工程结构

```text
agent/cpp_proxy_test/
├── Makefile
├── src/
│   ├── cpp_proxy_test/
│   │   ├── CMakeLists.txt
│   │   ├── package.xml
│   │   └── src/cpp_proxy_test.cpp
│   ├── com_interfaces/
│   └── hyrms_export/
└── install/
```

当前 `cpp_proxy_test.cpp` 是虚拟设备的最小调用示例，使用：

```cpp
#include "dev/virt/virt.hpp"
```

它不会自动测试遨博、RFID 或夹爪。测试这三个设备时，需要在测试程序中包含对应头文件并实例化对应 Proxy。

### 2. 放置 SDK 包

将以下两个包放在 `agent/cpp_proxy_test/src/` 目录：

```text
HyRMS_cpp_sdk_*.tar.gz
HyRMS_com_export_*.tar.gz
```

在测试工程目录执行：

```bash
cd /home/hyrms/ros2_ws/HyRMS/agent/cpp_proxy_test
make install_sdk
```

该目标会使用 `src/` 中版本号最高的 SDK 包，并重新生成：

```text
src/hyrms_export/
src/com_interfaces/
```

### 3. CMake 链接关系

当前测试工程使用以下 SDK 头文件和库路径：

```cmake
set(INCLUDE_PATHS
    /path/to/cpp_proxy_test/src/hyrms_export/include
    /path/to/cpp_proxy_test/src/cpp_proxy_test/include
    /path/to/cpp_proxy_test/src/cpp_proxy_test/src
)

set(THIRD_PARTY_LIBS
    /path/to/cpp_proxy_test/src/hyrms_export/lib/libhyrms_export.so
)
```

ROS 2 依赖至少包括：

```cmake
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(com_interfaces REQUIRED)
```

目标需要链接：

```cmake
target_link_libraries(cpp_proxy_test
    /path/to/cpp_proxy_test/src/hyrms_export/lib/libhyrms_export.so
)

ament_target_dependencies(cpp_proxy_test
    rclcpp
    com_interfaces
)
```

实际工程中使用当前 CMake 文件的相对路径即可，不需要把 `/path/to/cpp_proxy_test` 原样写入工程。

### 4. 构建和运行入口

Makefile 中的入口：

```bash
cd /home/hyrms/ros2_ws/HyRMS/agent/cpp_proxy_test

# 构建并运行测试程序
make run
```

Makefile 默认使用：

```text
ROS 2：/opt/ros/humble/setup.sh
包名：cpp_proxy_test
程序名：cpp_proxy_test
```

### 5. 测试程序替换为设备 Proxy

将虚拟设备示例中的头文件和对象替换为目标设备。例如遨博：

```cpp
#include <iostream>
#include <thread>

#include <rclcpp/rclcpp.hpp>

#include "dev/robot/robot.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto robot = std::make_shared<RobotProxy::AuboRobot>("robAub0001_proxy");

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(robot);
    std::thread spin_thread([&executor]()
                             { executor.spin(); });

    const int32_t ret = robot->connect();
    std::cout << "connect ret=" << ret
              << " msg=" << robot->msg << std::endl;

    robot->disconnect();
    rclcpp::shutdown();
    spin_thread.join();
    return ret;
}
```

RFID 和夹爪只需要替换类名、头文件和设备 ID：

```cpp
#include "dev/sensor/sensor.hpp"
#include "dev/gripper/gripper.hpp"

auto rfid = std::make_shared<SensorProxy::RfidReader>("snsRrd0001_proxy");
auto gripper = std::make_shared<GripperProxy::RmCeu>("griRmc0001_proxy");
```

## 七、遨博机械臂 C++ Proxy

### 1. 头文件和类

```cpp
#include "dev/robot/robot.hpp"

auto robot = std::make_shared<RobotProxy::AuboRobot>("robAub0001_proxy");
```

类名：`RobotProxy::AuboRobot`

设备 ID：`robAub0001`

### 2. 连接与使能

```cpp
int32_t ret = robot->connect();
if (ret != 0)
{
    std::cerr << robot->msg << std::endl;
}

ret = robot->enable(true);   // 上使能
ret = robot->enable(false);  // 下使能

ret = robot->disconnect();
```

| 方法 | 参数 | 返回值 |
| --- | --- | --- |
| `connect()` | 无 | `0` 表示连接成功 |
| `disconnect()` | 无 | `0` 表示断开成功 |
| `enable(bool enable)` | `true` 上使能，`false` 下使能 | 设备错误码 |
| `isConnect()` | 无 | 设备错误码，成功时更新 `is_conn` |

`isConnect()` 的使用方式：

```cpp
int32_t ret = robot->isConnect();
if (ret == 0)
{
    std::cout << "connected=" << std::boolalpha
              << robot->is_conn << std::endl;
}
```

### 3. 速度和加速度

```cpp
int32_t ret = robot->setSpeed(5.0);
if (ret != 0)
{
    std::cerr << robot->msg << std::endl;
}

ret = robot->setAcc(10.0);
```

| 方法 | 参数 | 定义 |
| --- | --- | --- |
| `setSpeed(double speed)` | `speed` | 速度百分比，`0` 到 `100` |
| `setAcc(double acc)` | `acc` | 加速度百分比，`0` 到 `100` |

这两个接口使用项目百分比定义，不传入 `m/s`、`mm/s`、`rad/s` 或 `deg/s` 等物理量。

### 4. 运行模式

```cpp
int32_t ret = robot->setMode(0);  // 手动模式
ret = robot->setMode(1);          // 自动模式
```

| 值 | 含义 |
| ---: | --- |
| `0` | 手动模式 |
| `1` | 自动模式 |

### 5. 单关节点动

```cpp
int32_t ret = robot->moveAxis(1, 1, 5.0);
```

| 参数 | 定义 |
| --- | --- |
| `axid` | 轴编号，`1` 到 `6` |
| `dir` | `0` 负方向，`1` 正方向 |
| `deg` | 单次点动角度或距离；角度单位为度，距离单位为毫米 |

### 6. 关节和笛卡尔运动

`joint_desc` 使用以下定义：

| `joint_desc` | 目标点类型 |
| ---: | --- |
| `false` | 关节坐标 |
| `true` | 笛卡尔坐标 |

关节目标点的六个元素单位为度：

```cpp
double joint_pose[6] = {
    0.0, -15.0, 100.0, 25.0, 90.0, 0.0};

int32_t ret = robot->moveJ(joint_pose, false);
```

笛卡尔目标点的数组顺序为 `{x, y, z, rx, ry, rz}`，`x/y/z` 单位为毫米，`rx/ry/rz` 单位为度：

```cpp
double desc_pose[6] = {
    -155.944, -727.344, 439.066, 174.8, 1.8, 103.4};

int32_t ret = robot->moveJ(desc_pose, true);
ret = robot->moveL(desc_pose, true);
```

接口定义：

| 方法 | 说明 |
| --- | --- |
| `moveJ(double pos_point[6], bool joint_desc)` | 阻塞点到点运动 |
| `moveL(double pos_point[6], bool joint_desc)` | 阻塞直线运动 |
| `startMoveJ(double pos_point[6], bool joint_desc)` | 非阻塞点到点运动 |
| `startMoveL(double pos_point[6], bool joint_desc)` | 非阻塞直线运动 |

非阻塞调用只表示命令请求返回，不表示机械臂已经到达目标点：

```cpp
int32_t ret = robot->startMoveJ(joint_pose, false);
```

停止、暂停和恢复：

```cpp
robot->stopMotion();
robot->pauseMotion();
robot->resumeMotion();
```

### 7. 读写寄存器和 IO

寄存器：

```cpp
int32_t ret = robot->setR(1, 12.5);

ret = robot->getR(1);
if (ret == 0)
{
    std::cout << "register[1]=" << robot->reg_value << std::endl;
}
```

IO 参数定义：

| 参数值 | 含义 |
| ---: | --- |
| `false` / `0` | DI 输入 |
| `true` / `1` | DO 输出 |

```cpp
// 设置 DO0 为高电平
int32_t ret = robot->setIO(true, 0, true);

// 读取 DO0
ret = robot->getIO(true, 0);
if (ret == 0)
{
    std::cout << "io=" << std::boolalpha << robot->io_value << std::endl;
}
```

### 8. 获取当前位姿

关节位姿通过 `joint_pose[6]` 返回，单位为度：

```cpp
int32_t ret = robot->getJointPose();
if (ret == 0)
{
    for (int i = 0; i < 6; ++i)
    {
        std::cout << "joint[" << i << "]=" << robot->joint_pose[i] << std::endl;
    }
}
```

笛卡尔位姿通过 `desc_pose[6]` 返回，数组顺序为 `{x, y, z, rx, ry, rz}`：

```cpp
int32_t ret = robot->getDescPose();
if (ret == 0)
{
    std::cout << "x=" << robot->desc_pose[0]
              << " y=" << robot->desc_pose[1]
              << " z=" << robot->desc_pose[2]
              << " rx=" << robot->desc_pose[3]
              << " ry=" << robot->desc_pose[4]
              << " rz=" << robot->desc_pose[5]
              << std::endl;
}
```

### 9. 程序接口

```cpp
int32_t ret = robot->programLoad("program_name");
```

参数为机械臂程序名称或路径，具体格式由目标 linker 和机械臂控制器支持的程序接口决定。

### 10. 力传感器接口

激活或复位：

```cpp
robot->ftActivate(1);  // 激活
robot->ftActivate(0);  // 复位

robot->ftSetZero(1);   // 设置当前值为零点
robot->ftSetZero(0);   // 清除零点
```

获取参考坐标系力和原始力：

```cpp
int32_t ret = robot->getForceTorqueRCS();
if (ret == 0)
{
    std::cout << robot->ft.fx << " "
              << robot->ft.fy << " "
              << robot->ft.fz << " "
              << robot->ft.tx << " "
              << robot->ft.ty << " "
              << robot->ft.tz << std::endl;
}

ret = robot->getForceTorqueOrigin();
```

`ft` 的字段：

| 字段 | 含义 |
| --- | --- |
| `fx/fy/fz` | 三轴力，单位 N |
| `tx/ty/tz` | 三轴力矩，单位 Nm |

当前版本的 Aubo linker 对力传感器命令按 linker 实现返回结果，调用后必须检查返回值再读取 `ft`。

### 11. 遨博 Proxy 公共状态成员

| 成员 | 类型 | 更新接口 | 含义 |
| --- | --- | --- | --- |
| `msg` | `std::string` | 每次 service 调用 | 最近一次调用消息 |
| `state_pkg` | `DEVM::AuboRobotState` | service 返回和 state topic | 遨博状态消息 |
| `ft` | `DEVM::ForceTorque` | 力查询接口 | 力和力矩 |
| `reg_value` | `double` | `getR()` | 寄存器值 |
| `is_conn` | `bool` | `isConnect()` | 连接状态 |
| `io_value` | `bool` | `getIO()` | IO 值 |
| `joint_pose[6]` | `double` | `getJointPose()` | 当前关节位姿 |
| `desc_pose[6]` | `double` | `getDescPose()` | 当前笛卡尔位姿 |

## 八、RFID 读写器 C++ Proxy

### 1. 头文件和类

```cpp
#include "dev/sensor/sensor.hpp"

auto rfid = std::make_shared<SensorProxy::RfidReader>("snsRrd0001_proxy");
```

类名：`SensorProxy::RfidReader`

设备 ID：`snsRrd0001`

### 2. 连接和断开

```cpp
int32_t ret = rfid->connect();
if (ret != 0)
{
    std::cerr << rfid->msg << std::endl;
}

ret = rfid->disconnect();
```

`connect()` 对应 RFID linker 打开串口，`disconnect()` 对应关闭串口。重复断开时，底层按成功处理。

### 3. 读取标签 ID

```cpp
std::string id;
int32_t ret = rfid->ReadID(id);
if (ret == 0)
{
    std::cout << "tag id=" << id << std::endl;
}
else
{
    std::cerr << "ReadID failed: " << ret
              << ", " << rfid->msg << std::endl;
}
```

| 项目 | 定义 |
| --- | --- |
| 输入参数 | `std::string &id`，输出参数 |
| 返回值 | `0` 成功，非 `0` 失败 |
| 超时 | 当前 linker 默认等待 3000 ms |
| 成功结果 | 写入 `id` |
| 失败结果 | 不使用 `id` |

`ReadID()` 会执行一次主动读取并等待标签，完成后停止主动读取。

### 4. 读取 EPC

```cpp
std::string epc;
int32_t ret = rfid->ReadEPC(epc);
if (ret == 0)
{
    std::cout << "epc=" << epc << std::endl;
}
```

`ReadEPC()` 从当前串口数据中读取一条完整 EPC。没有完整数据时返回错误，不应使用输出字符串。

### 5. 功率和主动读取

```cpp
int32_t ret = rfid->ChangePower(20);
ret = rfid->StartRead();
ret = rfid->StopRead();
```

| 方法 | 参数 | 定义 |
| --- | --- | --- |
| `ChangePower(int power)` | `power` | 功率范围 `20` 到 `30` |
| `StartRead()` | 无 | 启动主动读取 |
| `StopRead()` | 无 | 停止主动读取 |

### 6. RFID 完整调用示例

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include <rclcpp/rclcpp.hpp>

#include "dev/sensor/sensor.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto rfid = std::make_shared<SensorProxy::RfidReader>("snsRrd0001_proxy");
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(rfid);
    std::thread spin_thread([&executor]()
                             { executor.spin(); });

    int32_t ret = rfid->connect();
    if (ret == 0)
    {
        ret = rfid->ChangePower(20);
    }

    std::string id;
    if (ret == 0)
    {
        ret = rfid->ReadID(id);
    }

    if (ret != 0)
    {
        std::cerr << "rfid failed: " << ret
                  << ", " << rfid->msg << std::endl;
    }
    else
    {
        std::cout << "id=" << id << std::endl;
    }

    rfid->disconnect();
    rclcpp::shutdown();
    spin_thread.join();
    return ret;
}
```

### 7. RFID 错误码头文件

需要判断 RFID 专用错误码时可包含：

```cpp
#include "sensor/include/defines/ERROR_CODE.h"
```

主要错误码：

| 宏 | 含义 |
| --- | --- |
| `ERR_DEV_SENSOR_SUCCESS` | 操作成功 |
| `ERR_DEV_SENSOR_PORT_NOT_OPEN` | 串口未打开 |
| `ERR_DEV_SENSOR_POWER_INVALID` | 功率不在 `20..30` |
| `ERR_DEV_SENSOR_NO_DATA` | 当前没有完整标签数据 |
| `ERR_DEV_SENSOR_READ_TIMEOUT` | 读取标签超时 |
| `ERR_DEV_SENSOR_RESPONSE_TIMEOUT` | 等待读写器响应超时 |

## 九、夹爪 C++ Proxy

### 1. 头文件和类

```cpp
#include "dev/gripper/gripper.hpp"

auto gripper = std::make_shared<GripperProxy::RmCeu>("griRmc0001_proxy");
```

类名：`GripperProxy::RmCeu`

设备 ID：`griRmc0001`

### 2. 连接和断开

```cpp
int32_t ret = gripper->connect();
if (ret != 0)
{
    std::cerr << gripper->msg << std::endl;
}

ret = gripper->disconnect();
```

`connect()` 对应夹爪 linker 初始化 Modbus RTU，`disconnect()` 对应释放 Modbus 连接。

### 3. 执行夹爪点位

```cpp
int32_t ret = gripper->goPoint(0);
if (ret != 0)
{
    std::cerr << "goPoint failed: " << ret
              << ", " << gripper->msg << std::endl;
}
```

| 参数 | 定义 |
| --- | --- |
| `point` | 夹爪预设点位编号，范围 `0` 到 `15` |
| 返回值 | `0` 成功，非 `0` 失败 |
| 执行方式 | 阻塞等待点位到达 |
| 执行超时 | 当前底层等待时间为 300 秒 |

### 4. 夹爪完整调用示例

```cpp
#include <iostream>
#include <memory>
#include <thread>

#include <rclcpp/rclcpp.hpp>

#include "dev/gripper/gripper.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto gripper = std::make_shared<GripperProxy::RmCeu>("griRmc0001_proxy");
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(gripper);
    std::thread spin_thread([&executor]()
                             { executor.spin(); });

    int32_t ret = gripper->connect();
    if (ret == 0)
    {
        ret = gripper->goPoint(0);
    }

    if (ret != 0)
    {
        std::cerr << "gripper failed: " << ret
                  << ", " << gripper->msg << std::endl;
    }

    gripper->disconnect();
    rclcpp::shutdown();
    spin_thread.join();
    return ret;
}
```

### 5. 夹爪错误码头文件

需要判断夹爪专用错误码时可包含：

```cpp
#include "gripper/include/defines/ERROR_CODE.h"
```

主要错误码：

| 宏 | 含义 |
| --- | --- |
| `ERR_DEV_GRIPPER_SUCCESS` | 操作成功 |
| `GRIPPER_NO_CONN_ERROR` | 设备未连接 |
| `GRIPPER_ARGS_ERROR` | 参数错误 |
| `GRIPPER_WRITE_ERROR` | 写入数据失败 |
| `GRIPPER_READ_ERROR` | 读取数据失败 |
| `GRIPPER_EXEC_TIMEOUT_ERROR` | 执行超时 |
| `GRIPPER_ERROR_ALARM` | 错误报警 |
| `GRIPPER_POSITION_ALARM` | 位置超差报警 |
| `GRIPPER_SPEED_ALARM` | 速度超差报警 |
| `GRIPPER_MOTOR_STALL` | 电机堵转报警 |

## 十、三个设备同时使用

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include <rclcpp/rclcpp.hpp>

#include "dev/gripper/gripper.hpp"
#include "dev/robot/robot.hpp"
#include "dev/sensor/sensor.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto robot = std::make_shared<RobotProxy::AuboRobot>("robAub0001_proxy");
    auto rfid = std::make_shared<SensorProxy::RfidReader>("snsRrd0001_proxy");
    auto gripper = std::make_shared<GripperProxy::RmCeu>("griRmc0001_proxy");

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(robot);
    executor.add_node(rfid);
    executor.add_node(gripper);
    std::thread spin_thread([&executor]()
                             { executor.spin(); });

    int32_t ret = robot->connect();
    if (ret == 0)
    {
        ret = rfid->connect();
    }
    if (ret == 0)
    {
        ret = gripper->connect();
    }

    if (ret != 0)
    {
        std::cerr << "device connect failed: " << ret << std::endl;
    }

    gripper->disconnect();
    rfid->disconnect();
    robot->disconnect();

    rclcpp::shutdown();
    spin_thread.join();
    return ret;
}
```

## 十一、当前版本注意事项

1. C++ Proxy 调用的是 ROS 2 service，不是直接调用设备厂商 SDK。目标 HyRMS 必须在线并已加载设备 linker。
2. `agent/cpp_proxy_test` 当前源文件默认测试 `VirtDev`，不会自动创建上述三个 Proxy。
3. Aubo 的位置数组在当前 Proxy 链路中使用关节度数、笛卡尔毫米和度；不要把 Lua/Python 侧的数组格式与厂商原始 SDK 的米、弧度格式混用。
4. RFID 的串口地址和夹爪的串口地址不在 C++ Proxy 构造函数中传入，由目标 linker 配置提供。
5. 所有设备方法都要检查返回值；失败时不要继续使用本次查询的输出数据。
6. `goPoint()`、Aubo 阻塞运动和 RFID `ReadID()` 都可能等待设备动作或响应，调用线程应允许其阻塞，并保证 executor 线程持续运行。
