# CMakeLists.txt: CMake library for YAGEngine
cmake_minimum_required(VERSION 3.10)


# ---- Embed shaders into build ---- #

add_executable(embedfile ${CMAKE_CURRENT_SOURCE_DIR}/utils/embedfile/embedfile.c)

add_custom_command(
    OUTPUT vert.c
    COMMAND embedfile vert ${CMAKE_CURRENT_SOURCE_DIR}/shaders/vert.glsl
    DEPENDS shaders/vert.glsl
)

add_custom_command(
    OUTPUT frag.c
    COMMAND embedfile frag ${CMAKE_CURRENT_SOURCE_DIR}/shaders/frag.glsl
    DEPENDS shaders/frag.glsl
)

# ---- Copy engine default assets to package ---- #
file( COPY res/yage
      DESTINATION ${PROJECT_BINARY_DIR}/assets
)


# --- Make yagEngine Library ---- #

SET ( OpenGL_GL_PREFERENCE GLVND) # Prefer GLVND library
find_package(OpenGL REQUIRED) # Use Common OpenGL package library
find_package(glfw3 REQUIRED) # Use Common glfw package library
find_package(Freetype REQUIRED) # Use common freetype package

add_subdirectory(3rdp/glm) # Add the GLM subdirectory
add_subdirectory(3rdp/stb_image) # Add the STB Image subdirectory

add_library(yagEngine STATIC
    3rdp/glad/src/glad.c # Just add this too so the library can use the glad 
    demo1.hpp
    demo1.cpp
    src/gl_class/SimpleShaderPipeline.cpp
    src/gl_class/Vao.cpp
    src/gl_class/GLTexture.cpp
    src/Rectangle.cpp
    src/RenderObject.cpp
    src/SimpleRenderer.cpp
    src/fs/AssetBundle.cpp
    vert.c # The common vertex shader
    frag.c # The common fragment shader
)

target_include_directories(yagEngine PRIVATE
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIRS}
    ${FREETYPE_INCLUDE_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdp/glad/include" # The glad library 
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdp/stb_image"    # The stb_image library
    "${CMAKE_CURRENT_SOURCE_DIR}/src/gl_class"     # Source modules for the GL_CLASS types
    "${CMAKE_CURRENT_SOURCE_DIR}/src/fs"           # FileSystem Modules
    "${CMAKE_CURRENT_SOURCE_DIR}/src"              # Engine source modules
)

# Make an include directory from which yagEngine routines can be found
target_include_directories(yagEngine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)


# ---- Link dependencies to yagEngine ---- #

target_link_libraries(yagEngine 
    ${OPENGL_gl_LIBRARY}
    ${FREETYPE_LIBRARIES}
    glfw glm stb_image
    ${CMAKE_DL_LIBS})

get_target_property(target_includes yagEngine INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "${PROJECT_NAME} target includes: " ${target_includes})

# Compile commands for YCM
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON)
