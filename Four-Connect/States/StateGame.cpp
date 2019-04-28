#include <iostream>
#include "StateGame.hpp"

#include "../3D-Objects/Renderer3D.h"
#include "../Game.hpp"

const float StateGame::CAMERA_DISTANCE = 6.f;
const float StateGame::CAMERA_HEIGHT = 2.f;

StateGame::StateGame(Game *game)
    : StateBase(game)
{
    ball.loadFromFile("ball.png");
    circle.setOutlineColor(sf::Color::Blue);
    //circle.setOutlineThickness(0.01f);
    circle.setTexture(&ball);

    plate = sf::VertexArray(sf::Quads, 4);

    lastMousePos = sf::Mouse::getPosition(game->getWindow());
    clicking = false;
}

void StateGame::handleEvents(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        if (isClickableSpherePointedAt)
            board.dropSphere(pointedClickableSphere.x, pointedClickableSphere.y, board.getPlayerTurn());
    }
    /*
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Num1:
            board.dropSphere(0, 0, board.getPlayerTurn());
        break;
        case sf::Keyboard::Num2:
            board.dropSphere(0, 1, board.getPlayerTurn());
        break;
        case sf::Keyboard::Num3:
            board.dropSphere(0, 2, board.getPlayerTurn());
        break;
        case sf::Keyboard::Num4:
            board.dropSphere(0, 3, board.getPlayerTurn());
        break;
        case sf::Keyboard::A:
            board.dropSphere(1, 0, board.getPlayerTurn());
        break;
        case sf::Keyboard::Z:
            board.dropSphere(1, 1, board.getPlayerTurn());
        break;
        case sf::Keyboard::E:
            board.dropSphere(1, 2, board.getPlayerTurn());
        break;
        case sf::Keyboard::R:
            board.dropSphere(1, 3, board.getPlayerTurn());
        break;
        case sf::Keyboard::Q:
            board.dropSphere(2, 0, board.getPlayerTurn());
        break;
        case sf::Keyboard::S:
            board.dropSphere(2, 1, board.getPlayerTurn());
        break;
        case sf::Keyboard::D:
            board.dropSphere(2, 2, board.getPlayerTurn());
        break;
        case sf::Keyboard::F:
            board.dropSphere(2, 3, board.getPlayerTurn());
        break;
        case sf::Keyboard::W:
            board.dropSphere(3, 0, board.getPlayerTurn());
        break;
        case sf::Keyboard::X:
            board.dropSphere(3, 1, board.getPlayerTurn());
        break;
        case sf::Keyboard::C:
            board.dropSphere(3, 2, board.getPlayerTurn());
        break;
        case sf::Keyboard::V:
            board.dropSphere(3, 3, board.getPlayerTurn());
        break;

        default:

            break;
        }
    }
    */
}

void StateGame::update(float dt)
{
    bool clickingNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    if (clicking && clickingNow)
    {
        rotationY += 0.005 * (sf::Mouse::getPosition(game->getWindow()).x - lastMousePos.x);
        rotationZ += 0.005 * (sf::Mouse::getPosition(game->getWindow()).y - lastMousePos.y);
        if (rotationZ >= 1.571f)
            rotationZ = 1.571f;
        if (rotationZ < 0)
            rotationZ = 0;
    }
    clicking = clickingNow;
    lastMousePos = sf::Mouse::getPosition(game->getWindow());
}

void StateGame::render(sf::RenderWindow &window)
{
    auto circles = Renderer3D::getCirclesReadyToDraw(board, rotationY, rotationZ, CAMERA_DISTANCE, CAMERA_HEIGHT);
    //THIS MUST BE RECODED

    //Test all spheres do determine the closest clickable one
    //Also do the plate corners
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    Sphere3D* closestClickableSphere = nullptr;
    int distance = 100000000;
    for (Sphere3D& sphere : circles)
    {
        if (sphere.type == Sphere3D::Corner)
        {
            plate[sphere.id] = sf::Vertex(sphere.get2dPos(), sf::Color(100, 70, 0));
        }
        if (sphere.type == Sphere3D::Clickable)
        {
            sf::Vector2i screenPos = window.mapCoordsToPixel(sphere.get2dPos());
            screenPos -= mousePos;
            int dist = screenPos.x * screenPos.x + screenPos.y * screenPos.y;
            if (dist < 100 && dist < distance)
            {
                closestClickableSphere = &sphere;
                distance = dist;
            }
        }
    }
    isClickableSpherePointedAt = !!closestClickableSphere;
    if (closestClickableSphere)
    {
        pointedClickableSphere = closestClickableSphere->gridPos;
        closestClickableSphere->color = sf::Color::White;
        closestClickableSphere->diameter *= 1.2f;
    }

    window.draw(plate);
    for (Sphere3D& sphere : circles)
    {
        circle.setFillColor(sphere.color);
        circle.setRadius(sphere.diameter / 2.f);
        circle.setOrigin(sf::Vector2f(sphere.diameter / 2.f, sphere.diameter / 2.f));
        circle.setPosition(sphere.get2dPos());
        window.draw(circle);
        //std::cout << circle.getPosition().x << ", " << circle.getPosition().y << ", radius : " << circle.getRadius() << "\n";
    }

}

StateGame::~StateGame()
{

}
