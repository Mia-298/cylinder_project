# gas_handeye_calibration

`gas_handeye_calibration` 是手眼标定后端和采集 GUI 所在包。它通过 Charuco 标定板估计 `T_camera_board`，同时读取机器人当前 TCP 位姿，最终计算 `tool_camera_matrix`。

## 启动

推荐从统一入口启动：

```bash
ros2 launch gas_bringup handeye_collection.launch.py
```

该入口会启动：

- RealSense 彩色相机和 `/camera/color/camera_info`
- AUBO 控制节点
- `handeye_calibration_node`
- `handeye_capture_ui.py`

## 标定参数

默认参数文件：

```text
src/gas_handeye_calibration/config/handeye_calibration.yaml
```

关键参数：

| 参数 | 值 |
| --- | --- |
| `image_topic` | `/camera/color/image_raw` |
| `camera_info_topic` | `/camera/color/camera_info` |
| `robot_pose_service` | `/robot/get_pose` |
| `save_root_dir` | `calibration_data/handeye` |
| `board_dictionary_id` | `7` |
| `board_squares_x` | `10` |
| `board_squares_y` | `7` |
| `board_square_length_m` | `0.025` |
| `board_marker_length_m` | `0.018` |
| `handeye_method` | `TSAI` |
| `min_samples` | `5` |

## 服务

| 服务 | 类型 | 说明 |
| --- | --- | --- |
| `/handeye/add_sample` | `gas_interfaces/srv/HandEyeAddSample` | 采集当前图像、Charuco 位姿和机器人 TCP |
| `/handeye/clear_samples` | `gas_interfaces/srv/HandEyeClearSamples` | 清空当前 session 样本 |
| `/handeye/compute` | `gas_interfaces/srv/HandEyeCompute` | 计算手眼矩阵 |
| `/handeye/status` | `gas_interfaces/srv/HandEyeGetStatus` | 查询图像、内参、机器人和标定状态 |

## GUI 操作流程

1. 启动 `handeye_collection.launch.py`。
2. 确认 GUI 画面中可以稳定看到 Charuco 板。
3. 打开拖动示教，把机器人移动到第一个观察姿态。
4. 点击采集样本。
5. 改变观察姿态，重复采集。
6. 至少采集 5 组，实验建议多于 8 组。
7. 点击计算手眼，生成 `handeye_result.yaml`。

## 采样建议

标定板固定，移动相机或机器人末端：

- 正视、左偏航、右偏航
- 上俯仰、下俯仰
- 左滚转、右滚转
- 近距离、远距离

不要只在一个小范围内平移。姿态变化不足会导致手眼矩阵不稳定。

## 输出目录

```text
calibration_data/handeye/<session>/
├── session.yaml
├── samples/
│   ├── sample_0000.yaml
│   ├── sample_0000_raw.png
│   └── ...
├── debug/
│   ├── sample_0000_debug.png
│   └── ...
└── results/
    └── handeye_result.yaml
```

抓取节点需要 `handeye_result.yaml` 中的：

```text
tool_camera_matrix
```

正式抓取实验建议显式传入手眼结果文件：

```bash
ros2 launch gas_bringup grasp_pipeline.launch.py \
  handeye_result_file:=calibration_data/handeye/<session>/results/handeye_result.yaml
```
