from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    perception_launch = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'launch',
        'perception.launch.py',
    ])
    default_camera_config = PathJoinSubstitution([
        FindPackageShare('gas_bringup'),
        'config',
        'orbbec_camera.yaml',
    ])
    default_yolo_model_path = PathJoinSubstitution([
        FindPackageShare('yolo_cpp'),
        'models',
        'best.onnx',
    ])

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_camera',
            default_value='true',
            description='Start the Orbbec camera driver.',
        ),
        DeclareLaunchArgument(
            'use_yolo',
            default_value='true',
            description='Start the YOLO ONNX detector.',
        ),
        DeclareLaunchArgument(
            'camera_config',
            default_value=default_camera_config,
            description='YAML file passed to the Orbbec camera driver.',
        ),
        DeclareLaunchArgument(
            'model_path',
            default_value=default_yolo_model_path,
            description='Path to the YOLO ONNX model.',
        ),
        DeclareLaunchArgument(
            'image_topic',
            default_value='/camera/color/image_raw',
            description='Input color image topic for YOLO.',
        ),
        DeclareLaunchArgument(
            'point_cloud_topic',
            default_value='/camera/depth/points',
            description='Input point cloud topic for yolo_cpp sphere fitting.',
        ),
        DeclareLaunchArgument(
            'sphere_target_class',
            default_value='class_0',
            description='Class name used by yolo_cpp for sphere fitting.',
        ),
        DeclareLaunchArgument(
            'capture_interval_sec',
            default_value='0.5',
            description='Seconds between yolo_cpp capture cycles.',
        ),
        DeclareLaunchArgument(
            'service_name',
            default_value='/yolo/detect_once',
            description='Service used to trigger one-shot YOLO detection.',
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(perception_launch),
            launch_arguments={
                'use_camera': LaunchConfiguration('use_camera'),
                'use_yolo': LaunchConfiguration('use_yolo'),
                'camera_config': LaunchConfiguration('camera_config'),
                'model_path': LaunchConfiguration('model_path'),
                'image_topic': LaunchConfiguration('image_topic'),
                'point_cloud_topic': LaunchConfiguration('point_cloud_topic'),
                'sphere_target_class': LaunchConfiguration('sphere_target_class'),
                'capture_interval_sec': LaunchConfiguration('capture_interval_sec'),
                'service_name': LaunchConfiguration('service_name'),
            }.items(),
        ),
    ])
