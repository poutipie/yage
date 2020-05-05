#include "demo1.hpp"

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderpipeline/SimpleShaderPipeline.hpp"

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

    /* Initialize a Vertex array object and bind the square 1 data into it.
     */
    VAO_T sqr1_VAO;
    glGenVertexArrays(1, &sqr1_VAO);
    
    /*
     * Create vertex buffer data.
     * Vertex array buffer will be static so it will not change during updates
     */
    VBO_T sqr1_VBO;
    glGenBuffers(1, &sqr1_VBO);

    /*
     * Create Element buffer data
     */
    EBO_T sqr_EBO;
    glGenBuffers(1, &sqr_EBO);

    /* bind the Vertex Array Object first, then bind and set vertex buffer(s), 
     * and then configure vertex attributes(s).
     */
    glBindVertexArray(sqr1_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, sqr1_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sqr_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    /* Set up vertex attribute pointers. Data will be laid out like
     * |x, y, z|x, y, z|
     */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); // Enable vertex array for location (0)

    /* You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, 
     * but this rarely happens. Modifying other
     * VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs 
     * (nor VBOs) when it's not directly necessary.
     */
    glBindVertexArray(0); 

    /* We will do another set of binding for the second square
     */

    /* Again, generate the VAO containing everything about the square 2
     */
    VAO_T sqr2_VAO;
    glGenVertexArrays(1, &sqr2_VAO);

    /* Make the VBO object
     */
    VBO_T sqr2_VBO;
    glGenBuffers(1, &sqr2_VBO);

    /* Bind sqr2 vertex array so we can work with that
     */
    glBindVertexArray(sqr2_VAO);

    /* Bind the sqr2 vertex data buffer (VBO) to VAO of sqr2
     */
    glBindBuffer(GL_ARRAY_BUFFER, sqr2_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

    /* Bind the same buffer as we had in sqr1 to EBO of sqr2
     */
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sqr_EBO);

    /* Setup the vertex attribute pointers for location 0
     */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    /* Unbind VAO
     */
    glBindVertexArray(0);


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
  
        /* Bind vertex array. Rendering code for the VAO starts
     	*/
    	glBindVertexArray(sqr1_VAO);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        /* Unbind vertex array. Rendering code for the VAO ends
         */
        glBindVertexArray(0);

        /* Bind sqr2 vertex array. Rendering code for the VAO starts
         */
        glBindVertexArray(sqr2_VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return (EXIT_SUCCESS);
}


