//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Window.h"

Window::Window() {
    Setup("Game", sf::Vector2u(400, 600));
}

Window::~Window() {
    Destroy();
};

Window::Window(const std::string &title, const sf::Vector2u &size) {
    Setup(title, size);
    //t.loadFromFile("background.png");
}

void Window::Setup(const std::string &title, const sf::Vector2u &size) {
    windowTitle = title;
    windowSize = size;
    isDone = false;
    window.setFramerateLimit(30);
    Create();
}

void Window::Update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            isDone = true;
    }
}

void Window::Create() {
    window.create({windowSize.x, windowSize.y}, windowTitle);
}

void Window::Destroy() {
    window.close();
}

void Window::BeginDraw() {
    window.clear(sf::Color::Black);
}

void Window::EndDraw() {
    window.display();
}

void Window::Draw(sf::Drawable &drawable) {
    window.draw(drawable);
}

sf::RenderWindow *Window::GetRenderWindow() {
    return &window;
}

sf::Vector2u Window::GetWindowSize() {
    return windowSize;
}