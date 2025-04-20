#pragma once
#include "entity/drawable.h"
#include "entity/fighter/fighter.h"



namespace bf
{

    class HealthBar : public Drawable
    {
    public:
        HealthBar(float width, float height);

        void addToCanvas(Nothofagus::Canvas& canvas) override;
        void update(Nothofagus::Canvas& canvas, float deltaTime) override;
        void setPosition(const glm::vec2& position) override;
        void setColor(const Color color) override;

        float health() const { return fighter().health(); }

        void setFighter(const Fighter &fighter) { mFighter = &fighter; }
        const Fighter &fighter() const;

    private:
        const Fighter *mFighter = nullptr;
        Box mHealthBox;
        Box mBackgroundBox;
    };
}