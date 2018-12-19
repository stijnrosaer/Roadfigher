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

void roadfighter::World::update(float speed, vector<shared_ptr<Entity>> entities) {
    player->update(0, this->entities);
    this->speed = player->getSpeed();
    for(auto &entity : this->entities){
        entity->update(this->speed, this->entities);
    }

    toDelete();
}

float roadfighter::World::getSpeed() {
    return this->speed;
}

void roadfighter::World::addEntity(const shared_ptr<roadfighter::Entity> &object) {
    entities.push_back(object);
}

bool roadfighter::World::toDelete() {
    for(long i = entities.size() - 1; i >= 0; i--){
        if (entities[i]->toDelete()){
            entities.erase(entities.begin() + i);
        }

    }
    return true;
}
