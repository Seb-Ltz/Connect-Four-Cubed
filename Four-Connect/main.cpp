#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "BordTest.hpp"

int main(int, char const**)
{
    //Test the bord
    BordTest bordTest;
//    bordTest.init();
    bordTest.debugTest();

    Game game;
    game.run();

    return EXIT_SUCCESS;
}
