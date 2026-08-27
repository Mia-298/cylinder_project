#!/usr/bin/env python3
"""Manual robot pose and detected object position logger.

Move the robot manually to any point, press Enter, and the script records:
- current TCP pose in the robot base frame as x/y/z/roll/pitch/yaw;
- fitted sphere center transformed to the robot base frame;
- fitted sphere center in the camera frame as debug data.
"""

from __future__ import annotations

import argparse
import glob
import math
import statistics
import sys
import time
from datetime import datetime
from pathlib import Path
from typing import Optional, Sequence, Tuple

import cv2
import numpy as np
import rclpy
from rclpy.node import Node

from gas_interfaces.srv import DetectObjects, RobotGetPose


def default_output_path() -> Path:
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    return Path.home() / "Desktop" / f"gas_manual_pose_object_log_{timestamp}.txt"


def format_float(value: float) -> str:
    if not math.isfinite(float(value)):
        return "nan"
    return f"{float(value):.9f}"


def rpy_to_rotation_matrix(rx: float, ry: float, rz: float) -> np.ndarray:
    cx, sx = math.cos(rx), math.sin(rx)
    cy, sy = math.cos(ry), math.sin(ry)
    cz, sz = math.cos(rz), math.sin(rz)

    rx_mat = np.array([
        [1.0, 0.0, 0.0],
        [0.0, cx, -sx],
        [0.0, sx, cx],
    ], dtype=np.float64)
    ry_mat = np.array([
        [cy, 0.0, sy],
        [0.0, 1.0, 0.0],
        [-sy, 0.0, cy],
    ], dtype=np.float64)
    rz_mat = np.array([
        [cz, -sz, 0.0],
        [sz, cz, 0.0],
        [0.0, 0.0, 1.0],
    ], dtype=np.float64)
    return rz_mat @ ry_mat @ rx_mat


def make_transform(rotation: np.ndarray, translation: np.ndarray) -> np.ndarray:
    transform = np.eye(4, dtype=np.float64)
    transform[:3, :3] = rotation
    transform[:3, 3] = translation.reshape(3)
    return transform


def transform_point(transform: np.ndarray, point_xyz: np.ndarray) -> np.ndarray:
    point_h = np.array([point_xyz[0], point_xyz[1], point_xyz[2], 1.0], dtype=np.float64)
    return (transform @ point_h)[:3]


def matrix_is_valid_homogeneous(matrix: np.ndarray) -> bool:
    return (
        matrix.shape == (4, 4)
        and np.all(np.isfinite(matrix))
        and np.allclose(matrix[3, :], np.array([0.0, 0.0, 0.0, 1.0]), atol=1e-6)
    )


def read_opencv_matrix(storage: cv2.FileStorage, key: str) -> np.ndarray:
    node = storage.getNode(key)
    if node.empty():
        return np.empty((0, 0), dtype=np.float64)
    matrix = node.mat()
    if matrix is None:
        return np.empty((0, 0), dtype=np.float64)
    return np.asarray(matrix, dtype=np.float64)


def latest_handeye_result_file(workspace_dir: Path) -> Optional[Path]:
    pattern = str(workspace_dir / "calibration_data" / "handeye" / "*" / "results" / "handeye_result.yaml")
    candidates = [Path(path) for path in glob.glob(pattern)]
    candidates = [path for path in candidates if path.exists()]
    if not candidates:
        return None
    return max(candidates, key=lambda path: path.stat().st_mtime)


def load_tool_camera_matrix(path: Path) -> np.ndarray:
    storage = cv2.FileStorage(str(path), cv2.FILE_STORAGE_READ)
    if not storage.isOpened():
        raise RuntimeError(f"failed to open hand-eye result file: {path}")
    try:
        tool_camera = read_opencv_matrix(storage, "tool_camera_matrix")
        if tool_camera.size == 0:
            camera_tool = read_opencv_matrix(storage, "camera_tool_matrix")
            if camera_tool.size == 0:
                raise RuntimeError("hand-eye file does not contain tool_camera_matrix or camera_tool_matrix")
            if not matrix_is_valid_homogeneous(camera_tool):
                raise RuntimeError("camera_tool_matrix is not a valid 4x4 matrix")
            tool_camera = np.linalg.inv(camera_tool)

        if not matrix_is_valid_homogeneous(tool_camera):
            raise RuntimeError("tool_camera_matrix is not a valid 4x4 matrix")
        return tool_camera
    finally:
        storage.release()


class ManualLoggerNode(Node):
    def __init__(self, robot_pose_service: str, yolo_service: str, timeout: float) -> None:
        super().__init__("gas_manual_pose_object_logger")
        self.timeout = timeout
        self.robot_pose_service = robot_pose_service
        self.yolo_service = yolo_service
        self.robot_pose_client = self.create_client(RobotGetPose, robot_pose_service)
        self.yolo_client = self.create_client(DetectObjects, yolo_service)

    def wait_for_services(self) -> None:
        for name, client in [
            (self.robot_pose_service, self.robot_pose_client),
            (self.yolo_service, self.yolo_client),
        ]:
            print(f"[INFO] waiting for service: {name}")
            if not client.wait_for_service(timeout_sec=self.timeout):
                raise RuntimeError(f"service not available: {name}")
            print(f"[OK] service ready: {name}")

    def call_robot_pose(self) -> RobotGetPose.Response:
        return self._call_service(
            self.robot_pose_client,
            RobotGetPose.Request(),
            self.robot_pose_service,
        )

    def call_yolo(self, publish_debug_image: bool) -> DetectObjects.Response:
        request = DetectObjects.Request()
        request.publish_debug_image = publish_debug_image
        return self._call_service(self.yolo_client, request, self.yolo_service)

    def _call_service(self, client, request, service_name: str):
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=self.timeout)
        if not future.done():
            raise RuntimeError(f"timeout while calling {service_name}")
        response = future.result()
        if response is None:
            raise RuntimeError(f"{service_name} returned no response")
        return response


def object_base_from_camera(
    tcp_pose: np.ndarray,
    object_camera_m: np.ndarray,
    tool_camera: np.ndarray,
) -> np.ndarray:
    if not np.all(np.isfinite(object_camera_m)):
        return np.array([math.nan, math.nan, math.nan], dtype=np.float64)

    base_tool = make_transform(
        rpy_to_rotation_matrix(tcp_pose[3], tcp_pose[4], tcp_pose[5]),
        tcp_pose[:3],
    )
    base_camera = base_tool @ tool_camera
    return transform_point(base_camera, object_camera_m)


def resolve_handeye(args: argparse.Namespace) -> Tuple[np.ndarray, str]:
    path: Optional[Path]
    if args.handeye_result_file:
        path = Path(args.handeye_result_file).expanduser()
    else:
        path = latest_handeye_result_file(Path.cwd())

    if path is None:
        raise RuntimeError("no hand-eye result found under calibration_data/handeye")
    if not path.exists():
        raise RuntimeError(f"hand-eye result file not found: {path}")

    tool_camera = load_tool_camera_matrix(path)
    print(f"[OK] using hand-eye result: {path}")
    return tool_camera, str(path)


def write_header(file_handle, args: argparse.Namespace, handeye_file: str) -> None:
    file_handle.write("# gas manual pose and object position log\n")
    file_handle.write(f"# created_at: {datetime.now().isoformat(timespec='seconds')}\n")
    file_handle.write(f"# robot_pose_service: {args.robot_pose_service}\n")
    file_handle.write(f"# yolo_service: {args.yolo_service}\n")
    file_handle.write(f"# handeye_result_file: {handeye_file}\n")
    file_handle.write(f"# samples_per_point: {args.samples}\n")
    file_handle.write(f"# sample_period_sec: {args.sample_period}\n")
    file_handle.write("# tcp_base_* is the robot TCP pose returned by /robot/get_pose in the base frame.\n")
    file_handle.write("# object_base_* is the fitted sphere center transformed to the robot base frame.\n")
    file_handle.write("# object_camera_distance_m = sqrt(object_camera_x_m^2 + object_camera_y_m^2 + object_camera_z_m^2)\n")
    file_handle.write(
        "# columns: point_index\tsample_index\ttimestamp\tuser_label\t"
        "tcp_base_x_m\ttcp_base_y_m\ttcp_base_z_m\t"
        "tcp_base_roll_rad\ttcp_base_pitch_rad\ttcp_base_yaw_rad\t"
        "object_valid\tobject_base_x_m\tobject_base_y_m\tobject_base_z_m\t"
        "object_camera_distance_m\tobject_camera_x_m\tobject_camera_y_m\tobject_camera_z_m\t"
        "sphere_radius_m\tsphere_confidence\tsphere_class_id\tsphere_frame_id\t"
        "joint_1_rad\tjoint_2_rad\tjoint_3_rad\tjoint_4_rad\tjoint_5_rad\tjoint_6_rad\t"
        "message\n"
    )
    file_handle.flush()


def write_point_summary(
    file_handle,
    point_index: int,
    label: str,
    object_base_values: Sequence[np.ndarray],
    camera_distances: Sequence[float],
) -> None:
    valid_count = len(object_base_values)
    if valid_count == 0:
        file_handle.write(f"# summary\tpoint_index={point_index}\tlabel={label}\tvalid_samples=0\n")
        file_handle.flush()
        return

    object_base_array = np.vstack(object_base_values)
    mean_object_base = np.mean(object_base_array, axis=0)
    std_object_base = np.std(object_base_array, axis=0)
    mean_distance = statistics.fmean(camera_distances)
    std_distance = statistics.pstdev(camera_distances) if len(camera_distances) > 1 else 0.0
    file_handle.write(
        f"# summary\tpoint_index={point_index}\tlabel={label}\tvalid_samples={valid_count}"
        f"\tmean_object_base_x_m={format_float(mean_object_base[0])}"
        f"\tmean_object_base_y_m={format_float(mean_object_base[1])}"
        f"\tmean_object_base_z_m={format_float(mean_object_base[2])}"
        f"\tstd_object_base_x_m={format_float(std_object_base[0])}"
        f"\tstd_object_base_y_m={format_float(std_object_base[1])}"
        f"\tstd_object_base_z_m={format_float(std_object_base[2])}"
        f"\tmean_object_camera_distance_m={format_float(mean_distance)}"
        f"\tstd_object_camera_distance_m={format_float(std_distance)}\n"
    )
    file_handle.flush()


def run(args: argparse.Namespace) -> int:
    output = Path(args.output).expanduser() if args.output else default_output_path()
    output.parent.mkdir(parents=True, exist_ok=True)
    tool_camera, handeye_file = resolve_handeye(args)

    rclpy.init()
    node = ManualLoggerNode(args.robot_pose_service, args.yolo_service, args.timeout)
    try:
        node.wait_for_services()
        with output.open("w", encoding="utf-8") as file_handle:
            write_header(file_handle, args, handeye_file)
            index = 0

            print()
            print(f"把机械臂手动移动到任意测试点后按 Enter 记录，每个点采集 {args.samples} 帧。")
            print("可直接输入标签文字作为该点名称；输入 q/quit/exit 结束。")

            while True:
                user_input = input("\n移动到下一个点后按 Enter 记录，或输入标签/q: ").strip()
                if user_input.lower() in {"q", "quit", "exit"}:
                    break

                label = user_input
                index += 1
                pose_response = node.call_robot_pose()
                if not pose_response.success:
                    raise RuntimeError(f"robot pose failed: {pose_response.message}")
                tcp_pose = np.array([float(v) for v in pose_response.tcp_xyz_m_rpy_rad], dtype=np.float64)
                joint_pose = np.array([float(v) for v in pose_response.joint_rad], dtype=np.float64)

                print(
                    f"[INFO] point {index} start: "
                    f"tcp_base=[{tcp_pose[0]:.6f}, {tcp_pose[1]:.6f}, {tcp_pose[2]:.6f}, "
                    f"{tcp_pose[3]:.6f}, {tcp_pose[4]:.6f}, {tcp_pose[5]:.6f}]"
                )

                valid_object_base_values = []
                valid_camera_distances = []
                valid_count = 0

                for sample_index in range(1, args.samples + 1):
                    timestamp = datetime.now().isoformat(timespec="milliseconds")
                    yolo_response = node.call_yolo(args.publish_debug_image)
                    object_valid = bool(yolo_response.success and yolo_response.has_sphere_center)
                    if object_valid:
                        object_camera = np.array(
                            [float(v) for v in yolo_response.sphere_center_m],
                            dtype=np.float64,
                        )
                        object_valid = bool(np.all(np.isfinite(object_camera)))
                    else:
                        object_camera = np.array([math.nan, math.nan, math.nan], dtype=np.float64)

                    object_base = object_base_from_camera(tcp_pose, object_camera, tool_camera)
                    object_distance = float(np.linalg.norm(object_camera)) if object_valid else math.nan
                    message = yolo_response.message if yolo_response.success else "yolo service failed"

                    if object_valid:
                        valid_count += 1
                        valid_object_base_values.append(object_base)
                        valid_camera_distances.append(object_distance)

                    file_handle.write(
                        f"{index}\t{sample_index}\t{timestamp}\t{label}\t"
                        f"{format_float(tcp_pose[0])}\t{format_float(tcp_pose[1])}\t{format_float(tcp_pose[2])}\t"
                        f"{format_float(tcp_pose[3])}\t{format_float(tcp_pose[4])}\t{format_float(tcp_pose[5])}\t"
                        f"{1 if object_valid else 0}\t"
                        f"{format_float(object_base[0])}\t{format_float(object_base[1])}\t{format_float(object_base[2])}\t"
                        f"{format_float(object_distance)}\t"
                        f"{format_float(object_camera[0])}\t{format_float(object_camera[1])}\t{format_float(object_camera[2])}\t"
                        f"{format_float(float(yolo_response.sphere_radius_m))}\t"
                        f"{format_float(float(yolo_response.sphere_confidence))}\t"
                        f"{yolo_response.sphere_class_id}\t{yolo_response.sphere_frame_id}\t"
                        f"{format_float(joint_pose[0])}\t{format_float(joint_pose[1])}\t{format_float(joint_pose[2])}\t"
                        f"{format_float(joint_pose[3])}\t{format_float(joint_pose[4])}\t{format_float(joint_pose[5])}\t"
                        f"{message}\n"
                    )
                    file_handle.flush()

                    if sample_index == 1 or sample_index == args.samples or sample_index % 10 == 0 or not object_valid:
                        print(
                            f"[SAMPLE] point={index} frame={sample_index}/{args.samples} "
                            f"valid={1 if object_valid else 0} "
                            f"object_base=[{format_float(object_base[0])}, "
                            f"{format_float(object_base[1])}, {format_float(object_base[2])}]"
                        )

                    if sample_index < args.samples:
                        time.sleep(args.sample_period)

                write_point_summary(
                    file_handle,
                    index,
                    label,
                    valid_object_base_values,
                    valid_camera_distances,
                )

                print(f"[OK] point {index} finished: valid_samples={valid_count}/{args.samples}")
                print("请手动移动到下一个点。")

        print(f"\n[OK] output file: {output}")
        return 0
    finally:
        node.destroy_node()
        rclpy.shutdown()


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Manual logger for current TCP pose and fitted object position."
    )
    parser.add_argument("--robot-pose-service", default="/robot/get_pose")
    parser.add_argument("--yolo-service", default="/yolo/detect_once")
    parser.add_argument("--handeye-result-file", default="")
    parser.add_argument("--output", default="")
    parser.add_argument("--timeout", type=float, default=5.0)
    parser.add_argument("--samples", type=int, default=100)
    parser.add_argument("--sample-period", type=float, default=0.55)
    parser.add_argument("--publish-debug-image", action="store_true")
    return parser


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    if args.samples <= 0:
        parser.error("--samples must be positive")
    if args.sample_period < 0.0:
        parser.error("--sample-period must be non-negative")
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
