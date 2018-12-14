//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGCAR_H
#define PROJECTGP_PASSINGCAR_H

#include "Entity.h"

namespace roadfighter {
    class PassingCar : public roadfighter::Entity {
    protected:
        pair<float, float> loc;
        float width;
        float height;

        pair<float, float> tlLoc;
        pair<float, float> brLoc;

        int speed;

    public:
        // constructor
        PassingCar();


        // functions
        void draw() override = 0;
        void update(int speed) override = 0;

        int getSpeed() override;

    };
}

#endif //PROJECTGP_PASSINGCAR_H
