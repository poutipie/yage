
#include "AssetStore.hpp"

#include <stdio.h>
#include <fstream>
#include <string>
#include <filesystem>

namespace YAGE {
namespace FS {
namespace ASSET {

AssetStore::AssetStore() : m_image_assets(), m_font_assets() {
    return;
}

std::string AssetStore::get_path(const char* asset) {

    std::filesystem::path path;
    bool path_found = false;

    for (auto& p: std::filesystem::recursive_directory_iterator("assets")) {
        if (p.path().filename() == asset) {
            path = p.path();
            path_found = true;
            break;
        }
    }

    if (!path_found) {
        printf("FAILED TO FIND ASSET %s", asset);
        return NULL;
    }

    return path.string();
}

const ASSET::Image2D& AssetStore::load_image(const char* asset) {

    std::string name(asset);
    std::map<std::string, img2d_ptr>::const_iterator it;

    it = m_image_assets.find(name);
    if (it == m_image_assets.end()) {

        std::string path = get_path(asset);

        m_image_assets.insert({name, std::make_unique<ASSET::Image2D>(path)});
        it = m_image_assets.find(name);

        if(!it->second->is_valid()) {

            printf("FAILED TO LOAD IMAGE %s \n", path.c_str());
            throw ASSET::InvalidAssetException();
        }

    }
    return *it->second.get();
}

const ASSET::Font& AssetStore::load_font(const char* asset) {

    std::string name(asset);
    std::map<std::string, font_ptr>::const_iterator it;

    it = m_font_assets.find(name);
    if (it == m_font_assets.end()) {

        std::string path = get_path(asset);
        m_font_assets.insert({name, std::make_unique<ASSET::Font>(path)});
        it = m_font_assets.find(name);

        if(!it->second->is_valid()) {

            printf("FAILED TO LOAD FONT &s \n", path.c_str());
            throw ASSET::InvalidAssetException();
        }
    }
    return *it->second.get();
}

} // ASSET
} // FS
} // YAGE

