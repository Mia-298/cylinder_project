#!/usr/bin/python3

from __future__ import annotations

import signal
import threading
import time
from dataclasses import dataclass
from typing import Optional, Tuple

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from gas_interfaces.srv import (
    HandEyeAddSample,
    HandEyeClearSamples,
    HandEyeCompute,
    HandEyeGetStatus,
    RobotSetHandguide,
)
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
class Snapshot:
    frame_bgr: np.ndarray
    detection_text: str
    charuco_count: int
    marker_count: int
    has_camera_info: bool


def _make_charuco_board(dictionary_id: int, squares_x: int, squares_y: int,
                        square_length_m: float, marker_length_m: float):
    dictionary = cv2.aruco.getPredefinedDictionary(dictionary_id)
    if hasattr(cv2.aruco, "CharucoBoard_create"):
        board = cv2.aruco.CharucoBoard_create(
            squares_x,
            squares_y,
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


def _interpolate_charuco(gray: np.ndarray, marker_corners, marker_ids, board, charuco_detector):
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
        count = 0 if charuco_ids is None else len(charuco_ids)
        return count, charuco_corners, charuco_ids

    retval, charuco_corners, charuco_ids = cv2.aruco.interpolateCornersCharuco(
        marker_corners,
        marker_ids,
        gray,
        board,
    )
    count = 0 if retval is None else int(retval)
    return count, charuco_corners, charuco_ids


def _draw_sparse_charuco_corners(
    frame: np.ndarray,
    charuco_corners,
    charuco_ids,
    max_corners: int,
) -> int:
    ids_flat = np.asarray(charuco_ids, dtype=np.int32).reshape((-1,))
    corners = np.asarray(charuco_corners, dtype=np.float32).reshape((-1, 2))
    total = min(len(ids_flat), len(corners))
    if total <= 0:
        return 0

    limit = max(1, int(max_corners))
    if total <= limit:
        indices = np.arange(total, dtype=np.int32)
    else:
        indices = np.unique(np.linspace(0, total - 1, num=limit, dtype=np.int32))

    for idx in indices:
        pt = corners[int(idx)]
        center = (int(round(float(pt[0]))), int(round(float(pt[1]))))
        cv2.circle(frame, center, 4, (0, 220, 0), -1, cv2.LINE_AA)
        cv2.circle(frame, center, 6, (255, 255, 255), 1, cv2.LINE_AA)
    return int(len(indices))


def _camera_matrix_from_info(msg: CameraInfo) -> np.ndarray:
    if len(msg.k) != 9:
        return np.zeros((3, 3), dtype=np.float64)
    return np.array(msg.k, dtype=np.float64).reshape((3, 3))


def _dist_coeffs_from_info(msg: CameraInfo) -> np.ndarray:
    if not msg.d:
        return np.zeros((1, 5), dtype=np.float64)
    return np.array(msg.d, dtype=np.float64).reshape((1, -1))


class HandeyeCaptureNode(Node):
    def __init__(self):
        super().__init__("handeye_capture_ui")

        self.image_topic = self.declare_parameter("image_topic", "/camera/color/image_raw").value
        self.camera_info_topic = self.declare_parameter(
            "camera_info_topic", "/camera/color/camera_info").value
        self.add_sample_service = self.declare_parameter(
            "add_sample_service", "/handeye/add_sample").value
        self.clear_samples_service = self.declare_parameter(
            "clear_samples_service", "/handeye/clear_samples").value
        self.compute_service = self.declare_parameter(
            "compute_service", "/handeye/compute").value
        self.status_service = self.declare_parameter(
            "status_service", "/handeye/status").value
        self.handguide_service = self.declare_parameter(
            "handguide_service", "/robot/handguide").value
        self.board_dictionary_id = self.declare_parameter(
            "board_dictionary_id", 7).value
        self.board_squares_x = self.declare_parameter("board_squares_x", 10).value
        self.board_squares_y = self.declare_parameter("board_squares_y", 7).value
        self.board_square_length_m = self.declare_parameter(
            "board_square_length_m", 0.025).value
        self.board_marker_length_m = self.declare_parameter(
            "board_marker_length_m", 0.018).value
        self.display_charuco_corner_limit = int(self.declare_parameter(
            "display_charuco_corner_limit", 12).value)
        self.display_width = self.declare_parameter("display_width", 1280).value
        self.display_height = self.declare_parameter("display_height", 960).value

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

        self.add_sample_client = self.create_client(HandEyeAddSample, self.add_sample_service)
        self.clear_samples_client = self.create_client(
            HandEyeClearSamples, self.clear_samples_service)
        self.compute_client = self.create_client(HandEyeCompute, self.compute_service)
        self.status_client = self.create_client(HandEyeGetStatus, self.status_service)
        self.handguide_client = self.create_client(RobotSetHandguide, self.handguide_service)

        self._lock = threading.Lock()
        self._latest_snapshot = Snapshot(
            frame_bgr=self._placeholder_frame("waiting for camera"),
            detection_text="waiting for camera",
            charuco_count=0,
            marker_count=0,
            has_camera_info=False,
        )
        self._latest_camera_matrix = np.zeros((3, 3), dtype=np.float64)
        self._latest_dist_coeffs = np.zeros((1, 5), dtype=np.float64)
        self._latest_sample_count = 0
        self._latest_result_file = ""
        self._latest_message = "ready"
        self._busy = False
        self._closing = False
        self._refresh_after_id = None

    def _placeholder_frame(self, text: str) -> np.ndarray:
        frame = np.zeros((720, 1280, 3), dtype=np.uint8)
        self._put_overlay_text(frame, text, color=(0, 220, 255))
        return frame

    def _put_overlay_text(self, frame: np.ndarray, text: str, color=(0, 255, 0)) -> None:
        lines = [line for line in text.splitlines() if line.strip()]
        if not lines:
            return
        y = 40
        for line in lines:
            cv2.putText(
                frame,
                line,
                (20, y),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.85,
                color,
                2,
                cv2.LINE_AA,
            )
            y += 34

    def _camera_info_callback(self, msg: CameraInfo) -> None:
        with self._lock:
            self._latest_camera_matrix = _camera_matrix_from_info(msg)
            self._latest_dist_coeffs = _dist_coeffs_from_info(msg)

    def _image_callback(self, msg: Image) -> None:
        try:
            frame_bgr = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        except Exception as exc:
            self.get_logger().warn(f"failed to convert image: {exc}")
            return

        with self._lock:
            camera_matrix = self._latest_camera_matrix.copy()
            dist_coeffs = self._latest_dist_coeffs.copy()
            has_camera_info = bool(np.count_nonzero(camera_matrix))

        snapshot = self._annotate_frame(frame_bgr, camera_matrix, dist_coeffs, has_camera_info)

        with self._lock:
            self._latest_snapshot = snapshot

    def _annotate_frame(
        self,
        frame_bgr: np.ndarray,
        camera_matrix: np.ndarray,
        dist_coeffs: np.ndarray,
        has_camera_info: bool,
    ) -> Snapshot:
        annotated = frame_bgr.copy()
        gray = cv2.cvtColor(frame_bgr, cv2.COLOR_BGR2GRAY)

        detection_text = "no camera info" if not has_camera_info else "no board detected"
        charuco_count = 0
        marker_count = 0

        if has_camera_info:
            marker_corners, marker_ids, _ = _detect_markers(
                gray,
                self.dictionary,
                self.detector_params,
                self.aruco_detector,
            )
            if marker_ids is not None and len(marker_ids) > 0:
                marker_count = int(len(marker_ids))
                cv2.aruco.drawDetectedMarkers(annotated, marker_corners, marker_ids)
                retval, charuco_corners, charuco_ids = _interpolate_charuco(
                    gray,
                    marker_corners,
                    marker_ids,
                    self.board,
                    self.charuco_detector,
                )
                if retval is not None and int(retval) > 0 and charuco_corners is not None:
                    charuco_count = int(retval)
                    preview_count = _draw_sparse_charuco_corners(
                        annotated,
                        charuco_corners,
                        charuco_ids,
                        self.display_charuco_corner_limit,
                    )
                    detection_text = (
                        f"charuco corners: {charuco_count} "
                        f"(showing {preview_count})"
                    )
                else:
                    detection_text = f"markers: {marker_count}"

        color = (0, 220, 0) if charuco_count > 0 else (0, 220, 255)
        self._put_overlay_text(annotated, detection_text, color=color)
        return Snapshot(
            frame_bgr=annotated,
            detection_text=detection_text,
            charuco_count=charuco_count,
            marker_count=marker_count,
            has_camera_info=has_camera_info,
        )

    def snapshot(self) -> Snapshot:
        with self._lock:
            return Snapshot(
                frame_bgr=self._latest_snapshot.frame_bgr.copy(),
                detection_text=self._latest_snapshot.detection_text,
                charuco_count=self._latest_snapshot.charuco_count,
                marker_count=self._latest_snapshot.marker_count,
                has_camera_info=self._latest_snapshot.has_camera_info,
            )

    def latest_sample_count(self) -> int:
        with self._lock:
            return self._latest_sample_count

    def latest_result_file(self) -> str:
        with self._lock:
            return self._latest_result_file

    def latest_message(self) -> str:
        with self._lock:
            return self._latest_message

    def set_message(self, message: str) -> None:
        with self._lock:
            self._latest_message = message

    def set_busy(self, busy: bool) -> None:
        with self._lock:
            self._busy = busy

    def is_busy(self) -> bool:
        with self._lock:
            return self._busy

    def update_sample_count(self, sample_count: int) -> None:
        with self._lock:
            self._latest_sample_count = sample_count

    def update_result_file(self, result_file: str) -> None:
        with self._lock:
            self._latest_result_file = result_file

    def call_service_sync(self, client, request, timeout_sec: float = 30.0):
        if not client.wait_for_service(timeout_sec=timeout_sec):
            raise RuntimeError("service not available")
        future = client.call_async(request)
        deadline = time.time() + timeout_sec
        while rclpy.ok() and time.time() < deadline:
            if future.done():
                return future.result()
            time.sleep(0.05)
        raise TimeoutError("service call timed out")


class HandeyeCaptureApp:
    def __init__(self, node: HandeyeCaptureNode):
        self.node = node
        self.root = tk.Tk()
        self.root.title("Hand-Eye Capture")
        initial_width = max(1280, int(self.node.display_width) + 400)
        initial_height = max(800, int(self.node.display_height) + 80)
        self.root.geometry(f"{initial_width}x{initial_height}")
        self.root.minsize(1024, 700)
        self.root.resizable(True, True)

        self.status_var = tk.StringVar(value="ready")
        self.sample_var = tk.StringVar(value="samples: 0")
        self.result_var = tk.StringVar(value="result: -")
        self.detection_var = tk.StringVar(value="detection: -")

        self.image_label = None
        self.image_photo = None

        self.capture_button = None
        self.compute_button = None
        self.clear_button = None
        self.handguide_on_button = None
        self.handguide_off_button = None
        self._closing = False
        self._refresh_after_id = None
        self._ros_watch_after_id = None

        self._build_ui()
        self._schedule_refresh()
        self._schedule_ros_watch()
        self._schedule_bootstrap_status()
        self.root.protocol("WM_DELETE_WINDOW", self._on_close)

    def _build_ui(self) -> None:
        outer = ttk.Frame(self.root, padding=12)
        outer.pack(fill=tk.BOTH, expand=True)

        left = ttk.Frame(outer)
        left.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        right = ttk.Frame(outer, width=360)
        right.pack(side=tk.RIGHT, fill=tk.Y)
        right.pack_propagate(False)

        self.image_label = ttk.Label(left)
        self.image_label.pack(fill=tk.BOTH, expand=True)

        ttk.Label(right, text="采集控制", font=("Sans", 14, "bold")).pack(anchor=tk.W, pady=(0, 12))

        button_grid = ttk.Frame(right)
        button_grid.pack(fill=tk.X)

        self.handguide_on_button = ttk.Button(
            button_grid,
            text="拖动开启",
            command=lambda: self._run_action("drag on", self._handguide_on_worker),
        )
        self.handguide_on_button.grid(row=0, column=0, sticky="ew", padx=(0, 8), pady=(0, 8))

        self.handguide_off_button = ttk.Button(
            button_grid,
            text="拖动退出",
            command=lambda: self._run_action("drag off", self._handguide_off_worker),
        )
        self.handguide_off_button.grid(row=0, column=1, sticky="ew", pady=(0, 8))

        self.capture_button = ttk.Button(
            button_grid,
            text="采集",
            command=lambda: self._run_action("capture", self._capture_worker),
        )
        self.capture_button.grid(row=1, column=0, sticky="ew", padx=(0, 8), pady=(0, 8))

        self.compute_button = ttk.Button(
            button_grid,
            text="完成采集",
            command=lambda: self._run_action("compute", self._compute_worker),
        )
        self.compute_button.grid(row=1, column=1, sticky="ew", pady=(0, 8))

        self.clear_button = ttk.Button(
            button_grid,
            text="清空样本",
            command=lambda: self._run_action("clear", self._clear_worker),
        )
        self.clear_button.grid(row=2, column=0, sticky="ew", padx=(0, 8), pady=(0, 8))

        quit_button = ttk.Button(
            button_grid,
            text="退出",
            command=self._on_close,
        )
        quit_button.grid(row=2, column=1, sticky="ew", pady=(0, 8))

        button_grid.columnconfigure(0, weight=1)
        button_grid.columnconfigure(1, weight=1)

        info_box = ttk.Frame(right)
        info_box.pack(fill=tk.X, pady=(10, 0))

        ttk.Label(info_box, textvariable=self.status_var, wraplength=320,
                  justify=tk.LEFT).pack(anchor=tk.W, fill=tk.X, pady=(0, 8))
        ttk.Label(info_box, textvariable=self.sample_var).pack(anchor=tk.W, fill=tk.X, pady=(0, 4))
        ttk.Label(info_box, textvariable=self.detection_var).pack(anchor=tk.W, fill=tk.X, pady=(0, 4))
        ttk.Label(info_box, textvariable=self.result_var, wraplength=320,
                  justify=tk.LEFT).pack(anchor=tk.W, fill=tk.X)

    def _schedule_refresh(self) -> None:
        if self._closing:
            return
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

        self.detection_var.set(
            f"detection: {snapshot.detection_text} | markers {snapshot.marker_count} | "
            f"corners {snapshot.charuco_count}")
        self.sample_var.set(f"samples: {self.node.latest_sample_count()}")
        self.result_var.set(
            f"result: {self.node.latest_result_file() or '-'}")
        self.status_var.set(self.node.latest_message())

        if not self._closing:
            try:
                self._refresh_after_id = self.root.after(33, self._schedule_refresh)
            except tk.TclError:
                self._refresh_after_id = None

    def _schedule_ros_watch(self) -> None:
        if self._closing:
            return
        if not rclpy.ok():
            self._on_close()
            return
        try:
            self._ros_watch_after_id = self.root.after(100, self._schedule_ros_watch)
        except tk.TclError:
            self._ros_watch_after_id = None

    def _schedule_bootstrap_status(self) -> None:
        threading.Thread(target=self._bootstrap_status_worker, daemon=True).start()

    def _bootstrap_status_worker(self) -> None:
        try:
            response = self.node.call_service_sync(self.node.status_client, HandEyeGetStatus.Request(),
                                                  timeout_sec=15.0)
            self.node.update_sample_count(response.sample_count)
            self.node.update_result_file(response.result_file)
            self.node.set_message(
                f"status: samples={response.sample_count}, camera={response.has_camera_info}, "
                f"robot={response.has_robot_pose}, calibration={response.has_calibration}")
        except Exception as exc:
            self.node.set_message(f"status unavailable: {exc}")

    def _set_ui_busy(self, busy: bool) -> None:
        state = tk.DISABLED if busy else tk.NORMAL
        for widget in (
            self.capture_button,
            self.compute_button,
            self.clear_button,
            self.handguide_on_button,
            self.handguide_off_button,
        ):
            if widget is not None:
                try:
                    widget.configure(state=state)
                except tk.TclError:
                    pass

    def _run_action(self, label: str, worker_fn) -> None:
        if self.node.is_busy() or self._closing:
            return
        self.node.set_busy(True)
        self._set_ui_busy(True)
        self.node.set_message(f"{label}...")

        def runner():
            try:
                message = worker_fn()
            except Exception as exc:
                message = f"{label} failed: {exc}"
            if not self._closing:
                try:
                    self.root.after(0, lambda: self._finish_action(message))
                except tk.TclError:
                    pass

        threading.Thread(target=runner, daemon=True).start()

    def _finish_action(self, message: str) -> None:
        if self._closing:
            return
        self.node.set_message(message)
        self.node.set_busy(False)
        self._set_ui_busy(False)

    def _handguide_on_worker(self) -> str:
        request = RobotSetHandguide.Request()
        request.enable = True
        response = self.node.call_service_sync(
            self.node.handguide_client,
            request,
            timeout_sec=20.0,
        )
        return response.message if response.success else f"drag on failed: {response.message}"

    def _handguide_off_worker(self) -> str:
        request = RobotSetHandguide.Request()
        request.enable = False
        response = self.node.call_service_sync(
            self.node.handguide_client,
            request,
            timeout_sec=20.0,
        )
        return response.message if response.success else f"drag off failed: {response.message}"

    def _capture_worker(self) -> str:
        response = self.node.call_service_sync(
            self.node.add_sample_client,
            HandEyeAddSample.Request(),
            timeout_sec=30.0,
        )
        if response.success:
            self.node.update_sample_count(response.sample_count)
            return (
                f"sample {response.sample_id} stored, samples={response.sample_count}, "
                f"reprojection={response.reprojection_error_px:.3f}px")
        return f"capture failed: {response.message}"

    def _compute_worker(self) -> str:
        request = HandEyeCompute.Request()
        request.output_path = ""
        response = self.node.call_service_sync(
            self.node.compute_client,
            request,
            timeout_sec=120.0,
        )
        if not response.success:
            return f"compute failed: {response.message}"

        self.node.update_result_file(response.result_file)
        self.node.update_sample_count(response.sample_count)

        exit_message = ""
        try:
            exit_response = self.node.call_service_sync(
                self.node.handguide_client,
                RobotSetHandguide.Request(enable=False),
                timeout_sec=20.0,
            )
            if not exit_response.success:
                exit_message = f", drag exit warning: {exit_response.message}"
        except Exception as exc:
            exit_message = f", drag exit warning: {exc}"

        return (
            f"compute done, samples={response.sample_count}, "
            f"rms={response.rms_reprojection_error_px:.3f}px, "
            f"result={response.result_file}{exit_message}"
        )

    def _clear_worker(self) -> str:
        response = self.node.call_service_sync(
            self.node.clear_samples_client,
            HandEyeClearSamples.Request(),
            timeout_sec=20.0,
        )
        if response.success:
            self.node.update_sample_count(0)
            self.node.update_result_file("")
            return "samples cleared"
        return f"clear failed: {response.message}"

    def _on_close(self) -> None:
        if self._closing:
            return
        self._closing = True
        self._set_ui_busy(True)
        for after_id in (self._refresh_after_id, self._ros_watch_after_id):
            if after_id is None:
                continue
            try:
                self.root.after_cancel(after_id)
            except Exception:
                pass
        self._refresh_after_id = None
        self._ros_watch_after_id = None

        def cleanup():
            try:
                request = RobotSetHandguide.Request()
                request.enable = False
                if self.node.handguide_client.wait_for_service(timeout_sec=1.0):
                    self.node.call_service_sync(
                        self.node.handguide_client,
                        request,
                        timeout_sec=2.0,
                    )
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

        threading.Thread(target=cleanup, daemon=True).start()

        try:
            self.root.quit()
        except Exception:
            pass

        try:
            self.root.destroy()
        except Exception:
            pass

    def request_close(self) -> None:
        try:
            self.root.after(0, self._on_close)
        except tk.TclError:
            self._on_close()

    def run(self) -> None:
        self.root.mainloop()


def main() -> None:
    rclpy.init()
    node = HandeyeCaptureNode()

    def spin_node():
        try:
            rclpy.spin(node)
        except Exception:
            pass

    spin_thread = threading.Thread(target=spin_node, daemon=True)
    spin_thread.start()

    app = HandeyeCaptureApp(node)
    previous_sigint = signal.getsignal(signal.SIGINT)
    previous_sigterm = signal.getsignal(signal.SIGTERM)

    def request_shutdown(_signum, _frame):
        app.request_close()

    signal.signal(signal.SIGINT, request_shutdown)
    signal.signal(signal.SIGTERM, request_shutdown)
    try:
        app.run()
    finally:
        signal.signal(signal.SIGINT, previous_sigint)
        signal.signal(signal.SIGTERM, previous_sigterm)
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
