#include "entity/hud/health_bar.h"




namespace bf
{
    HealthBar::HealthBar(float width, float height) :
        mHealthBox(width, height),
        mBackgroundBox(width, height)
    {
        mBackgroundBox.setColor(Color::RED);
        mHealthBox.setColor(Color::GREEN);
    }


    void HealthBar::addToCanvas(Nothofagus::Canvas& canvas)
    {
        mBackgroundBox.addToCanvas(canvas);
        mHealthBox.addToCanvas(canvas);
    }


    const Fighter &HealthBar::fighter() const
    {
        if (mFighter == nullptr)
        {
            throw std::runtime_error("HealthBar::fighter: Fighter is not set.");
        }
        return *mFighter;
    }


    void HealthBar::setPosition(const glm::vec2& position)
    {
        mBackgroundBox.setPosition(position);
        mHealthBox.setPosition(position);
    }


    void HealthBar::update(Nothofagus::Canvas& canvas, float deltaTime)
    {
        float healthPercentage = health() / fighter().maxHealth();
        mHealthBox.setDimensions(mBackgroundBox.width() * healthPercentage, mBackgroundBox.height());

        float difference = mBackgroundBox.width() * (1 - healthPercentage) / 2.0f;

        glm::vec2 position = mBackgroundBox.position() - glm::vec2{difference, 0};

        mHealthBox.setPosition(position);
        mBackgroundBox.update(canvas, deltaTime);
        mHealthBox.update(canvas, deltaTime);
    }


    void HealthBar::setColor(const Color color)
    {
        mBackgroundBox.setColor(color);
        mHealthBox.setColor(color);
    }
}