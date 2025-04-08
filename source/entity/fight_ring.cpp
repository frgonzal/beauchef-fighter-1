#include "entity/fight_ring.hpp"
#include <nothofagus.h>
#include <colors.hpp>
#include <iostream>
#include <format>



namespace bf
{
    static constexpr int textureWidth = 1;
    static constexpr int textureHeight = 1;

    Nothofagus::Bellota FightRing::getBellota(Nothofagus::TextureId textureId) const
    {
        Nothofagus::Bellota bellota = Nothofagus::Bellota(
            Nothofagus::Transform(mBox.getCenter(), 1.0f),
            textureId
        );
        bellota.transform().scale() = {mWidth / textureWidth, mHeight / textureHeight};
        std::cout << "Bellota transform: " << std::format("({:.2f}, {:.2f})", bellota.transform().scale().x, bellota.transform().scale().y) << std::endl;
        return bellota;
    }

    Nothofagus::Texture FightRing::getTexture() const
    {
        const Nothofagus::ColorPallete colorPallete = {
            Colors::yellow,
            Colors::brown,
        };

        Nothofagus::Texture texture({textureWidth, textureHeight}, Colors::white);
        texture.setPallete(colorPallete).setPixels({0});
        return texture;
    }

    FightRing& FightRing::setPosition(const glm::vec2& position)
    {
        glm::vec2 halfSize = {mWidth / 2.0f, mHeight / 2.0f};
        glm::vec2 bottomLeft = position - halfSize;
        glm::vec2 topRight = position + halfSize;
        mBox = AxisAlignedBox({bottomLeft, topRight});
        std::cout << "set position" << std::endl;
        std::cout << "FightRing dimensions: " << std::format("({:.2f}, {:.2f})", mWidth, mHeight) << std::endl;
        std::cout << "FightRing position: " << std::format("({:.2f}, {:.2f})", position.x, position.y) << std::endl;
        return *this;
    }

    FightRing& FightRing::setDimensions(float width, float height)
    {
        mWidth = width;
        mHeight = height;
        glm::vec2 center;
        glm::vec2 halfSize = {mWidth / 2.0f, mHeight / 2.0f};
        glm::vec2 bottomLeft = center - halfSize;
        glm::vec2 topRight = center + halfSize;
        mBox = AxisAlignedBox({bottomLeft, topRight});
        std::cout << "set dimensions" << std::endl;
        std::cout << "FightRing dimensions: " << std::format("({:.2f}, {:.2f})", mWidth, mHeight) << std::endl;
        std::cout << "FightRing position: " << std::format("({:.2f}, {:.2f})", center.x, center.y) << std::endl;
        return *this;
    }
}