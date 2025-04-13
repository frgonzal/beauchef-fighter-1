#pragma once
#include "entity/fighter/state/fighter_state.h"



namespace bf
{
    class FighterMovingState : public FighterState
    {
    public:
        FighterMovingState() = default;
        FighterMovingState(FighterState *prevState);
        ~FighterMovingState() = default;

        void update(float deltaTime) override;

        bool isStanding() const override;
        bool isMoving() const override;
        bool isAttacking() const override;
        void attack() override;
        void addVelocity(const glm::vec2 &velocity) override;
    };
}