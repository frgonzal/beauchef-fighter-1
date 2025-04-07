#pragma once
#include "game_controller/states/game_state.hpp"
#include "game_controller/game_controller.hpp"


namespace bf
{
    class FinishedState : public GameState
    {
    public:
        FinishedState(GameController& gameController);
        ~FinishedState() = default;

        void update(float deltaTime) override;
        bool isRunning() const override;
        bool hasFinished() const override;
        float getTimeLeft() const override;

    private:
        GameController& mGameController;
    };
}