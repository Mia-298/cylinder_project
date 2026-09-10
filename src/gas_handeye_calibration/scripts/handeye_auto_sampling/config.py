"""Read and validate a trajectory before issuing any robot command."""

from dataclasses import dataclass
import math

import numpy as np
import yaml


@dataclass(frozen=True)
class Trajectory:
    poses: tuple
    settle_time_sec: float
    move_timeout_sec: float
    service_timeout_sec: float
    position_tolerance_m: float
    orientation_tolerance_rad: float


def _positive(value, name):
    if isinstance(value, bool) or not isinstance(value, (int, float)):
        raise ValueError(f"{name} must be a number")
    if not math.isfinite(value) or value <= 0:
        raise ValueError(f"{name} must be finite and positive")
    return float(value)


def load_trajectory(path):
    with open(path, encoding="utf-8") as stream:
        data = yaml.safe_load(stream)
    if not isinstance(data, dict):
        raise ValueError("trajectory file must contain a YAML mapping")
    expected = set(Trajectory.__dataclass_fields__) | {"frame", "angle_unit"}
    if set(data) != expected:
        raise ValueError(
            f"trajectory keys: missing={sorted(expected - set(data))}, "
            f"unknown={sorted(set(data) - expected, key=str)}")
    if data["frame"] != "base" or data["angle_unit"] != "rad":
        raise ValueError("trajectory requires frame: base and angle_unit: rad")
    if not isinstance(data["poses"], list) or not data["poses"]:
        raise ValueError("poses is empty; configure measured TCP poses first")
    poses = []
    for index, pose in enumerate(data["poses"], 1):
        if not isinstance(pose, list) or len(pose) != 6:
            raise ValueError(f"poses[{index}] requires [x, y, z, rx, ry, rz]")
        if any(isinstance(v, bool) or not isinstance(v, (int, float)) or not math.isfinite(v)
               for v in pose):
            raise ValueError(f"poses[{index}] must contain six finite numbers")
        poses.append(tuple(float(v) for v in pose))
    values = {key: _positive(data[key], key)
              for key in Trajectory.__dataclass_fields__ if key != "poses"}
    if values["move_timeout_sec"] <= values["settle_time_sec"]:
        raise ValueError("move_timeout_sec must exceed settle_time_sec")
    return Trajectory(poses=tuple(poses), **values)


def append_pose(path, pose):
    """Append one measured TCP pose while preserving the trajectory schema."""
    if len(pose) != 6 or not all(math.isfinite(float(value)) for value in pose):
        raise ValueError("pose must contain six finite numbers")
    with open(path, encoding="utf-8") as stream:
        data = yaml.safe_load(stream)
    if not isinstance(data, dict) or "poses" not in data:
        raise ValueError("trajectory file must contain a poses list")
    if not isinstance(data["poses"], list):
        raise ValueError("poses must be a YAML list")
    if data.get("frame") != "base" or data.get("angle_unit") != "rad":
        raise ValueError("trajectory requires frame: base and angle_unit: rad")
    data["poses"].append([float(value) for value in pose])
    with open(path, "w", encoding="utf-8") as stream:
        yaml.safe_dump(data, stream, sort_keys=False, allow_unicode=True)


def pose_error(actual, target):
    """Return translation distance and rotation angle, including equivalent RPY values."""
    def rotation(rpy):
        rx, ry, rz = rpy
        cx, cy, cz = math.cos(rx), math.cos(ry), math.cos(rz)
        sx, sy, sz = math.sin(rx), math.sin(ry), math.sin(rz)
        return np.array([
            [cz * cy, cz * sy * sx - sz * cx, cz * sy * cx + sz * sx],
            [sz * cy, sz * sy * sx + cz * cx, sz * sy * cx - cz * sx],
            [-sy, cy * sx, cy * cx],
        ])

    if len(actual) != 6 or not all(math.isfinite(v) for v in actual):
        raise ValueError("robot returned an invalid TCP pose")
    distance = math.sqrt(sum((a - b) ** 2 for a, b in zip(actual[:3], target[:3])))
    relative = rotation(actual[3:]).T @ rotation(target[3:])
    angle = math.acos(float(np.clip((np.trace(relative) - 1.0) / 2.0, -1.0, 1.0)))
    return distance, angle
