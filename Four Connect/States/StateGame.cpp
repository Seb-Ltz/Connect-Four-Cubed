#include <iostream>
#include "StateGame.hpp"

StateGame::StateGame(Game *game)
    : StateBase(game)
    , circle(50)
{
    // set the shape color to green
    circle.setFillColor(sf::Color(100, 250, 50));
}

void StateGame::handleEvents(sf::Event event)
{

}

void StateGame::update(float dt)
{

}

void StateGame::render(sf::RenderWindow &window)
{
    window.draw(circle);
}

StateGame::~StateGame()
{

}
