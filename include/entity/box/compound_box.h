#pragma once
#include "entity/box/box.h"
#include "entity/drawable.h"
#include "colors.h"
#include <vector>
#include "entity/collidable.h"
#include "entity/reflectable.h"


namespace bf
{
    class CompoundBox : public Drawable, public Collidable, public Reflectable
    {
    public:
        CompoundBox() = default;
        ~CompoundBox() = default;

        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;

        CompoundBox& addBox(const Box& box, const glm::vec2& offset = {0, 0});

        bool collides(const Collidable* other) const override;
        bool collidesWithBox(const Box* box) const override;
        bool collidesWithCompoundBox(const CompoundBox* compoundBox) const override;

        /** 
         * @brief Set the new center of the compound box.
         * @param newPosition The new position of the compound box.
         */
        CompoundBox& setPosition(const glm::vec2& newPosition);

        const std::vector<Box>& getBoxes() const;

        void reflectOverYAxis() override;
        void reflectOverYAxis(const float xPosition) override;

    private:
        glm::vec2 mPosition = {0, 0};
        std::vector<Box> mBoxes;
        std::vector<glm::vec2> mOffsets;
    };
}