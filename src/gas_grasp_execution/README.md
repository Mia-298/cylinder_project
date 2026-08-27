# gas_grasp_execution

`gas_grasp_execution` 提供 `/grasp/execute_once` 服务，用于执行一次气罐预抓取定位。它本身不做图像检测，也不直接读相机话题，而是串联 YOLO、手眼结果和机器人服务。

## 输入依赖

| 依赖 | 默认 |
| --- | --- |
| YOLO 服务 | `/yolo/detect_once` |
| 机器人位姿 | `/robot/get_pose` |
| 机器人直线运动 | `/robot/move_l` |
| 手眼状态 | `/handeye/status` |
| 手眼结果文件 | 最新 `calibration_data/handeye/*/results/handeye_result.yaml` 或 launch 显式传入 |

## 启动

推荐使用完整链路：

```bash
ros2 launch gas_bringup grasp_pipeline.launch.py \
  handeye_result_file:=calibration_data/handeye/<session>/results/handeye_result.yaml
```

单独启动本包节点：

```bash
ros2 launch gas_grasp_execution grasp_execution.launch.py \
  handeye_result_file:=calibration_data/handeye/<session>/results/handeye_result.yaml
```

单独启动时需要你自己保证 `/yolo/detect_once`、`/robot/get_pose`、`/robot/move_l` 已存在。

## 服务调用

```bash
ros2 service call /grasp/execute_once gas_interfaces/srv/GraspExecute \
  "{wait: true, publish_debug_image: true, approach_offset_m: 0.20}"
```

字段说明：

| 请求字段 | 说明 |
| --- | --- |
| `wait` | 是否等待机器人运动完成 |
| `publish_debug_image` | 是否要求 YOLO 发布调试图 |
| `approach_offset_m` | 沿相机射线从球心前方退回的预抓取距离 |

响应字段：

| 响应字段 | 说明 |
| --- | --- |
| `success` | 是否成功 |
| `error_code` | 错误码 |
| `target_tcp_xyz_m_rpy_rad` | 目标 TCP 位姿 |
| `object_point_camera_m` | 气罐球心在相机坐标系下的位置 |
| `object_point_base_m` | 气罐球心在机器人 base 坐标系下的位置 |
| `depth_m` | 球心深度 |
| `debug_summary` | 调试摘要 |

## 抓取计算流程

```text
1. 解析 handeye_result.yaml，读取 T_tool_camera
2. 调用 /yolo/detect_once
3. 要求 has_sphere_center=true
4. 校验 sphere_center_m 的 z 深度
5. 按 approach_offset_m 计算预抓取点
6. 调用 /robot/get_pose 得到 T_base_tool
7. 计算 T_base_camera = T_base_tool * T_tool_camera
8. 将目标点从 camera 坐标变换到 base 坐标
9. 保持当前 TCP 姿态，只替换 xyz
10. 调用 /robot/move_l
```

## 重要限制

当前版本只消费点云拟合出的三维球心：

```text
has_sphere_center=true
sphere_center_m=[x, y, z]
```

如果 YOLO 只有二维框，没有合格球心，服务直接返回 `-2003`。不会使用二维框中心加深度图回退。

## 错误码

| error_code | 含义 | 常见原因 |
| --- | --- | --- |
| `0` | 成功 | 已到达目标或已发送运动命令 |
| `-2003` | 没有可用三维球心 | 点云未发布、点云非 organized、ROI 深度点不足、球拟合失败 |
| `-2004` | 手眼结果不可用 | 未标定、路径错误、缺少 `tool_camera_matrix` |
| `-2005` | 机器人位姿不可用 | `/robot/get_pose` 不可用或返回失败 |
| `-2006` | 深度无效 | 球心 z 超范围，或 `approach_offset_m` 过大 |
| `-2007` | MoveL 失败 | 机器人状态、目标点不可达、控制器拒绝 |
| `-2999` | 异常 | 查看节点日志 |

## 调试顺序

1. `ros2 service list | grep /grasp`
2. `ros2 service list | grep /yolo`
3. `ros2 topic hz /camera/depth/points`
4. 手动调用 `/yolo/detect_once`，确认 `has_sphere_center=true`
5. 确认 `handeye_result_file` 指向正确标定结果
6. 调用 `/robot/get_pose`
7. 小 `approach_offset_m` 试运行，例如 `0.10`
