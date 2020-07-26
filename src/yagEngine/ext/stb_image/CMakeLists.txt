# CMakeLists.txt: CMake library for stb_image
cmake_minimum_required(VERSION 3.10)

add_library(stb_image STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/stb_image.h
)

set_target_properties(stb_image PROPERTIES LINKER_LANGUAGE CXX)

# Make an include directory from which stb_image routines can be found.
target_include_directories(stb_image PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Compile commands for YCM
SET ( CMAKE_EXPORT_COMPILE_COMMANDS ON )
