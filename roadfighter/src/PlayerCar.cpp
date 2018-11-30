//
// Created by stijn on 16/11/18.
//

#include "../include/PlayerCar.h"


roadfighter::PlayerCar::PlayerCar() : roadfighter::Entity() {
    this->loc = {0, -2};
}

const pair<float, float> &roadfighter::PlayerCar::GetLocation() const {
    return this->loc;
}