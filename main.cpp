//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"

int main() {
    Game game;

    while(!game.GetWindow()->IsDone()){
        game.Render();
        game.Update();
    }

}