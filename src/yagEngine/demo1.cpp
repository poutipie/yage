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
#include "AssetBundle.hpp"

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

    YAGE::GFX::SimpleRenderer renderer;
    renderer.set_background_color(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));
    YAGE::GFX::Rectangle test_rect(-0.75f, 0.75f, 0.5f, 0.5f);
    YAGE::GFX::Rectangle test_rect2(0.25f, -0.25f, 0.5f, 0.5f);
   
    /* Load and create a texture */
    unsigned int texture;

    YAGE::FS::AssetBundle assets;
    YAGE::FS::ASSET::Image2D image = assets.load_image("container.jpg");
    test_rect.set_texture(image);

    while(!glfwWindowShouldClose(window)) {

	    processInput(window);

        float time_value = glfwGetTime(); 
        float cycle_mult = sin(time_value);

        float green_value = (cycle_mult / 2.0f) + 0.5f;
        float green_value2 = ((-cycle_mult / 2.0f) + 0.5f);

        glm::mat4 trans = glm::mat4(1.0f);
 
        trans = glm::scale(trans, glm::vec3(cycle_mult, 1.0f, 1.0f));
        trans = glm::rotate(trans, glm::radians(180.0f * cycle_mult), glm::vec3(0.0, 0.0, 1.0));

        // Draw the rectangle'
        renderer.clear_scene();
        test_rect.set_color(glm::vec4(0.5f, 0.5f, green_value, 0.5f));
        test_rect.set_transform(trans);
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

