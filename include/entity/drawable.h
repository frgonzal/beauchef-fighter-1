#pragma once
#include <nothofagus.h>
#include "colors.h"


namespace bf
{
    class Drawable
    {
    public:
        virtual ~Drawable() = default;

        virtual void addToCanvas(Nothofagus::Canvas& canvas) = 0;
        virtual void update(Nothofagus::Canvas& canvas, float deltaTime) = 0;

        virtual void setPosition(const glm::vec2& position) = 0;
        virtual void setColor(const Color color) = 0;

        virtual void enable() { mEnabled = true; }
        virtual void disable() { mEnabled = false; }
        bool isEnabled() const { return mEnabled; }

    protected: 
        bool mEnabled = true;
    };
}