#include "entity/fighter/state/fighter_attack_state.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include "entity/fighter/state/fighter_moving_state.h"
#include "entity/fighter/fighter.h"
#include "colors.h"
#include <iostream>
#include <exception>

namespace bf
{
    FighterAttackState::FighterAttackState(Action attackAction)
    {
        switch (attackAction)
        {
            case Action::LEFT_ARM_ATTACK:
                currentAction() = Action::PREPARE_LEFT_ARM_ATTACK;
                break;
            case Action::LEFT_LEG_ATTACK:
                currentAction() = Action::PREPARE_LEFT_LEG_ATTACK;
                break;
            default:
                throw std::runtime_error("FighterAttackState: Invalid action type.");
        }
    }

    void FighterAttackState::update(float deltaTime)
    {
        if (mAnimationTimeElapsed == 0.0f)
        {
            mFighter->startAction(currentAction());
            mAnimationTimeElapsed += deltaTime;
            return;
        }

        if (mAnimationTimeElapsed < mPreparationMillisecondsDuration)
        {
            mAnimationTimeElapsed += deltaTime;
            return;
        }

        if (!mHasPlayedAttackAnimation)
        {
            mFighter->startAction(getNextAction());
            mFighter->playAttackSound();
            mHasPlayedAttackAnimation = true;
        }

        if (!mAttackHasImpacted)
        {
            Fighter &defender = mFighter->target();
            if (defender.collides(&mFighter->attackBoxes()))
            {
                attackFighter(&mFighter->target());
            }
        }

        if (mAnimationTimeElapsed >= mPreparationMillisecondsDuration + mAttackMillisecondsDuration)
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

        mAnimationTimeElapsed += deltaTime;
    }

    Action FighterAttackState::getNextAction()
    {
        switch (currentAction())
        {
            case Action::PREPARE_LEFT_ARM_ATTACK:
                return Action::LEFT_ARM_ATTACK;
            case Action::PREPARE_LEFT_LEG_ATTACK:
                return Action::LEFT_LEG_ATTACK;
            case Action::LEFT_ARM_ATTACK:
                return Action::LEFT_ARM_ATTACK;
            case Action::LEFT_LEG_ATTACK:
                return Action::LEFT_LEG_ATTACK;
            default:
                throw std::runtime_error("FighterAttackState::getNextAction: Invalid action index.");
        }
    }

    const Sprite &FighterAttackState::attackBoxes() const
    {
        switch (currentAction())
        {
            case Action::PREPARE_LEFT_ARM_ATTACK:
                return mFighter->leftArm();
            case Action::PREPARE_LEFT_LEG_ATTACK:
                return mFighter->leftLeg();
            case Action::LEFT_ARM_ATTACK:
                return mFighter->leftArm();
            case Action::LEFT_LEG_ATTACK:
                return mFighter->leftLeg();
            default:
                assert(false && "FighterAttackState::attackBoxes: Invalid action type.");
        }
    }

    void FighterAttackState::attackFighter(Fighter* attacker)
    {
        if (mAttackHasImpacted)
        {
            std::cout << "(Warning) FighterAttackState::attackFighter: Already attacked." << std::endl;
            return;
        }
        
        attacker->receiveAttack(*mFighter);
        mAttackHasImpacted = true;
    }
}