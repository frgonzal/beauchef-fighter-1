#include "game_controller/states/running_state.h"
#include "game_controller/states/finished_state.h"



namespace bf
{
    RunningState::RunningState(float timeLeftInMilliseconds) : 
        mTimeLeft(timeLeftInMilliseconds) {}

    void RunningState::update(float deltaTime)
    {
        mTimeLeft -= deltaTime;
        if (mTimeLeft <= 0.0f)
        {
            mGameController->setState(std::make_unique<FinishedState>());
        }
    } 

    bool RunningState::isRunning() const
    {
        return true;
    }

    bool RunningState::hasFinished() const
    {
        return false;
    }

    float RunningState::getTimeLeft() const
    {
        return mTimeLeft;
    }
}