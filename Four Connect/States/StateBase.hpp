#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>

class StateBase
{
    public:
        /**
         * Handles the events of the state
         * @param event Event, that will be handled
         */
        virtual void handleEvents(sf::Event event) = 0;

        /**
         * Updates the state
         * @param dt delta time, in seconds
         */
        virtual void update(float dt) = 0;

        /**
         * Renders the state
         * @param window reference of the RenderWindow
         */
        virtual void render(sf::RenderWindow &window) = 0;
};
