//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_BULLET_H
#define PROJECTGP_BULLET_H

#include "Entity.h"

namespace roadfighter {
    class Bullet : public Entity {
    private:
        coordinate loc;

    public:
        // constructor
        Bullet();


        // functions
        const coordinate &GetLocation() const override;

    };
}

#endif //PROJECTGP_BULLET_H
