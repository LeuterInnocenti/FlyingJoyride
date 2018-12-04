//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_GAME_H
#define FLYJOYRIDE_GAME_H

#include "Window.h"
#include "Block.h"
#include "Character.h"
#include "SFML/Graphics.hpp"

#include "BlockFactory.h"
#include <string>

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
    void eraseBullet();
    void createBullet();
    sf::FloatRect getBoundBullet();

    void deleteBlock();
    void moveBlock();
    void eraseB(int index) { blocks.erase(blocks.begin() + index); }

    void createBlock();
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
    static const float g; // gravità
    static const float jump;
    static const float shootTime;
    static const float bulletSpeed;
    static const float rateIncreaser;
    static const float speedIncreaser;

    Block block;
    sf::Vector2f speed;
    sf::Clock blockClock;
    BlockFactory factory;
    std::vector<std::unique_ptr<Block>> blocks;

    int blockX;
    int countBlock;
    bool isCreated;

    float creationRate;  // frequenza con cui vengono creati i blocchi normali
    sf::Vector2i windowSize;

    sf::Text text;
    sf::Font font;
    unsigned int score;
};

#endif //FLYJOYRIDE_GAME_H