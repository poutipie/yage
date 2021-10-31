#include "Image2D.hpp"

#include <stb_image.h>

namespace YAGE {

namespace FS {

namespace ASSET {

Image2D::Image2D(std::string file_path) : 
    m_data(nullptr), m_height(0), m_width(0), m_n_channels(0)
{
    m_data = stbi_load(file_path.c_str(), &m_width, &m_height, &m_n_channels, 0);
}

Image2D::~Image2D() {
    stbi_image_free(m_data);
}

bool Image2D::is_valid() const {
    if(!m_data) {
        return false;
    }
    return true;
}

unsigned char* Image2D::raw_data() const {
    return m_data;
}

int Image2D::get_width() const {
    return m_width;
}

int Image2D::get_height() const {
    return m_height;
}

int Image2D::get_n_channels() const {
    return m_n_channels;
}

} // ASSET
} // FS
} // YAGE