from pathlib import Path

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def _latest_handeye_result():
    root = Path("calibration_data") / "handeye"
    candidates = sorted(root.glob("*/results/handeye_result.yaml"))
    return str(candidates[-1]) if candidates else ""


def generate_launch_description():
    camera_launch = PathJoinSubstitution([
        FindPackageShare("gas_bringup"),
        "launch",
        "camera.launch.py",
    ])
    robot_launch = PathJoinSubstitution([
        FindPackageShare("gas_robot_control"),
        "launch",
        "aubo_control.launch.py",
    ])
    default_camera_config = PathJoinSubstitution([
        FindPackageShare("gas_bringup"),
        "config",
        "realsense_handeye_camera.yaml",
    ])
    default_robot_config = PathJoinSubstitution([
        FindPackageShare("gas_robot_control"),
        "config",
        "aubo_control_collect.yaml",
    ])
    default_params = PathJoinSubstitution([
        FindPackageShare("gas_handeye_validation"),
        "config",
        "handeye_validation.yaml",
    ])
    default_save_root_dir = "calibration_data/handeye_validation"
    default_handeye_result = _latest_handeye_result()

    return LaunchDescription([
        DeclareLaunchArgument(
            "use_camera",
            default_value="true",
            description="Start the RealSense camera driver.",
        ),
        DeclareLaunchArgument(
            "use_robot",
            default_value="true",
            description="Start the AUBO robot control node.",
        ),
        DeclareLaunchArgument(
            "use_gui",
            default_value="true",
            description="Start the validation GUI.",
        ),
        DeclareLaunchArgument(
            "camera_config",
            default_value=default_camera_config,
            description="YAML file passed to the RealSense camera driver.",
        ),
        DeclareLaunchArgument(
            "robot_config",
            default_value=default_robot_config,
            description="YAML file passed to the AUBO robot control node.",
        ),
        DeclareLaunchArgument(
            "params_file",
            default_value=default_params,
            description="YAML file passed to the validation GUI.",
        ),
        DeclareLaunchArgument(
            "handeye_result_file",
            default_value=default_handeye_result,
            description="Existing hand-eye result yaml to validate.",
        ),
        DeclareLaunchArgument(
            "save_root_dir",
            default_value=default_save_root_dir,
            description="Root directory used to store validation sessions.",
        ),
        DeclareLaunchArgument(
            "min_charuco_corners",
            default_value="12",
            description="Reject validation samples with fewer Charuco corners.",
        ),
        DeclareLaunchArgument(
            "min_validation_samples",
            default_value="8",
            description="Recommended minimum validation sample count.",
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(camera_launch),
            launch_arguments={
                "camera_config": LaunchConfiguration("camera_config"),
            }.items(),
            condition=IfCondition(LaunchConfiguration("use_camera")),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(robot_launch),
            launch_arguments={
                "config": LaunchConfiguration("robot_config"),
            }.items(),
            condition=IfCondition(LaunchConfiguration("use_robot")),
        ),
        Node(
            package="gas_handeye_validation",
            executable="handeye_validation_ui.py",
            name="handeye_validation_ui",
            output="screen",
            parameters=[
                LaunchConfiguration("params_file"),
                {
                    "handeye_result_file": LaunchConfiguration("handeye_result_file"),
                    "save_root_dir": LaunchConfiguration("save_root_dir"),
                    "min_charuco_corners": LaunchConfiguration("min_charuco_corners"),
                    "min_validation_samples": LaunchConfiguration("min_validation_samples"),
                },
            ],
            condition=IfCondition(LaunchConfiguration("use_gui")),
        ),
    ])
