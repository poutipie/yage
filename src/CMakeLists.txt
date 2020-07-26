cmake_minimum_required(VERSION 3.10)

project(cpp_2d_ver2)

set(CMAKE_CXX_STANDARD 11) # No explicit compiler flags if possible

add_subdirectory(yagEngine)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE yagEngine)

# Compile commands for YCM
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON)
