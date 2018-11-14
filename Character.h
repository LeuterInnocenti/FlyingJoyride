//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_CHARACTER_H
#define FLYJOYRIDE_CHARACTER_H

#include <SFML/Graphics.hpp>

class Character {
public:
    Character(sf::Vector2i windSize);
    ~Character();
    void render(sf::RenderWindow &window);
    void update(unsigned int wSizeY);
    sf::FloatRect getBound() { return player.getGlobalBounds(); }
    bool gameOver(bool death);
    void death() { characterDeath = true; }
    bool getDeath() { return characterDeath; }

    // funzioni per gestire bullets
    void createBullet();
    void moveBullet();
    void eraseBullet();
    sf::FloatRect getPosBullet(); //per gestire interesezione tra bullet e block: bullet non deve oltrepassare un block

private:
    sf::Vector2i windowSize;
    sf::RectangleShape player;
    sf::Clock clock;
    bool characterDeath = false;
    int ind;

    sf::CircleShape bullet;
    std::vector<sf::CircleShape> bullets;
    static const float bulletSpeed;

    static const float g; //gravity
    static const float jump;
    static const float levelGround;
    static const float shootTime;
};

#endif //FLYJOYRIDE_CHARACTER_H