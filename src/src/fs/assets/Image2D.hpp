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

        /**
         * @brief Construct a new Image2D object
         * 
         * @param file_path path to the image file to load
         */
        Image2D(std::string file_path);

        /**
         * @brief Destroy the Image 2D object
         * 
         */
        ~Image2D();

        /**
         * @brief Non construction-copyable
         * 
         */
        Image2D( const Image2D& ) = delete;

        /**
         * @brief Non copyable
         * 
         * @return Image2D& 
         */
        Image2D& operator=( const Image2D& ) = delete;

        /**
         * @brief Check if the Image2D object contains valid data
         * 
         * @return true with valid data
         * @return false otherwise
         */
        bool is_valid() const;

        /**
         * @brief Get the raw data pointer to image. Use only for old C interfaces that need it.
         * 
         * @return unsigned* image raw data bytes 
         */
        unsigned char* raw_data() const;

        /**
         * @brief Get the width of the image
         * 
         * @return int width
         */
        int get_width() const;

        /**
         * @brief Get the height of the image
         * 
         * @return int height
         */
        int get_height() const;

        /**
         * @brief Get the number of channels contained in the image data
         * 
         * @return int number of channels
         */
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

