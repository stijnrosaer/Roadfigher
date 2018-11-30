//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCAR_H
#define PROJECTGP_PLAYERCAR_H

#include "Entity.h"

namespace roadfighter {
    class PlayerCar : public roadfighter::Entity {
    private:
        pair<float, float> loc;

    public:
        // constructor
        PlayerCar();


        // functions
        const pair<float, float> &GetLocation() const override;
        void draw() override = 0;

    };
}

#endif //PROJECTGP_PLAYERCAR_H
