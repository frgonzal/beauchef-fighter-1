#include <rusty_audio.h>
#include <nothofagus.h>
#include <iostream>
#include <format>
#include "game_controller/game_controller.hpp"
#include "entity/fight_ring.hpp"
#include "entity/point.h"



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
    soundPlayer.setLooping(true);
    // soundPlayer.play();


    constexpr float aspectRatio = 16.0 / 9.0;
    constexpr uint32_t screenHeight = 120;
    constexpr uint32_t screenWidth = screenHeight * aspectRatio;
    Nothofagus::Canvas canvas({screenWidth, screenHeight}, "Beauchef Fighter", {0.7, 0.7, 0.7}, 6);

    bf::FightRing fightRing;
    fightRing.setDimensions(screenWidth - 10, screenHeight - 20);
    fightRing.setPosition({screenWidth / 2.0f, screenHeight / 2.0f});
    fightRing.addToCanvas(canvas);

    bf::Point point;
    point.setPosition({1, 1}).addToCanvas(canvas);

    bf::GameController gameController;

    auto update = [&](float dt)
    {
        // ImGui::Begin("Beauchef Fighter");
        // ImGui::Text(std::format("Time (eft: {:.2f}", gameController.getTimeLeft()).c_str());
        // ImGui::Text(std::format("dt: {:.2f}", dt).c_str());
        // ImGui::End();

        if (!gameController.isRunning()) return;
        gameController.update(dt);
    };

    Nothofagus::Controller controller;
    // controller.registerAction({Nothofagus::Key::ESCAPE, Nothofagus::DiscreteTrigger::Press}, [&]() { canvas.close(); });
    controller.registerAction({Nothofagus::Key::SPACE, Nothofagus::DiscreteTrigger::Press}, [&]() { soundPlayer.play(); });
    
    canvas.run(update, controller);


    return 0;
}