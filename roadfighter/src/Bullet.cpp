//
// Created by stijn on 16/11/18.
//

#include "../rf/Bullet.h"

roadfighter::Bullet::Bullet() {
    del = false;
}

float roadfighter::Bullet::getSpeed() {
    return this->speed;
}

bool roadfighter::Bullet::toDelete() {
    return del;
}

void roadfighter::Bullet::setDelete(bool del) {
    this->del = true;
}
