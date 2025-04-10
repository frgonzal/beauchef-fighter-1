#pragma once
#include "entity/fighter/state/fighter_state.h"



namespace bf
{
    class FighterStandingState : public FighterState
    {
    public:
        FighterStandingState() = default;
        ~FighterStandingState() = default;

        // void moveToLeft(float deltaTime);
        void update(float deltaTime) override;
    };
}