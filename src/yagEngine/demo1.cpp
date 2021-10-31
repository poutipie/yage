/**
 * @file demo1.cpp
 * @brief The source file of the demo1.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */
#include "demo1.hpp"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <glm/gtc/matrix_transform.hpp>

#include "SimpleRenderer.hpp"
#include "Rectangle.hpp"
#include "AssetBundle.hpp"


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

    YAGE::GFX::SimpleRenderer renderer;
    renderer.set_background_color(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));
    YAGE::GFX::Rectangle test_rect(-5.0f, 5.0f, 2.0f, 2.0f);
    YAGE::GFX::Rectangle test_rect2(5.0f, -5.0f, 2.0f, 2.0f);
    YAGE::GFX::Rectangle guide_horizontal(0.0f, 0.0f, 200.0f, 0.1f);
    YAGE::GFX::Rectangle guide_vertical(0.0f, 0.0f, 0.1f, 200.0f);
   
    /* Load and create a texture */
    YAGE::FS::ASSET::AssetBundle assets;
    const YAGE::FS::ASSET::Image2D& image = assets.load_image("container.jpg");
    test_rect.set_texture(image);

    while(!glfwWindowShouldClose(window)) {

	    processInput(window);

        float time_value = glfwGetTime();
        float cycle_mult = sin(time_value);
        float color = ((-cycle_mult / 2.0f) + 0.5f);

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::scale(trans, glm::vec3(cycle_mult, cycle_mult, cycle_mult));
        trans = glm::rotate(trans, glm::radians(180.0f * color), glm::vec3(0.0, 0.0, 1.0));

        test_rect.set_world_position(glm::vec3(cycle_mult * 5.0f, 5.0f, 0.0f));

        // Draw the rectangle
        renderer.clear_scene();
        test_rect.set_local_transform(trans);
        test_rect2.set_color(glm::vec4(0.5f, 0.5f, color, 0.5f));

        renderer.render(test_rect);
        renderer.render(test_rect2);
        renderer.render(guide_vertical);
        renderer.render(guide_horizontal);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return (EXIT_SUCCESS);
}
