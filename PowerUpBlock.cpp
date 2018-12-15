//
// Created by Athos Innocenti on 21/11/2018.
//

#include "PowerUpBlock.h"
#include <iostream>

PowerUpBlock::PowerUpBlock() {
    spriteTexture.loadFromFile("PBlock.png");
    setTexture(spriteTexture);
    setScale(0.15,0.15);
}

PowerUpBlock::~PowerUpBlock() {}