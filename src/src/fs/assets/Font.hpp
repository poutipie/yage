/**
 * @file Font.hpp
 * @author poutipie
 * @brief 
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FONT_HPP
#define FONT_HPP

#include <glm/glm.hpp>
#include <string>
#include <map>
#include <memory>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace YAGE {
namespace FS {
namespace ASSET {

    class Glyph {

        public:

            /**
             * @brief Construct a new Glyph object
             * 
             * @param size Size of glyph
             * @param bearing Offset from baseline to left/top of glyph
             * @param advance Horizontal offset to advance the glyph
             * @param bitmap_buffer glyph bitmap data
             */
            Glyph(glm::ivec2 size, glm::ivec2 bearing, unsigned int advance, unsigned char* bitmap_buffer)
            : size(size), bearing(bearing), advance(advance), bitmap_buffer(bitmap_buffer)
            {
                return;
            }

            /**
             * @brief Non construction-copyable
             * 
             */
            Glyph( const Glyph& ) = delete;

            /**
             * @brief Non copyable
             * 
             * @return Glyph& 
             */
            Glyph& operator=( const Glyph& ) = delete;

            /**
             * @brief Default. Destroy the Glyph object. 
             * bitmap buffer is owned by FT_Library memory manager. So don't delete it here.
             */
            ~Glyph() = default;

            glm::ivec2     size;           // Size of glyph
            glm::ivec2     bearing;        // Offset from baseline to left/top of glyph
            unsigned int   advance;        // Horizontal offset to advance the glyph
            unsigned char* bitmap_buffer;  // glyph bitmap data

    };

    typedef std::unique_ptr<Glyph> glyph_ptr;

    class Font {

        public:

            /**
             * @brief Construct a new Font object
             * 
             * @param file_path Path to a truetype font file
             */
            Font(std::string file_path);

            /**
             * @brief Deconstruct Font object
             */
            ~Font();

            /**
             * @brief Non construction-copyable
             */
            Font( const Font& ) = delete;

            /**
             * @brief Non copyable
             */
            Font& operator=( const Font& ) = delete;

            /**
             * @brief Check if the Font object contains valid data
             * 
             * @return true with valid data
             * @return false otherwise
             */
            bool is_valid() const;

            /**
             * @brief Get a glyph object from the fonr matching the character
             * 
             * @param glyph the character representing the glyph to get.
             * @return const Glyph& reference to the found glyph obhect
             */
            const Glyph& get_glyph(unsigned char glyph) const;

        private:

            FT_Library m_ft;
            FT_Face    m_fontface;

            std::string m_file_path;
            bool m_is_valid;

            std::map<unsigned char, glyph_ptr> m_glyphs;
    };

} // ASSET
} // FS
} // YAGE

#endif // FONT_HPP