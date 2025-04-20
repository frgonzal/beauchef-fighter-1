#pragma once
#include "entity/drawable.h"
#include <string>
#include <nothofagus.h>
#include <vector>
#include <tuple>
#include "colors.h"

namespace bf
{
    class DisplayableText : public Drawable
    {
    public:
        DisplayableText() = default;
        DisplayableText(std::string &&text, float width) : mText(text), mWidth(width) {}
        ~DisplayableText() = default;

        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;
        void setPosition(const glm::vec2& position) override;
        void setColor(const Color color) override;

        static Nothofagus::Texture getTextureForChar(char character, Color color);

    private:
        std::string mText;
        glm::vec2 mPosition = {0, 0};
        Color mColor = Color::YELLOW;
        float mWidth = 1.0f;

        std::vector<std::tuple<Nothofagus::BellotaId, glm::vec2>> mBellotaIds;
        std::vector<Nothofagus::TextureId> mTextureIds;
    };
}