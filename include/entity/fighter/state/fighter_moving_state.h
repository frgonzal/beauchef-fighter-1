#pragma once
#include "entity/fighter/state/fighter_state.h"



namespace bf
{
    class FighterMovingState : public FighterState
    {
    public:
        FighterMovingState() = default;
        ~FighterMovingState() = default;

        void update(float deltaTime) override;
    };
}