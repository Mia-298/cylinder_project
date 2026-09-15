from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    default_config = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'config',
        'orbbec_gemini_330.yaml',
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
            description='YAML file passed to the Orbbec Gemini 330 driver.',
        ),
        DeclareLaunchArgument(
            'camera_name',
            default_value='camera',
            description='Orbbec camera namespace and node name.',
        ),
        DeclareLaunchArgument(
            'camera_namespace',
            default_value='',
            description='Compatibility namespace argument; camera_name controls the namespace.',
        ),
        DeclareLaunchArgument(
            'serial_no',
            default_value='',
            description='Choose an Orbbec device by serial number.',
        ),
        DeclareLaunchArgument(
            'usb_port_id',
            default_value='',
            description='Choose an Orbbec device by USB port id.',
        ),
        DeclareLaunchArgument(
            'device_type',
            default_value='',
            description='Orbbec device type selector.',
        ),
        DeclareLaunchArgument(
            'json_file_path',
            default_value='',
            description='Optional Orbbec SDK configuration JSON file.',
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
            PythonLaunchDescriptionSource(orbbec_launch),
            launch_arguments={
                'config_file_path': LaunchConfiguration('camera_config'),
                'camera_name': LaunchConfiguration('camera_name'),
                'serial_number': LaunchConfiguration('serial_no'),
                'usb_port': LaunchConfiguration('usb_port_id'),
                'device_type': LaunchConfiguration('device_type'),
                'load_config_json_file_path': LaunchConfiguration('json_file_path'),
                'log_level': LaunchConfiguration('log_level'),
            }.items(),
        ),
    ])
