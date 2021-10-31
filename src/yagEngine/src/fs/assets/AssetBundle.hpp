/**
 * @file AssetBundle.hpp
 * @brief File to contain the AssetBundle class.
 * @author poutipie
 * @version 1
 * @date 2020-07-27
 */

#ifndef ASSETBUNDLE_HPP
#define ASSETBUNDLE_HPP

#include "Image2D.hpp"
#include <map>
#include <memory>

namespace YAGE {

namespace FS {

namespace ASSET {

struct InvalidAssetException : public std::exception
{
	const char * what () const throw ()
    {
    	return "Error while Loading asset";
    }
};

} // Asset

/**
 * @brief AssetBundle class can be used for loading files from game assets directories
 */
class AssetBundle {

    public:
        

        /**
         * @brief Default Constructor for AssetBundle
         */
        AssetBundle();


        /**
         * @brief Default Deconstructor for AssetBundle class
         */
        ~AssetBundle() = default;


        /**
         * @brief Gets the path to the asset.
         *
         * @param asset asset name to load
         *
         * @return The full path to the asset as char*
         */
        std::string get_path(const char* asset);


        /**
         * @brief Loads an Image asset
         *
         * @param asse Asset file name to loadt
         *
         * @return ASSET::Image2D representing the loaded image data 
         */
        const ASSET::Image2D& load_image(const char* asset);
    
    private:

        std::map<std::string, std::unique_ptr<ASSET::Image2D>> m_image_assets;
};

} // FS
} // YAGE

#endif // ASSETBUNDLE_HPP
