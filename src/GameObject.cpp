#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
}

GameObject::GameObject( int x, int y, const sf::Texture &txt )
{
    sprite.setTexture( txt, true );

    std::cout << sprite.getLocalBounds().width << " " << std::endl;
    std::cout << txt.getSize().x<< " "  << std::endl;

    position.x = x;
    position.y = y;

    sprite.setPosition(x, y);


}

GameObject::~GameObject()
{
    //dtor
}


void GameObject::draw(sf::RenderWindow &rw){
    rw.draw(sprite);
}

void GameObject::setAngle(float new_angle){
    sprite.setRotation(new_angle);
};

void GameObject::turn(float angle){
    sprite.rotate(angle);
};

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void GameObject::setPosition(Point position){
    sprite.setPosition( position.x, position.y );
}

void GameObject::setSprite( const sf::Sprite &sprite ){
    this->sprite = sprite;
}

