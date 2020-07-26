#ifndef IVAO_HPP
#define IVAO_HPP

namespace GL_CLASS {
    
    class IVao {

        public:

            /* Make the Vao */
            virtual bool make() = 0;

            /* Bind the Vao */
            virtual bool bind() const = 0;

            /* Draws Vao using the bound gl shaderpipeline */
            virtual bool draw() const = 0;

            /* Unbind the Vao */
            virtual bool unbind() const = 0;
    };

}


#endif // IVAO_HPP
