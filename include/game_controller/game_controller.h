#pragma once
#include <memory>
#include "game_controller/states/game_state.h"
#include "entity/fighter/fighter.h"
#include <functional>


namespace bf
{
    class GameController
    {
    public:
        GameController();
        ~GameController() = default;

        void update(float deltaTime);
        void setState(std::unique_ptr<GameState> newState);

        bool isRunning() const { return mCurrentState->isRunning(); }
        bool hasFinished() const { return mCurrentState->hasFinished(); }
        float getTimeLeft() const { return mCurrentState->getTimeLeft(); }

        void setWinner(Fighter* winner);
        bool hasWinner() const { return mWinner != nullptr; }
        const Fighter &getWinner() const { return *mWinner; }

        void setOnGameFinishedCallback(std::function<void()> callback);
        void onGameFinishedCallback() { mOnGameFinishedCallback(); }

    private:
        std::unique_ptr<GameState> mCurrentState;
        Fighter* mWinner = nullptr;
        std::function<void()> mOnGameFinishedCallback = [](){std::cout << "(Info) Game finished." << std::endl;};
    };
}

