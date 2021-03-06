#include "DefaultRenderer.hpp"

#include <glm/gtc/type_ptr.hpp>

namespace YAGE {
namespace GFX {

extern "C" const char vert[];
extern "C" const size_t vert_len;

extern "C" const char frag[];
extern "C" const size_t frag_len;

DefaultRenderer::DefaultRenderer() 
: 
m_shader_pipeline(GL_CLASS::PipelineCompilerSpec(vert, frag)),
m_viewport(20, 20, 600, 440),
m_background_color()
{
    m_shader_pipeline.make();
}

bool DefaultRenderer::render(const RenderTarget& object) {

    m_shader_pipeline.use();
    glm::mat4 local_transform = object.get_local_transform();

    if (object.has_texture()) {
        m_shader_pipeline.set_uniform_bool((char*)"use_texture", true);
    }
    else {
        m_shader_pipeline.set_uniform_bool((char*)"use_texture", false);
    }
    glm::vec4 object_color = object.get_color();
    m_shader_pipeline.set_uniform_float4((char*)"base_color",
        object_color[0], object_color[1],
        object_color[2], object_color[3]);
    
    // The coordinate translations
    
    // Objects local position, orientation, and scale.
    m_shader_pipeline.set_uniform_matf4((char*)"local", glm::value_ptr(local_transform));
    
    // Objects world position, orientation, and scale.
    glm::mat4 model_transform = glm::translate(glm::mat4(1.0f), object.get_world_position());
    m_shader_pipeline.set_uniform_matf4((char*)"model", glm::value_ptr(model_transform));

    // Objects view position, orientation, and scale.
    glm::mat4 view_transform = glm::mat4(1.0f); // TODO: Enable movement of the viewpoint.
    m_shader_pipeline.set_uniform_matf4((char*)"view", glm::value_ptr(view_transform));

    // Using an ortographic projection Matrix (with 20.0 units visible always bounds)
    glm::mat4 projection_transform = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -100.0f, 100.0f);
    m_shader_pipeline.set_uniform_matf4((char*)"projection", glm::value_ptr(projection_transform));

    object.render();

    return true;
}

void DefaultRenderer::clear_scene() const {
    m_viewport.clear(m_background_color);
}

void DefaultRenderer::set_background_color(glm::vec4 color) {
    m_background_color = color;
}

bool DefaultRenderer::set_background_color_rgba(uint8_t red, uint8_t green, uint8_t blue, float alpha) {

        if (alpha > 1.0f || alpha < 0.0f) {
            return false;
        }

        m_background_color = glm::vec4(
            (float)red / 255.0f,
            (float)green / 255.0f,
            (float)blue / 255.0f,
            alpha
        );

        return true;

}

} // GFX
} // YAGE
