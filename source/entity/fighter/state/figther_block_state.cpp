#include "entity/fighter/state/fighter_block_state.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include "entity/fighter/state/fighter_moving_state.h"
#include "entity/fighter/fighter.h"
#include <math.h>


namespace bf
{
    void FighterBlockState::update(float deltaTime)
    {
        if (mAnimationTimeElapsed == 0.f)
        {
            mFighter->startAction(currentAction());
            mFighter->playBlockSound();
        }
        mFighter->updateViewDirection();
        mAnimationTimeElapsed += deltaTime;
    }

    const Sprite &FighterBlockState::attackBoxes() const
    {
        return mFighter->leftArm();
    }

    void FighterBlockState::receiveAttack(const Fighter* attacker) 
    { 
        assert(mFighter != nullptr && "FighterBlockState error: Fighter pointer is null.");
        assert(mFighter->collides(&attacker->attackBoxes()) && "FighterBlockState::receiveAttack: Attacker does not collide with fighter's attack boxes.");

        float attackPower = std::max(0.f, attacker->attackPower() - mFighter->defensePower());
        mFighter->setHealth(mFighter->health() - attackPower);
    }

    void FighterBlockState::stopToBlock() 
    { 
        mFighter->stopAction();
        if (mFighter->velocity() == glm::vec2(0, 0))
        {
            mFighter->setState(std::make_unique<FighterStandingState>());
        } 
        else
        {
            mFighter->setState(std::make_unique<FighterMovingState>());
        }
    }
}