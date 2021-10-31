#include "GLViewport.hpp"
#include "GLBindings.hpp"

#include <stdio.h>

namespace GL_CLASS {

    GLViewport::GLViewport(unsigned int x, unsigned int y, unsigned int width, 
        unsigned int height) : 
    m_x(x), m_y(y), m_width(width), m_height(height) 
    {

        if (!GL_BINDINGS::Initialize()) {
            printf("Warning: GLViewport initialized before opengl bindings were tied to context.\n");
        }

        glViewport(x, y, width, height);
        return;
    }

    bool GLViewport::set() const{
        glViewport(m_x, m_y, m_width, m_height);
        return true;
    }

    bool GLViewport::reset(unsigned int x, unsigned int y, unsigned int width, 
        unsigned int height) {
        
        m_x = x;
        m_y = y;
        m_width = width;
        m_height = height;
        set();
        return true;

    }

    bool GLViewport::resize(unsigned int width, unsigned int height) {

        m_width = width;
        m_height = height;
        set();
        return true;
    }

    bool GLViewport::reposition(unsigned int x, unsigned int y) {

        m_x = x;
        m_y = y;
        set();
        return true;
    }

    void GLViewport::clear(glm::vec4 clear_color) const {

        glDisable(GL_SCISSOR_TEST);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glScissor(m_x, m_y, m_width, m_height);
        glEnable(GL_SCISSOR_TEST);
        glClearColor(
            clear_color[0], clear_color[1],
            clear_color[2], clear_color[3]
        );
        glClear(GL_COLOR_BUFFER_BIT);
    }

}