#include <rusty_audio.h>
#include <nothofagus.h>
#include <iostream>
#include <format>
#include "game_controller/game_controller.h"
#include "entity/static/fight_ring.h"
#include "entity/box/box.h"
#include "entity/fighter/fighter.h"
#include "entity/fighter/state/fighter_standing_state.h"



int main() 
{
    constexpr uint32_t sampleRate = 40000;
    constexpr uint32_t channels = 2;


    RustyAudio::Builder soundBuilder;
    soundBuilder.appendSinusoids({
        {500, 0.1, 200.0},
        {500, 0.3, 700.0},
        {500, 0.1, 300.0},
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
    fighter1.setPosition({screenWidth / 2.0f + 15, screenHeight / 2.0f});
    fighter1.addToCanvas(canvas);

    bf::Fighter fighter2;
    fighter2.setPosition({screenWidth / 2.0f - 15, screenHeight / 2.0f});
    fighter2.addToCanvas(canvas);

    fighter1.setTarget(&fighter2);
    fighter2.setTarget(&fighter1);

    auto update = [&](float dt)
    {
        ImGui::Begin("Beauchef Fighter");
        ImGui::Text(std::format("Fighter1 State: {}", fighter1.currentState()->toString()).c_str());
        ImGui::Text(std::format("Fighter1 Position: ({}, {})", fighter1.position().x, fighter1.position().y).c_str());
        ImGui::Text(std::format("Fighter1 Target Position: ({}, {})", fighter1.target()->position().x, fighter1.target()->position().y).c_str());
        ImGui::Text(std::format("Fighter1 View Direction: ({}, {})", fighter1.viewDirection().x, fighter1.viewDirection().y).c_str());

        ImGui::Text(std::format("Game State: {}", gameController.isRunning() ? "Running" : "Paused").c_str());
        ImGui::End();

        if (!gameController.isRunning()) return;

        gameController.update(dt);
        fighter1.update(canvas, dt);
        fighter2.update(canvas, dt);

        /** Ensure fighters are inside the fight ring limits */
        fightRing.moveEntityInsideLimits(fighter1);
        fightRing.moveEntityInsideLimits(fighter2);
    };

    Nothofagus::Controller controller;
    fighter1.registerActions(controller, bf::FighterControls::AWSD);
    
    canvas.run(update, controller);


    return 0;
}