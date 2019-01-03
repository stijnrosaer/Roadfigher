//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCAR_H
#define PROJECTGP_PLAYERCAR_H

#include "Entity.h"
#include "World.h"

namespace roadfighter {
    class PlayerCar : public roadfighter::Entity {
    protected:
        float speed;
        float relativeSpeed;

        int exploding;

        bool del;

    public:
        // constructor
        PlayerCar();


        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        // getters and setters
        void setLoc(location loc);

        float getSpeed() override;
        void setDelete(bool del) override;
        bool toDelete() override;

    };
}

#endif //PROJECTGP_PLAYERCAR_H
