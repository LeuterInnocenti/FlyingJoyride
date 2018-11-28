//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_CHARACTER_H
#define FLYJOYRIDE_CHARACTER_H

#include <SFML/Graphics.hpp>

class Character {
public:
    Character();
    ~Character();
    void render(sf::RenderWindow &window);

    sf::FloatRect getBound() { return player.getGlobalBounds(); }
    bool gameOver(bool death);
    void death() { characterDeath = true; }
    bool getDeath() { return characterDeath; }

    sf::Vector2f getPlayerSize(){return player.getSize();}
    sf::Vector2f getPlayerPosition(){return player.getPosition();}
    void setPlayerPosition(float posX, float posY){player.setPosition(posX, posY);}

    void setColor(sf::Color color) { player.setFillColor(color); }
    sf::Color getColor() { return player.getFillColor(); }

private:
    sf::RectangleShape player;
    bool characterDeath = false;
};

#endif //FLYJOYRIDE_CHARACTER_H