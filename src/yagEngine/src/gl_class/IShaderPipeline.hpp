/**
 * @file IShaderPipeline.hpp
 * @brief The file for the interface class of ShaderPipelines
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */
#ifndef ISHADERPIPELINE_HPP
#define ISHADERPIPELINE_HPP

#include "ShaderPipelineTypes.hpp"

namespace GL_CLASS {

    
    /**
     * @brief The main interface class for shader pipelines.
     */
    class IShaderPipeline {

        public:
            
            /**
             * @brief Compile and link the shader program.
             *
             * @return 
             */
            virtual bool make() = 0;
            
            /**
             * @brief Take the shader program into use.
             *
             * @return 
             */
            virtual bool use() const = 0;

            /**
             * @brief Sets a Uniform boolean for the shaders
             *
             * @param name Name of the uniform
             * @param value Value of the uniform
             *
             * @return True if succeeded. 
             */
            virtual bool set_uniform_bool(char* name, bool value) const = 0;

            /**
             * @brief Sets a Uniform integer for the shaders
             *
             * @param name The name of the uniform
             * @param value The value of the uniform
             *
             * @return True if succeeded. 
             */
            virtual bool set_uniform_int(char* name, int value) const = 0;

            /**
             * @brief Sets a uniform float for the shaders
             *
             * @param name The name of the uniform
             * @param value The value of the uniform
             *
             * @return True if succeeded
             */
            virtual bool set_uniform_float(char* name, float value) const = 0;

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
            virtual bool set_uniform_float4(char* name, float x, float y, float z, float i) = 0;

            /**
             * @brief Sets a uniform 4x4 matrix value for the shaders
             *
             * @param name The name of the uniform
             * @param values The all float values of the 4x4 matrix as array
             *
             * @return True if succeeded.
             */
            virtual bool set_uniform_matf4(char* name, const float* values) = 0;

    };
}


#endif // ISHADERPIPELINE_HPP

