//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCAR_H
#define PROJECTGP_PLAYERCAR_H

#include "Entity.h"

namespace roadfighter {
    class PlayerCar : public roadfighter::Entity {
    private:
        coordinate loc;

    public:
        PlayerCar();
    };
}

#endif //PROJECTGP_PLAYERCAR_H
