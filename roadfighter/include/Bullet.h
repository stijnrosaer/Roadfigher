//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLET_H
#define PROJECTGP_BULLET_H

#include "Entity.h"

namespace roadfighter {
    class Bullet : public Entity {
    private:
        pair<float, float> loc;

    public:
        // constructor
        Bullet();


        // functions
        const pair<float, float> &GetLocation() const override;
        void draw() override = 0;

    };
}

#endif //PROJECTGP_BULLET_H
