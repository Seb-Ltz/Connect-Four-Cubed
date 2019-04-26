#include <iostream>
#include "StateGame.hpp"

#include "../3D-Objects/Renderer3D.h"

const float StateGame::CAMERA_DISTANCE = 6.f;

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
    auto circles = Renderer3D::getCirclesReadyToDraw(board, rotationY, rotationZ, CAMERA_DISTANCE);
    window.draw(circle);
}

StateGame::~StateGame()
{

}
