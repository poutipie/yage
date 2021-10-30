#include "GLBindings.hpp"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
 
namespace GL_CLASS {
namespace GL_BINDINGS {

    bool Initialize() {

        if (!INITIALIZED) {

            // glad: load all OpenGL function pointers
            // ---------------------------------------
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                printf("Failed to initialize GLAD\n");
                return false;
            }  
        }

        INITIALIZED = true;
        return true;

    }

} // GL_BINDINGS
} // GL_CLASS