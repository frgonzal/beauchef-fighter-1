#include "entity/point.h"
#include <nothofagus.h>
#include "colors.hpp"



namespace bf
{
    Nothofagus::Bellota Point::getBellota(Nothofagus::TextureId textureId) const
    {
        Nothofagus::Bellota bellota = Nothofagus::Bellota(
            Nothofagus::Transform(mPosition, 1.0f),
            textureId
        );
        return bellota;
    }

    Nothofagus::Texture Point::getTexture() const
    {
        const Nothofagus::ColorPallete colorPallete = {Colors::red};

        Nothofagus::Texture texture({1, 1}, Colors::white);
        texture.setPallete(colorPallete).setPixels({0});
        return texture;
    }

    Point& Point::setPosition(const glm::vec2& position)
    {
        mPosition = position;
        return *this;
    }
}