//
// Created by stijn on 16/11/18.
//

#include "../rf/PlayerCar.h"


roadfighter::PlayerCar::PlayerCar() : roadfighter::Entity() {
    this->loc = {-0.15, -2.5};
    this->width = 0.3;
    this->height = 0.4;

    this->tlLoc = {loc.first-(width/2), loc.second+(height/2)};
    this->brLoc = {loc.first+(width/2), loc.second-(height/2)};

    this->speed = 0;
}

void roadfighter::PlayerCar::setLoc(const pair<float, float> &loc) {
    PlayerCar::loc = loc;
    this->tlLoc = {loc.first-(width/2), loc.second+(height/2)};
    this->brLoc = {loc.first+(width/2), loc.second-(height/2)};
}

float roadfighter::PlayerCar::getSpeed() {
    return this->speed;
}
