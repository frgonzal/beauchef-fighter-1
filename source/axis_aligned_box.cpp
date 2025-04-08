#include <iostream>
#include <algorithm>
#include "axis_aligned_box.h"
#include <nothofagus.h>
#include <iostream>



namespace bf
{
    AxisAlignedBox::AxisAlignedBox(const std::vector<glm::vec2> &points)
    {
        for (const auto &point : points) enclose(point);
        std::cout << "AxisAlignedBox initialized with points: " << *this << std::endl;
    }

    AxisAlignedBox& AxisAlignedBox::operator=(const AxisAlignedBox &other)
    {
        if (this != &other)
        {
            mBottomLeft = other.mBottomLeft;
            mTopRight = other.mTopRight;
            initialized = other.initialized;
        }
        return *this;
    }

    AxisAlignedBox& AxisAlignedBox::operator=(const AxisAlignedBox &&other)
    {
        if (this != &other)
        {
            mBottomLeft = other.mBottomLeft;
            mTopRight = other.mTopRight;
            initialized = other.initialized;
        }
        return *this;
    }

    AxisAlignedBox& AxisAlignedBox::enclose(const glm::vec2 &point)
    {
        std::cout << "Enclosing point: " << point.x << ", " << point.y << std::endl;
        if (!initialized)
        {
            mBottomLeft = mTopRight = point;
            initialized = true;
            return *this;
        }
        std::cout << "Enclosing point: " << point.x << ", " << point.y << std::endl;

        float newXMin = std::min(mBottomLeft.x, point.x);
        float newYMin = std::min(mBottomLeft.y, point.y);
        mBottomLeft = {newXMin, newYMin};

        float newXMax = std::max(mTopRight.x, point.x);
        float newYMax = std::max(mTopRight.y, point.y);
        mTopRight = {newXMax, newYMax};

        std::cout << "New bottom left: " << mBottomLeft.x << ", " << mBottomLeft.y << std::endl;
        std::cout << "New top right: " << mTopRight.x << ", " << mTopRight.y << std::endl;
        return *this;
    }

    bool AxisAlignedBox::collides(const AxisAlignedBox &other) const
    {
        return mBottomLeft.x < other.mTopRight.x &&
               mTopRight.x > other.mBottomLeft.x &&
               mBottomLeft.y < other.mTopRight.y &&
               mTopRight.y > other.mBottomLeft.y;
    }

    AxisAlignedBox& AxisAlignedBox::operator+=(const glm::vec2 &point)
    {
        mBottomLeft += point;
        mTopRight += point;
        return *this;
    }

    glm::vec2 AxisAlignedBox::getBottomLeft() const
    {
        return mBottomLeft;
    }

    glm::vec2 AxisAlignedBox::getTopRight() const
    {
        return mTopRight;
    }

    std::ostream& operator<<(std::ostream &os, const AxisAlignedBox &box)
    {
        return os << std::format("[({:.2f}, {:.2f}), ({:.2f}, {:.2f})]",
            box.mBottomLeft.x, box.mBottomLeft.y, box.mTopRight.x, box.mTopRight.y);
    }

    glm::vec2 AxisAlignedBox::getCenter() const
    {
        return {(mBottomLeft.x + mTopRight.x) / 2, (mBottomLeft.y + mTopRight.y) / 2};
    }

    bool AxisAlignedBox::encloses(const glm::vec2 &point) const
    {
        return point.x >= mBottomLeft.x && point.x <= mTopRight.x &&
               point.y >= mBottomLeft.y && point.y <= mTopRight.y;
    }
}