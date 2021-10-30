/**
 * @file GLBindings.hpp
 * @author poutipie
 * @brief Special internal header for making sure OpenGL funcions are initialized and tied to 
 *         context.
 * @version 0.1
 * @date 2021-10-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef GLBINDINGS_HPP
#define GLBINDINGS_HPP

#include "glad/glad.h"

namespace GL_CLASS {
namespace GL_BINDINGS {

    // Use this to check whether the opengl functions are already initialized
    static bool INITIALIZED = false;

    /**
     * @brief Initializes OpenGL functions and ties them to the context
     * 
     * @return true If initialize succeeded. False otherwise.
     */
    bool Initialize();

} // GL_BINDINGS
} // GL_CLASS

#endif // GLBINDINGS_HPP