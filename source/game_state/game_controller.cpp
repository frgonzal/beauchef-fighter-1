#include "game_controller/game_controller.hpp"
#include "game_controller/states/running_state.hpp"


namespace bf
{
    GameController::GameController()
        : mCurrentState(std::make_unique<RunningState>(*this, 30e3f)) {}

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