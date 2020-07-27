/**
 * @file demo1.cpp
 * @brief The source file of the demo1.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */
#include "demo1.hpp"

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <glm/gtc/matrix_transform.hpp>

#include "SimpleRenderer.hpp"
#include "Rectangle.hpp"

// TODO: Remove stb_image here
#include <stb_image.h>

/**
 * @brief GLFW callback for when window has been resized.
 *
 * @param window The GLFW window pointer that has been resized
 * @param width new width
 * @param height new height
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}


/**
 * @brief The input processing callback for a GLFW window.
 *
 * @param window The GLFWWindow pointer for window with possible input
 */
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int demo1::demo1_exec(void) {

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
        printf("Failed to initialize GLAD\n");
        return (EXIT_FAILURE);
    }    

    YAGE::GFX::SimpleRenderer renderer;
    YAGE::GFX::Rectangle test_rect(-0.75f, 0.75f, 0.5f, 0.5f);
    YAGE::GFX::Rectangle test_rect2(0.25f, -0.25f, 0.5f, 0.5f);
   
    /* Load and create a texture */
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    /* Set the texture wrapping parameters */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    /* Set the texture filtering parameters */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    /* Load image, create texture and generate mipmaps */
    int width, height, nrChannels;
    
    const char* text_path = "assets/yage/textures/container.jpg";
    unsigned char* data = stbi_load(text_path, &width, &height, &nrChannels, 0);
    if(!data) {
        printf("FAILED TO LOAD TEXTURE %s", text_path);
        return (EXIT_FAILURE);
    }
    else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    while(!glfwWindowShouldClose(window)) {

	processInput(window);

        float time_value = glfwGetTime(); 
        float cycle_mult = sin(time_value);

        float green_value = (cycle_mult / 2.0f) + 0.5f;
        float green_value2 = ((-cycle_mult / 2.0f) + 0.5f);

        glm::mat4 trans = glm::mat4(1.0f);
 
        trans = glm::scale(trans, glm::vec3(cycle_mult, 1.0f, 1.0f));
        trans = glm::rotate(trans, glm::radians(180.0f * cycle_mult), glm::vec3(0.0, 0.0, 1.0));

        // Render Background
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    
        glBindTexture(GL_TEXTURE_2D, texture);

        // Draw the rectangle
        test_rect.set_color(glm::vec4(0.5f, 0.5f, green_value, 0.5f));
        //test_rect.set_transform(trans);
        renderer.render(test_rect);
        test_rect2.set_color(glm::vec4(0.5f, 0.5f, green_value2, 0.5f));
        renderer.render(test_rect2);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return (EXIT_SUCCESS);
}

