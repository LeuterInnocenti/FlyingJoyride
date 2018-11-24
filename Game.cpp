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
const sf::Vector2f Game::speed = sf::Vector2f(0.7,0); // velocità dei blocchi
const float Game::creationRateNB = 1.4f;
const float Game::creationRatePUB = 14.7f;

Game::Game() : window("Joyride", sf::Vector2u (1080,720)), player(),
               playerClock(), normalBlockClock(), powerUpBlockClock() {
    reset();

    backgroundTexture.loadFromFile("Background.png");
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setScale(0.675,0.95);

    srand((unsigned)time(nullptr));
    setBlock();

    this->factory = factory;
}

Game::~Game() {
    blocks.clear();
}

void Game::update() {
    window.update();
    increaseScore();

    shoot();
    getPosBullet();

    movePlayer();
    if(player.getDeath()){
        // std::cout<<"Il tuo punteggio è: "<<score<<std::endl;
        window.setDone();
    }

    deleteBlock();
    collision();

    setBlock();
    moveBlock();
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
    player.render(*window.GetRenderWindow());
    for (auto &block : blocks)
        window.draw(*block); //non lo può fare perchè block non è un tipo grafico
    for(auto &b : bullets)
        window.draw(b);
    window.endDraw();
    //TO DO: stessa cosa per enemy
}

void Game::movePlayer() {
    player.setPlayerPosition(player.getPlayerPosition().x, player.getPlayerPosition().y + g);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        player.setPlayerPosition(player.getPlayerPosition().x, player.getPlayerPosition().y - jump);
    if(player.getPlayerPosition().y + player.getPlayerSize().y >= window.GetWindowSize().y - levelGround)
        player.setPlayerPosition(player.getPlayerPosition().x, window.GetWindowSize().y - player.getPlayerSize().y - levelGround);
    if(player.getPlayerPosition().y <= 0)
        player.setPlayerPosition(player.getPlayerPosition().x,0);
}

void Game::shoot() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && playerClock.getElapsedTime().asSeconds() >= shootTime) {
        createBullet();
        playerClock.restart();
    }
    moveBullet();
}

void Game::createBullet(){
    bullet.setRadius(10);
    bullet.setFillColor(sf::Color::Black);
    bullet.setPosition(player.getPlayerPosition().x+player.getPlayerSize().x, player.getPlayerPosition().y+player.getPlayerSize().y/2);
    bullets.emplace_back(sf::CircleShape(bullet));
}

void Game::moveBullet(){
    for(size_t j = 0; j < bullets.size(); ++j){
        bullets[j].move(bulletSpeed, 0);
        if(bullets[j].getPosition().x >= window.GetWindowSize().x + 2*player.getPlayerSize().x)
            bullets.erase(bullets.begin()+j);
    }
}

sf::FloatRect Game::getPosBullet() {
    sf::FloatRect bulletshape;
    for (int i = 0; i < bullets.size(); i++) {
        bulletshape = bullets[i].getGlobalBounds();
        ind = i;
    }
    return bulletshape;
}

void Game::eraseBullet() {
    bullets.erase(bullets.begin()+ind);
}

void Game::setBlock() {
    if (normalBlockClock.getElapsedTime().asSeconds() >= creationRateNB) {
        std::shared_ptr<Block> block = factory.createBlock(BlockType::NormalBlock);
        random();
        block->setPosition(sf::Vector2f(windowSize.x + 2*block->getSize().x,randomPos));
        blocks.emplace_back(block);
        normalBlockClock.restart();
    }
    else if (powerUpBlockClock.getElapsedTime().asSeconds() >= creationRatePUB) {
        std::shared_ptr<Block> block = factory.createBlock(BlockType::PowerUpBlock);
        random();
        block->setPosition(sf::Vector2f(windowSize.x + 2*block->getSize().x,randomPos));
        blocks.emplace_back(block);
        powerUpBlockClock.restart();
    }
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
    for(auto &i : blocks){
        /*
        std::shared_ptr<Block> test = std::shared_ptr<Block>(new class NormalBlock());
        test = dynamic_cast<>(i);
        */
        // se character interseca con block muore e gameover
        if(i->getGlobalBounds().intersects(player.getBound())) {
            player.gameOver(true);
        }
        // se bullet interseca un block viene eliminato
        if(i->getGlobalBounds().intersects(getPosBullet()))
            eraseBullet();
    }
}

//funzione randomica per settare coordinata Y del blocco
int Game::random() {
    int maxY = static_cast<int>(windowSize.y - (levelGround + block.getSize().x));
    randomPos = rand() % maxY;
    return randomPos;
}