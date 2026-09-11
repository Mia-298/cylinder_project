import glob
import os

from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    ExecuteProcess,
    IncludeLaunchDescription,
    OpaqueFunction,
    TimerAction,
)
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


def _execute_once(context):
    close_gripper = LaunchConfiguration('close_gripper').perform(context).lower() == 'true'
    activate_gripper = close_gripper
    request = (
        '{wait: true, publish_debug_image: true, approach_offset_m: 0.20, '
        f'close_gripper: {str(close_gripper).lower()}, '
        f'activate_gripper: {str(activate_gripper).lower()}, '
        'gripper_index: 0, '
        f"gripper_position: {LaunchConfiguration('gripper_position').perform(context)}, "
        f"gripper_velocity: {LaunchConfiguration('gripper_velocity').perform(context)}, "
        f"gripper_force: {LaunchConfiguration('gripper_force').perform(context)}, "
        f"gripper_max_time_ms: {LaunchConfiguration('gripper_max_time_ms').perform(context)}, "
        'gripper_wait: true}'
    )
    return [
        ExecuteProcess(
            cmd=[
                'ros2',
                'service',
                'call',
                '/grasp/execute_once',
                'gas_interfaces/srv/GraspExecute',
                request,
            ],
            output='screen',
        ),
    ]


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
        DeclareLaunchArgument(
            'close_gripper',
            default_value='false',
            description='Close the HyRMS gripper after reaching the pre-grasp point.',
        ),
        DeclareLaunchArgument(
            'gripper_position',
            default_value='70',
            description='Gripper position percentage mapped to an RmCeu preset point.',
        ),
        DeclareLaunchArgument(
            'gripper_velocity',
            default_value='30',
            description='Compatibility field; RmCeu Proxy does not use velocity.',
        ),
        DeclareLaunchArgument(
            'gripper_force',
            default_value='30',
            description='Compatibility field; RmCeu Proxy does not use force.',
        ),
        DeclareLaunchArgument(
            'gripper_max_time_ms',
            default_value='3000',
            description='Compatibility field; RmCeu goPoint is blocking.',
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(perception_launch),
            launch_arguments={
                'handeye_result_file': LaunchConfiguration('handeye_result_file'),
            }.items(),
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
            parameters=[grasp_config],
        ),
        TimerAction(
            period=LaunchConfiguration('execute_delay_sec'),
            actions=[OpaqueFunction(function=_execute_once)],
            condition=IfCondition(LaunchConfiguration('execute_once')),
        ),
    ])
