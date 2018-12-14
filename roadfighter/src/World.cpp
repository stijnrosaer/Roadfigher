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

void roadfighter::World::update(int speed) {
    player->update(0);
    this->speed = player->getSpeed();
    for(auto &entity : entities){
        entity->update(this->speed);
    }
}

int roadfighter::World::getSpeed() {
    return this->speed;
}

void roadfighter::World::addEntity(const shared_ptr<roadfighter::Entity> &object) {
    entities.push_back(object);
}
