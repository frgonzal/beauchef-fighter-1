#pragma once




namespace bf
{
    class Animatable
    {
    public:
        virtual ~Animatable() = default;
        virtual void playAnimation() = 0;
        virtual void stopAnimation() = 0;
    };
}