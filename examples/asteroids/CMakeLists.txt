# CMakeLists.txt: CMake project
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17) # No explicit compiler flags if possible

add_executable(asteroids ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

# ---- Link yagEngine ---- #
target_link_libraries(asteroids PRIVATE yage)
