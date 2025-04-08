#pragma once

#include <nothofagus.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <format>

namespace bf
{
    /** A class representing an axis-aligned bounding box in 2D space. */
    class AxisAlignedBox
    {
    public:
        AxisAlignedBox() = default;
        AxisAlignedBox& enclose(const glm::vec2 &point);
        bool collides(const AxisAlignedBox &other) const;
        bool encloses(const glm::vec2 &point) const;
        AxisAlignedBox& operator+=(const glm::vec2 &point);
        glm::vec2 getBottomLeft() const;
        glm::vec2 getTopRight() const;
        glm::vec2 getCenter() const;

        AxisAlignedBox& operator=(const AxisAlignedBox &other);
        AxisAlignedBox& operator=(const AxisAlignedBox &&other);

        /** Overloads the stream insertion operator to output the representation of an AxisAlignedBox. */
        friend std::ostream& operator<<(std::ostream &os, const AxisAlignedBox &box);

        /**
         * @brief Computes the axis-aligned bounding box that encloses a set of 2D points.
         *
         * @param points A vector of 2D points to be enclosed within the bounding box.
         * @return The smallest axis-aligned bounding box that contains all the given points.
         */
        AxisAlignedBox(const std::vector<glm::vec2> &points);

    private:
        glm::vec2 mBottomLeft, mTopRight;
        bool initialized = false;
    };
}