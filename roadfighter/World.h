//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_WORLD_H
#define PROJECTGP_WORLD_H

#include "Entity.h"
#include "PlayerCar.h"

namespace roadfighter {
    class World : public roadfighter::Entity {
    private:
        shared_ptr<roadfighter::Entity> player;
        vector<shared_ptr<roadfighter::Entity>> entities;

    public:
        // constructor
        World();

        // getters and setters
        const shared_ptr<Entity> &getPlayer() const;

        // functions
        const coordinate &GetLocation() const override;

    };
}

#endif //PROJECTGP_WORLD_H
