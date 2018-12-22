//
// Created by Athos Innocenti on 24/11/2018.
//

#include "BlockFactory.h"

BlockFactory::BlockFactory() {
    normalBlockTexture.loadFromFile("Block.png");
    powerUpBlockTexture.loadFromFile("PBlock.png");
}

BlockFactory::~BlockFactory() {}

std::unique_ptr<Block> BlockFactory::createBlock(BlockType type) {
    std::unique_ptr<Block> result = std::unique_ptr<Block>(new class Block());
    if (type == BlockType::NormalBlock) {
        result->setTexture(normalBlockTexture);
        result->setScale(0.1, 0.1);
    } else if (type == BlockType::PowerUpBlock) {
        result->setTexture(powerUpBlockTexture);
        result->setScale(0.15, 0.15);
        result->setIsPowerUpBlock();
    }
    return result;
}