#ifndef GAMEOBJECTHANDLER_H
#define GAMEOBJECTHANDLER_H

#include <vector>
#include "GameObject.h"

class GameObjectHandler
{
    public:
        virtual void add( GameObject go ) = 0;

        virtual std::vector<GameObject> &objects()=0;

    protected:

    private:

};

#endif // GAMEOBJECTHANDLER_H
