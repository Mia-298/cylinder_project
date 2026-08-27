#!/usr/bin/env python3
"""Automatic 9-point gas-can visual distance sampling demo.

The script:
1. reads the fitted sphere center from /yolo/detect_once;
2. converts it to the robot base frame using the current TCP pose and hand-eye result;
3. creates 9 horizontal camera viewpoints around the sphere;
4. moves the robot through those points with /robot/move_l;
5. records 100 valid fitted-sphere distance samples at every point.

The default target distance means camera-origin-to-sphere-center distance, not
TCP-to-sphere-center distance.
"""

from __future__ import annotations

import argparse
import glob
import math
import statistics
import sys
import time
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Iterable, List, Optional, Sequence, Tuple

import cv2
import numpy as np
import rclpy
from rclpy.node import Node

from gas_interfaces.srv import DetectObjects, HandEyeGetStatus, RobotGetPose, RobotMoveL


ANGLE_LABELS = [
    ("center", 0.0, "中心"),
    ("left30", 30.0, "左侧水平 30 deg"),
    ("right30", -30.0, "右侧水平 30 deg"),
]


@dataclass
class DetectionSample:
    valid: bool
    center_camera_m: np.ndarray
    distance_m: float
    depth_z_m: float
    radius_m: float
    confidence: float
    class_id: str
    frame_id: str
    message: str


@dataclass
class PlannedPoint:
    index: int
    range_label: str
    angle_label: str
    description: str
    desired_distance_m: float
    horizontal_angle_deg: float
    target_camera_base_m: np.ndarray
    target_tcp_pose: np.ndarray


def default_desktop_path() -> Path:
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    return Path.home() / "Desktop" / f"gas_auto_9point_distance_samples_{timestamp}.txt"


def format_float(value: float) -> str:
    if not math.isfinite(float(value)):
        return "nan"
    return f"{float(value):.9f}"


def matrix_is_valid_homogeneous(matrix: np.ndarray) -> bool:
    if matrix.shape != (4, 4):
        return False
    if not np.all(np.isfinite(matrix)):
        return False
    if not np.allclose(matrix[3, :], np.array([0.0, 0.0, 0.0, 1.0]), atol=1e-6):
        return False
    return True


def rpy_to_rotation_matrix(rx: float, ry: float, rz: float) -> np.ndarray:
    cx, sx = math.cos(rx), math.sin(rx)
    cy, sy = math.cos(ry), math.sin(ry)
    cz, sz = math.cos(rz), math.sin(rz)

    rx_mat = np.array([
        [1.0, 0.0, 0.0],
        [0.0, cx, -sx],
        [0.0, sx, cx],
    ])
    ry_mat = np.array([
        [cy, 0.0, sy],
        [0.0, 1.0, 0.0],
        [-sy, 0.0, cy],
    ])
    rz_mat = np.array([
        [cz, -sz, 0.0],
        [sz, cz, 0.0],
        [0.0, 0.0, 1.0],
    ])
    return rz_mat @ ry_mat @ rx_mat


def rotation_matrix_to_rpy(rotation: np.ndarray) -> Tuple[float, float, float]:
    sy = -float(rotation[2, 0])
    sy = min(1.0, max(-1.0, sy))
    ry = math.asin(sy)
    cy = math.cos(ry)

    if abs(cy) > 1e-9:
        rx = math.atan2(float(rotation[2, 1]), float(rotation[2, 2]))
        rz = math.atan2(float(rotation[1, 0]), float(rotation[0, 0]))
    else:
        rx = 0.0
        rz = math.atan2(-float(rotation[0, 1]), float(rotation[1, 1]))
    return rx, ry, rz


def make_transform(rotation: np.ndarray, translation: np.ndarray) -> np.ndarray:
    transform = np.eye(4, dtype=np.float64)
    transform[:3, :3] = rotation
    transform[:3, 3] = translation.reshape(3)
    return transform


def transform_point(transform: np.ndarray, point_xyz: np.ndarray) -> np.ndarray:
    point_h = np.array([point_xyz[0], point_xyz[1], point_xyz[2], 1.0], dtype=np.float64)
    return (transform @ point_h)[:3]


def rotate_xy(vector_xy: np.ndarray, angle_deg: float) -> np.ndarray:
    angle_rad = math.radians(angle_deg)
    c, s = math.cos(angle_rad), math.sin(angle_rad)
    return np.array([
        c * vector_xy[0] - s * vector_xy[1],
        s * vector_xy[0] + c * vector_xy[1],
    ], dtype=np.float64)


def read_opencv_matrix(storage: cv2.FileStorage, key: str) -> np.ndarray:
    node = storage.getNode(key)
    if node.empty():
        return np.empty((0, 0), dtype=np.float64)
    matrix = node.mat()
    if matrix is None:
        return np.empty((0, 0), dtype=np.float64)
    return np.asarray(matrix, dtype=np.float64)


def load_tool_camera_matrix(result_file: Path) -> np.ndarray:
    storage = cv2.FileStorage(str(result_file), cv2.FILE_STORAGE_READ)
    if not storage.isOpened():
        raise RuntimeError(f"failed to open hand-eye result file: {result_file}")
    try:
        tool_camera = read_opencv_matrix(storage, "tool_camera_matrix")
        if tool_camera.size == 0:
            camera_tool = read_opencv_matrix(storage, "camera_tool_matrix")
            if camera_tool.size == 0:
                raise RuntimeError("hand-eye result file does not contain tool_camera_matrix")
            if not matrix_is_valid_homogeneous(camera_tool):
                raise RuntimeError("camera_tool_matrix is not a valid 4x4 matrix")
            tool_camera = np.linalg.inv(camera_tool)

        if not matrix_is_valid_homogeneous(tool_camera):
            raise RuntimeError("tool_camera_matrix is not a valid 4x4 matrix")
        return tool_camera
    finally:
        storage.release()


def latest_handeye_result_file(workspace_dir: Path) -> Optional[Path]:
    pattern = str(workspace_dir / "calibration_data" / "handeye" / "*" / "results" / "handeye_result.yaml")
    candidates = [Path(path) for path in glob.glob(pattern)]
    candidates = [path for path in candidates if path.exists()]
    if not candidates:
        return None
    return max(candidates, key=lambda path: path.stat().st_mtime)


class AutoSamplerClient(Node):
    def __init__(self, args: argparse.Namespace) -> None:
        super().__init__("gas_auto_9point_distance_test")
        self.args = args
        self.yolo_client = self.create_client(DetectObjects, args.yolo_service)
        self.robot_pose_client = self.create_client(RobotGetPose, args.robot_pose_service)
        self.robot_move_l_client = self.create_client(RobotMoveL, args.robot_move_l_service)
        self.handeye_status_client = self.create_client(HandEyeGetStatus, args.handeye_status_service)

    def wait_for_services(self) -> None:
        for name, client in [
            (self.args.yolo_service, self.yolo_client),
            (self.args.robot_pose_service, self.robot_pose_client),
            (self.args.robot_move_l_service, self.robot_move_l_client),
        ]:
            print(f"[INFO] waiting for service: {name}")
            if not client.wait_for_service(timeout_sec=self.args.timeout):
                raise RuntimeError(f"service not available: {name}")
            print(f"[OK] service ready: {name}")

    def get_robot_pose(self) -> Tuple[np.ndarray, np.ndarray]:
        response = self._call_service(
            self.robot_pose_client,
            RobotGetPose.Request(),
            self.args.robot_pose_service,
            self.args.timeout,
        )
        if not response.success:
            raise RuntimeError(f"robot pose failed: {response.message}")

        tcp_pose = np.array([float(v) for v in response.tcp_xyz_m_rpy_rad], dtype=np.float64)
        joint_pose = np.array([float(v) for v in response.joint_rad], dtype=np.float64)
        if tcp_pose.shape[0] != 6:
            raise RuntimeError("robot pose response does not contain 6 TCP values")
        return tcp_pose, joint_pose

    def move_l(self, target_tcp_pose: np.ndarray, wait: bool) -> str:
        request = RobotMoveL.Request()
        for i in range(6):
            request.tcp_xyz_m_rpy_rad[i] = float(target_tcp_pose[i])
        request.wait = wait
        response = self._call_service(
            self.robot_move_l_client,
            request,
            self.args.robot_move_l_service,
            self.args.move_timeout,
        )
        if not response.success:
            raise RuntimeError(f"MoveL failed: {response.message}")
        return response.message

    def detect_once(self, publish_debug_image: bool) -> DetectionSample:
        request = DetectObjects.Request()
        request.publish_debug_image = publish_debug_image
        response = self._call_service(
            self.yolo_client,
            request,
            self.args.yolo_service,
            self.args.timeout,
        )
        if not response.success:
            return DetectionSample(
                False,
                np.array([math.nan, math.nan, math.nan], dtype=np.float64),
                math.nan,
                math.nan,
                math.nan,
                math.nan,
                "",
                "",
                response.message,
            )
        if not response.has_sphere_center:
            return DetectionSample(
                False,
                np.array([math.nan, math.nan, math.nan], dtype=np.float64),
                math.nan,
                math.nan,
                math.nan,
                float(response.sphere_confidence),
                response.sphere_class_id,
                response.sphere_frame_id,
                "no fitted sphere center",
            )

        center = np.array([float(v) for v in response.sphere_center_m], dtype=np.float64)
        if not np.all(np.isfinite(center)):
            return DetectionSample(
                False,
                center,
                math.nan,
                math.nan,
                float(response.sphere_radius_m),
                float(response.sphere_confidence),
                response.sphere_class_id,
                response.sphere_frame_id,
                "invalid fitted sphere center",
            )

        return DetectionSample(
            True,
            center,
            float(np.linalg.norm(center)),
            float(center[2]),
            float(response.sphere_radius_m),
            float(response.sphere_confidence),
            response.sphere_class_id,
            response.sphere_frame_id,
            response.message,
        )

    def resolve_handeye_result_file(self) -> Path:
        if self.args.handeye_result_file:
            path = Path(self.args.handeye_result_file).expanduser()
            if not path.exists():
                raise RuntimeError(f"hand-eye result file not found: {path}")
            return path

        latest_local = latest_handeye_result_file(Path.cwd())
        if latest_local is not None:
            print(f"[OK] using latest local hand-eye result: {latest_local}")
            return latest_local

        print(f"[INFO] waiting for service: {self.args.handeye_status_service}")
        if not self.handeye_status_client.wait_for_service(timeout_sec=self.args.timeout):
            raise RuntimeError(
                "no local hand-eye result under calibration_data/handeye and "
                f"service not available: {self.args.handeye_status_service}"
            )
        print(f"[OK] service ready: {self.args.handeye_status_service}")

        response = self._call_service(
            self.handeye_status_client,
            HandEyeGetStatus.Request(),
            self.args.handeye_status_service,
            self.args.timeout,
        )
        if not response.success:
            message = response.last_error or "hand-eye status query failed"
            raise RuntimeError(message)
        if not response.result_file:
            raise RuntimeError("hand-eye result file is empty")

        path = Path(response.result_file).expanduser()
        if not path.exists():
            raise RuntimeError(f"hand-eye result file does not exist: {path}")
        return path

    def _call_service(self, client, request, service_name: str, timeout_sec: float):
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=timeout_sec)
        if not future.done():
            raise RuntimeError(f"timeout while calling {service_name}")
        response = future.result()
        if response is None:
            raise RuntimeError(f"{service_name} returned no response")
        return response


def get_initial_detection(node: AutoSamplerClient, sample_count: int, sample_period: float) -> DetectionSample:
    valid_samples: List[DetectionSample] = []
    attempts = max(sample_count * 3, sample_count)

    for attempt in range(1, attempts + 1):
        sample = node.detect_once(False)
        if sample.valid:
            valid_samples.append(sample)
            print(
                f"[INFO] initial detection {len(valid_samples)}/{sample_count}: "
                f"center=[{sample.center_camera_m[0]:.4f}, {sample.center_camera_m[1]:.4f}, "
                f"{sample.center_camera_m[2]:.4f}], distance={sample.distance_m:.4f} m"
            )
        else:
            print(f"[WARN] initial detection invalid on attempt {attempt}: {sample.message}")

        if len(valid_samples) >= sample_count:
            break
        time.sleep(sample_period)

    if not valid_samples:
        raise RuntimeError("failed to get an initial fitted sphere center")

    centers = np.array([sample.center_camera_m for sample in valid_samples], dtype=np.float64)
    center_mean = np.mean(centers, axis=0)
    distance_m = float(np.linalg.norm(center_mean))
    radius_values = [sample.radius_m for sample in valid_samples if math.isfinite(sample.radius_m)]
    confidence_values = [sample.confidence for sample in valid_samples if math.isfinite(sample.confidence)]

    return DetectionSample(
        True,
        center_mean,
        distance_m,
        float(center_mean[2]),
        statistics.fmean(radius_values) if radius_values else math.nan,
        statistics.fmean(confidence_values) if confidence_values else math.nan,
        valid_samples[-1].class_id,
        valid_samples[-1].frame_id,
        f"mean of {len(valid_samples)} initial samples",
    )


def build_plan(
    args: argparse.Namespace,
    current_tcp_pose: np.ndarray,
    tool_camera: np.ndarray,
    sphere_camera_m: np.ndarray,
) -> Tuple[List[PlannedPoint], np.ndarray, np.ndarray, np.ndarray]:
    current_rotation = rpy_to_rotation_matrix(
        current_tcp_pose[3],
        current_tcp_pose[4],
        current_tcp_pose[5],
    )
    current_tool_translation = current_tcp_pose[:3]
    t_base_tool = make_transform(current_rotation, current_tool_translation)
    t_base_camera = t_base_tool @ tool_camera

    sphere_base_m = transform_point(t_base_camera, sphere_camera_m)
    current_camera_base_m = transform_point(t_base_camera, np.zeros(3, dtype=np.float64))

    center_vector_xy = current_camera_base_m[:2] - sphere_base_m[:2]
    center_norm = float(np.linalg.norm(center_vector_xy))
    if center_norm < 1e-6:
        raise RuntimeError("current camera XY position is too close to sphere XY position")
    center_direction_xy = center_vector_xy / center_norm

    if args.orientation_mode == "rotate-yaw":
        orientation_base_rotation = current_rotation
    else:
        orientation_base_rotation = current_rotation

    planned_points: List[PlannedPoint] = []
    index = 0
    range_labels = [
        ("range_0p4m", "0.4 m"),
        ("range_0p4_to_0p7m", "0.4-0.7 m"),
        ("range_gt0p7m", ">0.7 m"),
    ]

    for range_index, desired_distance_m in enumerate(args.radii):
        range_key, range_text = range_labels[range_index]

        for angle_key, angle_deg, angle_text in ANGLE_LABELS:
            index += 1
            if args.orientation_mode == "rotate-yaw":
                yaw_rotation = rpy_to_rotation_matrix(0.0, 0.0, math.radians(angle_deg))
                target_rotation = yaw_rotation @ orientation_base_rotation
            else:
                target_rotation = orientation_base_rotation

            if args.z_mode == "sphere":
                target_camera_z = sphere_base_m[2]
            else:
                target_camera_z = current_camera_base_m[2]

            dz = float(target_camera_z - sphere_base_m[2])
            if abs(dz) > desired_distance_m:
                raise RuntimeError(
                    f"cannot create {desired_distance_m:.3f} m viewpoint at z={target_camera_z:.3f}: "
                    f"vertical offset to sphere is {abs(dz):.3f} m"
                )
            horizontal_radius = math.sqrt(max(0.0, desired_distance_m * desired_distance_m - dz * dz))
            direction_xy = rotate_xy(center_direction_xy, angle_deg)

            target_camera_base_m = np.array([
                sphere_base_m[0] + horizontal_radius * direction_xy[0],
                sphere_base_m[1] + horizontal_radius * direction_xy[1],
                target_camera_z,
            ], dtype=np.float64)

            camera_offset_in_base = target_rotation @ tool_camera[:3, 3]
            target_tool_base_m = target_camera_base_m - camera_offset_in_base
            rx, ry, rz = rotation_matrix_to_rpy(target_rotation)
            target_tcp_pose = np.array([
                target_tool_base_m[0],
                target_tool_base_m[1],
                target_tool_base_m[2],
                rx,
                ry,
                rz,
            ], dtype=np.float64)

            planned_points.append(
                PlannedPoint(
                    index=index,
                    range_label=range_key,
                    angle_label=angle_key,
                    description=f"{range_text} {angle_text}",
                    desired_distance_m=float(desired_distance_m),
                    horizontal_angle_deg=float(angle_deg),
                    target_camera_base_m=target_camera_base_m,
                    target_tcp_pose=target_tcp_pose,
                )
            )

    return planned_points, sphere_base_m, current_camera_base_m, t_base_camera


def validate_plan(args: argparse.Namespace, current_tcp_pose: np.ndarray, plan: Sequence[PlannedPoint]) -> None:
    previous_xyz = current_tcp_pose[:3]
    for point in plan:
        target_xyz = point.target_tcp_pose[:3]
        if args.max_step_m > 0.0:
            step_m = float(np.linalg.norm(target_xyz - previous_xyz))
            if step_m > args.max_step_m:
                raise RuntimeError(
                    f"planned step to point {point.index} is {step_m:.3f} m, "
                    f"larger than --max-step-m {args.max_step_m:.3f}"
                )
        previous_xyz = target_xyz


def print_plan(plan: Sequence[PlannedPoint], sphere_base_m: np.ndarray, current_camera_base_m: np.ndarray) -> None:
    print()
    print("========== automatic 9-point plan ==========")
    print(
        "sphere_base_m: "
        f"x={sphere_base_m[0]:.6f}, y={sphere_base_m[1]:.6f}, z={sphere_base_m[2]:.6f}"
    )
    print(
        "current_camera_base_m: "
        f"x={current_camera_base_m[0]:.6f}, y={current_camera_base_m[1]:.6f}, z={current_camera_base_m[2]:.6f}"
    )
    print("index | description | desired_distance | tcp_x tcp_y tcp_z | rpy")
    for point in plan:
        pose = point.target_tcp_pose
        print(
            f"{point.index:02d} | {point.description} | {point.desired_distance_m:.3f} m | "
            f"{pose[0]:.6f} {pose[1]:.6f} {pose[2]:.6f} | "
            f"{pose[3]:.6f} {pose[4]:.6f} {pose[5]:.6f}"
        )
    print("============================================")
    print()


def write_run_header(
    file_handle,
    args: argparse.Namespace,
    handeye_result_file: Path,
    sphere_camera_m: np.ndarray,
    sphere_base_m: np.ndarray,
    current_tcp_pose: np.ndarray,
    current_camera_base_m: np.ndarray,
    plan: Sequence[PlannedPoint],
) -> None:
    file_handle.write("# gas automatic 9-point distance sampling\n")
    file_handle.write(f"# created_at: {datetime.now().isoformat(timespec='seconds')}\n")
    file_handle.write(f"# yolo_service: {args.yolo_service}\n")
    file_handle.write(f"# robot_pose_service: {args.robot_pose_service}\n")
    file_handle.write(f"# robot_move_l_service: {args.robot_move_l_service}\n")
    file_handle.write(f"# handeye_result_file: {handeye_result_file}\n")
    file_handle.write(f"# orientation_mode: {args.orientation_mode}\n")
    file_handle.write(f"# z_mode: {args.z_mode}\n")
    file_handle.write(f"# samples_per_point: {args.samples}\n")
    file_handle.write(f"# sample_period_sec: {args.sample_period}\n")
    file_handle.write("# distance_m = sqrt(center_x_m^2 + center_y_m^2 + center_z_m^2)\n")
    file_handle.write(
        "# initial_sphere_camera_m: "
        f"{sphere_camera_m[0]:.9f}, {sphere_camera_m[1]:.9f}, {sphere_camera_m[2]:.9f}\n"
    )
    file_handle.write(
        "# initial_sphere_base_m: "
        f"{sphere_base_m[0]:.9f}, {sphere_base_m[1]:.9f}, {sphere_base_m[2]:.9f}\n"
    )
    file_handle.write(
        "# initial_tcp_pose: "
        + ", ".join(format_float(v) for v in current_tcp_pose)
        + "\n"
    )
    file_handle.write(
        "# initial_camera_base_m: "
        f"{current_camera_base_m[0]:.9f}, {current_camera_base_m[1]:.9f}, {current_camera_base_m[2]:.9f}\n"
    )
    file_handle.write("# planned_points:\n")
    file_handle.write(
        "# plan_columns: point_index\trange_label\tangle_label\tdescription\tdesired_distance_m\t"
        "angle_deg\tcamera_base_x_m\tcamera_base_y_m\tcamera_base_z_m\t"
        "tcp_x_m\ttcp_y_m\ttcp_z_m\ttcp_roll_rad\ttcp_pitch_rad\ttcp_yaw_rad\n"
    )
    for point in plan:
        pose = point.target_tcp_pose
        cam = point.target_camera_base_m
        file_handle.write(
            f"# plan\t{point.index}\t{point.range_label}\t{point.angle_label}\t{point.description}\t"
            f"{format_float(point.desired_distance_m)}\t{format_float(point.horizontal_angle_deg)}\t"
            f"{format_float(cam[0])}\t{format_float(cam[1])}\t{format_float(cam[2])}\t"
            f"{format_float(pose[0])}\t{format_float(pose[1])}\t{format_float(pose[2])}\t"
            f"{format_float(pose[3])}\t{format_float(pose[4])}\t{format_float(pose[5])}\n"
        )
    file_handle.write(
        "# sample_columns: point_index\trange_label\tangle_label\tdescription\tattempt\tvalid_index\t"
        "timestamp\tvalid\tcenter_x_m\tcenter_y_m\tcenter_z_m\tdistance_m\tdepth_z_m\t"
        "radius_m\tconfidence\tclass_id\tframe_id\tmessage\n"
    )
    file_handle.flush()


def write_summary(file_handle, point: PlannedPoint, distances: Iterable[float]) -> None:
    values = [float(v) for v in distances if math.isfinite(float(v))]
    if not values:
        file_handle.write(
            f"# summary\t{point.index}\t{point.range_label}\t{point.angle_label}\tvalid=0\n"
        )
        return
    std_m = statistics.pstdev(values) if len(values) > 1 else 0.0
    file_handle.write(
        f"# summary\t{point.index}\t{point.range_label}\t{point.angle_label}"
        f"\tvalid={len(values)}"
        f"\tmean_m={statistics.fmean(values):.9f}"
        f"\tstd_m={std_m:.9f}"
        f"\tmin_m={min(values):.9f}"
        f"\tmax_m={max(values):.9f}\n"
    )


def run(args: argparse.Namespace) -> int:
    output = Path(args.output).expanduser() if args.output else default_desktop_path()
    output.parent.mkdir(parents=True, exist_ok=True)

    rclpy.init()
    node = AutoSamplerClient(args)
    try:
        node.wait_for_services()

        current_tcp_pose, _ = node.get_robot_pose()
        handeye_result_file = node.resolve_handeye_result_file()
        tool_camera = load_tool_camera_matrix(handeye_result_file)
        initial_detection = get_initial_detection(
            node,
            args.initial_detection_samples,
            args.sample_period,
        )

        plan, sphere_base_m, current_camera_base_m, _ = build_plan(
            args,
            current_tcp_pose,
            tool_camera,
            initial_detection.center_camera_m,
        )
        validate_plan(args, current_tcp_pose, plan)
        print_plan(plan, sphere_base_m, current_camera_base_m)

        if args.dry_run:
            print("[INFO] dry-run enabled; no robot motion or distance sampling was executed.")
            return 0

        if not args.yes:
            print("确认机械臂路径安全后，输入 YES 开始自动 MoveL 采样；其他输入退出。")
            if input("> ").strip() != "YES":
                print("[INFO] aborted before motion")
                return 0

        with output.open("w", encoding="utf-8") as file_handle:
            write_run_header(
                file_handle,
                args,
                handeye_result_file,
                initial_detection.center_camera_m,
                sphere_base_m,
                current_tcp_pose,
                current_camera_base_m,
                plan,
            )

            for point in plan:
                pose = point.target_tcp_pose
                print()
                print(
                    f"[MOVE {point.index}/9] {point.description}: "
                    f"tcp=[{pose[0]:.6f}, {pose[1]:.6f}, {pose[2]:.6f}, "
                    f"{pose[3]:.6f}, {pose[4]:.6f}, {pose[5]:.6f}]"
                )
                move_message = node.move_l(pose, args.wait_motion)
                print(f"[OK] MoveL: {move_message}")
                time.sleep(args.settle_sec)

                valid_distances: List[float] = []
                valid_index = 0
                attempt = 0
                while valid_index < args.samples and attempt < args.max_attempts:
                    attempt += 1
                    timestamp = datetime.now().isoformat(timespec="milliseconds")
                    sample = node.detect_once(args.publish_debug_image)
                    if sample.valid:
                        valid_index += 1
                        valid_distances.append(sample.distance_m)

                    file_handle.write(
                        f"{point.index}\t{point.range_label}\t{point.angle_label}\t{point.description}\t"
                        f"{attempt}\t{valid_index if sample.valid else 0}\t{timestamp}\t"
                        f"{1 if sample.valid else 0}\t"
                        f"{format_float(sample.center_camera_m[0])}\t"
                        f"{format_float(sample.center_camera_m[1])}\t"
                        f"{format_float(sample.center_camera_m[2])}\t"
                        f"{format_float(sample.distance_m)}\t"
                        f"{format_float(sample.depth_z_m)}\t"
                        f"{format_float(sample.radius_m)}\t"
                        f"{format_float(sample.confidence)}\t"
                        f"{sample.class_id}\t{sample.frame_id}\t{sample.message}\n"
                    )
                    file_handle.flush()

                    print(
                        f"[SAMPLE {point.index}/9] {valid_index}/{args.samples} "
                        f"attempt={attempt} distance={format_float(sample.distance_m)} m"
                    )

                    if valid_index < args.samples:
                        time.sleep(args.sample_period)

                write_summary(file_handle, point, valid_distances)
                file_handle.flush()

                if valid_index < args.samples:
                    print(
                        f"[WARN] point {point.index} only collected {valid_index}/{args.samples} "
                        f"valid samples after {attempt} attempts"
                    )

        print(f"\n[OK] output file: {output}")
        return 0
    finally:
        node.destroy_node()
        rclpy.shutdown()


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Automatically move robot to 9 horizontal viewpoints and collect fitted-sphere distances."
    )
    parser.add_argument("--yolo-service", default="/yolo/detect_once")
    parser.add_argument("--robot-pose-service", default="/robot/get_pose")
    parser.add_argument("--robot-move-l-service", default="/robot/move_l")
    parser.add_argument("--handeye-status-service", default="/handeye/status")
    parser.add_argument("--handeye-result-file", default="")
    parser.add_argument("--output", default="")
    parser.add_argument("--timeout", type=float, default=5.0)
    parser.add_argument("--move-timeout", type=float, default=60.0)
    parser.add_argument("--samples", type=int, default=100)
    parser.add_argument("--max-attempts", type=int, default=200)
    parser.add_argument("--sample-period", type=float, default=0.55)
    parser.add_argument("--settle-sec", type=float, default=1.0)
    parser.add_argument("--initial-detection-samples", type=int, default=5)
    parser.add_argument(
        "--radii",
        type=float,
        nargs=3,
        default=[0.40, 0.55, 0.80],
        metavar=("R1", "R2", "R3"),
        help="Camera-origin-to-sphere-center distances for the three ranges.",
    )
    parser.add_argument(
        "--z-mode",
        choices=["current-camera", "sphere"],
        default="current-camera",
        help="Target camera height: keep current camera Z or use sphere Z.",
    )
    parser.add_argument(
        "--orientation-mode",
        choices=["keep", "rotate-yaw"],
        default="keep",
        help="Keep current TCP orientation or rotate yaw with the horizontal viewpoint angle.",
    )
    parser.add_argument(
        "--max-step-m",
        type=float,
        default=1.0,
        help="Reject planned adjacent TCP moves longer than this. Use 0 to disable.",
    )
    parser.add_argument(
        "--no-wait-motion",
        action="store_false",
        dest="wait_motion",
        help="Send MoveL command without waiting for arrival.",
    )
    parser.set_defaults(wait_motion=True)
    parser.add_argument("--publish-debug-image", action="store_true")
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument(
        "--yes",
        action="store_true",
        help="Skip the final typed YES confirmation.",
    )
    return parser


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)

    if args.samples <= 0:
        parser.error("--samples must be positive")
    if args.max_attempts < args.samples:
        parser.error("--max-attempts must be greater than or equal to --samples")
    if len(args.radii) != 3:
        parser.error("--radii requires exactly three values")
    if not (args.radii[0] <= 0.4 + 1e-9):
        parser.error("first radius should represent the 0.4 m range")
    if not (0.4 < args.radii[1] < 0.7):
        parser.error("second radius must be inside the 0.4-0.7 m range")
    if not (args.radii[2] > 0.7):
        parser.error("third radius must be greater than 0.7 m")

    try:
        return run(args)
    except KeyboardInterrupt:
        print("\n[INFO] interrupted")
        return 130
    except Exception as exc:  # noqa: BLE001
        print(f"[ERROR] {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
