#include "entity/hud/displayable_text.h"
#include <exception>


namespace bf
{

    void DisplayableText::addToCanvas(Nothofagus::Canvas& canvas)
    {
        for (size_t i = 0; i < mText.size(); i++)
        {
            const char& character = mText[i];

            Nothofagus::Texture texture = getTextureForChar(character, mColor);
            const float textureSize = texture.size().x;

            Nothofagus::TextureId textureId = canvas.addTexture(texture);

            Nothofagus::Bellota bellota = Nothofagus::Bellota(
                Nothofagus::Transform(mPosition, 1.0f),
                textureId
            );

            glm::vec2 position = glm::vec2{static_cast<float>(i - mText.size() / 2.0f), 0.0f} * (mWidth + 0.1f);
            bellota.transform().location() = mPosition + position;
            bellota.transform().scale() = {mWidth / textureSize, mWidth / textureSize};
            bellota.visible() = isEnabled();

            mTextureIds.push_back(textureId);
            mBellotaIds.emplace_back(canvas.addBellota(bellota), mPosition + position);
        }
    }

    void DisplayableText::update(Nothofagus::Canvas& canvas, float deltaTime)
    {
        for (auto& [bellotaId, position] : mBellotaIds)
        {
            Nothofagus::Bellota& bellota = canvas.bellota(bellotaId);
            bellota.visible() = isEnabled();
            bellota.transform().location() = position;
        }
    }

    void DisplayableText::setPosition(const glm::vec2& position)
    {
        glm::vec2 translation = position - mPosition;
        mPosition = position;
        for (auto& [bellotaId, relativePosition] : mBellotaIds)
        {
            relativePosition =  relativePosition + translation;
        }
    }

    void DisplayableText::setColor(const Color color)
    {
        mColor = color;
    }


    Nothofagus::Texture DisplayableText::getTextureForChar(char character, Color color)
    {
        const unsigned int textureSize = 8;
        Nothofagus::Texture texture({textureSize, textureSize}, RGB::from(color));
        texture.setPallete({ RGB::from(Color::NONE), RGB::from(color) });

        switch (character) {
            case 'A': texture.setPixels({
                0,0,1,1,1,1,0,0,
                0,1,0,0,0,0,1,0,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,1,1,1,1,1,1,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1
            }); break;

            case 'B': texture.setPixels({
                1,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,1,1,1,1,1,0,0
            }); break;

            case 'C': texture.setPixels({
                0,1,1,1,1,1,1,0,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,1,
                0,1,1,1,1,1,1,0
            }); break;

            case 'D': texture.setPixels({
                1,1,1,1,1,0,0,0,
                1,0,0,0,0,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,1,0,0,
                1,1,1,1,1,0,0,0
            }); break;

            case 'E': texture.setPixels({
                1,1,1,1,1,1,1,1,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,1,1,1,1,1,1,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,1,1,1,1,1,1,1
            }); break;

            case 'F': texture.setPixels({
                1,1,1,1,1,1,1,1,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,1,1,1,1,1,1,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0
            }); break;

            case 'G': texture.setPixels({
                0,1,1,1,1,1,1,0,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,0,
                1,0,0,0,1,1,1,1,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                0,1,1,1,1,1,1,0
            }); break;

            case 'H': texture.setPixels({
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,1,1,1,1,1,1,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1
            }); break;

            case 'I': texture.setPixels({
                1,1,1,1,1,1,1,1,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                1,1,1,1,1,1,1,1
            }); break;

            case 'J': texture.setPixels({
                0,0,0,0,0,1,1,0,
                0,0,0,0,0,1,1,0,
                0,0,0,0,0,1,1,0,
                0,0,0,0,0,1,1,0,
                0,0,0,0,0,1,1,0,
                1,0,0,0,0,1,1,0,
                1,0,0,0,0,1,1,0,
                0,1,1,1,1,0,0,0
            }); break;

            case 'K': texture.setPixels({
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,1,0,0,
                1,1,1,1,1,0,0,0,
                1,0,0,0,0,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1
            }); break;

            case 'L': texture.setPixels({
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,1,1,1,1,1,1,1
            }); break;

            case 'M': texture.setPixels({
                1,0,0,0,0,0,0,1,
                1,1,0,0,0,0,1,1,
                1,0,1,0,0,1,0,1,
                1,0,0,1,1,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1
            }); break;

            case 'N': texture.setPixels({
                1,0,0,0,0,0,0,1,
                1,1,0,0,0,0,0,1,
                1,0,1,0,0,0,0,1,
                1,0,0,1,0,0,0,1,
                1,0,0,0,1,0,0,1,
                1,0,0,0,0,1,0,1,
                1,0,0,0,0,0,1,1,
                1,0,0,0,0,0,0,1
            }); break;

            case 'O': texture.setPixels({
                0,1,1,1,1,1,1,0,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                0,1,1,1,1,1,1,0
            }); break;

            case 'P': texture.setPixels({
                1,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,1,1,1,1,1,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0
            }); break;

            case 'Q': texture.setPixels({
                0,1,1,1,1,1,1,0,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,1,0,1,
                1,0,0,0,1,0,1,0,
                0,1,1,1,1,1,0,1,
                0,0,0,0,0,0,1,0
            }); break;

            case 'R': texture.setPixels({
                1,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,1,1,1,1,1,0,0,
                1,0,1,0,0,0,0,0,
                1,0,0,1,0,0,0,0,
                1,0,0,0,1,0,0,0,
                1,0,0,0,0,1,0,0
            }); break;

            case 'S': texture.setPixels({
                0,1,1,1,1,1,1,0,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,0,
                0,1,1,1,1,1,1,0,
                0,0,0,0,0,0,1,0,
                0,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                0,1,1,1,1,1,0,0
            }); break;

            case 'T': texture.setPixels({
                1,1,1,1,1,1,1,1,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,1,1,0,0,0
            }); break;

            case 'U': texture.setPixels({
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                0,1,1,1,1,1,1,0
            }); break;

            case 'V': texture.setPixels({
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                0,1,0,0,0,0,1,0,
                0,1,0,0,0,0,1,0,
                0,1,0,0,0,0,1,0,
                0,0,1,0,1,0,0,0,
                0,0,0,1,0,0,0,0
            }); break;

            case 'W': texture.setPixels({
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,0,0,0,0,0,1,
                1,0,1,0,1,0,1,0,
                1,0,1,0,1,0,1,0,
                1,0,1,0,1,0,1,0,
                0,1,0,1,0,1,0,0,
                0,1,0,1,0,1,0,0
            }); break;

            case 'X': texture.setPixels({
                1,0,0,0,0,0,0,1,
                0,1,0,0,0,0,1,0,
                0,1,0,0,0,0,1,0,
                0,0,1,1,1,1,0,0,
                0,0,1,1,1,1,0,0,
                0,1,0,0,0,0,1,0,
                0,1,0,0,0,0,1,0,
                1,0,0,0,0,0,0,1
            }); break;

            case 'Y': texture.setPixels({
                1,0,0,0,0,0,0,1,
                0,1,0,0,0,0,1,0,
                0,1,0,0,0,0,1,0,
                0,0,1,0,0,1,0,0,
                0,0,1,0,0,1,0,0,
                0,0,1,0,0,1,0,0,
                0,0,1,0,0,1,0,0,
                0,0,1,0,0,1,0,0
            }); break;

            case 'Z': texture.setPixels({
                1,1,1,1,1,1,1,1,
                0,0,0,0,0,0,1,0,
                0,0,0,0,0,1,0,0,
                0,0,0,0,1,0,0,0,
                0,0,0,1,0,0,0,0,
                0,0,1,0,0,0,0,0,
                0,1,0,0,0,0,0,0,
                1,1,1,1,1,1,1,1
            }); break;

            // Numbers 0–9
            case '0': texture.setPixels({
                0,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,1,0,0,1,0,
                1,0,0,1,0,0,1,0,
                1,0,0,1,0,0,1,0,
                1,0,0,1,0,0,1,0,
                1,0,0,0,0,0,1,0,
                0,1,1,1,1,1,0,0
            }); break;

            case '1': texture.setPixels({
                0,0,1,1,0,0,0,0,
                0,1,1,1,0,0,0,0,
                1,0,1,1,0,0,0,0,
                0,0,1,1,0,0,0,0,
                0,0,1,1,0,0,0,0,
                0,0,1,1,0,0,0,0,
                0,0,1,1,0,0,0,0,
                1,1,1,1,1,1,1,0
            }); break;

            case '2': texture.setPixels({
                0,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                0,0,0,0,0,0,1,0,
                0,0,0,0,0,1,0,0,
                0,0,0,0,1,0,0,0,
                0,0,0,1,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,1,1,1,1,1,1,0
            }); break;

            case '3': texture.setPixels({
                1,1,1,1,1,1,0,0,
                0,0,0,0,0,0,1,0,
                0,0,0,0,0,0,1,0,
                0,1,1,1,1,1,0,0,
                0,0,0,0,0,0,1,0,
                0,0,0,0,0,0,1,0,
                0,0,0,0,0,0,1,0,
                1,1,1,1,1,1,0,0
            }); break;

            case '4': texture.setPixels({
                1,0,0,0,1,0,0,0,
                1,0,0,0,1,0,0,0,
                1,0,0,1,1,0,0,0,
                1,0,1,0,1,0,0,0,
                1,1,1,1,1,1,1,0,
                0,0,0,0,1,0,0,0,
                0,0,0,0,1,0,0,0,
                0,0,0,1,1,0,0,0
            }); break;

            case '5': texture.setPixels({
                1,1,1,1,1,1,1,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,1,1,1,1,1,0,0,
                0,0,0,0,0,0,1,0,
                0,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                0,1,1,1,1,1,0,0
            }); break;

            case '6': texture.setPixels({
                0,1,1,1,1,1,0,0,
                1,0,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0,
                1,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                0,1,1,1,1,1,0,0
            }); break;

            case '7': texture.setPixels({
                1,1,1,1,1,1,1,0,
                0,0,0,0,0,0,1,0,
                0,0,0,0,0,1,0,0,
                0,0,0,0,1,0,0,0,
                0,0,0,1,0,0,0,0,
                0,0,1,0,0,0,0,0,
                0,1,0,0,0,0,0,0,
                1,0,0,0,0,0,0,0
            }); break;

            case '8': texture.setPixels({
                0,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                0,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                0,1,1,1,1,1,0,0
            }); break;

            case '9': texture.setPixels({
                0,1,1,1,1,1,0,0,
                1,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                0,1,1,1,1,1,1,0,
                0,0,0,0,0,0,1,0,
                0,0,0,0,0,0,1,0,
                1,0,0,0,0,0,1,0,
                0,1,1,1,1,1,0,0
            }); break;

            case ' ': texture.setPixels({
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
            }); break;



            default:
                assert(false && "Character not supported in DisplayableText::getTextureForChar()");
        }

        return texture;
    }
}