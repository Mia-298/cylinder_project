from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    default_config = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'config',
        'realsense_camera.yaml',
    ])
    realsense_launch = PathJoinSubstitution([
        FindPackageShare('realsense2_camera'),
        'launch',
        'rs_launch.py',
    ])

    return LaunchDescription([
        DeclareLaunchArgument(
            'camera_config',
            default_value=default_config,
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
            description='ROS log level for the camera node.',
        ),
        DeclareLaunchArgument(
            'output',
            default_value='screen',
            description='Node output destination.',
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(realsense_launch),
            launch_arguments={
                'config_file': LaunchConfiguration('camera_config'),
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
        ),
    ])
