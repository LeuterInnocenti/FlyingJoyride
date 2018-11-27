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
    sf::FloatRect getPosBullet();

    void deleteBlock();
    void moveBlock();
    void eraseB(int index) { blocks.erase(blocks.begin() + index); }

    void setBlock();
    void collision();

private:
    int randomCreation();
    int randomPos();
    int randomY;

    Window window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    static const float levelGround;

    Character player;
    sf::Clock playerClock;
    sf::CircleShape bullet;
    std::vector<sf::CircleShape> bullets;
    int ind;
    static const float g; // gravity
    static const float jump;
    static const float shootTime;
    static const float bulletSpeed;

    Block block;
    BlockFactory factory;
    std::vector<std::unique_ptr<Block>> blocks;
    sf::Clock blockClock;
    static const sf::Vector2f speed;
    int blockX;
    int countBlock;
    bool isCreated;

    static const float creationRate;  // frequenza con cui vengono creati i blocchi normali
    sf::Vector2i windowSize = sf::Vector2i (1080, 720);

    unsigned int score;
    sf::Text text;
    sf::Font font;
};

#endif //FLYJOYRIDE_GAME_H