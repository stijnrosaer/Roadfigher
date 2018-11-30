//
// Created by stijn on 16/11/18.
//

#include "../include/Bullet.h"

roadfighter::Bullet::Bullet() {}

const pair<float, float> &roadfighter::Bullet::GetLocation() const {
    return this->loc;
}
