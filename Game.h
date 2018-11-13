//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_GAME_H
#define FLYJOYRIDE_GAME_H

#include "Window.h"
#include "Block.h"
#include "Character.h"
#include "SFML/Graphics.hpp"

class Game {
public:
    Game();
    ~Game();
    void Update();
    void Render();
    Window *GetWindow() { return &window; };
    void Reset(); //gestione testo e score
    void HandleText();
    void IncreaseScore();

private:
    Window window;
    Block block;
    Character character;

    sf::Texture backgroundTexture;
    sf::Sprite background;

    unsigned int score;
    sf::Text text;
    sf::Font font;
    sf::Vector2f WindowSize;
};

#endif //FLYJOYRIDE_GAME_H