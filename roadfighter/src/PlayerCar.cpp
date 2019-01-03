//
// Created by stijn on 16/11/18.
//

#include "../rf/PlayerCar.h"


roadfighter::PlayerCar::PlayerCar() : roadfighter::Entity() {
    this->bounds.loc = {-0.15, -2.5};
    this->bounds.width = 0.3;
    this->bounds.height = 0.4;

    this->bounds.tlLoc = {bounds.loc.x-(bounds.width/2), bounds.loc.y+(bounds.height/2)};
    this->bounds.brLoc = {bounds.loc.x+(bounds.width/2), bounds.loc.y-(bounds.height/2)};

    this->speed = 0;
    this->exploding = 0;
}

void roadfighter::PlayerCar::setLoc(location loc) {
    this->bounds.loc = loc;
    this->bounds.tlLoc = {loc.x-(bounds.width/2), loc.y+(bounds.height/2)};
    this->bounds.brLoc = {loc.x+(bounds.width/2), loc.y-(bounds.height/2)};
}

float roadfighter::PlayerCar::getSpeed() {
    return this->speed;
}

bool roadfighter::PlayerCar::toDelete() {
    return del;
}

void roadfighter::PlayerCar::update(float speed, vector<shared_ptr<roadfighter::Entity>> entities) {
    if (collision(entities)){
        exploding ++;
        if (this->speed > 0) {
            this->speed -= 30;
        } else{
            this->speed = 0;
        }

        return;
    }

    if (exploding < 50 && exploding > 0){
        exploding ++;

        if (this->speed > 0) {
            this->speed -= 30;
        } else{
            this->speed = 0;
        }

        return;
    }
    if (exploding == 50){
        exploding = 0;

        this->speed = 0;
        setLoc({0, this->bounds.loc.y});

    }
}

void roadfighter::PlayerCar::setDelete(bool del) {
    this->del = true;
}
