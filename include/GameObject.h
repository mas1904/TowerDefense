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
        GameObject( int x,
                   int y,
                   const sf::Texture &txt );
        /** Default destructor */
        virtual ~GameObject();

        void draw( sf::RenderWindow &rw );

        void setSprite( const sf::Sprite &sprite );

        void setPosition( Point position );

        void setAngle( float angle );

        void turn( float angle );

        virtual void action( float seconds ) { turn(100.0 * seconds); };

        //function invoked on evry clock tick
        //virtual action( float seconds );

        sf::Sprite sprite;
    protected:

    private:
        Point position;
        int radius;

        float angle;


};

#endif // GAMEOBJECT_H
