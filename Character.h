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
    bool gameOver(bool death);
    void render(sf::RenderWindow &window);
    void death() { characterDeath = true; }

    void setPlayerTexture(sf::Texture &pTexture);
    void setPlayerPosition(float posX, float posY){ player.setPosition(posX, posY); }
    
    bool getDeath() { return characterDeath; }
    sf::Vector2f getPlayerSize();
    sf::FloatRect getBound() { return player.getGlobalBounds(); }
    sf::Vector2f getPlayerPosition(){ return player.getPosition(); }
    
private:
    sf::Sprite player;
    bool characterDeath = false;
};

#endif //FLYJOYRIDE_CHARACTER_H