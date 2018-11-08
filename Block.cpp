//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Block.h"
#include <chrono>
#include <iostream>

const sf::Vector2f Block::speed = sf::Vector2f(0.7,0);

Block::Block(sf::Vector2i windSize, Character &c) : windowSize (windSize), character(c) {
    SetBlock();
}

Block::~Block() {
    blocks.clear();
}

void Block::Update() {
    //Delete();
    Collision();
    frequency++;
    if(frequency > 250){
        SetBlock();
        frequency=0;
    }
}

void Block::SetBlock() {
    block.setSize(sf::Vector2f (100, 100));
    block.setFillColor(sf::Color::Red);
    Random();
    block.setPosition(1000,random * blockSize);
    blocks.emplace_back(block);
    itr = blocks.begin();
    blocks.insert(itr+1,block);
    //range -= scale;
    //Bsize = rand() % 8 + 1; //varia la posizione
    //count += 1;
}

bool Block::Move() {
    for(auto i = 0; i < blocks.size(); ++i) {
        blocks[i].move(-speed.x, speed.y);
        if (blocks[i].getPosition().x >= windowSize.x) {
            blocks[i].setPosition(pointzero, blocks[i].getPosition ().y);
            repos = true;
        }//SE BLOCCO MAGGIORE DELLA GRANDEZZA  MAPPA TORNA ALLO ZERO
    }
    return repos;
}

int Block::Random() { //funzione randomica per settare coordinata Y del blocco
    srand((unsigned)time(NULL));
    int maxY = (windowSize.y / blockSize) - 2;
    random = rand() % maxY + 1;
    return random;
}

void Block::Collision() { // se character interseca con block muore e gameover
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