//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGCAR_H
#define PROJECTGP_PASSINGCAR_H

#include "Entity.h"

namespace roadfighter {
    class PassingCar : public roadfighter::Entity {
    protected:
        int speed;
        pair<float, float> loc;

    public:
        // constructor
        PassingCar();


        // functions
        void draw() override = 0;
        void update() override = 0;

        int getSpeed() override;

    };
}

#endif //PROJECTGP_PASSINGCAR_H
