cmake_minimum_required(VERSION 3.8)

# 自动设置项目名
get_filename_component(CUR_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${CUR_DIR_NAME})

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# ------配置------

# ros包依赖
set(APP_DEPENDS
    rclcpp
    rclcpp_action
    rcl_interfaces
    com_interfaces
)

# 纯.so包依赖
set(EXT_SEARCH_PATHS
)

set(EXT_DEPENDS
)

# 纯cmake包依赖
set(THIRD_PARTY_DEPENDS
)

set(THIRD_PARTY_SEARCH_PATHS
)

set(THIRD_PARTY_LIBS
    ${CMAKE_CURRENT_SOURCE_DIR}/../hyrms_export/lib/libhyrms_export.so
)

set(SRC_PATHS
)

set(INCLUDE_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/../hyrms_export/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
set(TEST_PATHS
)


# ------构建库并安装------

foreach(APP_DEPEND ${APP_DEPENDS})
    find_package(${APP_DEPEND} REQUIRED)
endforeach()

list(APPEND CMAKE_PREFIX_PATH ${THIRD_PARTY_SEARCH_PATHS})

foreach(THIRD_PARTY_DEPEND ${THIRD_PARTY_DEPENDS})
    find_package(${THIRD_PARTY_DEPEND} CONFIG REQUIRED)
endforeach()

set(EXT_DEPEND_LIBS "")

foreach(EXT_DEPEND ${EXT_DEPENDS})
    find_library(${EXT_DEPEND}Lib
        NAMES ${EXT_DEPEND}
        PATHS ${EXT_SEARCH_PATHS}
        NO_CACHE
        REQUIRED)
    list(APPEND EXT_DEPEND_LIBS ${${EXT_DEPEND}Lib})
endforeach()

set(SRC_FILES "")

foreach(DIR ${SRC_PATHS})
    file(GLOB_RECURSE DIR_SRC "${DIR}/*.cpp")
    list(APPEND SRC_FILES ${DIR_SRC})
endforeach()

add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)

target_sources(${PROJECT_NAME} PRIVATE ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    $<INSTALL_INTERFACE:include>
    ${INCLUDE_PATHS}
)
target_link_libraries(${PROJECT_NAME} ${EXT_DEPEND_LIBS} ${THIRD_PARTY_LIBS})

ament_target_dependencies(${PROJECT_NAME} ${APP_DEPENDS})

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../hyrms_export/lib/
    DESTINATION lib
)

install(
    TARGETS ${PROJECT_NAME}
    DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
    find_package(ament_cmake_gtest REQUIRED)
    foreach(TEST_DIR ${TEST_PATHS})
        file(GLOB_RECURSE TEST_FILES "${TEST_DIR}/*.cpp")
        foreach(TEST_FILE ${TEST_FILES})
            get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
            ament_add_gtest(${TEST_NAME} ${TEST_FILE})
            target_include_directories(${TEST_NAME} PRIVATE ${INCLUDE_PATHS})
            ament_target_dependencies(${TEST_NAME} rclcpp)
        endforeach()
    endforeach()
endif()


ament_package()
