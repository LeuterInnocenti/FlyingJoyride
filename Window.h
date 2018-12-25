//
// Created by Athos Innocenti on 30/10/2018.
//

#ifndef FLYJOYRIDE_WINDOW_H
#define FLYJOYRIDE_WINDOW_H

#include <SFML/Graphics.hpp>

class Window {
public:
    Window();
    Window(const std::string &title, const sf::Vector2u &size);
    ~Window();
    void beginDraw();
    void endDraw();
    void update();
    bool isDone() { return done; };
    sf::RenderWindow *getRenderWindow();
    sf::Vector2u getWindowSize();
    void draw(sf::Drawable &drawable);

private:
    void setup(const std::string &title, const sf::Vector2u &size);
    void destroy();
    void create();

    sf::RenderWindow window;
    sf::Vector2u windowSize;
    std::string windowTitle;
    bool done;
};

#endif //FLYJOYRIDE_WINDOW_H