#pragma once
#include "game_controller/states/game_state.h"
#include "game_controller/game_controller.h"


namespace bf
{
    class FinishedState : public GameState
    {
    public:
        FinishedState() = default;
        ~FinishedState() = default;

        void update(float deltaTime) override;
        bool isRunning() const override;
        bool hasFinished() const override;
        float getTimeLeft() const override;
    };
}