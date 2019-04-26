#pragma once

#include <stdio.h>
#include "StateBase.hpp"

class Game
{
    public:

        Game();
        void run();

    private:
        sf::RenderWindow window;
        StateBase *currentState = nullptr;


};
