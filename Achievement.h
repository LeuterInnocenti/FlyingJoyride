//
// Created by Athos Innocenti on 10/12/2018.
//

#ifndef FLYJOYRIDE_ACHIEVEMENT_H
#define FLYJOYRIDE_ACHIEVEMENT_H
#define MAX_LINES 30
#define MAX_LINES_LEN 255

#include <fstream>
#include <iostream>

#include "Game.h"
#include "Observer.h"
#include "DisplayElement.h"

class Achievement : public Observer, public DisplayElement {
public:
    Achievement(Game *g);
    virtual ~Achievement();
    virtual void draw() override;
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;
    void loadAch();

protected:
    char string[MAX_LINES][MAX_LINES_LEN];
    unsigned int point, kill, a, b, c, d, e, f;
    Game* game;
};

#endif //FLYJOYRIDE_ACHIEVEMENT_H