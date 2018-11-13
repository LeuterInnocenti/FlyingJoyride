//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Character.h"

const float Character::g = 0.7;
const float Character::jump = 1.8;
const float Character::shootTime = 1.2f;
const float Character::levelGround = 63.0f;
const float Character::bulletSpeed = 0.5;

Character::Character(sf::Vector2i windSize) : windowSize(windSize), clock() {
    player.setSize(sf::Vector2f(100, 50));
    player.setFillColor(sf::Color::Blue);
    player.setPosition(50, 100);
}

Character::~Character() {}

void Character::Update(unsigned int wSizeY) {
    player.setPosition(player.getPosition().x, player.getPosition().y + g);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player.setPosition(player.getPosition().x, player.getPosition().y - jump);
    }
    if(player.getPosition().y+player.getSize().y>=wSizeY - levelGround)
        player.setPosition(player.getPosition().x, wSizeY - player.getSize().y - levelGround);
    if(player.getPosition().y<=0)
        player.setPosition(player.getPosition().x,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && clock.getElapsedTime().asSeconds() >= shootTime) {
        createBullet();
        clock.restart();
    }
    moveBullet();
}

void Character::createBullet(){
    bullet.setRadius(10);
    bullet.setFillColor(sf::Color::Black);
    bullet.setPosition(player.getPosition().x+player.getSize().x,player.getPosition().y+player.getSize().y/2);
    bullets.emplace_back(sf::CircleShape(bullet));
}

void Character::moveBullet(){
    for(size_t j = 0; j < bullets.size(); ++j){
        bullets[j].move(bulletSpeed,0);
        if(bullets[j].getPosition().x >= windowSize.x)
            bullets.erase(bullets.begin()+j);
    }
}

bool Character::GameOver(bool death){
    Death();
    if(death) {
        player.setFillColor(sf::Color::White);
    }
    return death;
}

void Character::Render(sf::RenderWindow &window) {
    window.draw(player);
    for(const auto &b : bullets)
        window.draw(b);
}

//restituisce il rect di bullet per intersect
sf::FloatRect Character::getposBullet() {
    sf::FloatRect bulletshape;
    for (auto &i : bullets) {
        bulletshape = i.getGlobalBounds();
    }
    return bulletshape;
}

void Character::eraseBullet(int j) {
    bullets.erase(bullets.begin()+j);
}