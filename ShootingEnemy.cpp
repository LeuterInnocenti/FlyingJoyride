//
// Created by Athos Innocenti on 04/12/2018.
//

#include "ShootingEnemy.h"

ShootingEnemy::ShootingEnemy() {
    spriteTexture.loadFromFile("senemy1.png");
    setTexture(spriteTexture);
    setScale(0.13,0.13);
    canShoot = true;
}

ShootingEnemy::~ShootingEnemy() {}