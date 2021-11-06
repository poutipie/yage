/**
 * @file GLShaderPipeline.hpp
 * @brief The file for the GLShaderPipeline class.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */

#ifndef GLSHADERPIPELINE_HPP
#define GLSHADERPIPELINE_HPP

#include "IShaderPipeline.hpp"

namespace GL_CLASS {


    /**
     * @brief GLShaderPipeline class that is the base ShaderPipeline to use unless special
     * needs need to be accounted for. Uses only a vertex shader and a fragment shader for
     * operation.
     */
    class GLShaderPipeline : public IShaderPipeline {

        public:

            /**
             * @brief The GLShaderPipeline Constructor.
             *
             * @param spec The PipelineCompilerSpec given for the ShaderPipeline. Should hold the in
             * memory resources for the shaders used.
             */
            GLShaderPipeline(const PipelineCompilerSpec & spec);
            
            /**
             * @brief Make the shader pipeline entirely and link it to a shader program.
             *
             * @return True if all needed shaders compiled and linked succesfully. False otherwise. 
             */
            bool make();

            /**
             * @brief Starts using this shader pipeline. (Wrapper for glUseProgram) 
             *
             * @return True if succeeded. False otherwise.
             */
            bool use() const;

            /**
             * @brief Sets a Uniform boolean for the shaders
             *
             * @param name Name of the uniform
             * @param value Value of the uniform
             *
             * @return True if succeeded. 
             */
            bool set_uniform_bool(char* name, bool value) const;

            /**
             * @brief Sets a Uniform integer for the shaders
             *
             * @param name The name of the uniform
             * @param value The value of the uniform
             *
             * @return True if succeeded. 
             */
            bool set_uniform_int(char* name, int value) const;

            /**
             * @brief Sets a uniform float for the shaders
             *
             * @param name The name of the uniform
             * @param value The value of the uniform
             *
             * @return True if succeeded
             */
            bool set_uniform_float(char* name, float value) const;

            /**
             * @brief Sets a uniform float4 for the shaders
             *
             * @param name The name of the uniform
             * @param x The first value of the float4
             * @param y The second value of the float4
             * @param z The third value of the float4
             * @param i The fourth value of the float4
             *
             * @return True if succeeded.
             */
            bool set_uniform_float4(char* name, float x, float y, float z, float i);

            /**
             * @brief Sets a uniform 4x4 matrix value for the shaders
             *
             * @param name The name of the uniform
             * @param values The all float values of the 4x4 matrix as array
             *
             * @return True if succeeded.
             */
            bool set_uniform_matf4(char* name, const float* values);

        private:

            PipelineCompilerSpec m_pipeline_compiler_spec;
            SHADER_PROGRAM_T m_shader_program;
    };

}


#endif // GLSHADERPIPELINE_HPP
