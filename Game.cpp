//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"
#include <iostream>

Game::Game() : window ("Joyride", sf::Vector2u (1080, 720)),
               map(sf::Vector2f (500, 16000), 0, character),
               character(sf::Vector2i (1080, 720)),
               block(sf::Vector2i (1080, 720), character) {}

Game::~Game() {}

void Game::Update() {
    window.Update();
    map.Update();
    character.Update(window.GetWindowSize().y);
    block.Move();
    block.Update();
    block.Collision();
    if(character.GetDeath()){
        //std::cout<<"Il tuo punteggio è: "<<10<<std::endl; //stampa score: map.GetScore()
        //window.SetDone();
     }
}

void Game::HandleInput() {
    /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        character.Shoot();
    */
}

void Game::Render() {
    window.BeginDraw();
    character.Render(*window.GetRenderWindow());
    block.Render(*window.GetRenderWindow());
    /*int num = 0;
    while(num%5==0){
        block.SetBlock();
        num++;
    }
     */
    //map.Render(*window.GetRenderWindow());
    //TO DO: stessa cosa per enemy
    window.EndDraw();
}