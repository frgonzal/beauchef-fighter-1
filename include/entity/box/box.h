#pragma once
#include "entity/drawable.h"
#include <nothofagus.h>
#include "colors.h"
#include "entity/collidable.h"
#include "entity/reflectable.h"
#include "ibox.h"
#include "ibox.h"
#include "colors.h"


namespace bf
{
    /** 
     * @brief Class representing a box in the game.
     * This class is used to create and manage a box that can be drawn on the canvas.
     */
    class Box : public IBox
    {
    public:
        /** 
         * @brief Constructor for Box class.
         * @param position The position of the box in the canvas.
         * @param width The width of the box.
         * @param height The height of the box.
         */
        Box(const glm::vec2 &position, float width, float height);
        Box() = default;
        ~Box() = default;

        void addToCanvas(Nothofagus::Canvas &canvas) override;
        void update(Nothofagus::Canvas &canvas, float deltaTime) override;
        
        void setPosition(const glm::vec2 &position);

        bool collides(const Collidable *other) const override;
        bool collidesWithBox(const Box *box) const override;
        bool collidesWithCompoundBox(const CompoundBox *compoundBox) const override;

        void setColor(const Color &color) override;

        Nothofagus::Texture getTexture() const;
        Nothofagus::Bellota getBellota(Nothofagus::TextureId) const;

        glm::vec2 getCenter() const;
        glm::vec2 getWidth() const;
        glm::vec2 getHeight() const;
        glm::vec2 bottomLeft() const;
        glm::vec2 topRight() const;

        void reflectOverYAxis() override;
        void reflectOverYAxis(const float xPosition) override;


        void playAnimation() override;
        void stopAnimation() override;

        void addAnimation(glm::vec2 offset, float width, float height);

    private: 
        glm::vec2 mBottomLeft;
        glm::vec2 mTopRight;
        Nothofagus::TextureId mTextureId;
        Nothofagus::BellotaId mBellotaId;
        glm::vec4 mColor = Colors::white;

        glm::vec2 mCurrentOffset = {0, 0};
        glm::vec2 mStaticDimension;
        std::vector<std::tuple<glm::vec2, float, float>> mAnimations;
    };
}