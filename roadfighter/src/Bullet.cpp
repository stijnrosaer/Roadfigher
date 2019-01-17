//
// Created by stijn on 16/11/18.
//

#include "../rf/Bullet.h"

roadfighter::Bullet::Bullet(location loc)
{
        del = false;

        this->bounds.loc = {loc.x, loc.y + 0.4};
        this->bounds.width = 0.15;
        this->bounds.height = 0.2;

        this->bounds.tlLoc = {bounds.loc.x - (bounds.width / 2), bounds.loc.y + (bounds.height / 2)};
        this->bounds.brLoc = {bounds.loc.x + (bounds.width / 2), bounds.loc.y - (bounds.height / 2)};

        //        cout << "bounds: " << bounds.tlLoc.x << " = " << bounds.tlLoc.y << endl;

        this->speed = 800;

        del = false;
}

float roadfighter::Bullet::getSpeed() { return this->speed; }

bool roadfighter::Bullet::toDelete()
{
        if (bounds.loc.y > 4) {
                del = true;
        }
        return del;
}

void roadfighter::Bullet::setDelete(bool del) { this->del = del; }

void roadfighter::Bullet::setLoc(location loc)
{
        this->bounds.tlLoc = loc;
        this->bounds.loc = {loc.x + (bounds.width / 2), loc.y - (bounds.height / 2)};
        this->bounds.brLoc = {loc.x + bounds.width, loc.y - bounds.height};

        //    cout << loc.x << " / " << loc.y << endl;
}

void roadfighter::Bullet::update(float speed, vector<shared_ptr<roadfighter::Entity>> entities)
{
        if (this->collision(entities) != nullptr) {
                this->callObserver(hitByBullet);
        }
        this->relativeSpeed = this->speed - speed;
}

void roadfighter::Bullet::moveBullet() { setLoc({bounds.tlLoc.x, bounds.tlLoc.y + relativeSpeed * 0.0005}); }

bool roadfighter::Bullet::finish() {
        return this->bounds.loc.y > 4;
}
