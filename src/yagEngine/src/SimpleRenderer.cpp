
#include "SimpleRenderer.hpp"

#include <glm/gtc/type_ptr.hpp>

namespace YAGE {
namespace GFX {

extern "C" const char vert[];
extern "C" const size_t vert_len;

extern "C" const char frag[];
extern "C" const size_t frag_len;

SimpleRenderer::SimpleRenderer() 
: m_shader_pipeline(GL_CLASS::PipelineCompilerSpec(vert, frag)){
    m_shader_pipeline.make();
}

bool SimpleRenderer::render(const RenderObject& object) {

    m_shader_pipeline.use();
    glm::mat4 trans = object.get_transform();

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
    m_shader_pipeline.set_uniform_matf4((char*)"transform", glm::value_ptr(trans));
    object.render();

    return true;
}

} // GFX
} // YAGE
