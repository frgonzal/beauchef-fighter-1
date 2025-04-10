#include "entity/fighter/fighter.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include <iostream>
#include "colors.h"


namespace bf
{
    Fighter::Fighter()
        : mCurrentState(std::make_unique<FighterStandingState>())
    {
        for(auto& [box, offset] : mBody)
        {
            box->setColor(mColor);
        }

        mCurrentState->setFighter(this);
        mVelocity = {0.01f, 0.0f};
    }

    void Fighter::setState(std::unique_ptr<FighterState> newState)
    {
        mCurrentState = std::move(newState);
    }


    void Fighter::addToCanvas(Nothofagus::Canvas& canvas)
    {
        for(auto& [box, offset] : mBody)
        {
            box->addToCanvas(canvas);
        }
    }

    void Fighter::update(Nothofagus::Canvas& canvas, float deltaTime)
    {
        mPosition += mVelocity * deltaTime;
        for(auto& [box, offset] : mBody)
        {
            box->setPosition(mPosition + offset);
            box->update(canvas, deltaTime);
        }
    }

    void Fighter::setPosition(const glm::vec2& newPosition)
    {
        mPosition = newPosition;
        for(auto& [box, offset] : mBody)
        {
            box->setPosition(mPosition + offset);
        }
    }
}