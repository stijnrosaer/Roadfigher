//
// Created by stijn on 16/11/18.
//

#include "../rf/RacingCar.h"
#include "../rf/Observer.h"

roadfighter::RacingCar::RacingCar()
{
        this->bounds.loc = {0.75, -2.5};
        this->bounds.width = 0.3;
        this->bounds.height = 0.4;

        this->bounds.tlLoc = {bounds.loc.x - (bounds.width / 2), bounds.loc.y + (bounds.height / 2)};
        this->bounds.brLoc = {bounds.loc.x + (bounds.width / 2), bounds.loc.y - (bounds.height / 2)};

        this->speed = 100;

        del = false;
}

bool roadfighter::RacingCar::toDelete()
{
        cout << del << endl;
        return del;
}

float roadfighter::RacingCar::getSpeed() { return 0; }

void roadfighter::RacingCar::setDelete(bool del)
{
        cout << "setdel" << endl;
        this->del = del;
}

void roadfighter::RacingCar::update(float speed, vector<shared_ptr<roadfighter::Entity>> entities)
{
        if (this->speed < 200) {
                this->speed += 5;
        } else {
                if (this->speed >= speed) {
                        if (Random::getInstance()->chance(0.70)) {
                                if (this->speed > 200) {
                                        this->speed -= 5;
                                }
                        } else if (Random::getInstance()->chance(0.10)) {
                                if (this->speed < 500) {
                                        this->speed += 5;
                                }
                        }
                } else {
                        if (Random::getInstance()->chance(0.70)) {
                                if (this->speed < 500) {
                                        this->speed += 5;
                                }
                        } else if (Random::getInstance()->chance(0.10)) {
                                if (this->speed > 250) {
                                        this->speed -= 5;
                                }
                        }
                }
        }

        this->relativeSpeed = this->speed - speed;
        this->moveRacingCar(up);

        if (this->collision(entities) != nullptr) {
                if (Random::getInstance()->chance(0.90)) {
                        if (Random::getInstance()->chance(0.5)) {
                                // move left
                                while (this->collision(entities) != nullptr && this->bounds.loc.x > -1.3) {
                                        this->moveRacingCar(left);
                                        //                    cout << this->bounds.loc.x << endl;
                                }
                        } else {
                                // move right
                                while (this->collision(entities) != nullptr && this->bounds.loc.x < 1.1) {
                                        this->moveRacingCar(right);
                                        //                    cout << this->bounds.loc.x << endl;
                                }
                        }
                }
        }

        if (collision(entities) != nullptr) {
                this->setLoc({0, -4});
                this->speed = 250;
        }

        //    cout << this->speed << endl;
}

void roadfighter::RacingCar::moveRacingCar(roadfighter::RacingCar::direction dir)
{
        switch (dir) {

        case up:
                setLoc({bounds.tlLoc.x, bounds.tlLoc.y + relativeSpeed * 0.0005});
                break;

        case down:
                setLoc({bounds.tlLoc.x, bounds.tlLoc.y + relativeSpeed * 0.0005});
                break;

        case left:
                setLoc({bounds.tlLoc.x - 0.15, bounds.tlLoc.y});
                break;

        case right:
                setLoc({bounds.tlLoc.x + 0.15, bounds.tlLoc.y});
                break;
        case slow:
                break;
        }
}

void roadfighter::RacingCar::setLoc(const location loc)
{
        this->bounds.tlLoc = loc;
        this->bounds.loc = {loc.x + (bounds.width / 2), loc.y - (bounds.height / 2)};
        this->bounds.brLoc = {loc.x + bounds.width, loc.y - bounds.height};
}

bool roadfighter::RacingCar::finish()
{
        if (speed > 0) {
                speed -= 5;
                if (speed < 0) {
                        speed = 0;
                }
                return false;
        }
        return true;
}