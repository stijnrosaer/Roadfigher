//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGCAR_H
#define PROJECTGP_PASSINGCAR_H

#include "Entity.h"

namespace roadfighter {
    class PassingCar : public roadfighter::Entity {
    private:
        pair<float, float> loc;

    public:
        // constructor
        PassingCar();


        // functions
        const pair<float, float> &GetLocation() const override;
        void draw() override = 0;

    };
}

#endif //PROJECTGP_PASSINGCAR_H
