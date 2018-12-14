//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLET_H
#define PROJECTGP_BULLET_H

#include "Entity.h"

namespace roadfighter {
    class Bullet : public Entity {
    protected:
        int speed;
        pair<float, float> loc;

    public:
        // constructor
        Bullet();


        // functions
        void draw() override = 0;
        void update(int speed) override = 0;

        int getSpeed() override;

    };
}

#endif //PROJECTGP_BULLET_H
