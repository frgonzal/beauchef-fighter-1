#pragma once


namespace bf
{
    class GameState
    {
    public:
        GameState() = default;

        virtual void update(float deltaTime) = 0;
        virtual bool isRunning() const = 0;
        virtual bool hasFinished() const = 0;
        virtual float getTimeLeft() const = 0;
    };
}


