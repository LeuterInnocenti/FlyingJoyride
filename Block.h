//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_BLOCK_H
#define FLYJOYRIDE_BLOCK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Character.h"

class Block {
public:
    Block(sf::Vector2i windSize, Character &c);
    ~Block();
    void setBlock();
    void update();
    void render(sf::RenderWindow &window);

    void collision();
    void deleteB();
    void move();
    void eraseB(int index) { blocks.erase(blocks.begin() + index); }

private:
    int random();
    int randomPos;

    sf::Clock clock;
    sf::RectangleShape block;
    std::vector<sf::RectangleShape> blocks; //container

    Character &character;
    sf::Vector2i windowSize;

    static const float creationRate; // frequenza con cui vengono creati i blocchi
    static const int levelGround;
    static const sf::Vector2f speed;
};


#endif //FLYJOYRIDE_BLOCK_H
