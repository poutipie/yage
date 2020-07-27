/**
 * @file AssetCommons.hpp
 * @brief File For Common Asset Types
 * @author poutipie
 * @version 1
 * @date 2020-07-27
 */

#ifndef ASSETCOMMONS_HPP
#define ASSETCOMMONS_HPP

#include <string>

namespace YAGE {

namespace FS {

namespace ASSET {


/**
 * @brief Basic Data Type for storing a 2D image
 */
struct Image2D {

    unsigned char* data;
    unsigned int data_len;
    int width;
    int height;
    int n_channels;

    ~Image2D() {
        delete data;
    }
};

} // ASSET
} // FS
} // YAGE

#endif // ASSETCOMMONS_HPP

