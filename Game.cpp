//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"
#include <iostream>

Game::Game() : window ("Joyride", sf::Vector2u (1080,720)),
               character(sf::Vector2i (1080, 720)),
               block(sf::Vector2i (1080, 720), character) {
    reset();
    backgroundTexture.loadFromFile("Background.png");
    background.setTexture(backgroundTexture);
    background.setScale(0.95,0.95);
}

Game::~Game() {}

void Game::update() {
    increaseScore();
    window.update();
    character.update(window.GetWindowSize().y);
    block.move();
    block.update();
    block.collision();
    if(character.getDeath()){
        // std::cout<<"Il tuo punteggio è: "<<score<<std::endl;
        window.setDone();
     }
}

void Game::increaseScore() {}

void Game::handleText() { // gestione del testo
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setString("");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(25);
    text.setPosition(15200, 50);
}


void Game::reset() {
    //handleText();
    score = 0;
}

void Game::render() {
    window.beginDraw();
    window.draw(background);
    character.render(*window.GetRenderWindow());
    block.render(*window.GetRenderWindow());
    window.endDraw();
    //TO DO: stessa cosa per enemy
}