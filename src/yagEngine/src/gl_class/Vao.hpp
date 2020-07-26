/**
 * @file Vao.hpp
 * @brief File for the Vertex Array Object Class.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */

#ifndef VAO_HPP
#define VAO_HPP

#include "IVao.hpp"

namespace GL_CLASS {

    typedef unsigned int VAO_T;
    typedef unsigned int VBO_T;
    typedef unsigned int EBO_T;

    enum class DRAW_HINT {
        STATIC,
        DYNAMIC,
        STREAM_DRAW
    };
   
    struct VaoAttributeSpec {
        
        /* The Vertex array data */
        float* vertices;
        unsigned int vertices_len;
        
        /* The Element array data */
        unsigned int* indices;
        unsigned int indices_len;

        /* Draw hint for opengl*/
        DRAW_HINT  draw_hint; 

    };


    /**
     * @brief Vartex Array Object class. This is needed by all the Renderable objects and it
     * generally holds the base vertice information within its memory.
     */
    class Vao : public IVao {

        public:

            /**
             * @brief Constructor of the Vae class
             *
             * @param spec The container for all the vertices, indixes data as well as other open_gl
             * options.
             */
            Vao(VaoAttributeSpec spec );

            /**
             * @brief Generates the corresponding Vertex Array Object in OpenGL together with the
             * needed VAO attribute configuration and the needed Element Array Buffer data.
             * Vertex Array Pointers data of the VAO will by default be laid out like:
             * |x, y, x| x, y, z | ..
             *
             * @return True if succeeded.
             */
            bool make();


            /**
             * @brief Binds this VAO to be in use in the GL engine
             *
             * @return True if succeeded.
             */
            bool bind() const;

            
            /**
             * @brief Draws this Vertex Array Object using TRIANGLES and based on the "indices"
             * defined on the VaoAttributeSpec
             *
             * @return True if succeeded.
             */
            bool draw() const;

            
            /**
             * @brief Unbinds this VAO from the GL engine by doing glBindVertexArray() 
             *
             * @return True if succeeded. 
             */
            bool unbind() const;
            

        private:

            unsigned int draw_hint_to_gl(DRAW_HINT hint);

            VaoAttributeSpec m_spec;
            VAO_T m_id;
            VBO_T m_vbo_id;
            EBO_T m_ebo_id;
    };

}

#endif //VAO_HPP

