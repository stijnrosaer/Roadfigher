//
// Created by stijn on 16/11/18.
//

#include "../include/World.h"

roadfighter::World::World() {

}

const shared_ptr<roadfighter::Entity> &roadfighter::World::getPlayer() const {
    return player;
}

const pair<float, float> &roadfighter::World::GetLocation() const {
    throw "No getlocation in world";
}

void roadfighter::World::setPlayer(const shared_ptr<roadfighter::Entity> &player) {
    World::player = player;
}

void roadfighter::World::draw() {
    throw "no draw in wordl";
}
