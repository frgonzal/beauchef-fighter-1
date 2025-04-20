#include "entity/sprite/sprite.h"
#include "entity/box/box.h"
#include "entity/collidable.h"
#include <nothofagus.h>
#include <algorithm>
#include <memory>


namespace bf
{
    Sprite& Sprite::addBox(std::unique_ptr<Box> box, const glm::vec2& offset)
    {
        float width = box->width();
        float height = box->height();
        mBoxes.emplace_back(std::move(box), offset, width, height);
        return *this;
    }

    void Sprite::enable()
    {
        for (auto& [box, _, __, ___] : mBoxes)
        {
            box->enable();
        }
        Drawable::enable();
    }

    void Sprite::disable()
    {
        for (auto& [box, _, __, ___] : mBoxes)
        {
            box->disable();
        }
        Drawable::disable();
    }

    void Sprite::addToCanvas(Nothofagus::Canvas& canvas)
    {
        for (auto& [box, offset, _, __] : mBoxes)
        {
            box->addToCanvas(canvas);
        }
    }

    void Sprite::update(Nothofagus::Canvas& canvas, float deltaTime)
    {
        for (auto& [box, offset, _, __] : mBoxes)
        {
            box->update(canvas, deltaTime);
        }
    }

    void Sprite::setPosition(const glm::vec2& position)
    {
        for (auto& [box, offset, _, __] : mBoxes)
        {
            box->setPosition(position + offset);
        }
    }

    bool Sprite::collides(const Collidable* other) const
    {
        if (!isEnabled()) return false;
        return std::any_of(mBoxes.begin(), mBoxes.end(), [other](const std::tuple<std::unique_ptr<Box>, glm::vec2, float, float>& data) {
            const auto& [box, _, __, ___] = data;
            return other->collidesWithBox(box.get());
        });
    }

    bool Sprite::collidesWithBox(const Box* other) const
    {
        if (!isEnabled()) return false;
        return std::any_of(mBoxes.begin(), mBoxes.end(), [other](const std::tuple<std::unique_ptr<Box>, glm::vec2, float, float>& data) {
            const auto& [box, _, __, ___] = data;
            return box->collidesWithBox(other);
        });
    }

    void Sprite::reflectOverYAxis()
    {
        orientation() = (orientation() == LEFT) ? RIGHT : LEFT;
        for (auto& [box, offset, _, __] : mBoxes)
        {
            offset = {-offset.x, offset.y};
            box->reflectOverYAxis();
        }
    }

    void Sprite::setColor(const Color color)
    {
        for (auto& [box, _, __, ___] : mBoxes)
        {
            box->setColor(color);
        }
    }
}