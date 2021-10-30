// GLScene.cpp
#include "GLScene.hpp"
#include "GLBindings.hpp"

#include <stdio.h>

namespace GL_CLASS {

    void GLScene::clear(glm::vec4 clear_color) {

        if (!GL_BINDINGS::Initialize()) {
            printf("Warning: GLScreen::clear used before opengl bindings were tied to context.\n");
        }

        glClearColor(
            clear_color[0], clear_color[1],
            clear_color[2], clear_color[3]
        );

        glClear(GL_COLOR_BUFFER_BIT);
    }

}