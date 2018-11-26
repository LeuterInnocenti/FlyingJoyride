//
// Created by Athos Innocenti on 21/11/2018.
//

#ifndef FLYJOYRIDE_POWERUPBLOCK_H
#define FLYJOYRIDE_POWERUPBLOCK_H

#include "Block.h"

class PowerUpBlock : public Block {
public:
    PowerUpBlock();
    virtual ~PowerUpBlock();
    static void activePowerUp();
};

#endif //FLYJOYRIDE_POWERUPBLOCK_H