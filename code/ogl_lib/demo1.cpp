#include "demo1.hpp"

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "shaderpipeline/SimpleShaderPipeline.hpp"

float vertices[] = {
     0.5f,  0.5f, 0.0f, // top right
     0.5f, -0.5f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f,  0.5f, 0.0f  // top left
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


typedef unsigned int VBO_T;
typedef unsigned int VAO_T;
typedef unsigned int EBO_T;


int demo1::demo1_exec(void) {

    GL_CLASS::PipelineCompilerSpec spec;
    const char* vert_res = vert;
    const char* frag_res = frag;
    spec.vertex_res = vert_res;
    spec.fragment_res = frag_res;
    GL_CLASS::SimpleShaderPipeline shader_pipeline(spec);
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

    /* Initialize a Vertex array object and bind the triangle data into it.
     */
    VAO_T VAO;
    glGenVertexArrays(1, &VAO);
    
    /*
     * Create vertex buffer data.
     * Vertex array buffer will be static so it will not change during updates
     */
    VBO_T triangle_VBO;
    glGenBuffers(1, &triangle_VBO);

    /*
     * Create Element buffer data
     */
    EBO_T triangle_EBO;
    glGenBuffers(1, &triangle_EBO);

    /* bind the Vertex Array Object first, then bind and set vertex buffer(s), 
     * and then configure vertex attributes(s).
     */
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, triangle_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    /* Set up vertex attribute pointers. Data will be laid out like
     * |x, y, z|x, y, z|
     */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); // Enable vertex array for loaction (0)

    /* You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, 
     * but this rarely happens. Modifying other
     * VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs 
     * (nor VBOs) when it's not directly necessary.
     */
    glBindVertexArray(0); 

    while(!glfwWindowShouldClose(window)) {

	processInput(window);

        shader_pipeline.use();
   
        // Render Background
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
  
        /* Bind vertex array. Rendering code for the VAO starts
     	*/
    	glBindVertexArray(VAO);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        /* Unbind vertex array. Rendering code for the VAO ends
         */
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return (EXIT_SUCCESS);
}


