#include <iostream>
#include <SFML/Graphics.hpp>

#include <iterator>
#include "TextureHandler.h"
#include "GameObjectHandler.h"
#include "Tower.h"

using namespace std;

class TableHandler : public GameObjectHandler{

    int id=0;

    vector<GameObject> items;


    void add( GameObject go ){
        items.push_back( go );
    }

    vector<GameObject> &objects(){
        return items;
    }

};


int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display

	TextureHandler textureHandler;

	textureHandler.loadTexture( "test", "cb.bmp" );

	sf::Sprite sprite(textureHandler.getTexture( "test" ));


	GameObjectHandler *gameObjectHandler = new TableHandler();

	gameObjectHandler->add( GameObject( 250, 250, textureHandler.getTexture( "test" ) ) );

	gameObjectHandler->add( GameObject( 350, 250, textureHandler.getTexture( "test" ) ) );

	gameObjectHandler->add( GameObject( 250, 350, textureHandler.getTexture( "test" ) ) );

	gameObjectHandler->add( GameObject( 350, 350, textureHandler.getTexture( "test" ) ) );

	// Start the game loop

	float seconds;
	sf::Clock clock;

	app.setFramerateLimit(60);

	float speedX=100.0, speedY=100.0;
    while (app.isOpen())
    {
        seconds = clock.getElapsedTime().asSeconds();
       // cout << 1.0/seconds << endl;
        clock.restart();
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        for( GameObject &go : gameObjectHandler->objects()){
            go.action( seconds );
        }




        /*
        sprite.move(speedX * seconds,speedY * seconds);

        if(sprite.getPosition().x + sprite.getLocalBounds().width > 800 || sprite.getPosition().x < 0) speedX=-speedX;
        if(sprite.getPosition().y + sprite.getLocalBounds().height > 600 || sprite.getPosition().y < 0) speedY=-speedY;
*/
        sprite.rotate(10.0 * seconds);


        // Clear screen
        app.clear();

        // Draw the sprite

        app.draw(sprite);
        for( GameObject &go : gameObjectHandler->objects()){
            go.draw( app );
        }

        // Update the window
        app.display();
    }

    delete gameObjectHandler;

    return EXIT_SUCCESS;
}
