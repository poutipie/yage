
#include "AssetBundle.hpp"

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <filesystem>

#include <stb_image.h>

namespace YAGE {

namespace FS {

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

ASSET::Image2D AssetBundle::load_image(const char* asset) {

    std::string path = get_path(asset);

    ASSET::Image2D result;
    result.data = stbi_load(path.c_str(), &result.width, &result.height, &result.n_channels, 0);

    if(!result.data) {
        printf("FAILED TO LOAD TEXTURE %s \n", path.c_str());
        throw ASSET::InvalidAssetException();
    }

    return result;    
}

} // FS

} // YAGE

