//
// Created by Athos Innocenti on 04/12/2018.
//

#include "FlyingEnemy.h"

FlyingEnemy::FlyingEnemy() {
    spriteTexture.loadFromFile("fenemy1.png");
    setTexture(spriteTexture);
    setScale(0.13,0.13);
}

FlyingEnemy::~FlyingEnemy() {}