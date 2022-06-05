/**
 * @file ShaderPipelineTypes.hpp
 * @brief File for common types used by the ShaderPipeline classes.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */

#ifndef SHADERPIPELINETYPES_HPP
#define SHADERPIPELINETYPES_HPP

namespace GL_CLASS {


    /**
     * @brief Generic type for OpenGL Vertex Shader
     */
    typedef unsigned int VERT_SHADER_T;

    /**
     * @brief Generic type for OpenGL Fragment Shader
     */
    typedef unsigned int FRAG_SHADER_T;

    /**
     * @brief Generic type for OpenGL Shader Program
     */
    typedef unsigned int SHADER_PROGRAM_T;


    /**
     * @brief Container for the Shader Pipeline vertex and array resources
     * (shall be NULL terminated)
     */
    struct PipelineCompilerSpec {


        /**
         * @brief Default constructor for PipelineCompilerSpec
         *
         * @param vert The NULL-terminated vertex shader source data.
         * @param frag The NULL-terminated fragment shader source data.
         */
        PipelineCompilerSpec(const char* vert, const char* frag) 
            : vertex_res(vert), fragment_res(frag) {};

        /**
         * @brief NULL terminated vertex shader source code.
         */
        const char* vertex_res = nullptr;
        
        /**
         * @brief NULL terminated fragment shader source code.
         */
        const char* fragment_res = nullptr;
    };

}

#endif // SHADERPIPELINETYPES_HPP
