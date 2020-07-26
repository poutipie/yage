
# Prefer GLVND library
SET ( OpenGL_GL_PREFERENCE GLVND)

# Need to use common libraries for Opengl and glfw
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Embed shaders into build
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

# Add the GLM subdirectory
add_subdirectory(ext/glm)

add_library(yagEngine STATIC
    ext/glad/src/glad.c # Just add this too so the library can use the glad 
    demo1.hpp
    demo1.cpp
    src/gl_class/SimpleShaderPipeline.cpp
    src/gl_class/Vao.cpp
    src/Rectangle.cpp
    src/RenderObject.cpp
    src/SimpleRenderer.cpp
    vert.c # The common vertex shader
    frag.c # The common fragment shader
)

target_include_directories(yagEngine PRIVATE
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/glad/include" # The glad library
    "${CMAKE_CURRENT_SOURCE_DIR}/src/gl_class"     # Source modules for the GL_CLASS types
    "${CMAKE_CURRENT_SOURCE_DIR}/src"              # Engine source modules
)

# Make an include directory from which yagEngine routines can be found
target_include_directories(yagEngine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link glfw to this together with the glm
target_link_libraries(yagEngine ${OPENGL_gl_LIBRARY} glfw glm ${CMAKE_DL_LIBS})


get_target_property(target_includes yagEngine INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "${PROJECT_NAME} target includes: " ${target_includes})

# Compile commands for YCM
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON)
