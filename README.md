# 气罐视觉、标定与抓取系统

本仓库是 ROS2 Humble 工作空间，集成 RealSense 相机、YOLOv8 ONNX 检测、有序点云球拟合、Charuco 手眼标定、标定精度验证、AUBO 机器人服务封装和一次抓取执行节点。

当前抓取主链路只使用 `yolo_cpp` 点云拟合得到的三维球心。`/grasp/execute_once` 不再使用二维框中心加深度图作为回退路径；如果 YOLO 没有返回合格的三维球心，抓取服务会直接失败并返回 `-2003`。

## 工作空间结构

```text
cylinder_project/
├── README.md                         # 当前入口说明
├── README_cylinder_project.md        # 图像采集与调试补充说明
├── calibration_data/
│   ├── handeye/<session>/results/handeye_result.yaml
│   └── handeye_validation/<session>/results/validation_result.yaml
├── src/
│   ├── gas_bringup/                  # 统一 launch 入口
│   ├── gas_interfaces/               # Detect / HandEye / Robot / Grasp srv
│   ├── gas_handeye_calibration/      # Charuco 手眼标定后端和采集 GUI
│   ├── gas_handeye_validation/       # 手眼结果精度验证和报告
│   ├── gas_robot_control/            # AUBO 机器人 service 封装
│   ├── gas_grasp_execution/          # 一次抓取执行服务
│   ├── yolo_cpp/                     # YOLO 推理、2D 检测和点云球拟合
│   └── third_party/                  # 当前使用的 RealSense / AUBO / ONNX Runtime，历史相机已忽略
├── third_party/onnxruntime/          # 旧层级遗留依赖
├── build/
├── install/
└── log/
```

## 关键包

| 包 | 作用 | README |
| --- | --- | --- |
| `gas_bringup` | 相机、视觉、标定、验证、抓取的统一启动入口 | `src/gas_bringup/README.md` |
| `gas_interfaces` | 本项目 service 接口定义 | `src/gas_interfaces/README.md` |
| `yolo_cpp` | YOLO 检测和点云球拟合 | `src/yolo_cpp/README.md` |
| `gas_handeye_calibration` | 手眼标定采样、计算和结果保存 | `src/gas_handeye_calibration/README.md` |
| `gas_handeye_validation` | 独立验证手眼标定精度 | `src/gas_handeye_validation/README.md` |
| `gas_robot_control` | AUBO 连接、使能、位姿、运动 service | `src/gas_robot_control/README.md` |
| `gas_grasp_execution` | 调用 YOLO、手眼和机器人完成一次预抓取 | `src/gas_grasp_execution/README.md` |
| `src/third_party` | 当前实际使用的 RealSense、AUBO、ONNX Runtime 依赖 | `src/third_party/README.md` |
| `third_party` | 旧层级遗留依赖说明 | `third_party/README.md` |

第三方包目录中的 README 属于 RealSense、ONNX Runtime 等依赖自身文档，本工程不覆盖。

## 环境

推荐环境：

- Ubuntu 22.04
- ROS2 Humble
- RealSense 相机
- AUBO 控制器，默认 `192.168.192.2:30004`
- OpenCV、cv_bridge、PCL、Eigen、ONNX Runtime、AUBO SDK

每个终端先执行：

```bash
cd ~/SyhDev/cylinder_project
source install/setup.bash
```

首次部署或接口变化后才需要重新构建：

```bash
cd ~/SyhDev/cylinder_project
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

## 模块运行清单

| 模块 | 命令 | 说明 |
| --- | --- | --- |
| 相机 | `ros2 launch gas_bringup camera.launch.py` | 只启动 RealSense 相机驱动 |
| 感知 | `ros2 launch gas_bringup perception.launch.py` | 相机 + YOLO + 点云球拟合 |
| 仅相机检查 | `ros2 launch gas_bringup perception.launch.py use_yolo:=false` | 只看彩色图和点云 |
| YOLO 调试 | `ros2 launch gas_bringup yolo_debug.launch.py` | 相机 + 检测节点 |
| 手眼采集 | `ros2 launch gas_bringup handeye_collection.launch.py` | 彩色图 + AUBO + 标定后端 |
| 手眼验证 | `ros2 launch gas_bringup handeye_validation.launch.py` | 验证已有标定结果 |
| 抓取链路 | `ros2 launch gas_bringup grasp_pipeline.launch.py handeye_result_file:=...` | 相机 + YOLO + AUBO + 抓取执行 |
| 机器人控制 | `ros2 launch gas_robot_control aubo_control.launch.py` | 单独启动 AUBO 服务 |
| 标定后端 | `ros2 launch gas_handeye_calibration handeye_calibration.launch.py` | 单独启动手眼后端 |
| 抓取执行 | `ros2 launch gas_grasp_execution grasp_execution.launch.py handeye_result_file:=...` | 单独启动抓取服务 |
| 采图工具 | `ros2 run yolo_cpp image_capture_node` | 保存 RGB / depth / point cloud |
| YOLO 节点 | `ros2 run yolo_cpp yolo_detect_node` | 相机已起时直接跑检测 |

这些入口都围绕 RealSense 的 `/camera/color/image_raw`、`/camera/color/camera_info` 和 `/camera/depth/color/points`。

## 推荐启动流程

### 1. 检查相机和点云

抓取链路需要有序点云，推荐用 perception 入口检查：

```bash
ros2 launch gas_bringup perception.launch.py use_yolo:=false
```

另开终端检查：

```bash
ros2 topic hz /camera/color/image_raw
ros2 topic hz /camera/depth/color/points
```

当前主链路使用 `/camera/depth/color/points`，不要按旧文档检查 `/camera/depth_registered/points`。

### 2. 采集手眼标定样本

```bash
ros2 launch gas_bringup handeye_collection.launch.py
```

GUI 中打开拖动，移动机器人到不同观察姿态，逐次采集样本，最后计算并保存：

```text
calibration_data/handeye/<session>/results/handeye_result.yaml
```

### 3. 验证标定精度

```bash
ros2 launch gas_bringup handeye_validation.launch.py
```

默认读取最新 `handeye_result.yaml`。正式实验建议显式指定：

```bash
ros2 launch gas_bringup handeye_validation.launch.py \
  handeye_result_file:=calibration_data/handeye/<session>/results/handeye_result.yaml
```

### 4. 启动抓取链路

```bash
ros2 launch gas_bringup grasp_pipeline.launch.py \
  handeye_result_file:=calibration_data/handeye/<session>/results/handeye_result.yaml
```

该入口会启动相机、YOLO、AUBO 控制节点和抓取节点。

### 5. 执行一次抓取

```bash
ros2 service call /grasp/execute_once gas_interfaces/srv/GraspExecute \
  "{wait: true, publish_debug_image: true, approach_offset_m: 0.20}"
```

ROS2 CLI 的 YAML 冒号后必须有空格，例如 `publish_debug_image: true`。

## 主数据流

```text
RealSense 相机
  ├── /camera/color/image_raw  ───────► yolo_cpp YOLO 检测
  ├── /camera/color/camera_info ──────► 手眼标定 / 精度验证
  └── /camera/depth/color/points ─────► yolo_cpp 点云 ROI 球拟合

yolo_cpp
  └── /yolo/detect_once
      ├── Detection2DArray
      └── has_sphere_center + sphere_center_m + sphere_radius_m

手眼标定
  └── calibration_data/handeye/<session>/results/handeye_result.yaml
      └── tool_camera_matrix

gas_grasp_execution
  ├── 读取 handeye_result.yaml
  ├── 调用 /yolo/detect_once 获取三维球心
  ├── 调用 /robot/get_pose 获取当前 TCP
  └── 调用 /robot/move_l 移动到预抓取点
```

## 常用接口

| 名称 | 类型 | 说明 |
| --- | --- | --- |
| `/yolo/detect_once` | `gas_interfaces/srv/DetectObjects` | 触发一次 YOLO 检测，返回 2D 检测和点云拟合三维球心 |
| `/grasp/execute_once` | `gas_interfaces/srv/GraspExecute` | 执行一次预抓取定位 |
| `/handeye/add_sample` | `gas_interfaces/srv/HandEyeAddSample` | 采集一组手眼样本 |
| `/handeye/compute` | `gas_interfaces/srv/HandEyeCompute` | 计算并保存手眼矩阵 |
| `/handeye/status` | `gas_interfaces/srv/HandEyeGetStatus` | 查询标定节点状态和结果文件 |
| `/robot/get_pose` | `gas_interfaces/srv/RobotGetPose` | 获取机器人 TCP 和关节位姿 |
| `/robot/move_l` | `gas_interfaces/srv/RobotMoveL` | 直线运动到目标 TCP |

查看完整字段：

```bash
ros2 interface show gas_interfaces/srv/DetectObjects
ros2 interface show gas_interfaces/srv/GraspExecute
```

## 抓取错误码

| error_code | 含义 | 优先检查 |
| --- | --- | --- |
| `0` | 成功 | 已到达目标或已发送运动命令 |
| `-2003` | 没有可用三维球心 | `/camera/depth/color/points`、`ordered_pc`、ROI 深度点、球体遮挡、反光 |
| `-2004` | 无法读取手眼结果 | `handeye_result_file`、`tool_camera_matrix` |
| `-2005` | 机器人位姿获取失败 | `/robot/get_pose`、机器人连接 |
| `-2006` | 深度或 approach 参数无效 | 球心 z 值、`approach_offset_m` |
| `-2007` | `MoveL` 执行失败 | 机器人状态、目标点可达性、碰撞风险 |
| `-2999` | 未捕获异常 | 查看节点日志 |

## 运行注意

- 抓取实验前必须确认机器人可急停、控制器处于远程模式、目标点在安全空间内。
- `grasp_pipeline.launch.py` 默认会自动连接并使能机器人。
- `handeye_collection.launch.py` 使用彩色图即可，不需要深度和点云。
- `perception.launch.py` 和 `grasp_pipeline.launch.py` 会把 YOLO 点云话题设置为 `/camera/depth/color/points`。
- 如果看到 `point cloud is not organized`，优先检查相机是否由 bringup 入口以 `ordered_pc:=true` 启动。
