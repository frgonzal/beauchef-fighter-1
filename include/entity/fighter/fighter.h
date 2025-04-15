#pragma once
#include <memory>
#include <nothofagus.h>
#include "entity/drawable.h"
#include "entity/box/ibox.h"
#include "entity/box/box.h"
#include "entity/box/compound_box.h"
#include "colors.h"
#include "entity/fighter/state/fighter_state.h"
#include "entity/fighter/fighter_keys.h"
#include <rusty_audio.h>
#include <vector>


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

        void moveInsideLimits(const glm::vec2& bottomLeftLimit, const glm::vec2& topRightLimit);

        const glm::vec2& position() const;

        const FighterState *currentState() const;

        void addVelocity(const glm::vec2& velocity);

        void setTarget(Fighter* target);

        Fighter* target();

        glm::vec2 &viewDirection();

        void updateTargetDirection();

        IBox **legs();


        void playStepSound();

    private:
        float mMaxSpeed = 1.0f / 32.0f;
        glm::vec4 mColor = Colors::cyan;
        std::unique_ptr<FighterState> mCurrentState;

        Fighter *mTarget = nullptr;
        glm::vec2 mViewDirection = {1, 0};

        CompoundBox mMainBody;

        CompoundBox mLeftLeg;
        CompoundBox mRightLeg;
        IBox* mLegs[2] = {&mLeftLeg, &mRightLeg};

        CompoundBox mLeftArm;
        CompoundBox mRightArm;

        std::vector<std::tuple<IBox*, glm::vec2>> mBody;

        RustyAudio::Buffer attackSoundBuffer;
        RustyAudio::Player attackSoundPlayer;

        RustyAudio::Buffer stepSoundBuffer;
        RustyAudio::Player stepSoundPlayer;

        void initSoundPlayer();
    };
}