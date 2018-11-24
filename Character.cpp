//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Character.h"

Character::Character() {
    player.setSize(sf::Vector2f(100, 50));
    player.setFillColor(sf::Color::Blue);
    player.setPosition(50, 100);
}

Character::~Character() {}

bool Character::gameOver(bool characterDeath){
    death();
    if(characterDeath) {
        player.setFillColor(sf::Color::White);
    }
    return characterDeath;
}

void Character::render(sf::RenderWindow &window) {
    window.draw(player);
}