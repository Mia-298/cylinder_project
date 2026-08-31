# yolo_cpp

`yolo_cpp` 负责气罐视觉检测和点云球拟合。它订阅相机彩色图和点云，周期性更新最新检测结果，并通过 `/yolo/detect_once` 提供一次性检测服务。

## 节点

| 可执行文件 | 作用 |
| --- | --- |
| `yolo_detect_node` | YOLOv8 ONNX 推理、2D 框输出、点云 ROI 球拟合 |
| `image_capture_node` | 图像、深度图、点云采集工具 |

主链路使用 `yolo_detect_node`。

## 输入输出

输入：

| 参数 | 主链路值 |
| --- | --- |
| `image_topic` | `/camera/color/image_raw` |
| `point_cloud_topic` | `/camera/depth/color/points` |
| `model_path` | `yolo_cpp/models/best.onnx` |
| `sphere_target_class` | `class_0` |
| `capture_interval_sec` | `0.5` |

服务：

```text
/yolo/detect_once
```

服务类型：

```text
gas_interfaces/srv/DetectObjects
```

返回：

- `detections`：二维检测框和置信度。
- `has_sphere_center`：是否有合格球拟合结果。
- `sphere_center_m`：相机坐标系下三维球心，单位 m。
- `sphere_radius_m`：拟合球半径，单位 m。
- `sphere_frame_id`：点云坐标系。

## 启动

推荐通过 bringup 启动：

```bash
ros2 launch gas_bringup perception.launch.py
```

只检查相机和点云，不启动 YOLO：

```bash
ros2 launch gas_bringup perception.launch.py use_yolo:=false
```

手动触发检测：

```bash
ros2 service call /yolo/detect_once gas_interfaces/srv/DetectObjects \
  "{publish_debug_image: true}"
```

## 点云要求

球拟合依赖 organized point cloud。当前主链路应检查：

```bash
ros2 topic hz /camera/depth/color/points
```

如果日志出现：

```text
point cloud is not organized
```

优先检查：

1. 是否从 `gas_bringup/perception.launch.py` 或 `gas_bringup/grasp_pipeline.launch.py` 启动。
2. 相机是否启用了 `ordered_pc=true`。
3. 点云话题是否是 `/camera/depth/color/points`。
4. 目标 ROI 内是否有足够有效深度点。

## 与抓取节点的关系

`/yolo/detect_once` 同时返回 2D 检测结果和点云拟合球心。当前抓取节点只消费点云拟合出的三维球心：

```text
has_sphere_center=true
sphere_center_m=[x, y, z]
```

如果只有二维框但没有球心，`/grasp/execute_once` 会返回 `-2003`。系统不会使用 2D 框中心加深度图回退。

## 图像采集工具

`image_capture_node` 可用于数据采集。默认按键：

```text
p: 保存下一张彩色图
d: 保存下一组彩色图、深度图和点云
q: 退出
```

该工具保留兼容旧采图流程，不是当前抓取主链路必需节点。
