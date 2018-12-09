//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCAR_H
#define PROJECTGP_PLAYERCAR_H

#include "Entity.h"

namespace roadfighter {
    class PlayerCar : public roadfighter::Entity {
    protected:
        pair<float, float> loc;

    public:
        // constructor
        PlayerCar();


        // functions
        void draw() override = 0;

    };
}

#endif //PROJECTGP_PLAYERCAR_H
