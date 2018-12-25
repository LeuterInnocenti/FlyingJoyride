//
// Created by Athos Innocenti on 22/12/18.
//

#include "Block.h"

Block::Block() {
    isPowerUp = false;
}

Block::~Block() {}

void Block::setIsPowerUpBlock() {
    isPowerUp = true;
}

bool Block::getIsPowerUpBlock() const {
    return isPowerUp;
}
