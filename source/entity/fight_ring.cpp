#include "entity/fight_ring.h"
#include <nothofagus.h>
#include <colors.h>
#include <iostream>
#include <format>



namespace bf
{
    FightRing::FightRing(const glm::vec2 &position, float width, float height) :
        mInnerBox(position, width, height),
        mOuterBox(position, width + 20, height + 20)
    {
        mInnerBox.setColor(Colors::yellow);
        mOuterBox.setColor(Colors::brown);
    }

    void FightRing::addToCanvas(Nothofagus::Canvas& canvas)
    {
        mOuterBox.addToCanvas(canvas);
        mInnerBox.addToCanvas(canvas);
    }

    void FightRing::update(Nothofagus::Canvas& canvas, float deltaTime)
    {
        throw std::runtime_error("Not implemented yet.");
    }
}