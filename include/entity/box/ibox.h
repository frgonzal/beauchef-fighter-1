#pragma once
#include "entity/drawable.h"
#include "entity/collidable.h"
#include "entity/reflectable.h"
#include <nothofagus.h>
#include <glm/vec2.hpp>
#include "colors.h"
#include "entity/animatable.h"


namespace bf 
{
    /**
     * @brief Common interface for Box-like objects.
     *
     * This interface gathers the common functionalities shared by both
     * Box and CompoundBox.
     */
    class IBox : public Drawable, public Collidable, public Reflectable, public Animatable
    {
    public:
        virtual ~IBox() = default;

        /**
         * @brief Set the new center of the box.
         * @param newPosition The new position of the box.
         * @return A reference to the modified box.
         */
        virtual void setPosition(const glm::vec2& newPosition) = 0;

        /**
         * @brief Get the center of the box.
         * @return The center of the box.
         */
        virtual void setColor(const Color& color) = 0;
    };
}
