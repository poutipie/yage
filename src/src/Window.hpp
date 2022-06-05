/**
 * @file Window.hpp
 * @author poutipie
 * @brief YAGE Window context abstraction
 * @version 0.1
 * @date 2021-10-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

class GLFWwindow;

namespace YAGE {

class Window {

    public:

        /**
         * @brief Construct a new Window object
         * 
         * @param width width of the window in pixels
         * @param height height of the window in pixels
         * @param title Title of the window
         */
        Window(unsigned int width, unsigned int height, const char* title);

        /**
         * @brief Destroy the Window object
         * 
         */
        ~Window();

        /**
         * @brief Create and spawn the actual window instance to Screen. 
         * 
         * @return true if creation succeeded
         * @return false If creation failed
         */
        bool create();

        /**
         * @brief Returns whether window has already been created
         * 
         * @return true if window is created
         * @return false if window ins not created
         */
        bool is_created();

        /**
         * @brief Return whether the window is waiting to be closed
         * 
         * @return true If is waiting
         */
        bool waiting_to_close();

        /**
         * @brief Update window frame. Swaps screen buffers and Processes possible input events
         * 
         * @return true If update succeeded.
         * @return false Otherwise
         */
        bool update();

    private:

        GLFWwindow* m_window;
        unsigned int m_width;
        unsigned int m_height;
        const char* m_title;

        bool m_created;

};

} // YAGE

#endif // WINDOW_HPP
