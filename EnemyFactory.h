//
// Created by Athos Innocenti on 04/12/2018.
//

#ifndef FLYJOYRIDE_ENEMYFACTORY_H
#define FLYJOYRIDE_ENEMYFACTORY_H

#include "Enemy.h"

enum EnemyType { FlyingEnemy, ShootingEnemy };

class EnemyFactory {
public:
    EnemyFactory();
    virtual ~EnemyFactory();
    std::unique_ptr<Enemy> createEnemy(EnemyType type);

private:
    sf::Texture flyingEnemyTexture;
    sf::Texture shootingEnemyTexture;
};

#endif //FLYJOYRIDE_ENEMYFACTORY_H