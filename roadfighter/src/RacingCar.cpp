//
// Created by stijn on 16/11/18.
//

#include "../rf/RacingCar.h"

roadfighter::RacingCar::RacingCar() {}

bool roadfighter::RacingCar::toDelete() {
    return del;
}

float roadfighter::RacingCar::getSpeed() {
    return 0;
}

void roadfighter::RacingCar::setDelete(bool del){
    this->del = true;
}

