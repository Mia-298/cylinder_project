import glob
import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription, TimerAction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def _latest_handeye_result_file():
    pattern = os.path.join(
        'calibration_data',
        'handeye',
        '*',
        'results',
        'handeye_result.yaml',
    )
    candidates = glob.glob(pattern)
    if not candidates:
        return ''
    return max(candidates, key=os.path.getmtime)


def generate_launch_description():
    perception_launch = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'launch',
        'perception.launch.py',
    ])
    default_robot_config = PathJoinSubstitution([
        FindPackageShare('gas_robot_control'),
        'config',
        'aubo_control.yaml',
    ])
    grasp_config = PathJoinSubstitution([
        FindPackageShare('gas_grasp_execution'),
        'config',
        'grasp_execution.yaml',
    ])

    return LaunchDescription([
        DeclareLaunchArgument(
            'handeye_result_file',
            default_value=_latest_handeye_result_file(),
            description='Hand-eye result YAML. Defaults to the newest result under calibration_data/handeye.',
        ),
        DeclareLaunchArgument(
            'robot_config',
            default_value=default_robot_config,
            description='YAML file passed to the AUBO robot control node.',
        ),
        DeclareLaunchArgument(
            'execute_once',
            default_value='false',
            description='Call /grasp/execute_once after startup.',
        ),
        DeclareLaunchArgument(
            'execute_delay_sec',
            default_value='8.0',
            description='Delay before execute_once service call.',
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(perception_launch),
        ),
        Node(
            package='gas_robot_control',
            executable='aubo_robot_control_node',
            name='aubo_robot_control_node',
            output='screen',
            parameters=[
                LaunchConfiguration('robot_config'),
                {
                    'auto_connect': True,
                    'auto_enable': True,
                    'auto_handguide': False,
                },
            ],
        ),
        Node(
            package='gas_grasp_execution',
            executable='gas_grasp_execution_node',
            name='gas_grasp_execution_node',
            output='screen',
            parameters=[
                grasp_config,
                {
                    'handeye_result_file': LaunchConfiguration('handeye_result_file'),
                },
            ],
        ),
        TimerAction(
            period=LaunchConfiguration('execute_delay_sec'),
            actions=[
                ExecuteProcess(
                    cmd=[
                        'ros2',
                        'service',
                        'call',
                        '/grasp/execute_once',
                        'gas_interfaces/srv/GraspExecute',
                        '{wait: true, publish_debug_image: true, approach_offset_m: 0.10}',
                    ],
                    output='screen',
                ),
            ],
            condition=IfCondition(LaunchConfiguration('execute_once')),
        ),
    ])
