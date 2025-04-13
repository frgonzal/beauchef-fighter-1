#pragma once

namespace bf
{
    class Reflectable
    {
    public:

        /** 
         * @brief Reflect the object over its Y-axis.
         * This method reflects the object over its Y-axis, effectively flipping it horizontally.
         */
        virtual void reflectOverYAxis() = 0;

        /** 
         * @brief Reflect the object over the Y-axis at a given position.
         * @param xPosition The X position of the reflection line.
         */
        virtual void reflectOverYAxis(const float xPosition) = 0;
    };
}