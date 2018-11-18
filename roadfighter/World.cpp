//
// Created by stijn on 16/11/18.
//

#include "World.h"

roadfighter::World::World() {
    this->player = roadfighter::Entity::createEntity("player");
}

const shared_ptr<roadfighter::Entity> &roadfighter::World::getPlayer() const {
    return player;
}
