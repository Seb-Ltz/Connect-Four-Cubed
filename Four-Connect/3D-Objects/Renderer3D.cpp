#include "Renderer3D.h"

#include "../Board.h"

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

}

void Renderer3D::applyCameraPos(std::vector<Sphere3D>& spheres, float cameraX)
{

}

void Renderer3D::applyPerspective(std::vector<Sphere3D>& spheres)
{

}

void Renderer3D::sortByDepth(std::vector<Sphere3D>& spheres)
{

}
