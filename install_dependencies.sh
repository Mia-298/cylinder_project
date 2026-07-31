#!/usr/bin/env bash
set -euo pipefail

# Resolve the directory containing this script.
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# The package is expected at:
#   <workspace>/src/yolo_cpp/install_dependencies.sh
WORKSPACE_DIR="$(cd "${SCRIPT_DIR}/../.." && pwd)"

ROS_DISTRO="${ROS_DISTRO:-humble}"

echo "[1/5] Checking ROS environment..."
if ! command -v ros2 >/dev/null 2>&1; then
  echo "Error: ros2 command was not found."
  echo "Source ROS 2 first, for example:"
  echo "  source /opt/ros/${ROS_DISTRO}/setup.bash"
  exit 1
fi

echo "[2/5] Updating apt package index..."
sudo apt update

echo "[3/5] Installing required system packages..."
sudo apt install -y \
  python3-rosdep \
  python3-colcon-common-extensions \
  "ros-${ROS_DISTRO}-cv-bridge" \
  "ros-${ROS_DISTRO}-sensor-msgs" \
  "ros-${ROS_DISTRO}-rclcpp" \
  libopencv-dev

echo "[4/5] Initializing rosdep if necessary..."
if [ ! -f /etc/ros/rosdep/sources.list.d/20-default.list ]; then
  sudo rosdep init
fi

rosdep update

echo "[5/5] Resolving dependencies declared by packages in src/..."
cd "${WORKSPACE_DIR}"
rosdep install \
  --from-paths src \
  --ignore-src \
  --rosdistro "${ROS_DISTRO}" \
  -r \
  -y

if [ -s "${SCRIPT_DIR}/requirements.txt" ]; then
  echo "Installing optional Python dependencies..."
  python3 -m pip install -r "${SCRIPT_DIR}/requirements.txt"
fi

echo
echo "Dependencies installed successfully."
echo "Build with:"
echo "  cd ${WORKSPACE_DIR}"
echo "  colcon build --packages-select yolo_cpp --symlink-install"
echo "  source install/setup.bash"
