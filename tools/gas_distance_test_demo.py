#!/usr/bin/env python3
"""Manual gas-can sphere distance test helper.

This script does not move the robot. Move the robot manually to each test pose,
then press Enter to record the current robot base pose or collect visual
distance samples.
"""

from __future__ import annotations

import argparse
import math
import statistics
import sys
import time
from datetime import datetime
from pathlib import Path
from typing import Iterable, List, Optional, Sequence, Tuple

import rclpy
from rclpy.node import Node

from gas_interfaces.srv import DetectObjects, RobotGetPose


DEFAULT_BASE_POINT_LABELS = [
    ("range_0p4m_center", "距离球心约 0.4 m 的中心点"),
    ("range_0p4_to_0p7m_center", "距离球心 0.4-0.7 m 区间内的中心点"),
    ("range_gt0p7m_center", "距离球心大于 0.7 m 的中心点"),
]

DEFAULT_DISTANCE_LABELS = [
    ("range_0p4m_center", "0.4 m 中心点"),
    ("range_0p4m_left30", "0.4 m 左侧水平 30 deg 点"),
    ("range_0p4m_right30", "0.4 m 右侧水平 30 deg 点"),
    ("range_0p4_to_0p7m_center", "0.4-0.7 m 中心点"),
    ("range_0p4_to_0p7m_left30", "0.4-0.7 m 左侧水平 30 deg 点"),
    ("range_0p4_to_0p7m_right30", "0.4-0.7 m 右侧水平 30 deg 点"),
    ("range_gt0p7m_center", ">0.7 m 中心点"),
    ("range_gt0p7m_left30", ">0.7 m 左侧水平 30 deg 点"),
    ("range_gt0p7m_right30", ">0.7 m 右侧水平 30 deg 点"),
]


def default_desktop_path(prefix: str) -> Path:
    desktop = Path.home() / "Desktop"
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    return desktop / f"{prefix}_{timestamp}.txt"


def parse_label_args(values: Optional[Sequence[str]], expected_count: int) -> Optional[List[Tuple[str, str]]]:
    if not values:
        return None
    if len(values) != expected_count:
        raise ValueError(f"expected {expected_count} labels, got {len(values)}")
    return [(label, label) for label in values]


def finite_xyz(values: Sequence[float]) -> bool:
    return len(values) >= 3 and all(math.isfinite(float(values[i])) for i in range(3))


def format_float(value: float) -> str:
    if not math.isfinite(value):
        return "nan"
    return f"{value:.9f}"


class DemoClient(Node):
    def __init__(self, robot_pose_service: str, yolo_service: str, service_timeout_sec: float) -> None:
        super().__init__("gas_distance_test_demo")
        self._service_timeout_sec = service_timeout_sec
        self._robot_pose_service = robot_pose_service
        self._yolo_service = yolo_service
        self._robot_pose_client = self.create_client(RobotGetPose, robot_pose_service)
        self._yolo_client = self.create_client(DetectObjects, yolo_service)

    def wait_for_robot_pose_service(self) -> None:
        self._wait_for_service(self._robot_pose_client, self._robot_pose_service)

    def wait_for_yolo_service(self) -> None:
        self._wait_for_service(self._yolo_client, self._yolo_service)

    def _wait_for_service(self, client, service_name: str) -> None:
        print(f"[INFO] waiting for service: {service_name}")
        if not client.wait_for_service(timeout_sec=self._service_timeout_sec):
            raise RuntimeError(f"service not available: {service_name}")
        print(f"[OK] service ready: {service_name}")

    def get_robot_pose(self) -> RobotGetPose.Response:
        request = RobotGetPose.Request()
        future = self._robot_pose_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=self._service_timeout_sec)
        if not future.done():
            raise RuntimeError(f"timeout while calling {self._robot_pose_service}")
        response = future.result()
        if response is None:
            raise RuntimeError(f"{self._robot_pose_service} returned no response")
        return response

    def detect_once(self, publish_debug_image: bool) -> DetectObjects.Response:
        request = DetectObjects.Request()
        request.publish_debug_image = publish_debug_image
        future = self._yolo_client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=self._service_timeout_sec)
        if not future.done():
            raise RuntimeError(f"timeout while calling {self._yolo_service}")
        response = future.result()
        if response is None:
            raise RuntimeError(f"{self._yolo_service} returned no response")
        return response


def write_header(file_handle, mode: str, service_name: str) -> None:
    now = datetime.now().isoformat(timespec="seconds")
    file_handle.write(f"# gas distance test demo\n")
    file_handle.write(f"# mode: {mode}\n")
    file_handle.write(f"# created_at: {now}\n")
    file_handle.write(f"# service: {service_name}\n")
    file_handle.flush()


def wait_user(prompt: str) -> bool:
    user_input = input(prompt).strip().lower()
    return user_input not in {"q", "quit", "exit"}


def record_base_points(args: argparse.Namespace) -> int:
    labels = parse_label_args(args.labels, 3) or DEFAULT_BASE_POINT_LABELS
    output = Path(args.output).expanduser() if args.output else default_desktop_path("gas_test_base_points")
    output.parent.mkdir(parents=True, exist_ok=True)

    rclpy.init()
    node = DemoClient(args.robot_pose_service, args.yolo_service, args.timeout)
    try:
        node.wait_for_robot_pose_service()

        with output.open("w", encoding="utf-8") as file_handle:
            write_header(file_handle, "record_base_points", args.robot_pose_service)
            file_handle.write("# columns: index\tlabel\tdescription\ttimestamp\tx_m\ty_m\tz_m\troll_rad\tpitch_rad\tyaw_rad\tj1_rad\tj2_rad\tj3_rad\tj4_rad\tj5_rad\tj6_rad\tmessage\n")
            file_handle.flush()

            for index, (label, description) in enumerate(labels, start=1):
                print()
                print(f"[POINT {index}/3] {description}")
                print("手动把机械臂移动到该测试点后按 Enter；输入 q 退出。")
                if not wait_user("> "):
                    print("[INFO] aborted by user")
                    break

                response = node.get_robot_pose()
                timestamp = datetime.now().isoformat(timespec="milliseconds")
                if not response.success:
                    print(f"[ERROR] robot pose failed: {response.message}")
                    file_handle.write(
                        f"{index}\t{label}\t{description}\t{timestamp}\tnan\tnan\tnan\tnan\tnan\tnan"
                        f"\tnan\tnan\tnan\tnan\tnan\tnan\t{response.message}\n"
                    )
                    file_handle.flush()
                    continue

                tcp = [float(v) for v in response.tcp_xyz_m_rpy_rad]
                joints = [float(v) for v in response.joint_rad]
                file_handle.write(
                    f"{index}\t{label}\t{description}\t{timestamp}\t"
                    f"{format_float(tcp[0])}\t{format_float(tcp[1])}\t{format_float(tcp[2])}\t"
                    f"{format_float(tcp[3])}\t{format_float(tcp[4])}\t{format_float(tcp[5])}\t"
                    f"{format_float(joints[0])}\t{format_float(joints[1])}\t{format_float(joints[2])}\t"
                    f"{format_float(joints[3])}\t{format_float(joints[4])}\t{format_float(joints[5])}\t"
                    f"{response.message}\n"
                )
                file_handle.flush()
                print(
                    "[OK] recorded "
                    f"x={tcp[0]:.6f}, y={tcp[1]:.6f}, z={tcp[2]:.6f}, "
                    f"rpy=[{tcp[3]:.6f}, {tcp[4]:.6f}, {tcp[5]:.6f}]"
                )

        print(f"\n[OK] base point file: {output}")
        return 0
    finally:
        node.destroy_node()
        rclpy.shutdown()


def extract_distance(response: DetectObjects.Response) -> Tuple[bool, List[float], float, float, str]:
    if not response.success:
        return False, [math.nan, math.nan, math.nan], math.nan, math.nan, response.message
    if not response.has_sphere_center:
        return False, [math.nan, math.nan, math.nan], math.nan, math.nan, "no fitted sphere center"

    center = [float(v) for v in response.sphere_center_m]
    if not finite_xyz(center):
        return False, center, math.nan, math.nan, "invalid fitted sphere center"

    distance_m = math.sqrt(center[0] * center[0] + center[1] * center[1] + center[2] * center[2])
    depth_z_m = center[2]
    return True, center, distance_m, depth_z_m, response.message


def write_distance_summary(file_handle, label: str, distances: Iterable[float]) -> None:
    values = [float(v) for v in distances if math.isfinite(float(v))]
    if not values:
        file_handle.write(f"# summary\t{label}\tvalid=0\n")
        return
    std_m = statistics.pstdev(values) if len(values) > 1 else 0.0
    file_handle.write(
        f"# summary\t{label}\tvalid={len(values)}"
        f"\tmean_m={statistics.fmean(values):.9f}"
        f"\tstd_m={std_m:.9f}"
        f"\tmin_m={min(values):.9f}"
        f"\tmax_m={max(values):.9f}\n"
    )


def collect_distance_samples(args: argparse.Namespace) -> int:
    labels = parse_label_args(args.labels, 9) or DEFAULT_DISTANCE_LABELS
    output = Path(args.output).expanduser() if args.output else default_desktop_path("gas_distance_samples")
    output.parent.mkdir(parents=True, exist_ok=True)

    rclpy.init()
    node = DemoClient(args.robot_pose_service, args.yolo_service, args.timeout)
    try:
        node.wait_for_yolo_service()

        with output.open("w", encoding="utf-8") as file_handle:
            write_header(file_handle, "collect_distance_samples", args.yolo_service)
            file_handle.write(f"# valid_samples_per_position: {args.samples}\n")
            file_handle.write(f"# sample_period_sec: {args.sample_period}\n")
            file_handle.write("# distance_m = sqrt(center_x_m^2 + center_y_m^2 + center_z_m^2)\n")
            file_handle.write(
                "# columns: position_index\tlabel\tdescription\tattempt\tvalid_index\ttimestamp\tvalid\t"
                "center_x_m\tcenter_y_m\tcenter_z_m\tdistance_m\tdepth_z_m\tradius_m\tconfidence\t"
                "class_id\tframe_id\tmessage\n"
            )
            file_handle.flush()

            for position_index, (label, description) in enumerate(labels, start=1):
                print()
                print(f"[POSITION {position_index}/9] {description}")
                print("手动把机械臂移动到这个位置并稳定后按 Enter；输入 q 退出。")
                if not wait_user("> "):
                    print("[INFO] aborted by user")
                    break

                valid_distances: List[float] = []
                valid_index = 0
                attempt = 0

                while valid_index < args.samples and attempt < args.max_attempts:
                    attempt += 1
                    timestamp = datetime.now().isoformat(timespec="milliseconds")
                    try:
                        response = node.detect_once(args.publish_debug_image)
                        valid, center, distance_m, depth_z_m, message = extract_distance(response)
                        radius_m = float(response.sphere_radius_m)
                        confidence = float(response.sphere_confidence)
                        class_id = response.sphere_class_id
                        frame_id = response.sphere_frame_id
                    except Exception as exc:  # noqa: BLE001 - keep the demo logging robust.
                        valid = False
                        center = [math.nan, math.nan, math.nan]
                        distance_m = math.nan
                        depth_z_m = math.nan
                        radius_m = math.nan
                        confidence = math.nan
                        class_id = ""
                        frame_id = ""
                        message = str(exc)

                    if valid:
                        valid_index += 1
                        valid_distances.append(distance_m)
                        progress = f"{valid_index}/{args.samples}"
                    else:
                        progress = f"{valid_index}/{args.samples}, invalid attempt {attempt}"

                    file_handle.write(
                        f"{position_index}\t{label}\t{description}\t{attempt}\t{valid_index if valid else 0}\t"
                        f"{timestamp}\t{1 if valid else 0}\t"
                        f"{format_float(center[0])}\t{format_float(center[1])}\t{format_float(center[2])}\t"
                        f"{format_float(distance_m)}\t{format_float(depth_z_m)}\t"
                        f"{format_float(radius_m)}\t{format_float(confidence)}\t"
                        f"{class_id}\t{frame_id}\t{message}\n"
                    )
                    file_handle.flush()
                    print(f"[{label}] {progress} distance={format_float(distance_m)} m")

                    if valid_index < args.samples:
                        time.sleep(args.sample_period)

                write_distance_summary(file_handle, label, valid_distances)
                file_handle.flush()

                if valid_index < args.samples:
                    print(
                        f"[WARN] {label} only collected {valid_index}/{args.samples} valid samples "
                        f"after {attempt} attempts"
                    )

        print(f"\n[OK] distance sample file: {output}")
        return 0
    finally:
        node.destroy_node()
        rclpy.shutdown()


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Manual base-pose recorder and 100-frame visual distance sampler."
    )
    parser.add_argument(
        "--robot-pose-service",
        default="/robot/get_pose",
        help="Robot pose service name.",
    )
    parser.add_argument(
        "--yolo-service",
        default="/yolo/detect_once",
        help="YOLO fitted sphere detection service name.",
    )
    parser.add_argument(
        "--timeout",
        type=float,
        default=5.0,
        help="Service wait/call timeout in seconds.",
    )

    subparsers = parser.add_subparsers(dest="command", required=True)

    record_parser = subparsers.add_parser(
        "record-points",
        help="Record three manually selected robot TCP base poses.",
    )
    record_parser.add_argument(
        "--output",
        default="",
        help="Output txt path. Default: ~/Desktop/gas_test_base_points_<time>.txt",
    )
    record_parser.add_argument(
        "--labels",
        nargs=3,
        help="Optional three custom labels.",
    )
    record_parser.set_defaults(func=record_base_points)

    collect_parser = subparsers.add_parser(
        "collect-distance",
        help="Collect visual distance samples at nine manually selected positions.",
    )
    collect_parser.add_argument(
        "--output",
        default="",
        help="Output txt path. Default: ~/Desktop/gas_distance_samples_<time>.txt",
    )
    collect_parser.add_argument(
        "--samples",
        type=int,
        default=100,
        help="Valid samples per position.",
    )
    collect_parser.add_argument(
        "--max-attempts",
        type=int,
        default=200,
        help="Maximum service calls per position.",
    )
    collect_parser.add_argument(
        "--sample-period",
        type=float,
        default=0.55,
        help="Delay between samples. YOLO default capture interval is 0.5 s.",
    )
    collect_parser.add_argument(
        "--publish-debug-image",
        action="store_true",
        help="Request yolo_cpp to publish debug image if supported.",
    )
    collect_parser.add_argument(
        "--labels",
        nargs=9,
        help="Optional nine custom labels.",
    )
    collect_parser.set_defaults(func=collect_distance_samples)

    return parser


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)

    try:
        return int(args.func(args))
    except KeyboardInterrupt:
        print("\n[INFO] interrupted")
        return 130
    except Exception as exc:  # noqa: BLE001 - command line demo should print failures plainly.
        print(f"[ERROR] {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
