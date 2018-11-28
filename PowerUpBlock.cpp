//
// Created by Athos Innocenti on 21/11/2018.
//

#include "PowerUpBlock.h"
#include <iostream>

PowerUpBlock::PowerUpBlock() {
    setFillColor(sf::Color::Yellow);
    setSize(sf::Vector2f(100, 80));
}

PowerUpBlock::~PowerUpBlock() {}

void PowerUpBlock::activePowerUp() {
    std::cout << "PowerUp attivato!" << std::endl;
}