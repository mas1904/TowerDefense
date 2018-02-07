#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <SFML/Graphics.hpp>

#include "HelperClasses.h"

class GameObject
{
    public:
        /** Default constructor */
        GameObject();
        /** Default destructor */
        virtual ~GameObject();

        void draw( sf::RenderWindow &rw);


        //function invoked on evry clock tick
        //virtual action( float seconds );

    protected:

    private:
        Point position;
        int radius;

        float angle;

        sf::Sprite sprite;

};

#endif // GAMEOBJECT_H
