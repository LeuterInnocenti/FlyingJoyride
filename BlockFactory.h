//
// Created by Athos Innocenti on 23/11/2018.
//

#ifndef FLYJOYRIDE_SIMPLEBLOCKFACTORY_H
#define FLYJOYRIDE_SIMPLEBLOCKFACTORY_H

#include "Block.h"

enum BlockType { PowerUpBlock, NormalBlock };

class BlockFactory {
public:
    BlockFactory();
    virtual ~BlockFactory();
    std::unique_ptr<Block> createBlock(BlockType type);

private:
    sf::Texture normalBlockTexture;
    sf::Texture powerUpBlockTexture;
};

#endif //FLYJOYRIDE_SIMPLEBLOCKFACTORY_H