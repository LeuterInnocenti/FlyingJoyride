//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Character.h"
#include <iostream>

const float Character::g = 0.7;
const float Character::jump = 1.8;

Character::Character(sf::Vector2i windSize) : windowSize(windSize) {
    player.setSize(sf::Vector2f(100, 50));
    player.setFillColor(sf::Color::Green);
    player.setPosition(50, 100);
}

Character::~Character() {}

void Character::Update(unsigned int wSizeY) {
    player.setPosition(player.getPosition().x, player.getPosition().y + g);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player.setPosition(player.getPosition().x, player.getPosition().y - jump);
    }
    if(player.getPosition().y+player.getSize().y>=wSizeY)
        player.setPosition(player.getPosition().x, wSizeY - player.getSize().y);
    if(player.getPosition().y<=0)
        player.setPosition(player.getPosition().x,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        frequency++;
    if(frequency > shootRate){
        createBullet();
        frequency=0;
    }
    moveBullet(bullets);
}

void Character::createBullet(){
    bullet.setRadius(10);
    bullet.setFillColor(sf::Color::White);
    bullet.setPosition(player.getPosition().x+player.getSize().x,player.getPosition().y+player.getSize().y/2);
    bullets.emplace_back(sf::CircleShape(bullet));
}

void Character::Shoot() {
    createBullet();
    bullets.emplace_back(sf::CircleShape(bullet));
    for(size_t j = 0; j < bullets.size(); ++j){
        bullets[j].move(0.5,0);
        if(bullets[j].getPosition().x >= windowSize.x)
            bullets.erase(bullets.begin()+j);
    }
    bullets.resize(2);
}

void Character::moveBullet(std::vector<sf::CircleShape> bullets){
    std::cout<<"numero proiettli= "<<bullets.size()<<std::endl;
    //nel container ci sono i proiettili ma non si muovono
    for(size_t j = 1; j < bullets.size(); ++j){
        bullets[j].move(0.5,0);
        if(bullets[j].getPosition().x >= windowSize.x)
            bullets.erase(bullets.begin()+j);
    }
    bullets.resize(2);
}

bool Character::GameOver(bool death){
    Death(); // setta Death a TRUE
    if(death) {
        player.setFillColor(sf::Color::White);
    }
    return death;
}

void Character::Death() {
    //if(death) { death = false;} else
    death = true;
}

void Character::Render(sf::RenderWindow &window) {
    window.draw(player);
    window.draw(bullet);
    for(const auto &b : bullets)
        window.draw(b);
}