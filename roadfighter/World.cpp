//
// Created by stijn on 16/11/18.
//

#include "World.h"

roadfighter::World::World() {
    this->player = make_shared<roadfighter::PlayerCar>();
}

const shared_ptr<roadfighter::Entity> &roadfighter::World::getPlayer() const {
    return player;
}

const coordinate &roadfighter::World::GetLocation() const {
    throw "No getlocation in world";
}
