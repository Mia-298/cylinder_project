cmake_minimum_required(VERSION 3.8)
project(gas_handeye_calibration)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(gas_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS core imgproc calib3d aruco imgcodecs)

add_executable(handeye_calibration_node
  src/handeye_calibration_node.cpp
  src/main.cpp
)
target_compile_features(handeye_calibration_node PUBLIC cxx_std_17)
target_include_directories(handeye_calibration_node PRIVATE
  ${OpenCV_INCLUDE_DIRS}
)
ament_target_dependencies(handeye_calibration_node
  cv_bridge
  gas_interfaces
  rclcpp
  sensor_msgs
  std_msgs
)
target_link_libraries(handeye_calibration_node
  opencv_core
  opencv_imgproc
  opencv_calib3d
  opencv_aruco
  opencv_imgcodecs
)

get_filename_component(_opencv_cmake_dir "${OpenCV_DIR}" DIRECTORY)
get_filename_component(_opencv_runtime_dir "${_opencv_cmake_dir}" DIRECTORY)
set_target_properties(handeye_calibration_node PROPERTIES
  BUILD_RPATH "${_opencv_runtime_dir}"
  INSTALL_RPATH "${_opencv_runtime_dir}"
)

install(TARGETS
  handeye_calibration_node
  DESTINATION lib/${PROJECT_NAME}
)

install(PROGRAMS
  scripts/handeye_capture_ui.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
