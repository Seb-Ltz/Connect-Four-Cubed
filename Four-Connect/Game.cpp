#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "States/StateGame.hpp"
#include "States/StateMenu.hpp"

Game::Game()
    //Init the sfml window
    : window(sf::VideoMode(800, 800), "SFML window")
{

}

void Game::run()
{
    window.setVerticalSyncEnabled(true);
    //Temporary for 3D testing
    sf::View v = window.getView();
    v.setCenter(sf::Vector2f());
    v.setSize(sf::Vector2f(2, 2));
    window.setView(v);
    //init current state
    currentState = new StateMenu(this);

    //Clock for the dt
    sf::Clock clk = sf::Clock();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            //Send the event to the currentState
            currentState->handleEvents(event);
        }

        //Update the state
        currentState->update(clk.restart().asSeconds());

        // Clear screen
        window.clear();

        // Render the current state
        currentState->render(window);

        // Update the window
        window.display();
    }


}

void Game::setCurrentState(StateBase *newState)
{
    delete currentState;
    currentState = newState;
}

Game::~Game()
{
    delete currentState;
}
