#ifndef SIMPLESHADERPIPELINE_HPP
#define SIMPLESHADERPIPELINE_HPP

#include "IShaderPipeline.hpp"

namespace GL_CLASS {

    class SimpleShaderPipeline : public IShaderPipeline {

        public:
            SimpleShaderPipeline(const PipelineCompilerSpec & spec);

            bool make();
            bool use() const;
            bool set_uniform_bool(char* name, bool value) const;
            bool set_uniform_int(char* namme, int value) const;
            bool set_uniform_float(char* name, float value) const; 
            bool set_uniform_float4(char* name, float x, float y, float z, float i);
            bool set_uniform_matf4(char* name, const float* values);

        private:

            PipelineCompilerSpec m_pipeline_compiler_spec;
            SHADER_PROGRAM_T m_shader_program;
    };

}


#endif // SIMPLESHADERPIPELINE_HPP
