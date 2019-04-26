#pragma once

#include <SFML/Graphics.hpp>

struct Sphere3D
{
    Sphere3D(sf::Color color, sf::Vector3f position, float diameter = .9f);

    const sf::Color color;
    sf::Vector3f position;
    float diameter;
};
