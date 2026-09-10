# gas_handeye_calibration

`gas_handeye_calibration` 是手眼标定后端和采集 GUI 所在包。它通过 Charuco 标定板估计 `T_camera_board`，同时读取机器人当前 TCP 位姿，最终计算 `tool_camera_matrix`。

## 启动

推荐从统一入口启动：

```bash
ros2 launch gas_bringup handeye_collection.launch.py
```

如果只想单独启动标定后端：

```bash
ros2 launch gas_handeye_calibration handeye_calibration.launch.py
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
| `board_legacy_pattern` | `true`，旧版排列 |
| `board_excluded_marker_ids` | 默认不排除；填写被遮挡的 marker ID 列表 |
| `min_charuco_corners` | `4`，单次采集的最少有效角点数 |
| `handeye_method` | `TSAI` |
| `min_samples` | `5` |

### 新版中心二维码标定板

`docs/新版标定板文件/rsd435i_charuco_qr_300mm_v1.pdf` 对应配置为
`config/handeye_calibration_rsd435i.yaml`。使用项目根目录下的这份配置启动手动标定：

```bash
ros2 launch gas_bringup handeye_collection.launch.py \
  handeye_params:=src/gas_handeye_calibration/config/handeye_calibration_rsd435i.yaml
```

| 配置项 | 旧板默认配置 | 新版配置 |
| --- | --- | --- |
| 方格数量 `board_squares_x / board_squares_y` | 10 / 7 | 10 / 10 |
| 字典 `board_dictionary_id` | 7（DICT_5X5_1000） | 7（DICT_5X5_1000） |
| 方格 / marker 边长 | 0.025 / 0.018 m | 0.025 / 0.018 m |
| 排列 `board_legacy_pattern` | true | false，与新版 PDF 生成器一致 |
| 排除的 marker ID | 无 | 17、18、21、22、27、28、31、32 |
| 最少有效角点 `min_charuco_corners` | 4 | 20 |

板参数只需在选用的 YAML 中设置，采集界面和 C++ 标定后端共用这些参数。
`board_squares_x/y` 填方格数，新版填写 10×10，不是内部角点数 9×9。
单位是米；边长应与按 100% 比例打印并实测的实体板一致。

中心二维码作为遮挡区域处理：排除与 90 mm 面板相交的 8 个 marker，其余 ID 保持生成器的原编号，继续使用可见 ChArUco 角点计算位姿。本流程不解码 QR，也不通过 QR 自动识别板型或校验尺寸，不支持资料中另行提到的“无 ArUco 的普通棋盘＋QR”版本。

新版配置的采集界面需要 Python OpenCV 支持 `CharucoBoard.setLegacyPattern`（例如 4.10）；C++ 后端已兼容项目现有的 OpenCV 4.5.4。界面的 `showing 12` 只是绘制数量上限，实际采集检查的是全部有效角点数，少于 20 个会拒绝保存。

切换板型后重新启动采集程序并新建一轮样本，不混用两块板的样本。省略 `handeye_params` 仍使用原来的 10×7 配置。结果文件路径和采集、计算按钮保持原有用法；`session.yaml` 会记录本次板型参数。独立的 `gas_handeye_validation` 精度验证程序尚未适配此新版板配置。

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
