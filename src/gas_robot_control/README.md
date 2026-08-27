# gas_robot_control

`gas_robot_control` 封装 AUBO 机器人 RPC 控制能力，并通过 ROS2 service 暴露给手眼标定、标定验证和抓取执行节点。

## 默认配置

主配置：

```text
src/gas_robot_control/config/aubo_control.yaml
```

手眼采集配置：

```text
src/gas_robot_control/config/aubo_control_collect.yaml
```

关键参数：

| 参数 | 默认值 |
| --- | --- |
| `robot_ip` | `192.168.192.2` |
| `robot_port` | `30004` |
| `service_namespace` | `/robot` |
| `request_timeout_ms` | `8000` |
| `velocity_rad_s` | `0.3490658504` |
| `acceleration_rad_s2` | `0.5235987756` |
| `motion_timeout_sec` | `120.0` |

`aubo_control_collect.yaml` 默认 `auto_handguide=true`，适合手眼采集时拖动机器人；`aubo_control.yaml` 不默认开启拖动，适合抓取执行。

## 启动

单独启动：

```bash
ros2 launch gas_robot_control aubo_control.launch.py
```

通常由这些入口自动启动：

```bash
ros2 launch gas_bringup handeye_collection.launch.py
ros2 launch gas_bringup grasp_pipeline.launch.py
```

## 服务

| 服务 | 类型 | 说明 |
| --- | --- | --- |
| `/robot/connect` | `RobotConnect` | 连接控制器 |
| `/robot/enable` | `RobotSetEnable` | 机器人上使能或下使能 |
| `/robot/get_pose` | `RobotGetPose` | 获取关节角和 TCP |
| `/robot/move_j` | `RobotMoveJ` | 关节空间运动 |
| `/robot/move_l` | `RobotMoveL` | TCP 直线运动 |
| `/robot/stop` | `RobotStop` | 停止当前运动 |
| `/robot/handguide` | `RobotSetHandguide` | 开关拖动示教 |
| `/robot/set_motion_params` | `RobotSetMotionParams` | 设置速度、加速度、融合半径和持续时间 |

## 常用检查

```bash
ros2 service list | grep /robot
ros2 service call /robot/get_pose gas_interfaces/srv/RobotGetPose "{}"
```

## 安全注意

- 确认机器人急停可用。
- 确认控制器处于远程控制模式。
- 确认 PC 和机器人在同一网段。
- 抓取前确认目标点在安全工作空间内。
- `grasp_pipeline.launch.py` 默认会自动连接并使能机器人。
