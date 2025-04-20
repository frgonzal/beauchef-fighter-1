#include "entity/static/fight_ring.h"
#include <nothofagus.h>
#include <colors.h>
#include <iostream>
#include <format>



namespace bf
{
    FightRing::FightRing(float width, float height, float borderWidth) :
        mOuterBox(width + 2 * borderWidth, height + 2 * borderWidth),
        mInnerBox(width, height)
    {
        mOuterBox.setColor(Color::BROWN);
        mInnerBox.setColor(Color::YELLOW);
    }

    void FightRing::setPosition(const glm::vec2& position)
    {
        mOuterBox.setPosition(position);
        mInnerBox.setPosition(position);
    }

    void FightRing::addToCanvas(Nothofagus::Canvas& canvas)
    {
        mOuterBox.addToCanvas(canvas);
        mInnerBox.addToCanvas(canvas);
    }

    void FightRing::moveEntityInsideLimits(Fighter& fighter)
    {
        fighter.moveInsideLimits(mInnerBox.bottomLeft(), mInnerBox.topRight());
    }
}