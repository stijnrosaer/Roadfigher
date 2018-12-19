//
// Created by stijn on 16/11/18.
//

#include "../rf/PassingCar.h"
#include "../../Random.h"

roadfighter::PassingCar::PassingCar() {
    int l = Random::getInstance()->random(0,4);
    float xloc;
    switch (l){
        case 0:
            xloc = -1;
            break;
        case 1:
            xloc = static_cast<float>(-0.5);
            break;
        case 2:
            xloc = 0;
            break;
        case 3:
            xloc = 0.5;
            break;
        case 4:
            xloc = 1;
            break;
        default:
            xloc = 0;
            break;
    }

    this->bounds.loc = {xloc, 3.5};
    this->bounds.width = 0.3;
    this->bounds.height = 0.4;

    this->bounds.tlLoc = {bounds.loc.first-(bounds.width/2), bounds.loc.second+(bounds.height/2)};
    this->bounds.brLoc = {bounds.loc.first+(bounds.width/2), bounds.loc.second-(bounds.height/2)};

    this->speed = 100;
}

float roadfighter::PassingCar::getSpeed() {
    return this->speed;
}

roadfighter::PassingCar::~PassingCar(){
}

void roadfighter::PassingCar::update(float speed, vector<shared_ptr<Entity>> entities) {
    this->relativeSpeed = this->speed - speed;
    // todo: location hier aanpassen met relative speed
}

bool roadfighter::PassingCar::toDelete() {
    return bounds.tlLoc.second < -3;
}

void roadfighter::PassingCar::setLoc(const pair<float, float> &loc) {
    this->bounds.tlLoc = loc;
    this->bounds.loc = {loc.first+(bounds.width/2), loc.second-(bounds.height/2)};
    this->bounds.brLoc = {loc.first+bounds.width, loc.second-bounds.height};
}
