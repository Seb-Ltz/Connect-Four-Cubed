#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    sf::CircleShape shape(50);
    
    // set the shape color to green
    shape.setFillColor(sf::Color(100, 250, 50));

    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(shape);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
