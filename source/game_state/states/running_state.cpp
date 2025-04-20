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
            mGameController->onGameFinishedCallback();
            mGameController->setState(std::make_unique<FinishedState>());
        }
    } 

    void RunningState::setWinner()
    {
        assert(mGameController != nullptr && "RunningState::setWinner: GameController is null.");
        assert(mGameController->hasWinner() && "RunningState::setWinner: Winner is null.");

        mGameController->onGameFinishedCallback();
        mGameController->setState(std::make_unique<FinishedState>());
    }
}