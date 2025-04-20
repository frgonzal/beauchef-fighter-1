#include "entity/fighter/fighter_keys.h"
#include <nothofagus.h>



namespace bf
{
    FighterKeys FighterKeys::getKeys(FighterControls controls)
    {
        switch (controls)
        {
            case FighterControls::AWSD:
                return FighterKeys(
                    Nothofagus::Key::A, 
                    Nothofagus::Key::D, 
                    Nothofagus::Key::W, 
                    Nothofagus::Key::S, 
                    Nothofagus::Key::F,
                    Nothofagus::Key::G, 
                    Nothofagus::Key::H
                );

            case FighterControls::ARROWS:
                return FighterKeys(
                    Nothofagus::Key::LEFT, 
                    Nothofagus::Key::RIGHT, 
                    Nothofagus::Key::UP, 
                    Nothofagus::Key::DOWN, 
                    Nothofagus::Key::_1,
                    Nothofagus::Key::_2,
                    Nothofagus::Key::_3
                );

            default:
                assert(false && "FighterKeys::getKeys: Invalid controls type.");
        }
    }
}