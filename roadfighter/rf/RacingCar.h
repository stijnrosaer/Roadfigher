//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_RACINGCAR_H
#define PROJECTGP_RACINGCAR_H

#include "Entity.h"

namespace roadfighter {
    class RacingCar : public roadfighter::Entity {
    protected:
        pair<float, float> loc;


    public:
        // constructor
        RacingCar();


        // functions
        void draw() override = 0;
        void update() override = 0;

    };
}

#endif //PROJECTGP_RACINGCAR_H
