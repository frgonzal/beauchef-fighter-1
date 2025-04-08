#include "fight_ring.hpp"
#include <nothofagus.h>
#include <colors.hpp>



namespace bf
{
    Nothofagus::Bellota FightRing::getBellota(Nothofagus::TextureId textureId) const
    {
        Nothofagus::Bellota bellota = Nothofagus::Bellota({{75.0f, 75.0f}}, textureId);
        bellota.transform().scale() = {20.0f, 10.0f};
        return bellota;
    }

    Nothofagus::Texture FightRing::getTexture() const
    {
        Nothofagus::Texture texture({8, 4}, {0.5, 0.5, 0.5, 1.0});
        texture.setPallete(getColorPallete()).setPixels(
            {
                0, 0,
                0, 0,
            }
        );
        return texture;
    }

    static Nothofagus::ColorPallete getColorPallete()
    {
        return {
            Colors::brown,
        };
    }
}