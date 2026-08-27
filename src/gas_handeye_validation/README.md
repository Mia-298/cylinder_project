# gas_handeye_validation

`gas_handeye_validation` 用于验证已经计算完成的手眼标定结果。它不会重新标定，而是固定 `handeye_result.yaml` 中的 `T_tool_camera`，重新采集多组验证姿态，检查同一个标定板在机器人 base 坐标系下是否保持一致。

## 验证原理

每个验证样本都会检测 Charuco 板，读取当前机器人 TCP 位姿，并计算：

```text
T_base_board_i = T_base_tool_i * T_tool_camera * T_camera_board_i
```

如果手眼矩阵可靠、标定板固定不动，则不同姿态得到的 `T_base_board_i` 应彼此接近。

## 启动

推荐从统一入口启动：

```bash
ros2 launch gas_bringup handeye_validation.launch.py
```

默认读取最新：

```text
calibration_data/handeye/*/results/handeye_result.yaml
```

正式实验建议显式指定：

```bash
ros2 launch gas_bringup handeye_validation.launch.py \
  handeye_result_file:=calibration_data/handeye/<session>/results/handeye_result.yaml
```

## 参数

默认参数文件：

```text
src/gas_handeye_validation/config/handeye_validation.yaml
```

关键参数：

| 参数 | 默认值 |
| --- | --- |
| `image_topic` | `/camera/color/image_raw` |
| `camera_info_topic` | `/camera/color/camera_info` |
| `robot_pose_service` | `/robot/get_pose` |
| `handguide_service` | `/robot/handguide` |
| `save_root_dir` | `calibration_data/handeye_validation` |
| `board_dictionary_id` | `7` |
| `board_squares_x` | `10` |
| `board_squares_y` | `7` |
| `board_square_length_m` | `0.025` |
| `board_marker_length_m` | `0.018` |
| `min_charuco_corners` | `12` |
| `min_validation_samples` | `8` |

## GUI 操作

1. 确认 GUI 显示的 `handeye_result_file` 正确。
2. 固定标定板，不要在验证过程中移动。
3. 打开拖动示教，移动机器人到不同观察姿态。
4. 确认图像中 Charuco 角点和坐标轴稳定。
5. 输入姿态标签，例如 `front`、`left_yaw`、`pitch_up`。
6. 点击采集验证样本。
7. 至少采集 8 组，覆盖偏航、俯仰、滚转和远近变化。
8. 点击生成报告。

## 输出目录

```text
calibration_data/handeye_validation/<session>/
├── session.yaml
├── samples/
│   ├── sample_0000.yaml
│   ├── sample_0000_raw.png
│   └── ...
├── debug/
│   ├── sample_0000_debug.png
│   └── ...
└── results/
    ├── validation_result.yaml
    ├── samples.csv
    └── precision_validation_report.md
```

## 指标说明

| 指标 | 单位 | 含义 |
| --- | --- | --- |
| `reprojection_rms_px` | px | Charuco 角点重投影误差，反映图像层面位姿拟合质量 |
| `validation_translation_rms_mm` | mm | 多姿态反算板位置的一致性 |
| `validation_rotation_rms_deg` | deg | 多姿态反算板方向的一致性 |

重投影误差小但平移 RMS 大时，问题通常不在角点检测，而可能在手眼矩阵、TCP、机器人位姿读取、标定板固定性或采样姿态分布。

## 常见问题

### 角点太少

默认 `min_charuco_corners=12`。角点太少会导致 `T_camera_board` 不稳定。可以临时降低，但不建议低于 8。

### 验证结果很差

优先检查：

- 验证时标定板是否移动。
- `handeye_result_file` 是否是本次要验证的结果。
- 机器人 TCP 设置是否和标定时一致。
- 验证姿态是否覆盖足够角度。
- 相机画面中 Charuco 角点是否清晰。

### 这是不是重新标定

不是。本包固定已有 `T_tool_camera`，只评估该结果在多姿态下的一致性。
