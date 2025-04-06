#include <rusty_audio.h>
#include <nothofagus.h>
#include <iostream>




int main() 
{
    constexpr uint32_t sampleRate = 40000;
    constexpr uint32_t channels = 2;


    RustyAudio::Builder soundBuilder;
    soundBuilder.appendSinusoids({
        {500, 0.1, 200.0}, // A4
        {500, 0.3, 700.0}, // C#5
        {500, 0.1, 300.0}  // E5
    });

    RustyAudio::Buffer soundBuffer = soundBuilder.generate(sampleRate, channels);

    RustyAudio::Player soundPlayer;
    soundPlayer.init(soundBuffer);

    soundPlayer.play();
    while (soundPlayer.isPlaying());

    Nothofagus::ScreenSize screenSize{150, 100};
    Nothofagus::Canvas canvas(screenSize, "Beauchef Fighter", {0.7, 0.7, 0.7}, 6);

    auto update = [&](float dt)
    {

    };

    Nothofagus::Controller controller;
    // controller.registerAction({Nothofagus::Key::ESCAPE, Nothofagus::DiscreteTrigger::Press}, [&]() { canvas.close(); });
    
    canvas.run(update, controller);


    return 0;
}