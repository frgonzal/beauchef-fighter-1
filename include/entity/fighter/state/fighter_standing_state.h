#pragma once
#include "entity/fighter/state/fighter_state.h"



namespace bf
{
    class FighterStandingState : public FighterState
    {
    public:
        FighterStandingState() = default;
        FighterStandingState(FighterState *prevState);
        ~FighterStandingState() = default;

        void update(float deltaTime) override;

        bool isStanding() const override;
        bool isMoving() const override;
        bool isAttacking() const override;
        void attack() override;
        void addVelocity(const glm::vec2 &velocity) override;

    };
}