//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"
#include <utility>
#include <iostream>

Game::Game() : window ("Joyride", sf::Vector2u (1080, 720)),
               character(sf::Vector2i (1080, 720)),
               block(sf::Vector2i (1080, 720), character) {
    Reset();
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
        //std::cout<<"Il tuo punteggio è: "<<10<<std::endl; //stampa score: map.GetScore()
        //window.SetDone();
     }
}

void Game::HandleInput() {}

void Game::IncreaseScore() {}

void Game::HandleText() { //gestione del testo
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setString("");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(25);
    text.setPosition(15200, 50);
}

void Game::Addstring(std::string message) {
    text.setString(message);
}

void Game::Reset() {
    HandleText();
    score = 0;
    view = sf::View(sf::Vector2f (300, 15000), sf::Vector2f (600, 600));
}

void Game::Render(sf::RenderWindow &window) {
    window.draw(text);
    window.setView(view);
}

void Game::Render() {
    window.BeginDraw();
    character.Render(*window.GetRenderWindow());
    block.Render(*window.GetRenderWindow());
    //TO DO: stessa cosa per enemy
    window.EndDraw();
}