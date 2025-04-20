#pragma once
#include "entity/fighter/state/fighter_state.h"


namespace bf
{
    class FighterBlockState : public FighterState
    {
    public:
        FighterBlockState() = default;
        ~FighterBlockState() = default;

        void update(float deltaTime) override;

        bool isStanding() const override { return false; }
        bool isMoving() const override { return false; }
        bool isAttacking() const override { return false; }
        void attack(Action action) override { /* Do nothing */; }

        const Action &currentAction() const override { return mCurrentAction; }
        Action &currentAction() override { return mCurrentAction; }

        Action getNextAction() override { return Action::BLOCK; }

        const Sprite &attackBoxes() const override;

        void receiveAttack(const Fighter* attacker) override;

        void stopToBlock() override;

    private:
        Action mCurrentAction = Action::BLOCK;
        float mAnimationTimeElapsed = 0.0f;
    };
}