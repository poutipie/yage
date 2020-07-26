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

    typedef unsigned int VERT_SHADER_T;
    typedef unsigned int FRAG_SHADER_T;
    typedef unsigned int SHADER_PROGRAM_T;


    /**
     * @brief Container for the Shader Pipeline vertex and array resources
     * (shall be NULL terminated)
     */
    struct PipelineCompilerSpec {
        PipelineCompilerSpec(const char* vert, const char* frag) 
            : vertex_res(vert), fragment_res(frag) {};
        // NULL terminated vertex shader source code
        const char* vertex_res = nullptr;
        // NULL terminated fragment shader source code
        const char* fragment_res = nullptr;
    };

}

#endif // SHADERPIPELINETYPES_HPP
