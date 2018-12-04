//
// Created by Athos Innocenti on 04/12/2018.
//

#include "ShootingEnemy.h"

ShootingEnemy::ShootingEnemy() {}

ShootingEnemy::~ShootingEnemy() {}

void ShootingEnemy::setEnemyTexture(sf::Texture texture) {
    setTexture(texture);
    setScale(0.1,0.1);
}