//
// Created by stijn on 16/11/18.
//

#include "../include/PassingCar.h"

roadfighter::PassingCar::PassingCar() {}

const pair<float, float> &roadfighter::PassingCar::GetLocation() const {
    return this->loc;
}
