import yaml

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, OpaqueFunction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def _launch_capture_ui(context):
    params_file = LaunchConfiguration('handeye_params').perform(context)
    with open(params_file, encoding='utf-8') as stream:
        calibration_params = yaml.safe_load(stream)['handeye_calibration_node']['ros__parameters']
    board_params = {
        key: value for key, value in calibration_params.items()
        if key.startswith('board_') or key in (
            'image_topic', 'camera_info_topic', 'min_charuco_corners')
    }
    service_namespace = calibration_params.get('service_namespace', '/handeye').rstrip('/')
    return [Node(
        package='gas_handeye_calibration',
        executable='handeye_capture_ui.py',
        name='handeye_capture_ui',
        output='screen',
        parameters=[{
            'add_sample_service': service_namespace + '/add_sample',
            'clear_samples_service': service_namespace + '/clear_samples',
            'compute_service': service_namespace + '/compute',
            'status_service': service_namespace + '/status',
            'handguide_service': '/robot/handguide',
            'display_charuco_corner_limit': 12,
            'display_width': 1280,
            'display_height': 960,
        }, board_params],
    )]


def generate_launch_description():
    camera_launch = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'launch',
        'camera.launch.py',
    ])
    robot_launch = PathJoinSubstitution([
        FindPackageShare('gas_robot_control'),
        'launch',
        'aubo_control.launch.py',
    ])
    handeye_launch = PathJoinSubstitution([
        FindPackageShare('gas_handeye_calibration'),
        'launch',
        'handeye_calibration.launch.py',
    ])
    default_camera_config = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'config',
        'realsense_handeye_camera.yaml',
    ])
    default_robot_config = PathJoinSubstitution([
        FindPackageShare('gas_robot_control'),
        'config',
        'aubo_control_collect.yaml',
    ])
    default_save_root_dir = 'calibration_data/handeye'
    default_handeye_params = PathJoinSubstitution([
        FindPackageShare('gas_handeye_calibration'),
        'config',
        'handeye_calibration.yaml',
    ])

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_camera',
            default_value='true',
            description='Start the RealSense camera driver.',
        ),
        DeclareLaunchArgument(
            'use_robot',
            default_value='true',
            description='Start the AUBO robot control node.',
        ),
        DeclareLaunchArgument(
            'use_handeye',
            default_value='true',
            description='Start the hand-eye calibration backend.',
        ),
        DeclareLaunchArgument(
            'use_gui',
            default_value='true',
            description='Start the hand-eye capture GUI.',
        ),
        DeclareLaunchArgument(
            'camera_config',
            default_value=default_camera_config,
            description='YAML file passed to the RealSense camera driver.',
        ),
        DeclareLaunchArgument(
            'robot_config',
            default_value=default_robot_config,
            description='YAML file passed to the AUBO robot control node.',
        ),
        DeclareLaunchArgument(
            'handeye_params',
            default_value=default_handeye_params,
            description='YAML file shared by the hand-eye backend and capture GUI.',
        ),
        DeclareLaunchArgument(
            'save_root_dir',
            default_value=default_save_root_dir,
            description='Root directory used to store hand-eye sessions.',
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(camera_launch),
            launch_arguments={
                'camera_config': LaunchConfiguration('camera_config'),
            }.items(),
            condition=IfCondition(LaunchConfiguration('use_camera')),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(robot_launch),
            launch_arguments={
                'config': LaunchConfiguration('robot_config'),
            }.items(),
            condition=IfCondition(LaunchConfiguration('use_robot')),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(handeye_launch),
            launch_arguments={
                'params_file': LaunchConfiguration('handeye_params'),
                'save_root_dir': LaunchConfiguration('save_root_dir'),
            }.items(),
            condition=IfCondition(LaunchConfiguration('use_handeye')),
        ),
        OpaqueFunction(
            function=_launch_capture_ui,
            condition=IfCondition(LaunchConfiguration('use_gui')),
        ),
    ])
