//
// Created by Athos Innocenti on 24/11/2018.
//

#include "SimpleBlockFactory.h"
#include "NormalBlock.h"
#include "PowerUpBlock.h"

SimpleBlockFactory::SimpleBlockFactory() {}

SimpleBlockFactory::~SimpleBlockFactory() {}

std::unique_ptr<Block> SimpleBlockFactory::createBlock(BlockType type) {
    std::unique_ptr<Block> result;
    if(type == BlockType::NormalBlock) {
        result = std::unique_ptr<Block>(new class NormalBlock());
    } else if (type == BlockType::PowerUpBlock) {
        result = std::unique_ptr<Block>(new class PowerUpBlock());
    }
    // result->setBitap(); per mettere lo sprite, vedi e.g. Bertini
    return result;
}