//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_WORLD_H
#define PROJECTGP_WORLD_H

#include "Entity.h"
#include "PlayerCar.h"

namespace roadfighter {
    class World : public roadfighter::Entity {
    private:
        vector<shared_ptr<roadfighter::Entity>> entities;

    };
}

#endif //PROJECTGP_WORLD_H
