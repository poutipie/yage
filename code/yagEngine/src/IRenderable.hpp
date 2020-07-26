#ifndef IRENDERABLE_HPP
#define IRENDERABLE_HPP

namespace YAGE {
namespace GFX {

    class IRenderable {
        
        public:

            virtual bool render() const = 0;

    };

} // GFX
} // YAGE

#endif // IRENDERABLE_HPP



