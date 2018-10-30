//
// Created by Athos Innocenti on 30/10/2018.
//
#include <iostream>
#include "Map.h"

Map::Map(sf::Vector2f WindS, unsigned int score, Character &character)
        : WindowSize(WindS), score(score), character(character) {
    Reset ();
}

void Map::Reset() {
    score = 0;
    view = sf::View (sf::Vector2f (300, 15000), sf::Vector2f (600, 600));
}

void Map::Render(sf::RenderWindow &window) {
    window.draw(text);
    window.setView(view);
}

Map::~Map() {}

void Map::Update() {
    IncreaseScore();
}