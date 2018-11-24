//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_GAME_H
#define FLYJOYRIDE_GAME_H

#include "Window.h"
#include "Block.h"
#include "Character.h"
#include "SFML/Graphics.hpp"

#include "SimpleBlockFactory.h"
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
    void reset(); //gestione testo e score

    void shoot();
    void moveBullet();
    void movePlayer();
    void eraseBullet();
    void createBullet();
    sf::FloatRect getPosBullet();

    void deleteBlock();
    void moveBlock();
    void eraseB(int index) { blocks.erase(blocks.begin() + index); }

    void setBlock();
    void collision();

private:
    int random();
    int randomPos;

    Window window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    static const float levelGround;

    Character player;
    sf::Clock playerClock;
    sf::CircleShape bullet;
    std::vector<sf::CircleShape> bullets;
    int ind;
    static const float g; //gravity
    static const float jump;
    static const float shootTime;
    static const float bulletSpeed;

    Block block;
    std::vector<std::shared_ptr<Block>> blocks;
    sf::Clock normalBlockClock;
    sf::Clock powerUpBlockClock;
    static const sf::Vector2f speed;

    static const float creationRateNB;  // frequenza con cui vengono creati i blocchi normali
    static const float creationRatePUB; // frequenza con cui vengono creati i blocchi Powerup
    sf::Vector2i windowSize = sf::Vector2i (1080, 720);

    unsigned int score;
    sf::Text text;
    sf::Font font;

    SimpleBlockFactory factory;
    std::string type;
};

#endif //FLYJOYRIDE_GAME_H