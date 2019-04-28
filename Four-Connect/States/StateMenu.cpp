#include <iostream>
#include "StateMenu.hpp"
#include "StateBase.hpp"
#include "StateGame.hpp"
#include "../Game.hpp"

StateMenu::StateMenu(Game *game) : StateBase(game)
{

}

void StateMenu::handleEvents(sf::Event event)
{
    if (/*event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X*/true)
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
