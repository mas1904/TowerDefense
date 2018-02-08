#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::GameObject( Point pos, const sf::Texture &txt ) :
    position(pos)
{
    sprite.setTexture( txt, true );

    std::cout << sprite.getLocalBounds().width << " " << std::endl;
    std::cout << txt.getSize().x<< " "  << std::endl;

    radius = sprite.getTextureRect().width;  //TO DO change after making load enemies frm xml
    sprite.setPosition(pos.x, pos.y);

    sprite.setOrigin( sprite.getTextureRect().width/2 , sprite.getTextureRect().height/2 );

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

