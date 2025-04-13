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

        Nothofagus::Key attack;
        Nothofagus::Key block;
        Nothofagus::Key jump;

        static FighterKeys getKeys(FighterControls controls);

    private:
        FighterKeys(
            Nothofagus::Key moveLeft, 
            Nothofagus::Key moveRight, 
            Nothofagus::Key moveUp, 
            Nothofagus::Key moveDown, 
            Nothofagus::Key attack,
            Nothofagus::Key block,
            Nothofagus::Key jump
        ) : moveLeft(moveLeft), 
            moveRight(moveRight), 
            moveUp(moveUp), 
            moveDown(moveDown), 
            attack(attack), 
            block(block), 
            jump(jump) {}
    };
}