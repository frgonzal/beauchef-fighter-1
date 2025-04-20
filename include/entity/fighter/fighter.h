#pragma once
#include <memory>
#include <nothofagus.h>
#include "entity/drawable.h"
#include "entity/box/box.h"
#include "colors.h"
#include "entity/fighter/state/fighter_state.h"
#include "entity/fighter/fighter_keys.h"
#include <rusty_audio.h>
#include <vector>
#include "entity/compound_sprite.h"
#include "entity/actions/has_actions.h"
#include <string>


namespace bf
{
    class Fighter : public Drawable, public Collidable, public Reflectable, public HasActions
    {
    public:
        Fighter(std::string &&name);
        ~Fighter() = default;

        /**
         * @brief Manage the fighter's state and its transitions.
         * @param newState The new state to set for the fighter.
         */
        void setState(std::unique_ptr<FighterState> newState);

        // Drawable interface
        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;
        void setPosition(const glm::vec2& position) override;
        void setColor(const Color color) override;

        // Reflectable interface
        void reflectOverYAxis() override;

        // HasActions interface
        void setDefaultAction(Action action) override;
        void startAction(Action action) override;
        void stopAction() override;

        bool collides(const Collidable* other) const override;
        bool collidesWithBox(const Box* box) const override;

        Fighter& registerActions(Nothofagus::Controller &controller, FighterControls controls);

        void moveInsideLimits(const glm::vec2& bottomLeftLimit, const glm::vec2& topRightLimit);

        const FighterState &currentState() const { return *mCurrentState; }

        void addVelocity(const glm::vec2& velocity) { mCurrentState->addVelocity(velocity); }

        void setTarget(Fighter* target);
        Fighter& target();
        const Fighter& target() const { return target(); }

        void updateViewDirection();
        glm::vec2 viewDirection();

        // State info
        bool isStanding() const { return mCurrentState->isStanding(); }
        bool isMoving() const { return mCurrentState->isMoving(); }
        bool isAttacking() const { return mCurrentState->isAttacking(); }

        void playStepSound();
        void playAttackSound();
        void playBlockSound();

        const float &health() const { return mHealth; }
        void setHealth(float health);
        bool isAlive() const { return mHealth > 0.0f; }

        const Sprite& attackBoxes() const { return mCurrentState->attackBoxes(); }

        Sprite& mainBody() { return mMainBody.activeSprite(); }
        Sprite& leftLeg() { return mLeftLeg.activeSprite(); }
        Sprite& rightLeg() { return mRightLeg.activeSprite(); }
        Sprite& leftArm() { return mLeftArm.activeSprite(); }
        Sprite& rightArm() { return mRightArm.activeSprite(); }

        void receiveAttack(const Fighter& attaker) { mCurrentState->receiveAttack(&attaker); }

        const std::string &name() const { return mName; }

        glm::vec2 &velocity() { return mVelocity; }
        const glm::vec2 &velocity() const { return mVelocity; }

        const glm::vec2 &position() const { return mPosition; }

        inline float maxSpeed() const { return 1 / 200.f; }
        inline float maxHealth() const { return 100.f; }
        inline float attackPower() const { return 20.f; }
        inline float defensePower() const { return 15.f; }

    private:
        std::string mName;
        float mHealth = 100.0f;

        glm::vec2 mPosition = {0, 0};
        glm::vec2 mVelocity = {0, 0};

        Color mColor = Color::WHITE;
        std::unique_ptr<FighterState> mCurrentState;

        Fighter *mTarget = nullptr;

        CompoundSprite mMainBody;
        CompoundSprite mLeftLeg;
        CompoundSprite mRightLeg;
        CompoundSprite mLeftArm;
        CompoundSprite mRightArm;

        std::vector<std::tuple<CompoundSprite*, glm::vec2>> mBody = {
            {&mLeftArm,  { 2, 16}},
            {&mRightArm, {-1, 16}},
            {&mMainBody, { 0, 9}},
            {&mLeftLeg,  { 1, 0}},
            {&mRightLeg, {-1, 0}}
        };

        std::vector<RustyAudio::Buffer> mAttackSoundBuffers;
        std::vector<std::unique_ptr<RustyAudio::Player>> mAttackSoundPlayers;

        std::vector<RustyAudio::Buffer> mStepSoundBuffers;
        std::vector<std::unique_ptr<RustyAudio::Player>> mStepSoundPlayers;

        RustyAudio::Buffer mBlockSoundBuffer;
        RustyAudio::Player mBlockSoundPlayer;

        void initSoundPlayer();
        void initBody();
    };
}