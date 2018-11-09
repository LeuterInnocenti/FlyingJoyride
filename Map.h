//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_MAP_H
#define FLYJOYRIDE_MAP_H

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Block.h"
#include <memory>

class Map {
public:
    Map(sf::Vector2f WindS, unsigned int score, Character &character);

    //~Map();

    //void IncreaseScore();

    //void Reset();

    //void HandleText();

    //void Update();

    //void Render(sf::RenderWindow &window);

    //float GetScore() { return static_cast<int> (score); }

    //float Gettextposition() { return text.getPosition().x; }

    //float GetviewCenter() { return view.getCenter().x; }

private:

    //void Addstring(std::string message);

    //unsigned int score;
    //float speed;
    //sf::View view;
    //sf::Text text;
    //sf::Font font;
    //sf::Vector2f WindowSize;
    //Character &character;
};

#endif //FLYJOYRIDE_MAP_H
