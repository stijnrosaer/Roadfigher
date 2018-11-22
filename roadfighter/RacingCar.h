//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_RACINGCAR_H
#define PROJECTGP_RACINGCAR_H

#include "Entity.h"

namespace roadfighter {
    class RacingCar : public roadfighter::Entity {
    private:
        coordinate loc;


    public:
        // constructor
        RacingCar();


        // functions
        const coordinate &GetLocation() const override;

    };
}

#endif //PROJECTGP_RACINGCAR_H
