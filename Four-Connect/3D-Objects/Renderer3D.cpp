#include "Renderer3D.h"

#include "../Board.h"

#include <cmath>

std::vector<Sphere3D> Renderer3D::getCirclesReadyToDraw(Board& board, float rotationY, float rotationZ, float cameraX, float cameraY)
{
    auto spheres = boardTo3DSpheres(board);
    applyCameraHeight(spheres, cameraY);
    rotateSphereList(spheres, rotationY, rotationZ);
    applyCameraDistance(spheres, cameraX);
    applyPerspective(spheres);
    sortByDepth(spheres);
    return spheres;
}

std::vector<Sphere3D> Renderer3D::boardTo3DSpheres(Board& board)
{
    std::vector<Sphere3D> spheres;

    //Corners
    spheres.push_back(Sphere3D(0, sf::Vector3f(-4, 0, -4)));
    spheres.push_back(Sphere3D(1, sf::Vector3f(4, 0, -4)));
    spheres.push_back(Sphere3D(2, sf::Vector3f(4, 0, 4)));
    spheres.push_back(Sphere3D(3, sf::Vector3f(-4, 0, 4)));
    //Spheres
    for (int x = 0; x < board.DIM_X; x++)
    for (int z = 0; z < board.DIM_Z; z++)
    for (int y = 0; y < board.DIM_Y; y++)
    {
        Board::Sphere sphere = board.getSphere(x, z, y);
        if (sphere == Board::Sphere::RedSphere)
        {
            spheres.push_back(Sphere3D(sf::Color::Red, sf::Vector3f(-1.5f + x, .9f * y, -1.5f + z)));
        }
        if (sphere == Board::Sphere::GreenSphere)
        {
            spheres.push_back(Sphere3D(sf::Color::Green, sf::Vector3f(-1.5f + x, .9f * y, -1.5f + z)));
        }
    }
    //Clickables
    for (int x = 0; x < board.DIM_X; x++)
    for (int z = 0; z < board.DIM_Z; z++)
    {
        spheres.push_back(Sphere3D(sf::Vector2i(x, z), sf::Vector3f(-1.5f + x, board.DIM_Y * .9f, -1.5f + z)));
    }

    return spheres;
}

void Renderer3D::applyCameraHeight(std::vector<Sphere3D>& spheres, float cameraY)
{
    for (Sphere3D& sphere : spheres)
        sphere.position += sf::Vector3f(0, -cameraY, 0);
}

void Renderer3D::rotateSphereList(std::vector<Sphere3D>& spheres, float rotationY, float rotationZ)
{
    for (Sphere3D& sphere : spheres)
    {
        //https://www.siggraph.org/education/materials/HyperGraph/modeling/mod_tran/3drota.htm
        //Y axis
        {
            sf::Vector3f newPos
            (
                sphere.position.z * sin(rotationY) + sphere.position.x * cos(rotationY),
                sphere.position.y,
                sphere.position.z * cos(rotationY) - sphere.position.x * sin(rotationY)
            );
            sphere.position = newPos;
        }
        //Z axis
        {
            sf::Vector3f newPos
            (
                sphere.position.x * cos(rotationZ) - sphere.position.y * sin(rotationZ),
                sphere.position.x * sin(rotationZ) + sphere.position.y * cos(rotationZ),
                sphere.position.z
            );
            sphere.position = newPos;
        }
    }
}

void Renderer3D::applyCameraDistance(std::vector<Sphere3D>& spheres, float cameraX)
{
    for (Sphere3D& sphere : spheres)
        sphere.position += sf::Vector3f(cameraX, 0, 0);
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
    return (a.position.x > b.position.x);
}
