# Cylinder Project：奥比中光图像采集

本项目基于 ROS 2 Humble，使用奥比中光 Gemini 330 系列相机发布彩色图像，并通过 `yolo_cpp` 功能包保存图像。

相机发布的彩色图像话题为：

```text
/camera/color/image_raw
```

图像采集节点支持两种工作模式：

1. 默认模式：在节点运行终端中按 `p`，保存下一张接收到的图像；
2. 自动模式：按照指定时间间隔连续保存图像。

图像默认保存到：

```text
/home/用户名/cylinder_dataset
```

在命令行中可表示为：

```bash
$HOME/cylinder_dataset
```

---

## 1. 工作空间路径

本说明假设 ROS 2 工作空间位于：

```text
~/data/Project_Backup/orbbec_software/cylinder_project
```

进入工作空间：

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
```

工作空间结构示例：

```text
cylinder_project/
├── src/
│   ├── orbbec_camera/
│   ├── orbbec_camera_msgs/
│   ├── orbbec_description/
│   └── yolo_cpp/
├── install_dependencies.sh
├── requirements.txt
├── build/
├── install/
└── log/
```

其中：

- `orbbec_camera`：奥比中光 ROS 2 相机驱动；
- `yolo_cpp`：彩色图像订阅与保存节点；
- `install_dependencies.sh`：依赖安装脚本；
- `build`、`install`、`log`：由 `colcon build` 生成。

---

## 2. 首次安装依赖

首次使用前，在工作空间根目录运行依赖安装脚本。

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
```

赋予脚本执行权限：

```bash
chmod +x install_dependencies.sh
```

加载 ROS 2 Humble 环境：

```bash
source /opt/ros/humble/setup.bash
```

运行依赖安装脚本：

```bash
./install_dependencies.sh
```

该脚本用于安装或检查以下依赖：

- ROS 2 Humble 构建工具；
- `rclcpp`；
- `sensor_msgs`；
- `cv_bridge`；
- OpenCV；
- `rosdep`；
- `colcon`；
- 工作空间内各功能包在 `package.xml` 中声明的依赖。

依赖安装通常只需在首次配置环境或依赖发生变化时执行。

---

## 3. 编译工作空间

完成依赖安装后，在工作空间根目录执行：

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
source /opt/ros/humble/setup.bash
colcon build
```

仅编译图像采集功能包时，可执行：

```bash
colcon build --packages-select yolo_cpp
```

编译完成后加载工作空间环境：

```bash
source install/setup.bash
```

每次重新编译后，应在需要运行节点的终端中重新执行：

```bash
source install/setup.bash
```

---

## 4. 启动流程

相机驱动和图像采集节点需要在两个终端中分别运行。

两个终端均需进入工作空间并加载环境：

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
source /opt/ros/humble/setup.bash
source install/setup.bash
```

---

## 5. 终端 1：启动奥比中光相机

在第一个终端中执行：

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 launch orbbec_camera gemini_330_series.launch.py
```

相机正常启动后，应发布彩色图像话题：

```text
/camera/color/image_raw
```

检查话题是否存在：

```bash
ros2 topic list | grep image_raw
```

检查彩色图像话题类型：

```bash
ros2 topic type /camera/color/image_raw
```

预期输出：

```text
sensor_msgs/msg/Image
```

检查图像发布帧率：

```bash
ros2 topic hz /camera/color/image_raw
```

---

## 6. 终端 2：默认按键拍照

在第二个终端中执行：

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 run yolo_cpp image_capture_node
```

默认模式下，节点不会自动连续保存图像。

按键功能：

```text
p：保存按键触发后接收到的下一张图像
q：退出图像采集节点
Ctrl+C：退出图像采集节点
```

按下 `p` 后，节点会等待下一张 `/camera/color/image_raw` 消息到达，然后保存该帧。

默认保存目录：

```bash
$HOME/cylinder_dataset
```

例如，当前用户名为 `mia` 时，实际保存路径为：

```text
/home/mia/cylinder_dataset
```

查看已保存图像：

```bash
ls -lh ~/cylinder_dataset
```

---

## 7. 自动连续拍摄

自动连续拍摄需要在启动节点时显式设置：

```bash
ros2 run yolo_cpp image_capture_node --ros-args \
  -p auto_save:=true \
  -p interval_sec:=0.5
```

上述命令表示：

```text
每隔约 0.5 秒保存一张新图像
```

对应保存速率约为：

```text
2 张/秒
```

### 每隔 1 秒保存一张

```bash
ros2 run yolo_cpp image_capture_node --ros-args \
  -p auto_save:=true \
  -p interval_sec:=1.0
```

### 每隔 0.2 秒保存一张

```bash
ros2 run yolo_cpp image_capture_node --ros-args \
  -p auto_save:=true \
  -p interval_sec:=0.2
```

自动拍摄期间仍可按 `p`，额外请求保存下一张图像。

---

## 8. 自定义保存目录

默认保存目录为：

```bash
$HOME/cylinder_dataset
```

指定其他保存目录：

```bash
ros2 run yolo_cpp image_capture_node --ros-args \
  -p save_directory:=/home/mia/data/cylinder_images
```

自动连续拍摄并指定保存目录：

```bash
ros2 run yolo_cpp image_capture_node --ros-args \
  -p auto_save:=true \
  -p interval_sec:=0.5 \
  -p save_directory:=/home/mia/data/cylinder_images
```

如果目标目录不存在，节点会自动创建该目录。

---

## 9. 常用参数

| 参数 | 默认值 | 说明 |
|---|---:|---|
| `image_topic` | `/camera/color/image_raw` | 订阅的彩色图像话题 |
| `save_directory` | `~/cylinder_dataset` | 图像保存目录 |
| `auto_save` | `false` | 是否启用自动连续拍摄 |
| `interval_sec` | `0.5` | 自动拍摄间隔，单位为秒 |
| `image_format` | `jpg` | 保存格式，可设置为 `jpg` 或 `png` |
| `filename_prefix` | `color` | 图像文件名前缀 |
| `jpeg_quality` | `95` | JPEG 保存质量 |
| `png_compression` | `3` | PNG 压缩等级 |

---

## 10. 图像文件命名

保存后的图像文件示例：

```text
color_000001_ros_1753952401_123456789.jpg
color_000002_ros_1753952401_623456789.jpg
color_000003_ros_1753952402_123456789.jpg
```

文件名中包含：

```text
文件前缀
图像序号
ROS 时间戳秒
ROS 时间戳纳秒
图像格式
```

统计已保存图像数量：

```bash
find ~/cylinder_dataset \
  -maxdepth 1 \
  -type f \
  | wc -l
```

查看最近保存的文件：

```bash
ls -lht ~/cylinder_dataset | head
```

清空采集目录前可先确认文件：

```bash
ls ~/cylinder_dataset
```

确认后删除所有已采集图像：

```bash
rm -f ~/cylinder_dataset/*
```

---

## 11. 完整操作流程

### 首次配置

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project

source /opt/ros/humble/setup.bash

chmod +x install_dependencies.sh
./install_dependencies.sh

colcon build
source install/setup.bash
```

### 终端 1：启动相机

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 launch orbbec_camera gemini_330_series.launch.py
```

### 终端 2：按 `p` 拍照

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 run yolo_cpp image_capture_node
```

节点启动后，在当前终端中按：

```text
p
```

即可保存下一张接收到的图像。

### 终端 2：自动连续拍照

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
source /opt/ros/humble/setup.bash
source install/setup.bash

ros2 run yolo_cpp image_capture_node --ros-args \
  -p auto_save:=true \
  -p interval_sec:=0.5
```

---

## 12. 默认代码参数

为了使节点默认采用“按 `p` 拍照”模式，代码中的默认参数应为：

```cpp
declare_parameter<bool>(
  "auto_save",
  false);
```

默认保存目录应为：

```cpp
declare_parameter<std::string>(
  "save_directory",
  "~/cylinder_dataset");
```

修改节点代码后重新编译：

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project

source /opt/ros/humble/setup.bash

colcon build --packages-select yolo_cpp

source install/setup.bash
```

如果代码中的 `auto_save` 默认值仍为 `true`，则直接运行节点时会自动连续拍摄，与本文档描述的默认行为不一致。

---

## 13. 常见问题

### 13.1 找不到功能包

报错示例：

```text
Package 'yolo_cpp' not found
```

处理方法：

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
source /opt/ros/humble/setup.bash
source install/setup.bash
```

然后重新运行：

```bash
ros2 run yolo_cpp image_capture_node
```

### 13.2 找不到相机启动文件

确认已经成功编译工作空间：

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project
colcon build
source install/setup.bash
```

检查启动文件：

```bash
ros2 launch orbbec_camera gemini_330_series.launch.py --show-args
```

### 13.3 节点没有收到图像

检查话题：

```bash
ros2 topic list | grep /camera/color/image_raw
```

检查帧率：

```bash
ros2 topic hz /camera/color/image_raw
```

如果话题不存在或没有数据，应优先检查相机驱动和 USB 连接。

### 13.4 按 `p` 没有反应

按键输入依赖交互式终端。建议使用以下方式直接启动节点：

```bash
ros2 run yolo_cpp image_capture_node
```

不要将按键采集节点放到后台运行，也不要在无法接收标准输入的终端环境中运行。

### 13.5 修改代码后运行结果没有变化

重新编译并加载环境：

```bash
cd ~/data/Project_Backup/orbbec_software/cylinder_project

colcon build --packages-select yolo_cpp

source install/setup.bash
```

如果仍然运行旧版本，可清理该功能包的构建结果：

```bash
rm -rf build/yolo_cpp
rm -rf install/yolo_cpp

colcon build --packages-select yolo_cpp
source install/setup.bash
```
