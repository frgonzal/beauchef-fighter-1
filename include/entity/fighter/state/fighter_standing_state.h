#pragma once
#include "entity/fighter/state/fighter_state.h"
#include "entity/actions/action.h"



namespace bf
{
    class FighterStandingState : public FighterState
    {
    public:
        FighterStandingState() = default;
        ~FighterStandingState() = default;

        void update(float deltaTime) override;

        bool isStanding() const override { return true; }
        bool isMoving() const override { return false; }
        bool isAttacking() const override { return false; }

        void addVelocity(const glm::vec2 &velocity) override;
        void attack(Action action) override;

        const Action &currentAction() const override { return mCurrentAction; }
        Action &currentAction() override { return mCurrentAction; }
        Action getNextAction() override { return Action::STAND; }

        const Sprite &attackBoxes() const override;

        void startToBlock() override;

    private:
        Action mCurrentAction = Action::STAND;
    };
}