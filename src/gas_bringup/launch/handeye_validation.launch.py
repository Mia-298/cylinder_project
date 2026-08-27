from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    validation_launch = PathJoinSubstitution([
        FindPackageShare("gas_handeye_validation"),
        "launch",
        "handeye_validation.launch.py",
    ])

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(validation_launch),
        ),
    ])
