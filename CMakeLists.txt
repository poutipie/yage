# CMakeLists.txt : CMake project for Cpp 2d Game, include source and define
# project specific logic here.
cmake_minimum_required(VERSION 3.10)

project("yage")


# For building the library
add_subdirectory(yage)

# Example games
add_subdirectory("examples/demo1")
add_subdirectory("examples/asteroids")
