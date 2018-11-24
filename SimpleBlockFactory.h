//
// Created by Athos Innocenti on 23/11/2018.
//

#ifndef FLYJOYRIDE_SIMPLEBLOCKFACTORY_H
#define FLYJOYRIDE_SIMPLEBLOCKFACTORY_H

#include "Block.h"
#include "PowerUpBlock.h"
#include "NormalBlock.h"

enum BlockType {PowerUpBlock, NormalBlock};

class SimpleBlockFactory {
public:
    SimpleBlockFactory();
    virtual ~SimpleBlockFactory();
    std::shared_ptr<Block> createBlock(BlockType type);
    /*
    Block createBlock(std::string type) const {
        Block block;
        if(type.compare("PowerUpBlock") == 0) //type.compare restituisce un intero
            block = PowerUpBlock();
        else
            block = NormalBlock();
        return block;
    }
    */
};

#endif //FLYJOYRIDE_SIMPLEBLOCKFACTORY_H