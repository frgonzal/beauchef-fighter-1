#pragma once
#include <nothofagus.h>
    

namespace bf
{
    enum FighterControls
    {
        AWSD,
        ARROWS,
    };

    class FighterKeys
    {
    public:
        ~FighterKeys() = default;

        Nothofagus::Key moveLeft;
        Nothofagus::Key moveRight;
        Nothofagus::Key moveUp;
        Nothofagus::Key moveDown;

        Nothofagus::Key block;
        Nothofagus::Key punch;
        Nothofagus::Key kick;

        static FighterKeys getKeys(FighterControls controls);

    private:
        FighterKeys(
            Nothofagus::Key moveLeft, 
            Nothofagus::Key moveRight, 
            Nothofagus::Key moveUp, 
            Nothofagus::Key moveDown, 
            Nothofagus::Key punch,
            Nothofagus::Key kick,
            Nothofagus::Key block
        ) : moveLeft(moveLeft), 
            moveRight(moveRight), 
            moveUp(moveUp), 
            moveDown(moveDown), 
            punch(punch),
            kick(kick),
            block(block)
        {}
    };
}