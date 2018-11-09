//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_GAME_H
#define FLYJOYRIDE_GAME_H

#include "Window.h"
#include "Block.h"
#include "Character.h"
#include "SFML/Graphics.hpp"
#include <memory>

class Game {
public:
    Game();

    ~Game();

    void Update();

    void HandleInput();

    void Render();

    Window *GetWindow() { return &window; };

    //gestione testo e score
    void Reset();

    void HandleText();

    void IncreaseScore();

    float GetScore() { return static_cast<int> (score); }

    float Gettextposition() { return text.getPosition().x; }

    void Render(sf::RenderWindow &window);

    float GetviewCenter() { return view.getCenter().x; }

private:
    Window window;
    Block block;
    Character character;

    //aggiunge riga di testo
    void Addstring(std::string message);

    unsigned int score;
    //float speed;
    sf::View view;
    sf::Text text;
    sf::Font font;
    sf::Vector2f WindowSize;
};

#endif //FLYJOYRIDE_GAME_H