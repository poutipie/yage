#ifndef VAO_HPP
#define VAO_HPP

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

    class IVao {

        public:

            /* Make the Vao */
            virtual bool make() = 0;

            /* Bind the Vao */
            virtual bool bind() = 0;

            /* Draws Vao using the bound gl shaderpipeline */
            virtual bool draw();

            /* Unbind the Vao */
            virtual bool unbind() = 0;
    };


    class Vao {

        public:

            Vao(VaoAttributeSpec spec );

            bool make();

            bool bind();

            bool draw();

            bool unbind();
            

        private:

            unsigned int draw_hint_to_gl(DRAW_HINT hint);

            VaoAttributeSpec m_spec;
            VAO_T m_id;
            VBO_T m_vbo_id;
            EBO_T m_ebo_id;
    };

}

#endif //VAO_HPP

