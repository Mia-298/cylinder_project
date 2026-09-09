from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    default_config = PathJoinSubstitution([
        FindPackageShare('gas_grasp_execution'),
        'config',
        'grasp_execution.yaml',
    ])

    return LaunchDescription([
        DeclareLaunchArgument(
            'config_file',
            default_value=default_config,
            description='YAML file passed to the grasp execution node.',
        ),
        Node(
            package='gas_grasp_execution',
            executable='gas_grasp_execution_node',
            name='gas_grasp_execution_node',
            output='screen',
            parameters=[LaunchConfiguration('config_file')],
        ),
    ])
