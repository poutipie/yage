
#include "Rectangle.hpp"

namespace YAGE {
namespace GFX {

Rectangle::Rectangle(float x, float y, float width, float height) 
    : RenderObject() {
   
    float vertices[] = {
        x, y, 0.0f,                 // top left
        x + width, y, 0.0f,         // top right
        x, y - height, 0.0f,        // bottom left
        x + width, y - height, 0.0f // bottom right
    };

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

