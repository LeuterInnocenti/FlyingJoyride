//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_GAME_H
#define FLYJOYRIDE_GAME_H

#include <string>
#include "Block.h"
#include "Enemy.h"
#include "Window.h"
#include "Character.h"
#include "BlockFactory.h"
#include "EnemyFactory.h"
#include "SFML/Graphics.hpp"

class Game {
public:
    Game();
    ~Game();
    void update();
    void render();
    void handleText();
    void increaseScore();
    void reset(); // gestione testo e score
    Window *GetWindow() { return &window; };

    void shoot();
    void moveBullet();
    void movePlayer();
    void eraseEnemy();
    void eraseBullet();
    void createBullet();
    void moveEnemyBullet();
    void createEnemyBullet();

    void moveObject();
    void deleteObject();
    void eraseB(int index) { blocks.erase(blocks.begin() + index); }
    void eraseF(int index) { enemies.erase(enemies.begin() + index); }

    void collision();
    void createObjects();

    int randomPos();
    int randomCreation();

    // funzioni getter
    int getMaxY() const;
    static const float getG();
    static const float getJump();
    float getCreationRate() const;
    static const float getShootTime();
    static const float getLevelGround();
    static const float getBulletSpeed();
    const sf::Vector2f &getSpeed() const;
    const std::vector<sf::CircleShape> &getBullets() const;
    int getContainerSize() { return static_cast<int>(blocks.size()); };

private:
    int maxY;
    int randomY;

    Window window;
    sf::Clock speedClock;
    sf::Sprite background;
    sf::Vector2i windowSize;
    sf::Texture backgroundTexture;
    static const float levelGround;

    Character player;
    sf::Clock playerClock;
    sf::CircleShape bullet;
    sf::Texture playerTexture1;
    sf::Texture playerTexture2;
    sf::Texture playerTexture3;
    sf::Texture puPlayerTexture1;
    sf::Texture puPlayerTexture2;
    sf::Texture puPlayerTexture3;
    std::vector<sf::CircleShape> bullets;
    std::vector<sf::CircleShape> enemyBullets;

    int ind;
    int iter;
    int blockX;
    int counter;
    int tollerance;
    bool isCreated;
    bool isPowerUpOn;
    bool isEnemyCreated;
    float creationRate;
    static const float g;
    static const float jump;
    static const float shootTime;
    static const float bulletSpeed;
    static const float rateIncreaser;
    static const float speedIncreaser;

    Block block;
    sf::Vector2f speed;
    BlockFactory factoryB;
    sf::Clock objectClock;
    sf::Clock controlPowerUp;
    std::vector<std::unique_ptr<Block>> blocks;

    sf::Clock enemyClock;
    EnemyFactory factoryE;
    sf::Texture fEnemyTexture;
    sf::Texture sEnemyTexture;
    std::vector<std::unique_ptr<Enemy>> enemies;

    sf::Text text;
    sf::Font font;
    unsigned int score;
};

#endif //FLYJOYRIDE_GAME_H