#include "Renderer3D.h"

#include "../Board.h"

#include <cmath>

std::vector<Sphere3D> Renderer3D::getCirclesReadyToDraw(Board& board, float rotationY, float rotationZ, float cameraX)
{
    auto spheres = boardTo3DSpheres(board);
    rotateSphereList(spheres, rotationY, rotationZ);
    applyCameraPos(spheres, cameraX);
    applyPerspective(spheres);
    sortByDepth(spheres);
    return spheres;
}

std::vector<Sphere3D> Renderer3D::boardTo3DSpheres(Board& board)
{
    std::vector<Sphere3D> spheres;

    for (int x = 0; x < board.DIM_X; x++)
    for (int z = 0; z < board.DIM_Z; z++)
    for (int y = 0; y < board.DIM_Y; y++)
    {
        Board::Sphere sphere = board.getSphere(x, z, y);
        if (sphere == Board::Sphere::RedSphere)
        {
            spheres.push_back(Sphere3D(sf::Color::Red, sf::Vector3f(x - 2, .9f * y, z - 2)));
        }
        if (sphere == Board::Sphere::GreenSphere)
        {
            spheres.push_back(Sphere3D(sf::Color::Green, sf::Vector3f(x - 2, .9f * y, z - 2)));
        }
    }

    return spheres;
}

void Renderer3D::rotateSphereList(std::vector<Sphere3D>& spheres, float rotationY, float rotationZ)
{
    for (Sphere3D& sphere : spheres)
    {
        //https://www.siggraph.org/education/materials/HyperGraph/modeling/mod_tran/3drota.htm
        //Y axis
        sf::Vector3f newPos
        (
            sphere.position.z * sin(rotationY) + sphere.position.x * cos(rotationY),
            sphere.position.y,
            sphere.position.z * cos(rotationY) - sphere.position.x * sin(rotationY)
        );
        sphere.position = newPos;
        //Z axis
        newPos = sf::Vector3f
        (
            sphere.position.x * cos(rotationZ) - sphere.position.y * cos(rotationY),
            sphere.position.x * sin(rotationZ) - sphere.position.y * cos(rotationZ),
            sphere.position.z
        );
        sphere.position = newPos;
    }
}

void Renderer3D::applyCameraPos(std::vector<Sphere3D>& spheres, float cameraX)
{
    for (Sphere3D& sphere : spheres)
        sphere.position -= sf::Vector3f(cameraX, 0, 0);
}

void Renderer3D::applyPerspective(std::vector<Sphere3D>& spheres)
{
    for (Sphere3D& sphere : spheres)
    {
        sf::Vector3f newPos
        (
            sphere.position.x,
            sphere.position.y / sphere.position.x,
            sphere.position.z / sphere.position.x
        );
        sphere.position = newPos;
        sphere.diameter /= sphere.position.x;
    }
}

void Renderer3D::sortByDepth(std::vector<Sphere3D>& spheres)
{
    std::sort(spheres.begin(), spheres.end(), compareDepth);
}

bool Renderer3D::compareDepth(Sphere3D a, Sphere3D b)
{
    return (a.position.x < b.position.x);
}
