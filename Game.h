//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_GAME_H
#define FLYJOYRIDE_GAME_H

#include <list>
#include <string>
#include <fstream>

#include "Block.h"
#include "Enemy.h"
#include "Window.h"
#include "Subject.h"
#include "Character.h"
#include "BlockFactory.h"
#include "EnemyFactory.h"
#include "SFML/Graphics.hpp"

class Game : public Subject {
public:
    Game();
    ~Game();
    void update();
    void render();
    void handleText();
    Window *GetWindow() { return &window; };

    void shoot();
    void moveBullet();
    void movePlayer();
    void createBullet();
    void moveEnemyBullet();
    void createEnemyBullet();

    void collision();
    void createObjects();

    void moveObject();
    void deleteObject();

    int randomPos();
    int randomCreation();
    int randomPowerUp();

    // funzioni getter
    int getMaxY() const;
    int getRandomY() const;
    bool getIsPowerUpOn() const;
    int getBlocksContainerSize();
    unsigned int getScore() const;
    float getCreationRate() const;
    int getBulletsContainerSize();
    int getEnemiesContainerSize();
    unsigned int getKilled() const;
    static const float getShootTime();
    static const float getLevelGround();
    static const float getBulletSpeed();
    const sf::Vector2f &getSpeed() const;
    int getEnemiesBulletsContainerSize();
    static const float getRateIncreaser();
    static const float getSpeedIncreaser();
    const sf::Vector2i &getWindowSize() const;
    const std::vector<sf::CircleShape> &getBullets() const;

    // funzioni per observer
    void setScore(unsigned int score);
    void setKilled(unsigned int killed);
    void notify() override;
    void unsubscribe(Observer *o) override;
    void subscribe(Observer *o) override;
    void setAchievementString(sf::String string);

private:
    int maxY;
    int randomY;

    Window window;
    sf::Clock scoreClock;
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
    sf::Texture dePlayerTexture1;
    sf::Texture dePlayerTexture2;
    sf::Texture dePlayerTexture3;
    std::vector<sf::CircleShape> bullets;
    std::vector<sf::CircleShape> enemyBullets;

    int n;
    float g;
    float jump;
    int blockX;
    int counter;
    int tollerance;
    bool isCreated;
    bool isDefectOn;
    bool isPowerUpOn;
    float creationRate;
    bool isEnemyCreated;
    static const int textSize;
    static const float shootTime;
    static const float bulletSpeed;
    static const float rateIncreaser;
    static const float speedIncreaser;

    sf::Vector2f speed;
    BlockFactory factoryB;
    sf::Clock objectClock;
    sf::Clock defectClock;
    sf::Clock controlPowerUp;
    std::vector<std::unique_ptr<Block>> blocks;

    sf::Clock enemyClock;
    EnemyFactory factoryE;
    sf::Texture fEnemyTexture;
    sf::Texture sEnemyTexture;
    std::vector<std::unique_ptr<Enemy>> enemies;

    sf::Font font;
    sf::Text text;
    sf::Text scoreText;
    sf::Text achievementText;
    unsigned int score;
    unsigned int killed;
    std::list<Observer*> observers;

    std::ofstream file;
};

#endif //FLYJOYRIDE_GAME_H