
#include <stdio.h>

#include "RenderObject.hpp"

#include <glm/gtc/type_ptr.hpp>

namespace YAGE {
namespace GFX {

    RenderObject::RenderObject() 
        : m_vao({nullptr, 0, nullptr, 0, GL_CLASS::DRAW_HINT::STATIC}), m_transform(1.0f), 
        m_base_color(0.0f, 0.0f, 0.0f, 0.0f) {
        return;
    }

    bool RenderObject::render() const{

        m_vao.draw();

        return true;
    }

    glm::mat4 RenderObject::get_transform() const {
        return m_transform;
    }

    bool RenderObject::set_transform(glm::mat4 trans) {
        
        m_transform = trans;

        return true;
    }

    bool RenderObject::transform_by(glm::mat4 trans) {
        
        m_transform *= trans;
        
        return true;
    }

    bool RenderObject::set_color(glm::vec4 color) {
        m_base_color = color;

        return true;
    }

    glm::vec4 RenderObject::get_color() const {
        return m_base_color;
    }

    void RenderObject::initialize_vao(GL_CLASS::Vao vao) {
        m_vao = vao;
        if (!m_vao.make()) {
            printf("RenderObject :: Failed to make vao.\n");
        }
    }

} // GFX
} // YAGE

