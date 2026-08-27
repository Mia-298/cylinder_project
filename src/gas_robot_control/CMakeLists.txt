cmake_minimum_required(VERSION 3.8)
project(gas_robot_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(gas_interfaces REQUIRED)
find_package(rclcpp REQUIRED)

set(_src_dir "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(AUBO_SDK_DIR "${_src_dir}/third_party/aubo_sdk")
set(AUBO_SDK_INCLUDE_DIR "${AUBO_SDK_DIR}/include")
set(AUBO_SDK_LIB_DIR "${AUBO_SDK_DIR}/lib")
set(AUBO_SDK_LIBS
  "${AUBO_SDK_LIB_DIR}/libaubo_sdk.so"
  "${AUBO_SDK_LIB_DIR}/librobot_proxy.so"
)

foreach(_sdk_lib IN LISTS AUBO_SDK_LIBS)
  if(NOT EXISTS "${_sdk_lib}")
    message(FATAL_ERROR "AUBO SDK library not found: ${_sdk_lib}")
  endif()
endforeach()

add_executable(aubo_robot_control_node src/aubo_robot_control_node.cpp)
target_compile_features(aubo_robot_control_node PUBLIC cxx_std_17)
target_include_directories(aubo_robot_control_node SYSTEM PRIVATE
  ${AUBO_SDK_INCLUDE_DIR}
  ${AUBO_SDK_INCLUDE_DIR}/aubo
)
ament_target_dependencies(aubo_robot_control_node
  gas_interfaces
  rclcpp
)
target_link_libraries(aubo_robot_control_node
  ${AUBO_SDK_LIBS}
)
set_target_properties(aubo_robot_control_node PROPERTIES
  BUILD_RPATH "${AUBO_SDK_LIB_DIR}"
  INSTALL_RPATH "$ORIGIN/../../lib"
)

install(TARGETS
  aubo_robot_control_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  config
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY
  ${AUBO_SDK_LIB_DIR}/
  DESTINATION lib
  FILES_MATCHING PATTERN "*.so*"
)

ament_package()
