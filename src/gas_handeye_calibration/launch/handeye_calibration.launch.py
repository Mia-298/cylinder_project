from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    default_config = PathJoinSubstitution([
        FindPackageShare('gas_handeye_calibration'),
        'config',
        'handeye_calibration.yaml',
    ])
    default_save_root_dir = 'calibration_data/handeye'

    return LaunchDescription([
        DeclareLaunchArgument(
            'params_file',
            default_value=default_config,
            description='Parameter file for hand-eye calibration.',
        ),
        DeclareLaunchArgument(
            'save_root_dir',
            default_value=default_save_root_dir,
            description='Root directory used to store hand-eye sessions.',
        ),
        Node(
            package='gas_handeye_calibration',
            executable='handeye_calibration_node',
            name='handeye_calibration_node',
            output='screen',
            parameters=[
                LaunchConfiguration('params_file'),
                {
                    'save_root_dir': LaunchConfiguration('save_root_dir'),
                },
            ],
        ),
    ])
