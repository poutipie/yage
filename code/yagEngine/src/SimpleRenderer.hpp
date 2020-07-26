#ifndef SIMPLERENDERER_HPP
#define SIMPLERENDERER_HPP

#include "RenderObject.hpp"
#include "gl_class/SimpleShaderPipeline.hpp"

namespace YAGE {
namespace GFX {

    class SimpleRenderer {

        public:

            SimpleRenderer();

            /* Renders the render object with this renderer */
            bool render(const RenderObject& object);

        private:

            GL_CLASS::SimpleShaderPipeline m_shader_pipeline;
    };
}
}

#endif // SIMPLERENDERER_HPP
