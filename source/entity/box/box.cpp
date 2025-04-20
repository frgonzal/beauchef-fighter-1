#include "entity/box/box.h"
#include <nothofagus.h>
#include <colors.h>
#include <iostream>
#include <format>
#include "entity/collidable.h"
#include "colors.h"


namespace bf
{
    Box::Box(float width, float height)
    {
        // default position is (0, 0)
        glm::vec2 halfSize = {width / 2.0f, height / 2.0f};
        mBottomLeft = -halfSize;
        mTopRight = halfSize;
    }

    void Box::addToCanvas(Nothofagus::Canvas& canvas)
    {
        Nothofagus::Texture texture = getTexture();
        mTextureId = canvas.addTexture(texture);
        Nothofagus::Bellota bellota = getBellota(mTextureId);
        mBellotaId = canvas.addBellota(bellota);
    }

    void Box::update(Nothofagus::Canvas& canvas, float deltaTime)
    {
        Nothofagus::Bellota &bellota = canvas.bellota(mBellotaId);
        bellota.visible() = isEnabled();
        if (!isEnabled()) return;

        bellota.transform().location() = center();
        bellota.transform().scale() = mTopRight - mBottomLeft;
    }


    Nothofagus::Bellota Box::getBellota(Nothofagus::TextureId textureId) const
    {
        Nothofagus::Bellota bellota = Nothofagus::Bellota(
            Nothofagus::Transform(center(), 1.0f),
            textureId
        );
        bellota.transform().scale() = mTopRight - mBottomLeft;
        return bellota;
    }

    Nothofagus::Texture Box::getTexture() const
    {
        return Nothofagus::Texture({1, 1}, RGB::from(mColor));
    }

    void Box::setPosition(const glm::vec2& newPosition)
    {
        glm::vec2 translation = newPosition - position();
        mBottomLeft += translation;
        mTopRight += translation;
    }


    glm::vec2 Box::center() const
    {
        return (mTopRight - mBottomLeft) / 2.0f + mBottomLeft;
    }

    bool Box::collides(const Collidable *other) const
    {
        if (!isEnabled()) return false;
        return other->collidesWithBox(this);
    }

    bool Box::collidesWithBox(const Box *other) const
    {
        if (!isEnabled()) return false;
        return mBottomLeft.x < other->mTopRight.x &&
               mTopRight.x > other->mBottomLeft.x &&
               mBottomLeft.y < other->mTopRight.y &&
               mTopRight.y > other->mBottomLeft.y;
    }

    void Box::setColor(const Color color)
    {
        mColor = color;
    }

    void Box::setDimensions(float width, float height)
    {
        glm::vec2 halfSize = {width / 2.0f, height / 2.0f};
        glm::vec2 centerPosition = center();
        mBottomLeft = centerPosition - halfSize;
        mTopRight = centerPosition + halfSize;
    }
}