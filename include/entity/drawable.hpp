#pragma once
#include <nothofagus.h>


namespace bf
{
    class Drawable
    {
    public:
        Drawable() = default;
        ~Drawable() = default;

        void addToCanvas(Nothofagus::Canvas& canvas);

        Nothofagus::BellotaId getBellotaId() const;
        Nothofagus::TextureId getTextureId() const;

        virtual Nothofagus::Texture getTexture() const = 0;
        virtual Nothofagus::Bellota getBellota(Nothofagus::TextureId) const = 0;

    private:
        Nothofagus::BellotaId mBellotaId;
        Nothofagus::TextureId mTextureId;
    };
}