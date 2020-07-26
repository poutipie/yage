/**
 * @file IRenderable.hpp
 * @brief The file for the IRenderable interface class and related types.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */

#ifndef IRENDERABLE_HPP
#define IRENDERABLE_HPP

namespace YAGE {
namespace GFX {


    /**
     * @brief IRenderable interface should be used when creating am object that will be rendearable
     * by a Renderer class.
     */
    class IRenderable {
        
        public:
            
            /**
             * @brief Render the renderable
             *
             * @return True if the rendering succeeded.
             */
            virtual bool render() const = 0;

    };

} // GFX
} // YAGE

#endif // IRENDERABLE_HPP



