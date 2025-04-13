#include "entity/fighter/state/fighter_state.h"
#include "entity/fighter/fighter.h"
#include <typeinfo>
#include <ostream>


namespace bf
{
    FighterState::FighterState(const FighterState* prevState) 
    {
        if (prevState)
        {
            mPosition = prevState->mPosition;
            mVelocity = prevState->mVelocity;
        }
    }

    void FighterState::setFighter(Fighter* fighter) 
    {
        mFighter = fighter;
    }

    glm::vec2& FighterState::velocity()
    {
        return mVelocity;
    }

    glm::vec2& FighterState::position() 
    {
        return mPosition;
    }

    std::ostream& operator<<(std::ostream& os, const FighterState& state)
    {
        os << "FighterState: " << typeid(state).name() << "\n";
        return os;
    }

    std::string FighterState::toString() const
    {
        return std::string(typeid(*this).name());
    }

}
