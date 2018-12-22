//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_BLOCK_H
#define FLYJOYRIDE_BLOCK_H

#include <SFML/Graphics.hpp>

class Block : public sf::Sprite {
public:
    Block();
    ~Block();
    void setIsPowerUpBlock();
    bool getIsPowerUpBlock() const;

protected:
    bool isPowerUp;
};

#endif //FLYJOYRIDE_BLOCK_H