//
// Created by stijn on 16/11/18.
//

#include "../include/RacingCar.h"

roadfighter::RacingCar::RacingCar() {}

const pair<float, float> &roadfighter::RacingCar::GetLocation() const {
    return this->loc;
}
