#pragma once
#include "drawable.hpp"



namespace bf
{
    class FightRing : public Drawable
    {
    public:
        FightRing() = default;
        ~FightRing() = default;

        Nothofagus::Texture getTexture() const override;
        Nothofagus::Bellota getBellota(Nothofagus::TextureId) const override;
    };
}