//
// Created by Athos Innocenti on 10/12/2018.
//

#include "Achievement.h"
#include <iostream>

Achievement::Achievement(Game *g) : game(g), point(0), kill(0), a(0), b(0), c(0), d(0), e(0), f(0) {
    attach();
    loadAch();
}

Achievement::~Achievement() {
    detach();
}

// carica la stringa
void Achievement::loadAch() {
    std::ifstream in("achievements.txt");
    int j = 0;
    while (in)
        in.getline((string[j++]), MAX_LINES_LEN);
}

void Achievement::draw() {
    if (point >= 5 && a == 0) {
        game->setAchievementString(string[0]);
        a++;
    }
    if (point >= 50 && b == 0) {
        game->setAchievementString(string[1]);
        b++;
    }
    if (point >= 100 && c == 0) {
        game->setAchievementString(string[2]);
        c++;
    }
    if (kill >= 5 && d == 0) {
        game->setAchievementString(string[3]);
        d++;
    }
    if (kill >= 15 && e == 0) {
        game->setAchievementString(string[4]);
        e++;
    }
    if (point >= 200 && f == 0) {
        game->setAchievementString(string[5]);
        f++;
    }
}

void Achievement::update() {
    point = game->getScore();
    kill = game->getKilled();
    draw();
}

void Achievement::attach() {
    game->subscribe(this);
}

void Achievement::detach() {
    game->unsubscribe(this);
}