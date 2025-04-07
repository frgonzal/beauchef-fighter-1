#include "game_controller/states/finished_state.hpp"



namespace bf
{
    FinishedState::FinishedState(GameController& gameController) 
        : mGameController(gameController) {}

    void FinishedState::update(float deltaTime)
    { } 

    bool FinishedState::isRunning() const
    {
        return false;
    }

    bool FinishedState::hasFinished() const
    {
        return true;
    }

    float FinishedState::getTimeLeft() const
    {
        return 0.0f;
    }
}