//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"
#include <iostream>

Game::Game() : window ("Joyride", sf::Vector2u (1080,720)),
               character(sf::Vector2i (1080, 720)),
               block(sf::Vector2i (1080, 720), character) {
    Reset();
    backgroundTexture.loadFromFile("Background.png");
    background.setTexture(backgroundTexture);
    background.setScale(0.95,0.95);
}

Game::~Game() {}

void Game::Update() {
    IncreaseScore();
    window.Update();
    character.Update(window.GetWindowSize().y);
    block.Move();
    block.Update();
    block.Collision();
    if(character.GetDeath()){
        // std::cout<<"Il tuo punteggio è: "<<score<<std::endl;
        window.SetDone();
     }
}

void Game::IncreaseScore() {}

void Game::HandleText() { // gestione del testo
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setString("");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(25);
    text.setPosition(15200, 50);
}


void Game::Reset() {
    //HandleText();
    score = 0;
}

void Game::Render() {
    window.BeginDraw();
    window.Draw(background);
    character.Render(*window.GetRenderWindow());
    block.Render(*window.GetRenderWindow());
    window.EndDraw();
    //TO DO: stessa cosa per enemy
}