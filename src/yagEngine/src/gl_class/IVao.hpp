/**
 * @file IVao.hpp
 * @brief The interface variables and classes for the VAO objects.
 * @author poutipie
 * @version 1
 * @date 2020-07-26
 */

#ifndef IVAO_HPP
#define IVAO_HPP

namespace GL_CLASS {
   

    /**
     * @brief Interface class for the Vertex Array Objects.
     */
    class IVao {

        public:

            
            /**
             * @brief Make the VAO.
             *
             * @return True if succeeded.
             */
            virtual bool make() = 0;

            /**
             * @brief Bind the VAO.
             *
             * @return True if succeeded.
             */
            virtual bool bind() const = 0;

            /**
             * @brief Draw the Vao using boud gl shaderpipeline
             *
             * @return True if succeded
             */
            virtual bool draw() const = 0;

            /**
             * @brief Unbind the VAO
             *
             * @return True if succeeded.
             */
            virtual bool unbind() const = 0;
    };

}


#endif // IVAO_HPP
