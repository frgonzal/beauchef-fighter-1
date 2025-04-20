#pragma once
#include <rusty_audio.h>


namespace bf
{
    class Audio
    {
    public:
        static constexpr unsigned int sampleRate = 44000;
        static constexpr unsigned int channels = 2;

        static void playBackgroundMusic();

        inline static RustyAudio::Buffer backgroundMusicBuffer;
        inline static RustyAudio::Player backgroundMusicPlayer;
    };
}