#pragma once
#include "entity/drawable.h"
#include "box.h"
#include <nothofagus.h>



namespace bf
{
    class FightRing : public Drawable
    {
    public:
        FightRing(const glm::vec2 &position, float width, float height);
        ~FightRing() = default;

        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;

    private:
        Box mInnerBox;
        Box mOuterBox;
    };
}