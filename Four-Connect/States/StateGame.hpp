#pragma once

#include <stdio.h>
#include "StateBase.hpp"
#include "../Board.h"

class StateGame : public StateBase
{
    public:

        /**
         * Inits the assets for the state
         */
        StateGame(Game *game);

        void handleEvents(sf::Event event) override;

        void update(float dt) override;

        void render(sf::RenderWindow &window) override;

        virtual ~StateGame();

    private:

        sf::VertexArray plate;
        sf::CircleShape circle;
        sf::Texture ball;

        Board board;
        float rotationY = 0.f, rotationZ = 0.f;
        static const float CAMERA_DISTANCE;
        static const float CAMERA_HEIGHT;

        sf::Vector2i lastMousePos;
        bool clicking;

        sf::Vector2i pointedClickableSphere;
        bool isClickableSpherePointedAt;

};
