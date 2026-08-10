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

ROS_DISTRO="${ROS_DISTRO:-humble}"
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

# 1. Check ROS 2 installation.
if [[ ! -f "${ROS_SETUP}" ]]; then
  echo "[ERROR] ROS 2 setup file not found: ${ROS_SETUP}"
  echo "        Install ROS 2 ${ROS_DISTRO} first, or set ROS_DISTRO correctly."
  return 1 2>/dev/null || exit 1
fi

# shellcheck disable=SC1090
source "${ROS_SETUP}"
echo "[OK] sourced ${ROS_SETUP}"

# 2. Check workspace.
if [[ ! -d "${WS_DIR}/src" ]]; then
  echo "[ERROR] ${WS_DIR} is not a ROS 2 workspace: src/ not found"
  return 1 2>/dev/null || exit 1
fi

cd "${WS_DIR}"

# 3. Install basic build tools when missing.
NEED_APT=false
command -v colcon >/dev/null 2>&1 || NEED_APT=true
command -v rosdep >/dev/null 2>&1 || NEED_APT=true

if [[ "${NEED_APT}" == true ]]; then
  echo "[INFO] Installing colcon/rosdep build tools..."
  sudo apt-get update
  sudo apt-get install -y \
    python3-colcon-common-extensions \
    python3-rosdep
fi

# 4. Initialize rosdep if necessary.
if [[ ! -f /etc/ros/rosdep/sources.list.d/20-default.list ]]; then
  echo "[INFO] Initializing rosdep..."
  sudo rosdep init || true
fi

# rosdep update does not require root.
echo "[INFO] Updating rosdep database..."
rosdep update

# 5. Install dependencies declared by packages in src/.
echo "[INFO] Installing workspace dependencies..."
rosdep install \
  --from-paths src \
  --ignore-src \
  -r \
  -y \
  --rosdistro "${ROS_DISTRO}"

echo "[OK] rosdep dependencies installed"

# 6. Optional clean build.
if [[ "${CLEAN_BUILD}" == true ]]; then
  echo "[INFO] Removing build/ install/ log/..."
  rm -rf build install log
fi

# 7. Build.
echo "[INFO] Running colcon build..."
colcon build \
  --symlink-install \
  "${COLCON_ARGS[@]}"

echo "[OK] colcon build completed"

# 8. Source the workspace overlay.
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
