// GLTexture.cpp
#include "GLTexture.hpp"
#include "glad/glad.h"

namespace GL_CLASS {

    GLTexture::GLTexture(GLTextureAttributeSpec spec)
        : m_spec(spec), m_id(0) {
    }

    bool GLTexture::make() {

        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);

        /* Set the texture wrapping parameters */
        unsigned int texture_wrapping = texture_wrap_to_gl(m_spec.texture_wrapping);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texture_wrapping);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texture_wrapping);

        /* Set the texture filtering parameters */
        unsigned int texture_filtering = texture_filter_to_gl(m_spec.texture_filtering);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texture_filtering);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texture_filtering);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_spec.width, m_spec.height, 0, GL_RGB, 
            GL_UNSIGNED_BYTE, m_spec.data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);

        return true;
    }
    
    bool GLTexture::bind() const {
        glBindTexture(GL_TEXTURE_2D, m_id);
        return true;
    }

    bool GLTexture::unbind() const {
        glBindTexture(GL_TEXTURE_2D,0);
        return true;
    }

    unsigned int GLTexture::texture_wrap_to_gl( GLTEXTURE_WRAP wrap_t) const {

        switch(wrap_t) {
            
            case GLTEXTURE_WRAP::REPEAT:
                return GL_REPEAT;
            case GLTEXTURE_WRAP::MIRRORED_REPEAT:
                return GL_MIRRORED_REPEAT;
            case GLTEXTURE_WRAP::CLAMP_TO_EDGE:
                return GL_CLAMP_TO_EDGE;
            case GLTEXTURE_WRAP::CLAMP_TO_BORDER:
                return GL_CLAMP_TO_BORDER;

            default:
                return GL_REPEAT;
        }
    }

    unsigned int GLTexture::texture_filter_to_gl( GLTEXTURE_FILTERING filter_t) const {

        switch(filter_t) {

            case GLTEXTURE_FILTERING::LINEAR:
                return GL_LINEAR;
            case GLTEXTURE_FILTERING::NEAREST:
                return GL_NEAREST;
            default:
                return GL_LINEAR;
        }

    }
}