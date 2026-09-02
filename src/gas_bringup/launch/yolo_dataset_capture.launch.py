from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # -------------------------------------------------------------------------
    # 1. 找到本项目已经封装好的 RealSense 相机 launch。
    #
    # 这里不直接 include realsense2_camera 的 rs_launch.py，而是复用
    # gas_bringup/launch/camera.launch.py。这样相机入口只有一套，后续维护
    # RealSense 参数时也只需要维护 camera.launch.py 和 config/*.yaml。
    # -------------------------------------------------------------------------
    camera_launch = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'launch',
        'camera.launch.py',
    ])

    # -------------------------------------------------------------------------
    # 2. 准备默认相机配置。
    #
    # realsense_camera.yaml 会启动彩色、深度和点云。虽然 YOLO 训练主要使用
    # 彩色图，但连续拍照节点本身也订阅深度图和点云；默认用完整 RGB-D
    # 配置可以让这些订阅也有真实 RealSense 发布者，便于检查数据链路。
    # 如果只想轻量采集 RGB 图片，可以启动时覆盖：
    # camera_config:=<gas_bringup>/config/realsense_handeye_camera.yaml
    # -------------------------------------------------------------------------
    default_camera_config = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'config',
        'realsense_camera.yaml',
    ])

    return LaunchDescription([
        # ---------------------------------------------------------------------
        # 3. 总开关参数。
        #
        # use_camera 控制是否启动 RealSense 驱动。
        # use_capture 控制是否启动 yolo_cpp 的连续采图节点。
        # 如果相机已经由别的终端启动，可以传 use_camera:=false，只启动采图。
        # ---------------------------------------------------------------------
        DeclareLaunchArgument(
            'use_camera',
            default_value='true',
            description='Start the RealSense camera driver.',
        ),
        DeclareLaunchArgument(
            'use_capture',
            default_value='true',
            description='Start the YOLO dataset image capture node.',
        ),

        # ---------------------------------------------------------------------
        # 4. RealSense 相机参数。
        #
        # 这些参数原样转交给 gas_bringup/launch/camera.launch.py。
        # 最常改的是 camera_config；多相机或固定某台相机时再改 serial_no。
        # ---------------------------------------------------------------------
        DeclareLaunchArgument(
            'camera_config',
            default_value=default_camera_config,
            description='YAML file passed to the RealSense camera driver.',
        ),
        DeclareLaunchArgument(
            'camera_name',
            default_value='camera',
            description='RealSense node name.',
        ),
        DeclareLaunchArgument(
            'camera_namespace',
            default_value='',
            description='RealSense node namespace. Leave empty to keep /camera/... topics.',
        ),
        DeclareLaunchArgument(
            'serial_no',
            default_value='',
            description='Choose a RealSense device by serial number.',
        ),
        DeclareLaunchArgument(
            'usb_port_id',
            default_value='',
            description='Choose a RealSense device by USB port id.',
        ),
        DeclareLaunchArgument(
            'device_type',
            default_value='',
            description='Choose a RealSense device by type.',
        ),
        DeclareLaunchArgument(
            'json_file_path',
            default_value='',
            description='Optional advanced RealSense configuration JSON file.',
        ),
        DeclareLaunchArgument(
            'initial_reset',
            default_value='false',
            description='Reset the camera before starting.',
        ),
        DeclareLaunchArgument(
            'log_level',
            default_value='info',
            description='ROS log level for started nodes.',
        ),
        DeclareLaunchArgument(
            'output',
            default_value='screen',
            description='Node output destination.',
        ),

        # ---------------------------------------------------------------------
        # 5. 连续采图节点的输入话题参数。
        #
        # color_topic 是 YOLO 训练真正需要的彩色图输入。
        # depth_topic 和 pointcloud_topic 保留给按需采 RGB-D/点云数据使用，
        # 默认话题全部对应当前 RealSense 相机链路。
        # ---------------------------------------------------------------------
        DeclareLaunchArgument(
            'color_topic',
            default_value='/camera/color/image_raw',
            description='Color image topic subscribed by image_capture_node.',
        ),
        DeclareLaunchArgument(
            'depth_topic',
            default_value='/camera/depth/image_rect_raw',
            description='Depth image topic subscribed by image_capture_node.',
        ),
        DeclareLaunchArgument(
            'pointcloud_topic',
            default_value='/camera/depth/color/points',
            description='Point cloud topic subscribed by image_capture_node.',
        ),

        # ---------------------------------------------------------------------
        # 6. 连续采图节点的保存位置和文件名参数。
        #
        # 默认会把 YOLO 训练图片写到 ~/cylinder_dataset/images。
        # 文件名前缀默认是 yolo，最终文件名会带序号和 ROS 时间戳。
        # ---------------------------------------------------------------------
        DeclareLaunchArgument(
            'save_directory',
            default_value='~/cylinder_dataset/images',
            description='Directory used to save captured color images.',
        ),
        DeclareLaunchArgument(
            'depth_save_directory',
            default_value='~/cylinder_dataset/depth',
            description='Directory used to save captured depth images.',
        ),
        DeclareLaunchArgument(
            'pointcloud_save_directory',
            default_value='~/cylinder_dataset/pointclouds',
            description='Directory used to save captured point clouds.',
        ),
        DeclareLaunchArgument(
            'filename_prefix',
            default_value='yolo',
            description='Prefix for saved color image filenames.',
        ),
        DeclareLaunchArgument(
            'depth_filename_prefix',
            default_value='depth',
            description='Prefix for saved depth image filenames.',
        ),
        DeclareLaunchArgument(
            'pointcloud_filename_prefix',
            default_value='cloud',
            description='Prefix for saved point cloud filenames.',
        ),

        # ---------------------------------------------------------------------
        # 7. 连续采图节点的自动保存参数。
        #
        # auto_save:=true 表示启动后不需要按键，自动按 interval_sec 周期
        # 保存彩色图。这个模式最适合给别人采 YOLO 训练数据。
        # image_format 支持 jpg/jpeg/png；jpg 时 jpeg_quality 生效。
        # ---------------------------------------------------------------------
        DeclareLaunchArgument(
            'auto_save',
            default_value='true',
            description='Automatically save color images.',
        ),
        DeclareLaunchArgument(
            'interval_sec',
            default_value='0.5',
            description='Seconds between automatically saved color images.',
        ),
        DeclareLaunchArgument(
            'image_format',
            default_value='jpg',
            description='Saved color image format: jpg, jpeg, or png.',
        ),
        DeclareLaunchArgument(
            'jpeg_quality',
            default_value='95',
            description='JPEG quality from 0 to 100.',
        ),
        DeclareLaunchArgument(
            'png_compression',
            default_value='3',
            description='PNG compression from 0 to 9.',
        ),

        # ---------------------------------------------------------------------
        # 8. 启动 RealSense 驱动。
        #
        # IncludeLaunchDescription 表示“把另一个 launch 文件包含进来运行”。
        # condition=IfCondition(...) 表示只有 use_camera 为 true 时才启动。
        # ---------------------------------------------------------------------
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(camera_launch),
            launch_arguments={
                'camera_config': LaunchConfiguration('camera_config'),
                'camera_name': LaunchConfiguration('camera_name'),
                'camera_namespace': LaunchConfiguration('camera_namespace'),
                'serial_no': LaunchConfiguration('serial_no'),
                'usb_port_id': LaunchConfiguration('usb_port_id'),
                'device_type': LaunchConfiguration('device_type'),
                'json_file_path': LaunchConfiguration('json_file_path'),
                'initial_reset': LaunchConfiguration('initial_reset'),
                'log_level': LaunchConfiguration('log_level'),
                'output': LaunchConfiguration('output'),
            }.items(),
            condition=IfCondition(LaunchConfiguration('use_camera')),
        ),

        # ---------------------------------------------------------------------
        # 9. 启动连续采图节点。
        #
        # Node 表示启动一个 ROS2 可执行程序：
        # package='yolo_cpp' 对应 src/yolo_cpp 这个包；
        # executable='image_capture_node' 对应 CMakeLists.txt 里安装的可执行文件。
        #
        # ParameterValue 用来把 launch 传进来的字符串显式转换成 bool/double/int，
        # 避免 auto_save、interval_sec 这类参数被当成普通字符串。
        # ---------------------------------------------------------------------
        Node(
            package='yolo_cpp',
            executable='image_capture_node',
            name='yolo_dataset_image_capture_node',
            output=LaunchConfiguration('output'),
            parameters=[{
                'color_topic': LaunchConfiguration('color_topic'),
                'depth_topic': LaunchConfiguration('depth_topic'),
                'pointcloud_topic': LaunchConfiguration('pointcloud_topic'),
                'save_directory': LaunchConfiguration('save_directory'),
                'depth_save_directory': LaunchConfiguration('depth_save_directory'),
                'pointcloud_save_directory': LaunchConfiguration('pointcloud_save_directory'),
                'auto_save': ParameterValue(
                    LaunchConfiguration('auto_save'),
                    value_type=bool,
                ),
                'interval_sec': ParameterValue(
                    LaunchConfiguration('interval_sec'),
                    value_type=float,
                ),
                'image_format': LaunchConfiguration('image_format'),
                'filename_prefix': LaunchConfiguration('filename_prefix'),
                'depth_filename_prefix': LaunchConfiguration('depth_filename_prefix'),
                'pointcloud_filename_prefix': LaunchConfiguration('pointcloud_filename_prefix'),
                'jpeg_quality': ParameterValue(
                    LaunchConfiguration('jpeg_quality'),
                    value_type=int,
                ),
                'png_compression': ParameterValue(
                    LaunchConfiguration('png_compression'),
                    value_type=int,
                ),
            }],
            condition=IfCondition(LaunchConfiguration('use_capture')),
        ),
    ])
