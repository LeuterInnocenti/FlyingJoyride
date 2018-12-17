//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Window.h"

Window::Window() {
    setup("Game", sf::Vector2u(400, 600));
}

Window::~Window() {
    destroy();
};

Window::Window(const std::string &title, const sf::Vector2u &size) {
    setup(title, size);
}

void Window::setup(const std::string &title, const sf::Vector2u &size) {
    windowTitle = title;
    windowSize = size;
    done = false;
    window.setFramerateLimit(30);
    create();
}

void Window::update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            done = true;
    }
}

void Window::create() {
    window.create({windowSize.x, windowSize.y}, windowTitle);
}

void Window::destroy() {
    window.close();
}

void Window::beginDraw() {
    window.clear(sf::Color::White);
}

void Window::endDraw() {
    window.display();
}

void Window::draw(sf::Drawable &drawable) {
    window.draw(drawable);
}

sf::RenderWindow *Window::getRenderWindow() {
    return &window;
}

sf::Vector2u Window::getWindowSize() {
    return windowSize;
}