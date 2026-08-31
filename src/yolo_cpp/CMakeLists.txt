cmake_minimum_required(VERSION 3.8)
project(yolo_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(gas_interfaces REQUIRED)
find_package(PCL REQUIRED COMPONENTS common io sample_consensus segmentation)
find_package(pcl_conversions REQUIRED)
find_package(message_filters REQUIRED)
find_package(vision_msgs REQUIRED)

set(
  ONNXRUNTIME_ROOT
  "${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/onnxruntime"
)
if(NOT EXISTS
  "${ONNXRUNTIME_ROOT}/include/onnxruntime_cxx_api.h")
  message(
    FATAL_ERROR
    "ONNX Runtime header not found: "
    "${ONNXRUNTIME_ROOT}/include/onnxruntime_cxx_api.h"
  )
endif()
if(NOT EXISTS
  "${ONNXRUNTIME_ROOT}/lib/libonnxruntime.so")
  message(
    FATAL_ERROR
    "ONNX Runtime library not found: "
    "${ONNXRUNTIME_ROOT}/lib/libonnxruntime.so"
  )
endif()

add_library(
  onnxruntime
  SHARED
  IMPORTED
)

set_target_properties(
  onnxruntime
  PROPERTIES
  IMPORTED_LOCATION
    "${ONNXRUNTIME_ROOT}/lib/libonnxruntime.so"
  INTERFACE_INCLUDE_DIRECTORIES
    "${ONNXRUNTIME_ROOT}/include"
)

add_executable(
  image_capture_node
  src/image_capture_node.cpp
  
)

add_executable(
  yolo_detect_node
  src/main.cpp
  src/yolo_detect_node.cpp
  src/yolov8_detector.cpp
  src/sphere_fitter.cpp
)

ament_target_dependencies(
  image_capture_node
  rclcpp
  sensor_msgs
  cv_bridge
  pcl_conversions

)

ament_target_dependencies(
  yolo_detect_node
  rclcpp
  ament_index_cpp
  gas_interfaces
  vision_msgs
  sensor_msgs
  geometry_msgs
  cv_bridge
  pcl_conversions
  message_filters
)

target_include_directories(
  image_capture_node
  PRIVATE
  ${OpenCV_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

target_include_directories(
  yolo_detect_node
  PRIVATE
  ${OpenCV_INCLUDE_DIRS}
  
)

target_link_libraries(
  image_capture_node
  ${OpenCV_LIBRARIES}
  ${PCL_LIBRARIES}
)

target_link_libraries(
  yolo_detect_node
  ${OpenCV_LIBS}
  onnxruntime
  ${PCL_LIBRARIES}
)

add_definitions(${PCL_DEFINITIONS})

set_target_properties(
  yolo_detect_node
  PROPERTIES
  BUILD_RPATH
    "${ONNXRUNTIME_ROOT}/lib"
  INSTALL_RPATH
    "$ORIGIN/.."
)

install(
  TARGETS 
  image_capture_node
  yolo_detect_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY models launch
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY
    "${ONNXRUNTIME_ROOT}/lib/"
  DESTINATION lib
  FILES_MATCHING
  PATTERN "libonnxruntime*.so*"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
