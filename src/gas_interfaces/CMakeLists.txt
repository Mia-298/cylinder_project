cmake_minimum_required(VERSION 3.8)
project(gas_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(vision_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/HandEyeAddSample.srv"
  "srv/HandEyeClearSamples.srv"
  "srv/HandEyeCompute.srv"
  "srv/HandEyeGetStatus.srv"
  "srv/DetectObjects.srv"
  "srv/GraspExecute.srv"
  "srv/RobotConnect.srv"
  "srv/RobotGetPose.srv"
  "srv/RobotMoveJ.srv"
  "srv/RobotMoveL.srv"
  "srv/RobotSetHandguide.srv"
  "srv/RobotSetEnable.srv"
  "srv/RobotSetMotionParams.srv"
  "srv/RobotStop.srv"
  DEPENDENCIES vision_msgs
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
