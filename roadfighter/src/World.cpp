//
// Created by stijn on 16/11/18.
//

#include "../rf/World.h"

roadfighter::World::World() {

}

const shared_ptr<roadfighter::Entity> &roadfighter::World::getPlayer() const {
    return player;
}

void roadfighter::World::setPlayer(const shared_ptr<roadfighter::Entity> &player) {
    World::player = player;
}

void roadfighter::World::draw() {
    player->draw();

    for(auto &entity : entities){
        entity->draw();
    }
}

void roadfighter::World::update() {
    player->update();
    this->speed = player->getSpeed();
    for(auto &entity : entities){
        entity->draw();
    }
}

int roadfighter::World::getSpeed() {
    return this->speed;
}
