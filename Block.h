//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_BLOCK_H
#define FLYJOYRIDE_BLOCK_H

#include <SFML/Graphics.hpp>

class Block : public sf::Sprite {
public:
    Block() {}
    virtual ~Block() {}

protected:
    sf::Texture spriteTexture;
};

#endif //FLYJOYRIDE_BLOCK_H