#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "HelperClasses.h"

class GameObject
{
    public:
        /** Default constructor */
        GameObject();
        GameObject( Point pos, const sf::Texture &txt );
        /** Default destructor */
        virtual ~GameObject();

        void draw( sf::RenderWindow &rw );

        void setSprite( const sf::Sprite &sprite );

        void setPosition( Point position );

        void setAngle( float angle );

        void turn( float angle );

        virtual void action( float seconds ) { };

        //function invoked on evry clock tick
        //virtual action( float seconds );

        sf::Sprite sprite;
    protected:

    private:
        Point position = Point(0,0);
        int radius = 0;

        float angle = 0;


};

#endif // GAMEOBJECT_H
