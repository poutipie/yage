#include "demo1.hpp"

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "SimpleShaderPipeline.hpp"
#include "Vao.hpp"

float vertices[] = {
    -0.25f,  0.75f, 0.0f, // top right
    -0.25f,  0.25f, 0.0f, // bottom right
    -0.75f,  0.25f, 0.0f, // bottom left
    -0.75f,  0.75f, 0.0f  // top left
};

float vertices2[] = {
     0.75f,  -0.25f, 0.0f, // top right
     0.75f, -0.75f, 0.0f, // bottom right
     0.25f, -0.75f, 0.0f, // bottom left
     0.25f,  -0.25f, 0.0f  // top left
};


unsigned int indices[] = {
    0, 1, 3,  // first triangle
    1, 2, 3   // second triangle
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

extern "C" const char vert[];
extern "C" const size_t vert_len;

extern "C" const char frag[];
extern "C" const size_t frag_len;

typedef unsigned int VAO_T;
typedef unsigned int VBO_T;
typedef unsigned int EBO_T;


int demo1::demo1_exec(void) {


    // Create the shaderpipeline
    GL_CLASS::PipelineCompilerSpec spec;
    const char* vert_res = vert;
    const char* frag_res = frag;
    spec.vertex_res = vert_res;
    spec.fragment_res = frag_res;
    GL_CLASS::SimpleShaderPipeline shader_pipeline(spec);

    // Create the Vao for first square
    GL_CLASS::VaoAttributeSpec sqr_spec{ 
        vertices, sizeof(vertices),
        indices, sizeof(indices), 
        GL_CLASS::DRAW_HINT::STATIC,
    };
    GL_CLASS::Vao sqr_vao(sqr_spec);

    // Create the VAO for second square
    GL_CLASS::VaoAttributeSpec sqr2_spec {
        vertices2, sizeof(vertices2),
        indices, sizeof(indices),
        GL_CLASS::DRAW_HINT::STATIC,
    };
    GL_CLASS::Vao sqr2_vao(sqr2_spec);

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return (EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        return (EXIT_FAILURE);
    }    

    if (!shader_pipeline.make())
    {
        printf("Failed to make shader program");
        return(EXIT_FAILURE);
    }

    if (!sqr_vao.make())
    {
        printf("Failed to make VAOi for first square");
    }

    if (!sqr2_vao.make())
    {
        printf("Failed to make VAO for second square");
    }

    /* Lets make a fun transform matrix that we can use in the demo
     */
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians(80.0f), glm::vec3(0.0, 0.0, 1.0));
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    
    while(!glfwWindowShouldClose(window)) {

	processInput(window);

        shader_pipeline.use();

        float time_value = glfwGetTime();
        float green_value = (sin(time_value) / 2.0f) + 0.5f;
        shader_pipeline.set_uniform_float4((char*)"our_color", 0.5f, green_value, 0.5f, 0.5f);
        shader_pipeline.set_uniform_matf4((char*)"transform", glm::value_ptr(trans));

        // Render Background
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
  
    	sqr_vao.draw();
        sqr2_vao.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return (EXIT_SUCCESS);
}

