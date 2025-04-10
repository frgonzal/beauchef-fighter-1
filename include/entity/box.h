#pragma once
#include "entity/drawable.h"
#include <nothofagus.h>
#include "colors.h"


namespace bf
{
    /** 
     * @brief Class representing a box in the game.
     * This class is used to create and manage a box that can be drawn on the canvas.
     */
    class Box : public Drawable
    {
    public:
        /** 
         * @brief Constructor for Box class.
         * @param position The position of the box in the canvas.
         * @param width The width of the box.
         * @param height The height of the box.
         */
        Box(const glm::vec2 &position, float width, float height);
        ~Box() = default;

        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;
        

        Box& setPosition(const glm::vec2& position);
        Box& operator+=(const glm::vec2 &point);

        bool collides(const Box &other) const;
        bool collides(const std::vector<Box> &points) const;
        Box& setAngle(float angle);
        Box& setColor(const glm::vec4& color);

        Nothofagus::Texture getTexture() const;
        Nothofagus::Bellota getBellota(Nothofagus::TextureId) const;

        glm::vec2 getCenter() const;
        glm::vec2 getWidth() const;
        glm::vec2 getHeight() const;
        glm::vec2 getBottomLeft() const;
        glm::vec2 getTopRight() const;

    private: 
        glm::vec2 mBottomLeft;
        glm::vec2 mTopRight;
        float mAngle = 0.0f;
        Nothofagus::TextureId mTextureId;
        Nothofagus::BellotaId mBellotaId;
        glm::vec4 mColor = Colors::white;
    };
}