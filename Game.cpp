//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"
#include <iostream>

const float Game::shootTime = 1.3f;
const float Game::levelGround = 63.0f;
const float Game::bulletSpeed = 1.7f;
const float Game::g = 0.7;
const float Game::jump = 1.8;

Game::Game() : window("FlyingJoyride", sf::Vector2u(1080, 720)),
               countBlock(1), blockX(100), isCreated(false), creationRate(1.4f), speed(sf::Vector2f(0.7, 0)),
               windowSize(window.getWindowSize()),
               player(), playerClock(), blockClock(), speedClock(), factory() {
    reset();

    backgroundTexture.loadFromFile("Background.png");
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setScale(0.675, 0.95);

    srand((unsigned) time(nullptr));
    setBlock();

    maxY = static_cast<int>(windowSize.y - (levelGround + blockX));
}

Game::~Game() {
    blocks.clear();
}

void Game::update() {
    window.update();

    shoot();
    getBoundBullet();

    movePlayer();
    if (player.getDeath()) {
        // std::cout<<"Il tuo punteggio è: "<<score<<std::endl;
        window.setDone();
    }

    deleteBlock();
    collision();

    setBlock();
    moveBlock();

    if (speedClock.getElapsedTime().asSeconds() >= 10) {
        speed.x += 0.2;
        creationRate -= 0.1;
        speedClock.restart();
    }
}

void Game::increaseScore() {}

// gestione del testo
void Game::handleText() {
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setString("");
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(25);
    text.setPosition(15200, 50);
}

void Game::reset() {
    //handleText();
    score = 0;
}

void Game::render() {
    window.beginDraw();
    window.draw(background);
    player.render(*window.getRenderWindow());
    for (auto &block : blocks)
        window.draw(*block);
    for (auto &b : bullets)
        window.draw(b);
    window.endDraw();
    // TO DO: stessa cosa per enemy
}

bool Game::movePlayer() {
    player.setPlayerPosition(player.getPlayerPosition().x, player.getPlayerPosition().y + g);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        player.setPlayerPosition(player.getPlayerPosition().x, player.getPlayerPosition().y - jump);
    if (player.getPlayerPosition().y + player.getPlayerSize().y >= window.getWindowSize().y - levelGround)
        player.setPlayerPosition(player.getPlayerPosition().x,
                                 window.getWindowSize().y - player.getPlayerSize().y - levelGround);
    if (player.getPlayerPosition().y <= 0)
        player.setPlayerPosition(player.getPlayerPosition().x, 0);
}

void Game::shoot() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && playerClock.getElapsedTime().asSeconds() >= shootTime) {
        createBullet();
        playerClock.restart();
    }
    moveBullet();
}

void Game::createBullet() {
    bullet.setRadius(10);
    bullet.setFillColor(sf::Color::Black);
    bullet.setPosition(player.getPlayerPosition().x + player.getPlayerSize().x,
                       player.getPlayerPosition().y + player.getPlayerSize().y / 2);
    bullets.emplace_back(sf::CircleShape(bullet));
}

void Game::moveBullet() {
    for (size_t j = 0; j < bullets.size(); ++j) {
        bullets[j].move(bulletSpeed, 0);
        if (bullets[j].getPosition().x >= window.getWindowSize().x + 2 * player.getPlayerSize().x)
            bullets.erase(bullets.begin() + j);
    }
}

sf::FloatRect Game::getBoundBullet() {
    sf::FloatRect bulletshape;
    for (int i = 0; i < bullets.size(); i++) {
        bulletshape = bullets[i].getGlobalBounds();
        ind = i;
    }
    return bulletshape;
}

void Game::eraseBullet() {
    bullets.erase(bullets.begin() + ind);
}

void Game::setBlock() {
    if (blockClock.getElapsedTime().asSeconds() >= creationRate && countBlock % 6 == 0 && randomCreation() == 1) {
        std::unique_ptr<Block> block = factory.createBlock(BlockType::PowerUpBlock);
        randomPos();
        block->setPosition(sf::Vector2f(windowSize.x + 2 * block->getSize().x, randomY));
        blocks.emplace_back(move(block));
        isCreated = true;
        blockClock.restart();
        countBlock++;
    }
    if (blockClock.getElapsedTime().asSeconds() >= creationRate && !isCreated) {
        std::unique_ptr<Block> block = factory.createBlock(BlockType::NormalBlock);
        randomPos();
        block->setPosition(sf::Vector2f(windowSize.x + 2 * block->getSize().x, randomY));
        blocks.emplace_back(move(block));
        blockClock.restart();
        countBlock++;
    }
    isCreated = false;
}

void Game::moveBlock() {
    for (auto &i : blocks) {
        i->move(-speed.x, speed.y);
    }
}

void Game::deleteBlock() {
    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i]->getPosition().x + blocks[i]->getSize().x < 0) {
            eraseB(i); // se esce dallo schermo lo cancella
        }
    }
}

void Game::collision() {
    for (auto &i : blocks) {
        class NormalBlock *test = dynamic_cast<class NormalBlock *>(i.get());
        // se character interseca con block muore e gameover
        if (i->getGlobalBounds().intersects(player.getBound()) && test != nullptr)
            player.gameOver(true);
        // se character interseca PowerUpBlock si attiva il potenziamento
        if (i->getGlobalBounds().intersects(player.getBound()) && test == nullptr) {
            PowerUpBlock::activePowerUp();
            player.setColor(sf::Color::Green);
            // blocks.erase();
        }
        // se bullet interseca un block viene eliminato
        if (i->getGlobalBounds().intersects(getBoundBullet()))
            eraseBullet();
    }
}

// funzione randomica per settare coordinata Y del blocco
int Game::randomPos() {
    randomY = rand() % maxY;
    return randomY;
}

int Game::randomCreation() {
    return (rand() % 4);
}

// funzioni getter
const float Game::getShootTime() { return shootTime; }

const float Game::getLevelGround() { return levelGround; }

const float Game::getG() { return g; }

const float Game::getJump() { return jump; }

const float Game::getBulletSpeed() { return bulletSpeed; }

const sf::Vector2f &Game::getSpeed() const { return speed; }

float Game::getCreationRate() const { return creationRate; }

int Game::getMaxY() const { return maxY; }

const std::vector<sf::CircleShape> &Game::getBullets() const { return bullets; }