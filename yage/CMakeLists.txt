# CMakeLists.txt: CMake library for yage
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


# --- Make yage Library ---- #

SET ( OpenGL_GL_PREFERENCE GLVND) # Prefer GLVND library
find_package(OpenGL REQUIRED) # Use Common OpenGL package library
find_package(glfw3 REQUIRED) # Use Common glfw package library
find_package(Freetype REQUIRED) # Use common freetype package


# Find ZLIB, PNG, HARFBUZZ, and BZIP since freetype requires them..
find_package(ZLIB REQUIRED)
find_package(BZip2 REQUIRED)
find_package(PNG REQUIRED)
find_library(FREETYPE_HARFBUZZ_LIB "harfbuzz")

add_subdirectory(3rdp/glm) # Add the GLM subdirectory
add_subdirectory(3rdp/stb_image) # Add the STB Image subdirectory

add_library(yage STATIC
    3rdp/glad/src/glad.c # Just add this too so the library can use the glad 
    src/gl_class/GLBindings.cpp
    src/gl_class/GLViewport.cpp
    src/gl_class/GLShaderPipeline.cpp
    src/gl_class/Vao.cpp
    src/gl_class/GLTexture.cpp
    src/Rectangle.cpp
    src/RenderObject.cpp
    src/SimpleRenderer.cpp
    src/Window.cpp
    src/fs/assets/AssetStore.cpp
    src/fs/assets/Image2D.cpp
    src/fs/assets/Font.cpp
    vert.c # The common vertex shader
    frag.c # The common fragment shader
)

target_include_directories(yage PRIVATE
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIRS}
)

# Make an include directory from which yage routines can be found
target_include_directories(yage PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${FREETYPE_INCLUDE_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdp/glad/include" # The glad library 
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdp/stb_image"    # The stb_image library
    "${CMAKE_CURRENT_SOURCE_DIR}/src/gl_class"      # Source modules for the GL_CLASS types
    "${CMAKE_CURRENT_SOURCE_DIR}/src/fs"            # FileSystem Modules
    "${CMAKE_CURRENT_SOURCE_DIR}/src/fs/assets"     # asset Modules
    "${CMAKE_CURRENT_SOURCE_DIR}/src"               # Engine source modules
)


# ---- Link dependencies to yage ---- #

target_link_libraries(yage 
    ${OPENGL_gl_LIBRARY}
    ${FREETYPE_LIBRARIES}
    ZLIB::ZLIB               # FREETYPE requies this
    BZip2::BZip2             # FREETYPE requires this
    PNG::PNG                 # FREETYPE requires this
    ${FREETYPE_HARFBUZZ_LIB} # FREETYPE requires this
    glfw glm stb_image
    ${CMAKE_DL_LIBS})

get_target_property(target_includes yage INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "${PROJECT_NAME} target includes: " ${target_includes})

# Compile commands for YCM
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON)
