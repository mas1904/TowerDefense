#ifndef WEAPON_H
#define WEAPON_H

#include "GameObject.h"
#include "Ammo.h"

class Weapon : public GameObject
{
    public:
        /** Default constructor */
        Weapon();
        /** Default destructor */
        virtual ~Weapon();

        void shoot();

    protected:

    private:
        Ammo ammo;

};

#endif // WEAPON_H
