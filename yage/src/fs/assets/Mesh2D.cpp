
#include "Mesh2D.hpp"

#include <fstream>
#include <sstream>

namespace YAGE {
namespace FS {
namespace ASSET {

Mesh2D::Mesh2D(std::string file_path) :
    m_vertex_data(), m_index_data()
{

    std::ifstream infile(file_path);

    std::string line;
    unsigned int vert_index = 0;
    while(std::getline(infile, line)) {
        
        std::istringstream iss(line);
        float x, y, tex_x, tex_y;
        char sep;

        bool line_read = (bool)(iss >> x >> y >> sep >> tex_x >> tex_y);

        if(line_read) {
            m_vertex_data.insert(
                m_vertex_data.end(), 
                {x, y, 0.0f, tex_x, tex_y}
            );

            if (vert_index >= 2) {
                m_index_data.insert(
                    m_index_data.end(), 
                    {
                        vert_index - 2,
                        vert_index - 1,
                        vert_index,
                    }
                );
            }
        }
        ++ vert_index;
    }
}

float* Mesh2D::vertex_data() const {
    return (float*)&m_vertex_data[0];
}

unsigned int Mesh2D::vertex_data_len() const {
    return m_vertex_data.size() * sizeof(float);
}

unsigned int* Mesh2D::index_data() const {
    return (unsigned int*)&m_index_data[0];
}

unsigned int Mesh2D::index_data_len() const {
    return m_index_data.size() * sizeof(unsigned int);
}

} // ASSET
} // FS
} // YAGE