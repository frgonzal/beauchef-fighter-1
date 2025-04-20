#pragma once
#include <nothofagus.h>
#include "entity/actions/action.h"
#include "entity/sprite/sprite.h"


namespace bf
{
    class Fighter;

    class FighterState
    {
    public:
        /** 
         * @brief Constructor for FighterState class.
         * @param prevState Pointer to the previous state of the fighter.
         */
        FighterState() = default;

        /** 
         * @brief Destructor for FighterState class.
         */
        virtual ~FighterState() = default;

        /** 
         * @brief Update the fighter state.
         * @param deltaTime The time elapsed since the last update.
         */
        virtual void update(float deltaTime) = 0;

        /** 
         * @brief Set the fighter associated with this state.
         * @param fighter Pointer to the fighter object.
         */
        void setFighter(Fighter* fighter);

        /** 
         * @brief Get the fighter associated with this state.
         * @return Pointer to the fighter object.
         */
        virtual bool isStanding() const = 0;

        /** 
         * @brief Check if the fighter is moving.
         * @return true if the fighter is moving, false otherwise.
         */
        virtual bool isMoving() const = 0;

        /** 
         * @brief Check if the fighter is attacking.
         * @return true if the fighter is attacking, false otherwise.
         */
        virtual bool isAttacking() const = 0;

        /** 
         * @brief Perform an attack action.
         */
        virtual void attack(Action action) = 0;

        /** 
         * @brief Add velocity to the fighter.
         * @param velocity The velocity to add.
         */
        virtual void addVelocity(const glm::vec2 &velocity);

        /** 
         * @brief Overload the output stream operator for FighterState.
         * @param os The output stream.
         * @param state The FighterState object.
         * @return Reference to the output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, const FighterState& state);

        /** 
         * @brief Convert the FighterState to a string representation.
         * @return String representation of the FighterState.
         */
        std::string toString() const;

        /** 
         * @brief Get the current action of the fighter.
         * @return The current action of the fighter.
         */
        virtual const Action &currentAction() const = 0;

        /** 
         * @brief Get the current action of the fighter (non-const version).
         * @return The current action of the fighter.
         */
        virtual Action &currentAction() = 0;

        /** 
         * @brief get the next action of the fighter.
         * @return The next action of the fighter.
         */
        virtual Action getNextAction() = 0;

        /** 
         * @brief Get the attack boxes of the fighter.
         * @return The attack boxes of the fighter.
         */
        virtual const Sprite &attackBoxes() const = 0;

        /** 
         * @brief Receive an attack from another fighter.
         * @param attacker Pointer to the attacking fighter.
         */
        virtual void receiveAttack(const Fighter* attacker);

        virtual void startToBlock() {}
        virtual void stopToBlock() {}

    protected:
        /** Pointer to the fighter associated with this state. */
        Fighter* mFighter;
    };
}