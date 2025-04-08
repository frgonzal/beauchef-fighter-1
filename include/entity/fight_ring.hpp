#pragma once
#include "entity/drawable.hpp"
#include "axis_aligned_box.h"
#include <nothofagus.h>



namespace bf
{
    class FightRing : public Drawable
    {
    public:
        FightRing() : mBox({{0.0f, 0.0f}, {0.0f, 0.0f}}) {}
        ~FightRing() = default;

        Nothofagus::Texture getTexture() const override;
        Nothofagus::Bellota getBellota(Nothofagus::TextureId) const override;
        FightRing& setPosition(const glm::vec2& position);
        FightRing& setDimensions(float width, float height);

    private:
        AxisAlignedBox mBox;
        float mWidth = 100.0f;
        float mHeight = 50.0f;
    };
}