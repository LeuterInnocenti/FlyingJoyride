//
// Created by Athos Innocenti on 04/12/2018.
//

#include "EnemyFactory.h"
#include "FlyingEnemy.h"
#include "ShootingEnemy.h"

EnemyFactory::EnemyFactory() {}

EnemyFactory::~EnemyFactory() {}

std::unique_ptr<Enemy> EnemyFactory::createEnemy(EnemyType type) {
    std::unique_ptr<Enemy> result;
    if (type == EnemyType::FlyingEnemy) {
        result = std::unique_ptr<Enemy>(new class FlyingEnemy());
    } else if (type == EnemyType::ShootingEnemy) {
        result = std::unique_ptr<Enemy>(new class ShootingEnemy());
    }
    return result;
}