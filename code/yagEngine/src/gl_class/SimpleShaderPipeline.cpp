// SImpleShaderPipeline.cpp
#include "SimpleShaderPipeline.hpp"
#include "glad/glad.h"
#include "stdio.h"

namespace GL_CLASS {

    SimpleShaderPipeline::SimpleShaderPipeline(const PipelineCompilerSpec& spec) 
        : m_pipeline_compiler_spec(spec) 
    {
        return;
    }

    bool SimpleShaderPipeline::make() {
        /* Compile our vertex shader for the program and link it.
        * Vertex shader maps the vertax data coordinates into normalized
        * screen coordinates.
        */
        const GLchar * vertex_source = m_pipeline_compiler_spec.vertex_res;
        VERT_SHADER_T vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_source, NULL);
        glCompileShader(vertex_shader);

        /* Check for compile errors while compiling the vertex shader.
        */
        int status;
        char info_log[512];

        glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &status);
        if (!status) {
            glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
            printf("ERROR COMPILING VERTEX SHADER!\n");
            printf(info_log, 512);
            return false;
        }

        /* Compile our fragment shader for the program and compile it
        * Fragment shader tells the colors that a vertice should have.
        */
        const GLchar * fragment_source = m_pipeline_compiler_spec.fragment_res;
        FRAG_SHADER_T fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_source, NULL);
        glCompileShader(fragment_shader);

        /* Check for compile errors while compiling the fragment shader.
        */
        glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &status);
        if (!status) {
            glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
            printf("ERROR COMPILING FRAGMENT SHADER!\n");
            printf(info_log, 512);
            return false;
        }

        /* Create Shader program for the previously compiled shaders
        */
        m_shader_program = glCreateProgram();
        glAttachShader(m_shader_program, vertex_shader);
        glAttachShader(m_shader_program, fragment_shader);
        glLinkProgram(m_shader_program);
   
        glGetProgramiv(m_shader_program, GL_LINK_STATUS, &status);
        if (!status) {
            glGetProgramInfoLog(m_shader_program, 512, NULL, info_log);
            printf("ERROR LINKING SHADER PROGRAM!\n");
            printf(info_log, 512);
            return false;
        }

        /* Delete shaders. 
         * They are no longer needed as they have been linked to the program
        */
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

        return true;
    }

    bool SimpleShaderPipeline::use() const {
        /* Finally, set our shader program to use. After this the program
     	* has a fully functional opengl pipeline to draw graphics on.
     	*/

        glUseProgram(m_shader_program);

        return true;
    }

    bool SimpleShaderPipeline::set_uniform_bool(char * name, bool value) const {
        glUniform1i(glGetUniformLocation(m_shader_program, name), (int)value);
        return true;
    }

    bool SimpleShaderPipeline::set_uniform_int(char* name, int value) const {
        glUniform1i(glGetUniformLocation(m_shader_program, name), value);  
        return true;
    }

    bool SimpleShaderPipeline::set_uniform_float(char* name, float value) const {
        glUniform1f(glGetUniformLocation(m_shader_program, name), value);
        return true;
    }

    
    bool SimpleShaderPipeline::set_uniform_float4(char* name, float x, float y, float z, float i) {
        glUniform4f(glGetUniformLocation(m_shader_program, name), x, y, z, i);
        return true;
    }

    bool SimpleShaderPipeline::set_uniform_matf4(char* name, const float* values) {
        unsigned int transform_loc = glGetUniformLocation(m_shader_program, name);
        glUniformMatrix4fv(transform_loc, 1, GL_FALSE, values); 
        return true;
    };
}

