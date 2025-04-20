#include "entity/fighter/fighter.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include <iostream>
#include "colors.h"
#include <nothofagus.h>
#include <rusty_audio.h>
#include <algorithm>
#include "entity/actions/action.h"


namespace bf
{
    Fighter::Fighter(std::string &&name) : mName(name)
    {
        orientation() = RIGHT;
        initBody();

        for (auto &[sprite, _] : mBody)
        {
            sprite->setDefaultAction(Action::STAND);
            sprite->setColor(mColor);
        }

        initSoundPlayer();    
        setState(std::make_unique<FighterStandingState>());
    }

    void Fighter::setState(std::unique_ptr<FighterState> newState)
    {
        mCurrentState = std::move(newState);
        mCurrentState->setFighter(this);
    }


    void Fighter::addToCanvas(Nothofagus::Canvas& canvas)
    {
        for(auto& [box, _] : mBody)
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
        mPosition = newPosition;
        for(auto& [compSprite, offset] : mBody)
        {
            compSprite->setPosition(position() + offset);
        }
    }

    void Fighter::setColor(const Color color)
    {
        mColor = color;
        for (auto& [compoundBox, _] : mBody)
        {
            compoundBox->setColor(color);
        }
    }


    void Fighter::setHealth(float health)
    {
        mHealth = std::clamp(health, 0.0f, maxHealth());
    }


    void Fighter::moveInsideLimits(const glm::vec2& bottomLeftLimit, const glm::vec2& topRightLimit)
    {
        float x = std::clamp(position().x, bottomLeftLimit.x, topRightLimit.x);
        float y = std::clamp(position().y, bottomLeftLimit.y, topRightLimit.y);
        setPosition({x, y});
    }

    void Fighter::setTarget(Fighter* target)
    {
        mTarget = target;
    }

    void Fighter::reflectOverYAxis()
    {
        for (auto& [box, offset] : mBody)
        {
            box->reflectOverYAxis();
            offset = {-offset.x, offset.y};
        }
    }

    glm::vec2 Fighter::viewDirection()
    {
        return (orientation() == LEFT) ? glm::vec2{-1, 0} : glm::vec2{1, 0};
    }

    void Fighter::updateViewDirection()
    {
        if (mTarget == nullptr)
        {
            std::cout << "(Warning) Fighter::updateTargetDirection: Target is null." << std::endl;
            return;
        }
        Orientation newOrientation = (target().position().x < position().x) ? LEFT : RIGHT;
        if (newOrientation != orientation())
        {
            reflectOverYAxis();
            orientation() = newOrientation;
        }
    }

    Fighter &Fighter::target()
    {
        if (mTarget == nullptr)
        {
            throw std::runtime_error("Fighter error: Target has not been set.");
        }
        return *mTarget;
    }

    bool Fighter::collides(const Collidable *other) const
    {
        if (!isEnabled()) return false;
        return std::any_of(mBody.begin(), mBody.end(), [other](const std::tuple<CompoundSprite*, glm::vec2>& bodyPart) {
            const auto &[compoundSprite, _] = bodyPart;
            return compoundSprite->collides(other);
        });
    }

    bool Fighter::collidesWithBox(const Box *other) const
    {
        if (!isEnabled()) return false;
        return std::any_of(mBody.begin(), mBody.end(), [other](const std::tuple<CompoundSprite*, glm::vec2>& bodyPart) {
            const auto &[compoundSprite, _] = bodyPart;
            return compoundSprite->collidesWithBox(other);
        });
    }

    void Fighter::setDefaultAction(Action action)
    {
        for (auto& [compoundSprite, _] : mBody)
        {
            compoundSprite->setDefaultAction(action);
        }
    }

    void Fighter::startAction(Action action)
    {
        for (auto& [compoundSprite, _] : mBody)
        {
            compoundSprite->startAction(action);
        }
    }

    void Fighter::stopAction()
    {
        for (auto& [compoundSprite, _] : mBody)
        {
            compoundSprite->stopAction();
        }
    }

    Fighter& Fighter::registerActions(Nothofagus::Controller &controller, FighterControls controls)
    {
        const FighterKeys actionKeys = FighterKeys::getKeys(controls);
        controller.registerAction({actionKeys.moveLeft, Nothofagus::DiscreteTrigger::Press},    [this]() { addVelocity({-maxSpeed(), 0}); });
        controller.registerAction({actionKeys.moveLeft, Nothofagus::DiscreteTrigger::Release},  [this]() { addVelocity({ maxSpeed(), 0}); });
        controller.registerAction({actionKeys.moveRight, Nothofagus::DiscreteTrigger::Press},   [this]() { addVelocity({ maxSpeed(), 0}); });
        controller.registerAction({actionKeys.moveRight, Nothofagus::DiscreteTrigger::Release}, [this]() { addVelocity({-maxSpeed(), 0}); });

        controller.registerAction({actionKeys.moveUp, Nothofagus::DiscreteTrigger::Press},     [this]() { addVelocity({0,  maxSpeed()}); });
        controller.registerAction({actionKeys.moveUp, Nothofagus::DiscreteTrigger::Release},   [this]() { addVelocity({0, -maxSpeed()}); });
        controller.registerAction({actionKeys.moveDown, Nothofagus::DiscreteTrigger::Press},   [this]() { addVelocity({0, -maxSpeed()}); });
        controller.registerAction({actionKeys.moveDown, Nothofagus::DiscreteTrigger::Release}, [this]() { addVelocity({0,  maxSpeed()}); });

        controller.registerAction({actionKeys.punch, Nothofagus::DiscreteTrigger::Press}, [this]() { mCurrentState->attack(Action::LEFT_ARM_ATTACK); });
        controller.registerAction({actionKeys.kick,  Nothofagus::DiscreteTrigger::Press}, [this]() { mCurrentState->attack(Action::LEFT_LEG_ATTACK); });

        controller.registerAction({actionKeys.block, Nothofagus::DiscreteTrigger::Press},   [this]() { mCurrentState->startToBlock(); });
        controller.registerAction({actionKeys.block, Nothofagus::DiscreteTrigger::Release}, [this]() { mCurrentState->stopToBlock(); });

        // controller.registerAction({Nothofagus::Key::SPACE, Nothofagus::DiscreteTrigger::Press}, [this]() { attackSoundPlayer.play(); });

        return *this;
    }
}