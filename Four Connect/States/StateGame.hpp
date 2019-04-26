#pragma once

#include <stdio.h>
#include "StateBase.hpp"

class StateGame : public StateBase
{
    public:

        /**
         * Inits the assets for the state
         */
        StateGame();

        void handleEvents(sf::Event event) override;

        void update(float dt) override;

        void render(sf::RenderWindow &window) override;

    private:
        sf::CircleShape circle;

};
