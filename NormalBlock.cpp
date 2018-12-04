//
// Created by Athos Innocenti on 21/11/2018.
//

#include "NormalBlock.h"

NormalBlock::NormalBlock() {
    spriteTexture.loadFromFile("Block.png");
    setTexture(spriteTexture);
    setScale(0.1,0.1);
}

NormalBlock::~NormalBlock() {}