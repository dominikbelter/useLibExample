# cmake requirements
cmake_minimum_required(VERSION 2.8)

# Build options have to be before PROJECT(...)
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE PATH "Configuration types")
SET(CMAKE_BUILD_TYPE "Release" CACHE PATH "Current build configuration")

# Example Project configuration
PROJECT(TUTORIAL_USELIBRARY)
SET(CMAKE_CXX_FLAGS "-std=c++14")

# Folders
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

# Settings
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/include")

# demos
option(BUILD_LIB_ROBOT_DEMO "Build LIB Robot Demo" ON)
mark_as_advanced(BUILD_LIB_ROBOT_DEMO)

# find Robot library
find_package(Robot REQUIRED)
include_directories(${ROBOT_INCLUDE_DIRS})
link_directories(${ROBOT_LIBRARIES})

# Executable output directory
SET(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin${OUTPUT_DIRECTORY_POSTFIX} CACHE PATH "Executable output directory")
mark_as_advanced(RUNTIME_OUTPUT_DIRECTORY)

if (MSVC)
  SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
endif()


###############################################################################
#
# Lib Robot DEMO executables
#
###############################################################################

if(BUILD_LIB_ROBOT_DEMO)
        SET(DEMO_SOURCES ./main.cpp)
        ADD_EXECUTABLE(useRobotLib ${DEMO_SOURCES})
        TARGET_LINK_LIBRARIES(useRobotLib Robot)
        INSTALL(TARGETS useRobotLib RUNTIME DESTINATION bin)
endif(BUILD_LIB_ROBOT_DEMO)
