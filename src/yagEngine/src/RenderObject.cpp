
#include <stdio.h>
#include <glm/gtc/type_ptr.hpp>

#include "RenderObject.hpp"

namespace YAGE {
namespace GFX {

    RenderObject::RenderObject() 
        : m_vao(
            {nullptr, 0, nullptr, 0, GL_CLASS::DRAW_HINT::STATIC}
        ), 
        m_texture(
            {0, 0, nullptr, GL_CLASS::GLTEXTURE_WRAP::REPEAT, GL_CLASS::GLTEXTURE_FILTERING::LINEAR}
        ), 
        m_local_transform(1.0f), 
        m_base_color(0.0f, 0.0f, 0.0f, 0.0f),
        m_has_texture(false) 
    {
        return;
    }

    bool RenderObject::render() const{

        m_texture.bind();
        m_vao.draw();
        m_texture.unbind();

        return true;
    }

    glm::vec3 RenderObject::get_world_position() const {
        return m_world_position;
    }

    bool RenderObject:: set_world_position(glm::vec3 position) {
        m_world_position = position;
        return true;
    }

    glm::mat4 RenderObject::get_local_transform() const {
        return m_local_transform;
    }

    bool RenderObject::set_local_transform(glm::mat4 trans) {
        
        m_local_transform = trans;

        return true;
    }

    bool RenderObject::transform_by(glm::mat4 trans) {
        
        m_local_transform *= trans;
        
        return true;
    }

    bool RenderObject::set_color(glm::vec4 color) {
        m_base_color = color;

        return true;
    }

    bool RenderObject::set_texture(const YAGE::FS::ASSET::Image2D &image) {

        m_texture = GL_CLASS::GLTexture(
            {
                (unsigned int) image.get_width(),
                (unsigned int) image.get_height(),
                image.raw_data(),
                GL_CLASS::GLTEXTURE_WRAP::REPEAT, 
                GL_CLASS::GLTEXTURE_FILTERING::LINEAR
            }
        );

        m_has_texture = true;
        return m_texture.make();
    }

    GL_CLASS::GLTexture RenderObject::get_texture() const {
        return m_texture;
    }

    bool RenderObject::has_texture() const {
        return m_has_texture;
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

