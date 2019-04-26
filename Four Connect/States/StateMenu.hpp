#pragma once

#include <stdio.h>
#include "StateBase.hpp"

class StateMenu : public StateBase {

    public:
        StateMenu(Game *game);

        void handleEvents(sf::Event event) override;

        void update(float dt) override;

        void render(sf::RenderWindow &window) override;

        ~StateMenu() override;
};