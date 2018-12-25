//
// Created by Athos Innocenti on 22/12/18.
//
#include "Enemy.h"

Enemy::Enemy() {
    canShoot = false;
}

bool Enemy::getCanShoot() const {
    return canShoot;
}

float Enemy::getEnemySpeedY() {
    return enemySpeedY;
}

void Enemy::setEnemySpeedY(float speedY) {
    enemySpeedY = speedY;
}

void Enemy::setCanShoot() {
    canShoot = true;
}