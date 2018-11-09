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

    int SetSize();

    void Update();

    void Render(sf::RenderWindow &window);

    void Collision();

    void Delete();

    void Move();

    void EraseB(int index) { blocks.erase(blocks.begin() + index); }

    float Getrandomy() { return random; }

    float GetposBlock(int index);

private:
    int Random();

    int random;
    int size;
    int maxSize = 150;

    sf::Clock clock;
    Character &character;
    sf::Vector2i windowSize;
    sf::RectangleShape block;
    std::vector<sf::RectangleShape> blocks; //container
    std::vector<sf::RectangleShape>::iterator itr;

    static const float creationRate; //frequenza con cui vengono creati i blocchi
    static const sf::Vector2f speed;

    const int distance = 300;
};


#endif //FLYJOYRIDE_BLOCK_H
