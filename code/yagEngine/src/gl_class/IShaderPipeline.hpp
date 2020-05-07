#ifndef ISHADERPIPELINE_HPP
#define ISHADERPIPELINE_HPP

#include "ShaderPipelineTypes.hpp"

namespace GL_CLASS {

    class IShaderPipeline {

        public:
            
            /* Compile and link the shader program
             */ 
            virtual bool make() = 0;

            /*
            * Take the shader program into use
            */
            virtual bool use() const = 0;

            /* Sets a boolean uniform to be used by the shaders in the pipeline
             */
            virtual bool set_uniform_bool(char* name, bool value) const = 0;

            /* Sets an integer uniform to be used by the shaders in the pipeline
             */
            virtual bool set_uniform_int(char* name, int value) const = 0;

            /* Sets a float uniform to be used by the shaders in the pipeline
             */
            virtual bool set_uniform_float(char* name, float value) const = 0;

            /* Sets a vector 4 uniform to be used by the shaders in the pipeline
             */
            virtual bool set_uniform_float4(char* name, float x, float y, float z, float i) = 0;

            /* Sets a matric 4 float uniform to be used by the shaders in the pipeline
             */
            virtual bool set_uniform_matf4(char* name, const float* values) = 0;

    };
}


#endif // ISHADERPIPELINE_HPP

