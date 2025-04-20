#pragma once
#include "entity/fighter/state/fighter_moving_state.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include "entity/fighter/state/fighter_attack_state.h"
#include "entity/fighter/state/fighter_block_state.h"
#include "entity/fighter/fighter.h"
#include "entity/actions/action.h"
#include <iostream>



namespace bf
{
    void FighterMovingState::update(float deltaTime)
    {
        if (mAnimationTimeElapsed == 0.f)
        {
            currentAction() = getNextAction();
            mFighter->startAction(currentAction());
            mFighter->playStepSound();
        }

        mFighter->setPosition(mFighter->position() + mFighter->velocity() * deltaTime);
        mFighter->updateViewDirection();

        if (mAnimationTimeElapsed >= mAnimationMillisecondsDuration + (std::rand() % 60))
        {
            mAnimationTimeElapsed = 0.0f;
            return;
        }
        mAnimationTimeElapsed += deltaTime;
    }

    Action FighterMovingState::getNextAction()
    {
        switch (currentAction())
        {
            case Action::STEP_LEFT:  return Action::STEP_RIGHT;
            case Action::STEP_RIGHT: return Action::STEP_LEFT;
            default:
                assert(false && "FighterMovingState: Invalid action type.");
        }
    }

    void FighterMovingState::attack(Action action) 
    { 
        mFighter->setState(std::make_unique<FighterAttackState>(action));
    }

    void FighterMovingState::addVelocity(const glm::vec2 &additionalVelocity) 
    { 
        mFighter->velocity() += additionalVelocity;
        if (mFighter->velocity() == glm::vec2(0, 0))
        {
            mFighter->setState(std::make_unique<FighterStandingState>());
        }
    }

    const Sprite &FighterMovingState::attackBoxes() const
    {
        return mFighter->leftArm();
    }

    void FighterMovingState::startToBlock() 
    { 
        mFighter->setState(std::make_unique<FighterBlockState>());
    }
}