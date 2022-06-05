/**
 * @file AssetStore.hpp
 * @brief File to contain the AssetStore class.
 * @author poutipie
 * @version 1
 * @date 2020-07-27
 */

#ifndef ASSETSTORE_HPP
#define ASSETSTORE_HPP

#include "Image2D.hpp"
#include "Font.hpp"
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

typedef std::unique_ptr<ASSET::Image2D> img2d_ptr;
typedef std::unique_ptr<ASSET::Font> font_ptr;

/**
 * @brief AssetStore class can be used for loading files from game assets directories
 */
class AssetStore {

    public:
        

        /**
         * @brief Default Constructor for AssetStore
         */
        AssetStore();


        /**
         * @brief Default Deconstructor for AssetStore class
         */
        ~AssetStore() = default;


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
         * @param asset Asset file name to load
         *
         * @return ASSET::Image2D representing the loaded image data 
         */
        const ASSET::Image2D& load_image(const char* asset);
    
        /**
         * @brief Loads a font asset
         * 
         * @param asset Asset file name to load
         * @return const ASSET::Font representing the loaded font data
         */
        const ASSET::Font& load_font(const char* asset);

    private:

        std::map<std::string, img2d_ptr> m_image_assets;
        std::map<std::string, font_ptr> m_font_assets;
};

} // Asset
} // FS
} // YAGE

#endif // ASSETSTORE_HPP
