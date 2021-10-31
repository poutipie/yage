
#include "AssetBundle.hpp"

#include <stdio.h>
#include <fstream>
#include <string>
#include <filesystem>

namespace YAGE {

namespace FS {

AssetBundle::AssetBundle() : m_image_assets() {
    return;
}

std::string AssetBundle::get_path(const char* asset) {

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

const ASSET::Image2D& AssetBundle::load_image(const char* asset) {

    std::map<std::string, std::unique_ptr<ASSET::Image2D>>::const_iterator it;
    
    std::string name(asset);
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

} // FS

} // YAGE

