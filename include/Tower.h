#ifndef TOWER_H
#define TOWER_H

#include "GameObject.h"
#include "Weapon.h"


class Tower : public GameObject
{
    public:
        /** Default constructor */
        Tower();
        /** Default destructor */
        virtual ~Tower();

        void setAngle( float angle );
        void turn( float angle );
        void shoot();

    protected:

    private:

        Weapon weapon;




};

#endif // TOWER_H
