#pragma once
#include <nothofagus.h>


namespace bf
{
    typedef glm::vec4 Color;

    class Colors
    {
    public:
        Colors() = delete;
        static constexpr Color grey       = {0.5, 0.5, 0.5, 1.0};
        static constexpr Color red        = {1.0, 0.0, 0.0, 1.0};
        static constexpr Color white      = {1.0, 1.0, 1.0, 1.0};
        static constexpr Color black      = {0.0, 0.0, 0.0, 1.0};
        static constexpr Color green      = {0.0, 1.0, 0.0, 1.0};
        static constexpr Color blue       = {0.0, 0.0, 1.0, 1.0};
        static constexpr Color yellow     = {1.0, 1.0, 0.0, 1.0};
        static constexpr Color cyan       = {0.0, 1.0, 1.0, 1.0};
        static constexpr Color magenta    = {1.0, 0.0, 1.0, 1.0};
        static constexpr Color orange     = {1.0, 0.5, 0.0, 1.0};
        static constexpr Color purple     = {0.5, 0.0, 0.5, 1.0};
        static constexpr Color pink       = {1.0, 0.75, 0.8, 1.0};
        static constexpr Color brown      = {0.5, 0.25, 0.0, 1.0};
        static constexpr Color lightGrey  = {0.75, 0.75, 0.75, 1.0};
        static constexpr Color darkGrey   = {0.25, 0.25, 0.25, 1.0};
        static constexpr Color lightRed   = {1.0, 0.5, 0.5, 1.0};
        static constexpr Color lightGreen = {0.5, 1.0, 0.5, 1.0};
        static constexpr Color lightBlue  = {0.5, 0.5, 1.0, 1.0};
    };
}
    