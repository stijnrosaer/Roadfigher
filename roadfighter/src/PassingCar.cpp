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

    this->loc = {xloc, 3.5};
    this->width = 0.3;
    this->height = 0.4;

    this->tlLoc = {loc.first-(width/2), loc.second+(height/2)};
    this->brLoc = {loc.first+(width/2), loc.second-(height/2)};

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
    return loc.second < -3;
}
