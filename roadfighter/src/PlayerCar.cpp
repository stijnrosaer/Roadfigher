//
// Created by stijn on 16/11/18.
//

#include "../rf/PlayerCar.h"

roadfighter::PlayerCar::PlayerCar() : roadfighter::Entity()
{
        this->bounds.loc = {-0.15, -2.5};
        this->bounds.width = 0.3;
        this->bounds.height = 0.4;

        this->bounds.tlLoc = {bounds.loc.x - (bounds.width / 2), bounds.loc.y + (bounds.height / 2)};
        this->bounds.brLoc = {bounds.loc.x + (bounds.width / 2), bounds.loc.y - (bounds.height / 2)};

        this->speed = 0;
        this->exploding = 0;
        this->waitForShoot = 0;
}

void roadfighter::PlayerCar::setLoc(location loc)
{
        this->bounds.loc = loc;
        this->bounds.tlLoc = {loc.x - (bounds.width / 2), loc.y + (bounds.height / 2)};
        this->bounds.brLoc = {loc.x + (bounds.width / 2), loc.y - (bounds.height / 2)};
}

float roadfighter::PlayerCar::getSpeed() { return this->speed; }

bool roadfighter::PlayerCar::toDelete() { return del; }

void roadfighter::PlayerCar::update(float speed, vector<shared_ptr<roadfighter::Entity>> entities)
{
        if (collision(entities)) {
                collision(entities)->setDelete(true);
                exploding++;
                if (this->speed > 0) {
                        this->speed -= 30;
                } else {
                        this->speed = 0;
                }

                return;
        }

        if (exploding < 50 && exploding > 0) {
                exploding++;

                if (this->speed > 0) {
                        this->speed -= 30;
                } else {
                        this->speed = 0;
                }

                return;
        }
        if (exploding == 50) {
                //                for (auto& item : entities) {
                //                        item->setDelete(true);
                //                }
                exploding = 0;

                this->speed = 0;
                setLoc({-0.15, this->bounds.loc.y});
        }

        if (waitForShoot > 0) {
                waitForShoot -= 1;
        }
}

void roadfighter::PlayerCar::setDelete(bool del) { this->del = true; }

void roadfighter::PlayerCar::reload() { waitForShoot = 50; }

void roadfighter::PlayerCar::movePlayerCar(roadfighter::PlayerCar::direction dir)
{
        switch (dir) {
        case up:
                if (this->speed < 400) {
                        this->speed += 5;
                }
                break;

        case down:
                this->speed -= 10;
                if (this->speed < 0) {
                        this->speed = 0;
                }
                break;

        case left:
                if (bounds.loc.x > -1.3) {
                        this->setLoc({bounds.loc.x - 0.07, bounds.loc.y});
                }
                break;

        case right:
                if (bounds.loc.x < 1.1) {
                        this->setLoc({bounds.loc.x + 0.07, bounds.loc.y});
                }
                break;

        case slow: {
                this->speed -= 3;
                if (this->speed < 0) {
                        this->speed = 0;
                }
        }
        }
}

bool roadfighter::PlayerCar::finish() {
        if (speed > 0){
                speed -= 5;
                if (speed < 0){
                        speed = 0;
                }
                return false;
        }
        return true;

}
