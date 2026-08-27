cmake_minimum_required(VERSION 3.8)
project(gas_grasp_execution)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(gas_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(vision_msgs REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS core)

add_executable(gas_grasp_execution_node
  src/main.cpp
  src/grasp_execution_node.cpp
)
target_compile_features(gas_grasp_execution_node PUBLIC cxx_std_17)
target_include_directories(gas_grasp_execution_node PRIVATE
  include
  ${OpenCV_INCLUDE_DIRS}
)
ament_target_dependencies(gas_grasp_execution_node
  gas_interfaces
  rclcpp
  vision_msgs
)
target_link_libraries(gas_grasp_execution_node
  opencv_core
)

get_filename_component(_opencv_cmake_dir "${OpenCV_DIR}" DIRECTORY)
get_filename_component(_opencv_runtime_dir "${_opencv_cmake_dir}" DIRECTORY)
set_target_properties(gas_grasp_execution_node PROPERTIES
  BUILD_RPATH "${_opencv_runtime_dir}"
  INSTALL_RPATH "${_opencv_runtime_dir}"
)

install(TARGETS
  gas_grasp_execution_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  include/
  DESTINATION include
)

install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
