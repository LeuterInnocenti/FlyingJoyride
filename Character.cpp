//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Character.h"

Character::Character() {
    player.setPosition(50, 100);
}

Character::~Character() {}

void Character::setPlayerTexture(sf::Texture &pTexture) {
    player.setTexture(pTexture);
    player.setScale(0.10, 0.10);
}

bool Character::gameOver(bool characterDeath) {
    death();
    return characterDeath;
}

void Character::render(sf::RenderWindow &window) {
    window.draw(player);
}

sf::Vector2f Character::getPlayerSize() {
    return sf::Vector2f(player.getGlobalBounds().width, player.getGlobalBounds().height);
}