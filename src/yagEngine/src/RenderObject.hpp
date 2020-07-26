/**
 * @file RenderObject.hpp
 * @brief The file for the RenderObject class and related types.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */

#ifndef RENDEROBJECT_HPP
#define RENDEROBJECT_HPP

#include <glm/glm.hpp>
#include "IRenderable.hpp"

#include "gl_class/Vao.hpp"

namespace YAGE {
namespace GFX {

/**
* @brief RenderObject is the basic renderable object. This object will have vertices defined
* together with a color and a transform to render them into a scene.
*/
class RenderObject : public IRenderable {

    public:

        /**
         * @brief See IRenderable. Basically a wrapper call for the 'draw' method of the VAO object.
         *
         * @return True if succeeded.
         */
        bool render() const;

        /**
         * @brief Get the transform matrix of this object.
         *
         * @return 
         */
        glm::mat4 get_transform() const;

        /**
         * @brief Sets the transform matrix of this object to another transform matrix. 
         *
         * @param trans The glm mat4 object that will replace the transform matrix
         *
         * @return 
         */
        bool set_transform(glm::mat4 trans);


        /**
         * @brief Set the color of this object to a new color. The color is defined as a float4.
         *
         * @param color The glm::vec4 defining the color of this object.
         *
         * @return True if settings succeeded. 
         */
        bool set_color(glm::vec4 color);

        /**
         * @brief Get the color od this object.
         *
         * @return The glm vec4 object representing the color.
         */
        glm::vec4 get_color() const;

        /**
         * @brief Transforms the current transform by the transform. (A multiplication operation)
         *
         * @param trans The transform that will be used to transorfm the current transform.
         *
         * @return True if matrix multiplications succeeded and transform completed.
         */
        bool transform_by(glm::mat4 trans);

    protected:

        /**
         * @brief The constructor for this RenderObject. Protected since this object should never be
         * directly created.
         */
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