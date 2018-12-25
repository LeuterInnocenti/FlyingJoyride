//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"
#include "Achievement.h"

#include <chrono>
#include <thread>
#include <time.h>

int main() {

    Game game;
    Achievement a = Achievement(&game);

    int FPS = 30;
    int MS_PER_FRAME = 1 / FPS;

    while (!game.GetWindow()->isDone()) {
        double start = clock() / CLOCKS_PER_SEC;
        game.render();
        game.update();
        std::this_thread::sleep_for(std::chrono::milliseconds((int) start + MS_PER_FRAME - (clock() / CLOCKS_PER_SEC)));
    }
}