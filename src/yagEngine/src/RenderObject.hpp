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

#include "gl_class/Vao.hpp"
#include "gl_class/GLTexture.hpp"

#include "IRenderable.hpp"
#include "Image2D.hpp"

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
         * @brief Get the world position of the object
         * 
         * @return glm::vec3 The world position of the object
         */
        glm::vec3 get_world_position() const;

        /**
         * @brief Set the world position of the object
         * 
         * @param position 
         * @return true if position was set successfully
         */
        bool set_world_position(glm::vec3 position);

        /**
         * @brief Get the transform matrix of this object.
         *
         * @return 
         */
        glm::mat4 get_local_transform() const;

        /**
         * @brief Sets the transform matrix of this object to another transform matrix. 
         *
         * @param trans The glm mat4 object that will replace the transform matrix
         *
         * @return 
         */
        bool set_local_transform(glm::mat4 trans);

        /**
         * @brief Set the color of this object to a new color. The color is defined as a float4.
         *
         * @param color The glm::vec4 defining the color of this object.
         *
         * @return True if settings succeeded. 
         */
        bool set_color(glm::vec4 color);

        /**
         * @brief Get the color of this object.
         *
         * @return The glm vec4 object representing the color.
         */
        glm::vec4 get_color() const;

        /**
         * @brief Set the texture to a texture in the file.
         * 
         * @param image_file Image2D object that will represent the texture
         *
         * @return true if settings succeeded
         */
        bool set_texture(const YAGE::FS::ASSET::Image2D &image);


        /**
         * @brief Get the texture of this object
         * 
         * @return GL_CLASS::GLTexture 
         */
        GL_CLASS::GLTexture get_texture() const;

        /**
         * @brief Tells if the RenderObject has a valid texture set
         * 
         * @return true if the texture is set.
         */
        bool has_texture() const;

        /**
         * @brief Adds the transformation operation to the current transform. (A multiplication)
         *
         * @param trans The transform that orients and scales the object in local space.
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

        /**
         * @brief Use this in the child class constructor to initialize the m_vao object properly.
         *
         * @param vao
         */
        void initialize_vao(GL_CLASS::Vao vao);


    private:

        GL_CLASS::Vao m_vao;
        GL_CLASS::GLTexture m_texture;
        bool m_has_texture;
        
        glm::vec3 m_world_position;
        glm::mat4 m_local_transform;
        glm::vec4 m_base_color;
};

} // GFX
} // YAGE

#endif // RENDEROBJECT_HPP
