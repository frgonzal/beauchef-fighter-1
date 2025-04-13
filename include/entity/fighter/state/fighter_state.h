#pragma once
#include <nothofagus.h>


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
         * @brief Constructor for FighterState class.
         * @param prevState Pointer to the previous state of the fighter.
         */
        FighterState(const FighterState* prevState);

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
        virtual void attack() = 0;

        /** 
         * @brief Add velocity to the fighter.
         * @param velocity The velocity to add.
         */
        virtual void addVelocity(const glm::vec2 &velocity) = 0;

        /** 
         * @brief Get the velocity of the fighter.
         * @return Reference to the velocity vector.
         */
        glm::vec2 &velocity();

        /** 
         * @brief Get the position of the fighter.
         * @return Reference to the position vector.
         */
        glm::vec2 &position();

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

    protected:
        /** Pointer to the fighter associated with this state. */
        Fighter* mFighter;

        /** Velocity of the fighter. */
        glm::vec2 mVelocity;

        /** Position of the fighter. */
        glm::vec2 mPosition;
    };
}