//
// Created by stijn on 16/11/18.
//

#include "Entity.h"
#include "PlayerCar.h"

shared_ptr<roadfighter::Entity> roadfighter::Entity::createEntity(string name) {
    if (name == "player"){
        return make_shared<roadfighter::PlayerCar>();
    }
}
