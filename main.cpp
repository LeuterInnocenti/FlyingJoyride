//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"
#include <chrono>
#include <thread>
#include <unistd.h>

int main() {

    Game game;

    int FPS = 30;
    int MS_PER_FRAME = 1 / FPS;

    while (!game.GetWindow()->isDone()) {
        game.render();
        game.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(MS_PER_FRAME));
    }
}