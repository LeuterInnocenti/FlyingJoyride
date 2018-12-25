//
// Created by Athos Innocenti on 04/12/2018.
//

#ifndef FLYJOYRIDE_ENEMY_H
#define FLYJOYRIDE_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy : public sf::Sprite {
public:
    Enemy();
    virtual ~Enemy() {}
    bool getCanShoot() const;
    void setCanShoot();
    virtual float getEnemySpeedY();
    virtual void setEnemySpeedY(float speedY);

protected:
    bool canShoot;
    float enemySpeedY;
    sf::Texture spriteTexture;
};

#endif //FLYJOYRIDE_ENEMY_H