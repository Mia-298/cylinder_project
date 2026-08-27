from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


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
        'orbbec_handeye_camera.yaml',
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
            description='Start the Orbbec camera driver.',
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
            description='YAML file passed to the Orbbec camera driver.',
        ),
        DeclareLaunchArgument(
            'robot_config',
            default_value=default_robot_config,
            description='YAML file passed to the AUBO robot control node.',
        ),
        DeclareLaunchArgument(
            'handeye_params',
            default_value=default_handeye_params,
            description='YAML file passed to the hand-eye backend.',
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
                'depth_registration': 'false',
                'enable_point_cloud': 'false',
                'enable_colored_point_cloud': 'false',
                'enable_d2c_viewer': 'false',
                'enable_depth': 'false',
                'enable_left_ir': 'false',
                'enable_right_ir': 'false',
                'enable_frame_sync': 'false',
                'enable_depth_scale': 'false',
                'enable_sync_output_accel_gyro': 'false',
                'enable_accel': 'false',
                'enable_gyro': 'false',
                'enable_laser': 'false',
                'align_mode': 'SW',
                'frame_aggregate_mode': 'color_frame',
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
        Node(
            package='gas_handeye_calibration',
            executable='handeye_capture_ui.py',
            name='handeye_capture_ui',
            output='screen',
            parameters=[{
                'image_topic': '/camera/color/image_raw',
                'camera_info_topic': '/camera/color/camera_info',
                'add_sample_service': '/handeye/add_sample',
                'clear_samples_service': '/handeye/clear_samples',
                'compute_service': '/handeye/compute',
                'status_service': '/handeye/status',
                'handguide_service': '/robot/handguide',
                'board_dictionary_id': 7,
                'board_squares_x': 10,
                'board_squares_y': 7,
                'board_square_length_m': 0.025,
                'board_marker_length_m': 0.018,
                'display_charuco_corner_limit': 12,
                'display_width': 1280,
                'display_height': 960,
            }],
            condition=IfCondition(LaunchConfiguration('use_gui')),
        ),
    ])
