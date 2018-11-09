//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Block.h"
#include <ctime>
#include <iostream>

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
    //Delete();
    Collision();
    if(clock.getElapsedTime().asSeconds() >= creationRate){
        SetBlock();
        clock.restart();
    }
}

void Block::SetBlock() {
    SetSize();
    block.setSize(sf::Vector2f(size, size));
    block.setFillColor(sf::Color::Red);
    Random();
    block.setPosition(1000,random);
    blocks.emplace_back(block);
}

int Block::SetSize(){
    size = rand() % maxSize + 100;
    return size;
}

void Block::Move() {
    for(auto i = 0; i < blocks.size(); ++i) {
        blocks[i].move(-speed.x, speed.y);
    }
}

//funzione randomica per settare coordinata Y del blocco
int Block::Random() {
    int maxY = windowSize.y-100; //minY è 0
    random = rand() % maxY;
    return random;
}

// se character interseca con block muore e gameover
void Block::Collision() {
    for(auto &i : blocks){
        if(i.getGlobalBounds().intersects(character.GetBound())){
            character.GameOver(true);
        }
    }
}

//NON FUNZIONA
void Block::Delete(){
    for(int i = 0; i < blocks.size(); ++i){
        if(blocks[i].getPosition().x > character.GetPosx() + distance){
            EraseB(i); // se esce dallo schermo lo cancella
        }
    }
}

float Block::GetposBlock(int index) {
    return blocks[index].getPosition().y;
}

void Block::Render(sf::RenderWindow &window) {
    for (const auto &block : blocks) {
        window.draw(block);
    }
}