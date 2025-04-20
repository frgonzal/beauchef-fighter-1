#include "entity/compound_sprite.h" 
#include "entity/box/box.h"        
#include "entity/collidable.h"     
#include <nothofagus.h>            
#include <stdexcept>               
#include <glm/glm.hpp>              


namespace bf
{
    void CompoundSprite::addToCanvas(Nothofagus::Canvas& canvas)
    {
        for (auto& [action, sprite] : mSprites)
        {
            if (action == mActiveAction)
            {
                sprite.enable();
            }
            else
            {
                sprite.disable();
            }
            sprite.addToCanvas(canvas);
        }
    }

    void CompoundSprite::update(Nothofagus::Canvas& canvas, float deltaTime)
    {
        for(auto& [action, sprite] : mSprites)
        {
            sprite.update(canvas, deltaTime);
        }
        
    }

    CompoundSprite& CompoundSprite::addSprite(Action action, Sprite &&sprite, const glm::vec2& offset)
    {
        mSprites[action] = std::move(sprite);
        return *this;
    }

    CompoundSprite& CompoundSprite::addBoxToSprite(Action action, Box &&box, const glm::vec2& offset)
    {
        mSprites[action].addBox(std::make_unique<Box>(box), offset);
        return *this;
    }

    bool CompoundSprite::collides(const Collidable* other) const
    {
        const Sprite &sprite = mSprites.at(mActiveAction);
        return sprite.collides(other);
    }

    bool CompoundSprite::collidesWithBox(const Box* box) const
    {
        const Sprite &sprite = mSprites.at(mActiveAction);
        return sprite.collidesWithBox(box);
    }

    void CompoundSprite::setPosition(const glm::vec2& newPosition)
    {
        mSprites[mActiveAction].setPosition(newPosition);
    }

    void CompoundSprite::reflectOverYAxis()
    {
        orientation() = (orientation() == LEFT) ? RIGHT : LEFT;
        Sprite &sprite = mSprites[mActiveAction];
        if (sprite.orientation() != orientation())
        {
            sprite.reflectOverYAxis();
        }
    }

    void CompoundSprite::setColor(const Color color)
    {
        for (auto& [_, sprite] : mSprites)
        {
            sprite.setColor(color);
        }
    }

    void CompoundSprite::setDefaultAction(Action action)
    {
        mDefaultAction = action;
        mActiveAction = action;
    }

    void CompoundSprite::startAction(Action action)
    {
        if (mActiveAction == action) return;
        mSprites[mActiveAction].disable();

        if (mSprites.find(action) == mSprites.end())
        {
            mActiveAction = mDefaultAction;
        }
        else
        {
            mActiveAction = action;
        }
        Sprite &sprite = mSprites[mActiveAction];
        sprite.enable();
        if (orientation() != sprite.orientation())
        {
            sprite.reflectOverYAxis();
        }
    }

    void CompoundSprite::stopAction()
    {
        if (mActiveAction == mDefaultAction) return;
    
        mSprites[mActiveAction].disable();
        mActiveAction = mDefaultAction;
        mSprites[mActiveAction].enable();
    }

}