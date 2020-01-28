cmake_minimum_required(VERSION 3.10)

project(cpp_2d_ver2)

file(GLOB SOURCES "code/*.cpp")
include_directories("code")
add_executable(${PROJECT_NAME} ${SOURCES})

# Compile commands for YCM
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON)
