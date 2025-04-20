#include "game_controller/game_controller.h"
#include "game_controller/states/running_state.h"
#include "game_controller/states/finished_state.h"


namespace bf
{
    GameController::GameController()
    {
        setState(std::make_unique<RunningState>(30e3f));
    }

    void GameController::update(float deltaTime)
    {
        mCurrentState->update(deltaTime);
    }

    void GameController::setState(std::unique_ptr<GameState> newState)
    {
        mCurrentState = std::move(newState);
        mCurrentState->setGameController(this);
    }

    void GameController::setWinner(Fighter* winner)
    {
        assert(winner != nullptr && "GameController::setWinner: Winner cannot be null.");

        if (!hasWinner() && winner->isAlive() && mCurrentState->isRunning())
        {
            mWinner = winner;
            mCurrentState->setWinner();
        }
        else 
        {
            std::cout << "(Warning) GameController::setWinner: Winner is already set or not alive." << std::endl;
        }
    }

    void GameController::setOnGameFinishedCallback(std::function<void()> callback)
    {
        mOnGameFinishedCallback = std::move(callback);
    }
}