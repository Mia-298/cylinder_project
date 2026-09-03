#!/usr/bin/env bash

# ROS 2 workspace one-click dependency install + build + source
# Recommended usage:
#   source ./build_ros2_ws.sh
#
# Optional:
#   source ./build_ros2_ws.sh --packages-select yolo_cpp
#   source ./build_ros2_ws.sh --clean
#   source ./build_ros2_ws.sh --clean --packages-select yolo_cpp

set -e

EXPECTED_ROS_DISTRO="humble"
ROS_DISTRO="${ROS_DISTRO:-${EXPECTED_ROS_DISTRO}}"
ROS_SETUP="/opt/ros/${ROS_DISTRO}/setup.bash"

# If the script is placed in the workspace root, use that directory.
# Otherwise, fall back to the current directory.
SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"
if [[ -d "${SCRIPT_DIR}/src" ]]; then
  WS_DIR="${SCRIPT_DIR}"
else
  WS_DIR="$(pwd)"
fi

CLEAN_BUILD=false
COLCON_ARGS=()
PROJECT_OPENCV_DIR="${PROJECT_OPENCV_DIR:-${OpenCV_DIR:-}}"

while [[ $# -gt 0 ]]; do
  case "$1" in
    --clean)
      CLEAN_BUILD=true
      shift
      ;;
    --packages-select)
      if [[ $# -lt 2 ]]; then
        echo "[ERROR] --packages-select requires a package name"
        return 1 2>/dev/null || exit 1
      fi
      COLCON_ARGS+=(--packages-select "$2")
      shift 2
      ;;
    --packages-up-to)
      if [[ $# -lt 2 ]]; then
        echo "[ERROR] --packages-up-to requires a package name"
        return 1 2>/dev/null || exit 1
      fi
      COLCON_ARGS+=(--packages-up-to "$2")
      shift 2
      ;;
    *)
      echo "[ERROR] Unknown argument: $1"
      return 1 2>/dev/null || exit 1
      ;;
  esac
done

echo "========================================"
echo "ROS 2 workspace setup"
echo "Workspace : ${WS_DIR}"
echo "ROS distro: ${ROS_DISTRO}"
echo "========================================"

# 1. Check ROS 2 Humble before doing any package installation.
if [[ "${ROS_DISTRO}" != "${EXPECTED_ROS_DISTRO}" ]]; then
  echo "[ERROR] This workspace requires ROS 2 ${EXPECTED_ROS_DISTRO}; found ROS_DISTRO=${ROS_DISTRO}"
  return 1 2>/dev/null || exit 1
fi

if [[ ! -f "${ROS_SETUP}" ]]; then
  echo "[ERROR] ROS 2 Humble setup file not found: ${ROS_SETUP}"
  echo "        Install ROS 2 Humble before running this script."
  return 1 2>/dev/null || exit 1
fi

# shellcheck disable=SC1090
source "${ROS_SETUP}"
if [[ "${ROS_DISTRO:-}" != "${EXPECTED_ROS_DISTRO}" ]]; then
  echo "[ERROR] The sourced setup file is not ROS 2 ${EXPECTED_ROS_DISTRO}"
  return 1 2>/dev/null || exit 1
fi
echo "[OK] sourced ${ROS_SETUP}"

# 2. Check workspace.
if [[ ! -d "${WS_DIR}/src" ]]; then
  echo "[ERROR] ${WS_DIR} is not a ROS 2 workspace: src/ not found"
  return 1 2>/dev/null || exit 1
fi

cd "${WS_DIR}"

# 3. Install the workspace dependencies directly. This deliberately avoids
# rosdep so a new machine does not depend on a pre-existing rosdep cache.
APT_PACKAGES=(
  # Build tools.
  python3-colcon-common-extensions
  cmake
  build-essential

  # Native libraries and Python runtime dependencies.
  libeigen3-dev
  libopencv-dev
  libopencv-contrib-dev
  libpcl-dev
  python3-numpy
  python3-opencv
  python3-pil
  python3-tk

  # ROS 2 Humble packages used by this workspace and the RealSense driver.
  ros-humble-ament-cmake
  ros-humble-ament-index-cpp
  ros-humble-ament-index-python
  ros-humble-builtin-interfaces
  ros-humble-cv-bridge
  ros-humble-diagnostic-updater
  ros-humble-geometry-msgs
  ros-humble-image-transport
  ros-humble-launch
  ros-humble-launch-ros
  ros-humble-lifecycle-msgs
  ros-humble-message-filters
  ros-humble-nav-msgs
  ros-humble-pcl-conversions
  ros-humble-rclcpp
  ros-humble-rclcpp-action
  ros-humble-rclcpp-components
  ros-humble-rclcpp-lifecycle
  ros-humble-rclpy
  ros-humble-librealsense2
  ros-humble-rosidl-default-generators
  ros-humble-rosidl-default-runtime
  ros-humble-sensor-msgs
  ros-humble-std-msgs
  ros-humble-std-srvs
  ros-humble-tf2
  ros-humble-tf2-ros
  ros-humble-vision-msgs
  ros-humble-xacro
)

is_apt_package_installed() {
  [[ "$(dpkg-query -W -f='${Status}' "$1" 2>/dev/null)" == "install ok installed" ]]
}

NEED_APT_UPDATE=false
for package in "${APT_PACKAGES[@]}"; do
  if ! is_apt_package_installed "${package}"; then
    NEED_APT_UPDATE=true
    break
  fi
done

if [[ "${NEED_APT_UPDATE}" == true ]]; then
  if ! command -v apt-get >/dev/null 2>&1 || ! command -v sudo >/dev/null 2>&1; then
    echo "[ERROR] apt-get and sudo are required to install dependencies"
    return 1 2>/dev/null || exit 1
  fi

  echo "[INFO] Updating apt package indexes..."
  sudo apt-get update

  for package in "${APT_PACKAGES[@]}"; do
    if is_apt_package_installed "${package}"; then
      echo "[OK] already installed: ${package}"
    else
      echo "[INFO] Installing: ${package}"
      sudo apt-get install -y "${package}"
    fi
  done
else
  echo "[OK] all declared apt dependencies are already installed"
fi

echo "[OK] direct apt dependencies installed"

# 4. Select a complete OpenCV installation before configuring any package.
# The hand-eye node requires the aruco module from opencv_contrib. CMake can
# otherwise select an incomplete /usr/local installation before the distro
# packages, which makes the failure appear only in gas_handeye_calibration.
probe_opencv_dir() {
  local candidate="$1"
  local probe_dir

  [[ -f "${candidate}/OpenCVConfig.cmake" ]] || return 1
  probe_dir="$(mktemp -d /tmp/cylinder-opencv-probe.XXXXXX)"
  printf '%s\n' \
    'cmake_minimum_required(VERSION 3.16)' \
    'project(opencv_component_probe NONE)' \
    'find_package(OpenCV REQUIRED COMPONENTS core imgproc calib3d aruco imgcodecs)' \
    > "${probe_dir}/CMakeLists.txt"

  if cmake -S "${probe_dir}" -B "${probe_dir}/build" \
      -DOpenCV_DIR="${candidate}" >/dev/null 2>&1; then
    rm -rf "${probe_dir}"
    return 0
  fi

  rm -rf "${probe_dir}"
  return 1
}

OPENCV_CANDIDATES=()
if [[ -n "${PROJECT_OPENCV_DIR}" ]]; then
  OPENCV_CANDIDATES+=("${PROJECT_OPENCV_DIR}")
fi
for candidate in /usr/lib/*/cmake/opencv4 /usr/local/lib/cmake/opencv4; do
  if [[ -d "${candidate}" ]]; then
    OPENCV_CANDIDATES+=("${candidate}")
  fi
done

OPENCV_CMAKE_DIR=""
for candidate in "${OPENCV_CANDIDATES[@]}"; do
  if probe_opencv_dir "${candidate}"; then
    OPENCV_CMAKE_DIR="${candidate}"
    break
  fi
done

if [[ -z "${OPENCV_CMAKE_DIR}" ]]; then
  echo "[ERROR] No OpenCV installation with aruco was found."
  echo "        Install libopencv-dev and libopencv-contrib-dev, or set"
  echo "        PROJECT_OPENCV_DIR to a complete OpenCVConfig.cmake directory."
  return 1 2>/dev/null || exit 1
fi
echo "[OK] using OpenCV: ${OPENCV_CMAKE_DIR}"

# 5. Optional clean build.
if [[ "${CLEAN_BUILD}" == true ]]; then
  echo "[INFO] Removing build/ install/ log/..."
  rm -rf build install log
fi

# 6. Build.
echo "[INFO] Running colcon build..."
COLCON_BUILD_ARGS=(--symlink-install)
COLCON_BUILD_ARGS+=(--cmake-args "-DOpenCV_DIR=${OPENCV_CMAKE_DIR}" -DBUILD_TESTING=OFF)
colcon build \
  "${COLCON_BUILD_ARGS[@]}" \
  "${COLCON_ARGS[@]}"

echo "[OK] colcon build completed"

# 7. Source the workspace overlay.
if [[ ! -f "${WS_DIR}/install/setup.bash" ]]; then
  echo "[ERROR] Build completed but install/setup.bash was not found"
  return 1 2>/dev/null || exit 1
fi

# shellcheck disable=SC1091
source "${WS_DIR}/install/setup.bash"
echo "[OK] sourced ${WS_DIR}/install/setup.bash"

echo "========================================"
echo "Workspace is ready."
echo "========================================"

# If executed rather than sourced, explain the shell-scope behavior.
if [[ "${BASH_SOURCE[0]}" == "$0" ]]; then
  echo
  echo "[NOTE] This script was executed as a child shell."
  echo "       The build succeeded, but the sourced environment will disappear"
  echo "       after this script exits. To keep the environment in this terminal:"
  echo
  echo "       source ./$(basename "$0")"
fi
