#include "Sphere3D.h"


Sphere3D::Sphere3D(sf::Color color, sf::Vector3f position) :         //Sphere
    type(Sphere3D::Sphere),
    diameter(.9f),
    color(color),
    position(position)
{

}
Sphere3D::Sphere3D(int id, sf::Vector3f position) :                    //Corner
    type(Corner),
    diameter(.2f),
    color(sf::Color::Transparent),
    position(position),
    id(id)
{

}
Sphere3D::Sphere3D(sf::Vector2i posGrid, sf::Vector3f position) :      //Clickable
    type(Clickable),
    diameter(.2f),
    color(sf::Color(255, 255, 255, 100)),
    position(position),
    gridPos(posGrid)
{

}
