
#include <stdio.h>
#include <glm/gtc/type_ptr.hpp>

#include "RenderTarget.hpp"

namespace YAGE {
namespace GFX {

    RenderTarget::RenderTarget() : 
        m_vao({nullptr, 0, nullptr, 0, GL_CLASS::DRAW_HINT::STATIC}), 
        m_texture({0, 0, nullptr, GL_CLASS::GLTEXTURE_FORMAT::RGB, GL_CLASS::GLTEXTURE_WRAP::REPEAT, 
                    GL_CLASS::GLTEXTURE_FILTERING::LINEAR}),
        m_world_position(0.0f, 0.0f, 0.0f),
        m_local_transform(1.0f), 
        m_base_color(0.0f, 0.0f, 0.0f, 0.0f),
        m_has_texture(false) 
    {
        return;
    }

    RenderTarget::RenderTarget(glm::vec3 world_position, glm::vec3 scale) :
        m_vao({nullptr, 0, nullptr, 0, GL_CLASS::DRAW_HINT::STATIC}), 
        m_texture({0, 0, nullptr, GL_CLASS::GLTEXTURE_FORMAT::RGB, GL_CLASS::GLTEXTURE_WRAP::REPEAT, 
                    GL_CLASS::GLTEXTURE_FILTERING::LINEAR}),
        m_world_position(world_position),
        m_local_transform(1.0f),
        m_base_color(0.0f, 0.0f, 0.0f, 0.0f),
        m_has_texture(false) 
    {
        transform_by(glm::scale(m_local_transform, scale));
        return;
    }

    RenderTarget::RenderTarget(float x, float y, float scale_x, float scale_y) :
        m_vao({nullptr, 0, nullptr, 0, GL_CLASS::DRAW_HINT::STATIC}), 
        m_texture({0, 0, nullptr, GL_CLASS::GLTEXTURE_FORMAT::RGB, GL_CLASS::GLTEXTURE_WRAP::REPEAT, 
                    GL_CLASS::GLTEXTURE_FILTERING::LINEAR}),
        m_world_position(glm::vec3(x, y, 1.0f)),
        m_local_transform(1.0f),
        m_base_color(0.0f, 0.0f, 0.0f, 0.0f),
        m_has_texture(false) 
    {
        transform_by(glm::scale(m_local_transform, glm::vec3(scale_x, scale_y, 1.0f)));
    }

    bool RenderTarget::render() const{

        m_texture.bind();
        m_vao.draw();
        m_texture.unbind();

        return true;
    }

    glm::vec3 RenderTarget::get_world_position() const {
        return m_world_position;
    }

    bool RenderTarget:: set_world_position(glm::vec3 position) {
        m_world_position = position;
        return true;
    }

    glm::mat4 RenderTarget::get_local_transform() const {
        return m_local_transform;
    }

    bool RenderTarget::set_local_transform(glm::mat4 trans) {
        
        m_local_transform = trans;

        return true;
    }

    bool RenderTarget::set_mesh(const YAGE::FS::ASSET::Mesh2D &mesh) {

        GL_CLASS::VaoAttributeSpec spec{
            mesh.vertex_data(),
            mesh.vertex_data_len(),
            mesh.index_data(),
            mesh.index_data_len(),
            GL_CLASS::DRAW_HINT::STATIC
        };

        GL_CLASS::Vao vao(spec);
        initialize_vao(vao);
        return true;
    }

    bool RenderTarget::transform_by(glm::mat4 trans) {
        
        m_local_transform *= trans;
        
        return true;
    }

    bool RenderTarget::set_color(glm::vec4 color) {

        m_base_color = color;
        return true;
    }

    bool RenderTarget::set_color_rgba(uint8_t red, uint8_t green, uint8_t blue, float_t alpha) {
        if (alpha > 1.0f || alpha < 0.0f) {
            return false;
        }

        m_base_color = glm::vec4(
            (float)red / 255.0f,
            (float)green / 255.0f,
            (float)blue / 255.0f,
            alpha
        );

        return true;
    }

    bool RenderTarget::set_texture(const YAGE::FS::ASSET::Image2D &image) {

        m_texture = GL_CLASS::GLTexture(
            {
                (unsigned int) image.get_width(),
                (unsigned int) image.get_height(),
                image.raw_data(),
                GL_CLASS::GLTEXTURE_FORMAT::RGB,
                GL_CLASS::GLTEXTURE_WRAP::REPEAT, 
                GL_CLASS::GLTEXTURE_FILTERING::LINEAR
            }
        );

        m_has_texture = true;
        return m_texture.make();
    }

    GL_CLASS::GLTexture RenderTarget::get_texture() const {
        return m_texture;
    }

    bool RenderTarget::has_texture() const {
        return m_has_texture;
    }

    glm::vec4 RenderTarget::get_color() const {
        return m_base_color;
    }

    void RenderTarget::initialize_vao(GL_CLASS::Vao vao) {
        m_vao = vao;
        if (!m_vao.make()) {
            printf("RenderTarget :: Failed to make vao.\n");
        }
    }

} // GFX
} // YAGE

