//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Block.h"

const sf::Vector2f Block::speed = sf::Vector2f(0.7,0);
const float Block::creationRate = 2.1f;

Block::Block(sf::Vector2i windSize, Character &c) : windowSize (windSize), character(c), clock() {
    srand((unsigned)time(NULL));
    SetBlock();
}

Block::~Block() {
    blocks.clear();
}

void Block::Update() {
    Delete();
    Collision();
    if (clock.getElapsedTime().asSeconds() >= creationRate) {
        SetBlock();
        clock.restart();
    }
}

void Block::SetBlock() {
    block.setSize(sf::Vector2f(100, 100));
    block.setFillColor(sf::Color::Red);
    Random();
    block.setPosition(1000,random);
    blocks.emplace_back(block);
}

void Block::Move() {
    for (auto i = 0; i < blocks.size(); ++i) {
        blocks[i].move(-speed.x, speed.y);
    }
}

//funzione randomica per settare coordinata Y del blocco
int Block::Random() {
    int maxY = windowSize.y - 100; //minY è 0
    random = rand() % maxY;
    return random;
}

// se character interseca con block muore e gameover
void Block::Collision() {
    for(int i = 0; i < blocks.size(); i++){
        if(blocks[i].getGlobalBounds().intersects(character.GetBound())){
            character.GameOver(true);
        }
        if(blocks[i].getGlobalBounds().intersects(character.getposBullet()))
            character.eraseBullet(i);
    }
}

void Block::Delete() {
    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i].getPosition().x + blocks[i].getSize().x < 0) {
            EraseB(i); // se esce dallo schermo lo cancella
        }
    }
}

void Block::Render(sf::RenderWindow &window) {
    for (const auto &block : blocks) {
        window.draw(block);
    }
}