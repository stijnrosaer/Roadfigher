//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PASSINGCAR_H
#define PROJECTGP_PASSINGCAR_H

#include "Entity.h"

namespace roadfighter {
    class PassingCar : public roadfighter::Entity {
    private:
        coordinate loc;

    public:
        // constructor
        PassingCar();


        // functions
        const coordinate &GetLocation() const override;

    };
}

#endif //PROJECTGP_PASSINGCAR_H
