#pragma once

#include <stdio.h>
#include "States/StateBase.hpp"

class Game
{
    public:

        Game();

        /**
         * Starts the game
         */
        void run();

        /**
         * Switches the current states
         * @param state new state to switch to
         */
         void setCurrentState(StateBase *newState);

         inline sf::RenderWindow& getWindow() { return window; }

    virtual ~Game();

private:
        sf::RenderWindow window;
        StateBase *currentState = nullptr;


};
