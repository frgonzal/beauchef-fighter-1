#include "entity/fighter/fighter.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include <iostream>
#include "colors.h"
#include <nothofagus.h>
#include <rusty_audio.h>
#include "audio.h"


namespace bf
{
    Fighter::Fighter()
        : mCurrentState(std::make_unique<FighterStandingState>())
    {
        for(auto& [box, offset] : mBody)
        {
            box->setColor(mColor);
        }

        mCurrentState->setFighter(this);
        initSoundPlayer();    
    }

    void Fighter::setState(std::unique_ptr<FighterState> newState)
    {
        mCurrentState = std::move(newState);
        mCurrentState->setFighter(this);
    }


    void Fighter::addToCanvas(Nothofagus::Canvas& canvas)
    {
        for(auto& [box, offset] : mBody)
        {
            box->addToCanvas(canvas);
        }
    }

    void Fighter::update(Nothofagus::Canvas& canvas, float deltaTime)
    {
        mCurrentState->update(deltaTime);
        for(auto& [box, offset] : mBody)
        {
            box->setPosition(position() + offset);
            box->update(canvas, deltaTime);
        }
    }

    void Fighter::setPosition(const glm::vec2& newPosition)
    {
        mCurrentState->position() = newPosition;
        for(auto& [box, offset] : mBody)
        {
            box->setPosition(position() + offset);
        }
    }


    Fighter& Fighter::registerActions(Nothofagus::Controller &controller, FighterControls controls)
    {
        const FighterKeys actionKeys = FighterKeys::getKeys(controls);
        controller.registerAction({actionKeys.moveLeft, Nothofagus::DiscreteTrigger::Press},    [this]() { addVelocity({-mMaxSpeed, 0}); });
        controller.registerAction({actionKeys.moveLeft, Nothofagus::DiscreteTrigger::Release},  [this]() { addVelocity({ mMaxSpeed, 0}); });
        controller.registerAction({actionKeys.moveRight, Nothofagus::DiscreteTrigger::Press},   [this]() { addVelocity({ mMaxSpeed, 0}); });
        controller.registerAction({actionKeys.moveRight, Nothofagus::DiscreteTrigger::Release}, [this]() { addVelocity({-mMaxSpeed, 0}); });

        controller.registerAction({actionKeys.moveUp, Nothofagus::DiscreteTrigger::Press},     [this]() { addVelocity({0,  mMaxSpeed}); });
        controller.registerAction({actionKeys.moveUp, Nothofagus::DiscreteTrigger::Release},   [this]() { addVelocity({0, -mMaxSpeed}); });
        controller.registerAction({actionKeys.moveDown, Nothofagus::DiscreteTrigger::Press},   [this]() { addVelocity({0, -mMaxSpeed}); });
        controller.registerAction({actionKeys.moveDown, Nothofagus::DiscreteTrigger::Release}, [this]() { addVelocity({0,  mMaxSpeed}); });

        controller.registerAction({Nothofagus::Key::SPACE, Nothofagus::DiscreteTrigger::Press}, [this]() { attackSoundPlayer.play(); });

        return *this;
    }


    void Fighter::moveInsideLimits(const glm::vec2& bottomLeftLimit, const glm::vec2& topRightLimit)
    {
        mCurrentState->position().x = std::clamp(position().x, bottomLeftLimit.x, topRightLimit.x);
        mCurrentState->position().y = std::clamp(position().y, bottomLeftLimit.y, topRightLimit.y);
    }

    void Fighter::initSoundPlayer()
    {
        RustyAudio::Builder attackSoundBuilder;
        attackSoundBuilder.appendSinusoids({
            {8,  1.0, 350.0},    // Ultra-short, intense impact burst
            {20, 0.8, 250.0},    // Main body component for impact resonance
            {40, 0.6, 150.0},    // Mid-range resonant decay
            {60, 0.3, 100.0}     // Low-end tail for a full decay
        });
        attackSoundBuffer = attackSoundBuilder.generate(Audio::sampleRate, Audio::channels);
        attackSoundPlayer.init(attackSoundBuffer);
        attackSoundPlayer.setLooping(false);
    }

    const glm::vec2& Fighter::position() const
    {
        return mCurrentState->position();
    }

    const FighterState *Fighter::currentState() const
    {
        return mCurrentState.get();
    }

    void Fighter::addVelocity(const glm::vec2& velocity)
    {
        mCurrentState->addVelocity(velocity);
    }

    void Fighter::setTarget(Fighter* target)
    {
        mTarget = target;
    }

    Fighter* Fighter::target()
    {
        return mTarget;
    }

    glm::vec2 &Fighter::viewDirection()
    {
        return mViewDirection;
    }

    void Fighter::updateTargetDirection()
    {
        if (target() != nullptr)
        {
            glm::vec2 targetDirection = target()->position() - position();
            if (targetDirection.x * viewDirection().x < 0) // The target is on the opposite side
            {
                viewDirection() = {-1 * viewDirection().x, viewDirection().y};
                for (auto& [box, offset] : mBody)
                {
                    offset = {- offset.x, offset.y};
                    box->reflectOverYAxis();
                }
            }
        }
    }
}