#pragma once

namespace bf
{

    /** 
     * @brief Forward declaration of Box and CompoundBox classes.
     * These classes are used in the Collidable interface.
     */
    class Box; class CompoundBox;


    /**
     * @brief Interface for collidable objects.
     * This interface defines the methods that must be implemented by any class that is collidable.
     */
    class Collidable
    {
    public:
        
        /**
         * @brief Check if this collidable object collides with another collidable object.
         * @param other The other collidable object to check for collision with.
         * @return true if the objects collide, false otherwise.
         */
        virtual bool collides(const Collidable* other) const = 0;

        virtual bool collidesWithBox(const Box* box) const = 0;
        virtual bool collidesWithCompoundBox(const CompoundBox* compoundBox) const = 0;
    };
}