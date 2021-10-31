/**
 * @file Image2D.hpp
 * @brief File For Image2D asset Type
 * @author poutipie
 * @version 1
 * @date 2020-07-27
 */

#ifndef IMAGE2D_HPP
#define IMAGE2D_HPP

#include <string>

namespace YAGE {

namespace FS {

namespace ASSET {


/**
 * @brief Basic Data Type for storing a 2D image
 */
class Image2D {

    public:
        Image2D(std::string file_path);
        Image2D( const Image2D& ) = delete; // non construction-copyable
        Image2D& operator=( const Image2D& ) = delete; // non copyable
        ~Image2D();

        bool is_valid() const;

        unsigned char* raw_data() const;

        int get_width() const;
        int get_height() const;
        int get_n_channels() const;

    private:

        unsigned char* m_data;
        int m_width;
        int m_height;
        int m_n_channels;
};

} // ASSET
} // FS
} // YAGE

#endif // IMAGE2D_HPP

