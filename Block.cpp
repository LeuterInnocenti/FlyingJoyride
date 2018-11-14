//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Block.h"

const sf::Vector2f Block::speed = sf::Vector2f(0.7,0);
const float Block::creationRate = 1.4f;
const int Block::levelGround = 63;

Block::Block(sf::Vector2i windSize, Character &c) : windowSize (windSize), character(c), clock() {
    srand((unsigned)time(NULL));
    setBlock();
}

Block::~Block() {
    blocks.clear();
}

void Block::update() {
    deleteB();
    collision();
    if (clock.getElapsedTime().asSeconds() >= creationRate) {
        setBlock();
        clock.restart();
    }
}

void Block::setBlock() {
    block.setSize(sf::Vector2f(100, 100));
    block.setFillColor(sf::Color::Red);
    random();
    block.setPosition(windowSize.x + 2*block.getSize().x,randomPos);
    blocks.emplace_back(block);
}

void Block::move() {
    for (auto i = 0; i < blocks.size(); ++i) {
        blocks[i].move(-speed.x, speed.y);
    }
}

//funzione randomica per settare coordinata Y del blocco
int Block::random() {
    int maxY = static_cast<int>(windowSize.y - (levelGround + block.getSize().x));
    randomPos = rand() % maxY;
    return randomPos;
}

// se character interseca con block muore e gameover
void Block::collision() {
    for(int i = 0; i < blocks.size(); i++){
        if(blocks[i].getGlobalBounds().intersects(character.getBound())){
            character.gameOver(true);
        }
        if(blocks[i].getGlobalBounds().intersects(character.getPosBullet()))
            character.eraseBullet();
    }
}

void Block::deleteB() {
    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i].getPosition().x + blocks[i].getSize().x < 0) {
            eraseB(i); // se esce dallo schermo lo cancella
        }
    }
}

void Block::render(sf::RenderWindow &window) {
    for (const auto &block : blocks) {
        window.draw(block);
    }
}