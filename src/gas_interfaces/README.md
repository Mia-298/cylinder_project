# gas_interfaces

`gas_interfaces` 定义本项目各模块之间的 ROS2 service 接口。视觉、标定、机器人和抓取节点都依赖这里的 `.srv`。

## 接口总览

| service 类型 | 主要服务名 | 说明 |
| --- | --- | --- |
| `DetectObjects` | `/yolo/detect_once` | 触发一次 YOLO 检测并返回点云拟合球心 |
| `GraspExecute` | `/grasp/execute_once` | 执行一次预抓取定位和 MoveL |
| `HandEyeAddSample` | `/handeye/add_sample` | 增加一组手眼标定样本 |
| `HandEyeClearSamples` | `/handeye/clear_samples` | 清空当前手眼样本 |
| `HandEyeCompute` | `/handeye/compute` | 计算手眼矩阵 |
| `HandEyeGetStatus` | `/handeye/status` | 查询手眼标定状态 |
| `RobotConnect` | `/robot/connect` | 连接 AUBO 控制器 |
| `RobotSetEnable` | `/robot/enable` | 设置机器人使能 |
| `RobotGetPose` | `/robot/get_pose` | 获取关节和 TCP 位姿 |
| `RobotMoveJ` | `/robot/move_j` | 关节运动 |
| `RobotMoveL` | `/robot/move_l` | 直线运动 |
| `RobotStop` | `/robot/stop` | 停止运动 |
| `RobotSetHandguide` | `/robot/handguide` | 拖动示教开关 |
| `RobotSetMotionParams` | `/robot/set_motion_params` | 设置运动参数 |

## 视觉接口

```text
DetectObjects.srv
bool publish_debug_image
---
bool success
string message
vision_msgs/Detection2DArray detections
bool has_sphere_center
float64[3] sphere_center_m
float64 sphere_radius_m
string sphere_frame_id
string sphere_class_id
float64 sphere_confidence
```

`detections` 保留二维框和置信度，抓取节点实际只使用 `has_sphere_center=true` 时的 `sphere_center_m`。

## 抓取接口

```text
GraspExecute.srv
bool wait
bool publish_debug_image
float64 approach_offset_m
---
bool success
int32 error_code
string message
float64[6] target_tcp_xyz_m_rpy_rad
float64[3] object_point_camera_m
float64[3] object_point_base_m
float64 depth_m
string debug_summary
```

调用示例：

```bash
ros2 service call /grasp/execute_once gas_interfaces/srv/GraspExecute \
  "{wait: true, publish_debug_image: true, approach_offset_m: 0.20}"
```

## 手眼接口

`HandEyeAddSample` 无请求字段，响应包含样本编号、样本数量、重投影误差和保存路径。

`HandEyeCompute` 请求可传 `output_path`，响应包含：

- `sample_count`
- `rms_reprojection_error_px`
- `tool_camera_matrix`
- `camera_tool_matrix`
- `result_file`

`HandEyeGetStatus` 用于 GUI 和抓取节点检查当前是否已有标定结果。

## 机器人接口

机器人服务统一挂在 `/robot` 命名空间下。默认配置在：

```text
src/gas_robot_control/config/aubo_control.yaml
```

常用检查：

```bash
ros2 service type /robot/get_pose
ros2 interface show gas_interfaces/srv/RobotGetPose
```

## 修改接口后的注意事项

如果改动 `.srv`，所有依赖接口的包都需要重新构建并重新 `source install/setup.bash`。当前请求只重写 README，没有修改任何接口文件。
