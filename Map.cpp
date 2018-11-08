//
// Created by Athos Innocenti on 30/10/2018.
//
#include <iostream>
#include <utility>
#include "Map.h"

Map::Map(sf::Vector2f WindS, unsigned int score, Character &character)
        : WindowSize(WindS), score(score), character(character) {
    Reset ();
}

Map::~Map() {}

void Map::Reset() {
    HandleText();
    score = 0;
    view = sf::View(sf::Vector2f (300, 15000), sf::Vector2f (600, 600));
}

void Map::HandleText() { //gestione del testo
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setString("");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(25);
    text.setPosition(15200, 50);
}

void Map::IncreaseScore() {}

void Map::Render(sf::RenderWindow &window) {
    window.draw(text);
    window.setView(view);
}

void Map::Addstring(std::string message) {
    text.setString(message);
}

void Map::Update() {
    IncreaseScore();
}