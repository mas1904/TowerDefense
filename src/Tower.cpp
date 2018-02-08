#include "Tower.h"

Tower::Tower()
{
    //ctor
}

Tower::~Tower()
{
    //dtor
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Tower::turnWeapon( float angle )
{
    weapon.turn( angle );


}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Tower::setWeaponAngle( float angle )
{
    weapon.setAngle( angle );


}

void Tower::shoot()
{
    weapon.shoot();

}
