//
// Created by Athos Innocenti on 24/11/2018.
//

#include "SimpleBlockFactory.h"
#include "NormalBlock.h"
#include "PowerUpBlock.h"

SimpleBlockFactory::SimpleBlockFactory() {}

SimpleBlockFactory::~SimpleBlockFactory() {}

std::shared_ptr<Block> SimpleBlockFactory::createBlock(BlockType type) {
    std::shared_ptr<Block> result;
    if(type == BlockType::NormalBlock) {
        result = std::shared_ptr<Block>(new class NormalBlock());
    } else if (type == BlockType::PowerUpBlock) {
        result = std::shared_ptr<Block>(new class PowerUpBlock());
    }
    // result->setBitap(); per mettere lo sprite, vedi e.g. Bertini
    return result;
}