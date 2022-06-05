# CMakeLists.txt: CMake project
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17) # No explicit compiler flags if possible

add_subdirectory(../../src build)

add_executable(demo1 ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

# ---- Include yagEngine headers ---- #
target_include_directories(demo1 PRIVATE
    "../../src"
)

# ---- Link yagEngine ---- #
target_link_libraries(demo1 PRIVATE yagEngine)

