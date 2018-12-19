//
// Created by stijn on 16/11/18.
//

#ifndef PROJECTGP_PLAYERCAR_H
#define PROJECTGP_PLAYERCAR_H

#include "Entity.h"
#include "World.h"

namespace roadfighter {
    class PlayerCar : public roadfighter::Entity {
        struct boundaries{
            pair<float, float> loc;
            float width;
            float height;
            pair<float, float> tlLoc;
            pair<float, float> brLoc;
        };
    protected:
        boundaries bounds;
        bool toRemove;

        float speed;
        float relativeSpeed;

    public:
        // constructor
        PlayerCar();


        // functions
        void draw() override = 0;
        void update(float speed, vector<shared_ptr<Entity>> entities) override;

        // getters and setters
        void setLoc(const pair<float, float> &loc);

        float getSpeed() override;

        bool toDelete() override;

    };
}

#endif //PROJECTGP_PLAYERCAR_H
