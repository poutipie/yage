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

    class Vao : public IVao {

        public:

            Vao(VaoAttributeSpec spec );

            bool make();

            bool bind() const;

            bool draw() const;

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

