#include <iostream>
#include "Board.h"

const int Board::DIM_X = 4;
const int Board::DIM_Z = 4;
const int Board::DIM_Y = 4;

const int Board::TO_CONNECT = 4;

Board::Board() :
    m_maxSpheres(DIM_X * DIM_Z * DIM_Y)
{
    m_spheres = new Sphere[m_maxSpheres];
    reset();
}

Board::~Board()
{
    delete[] m_spheres;
}

void Board::reset()
{
    m_sphereCount = 0;
    m_gameState = GameState::Playing;
    m_playerTurn = PlayerColor::PlayerRed;

    for (int x = 0; x < DIM_X; x++)
    for (int z = 0; z < DIM_Z; z++)
    for (int y = 0; y < DIM_Y; y++)
    {
        m_spheres[x * DIM_Z * DIM_Y + z * DIM_Y + y] = Sphere::NoSphere;
    }
}

bool Board::isThereSpace(int x, int z) const
{
    Sphere* column = getColumn(x, z);
    if (column == nullptr)  //Out of bounds
        return false;
    bool theresSpace = false;
    for (int i = 0; i < DIM_Y; i++)
    {
        if (column[i] == Sphere::NoSphere)
        {
            theresSpace = true;
            break;
        }
    }
    return theresSpace;
}

Board::DropResult Board::dropSphere(int x, int z, PlayerColor color)
{
    if (m_gameState != GameState::Playing)
        return DropResult::WrongGameState;

    if (color != m_playerTurn)
        return DropResult::NotYourTurn;

    Sphere* column = getColumn(x, z);

    if (column == nullptr)
        return DropResult::OutOfBounds;

    if (!isThereSpace(x, z))
        return DropResult::NotEnoughSpace;

    int y = 3; //CALCULATE THE PLACE TO PUT THE SPHERE

    //Save the sphere that got dropped
    if(color == PlayerColor::PlayerRed)
        setSphereAt(x, z, y, Sphere::RedSphere);
    if(color == PlayerColor::PlayerGreen)
        setSphereAt(x, z, y, Sphere::GreenSphere);

    m_sphereCount++;

    if (checkConnection(x, z, y))
        return DropResult::DroppedAndVictory;

    return Dropped;
}

Board::Sphere* const Board::getColumn(int x, int z) const
{
    if (x < 0 || z < 0 || x >= DIM_X || z >= DIM_Z)
        return nullptr; //Out of bounds

//    return m_spheres + x * DIM_Z * DIM_Y + z * DIM_Y;
    std::cout << x << " - " << z << " :  = ";
    for(int i = 0; i < m_maxSpheres; i++) {
        std::cout << *(m_spheres + i) << " ";
    }
    std::cout << std::endl;

    return m_spheres + x + oDIM_X * (DIM_Z * z);
    //x + WIDTH * (y + DEPTH * z)
}

Board::Sphere Board::getSphere(int x, int z, int y) const
{
    Sphere* column = getColumn(x, z);

    if (column == nullptr || y >= DIM_Y)  //Out of bounds
        return Sphere::NoSphere;

    return column[y];
}

bool Board::checkConnection(int x, int z, int y) const
{
    //TODO: Check if a sphere placed at theres coordinates causes a win
    return false;
}

void Board::setSphereAt(int x, int z, int y, Sphere sphere) {
    m_spheres[x * DIM_Z * DIM_Y + z * DIM_Y] = sphere;
}


