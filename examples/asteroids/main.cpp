#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include <glm/gtc/matrix_transform.hpp>

#include "SimpleRenderer.hpp"
#include "Rectangle.hpp"
#include "AssetStore.hpp"
#include "Window.hpp"

int main(void) {


    YAGE::Window window(640, 480, "Simple Test Demo");
    if(!window.create()) {
        printf("Unable to create window\n");
        return (EXIT_FAILURE);
    }

    YAGE::GFX::SimpleRenderer renderer;
    renderer.set_background_color_rgba(0, 0, 0);
    YAGE::GFX::Rectangle test_rect(-5.0f, 5.0f, 2.0f, 2.0f);
    YAGE::GFX::Rectangle guide_horizontal(0.0f, 0.0f, 200.0f, 0.1f);
    YAGE::GFX::Rectangle guide_vertical(0.0f, 0.0f, 0.1f, 200.0f);
    guide_horizontal.set_color(glm::vec4(1.0f, 0.0f, 0.0f, 0.5f));
    guide_vertical.set_color(glm::vec4(1.0f, 0.0f, 0.0f, 0.5f));
    test_rect.set_color_rgba(255, 255, 255);

    /* Load and create a texture */
    YAGE::FS::ASSET::AssetStore assets;


    auto start = std::chrono::high_resolution_clock::now();
    while(!window.waiting_to_close()) {

        auto now = std::chrono::high_resolution_clock::now();
        float time_value = std::chrono::duration<float>(now - start).count();

        test_rect.set_world_position(glm::vec3(sin(time_value) * 5.0f, 5.0f, 0.0f));

        renderer.clear_scene();
        renderer.render(test_rect);
        renderer.render(guide_vertical);
        renderer.render(guide_horizontal);

        window.update();
    }
    return (EXIT_SUCCESS);
}
