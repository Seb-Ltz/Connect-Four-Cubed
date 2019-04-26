//
//  StateMenu.cpp
//  Four Connect
//
//  Created by Sébastien Letzelter on 26.04.19.
//  Copyright © 2019 Sébastien Letzelter. All rights reserved.
//

#include <iostream>
#include "StateMenu.hpp"
#include "StateBase.hpp"
#include "StateGame.hpp"
#include "Game.hpp"

StateMenu::StateMenu(Game *game) : StateBase(game)
{

}

void StateMenu::handleEvents(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X)
    {
        std::cout << "CHANGING STATE" << std::endl;
        game->setCurrentState(new StateGame(game));
    }
}

void StateMenu::update(float dt)
{

}

void StateMenu::render(sf::RenderWindow &window)
{

}

StateMenu::~StateMenu()
{

}
