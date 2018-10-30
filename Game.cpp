//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"

Game::Game() : window ("Joyride", sf::Vector2u (1080, 720)),
               map(sf::Vector2f (500, 16000), 0, character){}

Game::~Game() {}

void Game::Update() {
    window.Update();
    map.Update();
    character.Update();
}

void Game::HandleInput() {}

void Game::Render() {
    window.BeginDraw();
    window.EndDraw();
}