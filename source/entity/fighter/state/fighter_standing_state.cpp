#include "entity/fighter/state/fighter_state.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include "entity/fighter/state/fighter_moving_state.h"
#include "entity/fighter/state/fighter_attack_state.h"
#include "entity/fighter/state/fighter_block_state.h"
#include "entity/fighter/fighter.h"


namespace bf
{
    void FighterStandingState::update(float deltaTime)
    {
        mFighter->stopAction();
        mFighter->updateViewDirection();
    }

    void FighterStandingState::attack(Action action) 
    { 
        mFighter->setState(std::make_unique<FighterAttackState>(action));
    }

    void FighterStandingState::addVelocity(const glm::vec2 &additionalVelocity) 
    { 
        mFighter->velocity() += additionalVelocity;
        if (mFighter->velocity() != glm::vec2(0, 0))
        {
            mFighter->setState(std::make_unique<FighterMovingState>());
        }
    }

    const Sprite &FighterStandingState::attackBoxes() const
    {
        return mFighter->leftArm();
    }

    void FighterStandingState::startToBlock() 
    { 
        mFighter->setState(std::make_unique<FighterBlockState>());
    }
}