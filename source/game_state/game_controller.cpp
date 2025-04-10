#include "game_controller/game_controller.h"
#include "game_controller/states/running_state.h"


namespace bf
{
    GameController::GameController()
    {
        mCurrentState = std::make_unique<RunningState>(30e3f);
        mCurrentState->setGameController(this);
    }

    void GameController::update(float deltaTime)
    {
        mCurrentState->update(deltaTime);
    }

    void GameController::setState(std::unique_ptr<GameState> newState)
    {
        mCurrentState = std::move(newState);
    }

    bool GameController::isRunning() const
    {
        return mCurrentState->isRunning();
    }

    bool GameController::hasFinished() const
    {
        return mCurrentState->hasFinished();
    }

    float GameController::getTimeLeft() const
    {
        return mCurrentState->getTimeLeft();
    }
} // namespace bf