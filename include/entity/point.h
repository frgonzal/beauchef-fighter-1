#pragma once
#include <nothofagus.h>
#include "entity/drawable.hpp"


namespace bf
{
    class Point : public Drawable
    {
    public:
        Point() = default;
        Point(const glm::vec2& position) : mPosition(position) {}
        Point(const glm::vec2&& position) : mPosition(position) {}
        ~Point() = default;

        Nothofagus::Texture getTexture() const override;
        Nothofagus::Bellota getBellota(Nothofagus::TextureId) const override;
        Point& setPosition(const glm::vec2& position);
    
    private:
        glm::vec2 mPosition{0.0f, 0.0f};
    };
}
