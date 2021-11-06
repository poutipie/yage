/**
 * @file demo1.cpp
 * @brief The source file of the demo1.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */
#include "demo1.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include <glm/gtc/matrix_transform.hpp>

#include "SimpleRenderer.hpp"
#include "Rectangle.hpp"
#include "AssetStore.hpp"
#include "Window.hpp"

int demo1::demo1_exec(void) {


    YAGE::Window window(640, 480, "Simple Test Demo");
    if(!window.create()) {
        printf("Unable to create window\n");
        return (EXIT_FAILURE);
    }

    YAGE::GFX::SimpleRenderer renderer;
    renderer.set_background_color(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));
    YAGE::GFX::Rectangle test_rect(-5.0f, 5.0f, 2.0f, 2.0f);
    YAGE::GFX::Rectangle test_rect2(5.0f, -5.0f, 2.0f, 2.0f);
    YAGE::GFX::Rectangle guide_horizontal(0.0f, 0.0f, 200.0f, 0.1f);
    YAGE::GFX::Rectangle guide_vertical(0.0f, 0.0f, 0.1f, 200.0f);
    guide_horizontal.set_color(glm::vec4(1.0f, 0.0f, 0.0f, 0.5f));
    guide_vertical.set_color(glm::vec4(1.0f, 0.0f, 0.0f, 0.5f));

    /* Load and create a texture */
    YAGE::FS::ASSET::AssetStore assets;
    const YAGE::FS::ASSET::Image2D& image = assets.load_image("container.jpg");
    test_rect.set_texture(image);

    /* Load and create a font */
    const YAGE::FS::ASSET::Font& font = assets.load_font("SourceCodePro-Regular.otf");
    const YAGE::FS::ASSET::Glyph& glyph = font.get_glyph('a');
    printf("Glyph a size: (%d,%d)\n", glyph.size[0], glyph.size[1]);

    auto start = std::chrono::high_resolution_clock::now();
    while(!window.waiting_to_close()) {

        auto now = std::chrono::high_resolution_clock::now();
        auto dur = now - start;
        float time_value = std::chrono::duration<float>(dur).count();
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

        window.update();
    }
    return (EXIT_SUCCESS);
}
