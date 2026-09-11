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

# The HyRMS C++ Proxy SDK is shipped with cpp_proxy_test_v2.4.0.  Its
# generated com_interfaces package is prebuilt alongside libhyrms_export.so.
set(_project_root "${CMAKE_CURRENT_SOURCE_DIR}/../..")
set(HYRMS_PROXY_ROOT "${_project_root}/cpp_proxy_test_v2.4.0/cpp_proxy_test/src/hyrms_export")
set(HYRMS_PROXY_INCLUDE_DIR "${HYRMS_PROXY_ROOT}/include")
set(HYRMS_PROXY_LIB_DIR "${HYRMS_PROXY_ROOT}/lib")
set(HYRMS_PROXY_LIB "${HYRMS_PROXY_LIB_DIR}/libhyrms_export.so")
set(HYRMS_COM_INTERFACES_ROOT
  "${_project_root}/cpp_proxy_test_v2.4.0/cpp_proxy_test/install/com_interfaces")
set(HYRMS_COM_INTERFACES_INCLUDE_DIR "${HYRMS_COM_INTERFACES_ROOT}/include/com_interfaces")
set(HYRMS_COM_INTERFACES_LIB_DIR "${HYRMS_COM_INTERFACES_ROOT}/lib")
set(HYRMS_COM_INTERFACES_TYPESUPPORT_LIB
  "${HYRMS_COM_INTERFACES_LIB_DIR}/libcom_interfaces__rosidl_typesupport_cpp.so")

foreach(_hyrms_file IN ITEMS
    "${HYRMS_PROXY_INCLUDE_DIR}/dev/gripper/gripper.hpp"
    "${HYRMS_PROXY_LIB}"
    "${HYRMS_COM_INTERFACES_INCLUDE_DIR}/com_interfaces/srv/rm_ceu_cmd_interface.hpp"
    "${HYRMS_COM_INTERFACES_TYPESUPPORT_LIB}")
  if(NOT EXISTS "${_hyrms_file}")
    message(FATAL_ERROR "HyRMS Proxy SDK file not found: ${_hyrms_file}")
  endif()
endforeach()

add_executable(gas_grasp_execution_node
  src/main.cpp
  src/grasp_execution_node.cpp
)
target_compile_features(gas_grasp_execution_node PUBLIC cxx_std_17)
target_include_directories(gas_grasp_execution_node PRIVATE
  include
  ${OpenCV_INCLUDE_DIRS}
  ${HYRMS_PROXY_INCLUDE_DIR}
  ${HYRMS_COM_INTERFACES_INCLUDE_DIR}
)
ament_target_dependencies(gas_grasp_execution_node
  gas_interfaces
  rclcpp
  vision_msgs
)
target_link_libraries(gas_grasp_execution_node
  opencv_core
  ${HYRMS_PROXY_LIB}
  ${HYRMS_COM_INTERFACES_TYPESUPPORT_LIB}
)
target_link_options(gas_grasp_execution_node PRIVATE
  -Wl,--no-as-needed
)

get_filename_component(_opencv_cmake_dir "${OpenCV_DIR}" DIRECTORY)
get_filename_component(_opencv_runtime_dir "${_opencv_cmake_dir}" DIRECTORY)
set_target_properties(gas_grasp_execution_node PROPERTIES
  BUILD_RPATH "${_opencv_runtime_dir};${HYRMS_PROXY_LIB_DIR};${HYRMS_COM_INTERFACES_LIB_DIR}"
  INSTALL_RPATH "\$ORIGIN/../../lib;${_opencv_runtime_dir}"
)

install(TARGETS
  gas_grasp_execution_node
  DESTINATION lib/${PROJECT_NAME}
)

install(FILES
  ${HYRMS_PROXY_LIB}
  ${HYRMS_COM_INTERFACES_TYPESUPPORT_LIB}
  DESTINATION lib
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
