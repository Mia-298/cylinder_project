#!/usr/bin/env python3
"""Plot manual pose/object log distance curves grouped by point."""

from __future__ import annotations

import argparse
import csv
import math
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional, Sequence

import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
from matplotlib.font_manager import FontProperties
import numpy as np


FONT_PATH = "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc"


def to_float(text: str) -> float:
    try:
        return float(text)
    except (TypeError, ValueError):
        return math.nan


def load_rows(path: Path) -> List[Dict[str, str]]:
    columns: Optional[List[str]] = None
    rows: List[Dict[str, str]] = []

    with path.open("r", encoding="utf-8") as file_handle:
        for raw_line in file_handle:
            line = raw_line.rstrip("\n")
            if not line:
                continue
            if line.startswith("# columns:"):
                columns = line.split(":", 1)[1].strip().split("\t")
                continue
            if line.startswith("#"):
                continue
            if columns is None:
                raise RuntimeError("missing '# columns:' header")
            values = line.split("\t")
            if len(values) < len(columns):
                values += [""] * (len(columns) - len(values))
            rows.append(dict(zip(columns, values)))

    return rows


def point_index(row: Dict[str, str]) -> int:
    return int(row.get("point_index") or row.get("index") or "0")


def sample_index(row: Dict[str, str]) -> int:
    return int(row.get("sample_index") or "1")


def xy_angle_deg(tcp_xy: np.ndarray, object_xy: np.ndarray) -> float:
    tcp_norm = float(np.linalg.norm(tcp_xy))
    object_norm = float(np.linalg.norm(object_xy))
    if tcp_norm < 1e-12 or object_norm < 1e-12:
        return math.nan
    cos_value = float(np.dot(tcp_xy, object_xy) / (tcp_norm * object_norm))
    cos_value = min(1.0, max(-1.0, cos_value))
    return math.degrees(math.acos(cos_value))


def group_rows(rows: Sequence[Dict[str, str]]) -> Dict[int, List[Dict[str, str]]]:
    grouped: Dict[int, List[Dict[str, str]]] = defaultdict(list)
    for row in rows:
        grouped[point_index(row)].append(row)
    for group in grouped.values():
        group.sort(key=sample_index)
    return dict(sorted(grouped.items()))


def point_stats(group: Sequence[Dict[str, str]]) -> Dict[str, float]:
    tcp_x = to_float(group[0].get("tcp_base_x_m", "nan"))
    tcp_y = to_float(group[0].get("tcp_base_y_m", "nan"))

    valid_rows = [
        row for row in group
        if row.get("object_valid") == "1"
        and math.isfinite(to_float(row.get("object_base_x_m", "nan")))
        and math.isfinite(to_float(row.get("object_base_y_m", "nan")))
        and math.isfinite(to_float(row.get("object_camera_distance_m", "nan")))
    ]

    if valid_rows:
        object_x = float(np.mean([to_float(row["object_base_x_m"]) for row in valid_rows]))
        object_y = float(np.mean([to_float(row["object_base_y_m"]) for row in valid_rows]))
        distances = np.array([to_float(row["object_camera_distance_m"]) for row in valid_rows], dtype=float)
    else:
        object_x = math.nan
        object_y = math.nan
        distances = np.array([], dtype=float)

    return {
        "tcp_x": tcp_x,
        "tcp_y": tcp_y,
        "object_x": object_x,
        "object_y": object_y,
        "angle_deg": xy_angle_deg(
            np.array([tcp_x, tcp_y], dtype=float),
            np.array([object_x, object_y], dtype=float),
        ),
        "valid_count": float(len(valid_rows)),
        "mean_distance_m": float(np.mean(distances)) if len(distances) else math.nan,
        "std_distance_m": float(np.std(distances)) if len(distances) else math.nan,
        "min_distance_m": float(np.min(distances)) if len(distances) else math.nan,
        "max_distance_m": float(np.max(distances)) if len(distances) else math.nan,
    }


def make_series(group: Sequence[Dict[str, str]]) -> tuple[List[int], List[float]]:
    x_values: List[int] = []
    y_values: List[float] = []
    for row in group:
        x_values.append(sample_index(row))
        if row.get("object_valid") == "1":
            y_values.append(to_float(row.get("object_camera_distance_m", "nan")))
        else:
            y_values.append(math.nan)
    return x_values, y_values


def plot_overview(grouped: Dict[int, List[Dict[str, str]]], output: Path, font: FontProperties) -> None:
    fig, ax = plt.subplots(figsize=(13.5, 7.5), dpi=160)

    for index, group in grouped.items():
        stats = point_stats(group)
        x_values, y_values = make_series(group)
        label = (
            f"点{index} 夹角={stats['angle_deg']:.1f}deg "
            f"均值={stats['mean_distance_m']:.3f}m"
        )
        ax.plot(x_values, y_values, marker="o", markersize=2.4, linewidth=1.2, label=label)

    ax.set_title("物体和TCP在基坐标XY面投影的夹角", fontproperties=font, fontsize=16, pad=14)
    ax.set_xlabel("帧数", fontproperties=font, fontsize=12)
    ax.set_ylabel("distance / m", fontsize=12)
    ax.grid(True, alpha=0.28)
    ax.legend(prop=font, fontsize=8, loc="center left", bbox_to_anchor=(1.01, 0.5))
    fig.tight_layout()
    fig.savefig(output, bbox_inches="tight")
    plt.close(fig)


def plot_detail_pdf(grouped: Dict[int, List[Dict[str, str]]], output: Path, font: FontProperties) -> None:
    with PdfPages(output) as pdf:
        for index, group in grouped.items():
            stats = point_stats(group)
            x_values, y_values = make_series(group)

            fig, ax = plt.subplots(figsize=(10.5, 5.8), dpi=150)
            ax.plot(x_values, y_values, marker="o", markersize=3.0, linewidth=1.4, color="#1f77b4")
            ax.axhline(stats["mean_distance_m"], color="#d62728", linestyle="--", linewidth=1.1)
            ax.set_title(
                f"点{index}: 物体和TCP在基坐标XY面投影的夹角 = {stats['angle_deg']:.2f} deg",
                fontproperties=font,
                fontsize=14,
                pad=12,
            )
            ax.set_xlabel("帧数", fontproperties=font, fontsize=11)
            ax.set_ylabel("distance / m", fontsize=11)
            ax.grid(True, alpha=0.28)
            info = (
                f"valid={int(stats['valid_count'])}/{len(group)}\n"
                f"mean={stats['mean_distance_m']:.6f} m\n"
                f"std={stats['std_distance_m']:.6f} m"
            )
            ax.text(
                0.985,
                0.965,
                info,
                ha="right",
                va="top",
                transform=ax.transAxes,
                bbox={"boxstyle": "round,pad=0.35", "facecolor": "white", "alpha": 0.85, "edgecolor": "#999999"},
                fontsize=9,
            )
            fig.tight_layout()
            pdf.savefig(fig)
            plt.close(fig)


def write_summary(grouped: Dict[int, List[Dict[str, str]]], output: Path) -> None:
    with output.open("w", encoding="utf-8", newline="") as file_handle:
        writer = csv.writer(file_handle, delimiter="\t")
        writer.writerow([
            "point_index",
            "valid_count",
            "total_count",
            "xy_angle_deg",
            "mean_distance_m",
            "std_distance_m",
            "min_distance_m",
            "max_distance_m",
            "tcp_base_x_m",
            "tcp_base_y_m",
            "mean_object_base_x_m",
            "mean_object_base_y_m",
        ])
        for index, group in grouped.items():
            stats = point_stats(group)
            writer.writerow([
                index,
                int(stats["valid_count"]),
                len(group),
                f"{stats['angle_deg']:.9f}",
                f"{stats['mean_distance_m']:.9f}",
                f"{stats['std_distance_m']:.9f}",
                f"{stats['min_distance_m']:.9f}",
                f"{stats['max_distance_m']:.9f}",
                f"{stats['tcp_x']:.9f}",
                f"{stats['tcp_y']:.9f}",
                f"{stats['object_x']:.9f}",
                f"{stats['object_y']:.9f}",
            ])


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser()
    parser.add_argument("input", type=Path)
    parser.add_argument("--out-prefix", type=Path, default=None)
    return parser


def main(argv: Optional[Sequence[str]] = None) -> int:
    args = build_parser().parse_args(argv)
    input_path = args.input.expanduser()
    if args.out_prefix is None:
        out_prefix = input_path.with_suffix("")
    else:
        out_prefix = args.out_prefix.expanduser()

    font = FontProperties(fname=FONT_PATH)
    plt.rcParams["axes.unicode_minus"] = False

    rows = load_rows(input_path)
    grouped = group_rows(rows)

    overview_png = out_prefix.with_name(out_prefix.name + "_distance_overview.png")
    detail_pdf = out_prefix.with_name(out_prefix.name + "_distance_detail.pdf")
    summary_txt = out_prefix.with_name(out_prefix.name + "_distance_summary.txt")

    plot_overview(grouped, overview_png, font)
    plot_detail_pdf(grouped, detail_pdf, font)
    write_summary(grouped, summary_txt)

    print(overview_png)
    print(detail_pdf)
    print(summary_txt)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
