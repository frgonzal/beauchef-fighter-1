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

        void update(float deltaTime) override { }
        bool isRunning() const override { return false; }
        bool hasFinished() const override { return true; }
        float getTimeLeft() const override { return 0.0f; }
        void setWinner() override;
    };
}