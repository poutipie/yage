
#include "Rectangle.hpp"

namespace YAGE {
namespace GFX {

Rectangle::Rectangle(float x, float y, float width, float height) 
    : RenderObject() {
    
    // Hardcoded model vertices for the rectangle:
    float vertices[] = {

        /* Model Space Vertex Coordinates */                   /* Texture Coordinates */
        0.0f - (0.5f * width), 0.0f + (0.5f * height),  0.0f,   0.0f, 1.0f,              /*top left*/  
        0.0f + (0.5f * width), 0.0f + (0.5f * height),  0.0f,   1.0f, 1.0f,              /*top right*/   
        0.0f - (0.5f * width), 0.0f - (0.5f * height), 0.0f,   0.0f, 0.0f,              /*bottom left*/
        0.0f + (0.5f * width), 0.0f - (0.5f * height), 0.0f,   1.0f, 0.0f               /*bottom right*/
    };

    set_world_position(glm::vec3(x, y, 0.0f));

    unsigned int vertices_len = sizeof(vertices);

    unsigned int indices[] = {
        0, 2, 1,
        2, 3, 1
    };

    unsigned int indices_len = sizeof(indices);

    GL_CLASS::VaoAttributeSpec spec{
        vertices, vertices_len,
        indices, indices_len,
        GL_CLASS::DRAW_HINT::STATIC,
    };

    GL_CLASS::Vao vao(spec);

    initialize_vao(vao);
}

} // GFX
} // YAGE

