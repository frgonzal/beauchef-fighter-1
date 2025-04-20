#pragma once
#include <memory>
#include <vector>
#include <nothofagus.h>
#include "entity/box/box.h"


namespace bf
{
    class Sprite : public Drawable, public Collidable, public Reflectable
    {
    public:
        Sprite() = default;
        ~Sprite() = default;

        // Prevent copying
        Sprite(const Sprite&) = delete;
        Sprite& operator=(const Sprite&) = delete;

        // Allow moving (optional but good practice)
        Sprite(Sprite&&) noexcept = default;
        Sprite& operator=(Sprite&&) noexcept = default;

        Sprite& addBox(std::unique_ptr<Box> box, const glm::vec2& offset = {0, 0});

        // Drawable interface
        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;
        void setPosition(const glm::vec2& position) override;
        void setColor(const Color color) override;
        void enable() override;
        void disable() override;

        // Collidable interface
        bool collides(const Collidable* other) const override;
        bool collidesWithBox(const Box* box) const override;

        // Reflectable interface
        void reflectOverYAxis() override;

    private:
        /**
         * @brief List of boxes with their offsets and dimensions.
         * Each box is represented as a tuple containing a unique pointer to the Box object,
         * its offset, width, and height.
         */
        std::vector<std::tuple<std::unique_ptr<Box>, glm::vec2, float, float>> mBoxes;
    };
}