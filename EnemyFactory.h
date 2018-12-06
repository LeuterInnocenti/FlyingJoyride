//
// Created by Athos Innocenti on 04/12/2018.
//

#ifndef FLYJOYRIDE_ENEMYFACTORY_H
#define FLYJOYRIDE_ENEMYFACTORY_H

#include "Enemy.h"
#include "FlyingEnemy.h"
#include "ShootingEnemy.h"

enum EnemyType { FlyingEnemy, ShootingEnemy };

class EnemyFactory {
public:
    EnemyFactory();
    ~EnemyFactory();
    std::unique_ptr<Enemy> createEnemy(EnemyType type);
};

#endif //FLYJOYRIDE_ENEMYFACTORY_H