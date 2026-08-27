from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    default_config = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'config',
        'orbbec_camera.yaml',
    ])
    orbbec_launch = PathJoinSubstitution([
        FindPackageShare('orbbec_camera'),
        'launch',
        'gemini_330_series.launch.py',
    ])

    return LaunchDescription([
        DeclareLaunchArgument(
            'camera_config',
            default_value=default_config,
            description='YAML file passed to the Orbbec camera driver.',
        ),
        DeclareLaunchArgument('depth_registration', default_value='false'),
        DeclareLaunchArgument('enable_point_cloud', default_value='false'),
        DeclareLaunchArgument('enable_colored_point_cloud', default_value='false'),
        DeclareLaunchArgument('enable_d2c_viewer', default_value='false'),
        DeclareLaunchArgument('enable_depth', default_value='true'),
        DeclareLaunchArgument('enable_left_ir', default_value='false'),
        DeclareLaunchArgument('enable_right_ir', default_value='false'),
        DeclareLaunchArgument('enable_frame_sync', default_value='false'),
        DeclareLaunchArgument('enable_depth_scale', default_value='true'),
        DeclareLaunchArgument('enable_sync_output_accel_gyro', default_value='false'),
        DeclareLaunchArgument('enable_accel', default_value='false'),
        DeclareLaunchArgument('enable_gyro', default_value='false'),
        DeclareLaunchArgument('enable_laser', default_value='true'),
        DeclareLaunchArgument('align_mode', default_value='SW'),
        DeclareLaunchArgument('frame_aggregate_mode', default_value='ANY'),
        DeclareLaunchArgument('ordered_pc', default_value='false'),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(orbbec_launch),
            launch_arguments={
                'config_file_path': LaunchConfiguration('camera_config'),
                'depth_registration': LaunchConfiguration('depth_registration'),
                'enable_point_cloud': LaunchConfiguration('enable_point_cloud'),
                'enable_colored_point_cloud': LaunchConfiguration('enable_colored_point_cloud'),
                'enable_d2c_viewer': LaunchConfiguration('enable_d2c_viewer'),
                'enable_depth': LaunchConfiguration('enable_depth'),
                'enable_left_ir': LaunchConfiguration('enable_left_ir'),
                'enable_right_ir': LaunchConfiguration('enable_right_ir'),
                'enable_frame_sync': LaunchConfiguration('enable_frame_sync'),
                'enable_depth_scale': LaunchConfiguration('enable_depth_scale'),
                'enable_sync_output_accel_gyro': LaunchConfiguration('enable_sync_output_accel_gyro'),
                'enable_accel': LaunchConfiguration('enable_accel'),
                'enable_gyro': LaunchConfiguration('enable_gyro'),
                'enable_laser': LaunchConfiguration('enable_laser'),
                'align_mode': LaunchConfiguration('align_mode'),
                'frame_aggregate_mode': LaunchConfiguration('frame_aggregate_mode'),
                'ordered_pc': LaunchConfiguration('ordered_pc'),
                'color.image_raw.enable_pub_plugins': '["image_transport/raw"]',
                'depth.image_raw.enable_pub_plugins': '["image_transport/raw"]',
                'left_ir.image_raw.enable_pub_plugins': '["image_transport/raw"]',
                'right_ir.image_raw.enable_pub_plugins': '["image_transport/raw"]',
            }.items(),
        ),
    ])
