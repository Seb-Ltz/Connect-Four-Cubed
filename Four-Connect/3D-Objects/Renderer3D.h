#pragma once

#include <vector>

#include "Sphere3D.h"

class Board;

class Renderer3D
{
    public:
        /**
        Literally do everything
        @param board The board to render
        @param rotationY The Y axis rotation of the board
        @param rotationZ The Z axis rotation of the board
        @param cameraX The distance of the camera from the center of the board
        @return A list of Sphere3D, only use Z and Y coordinates to draw
        */
        static std::vector<Sphere3D> getCirclesReadyToDraw(Board& board, float rotationY, float rotationZ, float cameraX, float cameraY);

    private:
        static std::vector<Sphere3D> boardTo3DSpheres(Board& board);
        static void rotateSphereList(std::vector<Sphere3D>& spheres, float rotationY, float rotationZ);
        static void applyCameraPos(std::vector<Sphere3D>& spheres, float cameraX, float cameraY);
        static void applyPerspective(std::vector<Sphere3D>& spheres);
        static void sortByDepth(std::vector<Sphere3D>& spheres);

        static bool compareDepth(Sphere3D a, Sphere3D b);
};
