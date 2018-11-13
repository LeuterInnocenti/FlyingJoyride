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
    void Render(sf::RenderWindow &window);
    void Update(unsigned int wSizeY);
    sf::FloatRect GetBound() { return player.getGlobalBounds(); }
    bool GameOver(bool death);
    void Death() { death = true; }
    bool GetDeath() { return death; }

    // funzioni per gestire bullets
    void createBullet();
    void moveBullet();
    void eraseBullet(int j);
    sf::FloatRect getposBullet(); //per gestire interesezione tra bullet e block: bullet non deve oltrepassare un block

private:
    sf::Vector2i windowSize;
    sf::RectangleShape player;
    sf::Clock clock;
    bool death = false;

    sf::CircleShape bullet;
    std::vector<sf::CircleShape> bullets;
    static const float bulletSpeed;

    static const float g; //gravity
    static const float jump;
    static const float levelGround;
    static const float shootTime;
};

#endif //FLYJOYRIDE_CHARACTER_H