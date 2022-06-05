/**
 * @file GLViewport.hpp
 * @author poutipie
 * @brief Class for handling OpenGL Viewport related functions
 * @version 0.1
 * @date 2021-10-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef GLVIEWPORT_HPP
#define GLVIEWPORT_HPP

#include <glm/glm.hpp>

namespace GL_CLASS {

    class GLViewport {

        public:

            /**
             * @brief Construct a new GLViewport object
             * 
             * @param x The x position of the viewport on the window
             * @param y The y position of the viewport on the window
             * @param width 
             * @param height 
             */
            GLViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
            ~GLViewport() = default;

            bool set() const;
            bool reset(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
            bool resize(unsigned int width, unsigned int height);
            bool reposition(unsigned int x, unsigned int y);

            void clear(glm::vec4 clear_color) const;

        private:
            unsigned int m_x;
            unsigned int m_y;
            unsigned int m_width;
            unsigned int m_height;

    };

} //  GLViewport

#endif // GLVIEWPORT_HPP