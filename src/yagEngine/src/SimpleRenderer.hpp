/**
 * @file SimpleRenderer.hpp
 * @brief File containing the SimpleRenderer object.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */

#ifndef SIMPLERENDERER_HPP
#define SIMPLERENDERER_HPP

#include "RenderObject.hpp"
#include "gl_class/SimpleShaderPipeline.hpp"
#include "gl_class/GLViewport.hpp"

namespace YAGE {
namespace GFX {

/**
 * @brief The SimpleRenderer object. This is a renderer that uses the SimpleShaderPipeline to render
 * RenderObjects.
 */
class SimpleRenderer {

    public:

        SimpleRenderer();

        /**
         * @brief Renders the render object with this renderer.
         * Uses the SimpleShaderPipeline with default vertex and fragment shader.
         * Takes advantage of 'base_color' and 'transform' uniforms to allow setting a color and a
         * transform for the RenderObject. Hence assumes that similarly named variables are used by
         * the shader.
         *
         * @param object The renderobject to be rendered.
         *
         * @return 
         */
        bool render(const RenderObject& object);

        /**
         * @brief Clears the rendered scene
         * 
         */
        void clear_scene() const;

        /**
         * @brief Set the background color to the renderer
         * 
         * @param color The background color to set
         */
        void set_background_color(glm::vec4 color);

    private:

        GL_CLASS::SimpleShaderPipeline m_shader_pipeline;
        GL_CLASS::GLViewport m_viewport;
        glm::vec4 m_background_color;
};

} // GFX
} // YAGE

#endif // SIMPLERENDERER_HPP

