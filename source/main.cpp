#include <rusty_audio.h>
#include <nothofagus.h>
#include <iostream>
#include <format>
#include "game_controller/game_controller.h"
#include "entity/fight_ring.h"
#include "entity/box/box.h"
#include "entity/fighter/fighter.h"
#include "entity/fighter/state/fighter_standing_state.h"



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

    bf::FightRing fightRing({screenWidth / 2.0f, screenHeight / 3.0f + 10}, screenWidth - 20, 2 * screenHeight / 3.0f);
    fightRing.addToCanvas(canvas);

    bf::GameController gameController;

    bf::Fighter fighter1;
    fighter1.setPosition({screenWidth / 2.0f, screenHeight / 2.0f});
    fighter1.addToCanvas(canvas);


    bf::Box box1({screenWidth / 2.0f, screenHeight / 2.0f}, 5, 10);
    box1.setColor(bf::Colors::blue);
    box1.addToCanvas(canvas);

    auto update = [&](float dt)
    {
        ImGui::Begin("Beauchef Fighter");
        ImGui::End();

        fighter1.update(canvas, dt);

        if (!gameController.isRunning()) return;
        gameController.update(dt);
    };

    Nothofagus::Controller controller;

    controller.registerAction({Nothofagus::Key::SPACE, Nothofagus::DiscreteTrigger::Press}, [&]() { soundPlayer.play(); });
    fighter1.registerActions(controller, bf::FighterControls::AWSD);
    
    canvas.run(update, controller);


    return 0;
}