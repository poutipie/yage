/**
 * @file GLScene.hpp
 * @author poutipie
 * @brief Class for handling Common OpenGL scene related function
 * @version 0.1
 * @date 2021-10-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef GLSCENE_HPP
#define GLSCENE_HPP

#include <glm/glm.hpp>

namespace GL_CLASS {

    class GLScene {

        public:

            GLScene() = delete;
            ~GLScene() = delete;

            static void clear(glm::vec4 clear_color);

    };

} //  GLScene

#endif // GLSCENE_HPP