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
    void BeginDraw();
    void EndDraw();
    void Update();
    bool IsDone() { return isDone; };
    sf::RenderWindow *GetRenderWindow();
    sf::Vector2u GetWindowSize();
    void Draw(sf::Drawable &drawable);
    void SetDone() { isDone = true; }

private:
    void Setup(const std::string &title, const sf::Vector2u &size);
    void Destroy();
    void Create();

    sf::RenderWindow window;
    sf::Texture t;
    sf::Text text;
    bool isDone;
    sf::Vector2u windowSize;
    std::string windowTitle;

};

#endif //FLYJOYRIDE_WINDOW_H
