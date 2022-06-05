#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include <glm/gtc/matrix_transform.hpp>

#include "DefaultRenderer.hpp"
#include "RenderTarget.hpp"
#include "AssetStore.hpp"
#include "Window.hpp"

int main(void) {


    YAGE::Window window(640, 480, "Asteroids Demo");
    if(!window.create()) {
        printf("Unable to create window\n");
        return (EXIT_FAILURE);
    }

    YAGE::GFX::DefaultRenderer renderer;
    renderer.set_background_color_rgba(0, 0, 0);

    YAGE::GFX::RenderTarget test_object;
    YAGE::GFX::RenderTarget test_rect(0.0f, 0.0f, 2.0f, 1.0f);
    YAGE::GFX::RenderTarget guide_horizontal(0.0f, 0.0f, 200.0f, 0.1f);
    YAGE::GFX::RenderTarget guide_vertical(0.0f, 0.0f, 0.1f, 200.0f);
    guide_horizontal.set_color(glm::vec4(1.0f, 0.0f, 0.0f, 0.5f));
    guide_vertical.set_color(glm::vec4(1.0f, 0.0f, 0.0f, 0.5f));
    test_rect.set_color_rgba(255, 255, 255);
    test_object.set_color_rgba(255, 0, 255);

    /* Load assets*/
    YAGE::FS::ASSET::AssetStore assets;

    const YAGE::FS::ASSET::Mesh2D &square_mesh = assets.load_mesh("square.mesh");
    test_object.set_mesh(square_mesh);
    test_rect.set_mesh(square_mesh);
    guide_horizontal.set_mesh(square_mesh);
    guide_vertical.set_mesh(square_mesh);

    auto start = std::chrono::high_resolution_clock::now();
    while(!window.waiting_to_close()) {

        auto now = std::chrono::high_resolution_clock::now();
        float time_value = std::chrono::duration<float>(now - start).count();

        test_rect.set_world_position(glm::vec3(sin(time_value) * 5.0f, 5.0f, 0.0f));

        renderer.clear_scene();
        renderer.render(test_rect);
        renderer.render(guide_vertical);
        renderer.render(guide_horizontal);
        renderer.render(test_object);

        window.update();
    }
    return (EXIT_SUCCESS);
}
