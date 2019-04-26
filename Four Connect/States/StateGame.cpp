#include "StateGame.hpp"

StateGame::StateGame()
    : circle(50)
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
