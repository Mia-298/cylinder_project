#!/usr/bin/env python3
"""Generate the 300 mm RealSense D435i ChArUco + center QR board.

The geometry in this file is the implementation of
``标定板设计规格_RealSense_D435i.md``.  Coordinates in the specification use
an origin at the top-left of the board and +Y down the board.  ReportLab uses
a bottom-left origin, so the conversion is kept in one helper below.

Dependencies:
    python -m pip install reportlab segno opencv-contrib-python-headless

Example:
    python generate_rsd435i_calibration_board.py -o rsd435i_board_001.pdf
    python generate_rsd435i_calibration_board.py -o board.pdf --board-id 002
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path
from typing import Iterable, Sequence


try:
    import cv2
    import numpy as np
    from reportlab.lib.colors import black, white
    from reportlab.pdfgen import canvas
    import segno
except ImportError as exc:  # pragma: no cover - exercised when dependencies are absent
    missing = getattr(exc, "name", "a required package")
    raise SystemExit(
        f"Missing dependency: {missing}. Install all dependencies with:\n"
        "  python -m pip install reportlab segno opencv-contrib-python-headless"
    ) from exc


# All physical dimensions are millimetres unless a variable explicitly says px.
MM_TO_PT = 72.0 / 25.4
BOARD_MM = 300.0
PAGE_MM = 320.0
PAGE_MARGIN_MM = 10.0
GRID_ORIGIN_MM = 25.0
GRID_SQUARES_X = 10
GRID_SQUARES_Y = 10
SQUARE_MM = 25.0
ARUCO_MARKER_MM = 18.0
ARUCO_DICT_NAME = "DICT_5X5_1000"
QR_PANEL_MM = 90.0
QR_PANEL_BORDER_MM = 2.0
QR_SYMBOL_MM = 78.0
QR_VERSION = 4
QR_ERROR = "m"
QR_PAYLOAD_TEMPLATE = "RSD4;ID={board_id};P=25.000;N=10x10;D=5X5-1000;R=1"
LABEL_TEMPLATE = "RSD4 CAL {board_id} | P25 | 10x10 | CHARUCO"


def mm(value: float) -> float:
    """Convert millimetres to PDF points."""

    return value * MM_TO_PT


def board_rect(page_x_mm: float, page_y_mm: float, x: float, y: float,
               width: float, height: float) -> tuple[float, float, float, float]:
    """Map a top-left/+Y-down board rectangle to ReportLab coordinates."""

    return (
        mm(page_x_mm + x),
        mm(page_y_mm + BOARD_MM - y - height),
        mm(width),
        mm(height),
    )


def draw_board_rect(pdf: canvas.Canvas, page_x_mm: float, page_y_mm: float,
                    x: float, y: float, width: float, height: float,
                    *, fill=white, stroke=None, line_width_mm: float = 0.0) -> None:
    """Draw a rectangle using board coordinates."""

    left, bottom, width_pt, height_pt = board_rect(
        page_x_mm, page_y_mm, x, y, width, height
    )
    pdf.setFillColor(fill)
    if stroke is None:
        pdf.setStrokeColor(fill)
        stroke_flag = 0
    else:
        pdf.setStrokeColor(stroke)
        stroke_flag = 1
        if line_width_mm > 0:
            pdf.setLineWidth(mm(line_width_mm))
    pdf.rect(left, bottom, width_pt, height_pt, stroke=stroke_flag, fill=1)


def draw_board_line(pdf: canvas.Canvas, page_x_mm: float, page_y_mm: float,
                    points: Sequence[tuple[float, float]], *, line_width_mm: float,
                    color=black) -> None:
    """Draw a polyline in top-left/+Y-down board coordinates."""

    if len(points) < 2:
        return
    path = pdf.beginPath()
    x0, y0 = points[0]
    path.moveTo(mm(page_x_mm + x0), mm(page_y_mm + BOARD_MM - y0))
    for x, y in points[1:]:
        path.lineTo(mm(page_x_mm + x), mm(page_y_mm + BOARD_MM - y))
    pdf.setStrokeColor(color)
    pdf.setLineWidth(mm(line_width_mm))
    pdf.drawPath(path, stroke=1, fill=0)


def validate_board_id(board_id: str) -> str:
    """Return a QR-safe board id or raise a useful command-line error."""

    if not re.fullmatch(r"[A-Za-z0-9_-]{1,12}", board_id):
        raise ValueError("board-id must contain 1-12 ASCII letters, digits, '_' or '-'")
    return board_id


def make_qr(payload: str):
    """Create a non-Micro QR, preferring version 4-M and allowing version 5-M.

    The payload is intentionally short so the QR modules remain large at the
    specified 78 mm physical size.  Segno may select a larger version if a
    custom board id increases the payload length.
    """

    last_error: Exception | None = None
    for version in (QR_VERSION, QR_VERSION + 1):
        try:
            qr = segno.make(
                payload,
                error=QR_ERROR,
                version=version,
                micro=False,
                boost_error=False,
            )
            if getattr(qr, "is_micro", False):
                raise ValueError("Micro QR was selected unexpectedly")
            actual_version = getattr(qr, "version", None)
            if actual_version != version:
                raise ValueError(
                    f"QR library selected version {actual_version!r}, expected {version}"
                )
            return qr, version
        except Exception as exc:  # segno uses ValueError for a payload that is too long
            last_error = exc
    raise ValueError(
        "QR payload does not fit Version 4-M or Version 5-M; shorten board-id"
    ) from last_error


def draw_checker_background(pdf: canvas.Canvas, page_x_mm: float, page_y_mm: float) -> None:
    """Draw the 10x10 black/white checker background."""

    for row in range(GRID_SQUARES_Y):
        for col in range(GRID_SQUARES_X):
            # The top-left square is black, matching the written specification.
            if (row + col) % 2 == 0:
                draw_board_rect(
                    pdf,
                    page_x_mm,
                    page_y_mm,
                    GRID_ORIGIN_MM + col * SQUARE_MM,
                    GRID_ORIGIN_MM + row * SQUARE_MM,
                    SQUARE_MM,
                    SQUARE_MM,
                    fill=black,
                )


def _get_aruco_dictionary():
    """Get the dictionary while supporting OpenCV 4.x API spelling."""

    aruco = cv2.aruco
    dictionary_id = getattr(aruco, ARUCO_DICT_NAME)
    return aruco.getPredefinedDictionary(dictionary_id)


def _board_marker_geometry(board) -> tuple[Iterable, Iterable]:
    """Read marker object points and ids across OpenCV Python API variants."""

    get_obj_points = getattr(board, "getObjPoints", None)
    get_ids = getattr(board, "getIds", None)
    if get_obj_points is None or get_ids is None:
        raise RuntimeError(
            "This OpenCV build does not expose CharucoBoard.getObjPoints/getIds; "
            "install a recent opencv-contrib-python-headless build."
        )
    obj_points = get_obj_points()
    ids = np.asarray(get_ids()).reshape(-1)
    if len(obj_points) != len(ids):
        raise RuntimeError("OpenCV returned mismatched ChArUco marker points and ids")
    return obj_points, ids


def _marker_matrix(dictionary, marker_id: int) -> list[list[bool]]:
    """Read one ArUco marker as a module matrix.

    ``generateImageMarker`` is used only as a convenient source of the official
    dictionary bits.  The final PDF is still vector geometry: every dark/light
    module is painted as an individual PDF rectangle.
    """

    marker_size = int(getattr(dictionary, "markerSize", 5))
    border_bits = 1
    module_count = marker_size + 2 * border_bits
    pixels_per_module = 100
    image = cv2.aruco.generateImageMarker(
        dictionary, int(marker_id), module_count * pixels_per_module,
        borderBits=border_bits
    )
    matrix: list[list[bool]] = []
    for row in range(module_count):
        row_values: list[bool] = []
        for col in range(module_count):
            sample = image[
                row * pixels_per_module + pixels_per_module // 2,
                col * pixels_per_module + pixels_per_module // 2,
            ]
            row_values.append(int(sample) < 128)
        matrix.append(row_values)
    return matrix


def draw_charuco_markers(pdf: canvas.Canvas, page_x_mm: float, page_y_mm: float) -> None:
    """Draw official ChArUco marker modules as vector rectangles."""

    dictionary = _get_aruco_dictionary()
    board = cv2.aruco.CharucoBoard(
        (GRID_SQUARES_X, GRID_SQUARES_Y),
        SQUARE_MM / 1000.0,
        ARUCO_MARKER_MM / 1000.0,
        dictionary,
    )
    marker_points, marker_ids = _board_marker_geometry(board)
    module_count = int(getattr(dictionary, "markerSize", 5)) + 2
    module_mm = ARUCO_MARKER_MM / module_count

    for obj, marker_id in zip(marker_points, marker_ids):
        points = np.asarray(obj, dtype=float).reshape(-1, 3) * 1000.0
        min_x = float(points[:, 0].min()) + GRID_ORIGIN_MM
        min_y = float(points[:, 1].min()) + GRID_ORIGIN_MM
        matrix = _marker_matrix(dictionary, int(marker_id))
        for row, values in enumerate(matrix):
            for col, is_black in enumerate(values):
                # Paint white modules too: the checker background must not show
                # through a marker's white cells.
                draw_board_rect(
                    pdf,
                    page_x_mm,
                    page_y_mm,
                    min_x + col * module_mm,
                    min_y + row * module_mm,
                    module_mm,
                    module_mm,
                    fill=black if is_black else white,
                )


def draw_qr(pdf: canvas.Canvas, page_x_mm: float, page_y_mm: float,
            payload: str) -> int:
    """Draw the center QR as vector modules and return its actual version."""

    qr, actual_version = make_qr(payload)
    matrix = list(qr.matrix_iter(scale=1, border=4))
    matrix_size = len(matrix)
    if matrix_size not in (41, 45):
        raise RuntimeError(
            f"Unexpected QR matrix size {matrix_size}; expected Version 4/5 with quiet zone"
        )
    module_mm = QR_SYMBOL_MM / matrix_size
    qr_x = (BOARD_MM - QR_SYMBOL_MM) / 2.0
    qr_y = (BOARD_MM - QR_SYMBOL_MM) / 2.0
    for row, values in enumerate(matrix):
        for col, is_black in enumerate(values):
            if bool(is_black):
                draw_board_rect(
                    pdf,
                    page_x_mm,
                    page_y_mm,
                    qr_x + col * module_mm,
                    qr_y + row * module_mm,
                    module_mm,
                    module_mm,
                    fill=black,
                )
    return actual_version


def draw_qr_panel(pdf: canvas.Canvas, page_x_mm: float, page_y_mm: float) -> None:
    """Cover the center of the checkerboard with the QR white panel."""

    panel_x = (BOARD_MM - QR_PANEL_MM) / 2.0
    panel_y = (BOARD_MM - QR_PANEL_MM) / 2.0
    draw_board_rect(
        pdf, page_x_mm, page_y_mm, panel_x, panel_y,
        QR_PANEL_MM, QR_PANEL_MM, fill=white,
    )
    draw_board_rect(
        pdf, page_x_mm, page_y_mm,
        panel_x + QR_PANEL_BORDER_MM / 2.0,
        panel_y + QR_PANEL_BORDER_MM / 2.0,
        QR_PANEL_MM - QR_PANEL_BORDER_MM,
        QR_PANEL_MM - QR_PANEL_BORDER_MM,
        fill=white, stroke=black, line_width_mm=QR_PANEL_BORDER_MM,
    )


def draw_labels(pdf: canvas.Canvas, page_x_mm: float, page_y_mm: float,
                board_id: str) -> None:
    """Draw the human-readable label and top-left orientation triangle."""

    # Small filled triangle in the top border. It is not used as a calibration point.
    path = pdf.beginPath()
    triangle = [(27.0, 7.0), (33.0, 7.0), (27.0, 13.0)]
    path.moveTo(mm(page_x_mm + triangle[0][0]), mm(page_y_mm + BOARD_MM - triangle[0][1]))
    for x, y in triangle[1:]:
        path.lineTo(mm(page_x_mm + x), mm(page_y_mm + BOARD_MM - y))
    path.close()
    pdf.setFillColor(black)
    pdf.setStrokeColor(black)
    pdf.drawPath(path, stroke=0, fill=1)

    label = LABEL_TEMPLATE.format(board_id=board_id)
    pdf.setFillColor(black)
    pdf.setFont("Helvetica-Bold", mm(4.5))
    pdf.drawCentredString(
        mm(page_x_mm + BOARD_MM / 2.0),
        mm(page_y_mm + BOARD_MM - 289.0),
        label,
    )


def draw_crop_marks(pdf: canvas.Canvas, page_x_mm: float, page_y_mm: float) -> None:
    """Draw optional marks outside the board, never inside the calibration area."""

    pdf.setStrokeColor(black)
    pdf.setLineWidth(mm(0.25))
    for x, y, dx, dy in (
        (0.0, 0.0, -5.0, 0.0),
        (BOARD_MM, 0.0, 5.0, 0.0),
        (0.0, BOARD_MM, -5.0, 0.0),
        (BOARD_MM, BOARD_MM, 5.0, 0.0),
    ):
        # Horizontal corner ticks are deliberately outside the board edge.
        x1 = mm(page_x_mm + x)
        y1 = mm(page_y_mm + BOARD_MM - y)
        pdf.line(x1, y1, x1 + mm(dx), y1)


def generate_board_pdf(output_path: str | Path, board_id: str = "001",
                       *, crop_marks: bool = True) -> Path:
    """Generate the board PDF and return its resolved output path."""

    board_id = validate_board_id(board_id)
    output = Path(output_path).expanduser().resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    page_x_mm = PAGE_MARGIN_MM
    page_y_mm = PAGE_MARGIN_MM
    payload = QR_PAYLOAD_TEMPLATE.format(board_id=board_id)

    pdf = canvas.Canvas(str(output), pagesize=(mm(PAGE_MM), mm(PAGE_MM)),
                        pageCompression=1)
    pdf.setTitle(f"RealSense D435i calibration board {board_id}")
    pdf.setAuthor("Calibration board generator")

    # White page and rigid-board outline.
    pdf.setFillColor(white)
    pdf.rect(0, 0, mm(PAGE_MM), mm(PAGE_MM), stroke=0, fill=1)
    draw_board_rect(
        pdf, page_x_mm, page_y_mm, 0, 0, BOARD_MM, BOARD_MM,
        fill=white, stroke=black, line_width_mm=0.8,
    )

    draw_checker_background(pdf, page_x_mm, page_y_mm)
    draw_charuco_markers(pdf, page_x_mm, page_y_mm)
    draw_qr_panel(pdf, page_x_mm, page_y_mm)
    actual_qr_version = draw_qr(pdf, page_x_mm, page_y_mm, payload)
    draw_labels(pdf, page_x_mm, page_y_mm, board_id)
    if crop_marks:
        draw_crop_marks(pdf, page_x_mm, page_y_mm)

    pdf.setSubject(
        f"300 mm board; 10x10 squares; 25 mm pitch; QR version {actual_qr_version}"
    )
    pdf.showPage()
    pdf.save()
    return output


def parse_args(argv: Sequence[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate the RealSense D435i 300 mm ChArUco + center QR PDF."
    )
    parser.add_argument(
        "-o", "--output", default="rsd435i_charuco_qr_300mm_v1.pdf",
        help="output PDF path (default: %(default)s)",
    )
    parser.add_argument(
        "--board-id", default="001",
        help="1-12 ASCII characters used in the QR payload (default: %(default)s)",
    )
    parser.add_argument(
        "--no-crop-marks", action="store_true",
        help="omit the four measurement marks outside the 300 mm board",
    )
    return parser.parse_args(argv)


def main(argv: Sequence[str] | None = None) -> int:
    args = parse_args(argv)
    try:
        output = generate_board_pdf(
            args.output,
            args.board_id,
            crop_marks=not args.no_crop_marks,
        )
    except (OSError, RuntimeError, ValueError) as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 2
    print(f"Wrote {output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
