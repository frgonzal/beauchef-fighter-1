#include "entity/drawable.hpp"
#include <nothofagus.h>


namespace bf
{
    void Drawable::addToCanvas(Nothofagus::Canvas& canvas)
    {
        Nothofagus::Texture texture = getTexture();
        mTextureId = canvas.addTexture(texture);
        Nothofagus::Bellota bellota = getBellota(mTextureId);
        mBellotaId = canvas.addBellota(bellota);
    }

    Nothofagus::BellotaId Drawable::getBellotaId() const
    {
        return mBellotaId;
    }

    Nothofagus::TextureId Drawable::getTextureId() const
    {
        return mTextureId;
    }
}