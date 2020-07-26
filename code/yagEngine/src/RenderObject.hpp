#ifndef RENDEROBJECT_HPP
#define RENDEROBJECT_HPP

#include <glm/glm.hpp>
#include "IRenderable.hpp"

#include "gl_class/Vao.hpp"

namespace YAGE {
namespace GFX {

class RenderObject : public IRenderable {

    public:
 
        bool render() const;

        glm::mat4 get_transform() const;

        bool set_transform(glm::mat4 trans);

        bool set_color(glm::vec4 color);

        glm::vec4 get_color() const;

        bool transform_by(glm::mat4 trans);

    protected:

        RenderObject();

        /* Use this in the child class constructor to initialize the m_vao */
        void initialize_vao(GL_CLASS::Vao vao);


    private:

        GL_CLASS::Vao m_vao;
        glm::mat4 m_transform;
        glm::vec4 m_base_color;
};

} // GFX
} // YAGE

#endif // RENDEROBJECT_HPP
