#pragma once
#include "entity/box/box.h"
#include "entity/drawable.h"
#include "colors.h"
#include <vector>


namespace bf
{
    class CompoundBox : public Drawable
    {
    public:
        CompoundBox() = default;
        ~CompoundBox() = default;

        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;

        void addBox(const Box& box, const glm::vec2& offset = {0, 0});
        void AddBoxes(const std::vector<Box>& boxes);

        /** 
         * @brief Set the new center of the compound box.
         * @param newPosition The new position of the compound box.
         */
        void setPosition(const glm::vec2& newPosition);

    private:
        std::vector<std::tuple<Box, glm::vec2>> mBoxes;
    };
}