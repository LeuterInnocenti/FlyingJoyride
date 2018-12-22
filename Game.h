//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_GAME_H
#define FLYJOYRIDE_GAME_H

#include <list>
#include <string>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "BlockFactory.h"
#include "EnemyFactory.h"

#include "Subject.h"

#include "Block.h"
#include "Enemy.h"
#include "Window.h"
#include "Character.h"

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

    void fireAnimation();

    // funzioni getter
    int getMaxY() const;
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
    std::ofstream file;

    Window window;
    Character player;

    BlockFactory factoryB;
    EnemyFactory factoryE;

    std::list<Observer*> observers;

    sf::Music music;

    sf::Sound shootSound;
    sf::Sound enemyDeadSound;
    sf::Sound powerUpSound;

    sf::SoundBuffer shootBuffer;
    sf::SoundBuffer enemyDeadBuffer;
    sf::SoundBuffer powerUpBuffer;

    sf::Clock scoreClock;
    sf::Clock playerClock;
    sf::Clock fireClock;
    sf::Clock speedClock;
    sf::Clock objectClock;
    sf::Clock defectClock;
    sf::Clock controlPowerUp;
    sf::Clock enemyClock;

    sf::Vector2i windowSize;
    sf::Vector2f speed;
    sf::Vector2f oldSpeed;

    sf::CircleShape bullet;

    sf::Sprite background;
    sf::Sprite fireSprite;

    sf::Font font1;
    sf::Font font2;

    sf::Text scoreText;
    sf::Text gameOver;
    sf::Text achievementText;
    sf::Text text;

    sf::Texture backgroundTexture;

    sf::Texture playerTexture1;
    sf::Texture playerTexture2;
    sf::Texture puPlayerTexture1;
    sf::Texture puPlayerTexture2;
    sf::Texture dePlayerTexture1;
    sf::Texture dePlayerTexture2;

    sf::Texture fireTexture1;
    sf::Texture fireTexture2;

    sf::Texture fEnemyTexture;
    sf::Texture sEnemyTexture;

    std::vector<sf::CircleShape> bullets;
    std::vector<sf::CircleShape> enemyBullets;

    std::vector<std::unique_ptr<Block>> blocks;
    std::vector<std::unique_ptr<Enemy>> enemies;

    int maxY;
    int n;
    int count;
    int blockX;
    int counter;
    int textCount;
    int tollerance;

    float g;
    float jump;
    float creationRate;

    bool isCreated;
    bool isDefectOn;
    bool isPowerUpOn;
    bool speedPowerUp;
    bool isEnemyCreated;

    unsigned int score;
    unsigned int killed;

    static const int textSize;
    static const float shootTime;
    static const float bulletSpeed;
    static const float rateIncreaser;
    static const float speedIncreaser;
    static const float levelGround;
    static const unsigned int creationLimit;
    static const unsigned int speedMultiplier;
    static const float speedLimit;
};

#endif //FLYJOYRIDE_GAME_H