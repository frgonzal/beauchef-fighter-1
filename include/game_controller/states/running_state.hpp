#pragma once

#include "game_controller/states/game_state.hpp"
#include "game_controller/game_controller.hpp"
#include "memory"

namespace bf
{
    class RunningState : public GameState
    {
    public:
        RunningState(GameController& gameController, float timeLeftInMilliseconds);
        ~RunningState() = default;

        void update(float deltaTime) override;
        bool isRunning() const override;
        bool hasFinished() const override;
        float getTimeLeft() const override;

    private:
        GameController& mGameController;
        float mTimeLeft;
    };
}