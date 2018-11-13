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
    void SetBlock();
    void Update();
    void Render(sf::RenderWindow &window);

    void Collision();
    void Delete();
    void Move();
    void EraseB(int index) { blocks.erase(blocks.begin() + index); }

private:
    int Random();
    int random;

    sf::Clock clock;
    sf::RectangleShape block;
    std::vector<sf::RectangleShape> blocks; //container

    Character &character;
    sf::Vector2i windowSize;

    static const float creationRate; // frequenza con cui vengono creati i blocchi
    static const sf::Vector2f speed;
};


#endif //FLYJOYRIDE_BLOCK_H
