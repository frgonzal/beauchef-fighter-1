#pragma once
#include "entity/fighter/state/fighter_state.h"
#include "entity/actions/action.h"



namespace bf
{
    class FighterMovingState : public FighterState
    {
    public:
        FighterMovingState() = default;
        ~FighterMovingState() = default;

        void update(float deltaTime) override;

        bool isStanding() const override { return false; }
        bool isMoving() const override { return true; }
        bool isAttacking() const override { return false; }

        void attack(Action action) override;
        void addVelocity(const glm::vec2 &velocity) override;

        const Action &currentAction() const override { return mCurrentAction; }
        Action &currentAction() override { return mCurrentAction; }
        Action getNextAction() override;

        const Sprite &attackBoxes() const override;

        void startToBlock() override;

    private:
        const float mAnimationMillisecondsDuration = 220.f;
        float mAnimationTimeElapsed = 0.f;
        Action mCurrentAction = Action::STEP_LEFT;
    };
}