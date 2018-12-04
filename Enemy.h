//
// Created by Athos Innocenti on 04/12/2018.
//

#ifndef FLYJOYRIDE_ENEMY_H
#define FLYJOYRIDE_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy : public sf::Sprite {
public:
    Enemy() {}
    virtual ~Enemy() {}
    virtual float getEnemySpeedY(){return enemySpeedY;};
    virtual void setEnemySpeedY(float speedY) {enemySpeedY = speedY;};

protected:
    sf::Texture spriteTexture;
    float enemySpeedY;
};

#endif //FLYJOYRIDE_ENEMY_H