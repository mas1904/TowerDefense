#include <iostream>
#include <SFML/Graphics.hpp>

#include <iterator>
#include <time.h>
#include <math.h>

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
    sf::RenderWindow app(sf::VideoMode(1024, 720), "SFML window");

    // Load a sprite to display

	TextureHandler textureHandler;

	textureHandler.loadTexture( "test", "cb.bmp" );    //TO DO loading from xml

	textureHandler.loadTexture( "grass1", "grass.bmp" );    //TO DO loading from xml
	textureHandler.loadTexture( "grass2", "grass2.bmp" );    //TO DO loading from xml
	textureHandler.loadTexture( "grass3", "grass3.bmp" );    //TO DO loading from xml
	textureHandler.loadTexture( "grass4", "grass4.bmp" );    //TO DO loading from xml

	textureHandler.loadTexture( "turret1", "turret1.bmp" );    //TO DO loading from xml

	const int num_of_grass_type = 4;

	sf::Sprite sprite(textureHandler.getTexture( "test" ));


	GameObjectHandler *gameObjectHandler = new TableHandler();

	srand( time(NULL) );

    string type = "grass";
	for(int i=0; i<app.getSize().y/128 + 1;i++){
        for(int j=0; j<app.getSize().x/128 + 1;j++){
            int r = rand( ) % num_of_grass_type + 1;
            gameObjectHandler->add( GameObject( Point(j*128, i*128), textureHandler.getTexture( type+to_string( r ) ) ) );
        }
	}


	gameObjectHandler->add( GameObject( Point(128*3, 128*3), textureHandler.getTexture( "turret1" ) ) );

	//gameObjectHandler->add( GameObject( Point(350, 250), textureHandler.getTexture( "test" ) ) );




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
