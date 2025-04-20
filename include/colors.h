#pragma once
#include <nothofagus.h>
#include <array>
#include <tuple>
#include <cstdint>



namespace bf
{
    /** 
     * @brief Enum class representing different colors.
     * This enum class defines a set of colors that can be used in the game.
     */
    enum class Color : std::uint8_t {
        NONE,
        RED,
        GREEN,
        BLUE,
        WHITE,
        BLACK,
        YELLOW,
        ORANGE,
        PURPLE,
        PINK,
        BROWN,
        SKY_BLUE,
        COUNT,
    };

    /** 
     * @brief Class to convert Color enum to RGB values.
     * This class provides a static method to convert Color enum values to their corresponding RGB values.
     */
    class RGB { 
    public:
        static constexpr std::array<glm::vec4, static_cast<size_t>(Color::COUNT)> table{{
            {      0.f,       0.f,       0.f, 0.f}, // NONE
            {230/255.f,  10/255.f,  10/255.f, 1.f}, // RED
            { 10/255.f, 230/255.f,  10/255.f, 1.f}, // GREEN
            { 10/255.f,  10/255.f, 230/255.f, 1.f}, // BLUE
            {255/255.f, 255/255.f, 255/255.f, 1.f}, // WHITE
            {  0/255.f,   0/255.f,   0/255.f, 1.f}, // BLACK
            {255/255.f, 239/255.f, 127/255.f, 1.f}, // YELLOW
            {255/255.f, 102/255.f,   0/255.f, 1.f}, // ORANGE
            {102/255.f,   0/255.f, 204/255.f, 1.f}, // PURPLE
            {204/255.f,   0/255.f, 204/255.f, 1.f}, // PINK
            {105/255.f,  73/255.f,  32/255.f, 1.f}, // BROWN
            {198/255.f, 233/255.f, 239/255.f, 1.f}, // SKY_BLUE
        }};
    
        static constexpr glm::vec4 from(Color c) {
            return table[static_cast<size_t>(c)];
        }
    };
}
    