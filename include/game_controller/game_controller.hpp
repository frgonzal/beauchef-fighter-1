#pragma once
#include <memory>
#include "game_controller/states/game_state.hpp"



namespace bf
{
    class GameController
    {
    public:
        GameController();
        ~GameController() = default;

        void update(float deltaTime);
        void setState(std::unique_ptr<GameState> newState);
        bool isRunning() const;
        bool hasFinished() const;
        float getTimeLeft() const;

    private:
        std::unique_ptr<GameState> mCurrentState;
    };
}

