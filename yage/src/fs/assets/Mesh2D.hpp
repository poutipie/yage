#ifndef MESH2D_HPP
#define MESH2D_HPP

#include <stdlib.h>
#include <string>
#include <vector>

#include "gl_class/Vao.hpp"

namespace YAGE {

namespace FS {

namespace ASSET {


/**
* Class to hold mesh data for rendering into 2D scene
*/
class Mesh2D {

    public:

        Mesh2D(std::string file_path);
        ~Mesh2D() = default;

        float* vertex_data() const;
        unsigned int vertex_data_len() const;

        unsigned int* index_data() const;
        unsigned int index_data_len() const;

    private:
        std::vector<float> m_vertex_data;
        std::vector<unsigned int> m_index_data;

};

} // ASSET
} // FS
} // YAGE

#endif // MESH2D_HPP

