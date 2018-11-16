//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_WORLD_H
#define PROJECTGP_WORLD_H

#include "Entity.h"
#include "PlayerCar.h"

namespace roadfighter {
    class World : public Entity {
    private:
        shared_ptr<roadfighter::Entity> player = roadfighter::Entity::createEntity("player");
        vector<shared_ptr<Entity>> racingCars;
        vector<shared_ptr<Entity>> passingCars;
        vector<shared_ptr<Entity>> Bullets;
    };
}

#endif //PROJECTGP_WORLD_H
