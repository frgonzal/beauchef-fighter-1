#pragma once
#include "entity/box/box.h"
#include "entity/drawable.h"
#include "colors.h"
#include <vector>
#include "entity/collidable.h"
#include "entity/reflectable.h"
#include <unordered_map>
#include "entity/actions/action.h"
#include "entity/actions/has_actions.h"
#include "entity/sprite/sprite.h"


namespace bf
{
    class CompoundSprite : public Drawable, public Collidable, public Reflectable, public HasActions
    {
    public:
        CompoundSprite() = default;
        ~CompoundSprite() = default;

        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;

        CompoundSprite& addSprite(Action action, Sprite &&sprite, const glm::vec2& offset);
        CompoundSprite& addBoxToSprite(Action action, Box &&box, const glm::vec2& offset);

        // Prevent copying
        CompoundSprite(const CompoundSprite&) = delete;
        CompoundSprite& operator=(const CompoundSprite&) = delete;

        // Allow moving (optional but good practice)
        CompoundSprite(CompoundSprite&&) noexcept = default;
        CompoundSprite& operator=(CompoundSprite&&) noexcept = default;

        bool collides(const Collidable* other) const override;
        bool collidesWithBox(const Box* box) const override;

        /** 
         * @brief Set the new center of the compound box.
         * @param newPosition The new position of the compound box.
         */
        void setPosition(const glm::vec2& newPosition) override;

        void reflectOverYAxis() override;

        /** 
         * @brief Set the color of the compound box.
         * @param color The new color of the compound box.
         */
        void setColor(const Color color) override;

        void setDefaultAction(Action action);
        void startAction(Action action);
        void stopAction();

        const Sprite& activeSprite() const { return mSprites.at(mActiveAction); }
        Sprite& activeSprite() { return mSprites.at(mActiveAction); }

    private:
        std::unordered_map<Action, Sprite> mSprites;
        Action mActiveAction = Action::STATIC;
        Action mDefaultAction = Action::STATIC;
    };
}