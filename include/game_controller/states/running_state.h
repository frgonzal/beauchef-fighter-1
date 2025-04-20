#pragma once
#include "game_controller/states/game_state.h"
#include "game_controller/game_controller.h"


namespace bf
{
    class RunningState : public GameState
    {
    public:
        RunningState(float timeLeftInMilliseconds);
        ~RunningState() = default;

        void update(float deltaTime) override;
        bool isRunning() const override { return true; }
        bool hasFinished() const override { return false; }
        float getTimeLeft() const override { return mTimeLeft; }

        void setWinner() override;

    private:
        float mTimeLeft;
    };
}