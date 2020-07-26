# CMakeLists.txt: CMake project
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11) # No explicit compiler flags if possible

add_subdirectory(yagEngine)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

# ---- Link yagEngine ---- #
target_link_libraries(${PROJECT_NAME} PRIVATE yagEngine)

