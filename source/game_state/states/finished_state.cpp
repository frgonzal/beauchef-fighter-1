#include "game_controller/states/finished_state.h"
#include <stdexcept>



namespace bf
{
    void FinishedState::update(float deltaTime)
    { 
        throw std::runtime_error("Game has finished. No updates are allowed.");
    } 

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