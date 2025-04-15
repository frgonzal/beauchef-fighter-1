#include "entity/box/box.h"
#include <nothofagus.h>
#include <colors.h>
#include <iostream>
#include <format>
#include "entity/collidable.h"
#include "entity/box/compound_box.h"
#include "colors.h"



namespace bf
{
    Box::Box(const glm::vec2 &position, float width, float height)
    {
        glm::vec2 halfSize = {width / 2.0f, height / 2.0f};
        mBottomLeft = position - halfSize;
        mTopRight = position + halfSize;
        mStaticDimension = {width, height};
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
        bellota.transform().scale() = mTopRight - mBottomLeft;
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

    void Box::setPosition(const glm::vec2& center)
    {
        glm::vec2 halfSize = getCenter() - mBottomLeft;
        mBottomLeft = center - halfSize + mCurrentOffset;
        mTopRight = center + halfSize + mCurrentOffset;
    }


    glm::vec2 Box::getCenter() const
    {
        return (mBottomLeft + mTopRight) / 2.0f;
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

    glm::vec2 Box::bottomLeft() const
    {
        return mBottomLeft;
    }

    glm::vec2 Box::topRight() const
    {
        return mTopRight;
    }

    void Box::setColor(const Color &color)
    {
        mColor = color;
    }

    void Box::reflectOverYAxis()
    {
        for(int i = 0; i < mAnimations.size(); ++i)
        {
            auto [offset, width, height] = mAnimations[i];
            mAnimations[i] = {glm::vec2{-offset.x, offset.y}, width, height};
        }
        mCurrentOffset.x = -mCurrentOffset.x;
    }

    void Box::reflectOverYAxis(const float xPosition)
    {
        float xLeft = mBottomLeft.x;
        mBottomLeft.x = 2 * xPosition - mTopRight.x;
        mTopRight.x = 2 * xPosition - xLeft;

        for(int i = 0; i < mAnimations.size(); ++i)
        {
            auto [offset, width, height] = mAnimations[i];
            mAnimations[i] = {glm::vec2{2 * xPosition - offset.x, offset.y}, width, height};
        }
        mCurrentOffset.x = 2 * xPosition - mCurrentOffset.x;
    }

    void Box::playAnimation()
    {
        std::cout << "Play animation" << std::endl;
        if (mAnimations.empty()) return;
        if (mCurrentOffset != glm::vec2{0, 0}) stopAnimation();

        auto [offset, width, height] = mAnimations.back();
        std::cout << "offset: " << offset.x << ", " << offset.y << std::endl;

        glm::vec2 position = getCenter() + offset;
        mBottomLeft = position - glm::vec2(width / 2.0f, height / 2.0f);
        mTopRight   = position + glm::vec2(width / 2.0f, height / 2.0f);
        std::cout << "mBottomLeft: " << mBottomLeft.x << ", " << mBottomLeft.y << std::endl;
        std::cout << "mTopRight: " << mTopRight.x << ", " << mTopRight.y << std::endl;

        mCurrentOffset = offset;
    }

    void Box::stopAnimation()
    {
        const float width = mStaticDimension.x;
        const float height = mStaticDimension.y;

        const glm::vec2 position = getCenter() - mCurrentOffset;
        mBottomLeft = position - glm::vec2(width / 2.0f, height / 2.0f);
        mTopRight   = position + glm::vec2(width / 2.0f, height / 2.0f);

        mCurrentOffset = {0, 0};
    }

    void Box::addAnimation(glm::vec2 offset, float width, float height)
    {
        mAnimations.push_back({offset, width, height});
    }
}