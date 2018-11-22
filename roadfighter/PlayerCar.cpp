//
// Created by stijn on 16/11/18.
//

#include "PlayerCar.h"


roadfighter::PlayerCar::PlayerCar() : roadfighter::Entity() {
    this->loc = {0, -2};
}

const coordinate &roadfighter::PlayerCar::GetLocation() const {
    return this->loc;
}
