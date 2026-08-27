# src/third_party

这里放当前 ROS2 工作空间实际使用的第三方依赖。依赖自身的 README 保持原样，本文件只说明本项目如何组织这些依赖。

## 目录

```text
src/third_party/
├── OrbbecSDK_ROS2/       # 当前使用的 Orbbec ROS2 相机包
├── aubo_sdk/             # AUBO 机器人 SDK 头文件和库
└── onnxruntime/          # YOLO ONNX 推理依赖
```

## 使用关系

| 目录 | 被谁使用 | 说明 |
| --- | --- | --- |
| `OrbbecSDK_ROS2` | `gas_bringup/camera.launch.py` | 提供 `orbbec_camera`、消息和描述包 |
| `aubo_sdk` | `gas_robot_control` | 提供 AUBO RPC 控制库 |
| `onnxruntime` | `yolo_cpp` | 提供 ONNX Runtime C/C++ 库 |

## 注意

- `src/OrbbecSDK_ROS2-2-main` 是旧相机包，已有 `COLCON_IGNORE`，不是当前主链路。
- 不要把 vendor README 改成本项目说明；项目说明写在本文件和根目录 README 中。
- 若升级第三方库，需要同步检查对应包的 `CMakeLists.txt`、库路径和运行时环境。
