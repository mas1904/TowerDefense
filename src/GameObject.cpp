#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
}

GameObject::~GameObject()
{
    //dtor
}


void GameObject::draw(sf::RenderWindow &rw){

    rw.draw(sprite);

}
