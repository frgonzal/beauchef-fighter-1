#pragma once
#include "entity/drawable.h"
#include "entity/collidable.h"
#include "entity/reflectable.h"
#include "colors.h"
#include <nothofagus.h>


namespace bf
{
    /** 
     * @brief Class representing a box in the game.
     * This class is used to create and manage a box that can be drawn on the canvas.
     */
    class Box : public Drawable, public Collidable, public Reflectable
    {
    public:
        /** 
         * @brief Constructor for Box class.
         * @param position The position of the box in the canvas.
         * @param width The width of the box.
         * @param height The height of the box.
         */
        Box() = default;
        ~Box() = default;
        Box(float width, float height);

        void addToCanvas(Nothofagus::Canvas &canvas) override;
        void update(Nothofagus::Canvas &canvas, float deltaTime) override;
        
        void setPosition(const glm::vec2 &position) override;
        void setDimensions(float width, float height);

        bool collides(const Collidable *other) const override;
        bool collidesWithBox(const Box *box) const override;

        void setColor(const Color color) override;

        Nothofagus::Texture getTexture() const;
        Nothofagus::Bellota getBellota(Nothofagus::TextureId) const;

        /** 
         * @brief Returns the center of the box.
         * @return The center of the box as a glm::vec2 object.
         */
        glm::vec2 center() const;

        /** 
         * @brief Returns the current position of the box.
         * @return The current position of the box as a glm::vec2 object.
         */
        inline glm::vec2 position() const { return center(); }

        float width() const { return mTopRight.x - mBottomLeft.x; }
        float height() const { return mTopRight.y - mBottomLeft.y; }

        const glm::vec2& bottomLeft() const { return mBottomLeft; }
        const glm::vec2& topRight() const { return mTopRight; }

        void reflectOverYAxis() override {/* Do nothign */;}

    private: 
        glm::vec2 mBottomLeft = {0, 0};
        glm::vec2 mTopRight = {0, 0};

        Nothofagus::TextureId mTextureId;
        Nothofagus::BellotaId mBellotaId;

        bool mHasBellota = false;

        Color mColor = Color::WHITE;

        bool mEnabled = true;
    };
}