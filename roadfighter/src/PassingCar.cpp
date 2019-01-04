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

    this->bounds.loc = {xloc, 3.5};
    this->bounds.width = 0.3;
    this->bounds.height = 0.4;

    this->bounds.tlLoc = {bounds.loc.x-(bounds.width/2), bounds.loc.y+(bounds.height/2)};
    this->bounds.brLoc = {bounds.loc.x+(bounds.width/2), bounds.loc.y-(bounds.height/2)};

    this->speed = 100;

    del = false;
}

float roadfighter::PassingCar::getSpeed() {
    return this->speed;
}

roadfighter::PassingCar::~PassingCar(){
}

void roadfighter::PassingCar::update(float speed, vector<shared_ptr<Entity>> entities) {
    this->relativeSpeed = this->speed - speed;
}

bool roadfighter::PassingCar::toDelete() {
    if(bounds.tlLoc.y < -3){
        del = true;
    } else if (bounds.brLoc.y > 4){
        del = true;
    }

    return del;
}

void roadfighter::PassingCar::setDelete(bool del) {
    this->del = del;

}

void roadfighter::PassingCar::setLoc(location loc) {
    this->bounds.tlLoc = loc;
    this->bounds.loc = {loc.x+(bounds.width/2), loc.y-(bounds.height/2)};
    this->bounds.brLoc = {loc.x+bounds.width, loc.y-bounds.height};
}

void roadfighter::PassingCar::movePassingCar() {
    setLoc({bounds.tlLoc.x, bounds.tlLoc.y + relativeSpeed*0.0005});
}
