//
// Created by Athos Innocenti on 23/11/2018.
//

#ifndef FLYJOYRIDE_SIMPLEBLOCKFACTORY_H
#define FLYJOYRIDE_SIMPLEBLOCKFACTORY_H

#include "Block.h"
#include "PowerUpBlock.h"
#include "NormalBlock.h"

enum BlockType { PowerUpBlock, NormalBlock };

class BlockFactory {
public:
    BlockFactory();
    virtual ~BlockFactory();
    std::unique_ptr<Block> createBlock(BlockType type);
};

#endif //FLYJOYRIDE_SIMPLEBLOCKFACTORY_H