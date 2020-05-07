
#include "Vao.hpp"

#include "glad/glad.h"

namespace GL_CLASS {

    Vao::Vao(VaoAttributeSpec spec)
    : m_spec(spec), m_id(0) {
    }

    bool Vao::make() {

        /* Generate the VAO in opengl */
        glGenVertexArrays(1, &m_id);

        /*
         * Create vertex buffer data.
         * Vertex array buffer
         */
        glGenBuffers(1, &m_vbo_id);

        /* Create Element Array buffer data */
        glGenBuffers(1, &m_ebo_id);

        /* Configure VAO attibutes */
        glBindVertexArray(m_id);

        glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
        unsigned int hint = draw_hint_to_gl(m_spec.draw_hint);
        glBufferData(GL_ARRAY_BUFFER, m_spec.vertices_len, m_spec.vertices, hint);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_spec.indices_len, m_spec.indices, hint);

        /* Set up vertex attribute pointers. Data will be laid out like
        * |x, y, z|x, y, z|
        */
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        /* You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, 
        * but this rarely happens. Modifying other VAOs requires a call to glBindVertexArray 
        * anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        */
        glBindVertexArray(0); // Unbind VAO

        return true;
    }

    bool Vao::bind() {
        glBindVertexArray(m_id); 
        return true;
    }

    bool Vao::draw() {

        bool ret = true;

        /* Bind Vertex Array. Drawing code for the certex array starts. */
        ret &= bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        ret &= unbind(); /* Unbind Vertex Array.. */
        
        return ret;
    }

    bool Vao::unbind() {
        glBindVertexArray(0);
        return true;
    }

    unsigned int Vao::draw_hint_to_gl(DRAW_HINT hint) {
        switch(hint) {
            case DRAW_HINT::STREAM_DRAW:
                return GL_STREAM_DRAW;
            case DRAW_HINT::DYNAMIC:
                return GL_DYNAMIC_DRAW;
            default:
                return GL_STATIC_DRAW;
        }
    }

}

