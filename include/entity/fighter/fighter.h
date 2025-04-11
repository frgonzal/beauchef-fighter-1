#pragma once
#include <memory>
#include <nothofagus.h>
#include "entity/drawable.h"
#include "entity/box/box.h"
#include "colors.h"
#include "entity/fighter/state/fighter_state.h"
#include "entity/fighter/fighter_keys.h"


namespace bf
{



    class Fighter : public Drawable
    {
    public:
        Fighter();
        ~Fighter() = default;

        void setState(std::unique_ptr<FighterState> newState);

        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;

        void setPosition(const glm::vec2& position);
        Fighter& registerActions(Nothofagus::Controller &controller, FighterControls controls);
        // void setVelocity(const glm::vec2& velocity);
        // void movePosition(const glm::vec2& delta);

    private:
        float mMaxSpeed = 1.0f / 32.0f;
        glm::vec2 mPosition = {0, 0};
        glm::vec2 mVelocity = {0, 0};
        glm::vec4 mColor = Colors::cyan;
        std::unique_ptr<FighterState> mCurrentState;

        Box mHead  = Box({0, 0}, 4.0, 4.0);
        Box mNeck  = Box({0, 0}, 2.0, 3.0);

        Box mChest = Box({0, 0}, 6.0, 15.0);

        Box mLeftLeg = Box({0, 0}, 2.0, 15.0);
        Box mRightLeg = Box({0, 0}, 2.0, 15.0);

        Box mLeftArm = Box({0, 0}, 12.0, 2.0);
        Box mRightArm = Box({0, 0}, 12.0, 2.0);

        std::vector<std::tuple<Box*, glm::vec2>> mBody = {
            {&mHead,  {0, 15 + 7.5 + 1.5 + 2.0}},
            {&mNeck,  {0, 15 + 7.5 + 1.5}},

            {&mLeftArm, {3.0, 15 + 6.0}},
            {&mRightArm, {9.0, 15 + 3.0}},

            {&mChest, {0, 15}},

            {&mLeftLeg, {-1.1, 0}},
            {&mRightLeg, {1.1, 0}}
        };
    };
}