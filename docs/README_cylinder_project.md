# Cylinder Project：RealSense 图像采集与调试

本文件是当前工程的采图、视觉调试和模块运行补充说明。总入口说明见 `README.md`。

当前相机主链路已经切到 RealSense：

- 相机驱动：`src/third_party/realsense-ros-ros2`
- 统一相机入口：`ros2 launch gas_bringup camera.launch.py`
- 历史相机目录已通过 `COLCON_IGNORE` 排除

默认话题：

| 数据 | Topic | 类型 |
| --- | --- | --- |
| 彩色图 | `/camera/color/image_raw` | `sensor_msgs/msg/Image` |
| 相机内参 | `/camera/color/camera_info` | `sensor_msgs/msg/CameraInfo` |
| 深度图 | `/camera/depth/image_rect_raw` | `sensor_msgs/msg/Image` |
| 对齐点云 | `/camera/depth/color/points` | `sensor_msgs/msg/PointCloud2` |

抓取和球拟合只使用 `/camera/depth/color/points`，不再使用旧的 `/camera/depth_registered/points`。

## 1. 工作空间

本说明默认工作空间位于：

```bash
cd ~/SyhDev/cylinder_project
```

每个新终端先加载环境：

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash
```

首次部署或接口变化后重新构建：

```bash
cd ~/SyhDev/cylinder_project
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

## 2. 模块运行指令

| 目标 | 命令 | 说明 |
| --- | --- | --- |
| 只启动相机 | `ros2 launch gas_bringup camera.launch.py` | RealSense 驱动 |
| 检查相机和点云 | `ros2 launch gas_bringup perception.launch.py use_yolo:=false` | 不启动 YOLO |
| 启动视觉检测 | `ros2 launch gas_bringup perception.launch.py` | 相机 + YOLO |
| 视觉调试 | `ros2 launch gas_bringup yolo_debug.launch.py` | 调试检测显示 |
| 手眼采集 | `ros2 launch gas_bringup handeye_collection.launch.py` | 彩色图 + 机器人 + 标定 GUI |
| 手眼验证 | `ros2 launch gas_bringup handeye_validation.launch.py` | 验证已有手眼结果 |
| 完整抓取 | `ros2 launch gas_bringup grasp_pipeline.launch.py handeye_result_file:=calibration_data/handeye/<session>/results/handeye_result.yaml` | 相机 + YOLO + AUBO + 抓取 |
| 机器人服务 | `ros2 launch gas_robot_control aubo_control.launch.py` | 单独启动 AUBO 控制节点 |
| 采图工具 | `ros2 run yolo_cpp image_capture_node` | 保存 RGB / depth / point cloud |
| YOLO 节点 | `ros2 run yolo_cpp yolo_detect_node` | 相机已启动时可直接运行 |

## 3. 相机检查

只检查 RealSense 输出：

```bash
ros2 launch gas_bringup perception.launch.py use_yolo:=false
```

另开终端检查话题：

```bash
ros2 topic hz /camera/color/image_raw
ros2 topic hz /camera/depth/color/points
ros2 topic info /camera/depth/color/points
```

`/camera/depth/color/points` 的发布者应来自 `realsense2_camera_node`。

## 4. 图像和点云采集

先启动相机：

```bash
ros2 launch gas_bringup perception.launch.py use_yolo:=false
```

另开终端启动采图工具：

```bash
ros2 run yolo_cpp image_capture_node
```

默认按键：

```text
p: 保存下一张彩色图
d: 保存按键后第一组彩色图、深度图和点云
q: 退出
```

默认保存目录：

| 数据 | 目录 |
| --- | --- |
| 彩色图 | `~/cylinder_dataset/images` |
| 深度图 | `~/cylinder_dataset/depth` |
| 点云 | `~/cylinder_dataset/pointclouds` |

检查保存结果：

```bash
ls -lh ~/cylinder_dataset/images
ls -lh ~/cylinder_dataset/depth
ls -lh ~/cylinder_dataset/pointclouds
```

## 5. YOLO 检测调试

推荐用 bringup 入口：

```bash
ros2 launch gas_bringup yolo_debug.launch.py
```

手动触发一次检测：

```bash
ros2 service call /yolo/detect_once gas_interfaces/srv/DetectObjects \
  "{publish_debug_image: true}"
```

抓取需要返回：

```text
has_sphere_center=true
sphere_center_m=[x, y, z]
```

如果出现 `point cloud is not organized`，优先检查 `src/gas_bringup/config/realsense_camera.yaml` 中是否保持：

```yaml
pointcloud.enable: true
pointcloud.ordered_pc: true
align_depth.enable: true
```

## 6. 模型更新

如需更新模型，将新的 `best.pt` 转成 ONNX 后替换：

```text
src/yolo_cpp/models/best.onnx
```

如果不是 `--symlink-install` 构建，替换模型后重新执行：

```bash
colcon build --packages-select yolo_cpp --symlink-install
source install/setup.bash
```
