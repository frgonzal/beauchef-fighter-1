#include "audio.h"
#include <rusty_audio.h>
#include <iostream>


namespace bf
{
    void Audio::playBackgroundMusic()
    {
        RustyAudio::Builder soundBuilder;

        soundBuilder.appendSinusoids({
                // F2 → 90 Hz
    {150.0f, 0.30000f,  90.0f},
    {100.0f, 0.30000f,  90.0f},

    // G2 → 100 Hz
    {150.0f, 0.30000f, 100.0f},
    {100.0f, 0.30000f, 100.0f},

    // F♯2 → 90 Hz
    {150.0f, 0.30000f,  90.0f},
    {100.0f, 0.30000f,  90.0f},

    // A2 → 110 Hz
    {120.0f, 0.30000f, 110.0f},
    {100.0f, 0.30000f, 110.0f},

    // G♯2 → 100 Hz
    {120.0f, 0.30000f, 100.0f},
    {100.0f, 0.30000f, 100.0f},

    // B2 → 120 Hz
    {120.0f, 0.35000f, 120.0f},
    {100.0f, 0.30000f, 120.0f},

    // D3 → 150 Hz
    {120.0f, 0.30000f, 150.0f},
    {100.0f, 0.30000f, 150.0f},

    // C3 → 130 Hz
    {120.0f, 0.30000f, 130.0f},
    {100.0f, 0.30000f, 130.0f},

    // A2 reprise → 110 Hz
    {120.0f, 0.30000f, 110.0f},
    {100.0f, 0.30000f, 110.0f},

    // G2 reprise → 100 Hz
    {150.0f, 0.30000f, 100.0f},
    {100.0f, 0.30000f, 100.0f},

    // E3 → 160 Hz
    {100.0f, 0.30000f, 160.0f},
    {100.0f, 0.30000f, 160.0f},

    // G3 → 200 Hz
    {100.0f, 0.30000f, 200.0f},
    {100.0f, 0.30000f, 200.0f},
        });

        Audio::backgroundMusicBuffer = soundBuilder.generate(Audio::sampleRate, Audio::channels);
        Audio::backgroundMusicPlayer.init(backgroundMusicBuffer);
        Audio::backgroundMusicPlayer.setLooping(true);
        Audio::backgroundMusicPlayer.play();
    }
}