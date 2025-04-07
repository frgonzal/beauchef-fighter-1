#include "game_controller/states/running_state.hpp"
#include "game_controller/states/finished_state.hpp"



namespace bf
{
    RunningState::RunningState(GameController& gameController, float timeLeftInMilliseconds)
        : mGameController(gameController), mTimeLeft(timeLeftInMilliseconds) {}

    void RunningState::update(float deltaTime)
    {
        mTimeLeft -= deltaTime;
        if (mTimeLeft <= 0.0f)
        {
            mGameController.setState(std::make_unique<FinishedState>(mGameController));
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