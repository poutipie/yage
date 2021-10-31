#include "Window.hpp"

#include <GLFW/glfw3.h>

namespace YAGE {

Window::Window(unsigned int width, unsigned int height, const char* title) :
    m_width(width),
    m_height(height),
    m_title(title),
    m_window(nullptr),
    m_created(false)
{
    
}

Window::~Window() {

    if (m_created) {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
}

bool Window::create() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        m_created = false;
        return false;
    }
    glfwMakeContextCurrent(m_window);
    m_created = true;
    return true;
}

bool Window::is_created() {
    return m_created;
}

bool Window::waiting_to_close() {
    return glfwWindowShouldClose(m_window);
}

bool Window::update() {

    if (!m_created) {
        return false;
    }

    glfwSwapBuffers(m_window);
    glfwPollEvents();
    return true;
}

} // YAGE