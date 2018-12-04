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
    Window *GetWindow() { return &window; };
    void reset(); // gestione testo e score

    void shoot();
    void moveBullet();
    void movePlayer();
    void eraseEnemy();
    void eraseBullet();
    void createBullet();
    sf::FloatRect getBoundBullet();
    sf::FloatRect getBoundEnemy();

    void deleteObject();
    void moveObject(); //poi diventa moveObject
    void eraseB(int index) { blocks.erase(blocks.begin() + index); }
    void eraseF(int index) { enemies.erase(enemies.begin() + index); }

    void createObjects();
    void collision();

    int randomCreation();
    int randomPos();

    // funzioni getter
    static const float getShootTime();
    static const float getLevelGround();
    static const float getG();
    static const float getJump();
    static const float getBulletSpeed();
    int getMaxY() const;
    const sf::Vector2f &getSpeed() const;
    float getCreationRate() const;
    int getContainerSize() { return static_cast<int>(blocks.size()); };
    const std::vector<sf::CircleShape> &getBullets() const;

private:
    int maxY;
    int randomY;

    Window window;
    sf::Clock speedClock;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    static const float levelGround;

    Character player;
    sf::Clock playerClock;
    sf::CircleShape bullet;
    sf::Texture playerTexture1;
    sf::Texture playerTexture2;
    sf::Texture playerTexture3;
    std::vector<sf::CircleShape> bullets;

    int ind;
    int iter;
    static const float g; // gravità
    static const float jump;
    static const float shootTime;
    static const float bulletSpeed;
    static const float rateIncreaser;
    static const float speedIncreaser;

    Block block;
    sf::Vector2f speed;
    sf::Clock objectClock;
    BlockFactory factoryB;
    std::vector<std::unique_ptr<Block>> blocks;

    EnemyFactory factoryE;
    sf::Texture fEnemyTexture1;
    std::vector<std::unique_ptr<Enemy>> enemies;

    int blockX;
    int counter;
    bool isCreated;

    float creationRate;  // frequenza con cui vengono creati i blocchi normali
    sf::Vector2i windowSize;

    sf::Text text;
    sf::Font font;
    unsigned int score;
};

#endif //FLYJOYRIDE_GAME_H