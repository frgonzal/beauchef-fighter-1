#include "entity/fighter/state/fighter_state.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include "entity/fighter/state/fighter_moving_state.h"
#include "entity/fighter/fighter.h"


namespace bf
{

    FighterStandingState::FighterStandingState(FighterState *prevState) 
        : FighterState(prevState) {}

    void FighterStandingState::update(float deltaTime)
    {
        mFighter->updateTargetDirection();
    }

    bool FighterStandingState::isStanding() const 
    { 
        return true; 
    }

    bool FighterStandingState::isMoving() const 
    { 
        return false; 
    }

    bool FighterStandingState::isAttacking() const 
    { 
        return false; 
    }

    void FighterStandingState::attack() 
    { 
        return; 
    }

    void FighterStandingState::addVelocity(const glm::vec2 &velocity) 
    { 
        mVelocity += velocity;
        mFighter->setState(std::make_unique<FighterMovingState>(this));
    }
}