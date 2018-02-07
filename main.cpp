#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

	// Start the game loop

	float seconds;
	sf::Clock clock;

	app.setFramerateLimit(60);

	float speedX=100.0, speedY=100.0;
    while (app.isOpen())
    {
        seconds = clock.getElapsedTime().asSeconds();
        cout << 1.0/seconds << endl;
        clock.restart();
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }


        sprite.move(speedX * seconds,speedY * seconds);

        if(sprite.getPosition().x + sprite.getLocalBounds().width > 800 || sprite.getPosition().x < 0) speedX=-speedX;
        if(sprite.getPosition().y + sprite.getLocalBounds().height > 600 || sprite.getPosition().y < 0) speedY=-speedY;

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);


        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
