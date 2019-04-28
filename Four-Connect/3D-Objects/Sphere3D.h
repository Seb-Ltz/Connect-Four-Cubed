#pragma once

#include <SFML/Graphics.hpp>

struct Sphere3D
{
    enum Type
    {
        Sphere,
        Corner,
        Clickable
    };

    Type type;

    Sphere3D(sf::Color color, sf::Vector3f position);    //Sphere
    Sphere3D(int id, sf::Vector3f position);                    //Corner
    Sphere3D(sf::Vector2i posGrid, sf::Vector3f position);      //Clickable

    inline sf::Vector2f get2dPos() const { return sf::Vector2f(position.z, -position.y); }

    float diameter;
    sf::Color color;
    sf::Vector3f position;

    sf::Vector2i gridPos;   //For clickables
    int id;                 //For corners

};
