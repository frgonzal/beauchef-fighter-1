#pragma once


namespace bf
{
    class Fighter;

    class FighterState
    {
    public:
        FighterState() = default;
        virtual ~FighterState() = default;
        virtual void update(float deltaTime) = 0;

        void setFighter(Fighter* fighter) 
        {
            mFighter = fighter;
        }

    protected:
        Fighter* mFighter;
    };
}