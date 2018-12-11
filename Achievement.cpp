//
// Created by Athos Innocenti on 10/12/2018.
//

#include "Achievement.h"
#include <iostream>

Achievement::Achievement(Game *g) : game(g), point(0), a(0), b(0), c(0) {
    attach();
    loadAch();
    font.loadFromFile("arial.ttf");
}

Achievement::~Achievement() {
    detach();
}

// carica la stringa indicata da string[index]
void Achievement::loadAch() {
    std::ifstream in("achievements.txt");
    int j = 0;
    while (in)
        in.getline((string[j++]), MAX_LINES_LEN);
}

void Achievement::draw() {
    achievement.setFont(font);
    achievement.setFillColor(sf::Color::White);
    achievement.setCharacterSize(25);
    achievement.setPosition(500, 6);
    if (point >= 7 && a == 0) {
        achievement.setString(string[0]);
        std::cout << string[0] << std::endl;
        a++;
    }
    if (point >= 50 && b == 0) {
        achievement.setString(string[1]);
        std::cout << string[1] << std::endl;
        b++;
    }
}

void Achievement::update() {
    point = game->getScore();
    draw();
}

void Achievement::attach() {
    game->subscribe(this);
}

void Achievement::detach() {
    game->unsubscribe(this);
}