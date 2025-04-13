#pragma once
#include "entity/fighter/state/fighter_moving_state.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include "entity/fighter/fighter.h"



namespace bf
{
    FighterMovingState::FighterMovingState(FighterState *prevState) 
        : FighterState(prevState) {}

    void FighterMovingState::update(float deltaTime)
    {
        mPosition += mVelocity * deltaTime;
        mFighter->updateTargetDirection();
    }

    bool FighterMovingState::isStanding() const 
    { 
        return false; 
    }

    bool FighterMovingState::isMoving() const 
    { 
        return true; 
    }

    bool FighterMovingState::isAttacking() const 
    { 
        return false; 
    }

    void FighterMovingState::attack() 
    { 
        return;
    }

    void FighterMovingState::addVelocity(const glm::vec2 &velocity) 
    { 
        mVelocity += velocity;
        if (mVelocity == glm::vec2(0, 0))
        {
            mFighter->setState(std::make_unique<FighterStandingState>(this));
        }
    }
}