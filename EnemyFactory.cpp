//
// Created by Athos Innocenti on 04/12/2018.
//

#include "EnemyFactory.h"

EnemyFactory::EnemyFactory() {
    flyingEnemyTexture.loadFromFile("fenemy1.png");
    shootingEnemyTexture.loadFromFile("senemy1.png");
}

EnemyFactory::~EnemyFactory() {}

std::unique_ptr<Enemy> EnemyFactory::createEnemy(EnemyType type) {
    std::unique_ptr<Enemy> result = std::unique_ptr<Enemy>(new class Enemy());
    if (type == EnemyType::FlyingEnemy) {
        result->setTexture(flyingEnemyTexture);
        result->setScale(0.13, 0.13);
    } else if (type == EnemyType::ShootingEnemy) {
        result->setTexture(shootingEnemyTexture);
        result->setScale(0.13, 0.13);
        result->setCanShoot();
    }
    return result;
}