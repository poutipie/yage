/**
 * @file Texture.hpp
 * @author poutipie
 * @brief Class to hold Texture Data
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

 #ifndef GLTEXTURE_HPP
 #define GLTEXTURE_HPP

namespace GL_CLASS {

    typedef unsigned int GL_TEXTURE_TYPE;

    enum class GLTEXTURE_FORMAT {
        RGB,
        RED
    };

    enum class GLTEXTURE_WRAP {
        REPEAT,          // The default behavior for textures. Repeats the texture image.
        MIRRORED_REPEAT, // Same as GL_REPEAT but mirrors the image with each repeat.
        CLAMP_TO_EDGE,   // Clamps the coordinates between 0 and 1. The result is that higher coordinates become clamped to the edge, resulting in a stretched edge pattern.
        CLAMP_TO_BORDER  // Coordinates outside the range are now given a user-specified border color.
    };

    enum class GLTEXTURE_FILTERING {
        LINEAR,
        NEAREST
    };

    /**
     * @brief The attributes that can be provided to the Texture object.
     */
    struct GLTextureAttributes {
        
        /**
         * @brief Width of the texture
         * 
         */
        unsigned int width;

        /**
         * @brief Height of the texture
         * 
         */
        unsigned int height;

        /**
         * @brief Data for the texture
         * 
         */
        unsigned char* data;

        /**
         * @brief The texture format settting
         */
        GLTEXTURE_FORMAT texture_format;

        /**
        * @brief The texture wrapping setting
        */
        GLTEXTURE_WRAP texture_wrapping;

        /**
         * @brief The texture filtering setting
         */
        GLTEXTURE_FILTERING texture_filtering;

    };

    class GLTexture {

        public:
            /**
             * @brief Constructor of the GLTexture class
             *
             * @param spec The configuration for all the opengl init functions.
             * options.
             */
            GLTexture(GLTextureAttributes attribs );

            /**
             * @brief Deconstructor of the GLTexture class
             */
            ~GLTexture() = default;

            /**
             * @brief Construct the GLTexture object
             * 
             */
            bool make();

            /**
             * @brief Bind this texture object (for OpenGL)
             * 
             * @return True if succeeded. 
             */
            bool bind() const;

            /**
             * @brief Unbinds this texture object (for OpenGL) 
             *
             * @return True if succeeded. 
             */
            bool unbind() const;

        private:

            unsigned int texture_format_to_gl( GLTEXTURE_FORMAT format_t) const;
            unsigned int texture_wrap_to_gl( GLTEXTURE_WRAP wrap_t) const;
            unsigned int texture_filter_to_gl( GLTEXTURE_FILTERING filter_t) const;

            GLTextureAttributes m_attribs;
            GL_TEXTURE_TYPE m_id;
    };

} // GL_CLASS

#endif // GLTEXTURE_HPP