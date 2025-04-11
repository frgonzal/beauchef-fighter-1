#include "entity/fighter/fighter_keys.h"
#include <nothofagus.h>



namespace bf
{
    FighterKeys FighterKeys::getKeys(FighterControls controls)
    {
        switch (controls)
        {
            case FighterControls::AWSD:
                return FighterKeys(Nothofagus::Key::A, Nothofagus::Key::D, Nothofagus::Key::W, Nothofagus::Key::S);

            case FighterControls::ARROWS:
                return FighterKeys(Nothofagus::Key::LEFT, Nothofagus::Key::RIGHT, Nothofagus::Key::UP, Nothofagus::Key::DOWN);

            default:
                throw std::invalid_argument("Invalid FighterControls value");
        }
    }
}