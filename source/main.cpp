#include <rusty_audio.h>
#include <nothofagus.h>
#include <iostream>
#include <format>
#include "game_controller/game_controller.h"
#include "entity/static/fight_ring.h"
#include "entity/box/box.h"
#include "entity/fighter/fighter.h"
#include "entity/fighter/state/fighter_standing_state.h"
#include <cstdlib>
#include <ctime>
#include "entity/actions/action.h"
#include "audio.h"
#include "entity/hud/health_bar.h"
#include "entity/hud/displayable_text.h"



int main() 
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    constexpr float aspectRatio = 16.0 / 9.0;
    constexpr uint32_t screenHeight = 50;
    constexpr uint32_t screenWidth = screenHeight * aspectRatio;
    Nothofagus::Canvas canvas({screenWidth, screenHeight}, "Beauchef Fighter", bf::RGB::from(bf::Color::SKY_BLUE), 14);

    float figthtRingBorderWidth = 2.5f;
    float fightRingRatio = 0.4f;
    bf::FightRing fightRing(
        screenWidth - 2 * figthtRingBorderWidth, 
        2 * (screenHeight * fightRingRatio - figthtRingBorderWidth),
        figthtRingBorderWidth
    );
    fightRing.setPosition({screenWidth / 2.0, screenHeight * fightRingRatio});
    fightRing.addToCanvas(canvas);

    bf::GameController gameController;

    bf::Fighter fighter1("JUGADOR 1");
    fighter1.setColor(bf::Color::BLUE);
    fighter1.setPosition({screenWidth / 2.0f - 15, screenHeight / 2.0f});
    fighter1.addToCanvas(canvas);

    bf::Fighter fighter2("JUGADOR 2");
    fighter2.setColor(bf::Color::ORANGE);
    fighter2.setPosition({screenWidth / 2.0f + 15, screenHeight / 2.0f});
    fighter2.addToCanvas(canvas);

    fighter1.setTarget(&fighter2);
    fighter2.setTarget(&fighter1);

    bf::HealthBar healthBarFighter1(20, 1);
    bf::HealthBar healthBarFighter2(20, 1);
    healthBarFighter1.setFighter(fighter1);
    healthBarFighter2.setFighter(fighter2);
    healthBarFighter1.setPosition({screenWidth / 2.0f - 20, screenHeight - 1.5f});
    healthBarFighter2.setPosition({screenWidth / 2.0f + 20, screenHeight - 1.5f});
    healthBarFighter1.addToCanvas(canvas);
    healthBarFighter2.addToCanvas(canvas);

    bf::DisplayableText titleText("BEAUCHEF FIGHTER", 0.8f);
    titleText.setPosition({screenWidth / 2.0f, screenHeight - 1.5f});
    titleText.setColor(bf::Color::RED);
    titleText.addToCanvas(canvas);

    bf::DisplayableText fighter1WinnerText("JUGADOR 1 HA GANADO", 3.f);
    fighter1WinnerText.setPosition({screenWidth / 2.0f, screenHeight / 2.0f});
    fighter1WinnerText.setColor(bf::Color::RED);
    fighter1WinnerText.disable();
    fighter1WinnerText.addToCanvas(canvas);
    bf::DisplayableText fighter2WinnerText("JUGADOR 2 HA GANADO", 3.f);
    fighter2WinnerText.setPosition({screenWidth / 2.0f, screenHeight / 2.0f});
    fighter2WinnerText.setColor(bf::Color::RED);
    fighter2WinnerText.disable();
    fighter2WinnerText.addToCanvas(canvas);
    bf::DisplayableText tieText("EMPATE", 3.f);
    tieText.setPosition({screenWidth / 2.0f, screenHeight / 2.0f});
    tieText.setColor(bf::Color::RED);
    tieText.disable();
    tieText.addToCanvas(canvas);

    auto update = [&](float dt)
    {
        ImGui::Begin("Beauchef Fighter");
        ImGui::Text(std::format("Time Left: {:.2f} seconds", gameController.getTimeLeft() / 1000.0f).c_str());
        ImGui::End();

        if (gameController.hasFinished()) return;

        gameController.update(dt);

        fighter1.update(canvas, dt);
        fighter2.update(canvas, dt);

        healthBarFighter1.update(canvas, dt);
        healthBarFighter2.update(canvas, dt);

        if (!fighter1.isAlive() && fighter2.isAlive())
        {
            gameController.setWinner(&fighter2);
            return;
        }
        else if (fighter1.isAlive() && !fighter2.isAlive())
        {
            gameController.setWinner(&fighter1);
            return;
        }

        fightRing.moveEntityInsideLimits(fighter1);
        fightRing.moveEntityInsideLimits(fighter2);
    };

    Nothofagus::Controller controller;
    fighter1.registerActions(controller, bf::FighterControls::AWSD);
    fighter2.registerActions(controller, bf::FighterControls::ARROWS);

    gameController.setOnGameFinishedCallback([&]() {
        if (!gameController.hasWinner())
        {
            tieText.enable();
            tieText.update(canvas, 0);
            return;
        }
        if (&gameController.getWinner() == &fighter1)
        {
            fighter1WinnerText.enable();
            fighter1WinnerText.update(canvas, 0);
        }
        else if (&gameController.getWinner() == &fighter2)
        {
            fighter2WinnerText.enable();
            fighter2WinnerText.update(canvas, 0);
        }
    });
    
    bf::Audio::playBackgroundMusic();
    canvas.run(update, controller);

    return 0;
}