#!/usr/bin/python3

from __future__ import annotations

import csv
import math
import os
import threading
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional, Tuple

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from gas_interfaces.srv import RobotGetPose, RobotSetHandguide
from PIL import Image as PilImage
from PIL import ImageTk
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import CameraInfo, Image
import tkinter as tk
from tkinter import ttk


try:
    RESAMPLE_LANCZOS = PilImage.Resampling.LANCZOS
except AttributeError:
    RESAMPLE_LANCZOS = PilImage.LANCZOS


@dataclass
class PoseEstimate:
    ok: bool
    message: str
    annotated_bgr: np.ndarray
    marker_count: int
    charuco_count: int
    reprojection_error_px: float
    rvec: Optional[np.ndarray]
    tvec: Optional[np.ndarray]
    t_camera_board: Optional[np.ndarray]
    charuco_ids: Optional[np.ndarray]
    charuco_corners: Optional[np.ndarray]


@dataclass
class DisplaySnapshot:
    frame_bgr: np.ndarray
    text: str
    marker_count: int
    charuco_count: int
    reprojection_error_px: float
    has_camera_info: bool
    has_handeye_result: bool


@dataclass
class ValidationSample:
    sample_id: int
    stamp_sec: float
    frame_id: str
    pose_label: str
    notes: str
    image_file: str
    debug_image_file: str
    sample_file: str
    marker_count: int
    charuco_count: int
    reprojection_error_px: float
    board_rvec: np.ndarray
    board_tvec: np.ndarray
    t_base_tool: np.ndarray
    t_camera_board: np.ndarray
    t_base_board: np.ndarray
    charuco_ids: np.ndarray
    charuco_corners: np.ndarray


def _now_string() -> str:
    return time.strftime("%Y%m%d_%H%M%S", time.localtime())


def _make_charuco_board(
    dictionary_id: int,
    squares_x: int,
    squares_y: int,
    square_length_m: float,
    marker_length_m: float,
):
    dictionary = cv2.aruco.getPredefinedDictionary(int(dictionary_id))
    if hasattr(cv2.aruco, "CharucoBoard_create"):
        board = cv2.aruco.CharucoBoard_create(
            int(squares_x),
            int(squares_y),
            float(square_length_m),
            float(marker_length_m),
            dictionary,
        )
    else:
        board = cv2.aruco.CharucoBoard(
            (int(squares_x), int(squares_y)),
            float(square_length_m),
            float(marker_length_m),
            dictionary,
        )
    if hasattr(board, "setLegacyPattern"):
        board.setLegacyPattern(True)

    if hasattr(cv2.aruco, "DetectorParameters_create"):
        detector_params = cv2.aruco.DetectorParameters_create()
    else:
        detector_params = cv2.aruco.DetectorParameters()

    aruco_detector = None
    if hasattr(cv2.aruco, "ArucoDetector"):
        aruco_detector = cv2.aruco.ArucoDetector(dictionary, detector_params)

    charuco_detector = None
    if hasattr(cv2.aruco, "CharucoDetector"):
        charuco_detector = cv2.aruco.CharucoDetector(board)
        if hasattr(charuco_detector, "setDetectorParameters"):
            charuco_detector.setDetectorParameters(detector_params)

    return dictionary, board, detector_params, aruco_detector, charuco_detector


def _detect_markers(gray: np.ndarray, dictionary, detector_params, aruco_detector):
    if aruco_detector is not None:
        return aruco_detector.detectMarkers(gray)
    return cv2.aruco.detectMarkers(gray, dictionary, parameters=detector_params)


def _interpolate_charuco(
    gray: np.ndarray,
    marker_corners,
    marker_ids,
    board,
    charuco_detector,
    camera_matrix: np.ndarray,
    dist_coeffs: np.ndarray,
):
    if marker_ids is None or len(marker_ids) == 0:
        return 0, None, None

    if charuco_detector is not None:
        charuco_corners, charuco_ids, _, _ = charuco_detector.detectBoard(
            gray,
            None,
            None,
            marker_corners,
            marker_ids,
        )
        count = 0 if charuco_ids is None else int(len(charuco_ids))
        return count, charuco_corners, charuco_ids

    try:
        retval, charuco_corners, charuco_ids = cv2.aruco.interpolateCornersCharuco(
            marker_corners,
            marker_ids,
            gray,
            board,
            None,
            None,
            camera_matrix,
            dist_coeffs,
        )
    except cv2.error:
        retval, charuco_corners, charuco_ids = cv2.aruco.interpolateCornersCharuco(
            marker_corners,
            marker_ids,
            gray,
            board,
        )
    count = 0 if retval is None else int(retval)
    return count, charuco_corners, charuco_ids


def _camera_matrix_from_info(msg: CameraInfo) -> np.ndarray:
    if len(msg.k) != 9:
        return np.zeros((3, 3), dtype=np.float64)
    return np.array(msg.k, dtype=np.float64).reshape((3, 3))


def _dist_coeffs_from_info(msg: CameraInfo) -> np.ndarray:
    if not msg.d:
        return np.zeros((1, 5), dtype=np.float64)
    return np.array(msg.d, dtype=np.float64).reshape((1, -1))


def _make_homogeneous(rotation: np.ndarray, translation: np.ndarray) -> np.ndarray:
    out = np.eye(4, dtype=np.float64)
    out[:3, :3] = np.asarray(rotation, dtype=np.float64).reshape((3, 3))
    out[:3, 3] = np.asarray(translation, dtype=np.float64).reshape((3,))
    return out


def _invert_transform(transform: np.ndarray) -> np.ndarray:
    rotation = transform[:3, :3]
    translation = transform[:3, 3]
    out = np.eye(4, dtype=np.float64)
    out[:3, :3] = rotation.T
    out[:3, 3] = -rotation.T @ translation
    return out


def _rpy_to_rotation_matrix(rx: float, ry: float, rz: float) -> np.ndarray:
    cx = math.cos(rx)
    sx = math.sin(rx)
    cy = math.cos(ry)
    sy = math.sin(ry)
    cz = math.cos(rz)
    sz = math.sin(rz)
    rotation_x = np.array(
        [[1.0, 0.0, 0.0], [0.0, cx, -sx], [0.0, sx, cx]],
        dtype=np.float64,
    )
    rotation_y = np.array(
        [[cy, 0.0, sy], [0.0, 1.0, 0.0], [-sy, 0.0, cy]],
        dtype=np.float64,
    )
    rotation_z = np.array(
        [[cz, -sz, 0.0], [sz, cz, 0.0], [0.0, 0.0, 1.0]],
        dtype=np.float64,
    )
    return rotation_z @ rotation_y @ rotation_x


def _robot_pose_to_transform(tcp_xyz_m_rpy_rad) -> np.ndarray:
    if len(tcp_xyz_m_rpy_rad) != 6:
        raise RuntimeError("robot pose response tcp_xyz_m_rpy_rad size is not 6")
    x, y, z, rx, ry, rz = [float(value) for value in tcp_xyz_m_rpy_rad]
    return _make_homogeneous(_rpy_to_rotation_matrix(rx, ry, rz), np.array([x, y, z]))


def _rotation_angle_deg(rotation: np.ndarray) -> float:
    trace = float(np.trace(rotation))
    value = max(-1.0, min(1.0, (trace - 1.0) * 0.5))
    return math.degrees(math.acos(value))


def _rotation_to_quaternion(rotation: np.ndarray) -> np.ndarray:
    matrix = np.asarray(rotation, dtype=np.float64)
    trace = float(np.trace(matrix))
    if trace > 0.0:
        s = math.sqrt(trace + 1.0) * 2.0
        qw = 0.25 * s
        qx = (matrix[2, 1] - matrix[1, 2]) / s
        qy = (matrix[0, 2] - matrix[2, 0]) / s
        qz = (matrix[1, 0] - matrix[0, 1]) / s
    else:
        idx = int(np.argmax(np.diag(matrix)))
        if idx == 0:
            s = math.sqrt(1.0 + matrix[0, 0] - matrix[1, 1] - matrix[2, 2]) * 2.0
            qw = (matrix[2, 1] - matrix[1, 2]) / s
            qx = 0.25 * s
            qy = (matrix[0, 1] + matrix[1, 0]) / s
            qz = (matrix[0, 2] + matrix[2, 0]) / s
        elif idx == 1:
            s = math.sqrt(1.0 + matrix[1, 1] - matrix[0, 0] - matrix[2, 2]) * 2.0
            qw = (matrix[0, 2] - matrix[2, 0]) / s
            qx = (matrix[0, 1] + matrix[1, 0]) / s
            qy = 0.25 * s
            qz = (matrix[1, 2] + matrix[2, 1]) / s
        else:
            s = math.sqrt(1.0 + matrix[2, 2] - matrix[0, 0] - matrix[1, 1]) * 2.0
            qw = (matrix[1, 0] - matrix[0, 1]) / s
            qx = (matrix[0, 2] + matrix[2, 0]) / s
            qy = (matrix[1, 2] + matrix[2, 1]) / s
            qz = 0.25 * s
    quat = np.array([qw, qx, qy, qz], dtype=np.float64)
    quat /= max(1e-12, np.linalg.norm(quat))
    if quat[0] < 0.0:
        quat = -quat
    return quat


def _quaternion_to_rotation(quat: np.ndarray) -> np.ndarray:
    qw, qx, qy, qz = [float(value) for value in quat]
    return np.array(
        [
            [1.0 - 2.0 * (qy * qy + qz * qz), 2.0 * (qx * qy - qz * qw), 2.0 * (qx * qz + qy * qw)],
            [2.0 * (qx * qy + qz * qw), 1.0 - 2.0 * (qx * qx + qz * qz), 2.0 * (qy * qz - qx * qw)],
            [2.0 * (qx * qz - qy * qw), 2.0 * (qy * qz + qx * qw), 1.0 - 2.0 * (qx * qx + qy * qy)],
        ],
        dtype=np.float64,
    )


def _average_rotation(rotations: List[np.ndarray]) -> np.ndarray:
    if not rotations:
        return np.eye(3, dtype=np.float64)
    accum = np.zeros((4, 4), dtype=np.float64)
    reference = _rotation_to_quaternion(rotations[0])
    for rotation in rotations:
        quat = _rotation_to_quaternion(rotation)
        if float(np.dot(reference, quat)) < 0.0:
            quat = -quat
        accum += np.outer(quat, quat)
    _, eigenvectors = np.linalg.eigh(accum)
    avg_quat = eigenvectors[:, -1]
    avg_quat /= max(1e-12, np.linalg.norm(avg_quat))
    if avg_quat[0] < 0.0:
        avg_quat = -avg_quat
    return _quaternion_to_rotation(avg_quat)


def _rms(values: np.ndarray) -> float:
    if values.size == 0:
        return 0.0
    return float(math.sqrt(float(np.mean(np.square(values)))))


def _stats(values: np.ndarray) -> Dict[str, float]:
    if values.size == 0:
        return {
            "mean": 0.0,
            "median": 0.0,
            "std": 0.0,
            "min": 0.0,
            "max": 0.0,
            "p90": 0.0,
            "rms": 0.0,
        }
    return {
        "mean": float(np.mean(values)),
        "median": float(np.median(values)),
        "std": float(np.std(values, ddof=1)) if values.size > 1 else 0.0,
        "min": float(np.min(values)),
        "max": float(np.max(values)),
        "p90": float(np.percentile(values, 90)),
        "rms": _rms(values),
    }


def _format_matrix_yaml(name: str, matrix: np.ndarray, indent: int = 0) -> str:
    spaces = " " * indent
    flat = [float(value) for value in matrix.reshape(-1)]
    values = ", ".join(f"{value:.12g}" for value in flat)
    return (
        f"{spaces}{name}:\n"
        f"{spaces}  rows: {matrix.shape[0]}\n"
        f"{spaces}  cols: {matrix.shape[1]}\n"
        f"{spaces}  data: [{values}]\n"
    )


class HandeyeValidationNode(Node):
    def __init__(self):
        super().__init__("handeye_validation_ui")

        self.image_topic = self.declare_parameter("image_topic", "/camera/color/image_raw").value
        self.camera_info_topic = self.declare_parameter(
            "camera_info_topic", "/camera/color/camera_info").value
        self.robot_pose_service = self.declare_parameter(
            "robot_pose_service", "/robot/get_pose").value
        self.handguide_service = self.declare_parameter(
            "handguide_service", "/robot/handguide").value
        self.handeye_result_file = self.declare_parameter("handeye_result_file", "").value
        self.save_root_dir = self.declare_parameter(
            "save_root_dir", "calibration_data/handeye_validation").value
        self.session_name = self.declare_parameter("session_name", "").value
        self.board_dictionary_id = int(self.declare_parameter("board_dictionary_id", 7).value)
        self.board_squares_x = int(self.declare_parameter("board_squares_x", 10).value)
        self.board_squares_y = int(self.declare_parameter("board_squares_y", 7).value)
        self.board_square_length_m = float(self.declare_parameter(
            "board_square_length_m", 0.025).value)
        self.board_marker_length_m = float(self.declare_parameter(
            "board_marker_length_m", 0.018).value)
        self.min_charuco_corners = int(self.declare_parameter("min_charuco_corners", 12).value)
        self.min_validation_samples = int(self.declare_parameter("min_validation_samples", 8).value)
        self.robot_pose_timeout_sec = float(self.declare_parameter("robot_pose_timeout_sec", 8.0).value)
        self.display_width = int(self.declare_parameter("display_width", 1280).value)
        self.display_height = int(self.declare_parameter("display_height", 960).value)

        self.bridge = CvBridge()
        (
            self.dictionary,
            self.board,
            self.detector_params,
            self.aruco_detector,
            self.charuco_detector,
        ) = _make_charuco_board(
            self.board_dictionary_id,
            self.board_squares_x,
            self.board_squares_y,
            self.board_square_length_m,
            self.board_marker_length_m,
        )
        self.board_corners = np.asarray(self.board.getChessboardCorners(), dtype=np.float32)

        self.t_tool_camera = np.eye(4, dtype=np.float64)
        self.t_camera_tool = np.eye(4, dtype=np.float64)
        self.handeye_source_sample_count = 0
        self.handeye_source_reprojection_px = -1.0
        self.handeye_result_file = self._resolve_handeye_result_file(self.handeye_result_file)
        self._load_handeye_result()

        self.image_sub = self.create_subscription(
            Image,
            self.image_topic,
            self._image_callback,
            qos_profile_sensor_data,
        )
        self.camera_info_sub = self.create_subscription(
            CameraInfo,
            self.camera_info_topic,
            self._camera_info_callback,
            10,
        )
        self.robot_pose_client = self.create_client(RobotGetPose, self.robot_pose_service)
        self.handguide_client = self.create_client(RobotSetHandguide, self.handguide_service)

        self._lock = threading.Lock()
        self._latest_camera_matrix = np.zeros((3, 3), dtype=np.float64)
        self._latest_dist_coeffs = np.zeros((1, 5), dtype=np.float64)
        self._latest_header_stamp_sec = 0.0
        self._latest_frame_id = ""
        self._latest_raw_bgr: Optional[np.ndarray] = None
        self._latest_pose: Optional[PoseEstimate] = None
        self._latest_snapshot = DisplaySnapshot(
            frame_bgr=self._placeholder_frame("waiting for camera"),
            text="waiting for camera",
            marker_count=0,
            charuco_count=0,
            reprojection_error_px=-1.0,
            has_camera_info=False,
            has_handeye_result=bool(self.handeye_result_file),
        )
        self._message = self._initial_message()
        self._busy = False
        self._samples: List[ValidationSample] = []
        self._last_result_file = ""
        self._last_report_file = ""
        self._create_session(self.session_name)

    def _initial_message(self) -> str:
        if self.handeye_result_file:
            return f"ready, handeye={self.handeye_result_file}"
        return "handeye result not found"

    def _placeholder_frame(self, text: str) -> np.ndarray:
        frame = np.zeros((720, 1280, 3), dtype=np.uint8)
        self._put_overlay_text(frame, text, color=(0, 220, 255))
        return frame

    def _put_overlay_text(self, frame: np.ndarray, text: str, color=(0, 255, 0)) -> None:
        lines = [line for line in text.splitlines() if line.strip()]
        y = 38
        for line in lines[:8]:
            cv2.putText(
                frame,
                line,
                (18, y),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.75,
                color,
                2,
                cv2.LINE_AA,
            )
            y += 30

    def _configured_path(self, path_text: str) -> Path:
        return Path(os.path.expanduser(path_text))

    def _record_path(self, path: Path | str) -> str:
        path_obj = Path(os.path.expanduser(str(path)))
        if not path_obj.is_absolute():
            return path_obj.as_posix()
        try:
            return path_obj.resolve().relative_to(Path.cwd().resolve()).as_posix()
        except ValueError:
            return path_obj.as_posix()

    def _resolve_handeye_result_file(self, configured_path: str) -> str:
        if configured_path:
            path = self._configured_path(configured_path)
            return self._record_path(path) if path.is_file() else ""

        candidates = sorted(
            Path("calibration_data").glob("handeye/*/results/handeye_result.yaml")
        )
        if candidates:
            return self._record_path(candidates[-1])
        return ""

    def _load_handeye_result(self) -> None:
        if not self.handeye_result_file:
            return
        fs = cv2.FileStorage(self.handeye_result_file, cv2.FILE_STORAGE_READ)
        if not fs.isOpened():
            self.handeye_result_file = ""
            return
        t_tool_camera = fs.getNode("tool_camera_matrix").mat()
        t_camera_tool = fs.getNode("camera_tool_matrix").mat()
        if t_tool_camera is None or t_tool_camera.shape != (4, 4):
            fs.release()
            self.handeye_result_file = ""
            return
        self.t_tool_camera = np.asarray(t_tool_camera, dtype=np.float64)
        if t_camera_tool is not None and t_camera_tool.shape == (4, 4):
            self.t_camera_tool = np.asarray(t_camera_tool, dtype=np.float64)
        else:
            self.t_camera_tool = _invert_transform(self.t_tool_camera)
        self.handeye_source_sample_count = int(fs.getNode("sample_count").real())
        self.handeye_source_reprojection_px = float(fs.getNode("rms_reprojection_error_px").real())
        fs.release()

    def _create_session(self, requested_name: str = "") -> None:
        session_name = requested_name.strip() if requested_name else _now_string()
        base_dir = self._configured_path(self.save_root_dir) / session_name
        samples_dir = base_dir / "samples"
        debug_dir = base_dir / "debug"
        results_dir = base_dir / "results"
        for directory in (samples_dir, debug_dir, results_dir):
            directory.mkdir(parents=True, exist_ok=True)
        self.session_name = session_name
        self.session_dir = base_dir
        self.samples_dir = samples_dir
        self.debug_dir = debug_dir
        self.results_dir = results_dir
        self._write_session_yaml()

    def _write_session_yaml(self) -> None:
        session_file = self.session_dir / "session.yaml"
        content = (
            "node_name: handeye_validation_ui\n"
            f"session_name: \"{self.session_name}\"\n"
            f"handeye_result_file: \"{self.handeye_result_file}\"\n"
            f"image_topic: \"{self.image_topic}\"\n"
            f"camera_info_topic: \"{self.camera_info_topic}\"\n"
            f"robot_pose_service: \"{self.robot_pose_service}\"\n"
            f"save_root_dir: \"{self._record_path(self.save_root_dir)}\"\n"
            f"board_dictionary_id: {self.board_dictionary_id}\n"
            f"board_squares_x: {self.board_squares_x}\n"
            f"board_squares_y: {self.board_squares_y}\n"
            f"board_square_length_m: {self.board_square_length_m:.12g}\n"
            f"board_marker_length_m: {self.board_marker_length_m:.12g}\n"
            f"min_charuco_corners: {self.min_charuco_corners}\n"
            f"min_validation_samples: {self.min_validation_samples}\n"
        )
        session_file.write_text(content, encoding="utf-8")

    def _camera_info_callback(self, msg: CameraInfo) -> None:
        with self._lock:
            self._latest_camera_matrix = _camera_matrix_from_info(msg)
            self._latest_dist_coeffs = _dist_coeffs_from_info(msg)

    def _image_callback(self, msg: Image) -> None:
        try:
            raw_bgr = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        except Exception as exc:
            self.get_logger().warn(f"failed to convert image: {exc}")
            return

        with self._lock:
            camera_matrix = self._latest_camera_matrix.copy()
            dist_coeffs = self._latest_dist_coeffs.copy()
            has_camera_info = bool(np.count_nonzero(camera_matrix))

        pose = self._estimate_board_pose(raw_bgr, camera_matrix, dist_coeffs, has_camera_info)
        stamp = msg.header.stamp
        stamp_sec = float(stamp.sec) + float(stamp.nanosec) * 1e-9

        text = pose.message
        if pose.ok:
            text = (
                f"corners={pose.charuco_count}, markers={pose.marker_count}, "
                f"reproj={pose.reprojection_error_px:.3f}px"
            )

        with self._lock:
            self._latest_raw_bgr = raw_bgr.copy()
            self._latest_pose = pose
            self._latest_header_stamp_sec = stamp_sec
            self._latest_frame_id = msg.header.frame_id
            self._latest_snapshot = DisplaySnapshot(
                frame_bgr=pose.annotated_bgr.copy(),
                text=text,
                marker_count=pose.marker_count,
                charuco_count=pose.charuco_count,
                reprojection_error_px=pose.reprojection_error_px,
                has_camera_info=has_camera_info,
                has_handeye_result=bool(self.handeye_result_file),
            )

    def _estimate_board_pose(
        self,
        frame_bgr: np.ndarray,
        camera_matrix: np.ndarray,
        dist_coeffs: np.ndarray,
        has_camera_info: bool,
    ) -> PoseEstimate:
        annotated = frame_bgr.copy()
        if not has_camera_info:
            self._put_overlay_text(annotated, "no camera info", color=(0, 220, 255))
            return PoseEstimate(
                ok=False,
                message="no camera info",
                annotated_bgr=annotated,
                marker_count=0,
                charuco_count=0,
                reprojection_error_px=-1.0,
                rvec=None,
                tvec=None,
                t_camera_board=None,
                charuco_ids=None,
                charuco_corners=None,
            )

        gray = cv2.cvtColor(frame_bgr, cv2.COLOR_BGR2GRAY)
        try:
            marker_corners, marker_ids, _ = _detect_markers(
                gray,
                self.dictionary,
                self.detector_params,
                self.aruco_detector,
            )
        except cv2.error as exc:
            self._put_overlay_text(annotated, f"marker detection failed: {exc}", color=(0, 0, 255))
            return PoseEstimate(False, "marker detection failed", annotated, 0, 0, -1.0, None, None, None, None, None)

        marker_count = 0 if marker_ids is None else int(len(marker_ids))
        if marker_count <= 0:
            self._put_overlay_text(annotated, "no board detected", color=(0, 220, 255))
            return PoseEstimate(False, "no board detected", annotated, 0, 0, -1.0, None, None, None, None, None)

        cv2.aruco.drawDetectedMarkers(annotated, marker_corners, marker_ids)
        retval, charuco_corners, charuco_ids = _interpolate_charuco(
            gray,
            marker_corners,
            marker_ids,
            self.board,
            self.charuco_detector,
            camera_matrix,
            dist_coeffs,
        )
        charuco_count = 0 if charuco_ids is None else int(retval)
        if charuco_count <= 0 or charuco_corners is None or charuco_ids is None:
            self._put_overlay_text(annotated, f"markers={marker_count}, no charuco", color=(0, 220, 255))
            return PoseEstimate(False, "no charuco corners", annotated, marker_count, 0, -1.0, None, None, None, None, None)

        cv2.aruco.drawDetectedCornersCharuco(annotated, charuco_corners, charuco_ids)
        ids_flat = np.asarray(charuco_ids, dtype=np.int32).reshape((-1,))
        corners = np.asarray(charuco_corners, dtype=np.float32).reshape((-1, 2))
        valid = (ids_flat >= 0) & (ids_flat < self.board_corners.shape[0])
        ids_flat = ids_flat[valid]
        corners = corners[valid]
        if len(ids_flat) < max(4, self.min_charuco_corners):
            message = f"corners={len(ids_flat)}, need >= {self.min_charuco_corners}"
            self._put_overlay_text(annotated, message, color=(0, 220, 255))
            return PoseEstimate(
                False,
                message,
                annotated,
                marker_count,
                int(len(ids_flat)),
                -1.0,
                None,
                None,
                None,
                ids_flat.reshape((-1, 1)),
                corners.reshape((-1, 1, 2)),
            )

        object_points = self.board_corners[ids_flat].reshape((-1, 1, 3)).astype(np.float32)
        image_points = corners.reshape((-1, 1, 2)).astype(np.float32)
        try:
            ok, rvec, tvec = cv2.solvePnP(
                object_points,
                image_points,
                camera_matrix,
                dist_coeffs,
                flags=cv2.SOLVEPNP_ITERATIVE,
            )
        except cv2.error as exc:
            self._put_overlay_text(annotated, f"solvePnP failed: {exc}", color=(0, 0, 255))
            return PoseEstimate(False, "solvePnP failed", annotated, marker_count, int(len(ids_flat)), -1.0, None, None, None, None, None)

        if not ok:
            self._put_overlay_text(annotated, "solvePnP failed", color=(0, 0, 255))
            return PoseEstimate(False, "solvePnP failed", annotated, marker_count, int(len(ids_flat)), -1.0, None, None, None, None, None)

        projected, _ = cv2.projectPoints(object_points, rvec, tvec, camera_matrix, dist_coeffs)
        diff = projected.reshape((-1, 2)) - image_points.reshape((-1, 2))
        reprojection_error = float(math.sqrt(float(np.mean(np.sum(diff * diff, axis=1)))))
        rotation, _ = cv2.Rodrigues(rvec)
        t_camera_board = _make_homogeneous(rotation, tvec.reshape((3,)))

        cv2.drawFrameAxes(
            annotated,
            camera_matrix,
            dist_coeffs,
            rvec,
            tvec,
            float(self.board_square_length_m * 2.0),
        )
        self._put_overlay_text(
            annotated,
            f"corners={len(ids_flat)} reproj={reprojection_error:.3f}px",
            color=(0, 220, 0),
        )
        return PoseEstimate(
            True,
            "pose ok",
            annotated,
            marker_count,
            int(len(ids_flat)),
            reprojection_error,
            np.asarray(rvec, dtype=np.float64).reshape((3, 1)),
            np.asarray(tvec, dtype=np.float64).reshape((3, 1)),
            t_camera_board,
            ids_flat.reshape((-1, 1)),
            image_points,
        )

    def snapshot(self) -> DisplaySnapshot:
        with self._lock:
            return DisplaySnapshot(
                frame_bgr=self._latest_snapshot.frame_bgr.copy(),
                text=self._latest_snapshot.text,
                marker_count=self._latest_snapshot.marker_count,
                charuco_count=self._latest_snapshot.charuco_count,
                reprojection_error_px=self._latest_snapshot.reprojection_error_px,
                has_camera_info=self._latest_snapshot.has_camera_info,
                has_handeye_result=self._latest_snapshot.has_handeye_result,
            )

    def sample_count(self) -> int:
        with self._lock:
            return len(self._samples)

    def latest_message(self) -> str:
        with self._lock:
            return self._message

    def set_message(self, message: str) -> None:
        with self._lock:
            self._message = message

    def latest_result_paths(self) -> Tuple[str, str]:
        with self._lock:
            return self._last_result_file, self._last_report_file

    def is_busy(self) -> bool:
        with self._lock:
            return self._busy

    def set_busy(self, busy: bool) -> None:
        with self._lock:
            self._busy = busy

    def new_session(self) -> str:
        with self._lock:
            self._samples = []
            self._last_result_file = ""
            self._last_report_file = ""
            self._create_session("")
            self._message = f"new validation session: {self.session_dir}"
            return str(self.session_dir)

    def call_service_sync(self, client, request, timeout_sec: float):
        if not client.wait_for_service(timeout_sec=timeout_sec):
            raise RuntimeError("service not available")
        future = client.call_async(request)
        deadline = time.time() + timeout_sec
        while rclpy.ok() and time.time() < deadline:
            if future.done():
                return future.result()
            time.sleep(0.03)
        raise TimeoutError("service call timed out")

    def set_handguide(self, enable: bool) -> str:
        request = RobotSetHandguide.Request()
        request.enable = bool(enable)
        response = self.call_service_sync(self.handguide_client, request, timeout_sec=20.0)
        if not response.success:
            raise RuntimeError(response.message)
        return response.message

    def capture_validation_sample(self, pose_label: str, notes: str) -> ValidationSample:
        if not self.handeye_result_file:
            raise RuntimeError("handeye_result_file is not loaded")

        with self._lock:
            if self._latest_raw_bgr is None or self._latest_pose is None:
                raise RuntimeError("no camera frame")
            pose = self._latest_pose
            raw_bgr = self._latest_raw_bgr.copy()
            annotated_bgr = pose.annotated_bgr.copy()
            stamp_sec = self._latest_header_stamp_sec
            frame_id = self._latest_frame_id
            sample_id = len(self._samples)
            session_dir = self.session_dir
            samples_dir = self.samples_dir
            debug_dir = self.debug_dir

        if not pose.ok:
            raise RuntimeError(f"board pose unavailable: {pose.message}")
        if pose.charuco_count < self.min_charuco_corners:
            raise RuntimeError(
                f"charuco corners too few: {pose.charuco_count}, need >= {self.min_charuco_corners}")

        robot_response = self.call_service_sync(
            self.robot_pose_client,
            RobotGetPose.Request(),
            timeout_sec=self.robot_pose_timeout_sec,
        )
        if not robot_response.success:
            raise RuntimeError(f"robot pose failed: {robot_response.message}")
        t_base_tool = _robot_pose_to_transform(robot_response.tcp_xyz_m_rpy_rad)
        t_base_board = t_base_tool @ self.t_tool_camera @ pose.t_camera_board

        prefix = f"sample_{sample_id:04d}"
        image_file = samples_dir / f"{prefix}_raw.png"
        debug_image_file = debug_dir / f"{prefix}_debug.png"
        sample_file = samples_dir / f"{prefix}.yaml"
        cv2.imwrite(str(image_file), raw_bgr)
        cv2.imwrite(str(debug_image_file), annotated_bgr)

        sample = ValidationSample(
            sample_id=sample_id,
            stamp_sec=stamp_sec,
            frame_id=frame_id,
            pose_label=pose_label.strip() or "unlabeled",
            notes=notes.strip(),
            image_file=self._record_path(image_file),
            debug_image_file=self._record_path(debug_image_file),
            sample_file=self._record_path(sample_file),
            marker_count=pose.marker_count,
            charuco_count=pose.charuco_count,
            reprojection_error_px=pose.reprojection_error_px,
            board_rvec=pose.rvec.copy(),
            board_tvec=pose.tvec.copy(),
            t_base_tool=t_base_tool,
            t_camera_board=pose.t_camera_board.copy(),
            t_base_board=t_base_board,
            charuco_ids=pose.charuco_ids.copy(),
            charuco_corners=pose.charuco_corners.copy(),
        )
        self._write_sample_file(sample)

        with self._lock:
            self._samples.append(sample)
            self._message = (
                f"sample {sample_id} saved, corners={sample.charuco_count}, "
                f"reproj={sample.reprojection_error_px:.3f}px"
            )
        return sample

    def _write_sample_file(self, sample: ValidationSample) -> None:
        fs = cv2.FileStorage(sample.sample_file, cv2.FILE_STORAGE_WRITE)
        if not fs.isOpened():
            raise RuntimeError(f"failed to write sample file: {sample.sample_file}")
        fs.write("sample_id", int(sample.sample_id))
        fs.write("stamp_sec", float(sample.stamp_sec))
        fs.write("frame_id", sample.frame_id)
        fs.write("pose_label", sample.pose_label)
        fs.write("notes", sample.notes)
        fs.write("image_file", sample.image_file)
        fs.write("debug_image_file", sample.debug_image_file)
        fs.write("marker_count", int(sample.marker_count))
        fs.write("charuco_count", int(sample.charuco_count))
        fs.write("reprojection_error_px", float(sample.reprojection_error_px))
        fs.write("board_rvec", sample.board_rvec)
        fs.write("board_tvec", sample.board_tvec)
        fs.write("T_base_tool", sample.t_base_tool)
        fs.write("T_camera_board", sample.t_camera_board)
        fs.write("T_tool_camera", self.t_tool_camera)
        fs.write("T_base_board", sample.t_base_board)
        fs.write("charuco_ids", sample.charuco_ids.astype(np.int32))
        fs.write("charuco_corners", sample.charuco_corners.reshape((-1, 2)).astype(np.float32))
        fs.release()

    def compute_validation_result(self) -> Tuple[str, str, Dict[str, object]]:
        with self._lock:
            samples = list(self._samples)
            session_dir = self.session_dir
            results_dir = self.results_dir

        if len(samples) < 2:
            raise RuntimeError("need at least 2 validation samples")

        metrics = self._compute_metrics(samples)
        result_file = results_dir / "validation_result.yaml"
        report_file = results_dir / "precision_validation_report.md"
        csv_file = results_dir / "samples.csv"
        self._write_result_yaml(result_file, csv_file, report_file, samples, metrics)
        self._write_samples_csv(csv_file, samples, metrics)
        self._write_report(report_file, result_file, csv_file, samples, metrics)

        with self._lock:
            self._last_result_file = self._record_path(result_file)
            self._last_report_file = self._record_path(report_file)
            self._message = (
                f"validation done: trans={metrics['mean_ref_translation_stats_mm']['rms']:.3f}mm, "
                f"rot={metrics['mean_ref_rotation_stats_deg']['rms']:.3f}deg"
            )
        return self._record_path(result_file), self._record_path(report_file), metrics

    def _compute_metrics(self, samples: List[ValidationSample]) -> Dict[str, object]:
        translations = np.array([sample.t_base_board[:3, 3] for sample in samples], dtype=np.float64)
        rotations = [sample.t_base_board[:3, :3] for sample in samples]
        mean_translation = np.mean(translations, axis=0)
        mean_rotation = _average_rotation(rotations)
        t_base_board_mean = _make_homogeneous(mean_rotation, mean_translation)
        t_base_board_ref0 = samples[0].t_base_board

        mean_ref_translation_mm = []
        mean_ref_rotation_deg = []
        ref0_translation_mm = []
        ref0_rotation_deg = []
        per_sample = []
        inv_ref0 = _invert_transform(t_base_board_ref0)
        for sample in samples:
            trans_mean = float(np.linalg.norm(sample.t_base_board[:3, 3] - mean_translation) * 1000.0)
            rot_mean = _rotation_angle_deg(mean_rotation.T @ sample.t_base_board[:3, :3])
            rel0 = inv_ref0 @ sample.t_base_board
            trans0 = float(np.linalg.norm(rel0[:3, 3]) * 1000.0)
            rot0 = _rotation_angle_deg(rel0[:3, :3])
            mean_ref_translation_mm.append(trans_mean)
            mean_ref_rotation_deg.append(rot_mean)
            ref0_translation_mm.append(trans0)
            ref0_rotation_deg.append(rot0)
            per_sample.append({
                "sample_id": sample.sample_id,
                "pose_label": sample.pose_label,
                "charuco_count": sample.charuco_count,
                "reprojection_error_px": sample.reprojection_error_px,
                "mean_ref_translation_mm": trans_mean,
                "mean_ref_rotation_deg": rot_mean,
                "ref0_translation_mm": trans0,
                "ref0_rotation_deg": rot0,
                "sample_file": sample.sample_file,
                "debug_image_file": sample.debug_image_file,
            })

        reproj = np.array([sample.reprojection_error_px for sample in samples], dtype=np.float64)
        charuco_counts = np.array([sample.charuco_count for sample in samples], dtype=np.float64)
        labels: Dict[str, int] = {}
        for sample in samples:
            labels[sample.pose_label] = labels.get(sample.pose_label, 0) + 1

        return {
            "sample_count": len(samples),
            "min_validation_samples": self.min_validation_samples,
            "handeye_result_file": self.handeye_result_file,
            "handeye_source_sample_count": self.handeye_source_sample_count,
            "handeye_source_reprojection_px": self.handeye_source_reprojection_px,
            "mean_ref_translation_stats_mm": _stats(np.array(mean_ref_translation_mm, dtype=np.float64)),
            "mean_ref_rotation_stats_deg": _stats(np.array(mean_ref_rotation_deg, dtype=np.float64)),
            "ref0_translation_stats_mm": _stats(np.array(ref0_translation_mm, dtype=np.float64)),
            "ref0_rotation_stats_deg": _stats(np.array(ref0_rotation_deg, dtype=np.float64)),
            "reprojection_stats_px": _stats(reproj),
            "charuco_count_stats": _stats(charuco_counts),
            "pose_label_counts": labels,
            "T_base_board_mean": t_base_board_mean,
            "T_base_board_ref0": t_base_board_ref0,
            "per_sample": per_sample,
        }

    def _write_result_yaml(
        self,
        result_file: Path,
        csv_file: Path,
        report_file: Path,
        samples: List[ValidationSample],
        metrics: Dict[str, object],
    ) -> None:
        lines = [
            "node_name: handeye_validation_ui",
            f"session_name: \"{self.session_name}\"",
            f"session_dir: \"{self._record_path(self.session_dir)}\"",
            f"handeye_result_file: \"{self.handeye_result_file}\"",
            f"sample_count: {metrics['sample_count']}",
            f"min_validation_samples: {self.min_validation_samples}",
            f"source_handeye_sample_count: {self.handeye_source_sample_count}",
            f"source_handeye_reprojection_px: {self.handeye_source_reprojection_px:.12g}",
            f"validation_translation_rms_mm: {metrics['mean_ref_translation_stats_mm']['rms']:.12g}",
            f"validation_rotation_rms_deg: {metrics['mean_ref_rotation_stats_deg']['rms']:.12g}",
            f"ref0_translation_rms_mm: {metrics['ref0_translation_stats_mm']['rms']:.12g}",
            f"ref0_rotation_rms_deg: {metrics['ref0_rotation_stats_deg']['rms']:.12g}",
            f"reprojection_rms_px: {metrics['reprojection_stats_px']['rms']:.12g}",
            f"charuco_count_mean: {metrics['charuco_count_stats']['mean']:.12g}",
            f"samples_csv: \"{self._record_path(csv_file)}\"",
            f"report_file: \"{self._record_path(report_file)}\"",
        ]
        lines.append("pose_label_counts:")
        for label, count in sorted(metrics["pose_label_counts"].items()):
            lines.append(f"  \"{label}\": {count}")
        lines.append(_format_matrix_yaml("T_tool_camera", self.t_tool_camera).rstrip())
        lines.append(_format_matrix_yaml("T_base_board_mean", metrics["T_base_board_mean"]).rstrip())
        lines.append("samples:")
        per_sample_by_id = {item["sample_id"]: item for item in metrics["per_sample"]}
        for sample in samples:
            item = per_sample_by_id[sample.sample_id]
            lines.extend([
                "  -",
                f"    sample_id: {sample.sample_id}",
                f"    pose_label: \"{sample.pose_label}\"",
                f"    charuco_count: {sample.charuco_count}",
                f"    reprojection_error_px: {sample.reprojection_error_px:.12g}",
                f"    mean_ref_translation_mm: {item['mean_ref_translation_mm']:.12g}",
                f"    mean_ref_rotation_deg: {item['mean_ref_rotation_deg']:.12g}",
                f"    ref0_translation_mm: {item['ref0_translation_mm']:.12g}",
                f"    ref0_rotation_deg: {item['ref0_rotation_deg']:.12g}",
                f"    sample_file: \"{self._record_path(sample.sample_file)}\"",
                f"    debug_image_file: \"{self._record_path(sample.debug_image_file)}\"",
            ])
        result_file.write_text("\n".join(lines) + "\n", encoding="utf-8")

    def _write_samples_csv(
        self,
        csv_file: Path,
        samples: List[ValidationSample],
        metrics: Dict[str, object],
    ) -> None:
        per_sample_by_id = {item["sample_id"]: item for item in metrics["per_sample"]}
        with csv_file.open("w", newline="", encoding="utf-8") as handle:
            writer = csv.writer(handle)
            writer.writerow([
                "sample_id",
                "pose_label",
                "charuco_count",
                "reprojection_error_px",
                "mean_ref_translation_mm",
                "mean_ref_rotation_deg",
                "ref0_translation_mm",
                "ref0_rotation_deg",
                "sample_file",
                "debug_image_file",
                "notes",
            ])
            for sample in samples:
                item = per_sample_by_id[sample.sample_id]
                writer.writerow([
                    sample.sample_id,
                    sample.pose_label,
                    sample.charuco_count,
                    f"{sample.reprojection_error_px:.9f}",
                    f"{item['mean_ref_translation_mm']:.9f}",
                    f"{item['mean_ref_rotation_deg']:.9f}",
                    f"{item['ref0_translation_mm']:.9f}",
                    f"{item['ref0_rotation_deg']:.9f}",
                    self._record_path(sample.sample_file),
                    self._record_path(sample.debug_image_file),
                    sample.notes,
                ])

    def _write_report(
        self,
        report_file: Path,
        result_file: Path,
        csv_file: Path,
        samples: List[ValidationSample],
        metrics: Dict[str, object],
    ) -> None:
        trans = metrics["mean_ref_translation_stats_mm"]
        rot = metrics["mean_ref_rotation_stats_deg"]
        reproj = metrics["reprojection_stats_px"]
        charuco = metrics["charuco_count_stats"]
        ref0_trans = metrics["ref0_translation_stats_mm"]
        ref0_rot = metrics["ref0_rotation_stats_deg"]
        warning = ""
        if len(samples) < self.min_validation_samples:
            warning = (
                f"\n> 注意：本次验证样本数为 {len(samples)}，少于建议值 "
                f"{self.min_validation_samples}，结果只能作为快速检查。\n"
            )

        labels = ", ".join(
            f"{label}: {count}" for label, count in sorted(metrics["pose_label_counts"].items())
        )
        content = f"""# 手眼标定精度验证报告

## 1. 验证对象

- 验证 session：`{self.session_name}`
- 验证数据目录：`{self._record_path(self.session_dir)}`
- 使用的手眼结果：`{self.handeye_result_file}`
- 原手眼结果样本数：`{self.handeye_source_sample_count}`
- 原手眼结果重投影 RMS：`{self.handeye_source_reprojection_px:.6f} px`
- 本次验证样本数：`{len(samples)}`
- 姿态标签分布：`{labels or "-"}`

{warning}
## 2. 主验证结论

本工具固定已有的 `T_tool_camera`，重新采集验证样本，并对每个样本计算：

`T_base_board_i = T_base_tool_i * T_tool_camera * T_camera_board_i`

如果手眼结果稳定，所有 `T_base_board_i` 应该彼此接近。

- 平移验证 RMS：`{trans['rms']:.3f} mm`
- 旋转验证 RMS：`{rot['rms']:.3f} deg`
- 重投影 RMS：`{reproj['rms']:.3f} px`

## 3. 分布统计

### 3.1 以平均板位姿为参考

- 平移：均值 `{trans['mean']:.3f} mm`，中位数 `{trans['median']:.3f} mm`，最大 `{trans['max']:.3f} mm`，P90 `{trans['p90']:.3f} mm`
- 旋转：均值 `{rot['mean']:.3f} deg`，中位数 `{rot['median']:.3f} deg`，最大 `{rot['max']:.3f} deg`，P90 `{rot['p90']:.3f} deg`

### 3.2 以第一个样本为参考

- 平移 RMS：`{ref0_trans['rms']:.3f} mm`
- 旋转 RMS：`{ref0_rot['rms']:.3f} deg`

### 3.3 图像检测质量

- 重投影：均值 `{reproj['mean']:.3f} px`，中位数 `{reproj['median']:.3f} px`，最大 `{reproj['max']:.3f} px`
- Charuco 角点数：均值 `{charuco['mean']:.2f}`，中位数 `{charuco['median']:.0f}`，最小 `{charuco['min']:.0f}`，最大 `{charuco['max']:.0f}`

## 4. 输出文件

- 机器可读结果：`{self._record_path(result_file)}`
- 单样本表格：`{self._record_path(csv_file)}`
- 单样本 YAML 和原始图像：`{self._record_path(self.samples_dir)}`
- Debug 图像：`{self._record_path(self.debug_dir)}`

## 5. 解释

- `reprojection_error_px` 只说明板子角点在图像中的 2D 拟合质量。
- `translation_rms_mm` 和 `rotation_rms_deg` 才是固定手眼结果后，多角度验证样本在机器人 base 坐标系下的一致性。
- 本报告不是重新标定报告，而是对已有手眼矩阵的独立验证报告。
"""
        report_file.write_text(content, encoding="utf-8")


class HandeyeValidationApp:
    def __init__(self, node: HandeyeValidationNode):
        self.node = node
        self.root = tk.Tk()
        self.root.title("Hand-Eye Validation")
        initial_width = max(1280, int(self.node.display_width) + 420)
        initial_height = max(800, int(self.node.display_height) + 90)
        self.root.geometry(f"{initial_width}x{initial_height}")
        self.root.minsize(1080, 720)
        self.root.resizable(True, True)

        self.status_var = tk.StringVar(value=self.node.latest_message())
        self.sample_var = tk.StringVar(value="samples: 0")
        self.detection_var = tk.StringVar(value="detection: -")
        self.handeye_var = tk.StringVar(value=f"handeye: {self.node.handeye_result_file or '-'}")
        self.result_var = tk.StringVar(value="result: -")
        self.pose_label_var = tk.StringVar(value="front")
        self.notes_var = tk.StringVar(value="")

        self.image_label = None
        self.image_photo = None
        self.action_buttons: List[ttk.Button] = []

        self._build_ui()
        self._schedule_refresh()
        self.root.protocol("WM_DELETE_WINDOW", self._on_close)

    def _build_ui(self) -> None:
        outer = ttk.Frame(self.root, padding=12)
        outer.pack(fill=tk.BOTH, expand=True)

        left = ttk.Frame(outer)
        left.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        right = ttk.Frame(outer, width=390)
        right.pack(side=tk.RIGHT, fill=tk.Y)
        right.pack_propagate(False)

        self.image_label = ttk.Label(left)
        self.image_label.pack(fill=tk.BOTH, expand=True)

        ttk.Label(right, text="标定精度验证", font=("Sans", 14, "bold")).pack(anchor=tk.W, pady=(0, 10))
        ttk.Label(right, textvariable=self.handeye_var, wraplength=360, justify=tk.LEFT).pack(
            anchor=tk.W, fill=tk.X, pady=(0, 8))

        form = ttk.Frame(right)
        form.pack(fill=tk.X, pady=(0, 10))
        ttk.Label(form, text="姿态标签").grid(row=0, column=0, sticky="w", pady=(0, 6))
        label_box = ttk.Combobox(
            form,
            textvariable=self.pose_label_var,
            values=(
                "front",
                "left_yaw",
                "right_yaw",
                "pitch_up",
                "pitch_down",
                "roll_left",
                "roll_right",
                "near",
                "far",
                "custom",
            ),
        )
        label_box.grid(row=0, column=1, sticky="ew", pady=(0, 6))
        ttk.Label(form, text="备注").grid(row=1, column=0, sticky="w")
        notes_entry = ttk.Entry(form, textvariable=self.notes_var)
        notes_entry.grid(row=1, column=1, sticky="ew")
        form.columnconfigure(1, weight=1)

        button_grid = ttk.Frame(right)
        button_grid.pack(fill=tk.X)

        self._add_button(button_grid, "拖动开启", 0, 0, lambda: self._run_action("drag on", self._handguide_on_worker))
        self._add_button(button_grid, "拖动退出", 0, 1, lambda: self._run_action("drag off", self._handguide_off_worker))
        self._add_button(button_grid, "采集验证样本", 1, 0, lambda: self._run_action("capture", self._capture_worker))
        self._add_button(button_grid, "生成报告", 1, 1, lambda: self._run_action("compute", self._compute_worker))
        self._add_button(button_grid, "新建测试", 2, 0, lambda: self._run_action("new session", self._new_session_worker))
        self._add_button(button_grid, "退出", 2, 1, self._on_close)

        button_grid.columnconfigure(0, weight=1)
        button_grid.columnconfigure(1, weight=1)

        info = ttk.Frame(right)
        info.pack(fill=tk.X, pady=(12, 0))
        ttk.Label(info, textvariable=self.status_var, wraplength=360, justify=tk.LEFT).pack(
            anchor=tk.W, fill=tk.X, pady=(0, 8))
        ttk.Label(info, textvariable=self.sample_var).pack(anchor=tk.W, fill=tk.X, pady=(0, 4))
        ttk.Label(info, textvariable=self.detection_var, wraplength=360, justify=tk.LEFT).pack(
            anchor=tk.W, fill=tk.X, pady=(0, 4))
        ttk.Label(info, textvariable=self.result_var, wraplength=360, justify=tk.LEFT).pack(
            anchor=tk.W, fill=tk.X)

    def _add_button(self, parent, text: str, row: int, column: int, command) -> None:
        button = ttk.Button(parent, text=text, command=command)
        padx = (0, 8) if column == 0 else (0, 0)
        button.grid(row=row, column=column, sticky="ew", padx=padx, pady=(0, 8))
        if text != "退出":
            self.action_buttons.append(button)

    def _set_ui_busy(self, busy: bool) -> None:
        state = tk.DISABLED if busy else tk.NORMAL
        for button in self.action_buttons:
            button.configure(state=state)

    def _schedule_refresh(self) -> None:
        snapshot = self.node.snapshot()
        frame = snapshot.frame_bgr

        label_w = self.image_label.winfo_width() if self.image_label else 0
        label_h = self.image_label.winfo_height() if self.image_label else 0
        max_w = max(320, label_w if label_w > 10 else int(self.node.display_width))
        max_h = max(240, label_h if label_h > 10 else int(self.node.display_height))

        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        pil_image = PilImage.fromarray(rgb)
        src_w, src_h = pil_image.size
        scale = min(max_w / src_w, max_h / src_h)
        target_w = max(1, int(src_w * scale))
        target_h = max(1, int(src_h * scale))
        if (target_w, target_h) != pil_image.size:
            pil_image = pil_image.resize((target_w, target_h), RESAMPLE_LANCZOS)
        self.image_photo = ImageTk.PhotoImage(image=pil_image)
        self.image_label.configure(image=self.image_photo)

        reproj_text = "-" if snapshot.reprojection_error_px < 0.0 else f"{snapshot.reprojection_error_px:.3f}px"
        self.detection_var.set(
            f"detection: {snapshot.text} | markers={snapshot.marker_count} | "
            f"corners={snapshot.charuco_count} | reproj={reproj_text}"
        )
        self.sample_var.set(
            f"samples: {self.node.sample_count()} / recommended >= {self.node.min_validation_samples}"
        )
        result_file, report_file = self.node.latest_result_paths()
        self.result_var.set(f"result: {result_file or '-'}\nreport: {report_file or '-'}")
        self.status_var.set(self.node.latest_message())
        self.root.after(33, self._schedule_refresh)

    def _run_action(self, label: str, worker_fn) -> None:
        if self.node.is_busy():
            return
        self.node.set_busy(True)
        self._set_ui_busy(True)
        self.node.set_message(f"{label}...")

        def runner():
            try:
                message = worker_fn()
            except Exception as exc:
                message = f"{label} failed: {exc}"
            self.root.after(0, lambda: self._finish_action(message))

        threading.Thread(target=runner, daemon=True).start()

    def _finish_action(self, message: str) -> None:
        self.node.set_message(message)
        self.node.set_busy(False)
        self._set_ui_busy(False)

    def _handguide_on_worker(self) -> str:
        return self.node.set_handguide(True) or "drag on"

    def _handguide_off_worker(self) -> str:
        return self.node.set_handguide(False) or "drag off"

    def _capture_worker(self) -> str:
        sample = self.node.capture_validation_sample(
            self.pose_label_var.get(),
            self.notes_var.get(),
        )
        self.notes_var.set("")
        return (
            f"sample {sample.sample_id} saved, label={sample.pose_label}, "
            f"corners={sample.charuco_count}, reproj={sample.reprojection_error_px:.3f}px"
        )

    def _compute_worker(self) -> str:
        result_file, report_file, metrics = self.node.compute_validation_result()
        return (
            f"report generated, trans={metrics['mean_ref_translation_stats_mm']['rms']:.3f}mm, "
            f"rot={metrics['mean_ref_rotation_stats_deg']['rms']:.3f}deg, report={report_file}"
        )

    def _new_session_worker(self) -> str:
        path = self.node.new_session()
        return f"new validation session: {path}"

    def _on_close(self) -> None:
        try:
            self.node.set_handguide(False)
        except Exception:
            pass
        try:
            self.node.destroy_node()
        except Exception:
            pass
        try:
            rclpy.shutdown()
        except Exception:
            pass
        self.root.after(50, self.root.destroy)

    def run(self) -> None:
        self.root.mainloop()


def main() -> None:
    rclpy.init()
    node = HandeyeValidationNode()
    spin_thread = threading.Thread(target=rclpy.spin, args=(node,), daemon=True)
    spin_thread.start()
    app = HandeyeValidationApp(node)
    try:
        app.run()
    finally:
        try:
            rclpy.shutdown()
        except Exception:
            pass
        try:
            node.destroy_node()
        except Exception:
            pass
        spin_thread.join(timeout=1.0)


if __name__ == "__main__":
    main()
