//
// Created by stijn on 16/11/18.
//

#include "../rf/Bullet.h"

roadfighter::Bullet::Bullet() {}

float roadfighter::Bullet::getSpeed() {
    return this->speed;
}

bool roadfighter::Bullet::toDelete() {
    return false;
}
