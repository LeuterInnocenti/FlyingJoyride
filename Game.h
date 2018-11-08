//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_GAME_H
#define FLYJOYRIDE_GAME_H

#include "Window.h"
#include "Map.h"
#include "Block.h"
#include "Character.h"
#include "SFML/Graphics.hpp"

class Game {
public:
    Game();
    ~Game();
    void Update();
    void HandleInput();
    void Render();

    Window *GetWindow() { return &window; };

private:
    Window window;
    Map map;
    Block block;
    Character character;
};

#endif //FLYJOYRIDE_GAME_H