from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node

from ament_index_python.packages import get_package_share_directory

import os


def generate_launch_description():

    # Orbbec 相机 launch 文件
    orbbec_launch = os.path.join(
        get_package_share_directory("orbbec_camera"),
        "launch",
        "gemini_330_series.launch.py"
    )

    camera = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(orbbec_launch)
        # launch_arguments={
        #     "depth_registration": "true",

        #     "enable_point_cloud": "true",
        #     "enable_colored_point_cloud": "true",
        #     "ordered_pc": "true",

        #     "align_mode": "SW",
        #     "align_target_stream": "COLOR",

        #     "device_preset": "High Density",

        #     "enable_spatial_filter": "true",
        #     "spatial_filter_alpha": "0.5",
        #     "spatial_filter_diff_threshold": "160",
        #     "spatial_filter_magnitude": "2",
        #     "spatial_filter_radius": "2",

        #     "enable_temporal_filter": "false",
        #     "enable_hole_filling_filter": "false",
        # }.items()
    )

    # YOLO + 点云球拟合视觉节点
    vision = Node(
        package="yolo_cpp",
        executable="yolo_detect_node",
        name="yolo_detect_node",
        output="screen",
        parameters=[
            {
                "image_topic":
                    "/camera/color/image_raw",

                "point_cloud_topic":
                    "/camera/depth_registered/points",

                "sphere_target_class":
                    "class_0",

                "capture_interval_sec":
                    0.5,
            }
        ]
    )

    return LaunchDescription([
        camera,
        vision,
    ])