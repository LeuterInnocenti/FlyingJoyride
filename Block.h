//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_BLOCK_H
#define FLYJOYRIDE_BLOCK_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
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

    bool Move();

    void EraseB(int index) { blocks.erase(blocks.begin() + index); }

    float Getrandomy() { return random; } // la X è prefissata e poi scorre

    float GetposBlock(int index);

private:
    int Random();
    int random;
    sf::Vector2i windowSize;
    sf::RectangleShape block;
    std::vector<sf::RectangleShape> blocks; //container
    std::vector<sf::RectangleShape>::iterator itr;
    static const sf::Vector2f speed;
    int blockSize = 3;

    Character &character;
    int range = 10000;
    const int scale = 5000; //distanza tra i blocchi
    int Bsize;
    int count = 0;
    const int distance = 300;

    const int pointzero = 0;
    bool repos = false;
    int frequency=0;
};


#endif //FLYJOYRIDE_BLOCK_H
