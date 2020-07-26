#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "RenderObject.hpp"

namespace YAGE {
namespace GFX {

class Rectangle : public RenderObject {

    public:

        Rectangle(float x, float y, float width, float height);

};

} // GFX
} // YAGE

#endif // RECTANGLE_HPP

