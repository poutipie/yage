/**
 * @file Rectangle.hpp
 * @brief File for the Rectangle object. 
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "RenderObject.hpp"

namespace YAGE {
namespace GFX {


/**
* @brief Class for a simple 2d rectangle object. No Sprite support, just base color and a
* transform.
*/
class Rectangle : public RenderObject {

    public:

        /**
         * @brief Contstructor for the Rectangle object.
         *
         * @param x The x position of this rectangle in cartesian coordinate system.
         * @param y The y position of this rectangle in cartesian coordinate system.
         * @param width The width of this rectangle in cartesian coordinate system.
         * @param height The height of this rectangle in cartesian coordinate system.
         */
        Rectangle(float x, float y, float width, float height);

};

} // GFX
} // YAGE

#endif // RECTANGLE_HPP

