#include "entity/box/box.h"
#include <nothofagus.h>
#include <colors.h>
#include <iostream>
#include <format>
#include "entity/collidable.h"
#include "entity/box/compound_box.h"



namespace bf
{
    Box::Box(const glm::vec2 &position, float width, float height)
    {
        glm::vec2 halfSize = {width / 2.0f, height / 2.0f};
        mBottomLeft = position - halfSize;
        mTopRight = position + halfSize;
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
        bellota.transform().location() = getCenter();
    }


    Nothofagus::Bellota Box::getBellota(Nothofagus::TextureId textureId) const
    {
        Nothofagus::Bellota bellota = Nothofagus::Bellota(
            Nothofagus::Transform(getCenter(), 1.0f),
            textureId
        );
        bellota.transform().scale() = mTopRight - mBottomLeft;
        return bellota;
    }

    Nothofagus::Texture Box::getTexture() const
    {
        return Nothofagus::Texture({1, 1}, mColor);
    }

    Box& Box::setPosition(const glm::vec2& center)
    {
        glm::vec2 halfSize = getCenter() - mBottomLeft;
        mBottomLeft = center - halfSize;
        mTopRight = center + halfSize;
        return *this;
    }


    glm::vec2 Box::getCenter() const
    {
        return (mBottomLeft + mTopRight) / 2.0f;
    }

    Box& Box::operator+=(const glm::vec2 &point)
    {
        mBottomLeft += point;
        mTopRight += point;
        return *this;
    }

    bool Box::collides(const Collidable *other) const
    {
        return other->collidesWithBox(this);
    }

    bool Box::collidesWithBox(const Box *other) const
    {
        return mBottomLeft.x < other->mTopRight.x &&
               mTopRight.x > other->mBottomLeft.x &&
               mBottomLeft.y < other->mTopRight.y &&
               mTopRight.y > other->mBottomLeft.y;
    }

    bool Box::collidesWithCompoundBox(const CompoundBox *compoundBox) const
    {
        for (const Box &other : compoundBox->getBoxes())
        {
            if (other.collidesWithBox(this))
            {
                return true;
            }
        }
        return false;
    }

    glm::vec2 Box::getWidth() const
    {
        return mTopRight - mBottomLeft;
    }

    glm::vec2 Box::getHeight() const
    {
        return mTopRight - mBottomLeft;
    }

    glm::vec2 Box::getBottomLeft() const
    {
        return mBottomLeft;
    }

    glm::vec2 Box::getTopRight() const
    {
        return mTopRight;
    }

    Box& Box::setColor(const glm::vec4& color)
    {
        mColor = color;
        return *this;
    }

    void Box::reflectOverYAxis()
    {
        // its a box, so no need to reflect over its own axis
    }

    void Box::reflectOverYAxis(const float xPosition)
    {
        float xLeft = mBottomLeft.x;
        mBottomLeft.x = 2 * xPosition - mTopRight.x;
        mTopRight.x = 2 * xPosition - xLeft;
    }
}