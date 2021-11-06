#include "Font.hpp"
#include <stdio.h>

namespace YAGE {
namespace FS {
namespace ASSET {

Font::Font(std::string file_path)
: m_ft(), m_fontface(), m_glyphs(), m_is_valid(false), m_file_path(file_path)
{
    // All functions return a value different than 0 whenever an error occurred
    if (FT_Init_FreeType(&m_ft))
    {
        printf("ERROR::FREETYPE: Could not init FreeType Library\n");
        m_is_valid = false;
        return;
    }

    if (FT_New_Face(m_ft, m_file_path.c_str(), 0, &m_fontface)) {
        printf("ERROR::FREETYPE: Failed to load font\n");
        m_is_valid = false;
        return;
    }

    // set size to load glyphs as
    FT_Set_Pixel_Sizes(m_fontface, 0, 48);

    // load first 128 characters of ASCII set
    for (unsigned char c = 0; c < 128; c++)
    {
        // Load character glyph
        if (FT_Load_Char(m_fontface, c, FT_LOAD_RENDER))
        {
            printf("ERROR::FREETYTPE: Failed to load Glyph\n");
            m_is_valid = false;
            return;
        }

        m_glyphs.insert(
            {
                c,
                std::make_unique<Glyph> (
                    glm::ivec2(m_fontface->glyph->bitmap.width, m_fontface->glyph->bitmap.rows),
                    glm::ivec2(m_fontface->glyph->bitmap_left, m_fontface->glyph->bitmap_top),
                    static_cast<unsigned int>(m_fontface->glyph->advance.x),
                    m_fontface->glyph->bitmap.buffer
                )
            }
        );
    }

    m_is_valid = true;
    return;
}

Font::~Font() {
    FT_Done_Face(m_fontface);
    FT_Done_FreeType(m_ft);
}

bool Font::is_valid() const {
    return m_is_valid;
}

const Glyph& Font::get_glyph(unsigned char glyph) const {

    std::map<unsigned char, glyph_ptr>::const_iterator it;
    it = m_glyphs.find(glyph);
    return *it->second.get();
}

} // ASSET
} // FS
} // YAGE