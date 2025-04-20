#pragma once
#include "entity/fighter/state/fighter_state.h"

namespace bf
{
    class FighterAttackState : public FighterState
    {
    public:
        FighterAttackState(Action attackAction);
        ~FighterAttackState() = default;

        void update(float deltaTime) override;

        bool isStanding() const override { return false; }
        bool isMoving() const override { return false; }
        bool isAttacking() const override { return true; }
        void attack(Action action) override { /* Do nothing */; }

        const Action &currentAction() const override { return mCurrentAction; }
        Action &currentAction() override { return mCurrentAction; }

        Action getNextAction() override;

        const Sprite &attackBoxes() const override;

        void attackFighter(Fighter* attacker);

    private:
        const float mPreparationMillisecondsDuration = 250.0f;
        const float mAttackMillisecondsDuration = 200.0f;

        float mAnimationTimeElapsed = 0.0f;

        bool mAttackHasImpacted = false;
        Action mCurrentAction;

        bool mHasPlayedAttackAnimation = false;
    };
}