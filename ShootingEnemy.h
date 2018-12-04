//
// Created by Athos Innocenti on 04/12/2018.
//

#ifndef FLYJOYRIDE_SHOOTINGENEMY_H
#define FLYJOYRIDE_SHOOTINGENEMY_H

#include "Enemy.h"

class ShootingEnemy : public Enemy {
public:
    ShootingEnemy();
    virtual ~ShootingEnemy();
    virtual void setEnemyTexture(sf::Texture texture);
};

#endif //FLYJOYRIDE_SHOOTINGENEMY_H