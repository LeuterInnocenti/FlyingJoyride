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

    void Update(unsigned int wSizeY);

    bool GameOver(bool death);

    void Death();

    void createBullet();

    void moveBullet();

    bool GetDeath() { return death; }

    float GetPosx() { return player.getPosition().x; }

    sf::FloatRect GetBound() { return player.getGlobalBounds(); }

    void Render(sf::RenderWindow &window);

private:
    sf::Vector2i windowSize;

    sf::CircleShape bullet;
    std::vector<sf::CircleShape> bullets;
    sf::RectangleShape player;
    static const float g; //gravity
    static const float jump;
    bool death = false;

    int frequency = 0;
    int shootRate = 200;
};

#endif //FLYJOYRIDE_CHARACTER_H