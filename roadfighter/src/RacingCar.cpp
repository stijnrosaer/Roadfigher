//
// Created by stijn on 16/11/18.
//

#include "../rf/RacingCar.h"

roadfighter::RacingCar::RacingCar() {
    this->bounds.loc = {0,0};
    this->bounds.width = 0.3;
    this->bounds.height = 0.4;

    this->bounds.tlLoc = {bounds.loc.x - (bounds.width / 2), bounds.loc.y + (bounds.height / 2)};
    this->bounds.brLoc = {bounds.loc.x + (bounds.width / 2), bounds.loc.y - (bounds.height / 2)};

    this->speed = 100;

    del = false;
}

bool roadfighter::RacingCar::toDelete() { return del; }

float roadfighter::RacingCar::getSpeed() { return 0; }

void roadfighter::RacingCar::setDelete(bool del) { this->del = del; }

void roadfighter::RacingCar::update(float speed, vector<shared_ptr<roadfighter::Entity>> entities) {
    if (speed < 150){
        speed += 5;
        this->relativeSpeed = this->speed - speed;
    } else {
        if (Random::getInstance()->chance(0.35)) {
            if (this->speed < 450) {
                this->speed += 5;
                this->relativeSpeed = this->speed - speed;
            }
        } else if (Random::getInstance()->chance(0.25)) {
            if (this->speed > 200) {
                this->speed -= 5;
                this->relativeSpeed = this->speed - speed;
            }
        }
    }

    this->moveRacingCar(up);

    if (this->collision(entities) != nullptr) {
        if (Random::getInstance()->chance(0.8)) {
            if (Random::getInstance()->chance(0.5)) {
                //move left
                while (this->collision(entities) != nullptr && this->bounds.loc.x > -1.3) {
                    this->moveRacingCar(left);
                }
            } else {
                //move right
                while (this->collision(entities) != nullptr && this->bounds.loc.x < 1.1) {
                    this->moveRacingCar(right);
                }
            }
        }
    }
}

void roadfighter::RacingCar::moveRacingCar(roadfighter::RacingCar::direction dir) {
    switch (dir){

        case up:
            setLoc({bounds.tlLoc.x, bounds.tlLoc.y + relativeSpeed * 0.0005});
            break;

        case down:
            setLoc({bounds.tlLoc.x, bounds.tlLoc.y + relativeSpeed * 0.0005});
            break;

        case left:
            setLoc({bounds.tlLoc.x - 0.1, bounds.tlLoc.y});
            break;

        case right:
            setLoc({bounds.tlLoc.x + 0.1, bounds.tlLoc.y});
            break;
        case slow:break;
    }
}

void roadfighter::RacingCar::setLoc(const location loc) {
    this->bounds.tlLoc = loc;
    this->bounds.loc = {loc.x + (bounds.width / 2), loc.y - (bounds.height / 2)};
    this->bounds.brLoc = {loc.x + bounds.width, loc.y - bounds.height};
}
