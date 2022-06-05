/**
 * @file DefaultRenderer.hpp
 * @brief File containing the DefaultRenderer object.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */

#ifndef DEFAULTRENDERER_HPP
#define DEFAULTRENDERER_HPP

#include "RenderTarget.hpp"
#include "Window.hpp"
#include "gl_class/GLShaderPipeline.hpp"
#include "gl_class/GLViewport.hpp"

namespace YAGE {
namespace GFX {

/**
 * @brief The DefaultRenderer object. This is a renderer that uses the GLShaderPipeline to render
 * RenderTargets.
 */
class DefaultRenderer {

    public:

        DefaultRenderer();

        /**
         * @brief Renders the render object with this renderer.
         * Uses the GLShaderPipeline with default vertex and fragment shader.
         * Takes advantage of 'base_color' and 'transform' uniforms to allow setting a color and a
         * transform for the RenderTarget. Hence assumes that similarly named variables are used by
         * the shader.
         *
         * @param object The RenderTarget to be rendered.
         *
         * @return 
         */
        bool render(const RenderTarget& object);

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
        bool set_background_color_rgba(uint8_t red, uint8_t green, uint8_t blue, float alpha = 1.0f);

    private:

        GL_CLASS::GLShaderPipeline m_shader_pipeline;
        GL_CLASS::GLViewport m_viewport;
        glm::vec4 m_background_color;
};

} // GFX
} // YAGE

#endif // DEFAULTRENDERER_HPP

