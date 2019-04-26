#include <iostream>
#include "StateGame.hpp"

#include "../3D-Objects/Renderer3D.h"

const float StateGame::CAMERA_DISTANCE = 6.f;
const float StateGame::CAMERA_HEIGHT = 2.f;

StateGame::StateGame(Game *game)
    : StateBase(game)
{
    circle.setOutlineColor(sf::Color::Blue);
    circle.setOutlineThickness(0.01f);
}

void StateGame::handleEvents(sf::Event event)
{

}

void StateGame::update(float dt)
{
    rotationY += dt * 0.5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        rotationZ += dt * 0.5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        rotationZ -= dt * 0.5;
}

void StateGame::render(sf::RenderWindow &window)
{
    auto circles = Renderer3D::getCirclesReadyToDraw(board, rotationY, rotationZ, CAMERA_DISTANCE, CAMERA_HEIGHT);
    for (Sphere3D& sphere : circles)
    {
        circle.setFillColor(sphere.color);
        circle.setRadius(sphere.diameter / 2.f);
        circle.setOrigin(sf::Vector2f(sphere.diameter / 2.f, sphere.diameter / 2.f));
        circle.setPosition(sf::Vector2f(sphere.position.z, -sphere.position.y));
        window.draw(circle);
        //std::cout << circle.getPosition().x << ", " << circle.getPosition().y << ", radius : " << circle.getRadius() << "\n";
    }

}

StateGame::~StateGame()
{

}
