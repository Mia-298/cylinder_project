# gas_bringup

`gas_bringup` 是本工作空间的统一启动包。实验时优先从这里启动，不建议直接调用底层包的 launch，避免话题、相机参数或机器人配置不一致。

## 启动入口

| launch | 作用 |
| --- | --- |
| `camera.launch.py` | 封装 RealSense 相机启动，供其它 launch include |
| `perception.launch.py` | 启动相机和 `yolo_cpp`，用于视觉检测和点云球拟合 |
| `handeye_collection.launch.py` | 启动彩色相机、AUBO、手眼标定后端和采集 GUI |
| `handeye_validation.launch.py` | 启动手眼标定精度验证 |
| `grasp_pipeline.launch.py` | 启动相机、YOLO、AUBO 和抓取执行节点 |
| `yolo_debug.launch.py` | 视觉调试入口 |

## 相机配置

| 配置文件 | 用途 |
| --- | --- |
| `config/realsense_camera.yaml` | 感知和抓取，启用彩色图、深度图、点云、有序点云 |
| `config/realsense_handeye_camera.yaml` | 手眼标定，只启用彩色图和相机内参 |

抓取和感知链路以 `/camera/depth/color/points` 为点云输入。旧的 `/camera/depth_registered/points` 不作为当前主链路判断依据。

## 常用命令

只检查相机和点云：

```bash
ros2 launch gas_bringup perception.launch.py use_yolo:=false
```

启动视觉检测：

```bash
ros2 launch gas_bringup perception.launch.py
```

启动手眼采集：

```bash
ros2 launch gas_bringup handeye_collection.launch.py
```

启动标定验证：

```bash
ros2 launch gas_bringup handeye_validation.launch.py
```

启动完整抓取：

```bash
ros2 launch gas_bringup grasp_pipeline.launch.py \
  handeye_result_file:=calibration_data/handeye/<session>/results/handeye_result.yaml
```

自动延迟执行一次抓取：

```bash
ros2 launch gas_bringup grasp_pipeline.launch.py \
  execute_once:=true \
  execute_delay_sec:=8.0 \
  handeye_result_file:=calibration_data/handeye/<session>/results/handeye_result.yaml
```

## 运行检查

```bash
ros2 topic hz /camera/color/image_raw
ros2 topic hz /camera/depth/color/points
ros2 service list | grep -E "yolo|grasp|handeye|robot"
```

## 注意

- `perception.launch.py` 会覆盖 YOLO 的 `point_cloud_topic` 为 `/camera/depth/color/points`。
- `grasp_pipeline.launch.py` 默认自动连接并使能 AUBO。
- 手眼采集入口为了稳定采样，只启动彩色相机，不启用深度和点云。
