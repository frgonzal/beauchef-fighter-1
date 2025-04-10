#pragma once
#include "game_controller/states/game_state.h"
#include "game_controller/game_controller.h"
#include "memory"


namespace bf
{
    class RunningState : public GameState
    {
    public:
        RunningState(float timeLeftInMilliseconds);
        ~RunningState() = default;

        void update(float deltaTime) override;
        bool isRunning() const override;
        bool hasFinished() const override;
        float getTimeLeft() const override;

    private:
        float mTimeLeft;
    };
}