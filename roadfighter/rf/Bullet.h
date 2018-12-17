//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLET_H
#define PROJECTGP_BULLET_H

#include "Entity.h"

namespace roadfighter {
    class Bullet : public Entity {
    protected:
        pair<float, float> loc;

        float speed;
        float relativeSpeed;

    public:
        // constructor
        Bullet();


        // functions
        void draw() override = 0;
        void update(int speed) override = 0;

        float getSpeed() override;

    };
}

#endif //PROJECTGP_BULLET_H
