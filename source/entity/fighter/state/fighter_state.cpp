#include "entity/fighter/state/fighter_state.h"
#include "entity/fighter/fighter.h"
#include <typeinfo>
#include <ostream>


namespace bf
{
    void FighterState::setFighter(Fighter* fighter) 
    {
        assert(fighter != nullptr && "FighterState error: Fighter pointer is null.");
        mFighter = fighter;
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

    void FighterState::addVelocity(const glm::vec2 &velocity)
    {
        assert(mFighter != nullptr && "FighterState error: Fighter pointer is null.");
        mFighter->velocity() += velocity;
    }

    void FighterState::receiveAttack(const Fighter* attacker)
    {
        assert(mFighter != nullptr && "FighterState error: Fighter pointer is null.");
        assert(mFighter->collides(&attacker->attackBoxes()) && "FighterState::receiveAttack: Attacker does not collide with fighter's attack boxes.");

        mFighter->setHealth(mFighter->health() - attacker->attackPower());
    }
}
