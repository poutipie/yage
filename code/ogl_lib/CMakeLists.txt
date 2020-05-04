
# Prefer GLVND library
SET ( OpenGL_GL_PREFERENCE GLVND)

# Need to use common libraries for Opengl and glfw
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIRS})

# We are also using glad library
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/glad/include")

# ShaderPipeline module
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/shaderpipeline")

# embed shaders into build
add_executable(embedfile ${CMAKE_CURRENT_SOURCE_DIR}/embedfile/embedfile.c)

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

add_library(
    ogl_lib
    glad/src/glad.c # Just add this too so the library can use the glad 
    demo1.hpp
    demo1.cpp
    shaderpipeline/SimpleShaderPipeline.cpp
    vert.c # The common vertex shader
    frag.c # The common fragment shader
)

target_link_libraries(ogl_lib ${OPENGL_gl_LIBRARY} glfw ${CMAKE_DL_LIBS})

# Make an include directory from which ogl_lib routines can be found
target_include_directories(ogl_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Compile commands for YCM
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON)
