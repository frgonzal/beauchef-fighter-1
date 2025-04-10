#pragma once
#include <nothofagus.h>


namespace bf
{
    class Drawable
    {
    public:
        virtual void addToCanvas(Nothofagus::Canvas& canvas) = 0;
        virtual void update(Nothofagus::Canvas& canvas, float deltaTime) = 0;
    };
}