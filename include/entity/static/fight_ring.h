#pragma once
#include "entity/drawable.h"
#include "entity/box/box.h"
#include <nothofagus.h>
#include "entity/fighter/fighter.h"


namespace bf
{
    class FightRing : public Drawable
    {
    public:
        FightRing(float width, float height, float borderWidth);
        ~FightRing() = default;

        void setPosition(const glm::vec2& position) override;
        void setColor(const Color color) override { /* Dont update color */; }
        void update(Nothofagus::Canvas& canvas, float deltaTime) override { /* Do nothing */; }
        void addToCanvas(Nothofagus::Canvas& canvas) override;

        void moveEntityInsideLimits(Fighter& fighter);

    private:
        Box mInnerBox;
        Box mOuterBox;
    };
}